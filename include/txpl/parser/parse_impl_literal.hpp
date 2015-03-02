// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/parser/parse_impl_literal.hpp

/** // doc: txpl/parser/parse_impl_literal.hpp {{{
 * \file txpl/parser/parse_impl_literal.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_PARSER_PARSE_IMPL_LITERAL_HPP
#define TXPL_PARSER_PARSE_IMPL_LITERAL_HPP

#include <txpl/parser/parse_impl_fwd.hpp>
#include <txpl/parser/parse_fwd.hpp>
#include <txpl/ast/nodes.hpp>
#include <txpl/lexer/token_t.hpp>
#include <txpl/lexer/get_qchar.hpp>
#include <txpl/lexer/get_int.hpp>
#include <txpl/lexer/get_real.hpp>
#include <txpl/lexer/get_qstring.hpp>
#include <txpl/lexer/get_qregex.hpp>

namespace txpl { namespace parser {
/** // doc: parse_impl<ast::literal> {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename BasicTypes>
struct parse_impl<ast::literal<Iterator, BasicTypes> >
{
  /** // doc: node_type {{{
   * \todo Write documentation
   */ // }}}
  typedef ast::literal<Iterator, BasicTypes> node_type;
  /** // doc: char_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename BasicTypes::char_type char_type;
  /** // doc: int_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename BasicTypes::int_type int_type;
  /** // doc: bool_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename BasicTypes::bool_type bool_type;
  /** // doc: real_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename BasicTypes::real_type real_type;
  /** // doc: string_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename BasicTypes::string_type string_type;
  /** // doc: regex_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename BasicTypes::regex_type regex_type;

  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  template<typename Ehandler>
  static bool
  apply(Iterator& first, Iterator const& last, node_type& node, Ehandler& eh)
  {
    if(first == last)
      return false;

    auto beg = first->begin();
    auto end = first->end();

    if(*first == lexer::token_t::qchar_)
      {
        char_type x;
        if(!lexer::get_qchar(beg, end, x, eh))
          return false;
        node.value = x;
      }
    else if(*first == lexer::token_t::int_)
      {
        int_type x;
        if(!lexer::get_int(beg, end, x, eh))
          return false;
        node.value = x;
      }
    else if(*first == lexer::token_t::word_)
      {
        const char* t = "true";
        const char* f = "false";
        string_type word(beg, end);
        if(word == string_type(t, t+4))
          node.value = true;
        else if(word == string_type(f, f+5))
          node.value = false;
        else
          return false;
      }
    else if(*first == lexer::token_t::real_)
      {
        real_type x;
        if(!lexer::get_real(beg, end, x, eh))
          return false;
        node.value = x;
      }
    else if(*first == lexer::token_t::qstring_)
      {
        string_type x;
        if(!lexer::get_qstring(beg, end, x, eh))
          return false;
        node.value = x;
      }
    else if(*first == lexer::token_t::qregex_)
      {
        regex_type x;
        if(!lexer::get_qregex(beg, end, x, eh))
          return false;
        node.value = x;
      }
    else
      return false;

    ++first;
    return true;
  }
};
} } // end namespace txpl::parser

#include <txpl/parser/parse.hpp>

#endif /* TXPL_PARSER_PARSE_IMPL_LITERAL_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
