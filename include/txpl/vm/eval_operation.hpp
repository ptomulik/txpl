// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/eval_operation.hpp

/** // doc: txpl/vm/eval_operation.hpp {{{
 * \file txpl/vm/eval_operation.hpp
 * \brief Defines the \ref txpl::vm::eval_operation() "vm::eval_operation()"
 */ // }}}
#ifndef TXPL_VM_EVAL_OPERATION_HPP_INCLUDED
#define TXPL_VM_EVAL_OPERATION_HPP_INCLUDED

#include <txpl/vm/eval_operation_impl.hpp>

namespace txpl { namespace vm {
/** // doc: eval_operation<N>() {{{
 * \ingroup VmGroup
 * \brief Evaluates binary operation
 *
 * \param op  operator identifier, see \ref txpl::vm::op_t "vm::op_t",
 * \param lhs left hand side operand to the operator \e op, at exit the
 *            operation result is stored here,
 * \param rhs right hand side operand to the operator \e op,
 * \param f   error handler.
 * \returns `true` on success of `false` otherwise.
 *
 * \par Description
 *
 * For a given binary operator \e op and operands \e lhs and \e rhs, the method
 * tries to evaluate \e lhs = \e lhs \e op \e rhs. On success, the result of
 * the operation is written to \e lhs and the function returns `true`. On error
 * the error handler \e f gets invoked and the function returns `false`. The
 * value under \e lhs remains unchanged in this case. The error handler \e f
 * must be a unary callable object, such that the following expression is valid
 *
 * \code
 *  f(msg)
 * \endcode
 *
 * with \e msg being a string (std::string or a null-terminated C string).
 * The argument \e msg provided to \f contains an error message. The error
 * handler \e f must be compatible with both, std::string and C string (``const
 * char*``).
 */ // }}}
template<size_t Level, typename Lhs, typename Rhs, typename Ehandler>
bool eval_operation(op_t op, Lhs& lhs, Rhs const& rhs, Ehandler f)
{ return eval_operation_impl<Level>::apply(op, lhs, rhs, f); }
} } // end namespace txpl::vm

#endif /* TXPL_VM_EVAL_OPERATION_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
