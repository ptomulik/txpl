// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/get_char.hpp

/** // doc: txpl/lexer/get_char.hpp {{{
 * \file txpl/lexer/get_char.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_LEXER_GET_CHAR_HPP_INCLUDED
#define TXPL_LEXER_GET_CHAR_HPP_INCLUDED

#include <txpl/lexer/get_oct_number.hpp>
#include <txpl/lexer/get_hex_number.hpp>
#include <txpl/lexer/recognize_printable.hpp>
#include <iterator>
#include <type_traits>

namespace txpl { namespace lexer {
/** // doc: get_char() {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename T, typename Ehandler>
bool get_char(Iterator& first, Iterator const& last, T& result, Ehandler f)
{
  // The TU type is used to avoid some overflow errors from get_oct_number(),
  // and get_hex_number(). For example, if `char' is a signed type on given
  // platform, then `\xFF' would cause an overflow error, whereas the same
  // code would not cause overflows for `unsigned char'.
  typedef typename std::make_unsigned<T>::type TU;
  typedef typename std::iterator_traits<Iterator>::value_type CharT;
  if(first == last)
    {
      f(first, last, "expected character specification");
      return false;
    }
  if(*first != '\\')
    {
      if(!recognize_printable(*first))
        {
          f(first, last, "non-printable character in character specification");
          return false;
        }
      result = static_cast<T>(*first++);
      return true;
    }
  ++first;
  if(first == last)
    {
      f(first, last, "incomplete escape sequence");
      return false;
    }

  if(recognize_oct_digit(*first))
    {
      TU x;
      if(!get_oct_number(first, last, x, f)) return false;
      result = static_cast<T>(x);
      return true;
    }
  else if(*first == 'x' || *first == 'X')
    {
      ++first;
      if(first == last)
        {
          f(first, last, "incomplete escape sequence");
          return false;
        }
      TU x;
      if(!get_hex_number(first, last, x, f)) return false;
      result = static_cast<T>(x);
      return true;
    }
  else
    {
      switch(*first)
        {
          case CharT{'\"'}:  result = T{'\"'}; break;
          case CharT{'\''}:  result = T{'\''}; break;
          case CharT{'\?'}:  result = T{'\?'}; break;
          case CharT{'\\'}:  result = T{'\\'}; break;
          case CharT{'a'}:   result = T{'\a'}; break;
          case CharT{'b'}:   result = T{'\b'}; break;
          case CharT{'f'}:   result = T{'\f'}; break;
          case CharT{'n'}:   result = T{'\n'}; break;
          case CharT{'r'}:   result = T{'\r'}; break;
          case CharT{'t'}:   result = T{'\t'}; break;
          case CharT{'v'}:   result = T{'\v'}; break;
          default:
            f(first, last, "invalid escape sequence");
            return false;
        }
      ++first;
      return true;
    }
}
} } // end namespace txpl::lexer

#endif /* TXPL_LEXER_GET_CHAR_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
