// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/ast/unary_expr.hpp

/** // doc: txpl/ast/unary_expr.hpp {{{
 * \file txpl/ast/unary_expr.hpp
 * \brief Defines \ref txpl::ast::unary_expr "ast::unary_expr<>"
 */ // }}}
#ifndef TXPL_AST_UNARY_EXPR_HPP_INCLUDED
#define TXPL_AST_UNARY_EXPR_HPP_INCLUDED

#include <txpl/ast/unary_expr_fwd.hpp>
#include <txpl/ast/expr.hpp>
#include <txpl/ast/node.hpp>
#include <txpl/vm/op_t.hpp>

namespace txpl { namespace ast {
/** \ingroup AstGroup
 * @{ */
template<typename Iterator, typename Value>
struct unary_expr
  : node<Iterator>
{
  /** // doc: base_type {{{
   * \brief Type of the base class used
   *
   * Same as \ref txpl::ast::node "ast::node<Iterator>"
   */ // }}}
  typedef node<Iterator> base_type;
  /** // doc: operator_type {{{
   * \brief Type used to represent the underlying operator
   *
   * Same as \ref txpl::vm::op_t "vm::op_t"
   */ // }}}
  typedef vm::op_t operator_type;
  /** // doc: expr_type {{{
   * \brief Type used to represent the AST node of the RHS subexpression
   */ // }}}
  typedef ast::expr<Iterator, Value, 2ul> expr_type;
  /** // doc: operator {{{
   * \brief Operator identifier
   */ // }}}
  operator_type operator_;
  /** // doc: expr {{{
   * \brief RHS subexpression provided as operand to the unary operator
   */ // }}}
  expr_type expr;
};
/** @} */
} } // end namespace ast

#endif /* TXPL_AST_UNARY_EXPR_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
