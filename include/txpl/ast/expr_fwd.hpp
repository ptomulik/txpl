// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/ast/expr_fwd.hpp

/** // doc: txpl/ast/expr_fwd.hpp {{{
 * \file txpl/ast/expr_fwd.hpp
 * \brief Forward declaration of \ref txpl::ast::expr "ast::expr<>"
 */ // }}}
#ifndef TXPL_AST_EXPR_FWD_HPP_INCLUDED
#define TXPL_AST_EXPR_FWD_HPP_INCLUDED

#include <txpl/ast/value.hpp>

namespace txpl { namespace ast {
/** // doc: expr {{{
 * \ingroup AstGroup
 * \brief AST node representing \e exprN expression
 *
 * \tparam Iterator token iterator type
 * \tparam Value value type used by \ref txpl::ast::literal "ast::literal<>"
 * \tparam Level expression level (operation precedence)
 *
 * This template is used to represent expressions 
 * \ref ExpressionSyntaxParserRules "expr15" through
 * \ref ExpressionSyntaxParserRules "expr0".
 */ // }}}
template <typename Iterator, typename Value = value<>, size_t Level = 15>
  struct expr;
} } // end namespace ast

#endif /* TXPL_AST_EXPR_FWD_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
