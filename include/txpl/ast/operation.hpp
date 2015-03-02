// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/ast/operation.hpp

/** // doc: txpl/ast/operation.hpp {{{
 * \file txpl/ast/operation.hpp
 * \brief Defines \ref txpl::ast::operation "ast::operation<>"
 */ // }}}
#ifndef TXPL_AST_OPERATION_HPP_INCLUDED
#define TXPL_AST_OPERATION_HPP_INCLUDED

#include <txpl/ast/operation_fwd.hpp>
#include <txpl/ast/node.hpp>
#include <txpl/ast/expr.hpp>
#include <txpl/vm/op_t.hpp>

namespace txpl { namespace ast {
/** \ingroup AstGroup
 * @{ */
template<typename Iterator, typename Value, size_t Level>
struct operation
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
  typedef ast::expr<Iterator, Value, Level> expr_type;
  /** // doc: operator {{{
   * \brief Operator identifier
   */ // }}}
  operator_type operator_;
  /** // doc: operand {{{
   * \brief RHS subexpression provided as argument to this operation
   */ // }}}
  expr_type expr;
  /** // doc: level {{{
   * \brief Level number (precedence) of this operation
   */ // }}}
  constexpr static size_t level = Level;
};
/** @} */
} } // end namespace ast

#include <txpl/ast/operation14.hpp>
#include <txpl/ast/operation1.hpp>
//#include <txpl/ast/operation0.hpp>

#endif /* TXPL_AST_OPERATION_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
