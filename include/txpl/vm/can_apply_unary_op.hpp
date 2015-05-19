// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/can_apply_unary_op.hpp

/** // doc: txpl/vm/can_apply_unary_op.hpp {{{
 * \file txpl/vm/can_apply_unary_op.hpp
 * \brief Implements the \ref txpl::vm::can_apply_unary_op "vm::can_apply_unary_op<>"
 */ // }}}
#ifndef TXPL_VM_CAN_APPLY_UNARY_OP_HPP_INCLUDED
#define TXPL_VM_CAN_APPLY_UNARY_OP_HPP_INCLUDED

#include <txpl/vm/apply_unary_op.hpp>
#include <txpl/vm/op_t.hpp>
#include <yaul/tml/enable_if_type.hpp>
#include <yaul/tml/bool.hpp>

namespace txpl { namespace vm {
/** \ingroup VmGroup
 * @{ */
/** // doc: can_apply_unary_op {{{
 * \brief Check at compile-time if a unary operator can be applied to given
 *        operand
 *
 * \tparam Op operator identifier, see \ref txpl::vm::op_t "vm::op_t",
 * \tparam T  type of the operand being checked.
 *
 * This meta-function is used to check at compile time if an unary operator
 * \e Op can be applied to an operand of types \e T. The meta-function
 * evaluates to `yaul::tml::true_` if the operation is supported by the C++ standard
 * (compiler) and to `yaul::tml::false_` elsewhere.
 *
 * The meta-function is used to dispatch at compile time the operations
 * supported by C++ standard to appropriate operator handlers and all the
 * others to error handlers.
 *
 * \b Example:
 * \snippet can_apply_unary_op1.cpp Code
 * \b Output:
 * \snippet can_apply_unary_op1.cpp Output
 */ // }}}
template<op_t Op, typename T, typename Enable = void>
struct can_apply_unary_op : yaul::tml::false_ { };
/** // doc: can_apply_plus {{{
 * \brief Partial specialization of \ref txpl::vm::can_apply_unary_op
 *        "vm::can_apply_unary_op<>" for supported unary operations.
 */ // }}}
template<op_t Op, typename T>
struct can_apply_unary_op<
  Op, T, typename yaul::tml::enable_if_type<
    decltype(apply_unary_op<Op>::apply(T()))
  >::type
>
  : yaul::tml::true_
{ };
/** @} */
} } // end namespace txpl::vm

#endif /* TXPL_VM_CAN_APPLY_UNARY_OP_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
