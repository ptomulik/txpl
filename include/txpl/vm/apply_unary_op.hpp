// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/apply_unary_op.hpp

/** // doc: txpl/vm/apply_unary_op.hpp {{{
 * \file txpl/vm/apply_unary_op.hpp
 * \brief Implements the \ref txpl::vm::apply_unary_op "vm::apply_unary_op<>"
 */ // }}}
#ifndef TXPL_VM_APPLY_UNARY_OP_HPP_INCLUDED
#define TXPL_VM_APPLY_UNARY_OP_HPP_INCLUDED

#include <txpl/vm/op_t.hpp>

namespace txpl { namespace vm {
/** \ingroup VmGroup
 * @{ */
/** // doc: can_apply_unary_op {{{
 * \brief Applies a unary operator to its operands
 *
 * \tparam Op operator identifier, see \ref txpl::vm::op_t "vm::op_t"
 *
 * This struct implements unary operations and is used by 
 * \ref txpl::vm::eval_unary_op_visitor "vm::eval_unary_op_visitor".
 * It shall be specialized for each supported unary operator. The
 * specialization shall implement a static unary method `apply()` which takes
 * operator's operand as its argument and returns operation result. In most
 * cases the method will be defined as
 *
 * \code
 * template<typename T>
 * static / unspecified_type / apply(T x)
 * { return / unspecified_value / ; }
 * \endcode
 *
 * \b Example:
 * 
 * Boolean negation (`!x`)
 *
 * \code
 *  template<>
 *  struct apply_unary_op<opt_t::not_>
 *  {
 *    template<typename T>
 *    static auto apply(T x) -> decltype(!x)
 *    { return !x; }
 *  };
 * \endcode
 *
 */ // }}}
template<op_t Op>
struct apply_unary_op;
/** // doc: apply_unary_op<plus_> {{{
 * \brief Specialization of the \ref txpl::vm::apply_unary_op
 *        "vm::apply_unary_op<>" for the `+` (unary plus) operator
 */ // }}}
template<>
struct apply_unary_op<op_t::plus_>
{
  /** // doc: apply() {{{
   * \brief Applies the unary opeator `+`
   * \tparam T type of the operand
   * \param x operand
   * \returns the result of `+x`
   */ // }}}
  template<typename T>
  static auto apply(T x) -> decltype(+x)
  { return +x; }
};
/** // doc: apply_unary_op<minus_> {{{
 * \brief Specialization of the \ref txpl::vm::apply_unary_op
 *        "vm::apply_unary_op<>" for the `-` (unary minus) operator
 */ // }}}
template<>
struct apply_unary_op<op_t::minus_>
{
  /** // doc: apply() {{{
   * \brief Applies the unary opeator `~`
   * \tparam T type of the operand
   * \param x operand
   * \returns the result of `~x`
   */ // }}}
  template<typename T>
  static auto apply(T x) -> decltype(-x)
  { return -x; }
};
/** // doc: apply_unary_op<not_> {{{
 * \brief Specialization of the \ref txpl::vm::apply_unary_op
 *        "vm::apply_unary_op<>" for the `!` (logical negation) operator
 */ // }}}
template<>
struct apply_unary_op<op_t::not_>
{
  /** // doc: apply() {{{
   * \brief Applies the unary opeator `!`
   * \tparam T type of the operand
   * \param x operand
   * \returns the result of `!x`
   */ // }}}
  template<typename T>
  static auto apply(T x) -> decltype(!x)
  { return !x; }
};
/** // doc: apply_unary_op<neg_> {{{
 * \brief Specialization of the \ref txpl::vm::apply_unary_op
 *        "vm::apply_unary_op<>" for the `~` (bitwise negation) operator
 */ // }}}
template<>
struct apply_unary_op<op_t::neg_>
{
  /** // doc: apply() {{{
   * \brief Applies the unary opeator `~`
   * \tparam T type of the operand
   * \param x operand
   * \returns the result of `~x`
   */ // }}}
  template<typename T>
  static auto apply(T x) -> decltype(~T()) // "~x" does no work under g++4.9.2
  { return ~x; }
};
/** @} */
} } // end namespace txpl::vm

#endif /* TXPL_VM_APPLY_UNARY_OP_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
