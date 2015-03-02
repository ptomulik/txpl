// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/eval_unary_op.hpp

/** // doc: txpl/vm/eval_unary_op.hpp {{{
 * \file txpl/vm/eval_unary_op.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_VM_EVAL_UNARY_OP_HPP_INCLUDED
#define TXPL_VM_EVAL_UNARY_OP_HPP_INCLUDED

#include <txpl/vm/disambiguate.hpp>
#include <txpl/vm/op_t.hpp>
#include <tml/enable_if_type.hpp>
#include <tml/bool.hpp>
#include <utility>

namespace txpl { namespace vm {
/** // doc: can_apply_unary_op {{{
 * \todo Write documentation
 */ // }}}
template<op_t Op>
struct apply_unary_op;
/** // doc: can_apply_unary_op {{{
 * \todo Write documentation
 */ // }}}
template<op_t Op, typename T, typename Enable = void>
struct can_apply_unary_op : tml::false_ { };

/** // doc: apply_unary_op<plus_> {{{
 * \todo Write documentation
 */ // }}}
template<>
struct apply_unary_op<op_t::plus_>
{
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  template<typename T>
  static auto apply(T x) -> decltype(+x)
  { return +x; }
};
/** // doc: apply_unary_op<minus_> {{{
 * \todo Write documentation
 */ // }}}
template<>
struct apply_unary_op<op_t::minus_>
{
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  template<typename T>
  static auto apply(T x) -> decltype(-x)
  { return -x; }
};
/** // doc: apply_unary_op<not_> {{{
 * \todo Write documentation
 */ // }}}
template<>
struct apply_unary_op<op_t::not_>
{
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  template<typename T>
  static auto apply(T x) -> decltype(!x)
  { return !x; }
};
/** // doc: apply_unary_op<neg_> {{{
 * \todo Write documentation
 */ // }}}
template<>
struct apply_unary_op<op_t::neg_>
{
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  template<typename T>
  static auto apply(T x) -> decltype(~T()) // "~x" does no work under g++4.9.2
  { return ~x; }
};
/** // doc: can_apply_plus {{{
 * \todo Write documentation
 */ // }}}
template<op_t Op, typename T>
struct can_apply_unary_op<
  Op, T, typename tml::enable_if_type<
    decltype(apply_unary_op<Op>::apply(T()))
  >::type
>
  : tml::true_
{ };

/** // doc: eval_unary_op_visitor {{{
 * \todo Write documentation
 */ // }}}
template<op_t Op, typename BasicTypes, typename Value>
struct eval_unary_op_visitor
{
  /** // doc: result_type {{{
   * \todo Write documentation
   */ // }}}
  typedef bool result_type;
  /** // doc: eval_unary_op_visitor() {{{
   * \todo Write documentation
   */ // }}}
  eval_unary_op_visitor(Value& r)
    : result(r)
  { }
  /** // doc operator() {{{
   * \todo Write documentation
   */ // }}}
  template<typename T>
  result_type operator()(T const& x) const
  { return apply(x, typename can_apply_unary_op<Op,T>::type()); }
protected:
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  template<typename T>
  result_type apply(T const& x, tml::true_) const
  {
    result = disambiguate<BasicTypes>(apply_unary_op<Op>::apply(x));
    return true;
  }
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  template<typename T>
  result_type apply(T const&, tml::false_) const
  { return false; }
private:
  Value& result;
};
/** // doc: eval_unary_op() {{{
 * \todo Write documentation
 */ // }}}
template<op_t Op, typename BasicTypes, typename Value>
eval_unary_op_visitor<Op, BasicTypes, Value>
eval_unary_op(Value& result)
{
  return eval_unary_op_visitor<Op, BasicTypes, Value>(result);
}
} } // end namespace txpl::vm

#endif /* TXPL_VM_EVAL_UNARY_OP_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
