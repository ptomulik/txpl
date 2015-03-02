// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/parser/parse_impl_array_expr.hpp

/** // doc: txpl/parser/parse_impl_array_expr.hpp {{{
 * \file txpl/parser/parse_impl_array_expr.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_PARSER_PARSE_IMPL_ARRAY_EXPR_HPP
#define TXPL_PARSER_PARSE_IMPL_ARRAY_EXPR_HPP

#include <txpl/parser/parse_impl_fwd.hpp>
#include <txpl/parser/parse_fwd.hpp>
#include <txpl/ast/nodes.hpp>
#include <txpl/util/fake_functor.hpp>
#include <utility>

namespace txpl { namespace parser {
/** // doc: parse_impl<ast::array_expr> {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename Value>
struct parse_impl<ast::array_expr<Iterator, Value> >
{
  /** // doc: node_type {{{
   * \todo Write documentation
   */ // }}}
  typedef ast::array_expr<Iterator, Value> node_type;
  /** // doc: expr_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename node_type::expr_type expr_type;
  /** // doc: expr_list_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename node_type::expr_list_type expr_list_type;
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  template<typename Ehandler>
  static bool
  apply(Iterator& first, Iterator const& last, node_type& node, Ehandler f)
  {
    if(first == last) return false;
    expr_type expr;
    expr_list_type expr_list;
    Iterator it;
    if(*first != '[') return false;
    if(++first == last)
      {
        f(first, last, "expected expression or ']'");
        return false;
      }
    it = first;
    if(parse(first, last, expr, util::fake_functor<void>()))
      {
        expr_list.push_back(std::move(expr));
        for(;;)
          {
            if(first == last) break;
            if(*first != ',') break;
            ++first;
            it = first;
            if(!parse(first, last, expr, f))
              return false;
            expr_list.push_back(std::move(expr));
          }
      }
    else
      {
        first = it;
      }
    if(first == last)
      {
        f(first, last, "expected ']'");
        return false;
      }
    if(*first != ']')
      {
        f(first, last, "expected ']'");
        return false;
      }
    ++first;
    node.expr_list = std::move(expr_list);
    return true;
  }
};
} } // end namespace txpl::parser

#include <txpl/parser/parse.hpp>

#endif /* TXPL_PARSER_PARSE_IMPL_ARRAY_EXPR_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
