// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/ast/braced_expr.hpp

/** // doc: txpl/ast/braced_expr.hpp {{{
 * \file txpl/ast/braced_expr.hpp
 * \brief Defines \ref txpl::ast::braced_expr "ast::braced_expr<>"
 */ // }}}
#ifndef TXPL_AST_BRACED_EXPR_HPP_INCLUDED
#define TXPL_AST_BRACED_EXPR_HPP_INCLUDED

#include <txpl/ast/braced_expr_fwd.hpp>
#include <txpl/ast/node.hpp>
#include <txpl/ast/expr.hpp>

namespace txpl { namespace ast {
/** \ingroup AstGroup
 * @{ */
template<typename Iterator, typename Value>
struct braced_expr
  : node<Iterator>
{
  /** // doc: base_type {{{
   * \brief Type of the base class used
   *
   * Same as \ref txpl::ast::node "ast::node<Iterator>"
   */ // }}}
  typedef node<Iterator> base_type;
  /** // doc: expr_type {{{
   * \brief Type of the AST node representing the subexpression being braced
   *
   * Same as \ref txpl::ast::expr "ast::expr<Iterator,Value>"
   */ // }}}
  typedef ast::expr<Iterator, Value> expr_type;
  /** // doc: expr {{{
   * \brief AST node representing the subexpression being braced
   */ // }}}
  expr_type expr;
};
/** @} */
} } // end namespace ast

#endif /* TXPL_AST_BRACED_EXPR_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
