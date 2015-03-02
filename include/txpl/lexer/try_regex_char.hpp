// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/try_regex_char.hpp

/** // doc: txpl/lexer/try_regex_char.hpp {{{
 * \file txpl/lexer/try_regex_char.hpp
 * \brief Implements \ref txpl::lexer::try_regex_char() "lexer::try_regex_char()"
 */ // }}}
#ifndef TXPL_LEXER_TRY_REGEX_CHAR_HPP_INCLUDED
#define TXPL_LEXER_TRY_REGEX_CHAR_HPP_INCLUDED

#include <txpl/lexer/try_hex_digit.hpp>
#include <txpl/lexer/try_oct_digit.hpp>
#include <algorithm>

namespace txpl { namespace lexer {
/** // doc: try_regex_char() {{{
 * \ingroup LexerGroup
 * \brief Scan for a single character in regular expression specification
 *
 * \param first   iterator pointing to the first character of the input to be
 *                scanned,
 * \param last    iterator pointing one after the last input character allowed
 *                to be scanned,
 * \returns `true` on success of `false` otherwise
 *
 * \par Description
 *
 * The function implements lexer rule \ref ExpressionSyntaxLexerRules
 * "regex-char" without semantic value retrieval.
 *
 * This function scans the content between iterators \e first and \e last
 * trying to recognize a single character in a regular expression
 * definition. It automatically handles all the supported escape sequences. On
 * success, the iterator \e first is moved to the next position after the last
 * scanned input character. On error, the iterator \e first is moved to the
 * character at which the error has been detected and the function returns
 * `false`.
 *
 * \note This operation may leave un-scanned input characters and still be
 *       successful, that is it is possible that ``first != last`` at exit
 *       while the function returns `true`.
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
