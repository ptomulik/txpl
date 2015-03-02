// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/try_int.hpp

/** // doc: txpl/lexer/try_int.hpp {{{
 * \file txpl/lexer/try_int.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_LEXER_TRY_INT_HPP_INCLUDED
#define TXPL_LEXER_TRY_INT_HPP_INCLUDED

#include <txpl/lexer/try_oct_number.hpp>
#include <txpl/lexer/try_dec_number.hpp>
#include <txpl/lexer/try_hex_number.hpp>
#include <iterator>

namespace txpl { namespace lexer {
/** // doc: try_int {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator>
bool try_int(Iterator& first, Iterator const& last)
{
  typedef typename std::iterator_traits<Iterator>::value_type CharT;
  if(first == last) return false;
  if(*first == CharT{'0'})
    {
      ++first;
      if(first == last)                   return true;
      if(*first == CharT{'x'} || *first == CharT{'X'})
        return try_hex_number(++first, last);
      // We already have an octal value of '0', so we always return true.
      // The try_oct_number() is invoked only to scan for rest of number,
      // that is to move the 'first' iterator to proper position.
      try_oct_number(first, last);
      return true;
    }
  else
    return try_dec_number(first, last);
}
} } // end namespace txpl::lexer

#endif /* TXPL_LEXER_TRY_INT_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
