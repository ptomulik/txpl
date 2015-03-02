// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/get_qstring.hpp

/** // doc: txpl/lexer/get_qstring.hpp {{{
 * \file txpl/lexer/get_qstring.hpp
 * \brief Implements \ref txpl::lexer::get_qstring() "lexer::get_qstring()"
 */ // }}}
#ifndef TXPL_LEXER_GET_QSTRING_HPP_INCLUDED
#define TXPL_LEXER_GET_QSTRING_HPP_INCLUDED

#include <txpl/lexer/get_char.hpp>
#include <iterator>

namespace txpl { namespace lexer {
/** // doc: get_qstring() {{{
 * \ingroup LexerGroup
 * \brief Scan for a double-quoted string
 *
 * \param first   iterator pointing to the first character of the input to be
 *                scanned,
 * \param last    iterator pointing one after the last input character allowed
 *                to be scanned,
 * \param result  where the decoded string should be stored,
 * \param f       error handler.
 * \returns `true` on success of `false` otherwise
 *
 * \par Description
 *
 * The function implements lexer rule \ref ExpressionSyntaxLexerRules "qstring"
 * with semantic value retrieval.
 *
 * This function scans the content between iterators \e first and \e last
 * trying to decode a double-quoted string. It automatically handles all
 * the supported escape sequences in the string. On success, the iterator
 * \e first is moved to the next position after the last scanned input
 * character, the decoded character gets stored to \e result and the function
 * returns `true`. On error, the iterator \e first is moved to the character at
 * which the error has been detected, the error handler \e f gets invoked and
 * the function returns `false`. The error handler \e f is invoked as follows:
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
