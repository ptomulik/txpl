// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/parser/parse_impl_operation.hpp

/** // doc: txpl/parser/parse_impl_operation1.hpp {{{
 * \file txpl/parser/parse_impl_operation1.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_PARSER_PARSE_IMPL_OPERATION1_HPP
#define TXPL_PARSER_PARSE_IMPL_OPERATION1_HPP

#include <txpl/parser/parse_impl_fwd.hpp>
#include <txpl/parser/parse_fwd.hpp>
#include <txpl/ast/operation1.hpp>
#include <txpl/ast/expr.hpp>
#include <utility>

namespace txpl { namespace parser {
/** // doc: parse_impl<ast::operation<1>> {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename Value>
struct parse_impl<ast::operation<Iterator, Value, 1ul> >
{
  /** // doc: node_type {{{
   * \todo Write documentation
   */ // }}}
  typedef ast::operation<Iterator, Value, 1ul> node_type;
  /** // doc: operator_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename node_type::operator_type operator_type;
  /** // doc: expr_type {{{
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
    if(*first == '[')
      {
        expr_type expr;
        Iterator it = ++first;
        if(!parse(first, last, expr, f))
          {
            if(it == first)
              f(first, last, "expected expression");
            return false;
          }
        if(first == last)
          {
            f(first, last, "missing closing square bracket");
            return false;
          }
        if(*first != ']')
          {
            f(first, last, "missing closing square bracket");
            return false;
          }
        ++first;
        node.expr = std::move(expr);
        node.operator_ = vm::op_t::subscript_;
        return true;
      }
    else
      return false;
  }
};
} } // end namespace txpl::parser

#include <txpl/parser/parse.hpp>

#endif /* TXPL_PARSER_PARSE_IMPL_OPERATION1_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
