// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/ast/expr.hpp

/** // doc: txpl/ast/expr.hpp {{{
 * \file txpl/ast/expr.hpp
 * \brief Defines \ref txpl::ast::expr "ast::expr<>"
 */ // }}}
#ifndef TXPL_AST_EXPR_HPP_INCLUDED
#define TXPL_AST_EXPR_HPP_INCLUDED

#include <txpl/ast/expr_fwd.hpp>
#include <txpl/ast/node.hpp>
#include <txpl/ast/operation.hpp>
#include <list>

namespace txpl { namespace ast {
/** \ingroup AstGroup
 * @{ */
template<typename Iterator, typename Value, size_t Level>
struct expr
  : node<Iterator>
{
  /** // doc: base_type {{{
   * \brief Typedef for the base class
   *
   * Same as \ref txpl::ast::node "ast::node<Iterator>"
   */ // }}}
  typedef node<Iterator> base_type;
  /** // doc: head_type {{{
   * \brief Node type of the left-most subexpression in this expression's syntax
   *
   * Let's take an \ref ExpressionSyntaxParserRules "expr14" production as an
   * example
   *
   * \e expr14 := \e expr13 ( <tt>'||'</tt> \e expr13 )*
   *
   * This production has \e expr13 as the leftmost subexpression, so it holds
\verbatim
      std::is_same<ast::expr<Iterator, Value, 14>::head_type ast::expr<Iterator, Value, 13> >
\endverbatim
   */ // }}}
  typedef expr<Iterator, Value, Level-1> head_type;
  /** // doc: tail_type {{{
   * \brief Type used to represent remaining subexpressions in this
   *        expression's syntax
   * 
   * Let's take an \ref ExpressionSyntaxParserRules "expr14" production as an
   * example
   *
   * \e expr14 := \e expr13 ( <tt>'||'</tt> \e expr13 )*
   *
   * The tail_type is used to represent a (possibly empty) list of \ref
   * txpl::ast::operation "operations" denoted in the syntax as
   * ( <tt>'||'</tt> * \e expr13 )*.
   */ // }}}
  typedef std::list<operation<Iterator, Value, Level-1> > tail_type;
  /** // doc: head {{{
   * \brief AST node representing the left-most subexpression in this
   *        expression's syntax
   */ // }}}
  head_type head;
  /** // doc: tail {{{
   * \brief A list representing remaining subexpression in this expression's syntax
   */ // }}}
  tail_type tail;
  /** // doc: level {{{
   * \brief Expression level, same as the \e Level template argument
   */ // }}}
  constexpr static size_t level = Level;
};
/** @} */
} } // end namespace ast

#include <txpl/ast/expr5.hpp>
#include <txpl/ast/expr3.hpp>
#include <txpl/ast/expr2.hpp>
#include <txpl/ast/expr0.hpp>

#endif /* TXPL_AST_EXPR_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
