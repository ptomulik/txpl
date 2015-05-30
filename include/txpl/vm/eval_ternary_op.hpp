// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/eval_ternary_op.hpp

/** // doc: txpl/vm/eval_ternary_op.hpp {{{
 * \file txpl/vm/eval_ternary_op.hpp
 * \brief Implements \ref txpl::vm::eval_ternary_op_visitor "vm::eval_ternary_op_visitor<>"
 */ // }}}
#ifndef TXPL_VM_EVAL_TERNARY_OP_HPP_INCLUDED
#define TXPL_VM_EVAL_TERNARY_OP_HPP_INCLUDED

#include <txpl/vm/can_apply_ternary_op.hpp>
#include <txpl/vm/apply_ternary_op.hpp>
#include <txpl/vm/disambiguate.hpp>
#include <txpl/vm/value_traits.hpp>
#include <txpl/vm/array.hpp>
#include <txpl/vm/object.hpp>
#include <txpl/vm/op_t.hpp>
#include <yaul/tml/bool.hpp>
#include <yaul/variant/apply_visitor.hpp>
#include <yaul/variant/static_visitor.hpp>
#include <yaul/variant/multivisitors.hpp>
#include <utility>

namespace txpl { namespace vm {
/** // doc: eval_ternary_op_visitor {{{
 * \ingroup VmGroup
 * \brief Applies ternary operator to its operands
 *
 * \tparam Op identifier of the ternary operator, see \ref txpl::vm::op_t "vm::op_t"
 * \tparam Value a universal (variant) value type used to store result of the operation.
 *
 * The purpose of this functor is to either invoke appropriate instantiation of
 * the \ref txpl::vm::apply_ternary_op "vm::apply_ternary_op<>" or to
 * indicate an error if the operands provided to the functor are not
 * compatible with the given operator \e Op. This visitor is intended to be
 * called by one of `yaul::apply_visitor()` functions.
 */ // }}}
template<op_t Op, typename Value>
struct eval_ternary_op_visitor
  : yaul::static_visitor<bool>
{
  /** // doc: Array {{{
   * \brief Array of values of \e Values
   */ //}}}
  using Array = array<Value>;
  /** // doc: Object {{{
   * \brief Object with \e Values
   */ // }}}
  using Object = object<Value>;
  /** // doc: eval_ternary_op_visitor() {{{
   * \brief Constructor
   * \param r reference to a variable where the operation result will be stored
   *        after of successful application of the operator \e Op
   *
   * The functor, when called successfully (see \ref operator()()), will store
   * its result in a variable referenced by \e r.
   */ // }}}
  eval_ternary_op_visitor(Value& r)
    : result(r)
  { }
  /** // doc operator() {{{
   * \brief Tries to apply operator \e Op to operands \e x1, \e x2
   * \tparam T1 type of the first operand,
   * \tparam T2 type of the second operand,
   * \tparam T3 type of the third operand,
   * \param x1 first operand,
   * \param x2 second operand,
   * \param x2 third operand.
   * \return `true` if the operator was successfully applied or `false`
   *         otherwise
   *
   * If succesfull, the method stores the result of operation under the
   * reference \e r provided as an argument to the 
   * \ref eval_ternary_op_visitor(Value&) "constructor".
   */ // }}}
  template<typename T1, typename T2, typename T3>
  bool operator()(T1 const& x1, T2 const& x2, T3 const& x3) const
  { return apply(x1, x2, x3, typename can_apply_ternary_op<Op,T1,T2,T3>::type()); }
protected:
  /** // doc: apply() {{{
   * \brief Applies the operator \e Op to operands
   * \tparam T1 type of the first operand,
   * \tparam T2 type of the second operand,
   * \tparam T3 type of the third operand,
   * \param x1 first operand,
   * \param x2 second operand,
   * \param x3 third operand.
   * \returns `true`
   *
   * This statically dispatched method handles operands compatible with the
   * operator \e Op. It applies the operator \e Op to operands \e x1, \e x2,
   * \e x3, stores result under a reference provided as the argument \e r to
   * the \ref eval_ternary_op_visitor(Value&) "constructor", and returns `true`.
   */ // }}}
  template<typename T1, typename T2, typename T3>
  bool apply(T1 const& x1, T2 const& x2, T3 const& x3, yaul::tml::true_) const
  {
    result = disambiguate<value_traits<Value> >(apply_ternary_op<Op>::apply(x1, x2, x3));
    return true;
  }
  /** // doc: apply() {{{
   * \brief Specialization of ternary operations on arrays
   *
   * \param x1 first operand,
   * \param x2 second operand,
   * \param x3 third operand.
   * \returns `true` if arrays \e x1, \e x2, \e x3 are compatible with operator
   *          \e Op, or `false` otherwise
   *
   * Whether the \e x1, \e x2, \e x3 are compatible with \e Op is determined at
   * runtime (because this depends on the dimension, sizes and contents of
   * arrays which is know only at runtime).
   */ // }}}
  bool apply(Array const& x1, Array const& x2, Array const& x3, yaul::tml::true_) const
  {
    if(x1.size() != x2.size() || x1.size() != x3.size()) return false;
    array<Value> r(x1.size());
    for(size_t i = 0; i != r.size(); ++i)
      {
        auto op = eval_ternary_op_visitor<Op, Value>(r[i]);
        if(!yaul::apply_visitor(op, x1[i], x2[i], x3[i]))
          return false;
      }
    result = std::forward<array<Value> >(r);
    return true;
  }
  /** // doc: apply() {{{
   * \brief Specialization of ternary operations on arrays
   *
   * \param x1 first operand,
   * \param x2 second operand,
   * \param x3 third operand.
   * \returns currently it does nothing and always returns `false`
   */ // }}}
  bool apply(Object const&, Object const&, Object const&, yaul::tml::true_) const
  {
    // TODO: elaborate if we're able to apply ternary ops to objects somehow??
    return false;
  }
  /** // doc: apply() {{{
   * \brief Does nothing and returns `false`
   * \tparam T1 type of the first operand,
   * \tparam T2 type of the second operand,
   * \tparam T3 type of the third operand,
   * \param x1 first operand,
   * \param x2 second operand,
   * \param x3 third operand.
   * \returns `false`
   *
   * This statically dispatched method handles operands incompatible with the
   * operator \e Op. It always  returns `false`. The data under the reference
   * provided as an argument to the \ref eval_ternary_op_visitor(Value&)
   * "constructor" remains unchanged.
   */ // }}}
  template<typename T1, typename T2, typename T3>
  bool apply(T1 const&, T2 const&, T3 const&, yaul::tml::false_) const
  { return false; }
private:
  Value& result;
};
/** // doc: eval_ternary_op() {{{
 * \ingroup VmGroup
 * \brief Creates \ref txpl::vm::eval_ternary_op_visitor "vm::eval_ternary_op_visitor<>"
 *
 * \tparam Op operator identifier, see \ref txpl::vm::op_t "vm::op_t",
 * \tparam Value a universal (variant) value type used to store the result of
 *         operation
 * \param result reference to a variable, where the result of operation
 *        shall be stored after successful use of the created functor.
 *
 * \b Example:
 * \snippet eval_ternary_op1.cpp Code
 * \b Output:
 * \snippet eval_ternary_op1.cpp Output
 */ // }}}
template<op_t Op, typename Value>
eval_ternary_op_visitor<Op, Value>
eval_ternary_op(Value& result)
{ return eval_ternary_op_visitor<Op, Value>(result); }
} } // end namespace txpl::vm

#endif /* TXPL_VM_EVAL_TERNARY_OP_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
