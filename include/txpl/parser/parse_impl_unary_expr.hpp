// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/parser/parse_impl_unary_expr.hpp

/** // doc: txpl/parser/parse_impl_unary_expr.hpp {{{
 * \file txpl/parser/parse_impl_unary_expr.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_PARSER_PARSE_IMPL_UNARY_EXPR_HPP
#define TXPL_PARSER_PARSE_IMPL_UNARY_EXPR_HPP

#include <txpl/parser/parse_impl_fwd.hpp>
#include <txpl/parser/parse_fwd.hpp>
#include <txpl/ast/nodes.hpp>

namespace txpl { namespace parser {
/** // doc: parse_impl<ast::unary_expr> {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename Value>
struct parse_impl<ast::unary_expr<Iterator, Value> >
{
  /** // doc: node_type {{{
   * \todo Write documentation
   */ // }}}
  typedef ast::unary_expr<Iterator, Value> node_type;
  /** // doc: operator_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename ast::unary_expr<Iterator, Value>::operator_type operator_type;
  /** // doc: expr_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename ast::unary_expr<Iterator, Value>::expr_type expr_type;
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  template<typename Ehandler>
  static bool
  apply(Iterator& first, Iterator const& last, node_type& node, Ehandler f)
  {
    if(first == last) return false;

    // FIXME: we shouldn't assume that the object pointed to by Iterator
    // has the id() member method. Instead, we should delegate somewhere
    // the following assignment. This should be elaborated in the future.
    operator_type op = static_cast<operator_type>(first->id());
    if(!(op == '+' || op == '-' || op == '!' || op == '~')) return false;
    Iterator it = ++first;
    if(!parse(first, last, node.expr, f))
      {
        if(it == first)
          f(first, last, "expected sub-expression");
        return false;
      }
    node.operator_ = op;
    return true;
  }
};
} } // end namespace txpl::parser

#include <txpl/parser/parse.hpp>

#endif /* TXPL_PARSER_PARSE_IMPL_UNARY_EXPR_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
