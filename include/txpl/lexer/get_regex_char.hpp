// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/get_regex_char.hpp

/** // doc: txpl/lexer/get_regex_char.hpp {{{
 * \file txpl/lexer/get_regex_char.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_LEXER_GET_REGEX_CHAR_HPP_INCLUDED
#define TXPL_LEXER_GET_REGEX_CHAR_HPP_INCLUDED

namespace txpl { namespace lexer {
/** // doc: get_regex_char() {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename T, typename Ehandler>
bool get_regex_char(Iterator& first, Iterator const& last, T& result, Ehandler f)
{
  if(first == last)
    {
      f(first, last, "expected regex-character specification");
      return false;
    }
  if(*first != '\\')
    {
      result = static_cast<T>(*first++);
      return true;
    }
  if((++first) == last)
    {
      result = T{'\\'};
      return true;
    }
  switch(*first)
    {
      case '\"':
        result = static_cast<T>(*first++);
        break;
      default:
        result = T{'\\'};
        break;
    }
  return true;
}
} } // end namespace txpl::lexer

#endif /* TXPL_LEXER_GET_REGEX_CHAR_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
