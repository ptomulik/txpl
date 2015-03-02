// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/try_real.hpp

/** // doc: txpl/lexer/try_real.hpp {{{
 * \file txpl/lexer/try_real.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_LEXER_TRY_REAL_HPP_INCLUDED
#define TXPL_LEXER_TRY_REAL_HPP_INCLUDED

#include <txpl/lexer/try_dec_number.hpp>
#include <iterator>

namespace txpl { namespace lexer {
/** // doc: try_exponent {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator>
bool try_exponent(Iterator& first, Iterator const& last)
{
  typedef typename std::iterator_traits<Iterator>::value_type CharT;
  if(first == last)                                 return false;
  if(*first != CharT{'e'} && *first != CharT{'E'})  return false;
  if(++first == last)                               return false;
  if(*first == CharT{'-'} || *first == CharT{'+'})  ++first;
  if(!try_dec_number(first, last))                  return false;
  return true;
}
/** // doc: try_real {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator>
bool try_real(Iterator& first, Iterator const& last)
{
  typedef typename std::iterator_traits<Iterator>::value_type CharT;
  if(try_dec_number(first, last))
    {
      if(*first == CharT{'.'})
        try_dec_number(++first, last);
      else
        return try_exponent(first, last);
    }
  else
    {
      if(*first != CharT{'.'})          return false;
      if(!try_dec_number(++first,last)) return false;
    }
  Iterator tmp = first;
  if(try_exponent(first, last))     return true;
  if(tmp != first)                  return false; // exponent has no digits
  return true;
}
} } // end namespace txpl::lexer

#endif /* TXPL_LEXER_TRY_REAL_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
