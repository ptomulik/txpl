// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/get_dec_number.hpp

/** // doc: txpl/lexer/get_dec_number.hpp {{{
 * \file txpl/lexer/get_dec_number.hpp
 * \brief Implements \ref txpl::lexer::get_dec_number() "lexer::get_dec_number()"
 */ // }}}
#ifndef TXPL_LEXER_GET_DEC_NUMBER_HPP_INCLUDED
#define TXPL_LEXER_GET_DEC_NUMBER_HPP_INCLUDED

#include <txpl/lexer/get_dec_digit.hpp>

namespace txpl { namespace lexer {
  /** // doc: get_dec_number() {{{
 * \ingroup LexerGroup
 * \brief Scan input for a decimal number
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
 * The function implements lexer rule \ref ExpressionSyntaxLexerRules
 * "dec-number" with semantic value retrieval.
 *
 * This function scans the content between iterators \e first and \e last
 * trying to decode a decimal number. On success, the iterator \e first is
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
bool get_dec_number(Iterator& first, Iterator const& last, T& result, Ehandler& f)
{
  if(first == last)
    {
      f(first, last, "decimal digit expected");
      return false;
    }
  T x; 
  if(!get_dec_digit(*first, x))
    {
      f(first, last, "decimal digit expected");
      return false;
    }
  for(++first;first != last;++first)
    {
      T y; 
      if(!get_dec_digit<T>(*first, y))
        {
          f(first, last, "decimal digit expected");
          return false;
        }
      y = x*10 + y;
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

#endif /* TXPL_LEXER_GET_DEC_NUMBER_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
