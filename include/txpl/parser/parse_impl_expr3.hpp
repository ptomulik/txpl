// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/parser/parse_impl_expr.hpp

/** // doc: txpl/parser/parse_impl_expr3.hpp {{{
 * \file txpl/parser/parse_impl_expr3.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_PARSER_PARSE_IMPL_EXPR3_HPP
#define TXPL_PARSER_PARSE_IMPL_EXPR3_HPP

#include <txpl/parser/parse_impl_fwd.hpp>
#include <txpl/parser/parse_fwd.hpp>
#include <txpl/ast/expr3.hpp>
#include <txpl/ast/expr.hpp>
#include <txpl/ast/unary_expr.hpp>
#include <utility>

namespace txpl { namespace parser {
/** // doc: parse_impl<ast::expr<3> > {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename Value>
struct parse_impl<ast::expr<Iterator, Value, 3ul> >
{
  /** // doc: node_type {{{
   * \todo Write documentation
   */ // }}}
  typedef ast::expr<Iterator, Value, 3ul> node_type;
  /** // doc: unary_expr_type {{{
   * \todo Write documentation
   */ // }}}
  typedef ast::unary_expr<Iterator, Value> unary_expr_type;
  /** // doc: expr2_type {{{
   * \todo Write documentation
   */ // }}}
  typedef ast::expr<Iterator, Value, 2ul> expr2_type;
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  template<typename Ehandler>
  static bool
  apply(Iterator& first, Iterator const& last, node_type& node, Ehandler f)
  {
    if(first == last) return false;

    Iterator it = first;

    {
      unary_expr_type unary;
      if(parse(first, last, unary, f))
        {
          node.expr = std::move(unary);
          return true;
        }
      else if(it != first)
        return false;
    }

    {
      expr2_type expr2;
      if(parse(first, last, expr2, f))
        {
          node.expr = std::move(expr2);
          return true;
        }
      else if(it != first)
        return false;
    }
    return false;
  }
};
} } // end namespace txpl::parser

#include <txpl/parser/parse.hpp>

#endif /* TXPL_PARSER_PARSE_IMPL_EXPR3_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
