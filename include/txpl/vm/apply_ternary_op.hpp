// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/apply_ternary_op.hpp

/** // doc: txpl/vm/apply_ternary_op.hpp {{{
 * \file txpl/vm/apply_ternary_op.hpp
 * \brief Defines the \ref txpl::vm::apply_ternary_op "vm::apply_ternary_op<>"
 */ // }}}
#ifndef TXPL_VM_APPLY_TERNARY_OP_HPP_INCLUDED
#define TXPL_VM_APPLY_TERNARY_OP_HPP_INCLUDED

#include <txpl/vm/op_t.hpp>
#include <type_traits>

namespace txpl { namespace vm {
/** \ingroup VmGroup
 * @{ */
/** // doc: apply_ternary_op {{{
 * \brief Applies a ternary operator to its operands
 *
 * \tparam Op operator identifier, see \ref txpl::vm::op_t "vm::op_t"
 *
 * This struct implements ternary operations and is used by 
 * \ref txpl::vm::eval_ternary_op_visitor "vm::eval_ternary_op_visitor".
 * It shall be specialized for each supported ternary operator. The
 * specialization shall implement a static ternary method `apply()` which takes
 * operator's operands as its arguments and returns operation result. In most
 * cases, the method will be defined as
 *
 * \code
 * template<typename T1, typename T2, typename T3>
 * static / unspecified_type / apply(T1 x1, T2 x2, T3 x3)
 * { return / unspecified_value / ; }
 * \endcode
 *
 * \b Example:
 * 
 * Ternary conditional expression (`x1 ? x2 : x3`)
 *
 * \code
 *  template<>
 *  struct apply_ternary_op<opt_t::qmark_>
 *  {
 *    template<typename T1, typename T2, typename T3>
 *    static auto apply(T1 x1, T2 x2, T3 x3)
 *      -> typename std::remove_reference<decltype(x1 ? x2 : x3)>::type
 *    { return x1 ?  x2 : x3; }
 *  };
 * \endcode
 *
 */ // }}}
template<op_t Op>
struct apply_ternary_op;
/** // doc: apply_ternary_op<qmark> {{{
 * \brief Specialization of the \ref txpl::vm::apply_ternary_op
 *        "vm::apply_ternary_op<>" for the `?:` (conditional) operator
 */ // }}}
template<>
struct apply_ternary_op<op_t::qmark_>
{
  // We use std::remove_reference<> becaue - according to C++ standard - the
  // ternary conditional expression may be used as an lvalue reference and in
  // some compilers decltype( x1 ? x2 : x3) yields an lvalue reference. This
  // was seen at least in clang 3.5.0.
  /** // doc: apply() {{{
   * \brief Applies the ternary operator `?:`
   * \tparam T1 type of the first operand
   * \tparam T2 type of the second operand
   * \tparam T3 type of the third operand
   * \param x1 first operand
   * \param x2 second operand
   * \param x3 third operand
   * \returns the result of `x1 ? x2 : x3`
   */ // }}}
  template<typename T1, typename T2, typename T3>
  static auto apply(T1 x1, T2 x2, T3 x3)
    -> typename std::remove_reference<decltype(x1 ? x2 : x3)>::type
  { return x1 ?  x2 : x3; }
};
/** @} */
} } // end namespace txpl::vm

#endif /* TXPL_VM_APPLY_TERNARY_OP_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
