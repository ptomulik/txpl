// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/get_int.hpp

/** // doc: txpl/lexer/get_int.hpp {{{
 * \file txpl/lexer/get_int.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_LEXER_GET_INT_HPP_INCLUDED
#define TXPL_LEXER_GET_INT_HPP_INCLUDED

#include <txpl/lexer/get_oct_number.hpp>
#include <txpl/lexer/get_dec_number.hpp>
#include <txpl/lexer/get_hex_number.hpp>
#include <iterator>

namespace txpl { namespace lexer {
/** // doc: get_int() {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename T, typename Ehandler>
bool get_int(Iterator& first, Iterator const& last, T& result, Ehandler f)
{
  typedef typename std::iterator_traits<Iterator>::value_type CharT;
  if(first == last)
    {
      f(first, last, "decimal digit expected");
      return false;
    }
  if(*first == CharT{'0'})
    {
      ++first;
      if(first == last)
        {
          result = T{0};
          return true;
        }
      if(*first == 'x' || *first == 'X')
        return get_hex_number(++first, last, result, f);
      else
        return get_oct_number(first, last, result, f);
    }
  else
    return get_dec_number(first, last, result, f);
}
} } // end namespace txpl::lexer

#endif /* TXPL_LEXER_GET_INT_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
