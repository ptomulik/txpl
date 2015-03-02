// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/ast/unary_expr_fwd.hpp

/** // doc: txpl/ast/unary_expr_fwd.hpp {{{
 * \file txpl/ast/unary_expr_fwd.hpp
 * \brief Forward declaration of \ref txpl::ast::unary_expr "ast::unary_expr<>"
 */ // }}}
#ifndef TXPL_AST_UNARY_EXPR_FWD_HPP_INCLUDED
#define TXPL_AST_UNARY_EXPR_FWD_HPP_INCLUDED

#include <txpl/ast/value.hpp>

namespace txpl { namespace ast {
/** // doc: unary_expr {{{
 * \ingroup AstGroup
 * \brief AST node representing unary expression
 *
 * \tparam Iterator token iterator type
 * \tparam Value value type for use in \ref txpl::ast::literal "ast::literal<>"
 *
 * This node type is used to represent the result of parsing a
 * \ref ExpressionSyntaxParserRules "unary_expr" subexpression.
 */ // }}}
template<typename Iterator, typename Value = value<> > struct unary_expr;
} } // end namespace ast

#endif /* TXPL_AST_UNARY_EXPR_FWD_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
