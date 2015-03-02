// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/ast/operation.hpp

/** // doc: txpl/ast/operation1.hpp {{{
 * \file txpl/ast/operation1.hpp
 * \brief Defines \ref txpl::ast::operation "ast::operation<1>"
 */ // }}}
#ifndef TXPL_AST_OPERATION1_HPP_INCLUDED
#define TXPL_AST_OPERATION1_HPP_INCLUDED

#include <txpl/ast/operation_fwd.hpp>
#include <txpl/ast/node.hpp>
#include <txpl/ast/expr.hpp>
#include <txpl/vm/op_t.hpp>

namespace txpl { namespace ast {
/** \ingroup AstGroup
 * @{ */
/** // doc: operation<1> {{{
 * \brief Specialization of the \ref txpl::ast::operation "ast::operation<>"
 *        for \e Level == 1
 */ // }}}
template<typename Iterator, typename Value>
struct operation<Iterator, Value, 1ul>
  : node<Iterator>
{
  /** // doc: base_type {{{
   * \brief Type of the base class
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
  typedef ast::expr<Iterator, Value> expr_type;
  /** // doc: operator {{{
   * \brief Operator identifier
   */ // }}}
  operator_type operator_;
  /** // doc: expr {{{
   * \brief RHS subexpressions provided as arguments to this operation
   */ // }}}
  expr_type expr;
  /** // doc: level {{{
   * \brief Level number (precedence) of this operation, equals 1 for this
   *        specialization
   */ // }}}
  constexpr static size_t level = 1ul;
};
/** @} */
} } // end namespace ast

#endif /* TXPL_AST_OPERATION1_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
