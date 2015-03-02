// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/context.hpp

/** // doc: txpl/vm/context.hpp {{{
 * \file txpl/vm/context.hpp
 * \brief Defines the \ref txpl::vm::context "vm::context<>"
 */ // }}}
#ifndef TXPL_VM_CONTEXT_HPP_INCLUDED
#define TXPL_VM_CONTEXT_HPP_INCLUDED

#include <txpl/vm/value.hpp>
#include <txpl/vm/scope.hpp>
#include <txpl/vm/symbol.hpp>
#include <txpl/vm/scope_lookup.hpp>
#include <txpl/vm/scope_insert.hpp>

namespace txpl { namespace vm {
/** // doc: context {{{
 * \ingroup VmGroup
 * \brief Evaluation context for the \ref VmGroup "virtual machnie's" evaluator
 *
 * \tparam Value a universal (variant) value type used to represent the result
 *         of expression evaluation
 *
 * The \ref txpl::vm::context "vm::context" is passed around when evaluating an
 * expression. The object encapsulates the following things
 *
 *  - scope tree, which is a recursive map of \ref txpl::vm::symbol "symbols",
 *    see \ref global_scope,
 *  - path to the current scope, see \ref current_scope.
 *
 * For example, all the (predefined) variables that may be used in expressions
 * are stored in \ref txpl::vm::context "vm::context" (they're nested in the
 * global scope or subscopes). An expression may be evaluated several times
 * in different \ref txpl::vm::context "contexts" (for example, with different
 * values of variables).
 */ // }}}
template<typename Value = vm::value<> >
struct context
{
  /** // doc: value_type {{{
   * \brief Same as \e Value template argument
   */ // }}}
  typedef Value value_type;
  /** // doc: symbol_type {{{
   * \brief Type of mapped elements in the \ref global_scope map
   */ // }}}
  typedef symbol<value_type> symbol_type;
  /** // doc: scope_type {{{
   * \brief Type of the map used to implement scopes in the context
   */ // }}}
  typedef scope<symbol_type> scope_type;
  /** // doc: scope_key_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename scope_type::key_type scope_key_type;
  /** // doc: global_scope {{{
   * \brief Recursive map (tree) used to store symbol table
   *
   * This is a recursive map (tree) which stores symbols (variables, subscopes,
   * etc) defined in the \ref txpl::vm::context "context".
   *
   * \sa \ref txpl::vm::scope "vm::scope<>"
   */ // }}}
  scope_type global_scope;
  /** // doc: current_scope {{{
   * \brief Path to the current scope
   *
   * Current scope is a starting point for symbol lookup in the scope tree.
   * This path should have the following syntax
\verbatim
( word ( `::' word )* ) ?
\endverbatim
   * where the \e word shall match the regular expression
   * `[a-zA-Z_][a-zA-Z_0-9]*`.
   *
   * \note At this moment the correct syntax and validity of the
   * \ref current_scope is not enforced. It's up to the user to ensure, that
   * correct path is stored in the \ref current_scope.
   */ // }}}
  std::string current_scope;
};
} } // end namespace txpl

#endif /* TXPL_VM_CONTEXT_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
