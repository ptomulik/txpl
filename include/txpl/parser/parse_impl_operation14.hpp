// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/parser/parse_impl_operation.hpp

/** // doc: txpl/parser/parse_impl_operation14.hpp {{{
 * \file txpl/parser/parse_impl_operation14.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_PARSER_PARSE_IMPL_OPERATION14_HPP
#define TXPL_PARSER_PARSE_IMPL_OPERATION14_HPP

#include <txpl/parser/parse_impl_fwd.hpp>
#include <txpl/parser/parse_fwd.hpp>
#include <txpl/parser/is_level_op.hpp>
#include <txpl/ast/operation14.hpp>
#include <txpl/ast/expr.hpp>

namespace txpl { namespace parser {
/** // doc: parse_impl<ast::operation<14>> {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename Value>
struct parse_impl<ast::operation<Iterator, Value, 14ul> >
{
  /** // doc: node_type {{{
   * \todo Write documentation
   */ // }}}
  typedef ast::operation<Iterator, Value, 14ul> node_type;
  /** // doc: operator_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename ast::operation<Iterator, Value, 14ul>::operator_type operator_type;
  /** // doc: expr_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename ast::operation<Iterator, Value, 14ul>::expr_type expr_type;
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
    if(!is_level_op<14ul>(op)) return false;
    Iterator it = ++first;
    if(op == '?')
      {
        ast::expr<Iterator, Value> expr1;
        if(!parse(first, last, expr1, f))
          {
            if(it == first)
              f(first, last, "expected sub-expression");
            return false;
          }
        if(first == last)
          {
            f(first, last, "expected colon");
            return false;
          }
        if(*first != ':')
          {
            f(first, last, "expected colon");
            return false;
          }
        it = ++first;
        ast::expr<Iterator, Value> expr2;
        if(!parse(first, last, expr2, f))
          {
            if(it == first)
              f(first, last, "expected sub-expression");
            return false;
          }
        node.expr[0] = expr1;
        node.expr[1] = expr2;
      }
    node.operator_ = op;
    return true;
  }
};
} } // end namespace txpl::parser

#include <txpl/parser/parse.hpp>

#endif /* TXPL_PARSER_PARSE_IMPL_OPERATION_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
