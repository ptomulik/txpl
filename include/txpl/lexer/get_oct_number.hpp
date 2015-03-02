// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/get_oct_number.hpp

/** // doc: txpl/lexer/get_oct_number.hpp {{{
 * \file txpl/lexer/get_oct_number.hpp
 * \brief Implements \ref txpl::lexer::get_oct_number() "lexer::get_oct_number()"
 */ // }}}
#ifndef TXPL_LEXER_GET_OCT_NUMBER_HPP_INCLUDED
#define TXPL_LEXER_GET_OCT_NUMBER_HPP_INCLUDED

#include <txpl/lexer/get_oct_digit.hpp>

namespace txpl { namespace lexer {
/** // doc: get_oct_number() {{{
 * \ingroup LexerGroup
 * \brief Scan input for an octal number
 *
 * \param first   iterator pointing to the first character of the input to be
 *                scanned,
 * \param last    iterator pointing one after the last input character allowed
 *                to be scanned,
 * \param result  where the decoded number should be stored, a mutable
 *                reference to integer variable,
 * \param f       error handler.
 * \returns `true` on success of `false` otherwise
 *
 * \par Description
 *
 * The function is used to implement lexer rule \ref ExpressionSyntaxLexerRules
 * "oct-number" with semantic value retrieval.
 *
 * This function scans the content between iterators \e first and \e last
 * trying to decode an octal number. On success, the iterator \e first is
 * moved to the next position after the last scanned input character, the
 * decoded number gets stored to \e result and the function returns `true`.
 * On error, the iterator \e first is moved to the character at which the error
 * has been detected, the error handler \e f gets invoked and the function
 * returns `false`. The error handler \e f is invoked as follows:
 *
 * \code
 *  f(it, last, msg)
 * \endcode
 *
 * with
 *
 *  - \e it being an iterator pointing to the erroneous character,
 *  - \e last being same as the \e last iterator provided to
 *       \ref txpl::lexer::get_char() "lexer::get_char()"
 *  - \e msg being a null-terminated C string with an error message.
 *
 * \note This function must scan all the characters between \e first and \e
 *       last to be successful.
 */ // }}}
template<typename Iterator, typename T, typename Ehandler>
bool get_oct_number(Iterator& first, Iterator const& last, T& result, Ehandler f)
{
  T x;
  if(first == last)
    {
      f(first, last, "octal digit expected");
      return false;
    }
  if(!get_oct_digit(*first, x))
    {
      f(first, last, "octal digit expected");
      return false;
    }
  for(++first;first != last;++first)
    {
      T y;
      if(!get_oct_digit(*first, y))
        {
          f(first, last, "octal digit expected");
          return false;
        }
      y = (x << 3) | y;
      if(y < x)
        {
          f(first, last, "integer constant too large for this type");
          return false;
        }
      x = y;
    }
  result = x;
  return true;
}
} } // end namespace txpl::lexer

#endif /* TXPL_LEXER_GET_OCT_NUMBER_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
