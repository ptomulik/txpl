// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/ast/operation_fwd.hpp

/** // doc: txpl/ast/operation_fwd.hpp {{{
 * \file txpl/ast/operation_fwd.hpp
 * \brief Forward declaration of \ref txpl::ast::operation "ast::operation<>"
 */ // }}}
#ifndef TXPL_AST_OPERATION_FWD_HPP_INCLUDED
#define TXPL_AST_OPERATION_FWD_HPP_INCLUDED

#include <txpl/ast/value.hpp>

namespace txpl { namespace ast {
/** // doc: operation {{{
 * \brief AST node used to represent single tail-operation in an
 *        \ref ExpressionSyntaxParserRules "exprN" syntax
 *
 * \tparam Iterator token iterator type used,
 * \tparam Value value type used by \ref txpl::ast::literal "ast::literal<>"
 * \tparam Level level number (precedence) of this operation
 *
 * Let's take the \ref ExpressionSyntaxParserRules "expr14" rule as an example
 *
 * \e expr14 := \e expr13 ( <tt>'||'</tt> \e expr13 )*
 *
 * This production involves a subexpression ( <tt>'||'</tt> \e expr13 ), which
 * shall be represented by
 * \ref txpl::ast::operation "ast::operation<Iterator, Value, 13>" in the AST
 * type hierarchy.
 */ // }}}
template <typename Iterator, typename Value = value<>, size_t Level = 14>
  struct operation;
} } // end namespace ast

#endif /* TXPL_AST_OPERATION_FWD_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
