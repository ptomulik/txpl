// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/ast/node.hpp

/** // doc: txpl/ast/node.hpp {{{
 * \file txpl/ast/node.hpp
 * \brief Implements \ref txpl::ast::node "ast::node<>"
 */ // }}}
#ifndef TXPL_AST_NODE_HPP
#define TXPL_AST_NODE_HPP

#include <txpl/ast/node_fwd.hpp>
#include <boost/range/iterator_range_core.hpp>

namespace txpl { namespace ast {
/** // doc: node {{{
 * \brief Base class for all the AST nodes
 *
 * \tparam Iterator type of token iterator; \e Iterators are stored in node
 *         to mark the positions of subexpressions represented by given nodes.
 */ // }}}
template<typename Iterator>
struct node
{
  /** // doc: range_type {{{
   * \todo Write documentation
   */ // }}}
  typedef boost::iterator_range<Iterator> range_type;
  /** // doc: range {{{
   * \todo Write documentation
   */ // }}}
  boost::iterator_range<Iterator> range;
  /** // doc: token_iterator_type {{{
   * \brief Type of the token iterator used
   *
   * Same as \e Iterator template parameter used
   */ // }}}
  typedef Iterator token_iterator_type;
  /** // doc: set_range() {{{
   * \brief Set the begin and end iterators
   */ // }}}
  void set_range(Iterator const& begin, Iterator const& end)
  { range = range_type(begin, end); }
  /** // doc: begin() {{{
   * \brief Retrieve the begin iterator
   */ // }}}
  Iterator begin() const noexcept
  { return range.begin(); }
  /** // doc: end() {{{
   * \brief Retrieve the end iterator
   */ // }}}
  Iterator end() const noexcept
  { return range.end(); }
};
} } // end txpl::ast

#endif /* TXPL_AST_NODE_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
