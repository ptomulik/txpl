// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/try_qregex.hpp

/** // doc: txpl/lexer/try_qregex.hpp {{{
 * \file txpl/lexer/try_qregex.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_LEXER_TRY_QREGEX_HPP_INCLUDED
#define TXPL_LEXER_TRY_QREGEX_HPP_INCLUDED

#include <txpl/lexer/try_regex_char.hpp>
#include <iterator>

namespace txpl { namespace lexer {
/** // doc: try_qregex {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator>
bool try_qregex(Iterator& first, Iterator const& last)
{
  typedef typename std::iterator_traits<Iterator>::value_type CharT;

  if(first == last) return false;
  switch(*first)
    {
      case CharT{'r'}:
      case CharT{'b'}:
      case CharT{'x'}:
      case CharT{'a'}:
      case CharT{'g'}:
      case CharT{'e'}:
        break;
      default:
        return false;
    }
  if(++first == last)         return false;
  if(*first != CharT{'\"'})   return false;
  if(++first == last)         return false;
  while(*first != CharT{'\"'})
    {
      if(!try_regex_char(first, last))  return false;
      if(first == last)                 return false;
    }
  ++first;
  bool iseen = false, cseen = false;
  for(size_t n=0; n < 2 && first != last; ++n)
    {
      switch(*first)
        {
          case CharT{'i'}:
            if(!iseen)
              {
                iseen = true;
                ++first;
              }
            else
              n = 2;
            break;
          case CharT{'c'}:
            if(!cseen)
              {
                cseen = true;
                ++first;
              }
            else
              n = 2;
            break;
          default:
            n = 2;
            break;
        }
    }
  return true;
}
} } // end namespace txpl::lexer

#endif /* TXPL_LEXER_TRY_QREGEX_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
