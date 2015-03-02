// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/get_word.hpp

/** // doc: txpl/lexer/get_word.hpp {{{
 * \file txpl/lexer/get_word.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_LEXER_GET_WORD_HPP_INCLUDED
#define TXPL_LEXER_GET_WORD_HPP_INCLUDED

#include <txpl/lexer/recognize_alpha.hpp>
#include <txpl/lexer/recognize_alnum.hpp>
#include <iterator>

namespace txpl { namespace lexer {
/** // doc: get_word() {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename T, typename Ehandler>
bool get_word(Iterator& first, Iterator const& last, T& result, Ehandler f)
{
  typedef typename std::iterator_traits<Iterator>::value_type CharT;
  Iterator it = first;
  if(first == last)
    {
      f(first, last, "expected letter or '_'");
      return false;
    }
  if(!recognize_alpha(*first) && *first != CharT{'_'})
    {
      f(first, last, "expected letter or '_'");
      return false;
    }
  for(++first; first != last; ++first)
    {
      if(!recognize_alnum(*first) && *first != CharT{'_'})
        {
          f(first, last, "expected letter, digit, or '_'");
          return false;
        }
    }
  result = T(it, last);
  return true;
}
} } // end namespace txpl::lexer

#endif /* TXPL_LEXER_GET_WORD_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
