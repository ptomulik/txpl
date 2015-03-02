// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/try_char.hpp

/** // doc: txpl/lexer/try_char.hpp {{{
 * \file txpl/lexer/try_char.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_LEXER_TRY_CHAR_HPP_INCLUDED
#define TXPL_LEXER_TRY_CHAR_HPP_INCLUDED

#include <txpl/lexer/recognize_oct_digit.hpp>
#include <txpl/lexer/recognize_printable.hpp>
#include <txpl/lexer/try_hex_number.hpp>
#include <txpl/lexer/try_oct_number.hpp>
#include <iterator>

namespace txpl { namespace lexer {
/** // doc: try_char() {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator>
bool try_char(Iterator& first, Iterator const& last)
{
  typedef typename std::iterator_traits<Iterator>::value_type CharT;
  if(first == last)                     return false;
  if(*first != CharT{'\\'})
    {
      if(!recognize_printable(*first))  return false;
      ++first;
      return true;
    }
  if(++first == last)                   return false;
  if(recognize_oct_digit(*first) != 0)
    {
      Iterator ahead = first;
      // The following loop has same effect as:
      //  std::advance(ahead, std::min(3, std::distance(first, last)));
      for(size_t n = 3; n>0 && ahead != last; --n, ++ahead) { }
      if(!try_oct_number(first, ahead)) return false;
    }
  else if(*first == 'x' || *first == 'X')
    {
      if((++first) == last)             return false;
      if(!try_hex_number(first, last))  return false;
    }
  else
    {
      switch(*first)
        {
          case CharT{'\"'}:
          case CharT{'\''}:
          case CharT{'\?'}:
          case CharT{'\\'}:
          case CharT{'a'}:
          case CharT{'b'}:
          case CharT{'f'}:
          case CharT{'n'}:
          case CharT{'r'}:
          case CharT{'t'}:
          case CharT{'v'}:
            break;
          default:
            return false;
        }
      ++first;
    }
  return true;
}
} } // end namespace txpl::lexer

#endif /* TXPL_LEXER_TRY_CHAR_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
