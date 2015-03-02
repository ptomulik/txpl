// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/eval.hpp

/** // doc: txpl/vm/eval.hpp {{{
 * \file txpl/vm/eval.hpp
 * \brief Defines the \ref txpl::vm::eval() "vm::eval()" function
 */ // }}}
#ifndef TXPL_VM_EVAL_HPP_INCLUDED
#define TXPL_VM_EVAL_HPP_INCLUDED

#include <txpl/vm/eval_impl_fwd.hpp>
#include <txpl/util/fake_functor.hpp>

namespace txpl { namespace vm {
/** \ingroup VmGroup
 * @{ */
/** // doc: eval() {{{
 * \brief Evaluates parsed expression in a context
 *
 * \param node    root node of the abstract syntax tree representing the parsed
 *                expression to be evaluated,
 * \param context evaluation context, see \ref VmContextConcept,
 * \param result  where to store the result of expression evaluation,
 *                must be a mutable \ref VmValueConcept,
 * \param f       error handler invoked when the expression cannot be
 *                evaluated, see below,
 * \apram range   suggested token range for error reporting,
 * \returns `true` on success or `false` otherwise.
 *
 * \par Description
 *
 * This function evaluates an already parsed expression stored as an abstract
 * syntax tree (AST). The AST tree is provided to function as the \e node
 * argument, which is assumed to be its root node. On success, the result of
 * evaluation gets stored to \e result. If an error occurs, the error handler
 * \e f gets invoked and the function returns `false`. The data under \e result
 * remains unchanged in that case.
 *
 * The error handler should be a callable object accepting three arguments.
 * The following expression should be valid:
 *
 * \code
 *  f(beg, end, msg)
 * \endcode
 *
 * with
 *
 *  - \e beg being an iterator pointing to the first token of the failed
 *    subexpression,
 *  - \e end being an iterator pointing one-past the last token of the failed
 *    subexpression,
 *  - \e msg being a string (`std::string`, contains error message).
 *
 */ // }}}
template<typename Node, typename Context, typename Value, typename Ehandler, typename Range>
bool eval(Node const& node, Context const& context, Value& result, Ehandler f, Range const& range)
{ return eval_impl<Node>::apply(node, context, result, f, range); }
/** // doc: eval() {{{
 * \brief Evaluates parsed expression in a context
 *
 * \param node    root node of the abstract syntax tree representing the parsed
 *                expression to be evaluated,
 * \param context evaluation context, see \ref VmContextConcept,
 * \param result  where to store the result of expression evaluation,
 *                must be a mutable \ref VmValueConcept,
 * \param f       error handler invoked when the expression cannot be
 *                evaluated, see below,
 * \returns `true` on success or `false` otherwise.
 *
 * \par Description
 *
 * This function evaluates an already parsed expression stored as an abstract
 * syntax tree (AST). The AST tree is provided to function as the \e node
 * argument, which is assumed to be its root node. On success, the result of
 * evaluation gets stored to \e result. If an error occurs, the error handler
 * \e f gets invoked and the function returns `false`. The data under \e result
 * remains unchanged in that case.
 *
 * The error handler should be a callable object accepting three arguments.
 * The following expression should be valid:
 *
 * \code
 *  f(beg, end, msg)
 * \endcode
 *
 * with
 *
 *  - \e beg being an iterator pointing to the first token of the failed
 *    subexpression,
 *  - \e end being an iterator pointing one-past the last token of the failed
 *    subexpression,
 *  - \e msg being a string (`std::string`, contains error message).
 *
 */ // }}}
template<typename Node, typename Context, typename Value, typename Ehandler>
bool eval(Node const& node, Context const& context, Value& result, Ehandler f)
{ return eval_impl<Node>::apply(node, context, result, f, node.range); }
/** // doc: eval() {{{
 * \brief Evaluate parsed expression in a context
 *
 * \param node    top node of the abstract syntax tree of the expression,
 * \param context evaluation context,
 * \param result  where to store the result of expression evaluation,
 *                must be a model of \ref VmValue,
 * \returns `true` on success or `false` otherwise.
 *
 * \par Description
 *
 * This is a variant of \ref txpl::vm::eval() "vm::eval()" invokable without an
 * error handler.
 *
 * \sa \ref txpl::vm::eval() "vm::eval()"
 */ // }}}
template<typename Node, typename Context, typename Value>
bool eval(Node const& node, Context const& context, Value& result)
{ return eval(node, context, result, util::fake_functor<void>()); }
/** @} */
} } // end namespace txpl::vm

#include <txpl/vm/eval_impl.hpp>

#endif /* TXPL_VM_EVAL_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
