// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/parser/parse_impl_symbol.hpp

/** // doc: txpl/parser/parse_impl_symbol.hpp {{{
 * \file txpl/parser/parse_impl_symbol.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_PARSER_PARSE_IMPL_SYMBOL_HPP
#define TXPL_PARSER_PARSE_IMPL_SYMBOL_HPP

#include <txpl/parser/parse_impl_fwd.hpp>
#include <txpl/parser/parse_fwd.hpp>
#include <txpl/ast/nodes.hpp>
#include <txpl/lexer/token_t.hpp>
#include <txpl/lexer/get_word.hpp>
#include <txpl/lexer/get_content.hpp>

namespace txpl { namespace parser {
/** // doc: parse_impl<ast::symbol> {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator>
struct parse_impl<ast::symbol<Iterator> >
{
  /** // doc: node_type {{{
   * \todo Write documentation
   */ // }}}
  typedef ast::symbol<Iterator> node_type;
  /** // doc: string_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename ast::symbol<Iterator>::name_type name_type;
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  template<typename Ehandler>
  static bool
  apply(Iterator& first, Iterator const& last, node_type& node, Ehandler f)
  {
    if(first == last) return false;

    name_type name;
    name_type n2;

    auto beg = first->begin();
    auto end = first->end();
    if(*first == lexer::token_t::nssep_)
      {
        if(++first == last)
          {
            f(first, last, "name expected");
            return false;
          }
        if(!lexer::get_content(beg, end, name, f))
          return false;
        if(*first != lexer::token_t::word_)
          {
            f(first, last, "name expected");
            return false;
          }
      }
    else if(*first != lexer::token_t::word_)
      return false;

    beg = first->begin();
    end = first->end();
    if(!lexer::get_word(beg, end, n2, f))
      return false;
    name += n2;

    ++first;

    while(first != last)
      {
        if(*first != lexer::token_t::nssep_) break;

        beg = first->begin();
        end = first->end();
        if(!lexer::get_content(beg, end, n2, f))
          return false;
        name += n2;

        if(++first == last)
          {
            f(first, last, "name expected");
            return false;
          }

        if(*first != lexer::token_t::word_)
          {
            f(first, last, "name expected");
            return false;
          }

        beg = first->begin();
        end = first->end();
        if(!lexer::get_word(beg, end, n2, f))
          return false;
        name += n2;

        ++first;
      }
    node.name = name;
    return true;
  }
};
} } // end namespace txpl::parser

#include <txpl/parser/parse.hpp>

#endif /* TXPL_PARSER_PARSE_IMPL_SYMBOL_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
