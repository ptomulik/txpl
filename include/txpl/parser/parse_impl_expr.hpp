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
#include <txpl/ast/nodes.hpp>

namespace txpl { namespace parser {
/** // doc: parse_impl<ast::expr<BasicTypes, Level>> {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename BasicTypes, size_t Level>
struct parse_impl<ast::expr<Iterator, BasicTypes, Level> >
{
  /** // doc: node_type {{{
   * \todo Write documentation
   */ // }}}
  typedef ast::expr<Iterator, BasicTypes, Level> node_type;
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  template<typename Ehandler>
  static bool
  apply(Iterator& first, Iterator const& last, node_type& node, Ehandler& eh)
  {
    typename node_type::tail_type::value_type operation;
    typename node_type::tail_type tail;

    Iterator it = first;
    if(!parse(first, last, node.head, eh)) return false;
    for(it = first; parse(first, last, operation, eh); it = first)
      tail.push_back(operation);
    if(it != first)
      return false; // indicates error detected by children ...
    node.tail = tail;
    return true;
  }
};
/** // doc: parse_impl<ast::expr<Iterator, BasicTypes, Level>> {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename BasicTypes>
struct parse_impl<ast::expr<Iterator, BasicTypes> >
{
  /** // doc: node_type {{{
   * \todo Write documentation
   */ // }}}
  typedef ast::expr<Iterator, BasicTypes> node_type;
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  template<typename Ehandler>
  static bool
  apply(Iterator& first, Iterator const& last, node_type& node, Ehandler& eh)
  {
    typename node_type::tail_type::value_type operation;
    typename node_type::tail_type tail;

    Iterator it = first;
    if(!parse(first, last, node.head, eh))
      {
        if(it == first)
          eh(first, last, "expected expression");
        return false;
      }
    for(it = first; parse(first, last, operation, eh); it = first)
      tail.push_back(operation);
    if(it != first)
      return false; // indicates error detected by children ...
    node.tail = tail;
    return true;
  }
};
/** // doc: parse_impl<ast::expr<0> > {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename BasicTypes>
struct parse_impl<ast::expr<Iterator, BasicTypes, 0ul> >
{
  /** // doc: node_type {{{
   * \todo Write documentation
   */ // }}}
  typedef ast::expr<Iterator, BasicTypes, 0ul> node_type;
  /** // doc: braced_expr_type {{{
   * \todo Write documentation
   */ // }}}
  typedef ast::braced_expr<Iterator, BasicTypes> braced_expr_type;
  /** // doc: unary_expr_type {{{
   * \todo Write documentation
   */ // }}}
  typedef ast::unary_expr<Iterator, BasicTypes> unary_expr_type;
  /** // doc: name_type {{{
   * \todo Write documentation
   */ // }}}
  typedef ast::name<Iterator, BasicTypes> name_type;
  /** // doc: literal_type {{{
   * \todo Write documentation
   */ // }}}
  typedef ast::literal<Iterator, BasicTypes> literal_type;
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  template<typename Ehandler>
  static bool
  apply(Iterator& first, Iterator const& last, node_type& node, Ehandler& eh)
  {
    if(first == last) return false;

    Iterator it = first;

    braced_expr_type braced;
    if(parse(first, last, braced, eh))
      {
        node.attrib = braced;
        return true;
      }
    else if(it != first)
      return false;

    unary_expr_type unary;
    if(parse(first, last, unary, eh))
      {
        node.attrib = unary;
        return true;
      }
    else if(it != first)
      return false;

    literal_type literal;
    if(parse(first, last, literal, eh))
      {
        node.attrib = literal;
        return true;
      }
    else if(it != first)
      return false;

    name_type name;
    if(parse(first, last, name, eh))
      {
        node.attrib = name;
        return true;
      }

    return false;
  }
};
} } // end namespace txpl::parser

#include <txpl/parser/parse.hpp>

#endif /* TXPL_PARSER_PARSE_IMPL_EXPR_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
