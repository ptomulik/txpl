// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/parser/parse_impl_name.hpp

/** // doc: txpl/parser/parse_impl_name.hpp {{{
 * \file txpl/parser/parse_impl_name.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_PARSER_PARSE_IMPL_NAME_HPP
#define TXPL_PARSER_PARSE_IMPL_NAME_HPP

#include <txpl/parser/parse_impl_fwd.hpp>
#include <txpl/parser/parse_fwd.hpp>
#include <txpl/ast/nodes.hpp>
#include <txpl/lexer/token_t.hpp>
#include <txpl/lexer/get_word.hpp>
#include <txpl/lexer/get_content.hpp>

namespace txpl { namespace parser {
/** // doc: parse_impl<ast::name> {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename BasicTypes>
struct parse_impl<ast::name<Iterator, BasicTypes> >
{
  /** // doc: node_type {{{
   * \todo Write documentation
   */ // }}}
  typedef ast::name<Iterator, BasicTypes> node_type;
  /** // doc: string_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename ast::name<Iterator, BasicTypes>::value_type value_type;
  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  template<typename Ehandler>
  static bool
  apply(Iterator& first, Iterator const& last, node_type& node, Ehandler& eh)
  {
    if(first == last) return false;

    value_type val;
    value_type v2;

    auto beg = first->begin();
    auto end = first->end();
    if(*first == lexer::token_t::nssep_)
      {
        if(++first == last)
          {
            eh(first, last, "name expected");
            return false;
          }
        if(!lexer::get_content(beg, end, val, eh))
          return false;
        if(*first != lexer::token_t::word_)
          {
            eh(first, last, "name expected");
            return false;
          }
      }
    else if(*first != lexer::token_t::word_)
      return false;

    beg = first->begin();
    end = first->end();
    if(!lexer::get_word(beg, end, v2, eh))
      return false;
    val += v2;

    ++first;

    while(first != last)
      {
        if(*first != lexer::token_t::nssep_) break;

        beg = first->begin();
        end = first->end();
        if(!lexer::get_content(beg, end, v2, eh))
          return false;
        val += v2;

        if(++first == last)
          {
            eh(first, last, "name expected");
            return false;
          }

        if(*first != lexer::token_t::word_)
          {
            eh(first, last, "name expected");
            return false;
          }

        beg = first->begin();
        end = first->end();
        if(!lexer::get_word(beg, end, v2, eh))
          return false;
        val += v2;

        ++first;
      }
    node.value = val;
    return true;
  }
};
} } // end namespace txpl::parser

#include <txpl/parser/parse.hpp>

#endif /* TXPL_PARSER_PARSE_IMPL_NAME_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
