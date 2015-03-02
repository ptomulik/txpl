// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/eval_binary_op.hpp

/** // doc: txpl/vm/eval_binary_op.hpp {{{
 * \file txpl/vm/eval_binary_op.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_VM_EVAL_BINARY_OP_HPP_INCLUDED
#define TXPL_VM_EVAL_BINARY_OP_HPP_INCLUDED

#include <txpl/vm/op_t.hpp>
#include <txpl/vm/disambiguate.hpp>
#include <txpl/vm/array.hpp>
#include <txpl/vm/object.hpp>
#include <tml/enable_if_type.hpp>
#include <tml/bool.hpp>
#include <boost/variant/apply_visitor.hpp>
#include <utility>
#include <regex>

namespace txpl { namespace vm {

/** // doc: apply_binary_op {{{
 * \todo Write documentation
 */ // }}}
template<op_t Op>
struct apply_binary_op;
/** // doc: can_apply_binary_op {{{
 * \todo Write documentation
 */ // }}}
template<op_t Op, typename T1, typename T2, typename Enable = void>
struct can_apply_binary_op : tml::false_ { };

/** // doc: apply_binary_op<or> {{{
 * \todo Write documentation
 */ // }}}
template<>
struct apply_binary_op<op_t::or_>
{
  template<typename T1, typename T2>
  static auto apply(T1 x1, T2 x2) -> decltype(x1 || x2)
  { return x1 || x2; }
};
/** // doc: apply_binary_op<and> {{{
 * \todo Write documentation
 */ // }}}
template<>
struct apply_binary_op<op_t::and_>
{
  template<typename T1, typename T2>
  static auto apply(T1 x1, T2 x2) -> decltype(x1 && x2)
  { return x1 && x2; }
};
/** // doc: apply_binary_op<bitor> {{{
 * \todo Write documentation
 */ // }}}
template<>
struct apply_binary_op<op_t::bitor_>
{
  template<typename T1, typename T2>
  static auto apply(T1 x1, T2 x2) -> decltype(x1 | x2)
  { return x1 | x2; }
};
/** // doc: apply_binary_op<xor> {{{
 * \todo Write documentation
 */ // }}}
template<>
struct apply_binary_op<op_t::xor_>
{
  template<typename T1, typename T2>
  static auto apply(T1 x1, T2 x2) -> decltype(x1 ^ x2)
  { return x1 ^ x2; }
};
/** // doc: apply_binary_op<bitand> {{{
 * \todo Write documentation
 */ // }}}
template<>
struct apply_binary_op<op_t::bitand_>
{
  template<typename T1, typename T2>
  static auto apply(T1 x1, T2 x2) -> decltype(x1 & x2)
  { return x1 & x2; }
};
/** // doc: apply_binary_op<eq> {{{
 * \todo Write documentation
 */ // }}}
template<>
struct apply_binary_op<op_t::eq_>
{
  template<typename T1, typename T2>
  static auto apply(T1 x1, T2 x2) -> decltype(x1 == x2)
  { return x1 == x2; }
};
/** // doc: apply_binary_op<neq> {{{
 * \todo Write documentation
 */ // }}}
template<>
struct apply_binary_op<op_t::neq_>
{
  template<typename T1, typename T2>
  static auto apply(T1 x1, T2 x2) -> decltype(x1 != x2)
  { return x1 != x2; }
};
/** // doc: apply_binary_op<eq> {{{
 * \todo Write documentation
 */ // }}}
template<>
struct apply_binary_op<op_t::match_>
{
  template<typename T1, typename T2>
  static auto apply(T1 x1, T2 x2) -> decltype(std::regex_match(x1,x2))
  { return std::regex_match(x1,x2); }
};
/** // doc: apply_binary_op<eq> {{{
 * \todo Write documentation
 */ // }}}
template<>
struct apply_binary_op<op_t::nmatch_>
{
  template<typename T1, typename T2>
  static auto apply(T1 x1, T2 x2) -> decltype(!std::regex_match(x1,x2))
  { return !std::regex_match(x1,x2); }
};
/** // doc: apply_binary_op<lt> {{{
 * \todo Write documentation
 */ // }}}
template<>
struct apply_binary_op<op_t::lt_>
{
  template<typename T1, typename T2>
  static auto apply(T1 x1, T2 x2) -> decltype(x1 < x2)
  { return x1 < x2; }
};
/** // doc: apply_binary_op<gt> {{{
 * \todo Write documentation
 */ // }}}
template<>
struct apply_binary_op<op_t::gt_>
{
  template<typename T1, typename T2>
  static auto apply(T1 x1, T2 x2) -> decltype(x1 > x2)
  { return x1 > x2; }
};
/** // doc: apply_binary_op<le> {{{
 * \todo Write documentation
 */ // }}}
template<>
struct apply_binary_op<op_t::le_>
{
  template<typename T1, typename T2>
  static auto apply(T1 x1, T2 x2) -> decltype(x1 <= x2)
  { return x1 <= x2; }
};
/** // doc: apply_binary_op<ge> {{{
 * \todo Write documentation
 */ // }}}
template<>
struct apply_binary_op<op_t::ge_>
{
  template<typename T1, typename T2>
  static auto apply(T1 x1, T2 x2) -> decltype(x1 >= x2)
  { return x1 >= x2; }
};
/** // doc: apply_binary_op<lshift> {{{
 * \todo Write documentation
 */ // }}}
template<>
struct apply_binary_op<op_t::lshift_>
{
  template<typename T1, typename T2>
  static auto apply(T1 x1, T2 x2) -> decltype(x1 << x2)
  { return x1 << x2; }
};
/** // doc: apply_binary_op<rshift> {{{
 * \todo Write documentation
 */ // }}}
template<>
struct apply_binary_op<op_t::rshift_>
{
  template<typename T1, typename T2>
  static auto apply(T1 x1, T2 x2) -> decltype(x1 >> x2)
  { return x1 >> x2; }
};
/** // doc: apply_binary_op<plus> {{{
 * \todo Write documentation
 */ // }}}
template<>
struct apply_binary_op<op_t::plus_>
{
  template<typename T1, typename T2>
  static auto apply(T1 x1, T2 x2) -> decltype(x1 + x2)
  { return x1 + x2; }
};
/** // doc: apply_binary_op<minus> {{{
 * \todo Write documentation
 */ // }}}
template<>
struct apply_binary_op<op_t::minus_>
{
  template<typename T1, typename T2>
  static auto apply(T1 x1, T2 x2) -> decltype(x1 - x2)
  { return x1 - x2; }
};
/** // doc: apply_binary_op<mul> {{{
 * \todo Write documentation
 */ // }}}
template<>
struct apply_binary_op<op_t::mul_>
{
  template<typename T1, typename T2>
  static auto apply(T1 x1, T2 x2) -> decltype(x1 * x2)
  { return x1 * x2; }
};
/** // doc: apply_binary_op<div> {{{
 * \todo Write documentation
 */ // }}}
template<>
struct apply_binary_op<op_t::div_>
{
  template<typename T1, typename T2>
  static auto apply(T1 x1, T2 x2) -> decltype(x1 / x2)
  { return x1 / x2; }
};
/** // doc: apply_binary_op<mod> {{{
 * \todo Write documentation
 */ // }}}
template<>
struct apply_binary_op<op_t::mod_>
{
  template<typename T1, typename T2>
  static auto apply(T1 x1, T2 x2) -> decltype(x1 % x2)
  { return x1 % x2; }
};
/** // doc: can_apply_or {{{
 * \todo Write documentation
 */ // }}}
template<op_t Op, typename T1, typename T2>
struct can_apply_binary_op<
    Op, T1, T2
  , typename tml::enable_if_type<
      decltype(apply_binary_op<Op>::apply(T1(),T2()))
    >::type
>
  : tml::true_ { };
/** // doc: eval_binary_op_visitor {{{
 * \todo Write documentation
 */ // }}}
template<op_t Op, typename BasicTypes, typename Value>
struct eval_binary_op_visitor
{
  /** // doc: result_type {{{
   * \todo Write documentation
   */ // }}}
  typedef bool result_type;
  /** // doc: eval_binary_op_visitor() {{{
   * \todo Write documentation
   */ // }}}
  eval_binary_op_visitor(Value& r)
    : result(r)
  { }
  /** // doc operator() {{{
   * \todo Write documentation
   */ // }}}
  template<typename T1, typename T2>
  result_type operator()(T1 const& x1, T2 const& x2) const
  { return apply(x1, x2, typename can_apply_binary_op<Op,T1,T2>::type()); }
protected:
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  template<typename T1, typename T2>
  result_type apply(T1 const& x1, T2 const& x2, tml::true_) const
  {
    result = disambiguate<BasicTypes>(apply_binary_op<Op>::apply(x1, x2));
    return true;
  }
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  result_type apply(array<Value> const& x1, array<Value> const& x2, tml::true_) const
  {
    if(x1.size() != x2.size()) return false;
    array<Value> r(x1.size());
    for(size_t i = 0; i != r.size(); ++i)
      {
        auto op = eval_binary_op_visitor<Op,BasicTypes,Value>(r[i]);
        if(!boost::apply_visitor(op, x1[i], x2[i]))
          return false;
      }
    result = std::forward<array<Value> >(r);
    return true;
  }
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  result_type apply(object<Value> const&, object<Value> const&, tml::true_) const
  {
    // TODO: elaborate if we're able to apply binary ops to objects somehow??
    return false;
  }
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  template<typename T1, typename T2>
  result_type apply(T1 const&, T2 const&, tml::false_) const
  {
    return false;
  }
private:
  Value& result;
};
/** // doc: eval_binary_op() {{{
 * \todo Write documentation
 */ // }}}
template<op_t Op, typename BasicTypes, typename Value>
eval_binary_op_visitor<Op, BasicTypes, Value>
eval_binary_op(Value& result)
{
  return eval_binary_op_visitor<Op, BasicTypes, Value>(result);
}
} } // end namespace txpl::vm

#endif /* TXPL_VM_EVAL_BINARY_OP_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
