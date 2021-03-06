// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/get_qchar.hpp

/** // doc: txpl/lexer/get_qchar.hpp {{{
 * \file txpl/lexer/get_qchar.hpp
 * \brief Implements \ref txpl::lexer::get_qchar() "lexer::get_qchar()"
 */ // }}}
#ifndef TXPL_LEXER_GET_QCHAR_HPP_INCLUDED
#define TXPL_LEXER_GET_QCHAR_HPP_INCLUDED

#include <txpl/lexer/get_char.hpp>

namespace txpl { namespace lexer {
/** // doc: get_qchar() {{{
 * \ingroup LexerGroup
 * \brief Scan for a quoted character
 *
 * \param first   iterator pointing to the first character of the input to be
 *                scanned,
 * \param last    iterator pointing one after the last input character allowed
 *                to be scanned,
 * \param result  where the decoded character should be stored,
 * \param f       error handler.
 * \returns `true` on success of `false` otherwise
 *
 * \par Description
 *
 * The function implements lexer rule \ref ExpressionSyntaxLexerRules "qchar"
 * with semantic value retrieval.
 *
 * This function scans the content between iterators \e first and \e last
 * trying to decode a quoted character. It automatically handles all the
 * supported escape sequences. On success, the iterator \e first is
 * moved to the next position after the last scanned input character, the
 * decoded character gets stored to \e result and the function returns `true`.
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
 * \note This operation may leave un-scanned input characters and still be
 *       successful, that is it is possible that ``first != last`` at exit
 *       while the function returns `true`.
 */ // }}}
template<typename Iterator, typename T, typename Ehandler>
bool get_qchar(Iterator& first, Iterator const& last, T& result, Ehandler f)
{
  if(first == last)
    {
      f(first, last, "expected opening single-quote");
      return false;
    }
  if(*first != '\'')
    {
      f(first, last, "expected opening single-quote");
      return false;
    }
  ++first;
  if(first == last)
    {
      f(first, last, "incomplete quoted-character");
      return false;
    }
  if(*first == '\'')
    {
      f(first, last, "unexpected single-quote");
      return false;
    }
  T c; 
  if(!get_char(first, last, c, f))
    return false;
  if(first == last)
    {
      f(first, last, "expected closing single-quote");
      return false;
    }
  if(*first != '\'')
    {
      f(first, last, "expected closing single-quote");
      return false;
    }
  ++first;
  result = c;
  return true;
}
} } // end namespace txpl::lexer

#endif /* TXPL_LEXER_GET_QCHAR_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
