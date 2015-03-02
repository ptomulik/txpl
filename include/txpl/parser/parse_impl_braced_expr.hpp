// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/parser/parse_impl_braced_expr.hpp

/** // doc: txpl/parser/parse_impl_braced_expr.hpp {{{
 * \file txpl/parser/parse_impl_braced_expr.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_PARSER_PARSE_IMPL_BRACED_EXPR_HPP
#define TXPL_PARSER_PARSE_IMPL_BRACED_EXPR_HPP

#include <txpl/parser/parse_impl_fwd.hpp>
#include <txpl/parser/parse_fwd.hpp>
#include <txpl/ast/nodes.hpp>

namespace txpl { namespace parser {
/** // doc: parse_impl<ast::braced_expr> {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename Value>
struct parse_impl<ast::braced_expr<Iterator, Value> >
{
  /** // doc: node_type {{{
   * \todo Write documentation
   */ // }}}
  typedef ast::braced_expr<Iterator, Value> node_type;
  /** // doc: node_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename node_type::expr_type expr_type;
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  template<typename Ehandler>
  static bool
  apply(Iterator& first, Iterator const& last, node_type& node, Ehandler f)
  {
    if(first == last) return false;
    expr_type expr;
    Iterator it;
    if(*first != '(') return false;
    if(++first == last)
      {
        f(first, last, "expected sub-expression");
        return false;
      }
    it = first;
    if(!parse(first, last, expr, f))
      {
        if(it == first)
          f(first, last, "expected sub-expression");
        return false;
      }
    if(first == last)
      {
        f(first, last, "expected ')'");
        return false;
      }
    if(*first != ')')
      {
        f(first, last, "expected ')'");
        return false;
      }
    ++first;
    node.expr = expr;
    return true;
  }
};
} } // end namespace txpl::parser

#include <txpl/parser/parse.hpp>

#endif /* TXPL_PARSER_PARSE_IMPL_BRACED_EXPR_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
