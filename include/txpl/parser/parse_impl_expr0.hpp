// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/parser/parse_impl_expr.hpp

/** // doc: txpl/parser/parse_impl_expr0.hpp {{{
 * \file txpl/parser/parse_impl_expr0.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_PARSER_PARSE_IMPL_EXPR0_HPP
#define TXPL_PARSER_PARSE_IMPL_EXPR0_HPP

#include <txpl/parser/parse_impl_fwd.hpp>
#include <txpl/parser/parse_fwd.hpp>
#include <txpl/ast/expr0.hpp>
#include <txpl/ast/braced_expr.hpp>
#include <txpl/ast/array_expr.hpp>
#include <txpl/ast/symbol.hpp>
#include <txpl/ast/literal.hpp>
#include <utility>

namespace txpl { namespace parser {
/** // doc: parse_impl<ast::expr<0> > {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename Value>
struct parse_impl<ast::expr<Iterator, Value, 0ul> >
{
  /** // doc: node_type {{{
   * \todo Write documentation
   */ // }}}
  typedef ast::expr<Iterator, Value, 0ul> node_type;
  /** // doc: braced_expr_type {{{
   * \todo Write documentation
   */ // }}}
  typedef ast::braced_expr<Iterator, Value> braced_expr_type;
  /** // doc: array_expr_type {{{
   * \todo Write documentation
   */ // }}}
  typedef ast::array_expr<Iterator, Value> array_expr_type;
  /** // doc: name_type {{{
   * \todo Write documentation
   */ // }}}
  typedef ast::symbol<Iterator> name_type;
  /** // doc: literal_type {{{
   * \todo Write documentation
   */ // }}}
  typedef ast::literal<Iterator, Value> literal_type;
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
      braced_expr_type braced;
      if(parse(first, last, braced, f))
        {
          node.expr = std::move(braced);
          return true;
        }
      else if(it != first)
        return false;
    }

    {
      array_expr_type array;
      if(parse(first, last, array, f))
        {
          node.expr = std::move(array);
          return true;
        }
      else if(it != first)
        return false;
    }

    {
      literal_type literal;
      if(parse(first, last, literal, f))
        {
          node.expr = std::move(literal);
          return true;
        }
      else if(it != first)
        return false;
    }

    {
      name_type name;
      if(parse(first, last, name, f))
        {
          node.expr = std::move(name);
          return true;
        }
    }

    return false;
  }
};
} } // end namespace txpl::parser

#include <txpl/parser/parse.hpp>

#endif /* TXPL_PARSER_PARSE_IMPL_EXPR0_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
