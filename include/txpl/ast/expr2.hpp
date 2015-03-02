// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/ast/expr2.hpp

/** // doc: txpl/ast/expr2.hpp {{{
 * \file txpl/ast/expr2.hpp
 * \brief Defines \ref txpl::ast::expr "ast::expr<5>"
 */ // }}}
#ifndef TXPL_AST_EXPR2_HPP_INCLUDED
#define TXPL_AST_EXPR2_HPP_INCLUDED

#include <txpl/ast/expr_fwd.hpp>
#include <txpl/ast/node.hpp>
#include <txpl/ast/expr0.hpp>
#include <txpl/ast/operation1.hpp>
#include <list>

namespace txpl { namespace ast {
/** \ingroup AstGroup
 * @{ */
/** // doc: expr<5> {{{
 * \brief Specializes the \ref txpl::ast::expr "ast::expr<>" for \e Level == 5
 */ // }}}
template<typename Iterator, typename Value>
struct expr<Iterator, Value, 2ul>
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
   */ // }}}
  typedef expr<Iterator, Value, 0ul> head_type;
  /** // doc: tail_type {{{
   * \brief Type used to represent the remaining subexpressions in this
   *        expression's syntax
   */ // }}}
  typedef std::list<operation<Iterator, Value, 1ul> > tail_type;
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
   * \brief Expression level, equals 5 for this specialization
   */ // }}}
  constexpr static size_t level = 2ul;
};
/** @} */
} } // end namespace ast

#endif /* TXPL_AST_EXPR2_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
