// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/try_token.hpp

/** // doc: txpl/lexer/try_token.hpp {{{
 * \file txpl/lexer/try_token.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_LEXER_TRY_TOKEN_HPP_INCLUDED
#define TXPL_LEXER_TRY_TOKEN_HPP_INCLUDED

#include <txpl/lexer/token_t.hpp>
#include <txpl/lexer/try_real.hpp>
#include <txpl/lexer/try_int.hpp>
#include <txpl/lexer/try_qchar.hpp>
#include <txpl/lexer/try_qstring.hpp>
#include <txpl/lexer/try_qregex.hpp>
#include <txpl/lexer/try_word.hpp>
#include <txpl/lexer/try_spaces.hpp>
#include <iterator>

namespace txpl { namespace lexer {
/** // doc: try_token() {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator>
token_t try_token(Iterator const& first, Iterator const& last, Iterator& next)
{
  typedef typename std::iterator_traits<Iterator>::value_type CharT;

  if((next = first) == last)          return token_t::invalid_;
  if(try_spaces(next, last))          return token_t::spaces_;
  if(try_real(next, last))            return token_t::real_;
  if(try_int(next = first, last))     return token_t::int_;
  if(try_qchar(next = first, last))   return token_t::qchar_;
  if(try_qstring(next = first, last)) return token_t::qstring_;
  if(try_qregex(next = first, last))  return token_t::qregex_;
  if(try_word(next = first, last))    return token_t::word_;
  // operators
  next = first;
  switch(*first)
    {
      case CharT{'+'}:
      case CharT{'-'}:
      case CharT{'*'}:
      case CharT{'/'}:
      case CharT{'%'}:
      case CharT{'^'}:
      case CharT{'~'}:
      case CharT{','}:
      case CharT{'.'}:
      case CharT{'('}:
      case CharT{')'}:
      case CharT{'['}:
      case CharT{']'}:
      case CharT{'{'}:
      case CharT{'}'}:
      case CharT{'?'}:
        ++next;
        return static_cast<token_t>(*first);
      case CharT{'&'}:
        ++next;
        if(next != last && *next == CharT{'&'})
          {
            ++next;
            return token_t::and_;
          }
        else
          return token_t::bitand_;
      case CharT{'|'}:
        ++next;
        if(next != last && *next == CharT{'|'})
          {
            ++next;
            return token_t::or_;
          }
        else
          return token_t::bitor_;
      case CharT{'<'}:
        if(++next != last)
          {
            if(*next == CharT{'<'})
              {
                ++next;
                return token_t::lshift_;
              }
            else if(*next == CharT{'='})
              {
                ++next;
                return token_t::le_;
              }
            else
              return token_t::lt_;
          }
        else
          return token_t::lt_;
      case CharT{'>'}:
        if(++next != last)
          {
            if(*next == CharT{'>'})
              {
                ++next;
                return token_t::rshift_;
              }
            else if(*next == CharT{'='})
              {
                ++next;
                return token_t::ge_;
              }
            else
              return token_t::gt_;
          }
        else
          return token_t::gt_;
      case CharT{'!'}:
        if(++next != last)
          {
            if(*next == CharT{'='})
              {
                ++next;
                return token_t::neq_;
              }
            else if(*next == CharT{'~'})
              {
                ++next;
                return token_t::nmatch_;
              }
            else
              return token_t::not_;
          }
        else
          return token_t::not_;
      case CharT{'='}:
        if(++next != last)
          {
            if(*next == CharT{'='})
              {
                ++next;
                return token_t::eq_;
              }
            else if(*next == CharT{'~'})
              {
                ++next;
                return token_t::match_;
              }
          }
        break;
      case CharT{':'}:
        ++next;
        if(next == last)
          return token_t::colon_;
        if(*next == CharT{':'})
          {
            ++next;
            return token_t::nssep_;
          }
        else
          return token_t::colon_;
        break;
    }
  // search for the nearest space
  for(;next != last; ++next)
  {
    Iterator it;
    if(try_spaces(it = next, last)) break;
  }
  return token_t::invalid_;
}
} } // end namespace txpl::lexer

#endif /* TXPL_LEXER_TRY_TOKEN_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
