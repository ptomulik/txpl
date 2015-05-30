// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/eval_binary_op.hpp

/** // doc: txpl/vm/eval_binary_op.hpp {{{
 * \file txpl/vm/eval_binary_op.hpp
 * \brief Implements \ref txml::vm::eval_binary_op() "vm::eval_binary_op()"
 */ // }}}
#ifndef TXPL_VM_EVAL_BINARY_OP_HPP_INCLUDED
#define TXPL_VM_EVAL_BINARY_OP_HPP_INCLUDED

#include <txpl/vm/can_apply_binary_op.hpp>
#include <txpl/vm/apply_binary_op.hpp>
#include <txpl/vm/op_t.hpp>
#include <txpl/vm/disambiguate.hpp>
#include <txpl/vm/value_traits.hpp>
#include <txpl/vm/array.hpp>
#include <txpl/vm/object.hpp>
#include <txpl/vm/dict.hpp>
#include <yaul/tml/bool.hpp>
#include <yaul/variant/apply_visitor.hpp>
#include <yaul/variant/static_visitor.hpp>
#include <regex>

namespace txpl { namespace vm {
/** // doc: eval_binary_op_visitor {{{
 * \ingroup VmGroup
 * \brief Applies binary operator to its operands
 *
 * \tparam Op identifier of the binary operator, see \ref txpl::vm::op_t "vm::op_t"
 * \tparam Value a universal (variant) value type used to store result of the operation.
 *
 * The purpose of this functor is to either invoke appropriate instantiation of
 * the \ref txpl::vm::apply_binary_op "vm::apply_binary_op<>" or to
 * indicate an error if the operands provided to the functor are not
 * compatible with the given operator \e Op. This visitor is intended to be
 * called by one of `yaul::apply_visitor()` functions.
 */ // }}}
template<op_t Op, typename Value>
struct eval_binary_op_visitor
  : yaul::static_visitor<bool>
{
  /** // doc: eval_binary_op_visitor() {{{
   * \brief Constructor
   * \param r reference to a variable where the operation result will be stored
   *        after of successful application of the operator \e Op
   *
   * The functor, when called successfully (see \ref operator()()), will store
   * its result in a variable referenced by \e r.
   */ // }}}
  eval_binary_op_visitor(Value& r)
    : result(r)
  { }
  /** // doc operator() {{{
   * \brief Tries to apply operator \e Op to operands \e x1, \e x2
   * \tparam T1 type of the first operand,
   * \tparam T2 type of the second operand,
   * \param x1 first operand,
   * \param x2 second operand.
   * \return `true` if the operator was successfully applied or `false`
   *         otherwise
   *
   * If succesfull, the method stores the result of operation under the
   * reference \e r provided as an argument to the 
   * \ref eval_binary_op_visitor(Value&) "constructor".
   */ // }}}
  template<typename T1, typename T2>
  bool operator()(T1 const& x1, T2 const& x2) const
  { return apply(x1, x2, typename can_apply_binary_op<Op,T1,T2>::type()); }
protected:
  /** // doc: apply() {{{
   * \brief Applies the operator \e Op to operands
   * \tparam T1 type of the first operand,
   * \tparam T2 type of the second operand,
   * \param x1 first operand,
   * \param x2 second operand.
   * \returns `true`
   *
   * This statically dispatched method handles operands compatible with the
   * operator \e Op. It applies the operator \e Op to operands \e x1, \e x2,
   * stores result under a reference provided as the argument \e r to the
   * \ref eval_binary_op_visitor(Value&) "constructor", and returns `true`.
   */ // }}}
  template<typename T1, typename T2>
  bool apply(T1 const& x1, T2 const& x2, yaul::tml::true_) const
  {
    result = disambiguate<value_traits<Value> >(apply_binary_op<Op>::apply(x1, x2));
    return true;
  }
  /** // doc: apply() {{{
   * \brief Does nothing and returns `false`
   * \tparam T1 type of the first operand,
   * \tparam T2 type of the second operand,
   * \param x1 first operand,
   * \param x2 second operand.
   * \returns `false`
   *
   * This statically dispatched method handles operands incompatible with the
   * operator \e Op. It always  returns `false`. The data under the reference
   * provided as an argument to the \ref eval_binary_op_visitor(Value&)
   * "constructor" remains unchanged.
   */ // }}}
  template<typename T1, typename T2>
  bool apply(T1 const&, T2 const&, yaul::tml::false_) const
  { return false; }
  /** // doc: apply() {{{
   * \brief Specialization of binary operations on arrays
   *
   * \param x1 first operand,
   * \param x2 second operand.
   * \returns `true` if arrays \e x1, \e x2 are compatible with operator \e Op,
   *           or `false` otherwise
   *
   * Whether the \e x1, \e x2 are compatible with \e Op is determined at
   * runtime (because this depends on the dimension, sizes and contents of
   * arrays which is know only at runtime).
   */ // }}}
  bool apply(array<Value> const& x1, array<Value> const& x2) const
  {
    if(x1.size() != x2.size()) return false;
    array<Value> r(x1.size());
    for(size_t i = 0; i != r.size(); ++i)
      {
        auto op = eval_binary_op_visitor<Op,Value>(r[i]);
        if(!yaul::apply_visitor(op, x1[i], x2[i]))
          return false;
      }
    result = std::forward<array<Value> >(r);
    return true;
  }
  /** // doc: apply() {{{
   * \brief Specialization of binary operations on arrays
   *
   * \param x1 first operand,
   * \param x2 second operand.
   * \returns `true` if arrays \e x1, \e x2 are compatible with operator \e op_t::subscript_,
   *           or `false` otherwise
   *
   * Whether the \e x1, \e x2 are compatible with \e op_t::subscript_ is determined at
   * runtime (because this depends on the dimension, sizes and contents of
   * arrays which is know only at runtime).
   */ // }}}
  bool apply(array<Value> const& x1, array<Value> const& x2, yaul::tml::false_) const
  { return apply(x1, x2); }
  /** // doc: apply() {{{
   * \brief Specialization of binary operations on arrays
   *
   * \param x1 first operand,
   * \param x2 second operand.
   * \returns `true` if arrays \e x1, \e x2 are compatible with operator \e op_t::subscript_,
   *           or `false` otherwise
   *
   * Whether the \e x1, \e x2 are compatible with \e op_t::subscript_ is determined at
   * runtime (because this depends on the dimension, sizes and contents of
   * arrays which is know only at runtime).
   */ // }}}
  bool apply(array<Value> const& x1, array<Value> const& x2, yaul::tml::true_) const
  { return apply(x1, x2); }
  /** // doc: apply() {{{
   * \brief Specialization of binary operations on arrays
   *
   * \param x1 first operand,
   * \param x2 second operand.
   * \returns currently it does nothing and always returns `false`
   */ // }}}
  bool apply(object<Value> const&, object<Value> const&, yaul::tml::true_) const
  {
    // TODO: elaborate if we're able to apply binary ops to objects somehow??
    return false;
  }
private:
  Value& result;
};
/** // doc: eval_binary_op_visitor {{{
 * \ingroup VmGroup
 * \brief Specialization of \ref txpl::vm::eval_binary_op_visitor
 *        "vm::eval_binary_op_visitor" for subscript operator ``[]``
 */ // }}}
template<typename Value>
struct eval_binary_op_visitor<op_t::subscript_, Value>
  : yaul::static_visitor<bool>
{
  /** // doc: eval_binary_op_visitor() {{{
   * \brief Constructor
   * \param r reference to a variable where the operation result will be stored
   *        after of successful application of the operator \e op_t::subscript_
   *
   * The functor, when called successfully (see \ref operator()()), will store
   * its result in a variable referenced by \e r.
   */ // }}}
  eval_binary_op_visitor(Value& r)
    : result(r)
  { }
  /** // doc operator() {{{
   * \brief Tries to apply operator \e op_t::subscript_ to operands \e x1, \e x2
   * \tparam T1 type of the first operand,
   * \tparam T2 type of the second operand,
   * \param x1 first operand,
   * \param x2 second operand.
   * \return `true` if the operator was successfully applied or `false`
   *         otherwise
   *
   * If succesfull, the method stores the result of operation under the
   * reference \e r provided as an argument to the 
   * \ref eval_binary_op_visitor(Value&) "constructor".
   */ // }}}
  template<typename T1, typename T2>
  bool operator()(T1 const& x1, T2 const& x2) const
  { return apply(x1, x2, typename can_apply_binary_op<op_t::subscript_,T1,T2>::type()); }
protected:
  /** // doc: apply() {{{
   * \brief Applies the operator \e op_t::subscript_ to operands
   * \tparam T1 type of the first operand,
   * \tparam T2 type of the second operand,
   * \param x1 first operand,
   * \param x2 second operand.
   * \returns `true`
   *
   * This statically dispatched method handles operands compatible with the
   * operator \e op_t::subscript_. It applies the operator \e op_t::subscript_ to operands \e x1, \e x2,
   * stores result under a reference provided as the argument \e r to the
   * \ref eval_binary_op_visitor(Value&) "constructor", and returns `true`.
   */ // }}}
  template<typename T1, typename T2>
  bool apply(dict<T1> const& x1, T2 const& x2, yaul::tml::true_) const
  {
    auto it = x1.find(x2);
    if(it == x1.end())
      return false;
    result = disambiguate<value_traits<Value> >(it->second);
    return true;
  }
  /** // doc: apply() {{{
   * \brief Applies the operator \e op_t::subscript_ to operands
   * \tparam T1 type of the first operand,
   * \tparam T2 type of the second operand,
   * \param x1 first operand,
   * \param x2 second operand.
   * \returns `true`
   *
   * This statically dispatched method handles operands compatible with the
   * operator \e op_t::subscript_. It applies the operator \e op_t::subscript_ to operands \e x1, \e x2,
   * stores result under a reference provided as the argument \e r to the
   * \ref eval_binary_op_visitor(Value&) "constructor", and returns `true`.
   */ // }}}
  template<typename T1, typename T2>
  bool apply(T1 const& x1, T2 const& x2, yaul::tml::true_) const
  {
    if(x2 < T2{0} || static_cast<typename T1::size_type>(x2) >= x1.size())
      return false;
    result = disambiguate<value_traits<Value> >(x1[x2]);
    return true;
  }
  /** // doc: apply() {{{
   * \brief Specialization of binary operations on arrays
   *
   * \param x1 first operand,
   * \param x2 second operand.
   * \returns `true` if arrays \e x1, \e x2 are compatible with operator \e op_t::subscript_,
   *           or `false` otherwise
   *
   * Whether the \e x1, \e x2 are compatible with \e op_t::subscript_ is determined at
   * runtime (because this depends on the dimension, sizes and contents of
   * arrays which is know only at runtime).
   */ // }}}
  bool apply(array<Value> const& x1, array<Value> const& x2) const
  {
    if(x1.size() != x2.size()) return false;
    array<Value> r(x1.size());
    for(size_t i = 0; i != r.size(); ++i)
      {
        auto op = eval_binary_op_visitor<op_t::subscript_,Value>(r[i]);
        if(!yaul::apply_visitor(op, x1[i], x2[i]))
          return false;
      }
    result = std::forward<array<Value> >(r);
    return true;
  }
  /** // doc: apply() {{{
   * \brief Specialization of binary operations on arrays
   *
   * \param x1 first operand,
   * \param x2 second operand.
   * \returns `true` if arrays \e x1, \e x2 are compatible with operator \e op_t::subscript_,
   *           or `false` otherwise
   *
   * Whether the \e x1, \e x2 are compatible with \e op_t::subscript_ is determined at
   * runtime (because this depends on the dimension, sizes and contents of
   * arrays which is know only at runtime).
   */ // }}}
  bool apply(array<Value> const& x1, array<Value> const& x2, yaul::tml::false_) const
  { return apply(x1, x2); }
  /** // doc: apply() {{{
   * \brief Specialization of binary operations on arrays
   *
   * \param x1 first operand,
   * \param x2 second operand.
   * \returns `true` if arrays \e x1, \e x2 are compatible with operator \e op_t::subscript_,
   *           or `false` otherwise
   *
   * Whether the \e x1, \e x2 are compatible with \e op_t::subscript_ is determined at
   * runtime (because this depends on the dimension, sizes and contents of
   * arrays which is know only at runtime).
   */ // }}}
  bool apply(array<Value> const& x1, array<Value> const& x2, yaul::tml::true_) const
  { return apply(x1, x2); }
#if 0
  /** // doc: apply() {{{
   * \brief Specialization of binary operations on arrays
   *
   * \param x1 first operand,
   * \param x2 second operand.
   * \returns currently it does nothing and always returns `false`
   */ // }}}
  bool apply(object<Value> const&, object<Value> const&, yaul::tml::true_) const
  {
    // TODO: elaborate if we're able to apply binary ops to objects somehow??
    return false;
  }
#endif
  /** // doc: apply() {{{
   * \brief Does nothing and returns `false`
   * \tparam T1 type of the first operand,
   * \tparam T2 type of the second operand,
   * \param x1 first operand,
   * \param x2 second operand.
   * \returns `false`
   *
   * This statically dispatched method handles operands incompatible with the
   * operator \e op_t::subscript_. It always  returns `false`. The data under the reference
   * provided as an argument to the \ref eval_binary_op_visitor(Value&)
   * "constructor" remains unchanged.
   */ // }}}
  template<typename T1, typename T2>
  bool apply(T1 const&, T2 const&, yaul::tml::false_) const
  { return false; }
private:
  Value& result;
};
/** // doc: eval_binary_op() {{{
 * \ingroup VmGroup
 * \brief Creates \ref txpl::vm::eval_binary_op_visitor "vm::eval_binary_op_visitor<>"
 *
 * \tparam Op operator identifier, see \ref txpl::vm::op_t "vm::op_t",
 * \tparam Value a universal (variant) value type used to store the result of
 *         operation
 * \param result reference to a variable, where the result of operation
 *        shall be stored after successful use of the created functor.
 *
 * \b Example:
 * \snippet eval_binary_op1.cpp Code
 * \b Output:
 * \snippet eval_binary_op1.cpp Output
 */ // }}}
template<op_t Op, typename Value>
eval_binary_op_visitor<Op, Value>
eval_binary_op(Value& result)
{ return eval_binary_op_visitor<Op, Value>(result); }
} } // end namespace txpl::vm

#endif /* TXPL_VM_EVAL_BINARY_OP_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
