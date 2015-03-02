// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/parser/parse_impl_expr.hpp

/** // doc: txpl/parser/parse_impl_expr.hpp {{{
 * \file txpl/parser/parse_impl_expr.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_PARSER_PARSE_IMPL_EXPR_HPP
#define TXPL_PARSER_PARSE_IMPL_EXPR_HPP

#include <txpl/parser/parse_impl_fwd.hpp>
#include <txpl/parser/parse_fwd.hpp>
#include <txpl/ast/expr.hpp>
#include <utility>

namespace txpl { namespace parser {
/** // doc: parse_impl<ast::expr<Value, Level>> {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename Value, size_t Level>
struct parse_impl<ast::expr<Iterator, Value, Level> >
{
  /** // doc: node_type {{{
   * \todo Write documentation
   */ // }}}
  typedef ast::expr<Iterator, Value, Level> node_type;
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  template<typename Ehandler>
  static bool
  apply(Iterator& first, Iterator const& last, node_type& node, Ehandler f)
  {
    typename node_type::tail_type::value_type operation;
    typename node_type::tail_type tail;

    Iterator it = first;
    if(!parse(first, last, node.head, f)) return false;
    for(it = first; parse(first, last, operation, f); it = first)
      tail.push_back(operation);
    if(it != first)
      return false; // indicates error detected by children ...
    node.tail = tail;
    return true;
  }
};
} } // end namespace txpl::parser

#include <txpl/parser/parse_impl_expr_top.hpp>
#include <txpl/parser/parse_impl_expr0.hpp>
#include <txpl/parser/parse_impl_expr3.hpp>
#include <txpl/parser/parse.hpp>

#endif /* TXPL_PARSER_PARSE_IMPL_EXPR_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
