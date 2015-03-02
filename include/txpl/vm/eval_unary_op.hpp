// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/eval_unary_op.hpp

/** // doc: txpl/vm/eval_unary_op.hpp {{{
 * \file txpl/vm/eval_unary_op.hpp
 * \brief Implements the \ref txpl::vm::eval_unary_op_visitor "vm::eval_unary_op_visitor<>"
 */ // }}}
#ifndef TXPL_VM_EVAL_UNARY_OP_HPP_INCLUDED
#define TXPL_VM_EVAL_UNARY_OP_HPP_INCLUDED

#include <txpl/vm/can_apply_unary_op.hpp>
#include <txpl/vm/apply_unary_op.hpp>
#include <txpl/vm/disambiguate.hpp>
#include <txpl/vm/value_traits.hpp>
#include <txpl/vm/op_t.hpp>
#include <txpl/vm/array.hpp>
#include <tml/bool.hpp>
#include <boost/variant/static_visitor.hpp>

namespace txpl { namespace vm {
/** // doc: eval_unary_op_visitor {{{
 * \ingroup VmGroup
 * \brief Applies unary operator to an operand
 *
 * \tparam Op identifier of the unary operator, see \ref txpl::vm::op_t "vm::op_t"
 * \tparam Value a universal (variant) value type used to store result of the operation.
 *
 * The purpose of this functor is to either invoke appropriate instantiation of
 * the \ref txpl::vm::apply_unary_op "vm::apply_unary_op<>" or to
 * indicate an error if the operands provided to the functor are not
 * compatible with the given operator \e Op. This visitor is intended to be
 * called by one of `boost::apply_visitor()` functions.
 */ // }}}
template<op_t Op, typename Value>
struct eval_unary_op_visitor
  : boost::static_visitor<bool>
{
  /** // doc: eval_unary_op_visitor() {{{
   * \brief Constructor
   * \param r reference to a variable where the operation result will be stored
   *        after successful application of the operator \e Op
   *
   * The functor, when called successfully (see \ref operator()()), will store
   * its result in a variable referenced by \e r.
   */ // }}}
  eval_unary_op_visitor(Value& r)
    : result(r)
  { }
  /** // doc operator() {{{
   * \brief Tries to apply operator \e Op to operand \e x
   * \tparam T type of the operand,
   * \param x the operand,
   * \return `true` if the operator was successfully applied or `false`
   *         otherwise
   *
   * If succesfull, the method stores the result of operation under the
   * reference \e r provided as an argument to the 
   * \ref eval_unary_op_visitor(Value&) "constructor".
   */ // }}}
  template<typename T>
  bool operator()(T const& x) const
  { return apply(x, typename can_apply_unary_op<Op,T>::type()); }
protected:
  /** // doc: apply() {{{
   * \brief Applies the operator \e Op to operand
   * \tparam T type of the operand,
   * \param x the operand,
   * \returns `true`
   *
   * This statically dispatched method handles operands compatible with the
   * operator \e Op. It applies the operator \e Op to operand \e x,
   * stores result under a reference provided as the argument \e r to the
   * \ref eval_unary_op_visitor(Value&) "constructor", and returns `true`.
   */ // }}}
  template<typename T>
  bool apply(T const& x, tml::true_) const
  {
    result = disambiguate<value_traits<Value> >(apply_unary_op<Op>::apply(x));
    return true;
  }
  /** // doc: apply() {{{
   * \brief Applies the operator \e Op to operand
   * \tparam T type of the operand,
   * \param x the operand,
   * \returns `true`
   *
   * This statically dispatched method handles operands compatible with the
   * operator \e Op. It applies the operator \e Op to operand \e x,
   * stores result under a reference provided as the argument \e r to the
   * \ref eval_unary_op_visitor(Value&) "constructor", and returns `true`.
   */ // }}}
  bool apply(array<Value> const& x) const
  {
    array<Value> r(x.size());
    for(size_t i = 0; i != r.size(); ++i)
      {
        auto op = eval_unary_op_visitor<Op,Value>(r[i]);
        if(!boost::apply_visitor(op, x[i]))
          return false;
      }
    result = std::forward<array<Value> >(r);
    return true;
  }
  /** // doc: apply() {{{
   * \brief Applies the operator \e Op to operand
   * \tparam T type of the operand,
   * \param x the operand,
   * \returns `true`
   *
   * This statically dispatched method handles operands compatible with the
   * operator \e Op. It applies the operator \e Op to operand \e x,
   * stores result under a reference provided as the argument \e r to the
   * \ref eval_unary_op_visitor(Value&) "constructor", and returns `true`.
   */ // }}}
  bool apply(array<Value> const& x, tml::true_) const
  { return apply(x); }
  /** // doc: apply() {{{
   * \brief Applies the operator \e Op to operand
   * \tparam T type of the operand,
   * \param x the operand,
   * \returns `true`
   *
   * This statically dispatched method handles operands compatible with the
   * operator \e Op. It applies the operator \e Op to operand \e x,
   * stores result under a reference provided as the argument \e r to the
   * \ref eval_unary_op_visitor(Value&) "constructor", and returns `true`.
   */ // }}}
  bool apply(array<Value> const& x, tml::false_) const
  { return apply(x); }
  /** // doc: apply() {{{
   * \brief Does nothing and returns `false`
   * \tparam T type of the operand,
   * \param x the operand,
   * \returns `false`
   *
   * This statically dispatched method handles operands incompatible with the
   * operator \e Op. It always  returns `false`. The data under the reference
   * provided as an argument to the * \ref eval_unary_op_visitor(Value&)
   * "constructor" remains unchanged.
   */ // }}}
  template<typename T>
  bool apply(T const&, tml::false_) const
  { return false; }
private:
  Value& result;
};
/** // doc: eval_unary_op() {{{
 * \ingroup VmGroup
 * \brief Creates \ref txpl::vm::eval_unary_op_visitor "vm::eval_unary_op_visitor<>"
 *
 * \tparam Op operator identifier, see \ref txpl::vm::op_t "vm::op_t",
 * \tparam Value a universal (variant) value type used to store the result of
 *         operation
 * \param result reference to a variable, where the result of operation
 *        shall be stored after successful use of the created functor.
 *
 * \b Example:
 * \snippet eval_unary_op1.cpp Code
 * \b Output:
 * \snippet eval_unary_op1.cpp Output
 */ // }}}
template<op_t Op, typename Value>
eval_unary_op_visitor<Op, Value>
eval_unary_op(Value& result)
{ return eval_unary_op_visitor<Op, Value>(result); }
} } // end namespace txpl::vm

#endif /* TXPL_VM_EVAL_UNARY_OP_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
