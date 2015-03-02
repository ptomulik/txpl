// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/ast/node.hpp

/** // doc: txpl/ast/node.hpp {{{
 * \file txpl/ast/node.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_AST_NODE_HPP
#define TXPL_AST_NODE_HPP

namespace txpl { namespace ast {
/** // doc: node {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator>
struct node
{
  /** // doc: token_iterator_type {{{
   * \todo Write documentation
   */ // }}}
  typedef Iterator token_iterator_type;
  /** // doc: node() {{{
   * \todo Write documentation
   */ // }}}
  node()
  { }
  /** // doc: node() {{{
   * \todo Write documentation
   */ // }}}
  node(Iterator const& begin, Iterator const& end)
    : _begin(begin), _end(end)
  { }
  /** // doc: set_range() {{{
   * \todo Write documentation
   */ // }}}
  void set_range(Iterator const& begin, Iterator const& end)
  {
    _begin = begin;
    _end = end;
  }
  /** // doc: begin() {{{
   * \todo Write documentation
   */ // }}}
  Iterator const& begin() const noexcept
  { return this->_begin; }
  /** // doc: end() {{{
   * \todo Write documentation
   */ // }}}
  Iterator const& end() const noexcept
  { return this->_end; }
private:
  Iterator _begin;
  Iterator _end;
};
} } // end txpl::ast

#endif /* TXPL_AST_NODE_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
