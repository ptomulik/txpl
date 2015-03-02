// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/eval_ternary_op.hpp

/** // doc: txpl/vm/eval_ternary_op.hpp {{{
 * \file txpl/vm/eval_ternary_op.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_VM_EVAL_TERNARY_OP_HPP_INCLUDED
#define TXPL_VM_EVAL_TERNARY_OP_HPP_INCLUDED

#include <txpl/vm/op_t.hpp>
#include <txpl/vm/disambiguate.hpp>
#include <txpl/vm/array.hpp>
#include <txpl/vm/object.hpp>
#include <tml/enable_if_type.hpp>
#include <tml/bool.hpp>
#include <boost/variant/apply_visitor.hpp>
#include <boost/variant/multivisitors.hpp>
#include <utility>

namespace txpl { namespace vm {

/** // doc: apply_ternary_op {{{
 * \todo Write documentation
 */ // }}}
template<op_t Op>
struct apply_ternary_op;
/** // doc: can_apply_ternary_op {{{
 * \todo Write documentation
 */ // }}}
template<op_t Op, typename T1, typename T2, typename T3, typename Enable = void>
struct can_apply_ternary_op : tml::false_ { };

/** // doc: apply_ternary_op<qmark> {{{
 * \todo Write documentation
 */ // }}}
template<>
struct apply_ternary_op<op_t::qmark_>
{
  // We use std::remove_reference<> becaue - according to C++ standard - the
  // ternary conditional expression may be used as an lvalue reference and in
  // some compilers decltype( x1 ? x2 : x3) yields an lvalue reference. This
  // was seen at least in clang 3.5.0.
  template<typename T1, typename T2, typename T3>
  static auto apply(T1 x1, T2 x2, T3 x3)
    -> typename std::remove_reference<decltype(x1 ? x2 : x3)>::type
  { return x1 ?  x2 : x3; }
};
/** // doc: can_apply_or {{{
 * \todo Write documentation
 */ // }}}
template<op_t Op, typename T1, typename T2, typename T3>
struct can_apply_ternary_op<
    Op, T1, T2, T3
  , typename tml::enable_if_type<
      decltype(apply_ternary_op<Op>::apply(T1(),T2(), T3()))
    >::type
>
  : tml::true_ { };
/** // doc: eval_ternary_op_visitor {{{
 * \todo Write documentation
 */ // }}}
template<op_t Op, typename BasicTypes, typename Value>
struct eval_ternary_op_visitor
{
  /** // doc: result_type {{{
   * \todo Write documentation
   */ // }}}
  typedef bool result_type;
  /** // doc: eval_ternary_op_visitor() {{{
   * \todo Write documentation
   */ // }}}
  eval_ternary_op_visitor(Value& r)
    : result(r)
  { }
  /** // doc operator() {{{
   * \todo Write documentation
   */ // }}}
  template<typename T1, typename T2, typename T3>
  result_type operator()(T1 const& x1, T2 const& x2, T3 const& x3) const
  { return apply(x1, x2, x3, typename can_apply_ternary_op<Op,T1,T2,T3>::type()); }
protected:
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  template<typename T1, typename T2, typename T3>
  result_type
  apply(T1 const& x1, T2 const& x2, T3 const& x3, tml::true_) const
  {
    result = disambiguate<BasicTypes>(apply_ternary_op<Op>::apply(x1, x2, x3));
    return true;
  }
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  result_type
  apply(array<Value> const& x1, array<Value> const& x2, array<Value> const& x3, tml::true_) const
  {
    if(x1.size() != x2.size() || x1.size() != x3.size()) return false;
    array<Value> r(x1.size());
    for(size_t i = 0; i != r.size(); ++i)
      {
        auto op = eval_ternary_op_visitor<Op,BasicTypes,Value>(r[i]);
        if(!boost::apply_visitor(op, x1[i], x2[i], x3[i]))
          return false;
      }
    result = std::forward<array<Value> >(r);
    return true;
  }
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  result_type
  apply(object<Value> const&, object<Value> const&, object<Value> const&, tml::true_) const
  {
    // TODO: elaborate if we're able to apply ternary ops to objects somehow??
    return false;
  }
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  template<typename T1, typename T2, typename T3>
  result_type
  apply(T1 const&, T2 const&, T3 const&, tml::false_) const
  {
    return false;
  }
private:
  Value& result;
};
/** // doc: eval_ternary_op() {{{
 * \todo Write documentation
 */ // }}}
template<op_t Op, typename BasicTypes, typename Value>
eval_ternary_op_visitor<Op, BasicTypes, Value>
eval_ternary_op(Value& result)
{
  return eval_ternary_op_visitor<Op, BasicTypes, Value>(result);
}
} } // end namespace txpl::vm

#endif /* TXPL_VM_EVAL_TERNARY_OP_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
