// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/apply_binary_op.hpp

/** // doc: txpl/vm/apply_binary_op.hpp {{{
 * \file txpl/vm/apply_binary_op.hpp
 * \brief Implements \ref txml::vm::apply_binary_op "vm::apply_binary_op<>"
 */ // }}}
#ifndef TXPL_VM_APPLY_BINARY_OP_HPP_INCLUDED
#define TXPL_VM_APPLY_BINARY_OP_HPP_INCLUDED

#include <txpl/vm/op_t.hpp>
#include <regex>

namespace txpl { namespace vm {
/** \ingroup VmGroup
 * @{ */
/** // doc: apply_binary_op {{{
 * \brief Applies a binary operator to its operands
 *
 * \tparam Op operator identifier, see \ref txpl::vm::op_t "vm::op_t"
 *
 * This struct implements binary operations and is used by 
 * \ref txpl::vm::eval_binary_op_visitor "vm::eval_binary_op_visitor".
 * It shall be specialized for each supported binary operator. The
 * specialization shall implement a static binary method `apply()` which takes
 * operator's operands as its arguments and returns operation result. In most
 * cases, the method will be defined as
 *
 * \code
 * template<typename T1, typename T2>
 * static / unspecified_type / apply(T1 x1, T2 x2)
 * { return / unspecified_value / ; }
 * \endcode
 *
 * \b Example:
 * 
 * Binary plus (`x1 + x2`)
 *
 * \code
 * template<>
 * struct apply_binary_op<opt_t::plus_>
 * {
 *   template<typename T1, typename T2>
 *   static auto apply(T1 x1, T2 x2) -> decltype(x1 + x2)
 *   { return x1 + x2; }
 * };
 * \endcode
 *
 */ // }}}
template<op_t Op>
struct apply_binary_op;
/** // doc: apply_binary_op<or> {{{
 * \brief Specialization of the \ref txpl::vm::apply_binary_op
 *        "vm::apply_binary_op<>" for the `||` (logical or) operator
 */ // }}}
template<>
struct apply_binary_op<op_t::or_>
{
  /** // doc: apply() {{{
   * \brief Applies the binary operator `||`
   * \tparam T1 first operand type
   * \tparam T2 second operand type
   * \param x1 first operand
   * \param x2 second operand
   * \returns result of `x1 || x2`
   */ // }}}
  template<typename T1, typename T2>
  static auto apply(T1 x1, T2 x2) -> decltype(x1 || x2)
  { return x1 || x2; }
};
/** // doc: apply_binary_op<and> {{{
 * \brief Specialization of the \ref txpl::vm::apply_binary_op
 *        "vm::apply_binary_op<>" for the `&&` (logical and) operator
 */ // }}}
template<>
struct apply_binary_op<op_t::and_>
{
  /** // doc: apply() {{{
   * \brief Applies the binary operator `&&`
   * \tparam T1 first operand type
   * \tparam T2 second operand type
   * \param x1 first operand
   * \param x2 second operand
   * \returns result of `x1 && x2`
   */ // }}}
  template<typename T1, typename T2>
  static auto apply(T1 x1, T2 x2) -> decltype(x1 && x2)
  { return x1 && x2; }
};
/** // doc: apply_binary_op<bitor> {{{
 * \brief Specialization of the \ref txpl::vm::apply_binary_op
 *        "vm::apply_binary_op<>" for the `|` (bitwise or) operator
 */ // }}}
template<>
struct apply_binary_op<op_t::bitor_>
{
  /** // doc: apply() {{{
   * \brief Applies the binary operator `|`
   * \tparam T1 first operand type
   * \tparam T2 second operand type
   * \param x1 first operand
   * \param x2 second operand
   * \returns result of `x1 | x2`
   */ // }}}
  template<typename T1, typename T2>
  static auto apply(T1 x1, T2 x2) -> decltype(x1 | x2)
  { return x1 | x2; }
};
/** // doc: apply_binary_op<xor> {{{
 * \brief Specialization of the \ref txpl::vm::apply_binary_op
 *        "vm::apply_binary_op<>" for the `^` (xor) operator
 */ // }}}
template<>
struct apply_binary_op<op_t::xor_>
{
  /** // doc: apply() {{{
   * \brief Applies the binary operator `^`
   * \tparam T1 first operand type
   * \tparam T2 second operand type
   * \param x1 first operand
   * \param x2 second operand
   * \returns result of `x1 ^ x2`
   */ // }}}
  template<typename T1, typename T2>
  static auto apply(T1 x1, T2 x2) -> decltype(x1 ^ x2)
  { return x1 ^ x2; }
};
/** // doc: apply_binary_op<bitand> {{{
 * \brief Specialization of the \ref txpl::vm::apply_binary_op
 *        "vm::apply_binary_op<>" for the `&` (bitwise and) operator
 */ // }}}
template<>
struct apply_binary_op<op_t::bitand_>
{
  /** // doc: apply() {{{
   * \brief Applies the binary operator `&`
   * \tparam T1 first operand type
   * \tparam T2 second operand type
   * \param x1 first operand
   * \param x2 second operand
   * \returns result of `x1 & x2`
   */ // }}}
  template<typename T1, typename T2>
  static auto apply(T1 x1, T2 x2) -> decltype(x1 & x2)
  { return x1 & x2; }
};
/** // doc: apply_binary_op<eq> {{{
 * \brief Specialization of the \ref txpl::vm::apply_binary_op
 *        "vm::apply_binary_op<>" for the `==` (equal to) operator
 */ // }}}
template<>
struct apply_binary_op<op_t::eq_>
{
  /** // doc: apply() {{{
   * \brief Applies the binary operator `==`
   * \tparam T1 first operand type
   * \tparam T2 second operand type
   * \param x1 first operand
   * \param x2 second operand
   * \returns result of `x1 == x2`
   */ // }}}
  template<typename T1, typename T2>
  static auto apply(T1 x1, T2 x2) -> decltype(x1 == x2)
  { return x1 == x2; }
};
/** // doc: apply_binary_op<neq> {{{
 * \brief Specialization of the \ref txpl::vm::apply_binary_op
 *        "vm::apply_binary_op<>" for the `!=` (not equal) operator
 */ // }}}
template<>
struct apply_binary_op<op_t::neq_>
{
  /** // doc: apply() {{{
   * \brief Applies the binary operator `!=`
   * \tparam T1 first operand type
   * \tparam T2 second operand type
   * \param x1 first operand
   * \param x2 second operand
   * \returns result of `x1 != x2`
   */ // }}}
  template<typename T1, typename T2>
  static auto apply(T1 x1, T2 x2) -> decltype(x1 != x2)
  { return x1 != x2; }
};
/** // doc: apply_binary_op<eq> {{{
 * \brief Specialization of the \ref txpl::vm::apply_binary_op
 *        "vm::apply_binary_op<>" for the `=~` (regex match) operator
 */ // }}}
template<>
struct apply_binary_op<op_t::match_>
{
  /** // doc: apply() {{{
   * \brief Applies the binary operator `=~` (regex match)
   * \tparam T1 first operand type
   * \tparam T2 second operand type
   * \param x1 first operand
   * \param x2 second operand
   * \returns result of `std::regex_match(x1, x2)`
   */ // }}}
  template<typename T1, typename T2>
  static auto apply(T1 x1, T2 x2) -> decltype(std::regex_match(x1,x2))
  { return std::regex_match(x1,x2); }
};
/** // doc: apply_binary_op<nmatch> {{{
 * \brief Specialization of the \ref txpl::vm::apply_binary_op
 *        "vm::apply_binary_op<>" for the `!~` (regex not match) operator
 */ // }}}
template<>
struct apply_binary_op<op_t::nmatch_>
{
  /** // doc: apply() {{{
   * \brief Applies the binary operator `!~`
   * \tparam T1 first operand type
   * \tparam T2 second operand type
   * \param x1 first operand
   * \param x2 second operand
   * \returns result of `!std::regex_match(x1,x2)`
   */ // }}}
  template<typename T1, typename T2>
  static auto apply(T1 x1, T2 x2) -> decltype(!std::regex_match(x1,x2))
  { return !std::regex_match(x1,x2); }
};
/** // doc: apply_binary_op<subscript> {{{
 * \brief Specialization of the \ref txpl::vm::apply_binary_op
 *        "vm::apply_binary_op<>" for the `!~` (regex not match) operator
 */ // }}}
template<>
struct apply_binary_op<op_t::subscript_>
{
  /** // doc: apply() {{{
   * \brief Applies the subscript operator `[]`
   * \tparam T1 first operand type
   * \tparam T2 second operand type
   * \param x1 first operand
   * \param x2 second operand
   * \returns result of `!std::regex_match(x1,x2)`
   */ // }}}
  template<typename T1, typename T2>
  static auto apply(T1 x1, T2 x2) -> decltype(x1[x2])
  { return x1[x2]; }
};
/** // doc: apply_binary_op<lt> {{{
 * \brief Specialization of the \ref txpl::vm::apply_binary_op
 *        "vm::apply_binary_op<>" for the `<` (less than) operator
 */ // }}}
template<>
struct apply_binary_op<op_t::lt_>
{
  /** // doc: apply() {{{
   * \brief Applies the binary operator `<`
   * \tparam T1 first operand type
   * \tparam T2 second operand type
   * \param x1 first operand
   * \param x2 second operand
   * \returns result of `x1 < x2`
   */ // }}}
  template<typename T1, typename T2>
  static auto apply(T1 x1, T2 x2) -> decltype(x1 < x2)
  { return x1 < x2; }
};
/** // doc: apply_binary_op<gt> {{{
 * \brief Specialization of the \ref txpl::vm::apply_binary_op
 *        "vm::apply_binary_op<>" for the `>` (greater than) operator
 */ // }}}
template<>
struct apply_binary_op<op_t::gt_>
{
  /** // doc: apply() {{{
   * \brief Applies the binary operator `>`
   * \tparam T1 first operand type
   * \tparam T2 second operand type
   * \param x1 first operand
   * \param x2 second operand
   * \returns result of `x1 > x2`
   */ // }}}
  template<typename T1, typename T2>
  static auto apply(T1 x1, T2 x2) -> decltype(x1 > x2)
  { return x1 > x2; }
};
/** // doc: apply_binary_op<le> {{{
 * \brief Specialization of the \ref txpl::vm::apply_binary_op
 *        "vm::apply_binary_op<>" for the `<=` (less or equal than) operator
 */ // }}}
template<>
struct apply_binary_op<op_t::le_>
{
  /** // doc: apply() {{{
   * \brief Applies the binary operator `<=`
   * \tparam T1 first operand type
   * \tparam T2 second operand type
   * \param x1 first operand
   * \param x2 second operand
   * \returns result of `x1 <= x2`
   */ // }}}
  template<typename T1, typename T2>
  static auto apply(T1 x1, T2 x2) -> decltype(x1 <= x2)
  { return x1 <= x2; }
};
/** // doc: apply_binary_op<ge> {{{
 * \brief Specialization of the \ref txpl::vm::apply_binary_op
 *        "vm::apply_binary_op<>" for the `>=` (greater or equal than) operator
 */ // }}}
template<>
struct apply_binary_op<op_t::ge_>
{
  /** // doc: apply() {{{
   * \brief Applies the binary operator `>=`
   * \tparam T1 first operand type
   * \tparam T2 second operand type
   * \param x1 first operand
   * \param x2 second operand
   * \returns result of `x1 >= x2`
   */ // }}}
  template<typename T1, typename T2>
  static auto apply(T1 x1, T2 x2) -> decltype(x1 >= x2)
  { return x1 >= x2; }
};
/** // doc: apply_binary_op<lshift> {{{
 * \brief Specialization of the \ref txpl::vm::apply_binary_op
 *        "vm::apply_binary_op<>" for the `<<`  (left shift) operator
 */ // }}}
template<>
struct apply_binary_op<op_t::lshift_>
{
  /** // doc: apply() {{{
   * \brief Applies the binary operator `<<`
   * \tparam T1 first operand type
   * \tparam T2 second operand type
   * \param x1 first operand
   * \param x2 second operand
   * \returns result of `x1 << x2`
   */ // }}}
  template<typename T1, typename T2>
  static auto apply(T1 x1, T2 x2) -> decltype(x1 << x2)
  { return x1 << x2; }
};
/** // doc: apply_binary_op<rshift> {{{
 * \brief Specialization of the \ref txpl::vm::apply_binary_op
 *        "vm::apply_binary_op<>" for the `>>` (right shift) operator
 */ // }}}
template<>
struct apply_binary_op<op_t::rshift_>
{
  /** // doc: apply() {{{
   * \brief Applies the binary operator `>>`
   * \tparam T1 first operand type
   * \tparam T2 second operand type
   * \param x1 first operand
   * \param x2 second operand
   * \returns result of `x1 >> x2`
   */ // }}}
  template<typename T1, typename T2>
  static auto apply(T1 x1, T2 x2) -> decltype(x1 >> x2)
  { return x1 >> x2; }
};
/** // doc: apply_binary_op<plus_> {{{
 * \brief Specialization of the \ref txpl::vm::apply_binary_op
 *        "vm::apply_binary_op<>" for the `+` (addition) operator
 */ // }}}
template<>
struct apply_binary_op<op_t::plus_>
{
  /** // doc: apply() {{{
   * \brief Applies the binary operator `+`
   * \tparam T1 first operand type
   * \tparam T2 second operand type
   * \param x1 first operand
   * \param x2 second operand
   * \returns result of `x1 + x2`
   */ // }}}
  template<typename T1, typename T2>
  static auto apply(T1 x1, T2 x2) -> decltype(x1 + x2)
  { return x1 + x2; }
};
/** // doc: apply_binary_op<minus_> {{{
 * \brief Specialization of the \ref txpl::vm::apply_binary_op
 *        "vm::apply_binary_op<>" for the `-` (subtraction) operator
 */ // }}}
template<>
struct apply_binary_op<op_t::minus_>
{
  /** // doc: apply() {{{
   * \brief Applies the binary operator `-`
   * \tparam T1 first operand type
   * \tparam T2 second operand type
   * \param x1 first operand
   * \param x2 second operand
   * \returns result of `x1 - x2`
   */ // }}}
  template<typename T1, typename T2>
  static auto apply(T1 x1, T2 x2) -> decltype(x1 - x2)
  { return x1 - x2; }
};
/** // doc: apply_binary_op<mul_> {{{
 * \brief Specialization of the \ref txpl::vm::apply_binary_op
 *        "vm::apply_binary_op<>" for the `*` (multiplication) operator
 */ // }}}
template<>
struct apply_binary_op<op_t::mul_>
{
  /** // doc: apply() {{{
   * \brief Applies the binary operator `*`
   * \tparam T1 first operand type
   * \tparam T2 second operand type
   * \param x1 first operand
   * \param x2 second operand
   * \returns result of `x1 * x2`
   */ // }}}
  template<typename T1, typename T2>
  static auto apply(T1 x1, T2 x2) -> decltype(x1 * x2)
  { return x1 * x2; }
};
/** // doc: apply_binary_op<div_> {{{
 * \brief Specialization of the \ref txpl::vm::apply_binary_op
 *        "vm::apply_binary_op<>" for the `/`  (division) operator
 */ // }}}
template<>
struct apply_binary_op<op_t::div_>
{
  /** // doc: apply() {{{
   * \brief Applies the binary operator `/`
   * \tparam T1 first operand type
   * \tparam T2 second operand type
   * \param x1 first operand
   * \param x2 second operand
   * \returns result of `x1 / x2`
   */ // }}}
  template<typename T1, typename T2>
  static auto apply(T1 x1, T2 x2) -> decltype(x1 / x2)
  { return x1 / x2; }
};
/** // doc: apply_binary_op<mod_> {{{
 * \brief Specialization of the \ref txpl::vm::apply_binary_op
 *        "vm::apply_binary_op<>" for the `%` (modulo) operator
 */ // }}}
template<>
struct apply_binary_op<op_t::mod_>
{
  /** // doc: apply() {{{
   * \brief Applies the binary operator `%`
   * \tparam T1 first operand type
   * \tparam T2 second operand type
   * \param x1 first operand
   * \param x2 second operand
   * \returns result of x1 % x2
   */ // }}}
  template<typename T1, typename T2>
  static auto apply(T1 x1, T2 x2) -> decltype(x1 % x2)
  { return x1 % x2; }
};
/** @} */
} } // end namespace txpl::vm

#endif /* TXPL_VM_APPLY_BINARY_OP_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
