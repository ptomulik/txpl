// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/get_qchar.hpp

/** // doc: txpl/lexer/get_qchar.hpp {{{
 * \file txpl/lexer/get_qchar.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_LEXER_GET_QCHAR_HPP_INCLUDED
#define TXPL_LEXER_GET_QCHAR_HPP_INCLUDED

#include <txpl/lexer/get_char.hpp>

namespace txpl { namespace lexer {
/** // doc: get_qchar() {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename T, typename Ehandler>
bool get_qchar(Iterator& first, Iterator const& last, T& result, Ehandler f)
{
  if(first == last)
    {
      f(first, last, "expected opening single-quote");
      return false;
    }
  if(*first != '\'')
    {
      f(first, last, "expected opening single-quote");
      return false;
    }
  ++first;
  if(first == last)
    {
      f(first, last, "incomplete quoted-character");
      return false;
    }
  if(*first == '\'')
    {
      f(first, last, "unexpected single-quote");
      return false;
    }
  T c; 
  if(!get_char(first, last, c, f))
    return false;
  if(first == last)
    {
      f(first, last, "expected closing single-quote");
      return false;
    }
  if(*first != '\'')
    {
      f(first, last, "expected closing single-quote");
      return false;
    }
  ++first;
  result = c;
  return true;
}
} } // end namespace txpl::lexer

#endif /* TXPL_LEXER_GET_QCHAR_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
