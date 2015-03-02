// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/get_dec_digit.hpp

/** // doc: txpl/lexer/get_dec_digit.hpp {{{
 * \file txpl/lexer/get_dec_digit.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_LEXER_GET_DEC_NUMBER_HPP_INCLUDED
#define TXPL_LEXER_GET_DEC_NUMBER_HPP_INCLUDED

#include <txpl/lexer/get_dec_digit.hpp>

namespace txpl { namespace lexer {
  /** // doc: get_dec_number() {{{
   * \todo Write documentation
   */ // }}}
template<typename Iterator, typename T, typename Ehandler>
bool get_dec_number(Iterator& first, Iterator const& last, T& result, Ehandler& f)
{
  if(first == last)
    {
      f(first, last, "decimal digit expected");
      return false;
    }
  T x; 
  if(!get_dec_digit(*first, x))
    {
      f(first, last, "decimal digit expected");
      return false;
    }
  for(++first;first != last;++first)
    {
      T y; 
      if(!get_dec_digit<T>(*first, y))
        {
          f(first, last, "decimal digit expected");
          return false;
        }
      y = x*10 + y;
      if(y < x)
        {
          f(first, last, "integer constant too large for this type");
          return false;
        }
      x = y;
    }
  result = x;
  return true;
}
} } // end namespace txpl::lexer

#endif /* TXPL_LEXER_GET_DEC_NUMBER_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
