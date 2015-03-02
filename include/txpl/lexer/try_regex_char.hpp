// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/try_regex_char.hpp

/** // doc: txpl/lexer/try_regex_char.hpp {{{
 * \file txpl/lexer/try_regex_char.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_LEXER_TRY_REGEX_CHAR_HPP_INCLUDED
#define TXPL_LEXER_TRY_REGEX_CHAR_HPP_INCLUDED

#include <txpl/lexer/try_hex_digit.hpp>
#include <txpl/lexer/try_oct_digit.hpp>
#include <algorithm>

namespace txpl { namespace lexer {
/** // doc: try_regex_char() {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator>
bool try_regex_char(Iterator& first, Iterator const& last)
{
  if(first == last)     return false;
  if(*first++ != '\\')  return true;
  if(first == last)     return true;

  switch(*first)
    {
      case '\"':
        break;
      default:
        return true;
    }
  ++first;
  return true;
}
} } // end namespace txpl::lexer

#endif /* TXPL_LEXER_TRY_REGEX_CHAR_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
