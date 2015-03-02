// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/get_qstring.hpp

/** // doc: txpl/lexer/get_qstring.hpp {{{
 * \file txpl/lexer/get_qstring.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_LEXER_GET_QSTRING_HPP_INCLUDED
#define TXPL_LEXER_GET_QSTRING_HPP_INCLUDED

#include <txpl/lexer/get_char.hpp>
#include <iterator>

namespace txpl { namespace lexer {
/** // doc: get_qstring() {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename T, typename Ehandler>
bool get_qstring(Iterator& first, Iterator const& last, T& result, Ehandler f)
{
  typedef typename std::iterator_traits<Iterator>::value_type CharT;
  typedef typename T::value_type C;
  if(first == last)
    {
      f(first, last, "expected opening double-quote");
      return false;
    }
  if(*first != CharT{'\"'})
    {
      f(first, last, "expected opening double-quote");
      return false;
    }
  ++first;
  if(first == last)
    {
      f(first, last, "incomplete double-quoted string");
      return false;
    }
  T s;
  while(*first != CharT{'\"'})
    {
      C c;
      if(!get_char(first, last, c, f))
        return false;
      if(first == last)
        {
          f(first, last, "incomplete double-quoted string");
          return false;
        }
      s.push_back(c);
    }
  ++first;
  result = s;
  return true;
}
} } // end namespace txpl::lexer

#endif /* TXPL_LEXER_GET_QSTRING_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
