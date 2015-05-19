// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/can_apply_ternary_op.hpp

/** // doc: txpl/vm/can_apply_ternary_op.hpp {{{
 * \file txpl/vm/can_apply_ternary_op.hpp
 * \brief Implements the \ref txpl::vm::can_apply_ternary_op "vm::can_apply_ternary_op<>"
 */ // }}}
#ifndef TXPL_VM_CAN_APPLY_TERNARY_OP_HPP_INCLUDED
#define TXPL_VM_CAN_APPLY_TERNARY_OP_HPP_INCLUDED

#include <txpl/vm/apply_ternary_op.hpp>
#include <txpl/vm/op_t.hpp>
#include <yaul/tml/enable_if_type.hpp>
#include <yaul/tml/bool.hpp>

namespace txpl { namespace vm {
/** \ingroup VmGroup
 * @{ */
/** // doc: can_apply_ternary_op {{{
 * \brief Check at compile-time if a ternary operator can be applied to given
 *        operands
 *
 * \tparam Op operator identifier, see \ref txpl::vm::op_t "vm::op_t"
 * \tparam T1 type of the first operand
 * \tparam T2 type of the second operand
 * \tparam T3 type of the third operand
 *
 * This meta-function is used to check at compile time if a ternary operator
 * \e Op can be applied to operands of (possibly different) types \e T1, \e T2,
 * \e T3. The meta-function evaluates to `yaul::tml::true_` if the operation is
 * supported by the C++ standard (compiler) and to `yaul::tml::false_` elsewhere.
 *
 * The meta-function is used to dispatch at compile time the operations
 * supported by C++ standard to appropriate operator handlers and all the
 * others to error handlers.
 *
 * \b Example:
 * \snippet can_apply_ternary_op1.cpp Code
 * \b Output:
 * \snippet can_apply_ternary_op1.cpp Output
 */ // }}}
template<op_t Op, typename T1, typename T2, typename T3, typename Enable = void>
struct can_apply_ternary_op : yaul::tml::false_ { };
/** // doc: can_apply_or {{{
 * \brief Partial specialization of \ref txpl::vm::can_apply_ternary_op
 *        "vm::can_apply_ternary_op<>" for supported ternary operations.
 */ // }}}
template<op_t Op, typename T1, typename T2, typename T3>
struct can_apply_ternary_op<
    Op, T1, T2, T3
  , typename yaul::tml::enable_if_type<
      decltype(apply_ternary_op<Op>::apply(T1(),T2(), T3()))
    >::type
>
  : yaul::tml::true_ { };
/** @} */
} } // end namespace txpl::vm

#endif /* TXPL_VM_CAN_APPLY_TERNARY_OP_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
