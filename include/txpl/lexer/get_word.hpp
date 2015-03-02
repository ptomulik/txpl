// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/get_word.hpp

/** // doc: txpl/lexer/get_word.hpp {{{
 * \file txpl/lexer/get_word.hpp
 * \brief Implements \ref txpl::lexer::get_word() "lexer::get_word()"
 */ // }}}
#ifndef TXPL_LEXER_GET_WORD_HPP_INCLUDED
#define TXPL_LEXER_GET_WORD_HPP_INCLUDED

#include <txpl/lexer/recognize_alpha.hpp>
#include <txpl/lexer/recognize_alnum.hpp>
#include <iterator>

namespace txpl { namespace lexer {
/** // doc: get_word() {{{
 * \ingroup LexerGroup
 * \brief Scan for a word
 *
 * \param first   iterator pointing to the first character of the input to be
 *                scanned,
 * \param last    iterator pointing one after the last input character allowed
 *                to be scanned,
 * \param result  where the word should be stored, must be a mutble to a string
 *                variable,
 * \param f       error handler.
 * \returns `true` on success of `false` otherwise
 *
 * \par Description
 *
 * The function implements lexer rule \ref ExpressionSyntaxLexerRules "word"
 * with semantic value retrieval.
 *
 * This function scans the content between iterators \e first and \e last
 * trying to recognize a word. On success, the iterator \e first is moved to
 * the next position after the last scanned input character, the decoded
 * character gets stored to \e result and the function returns `true`. On
 * error, the iterator \e first is moved to the character at which the error
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
bool get_word(Iterator& first, Iterator const& last, T& result, Ehandler f)
{
  typedef typename std::iterator_traits<Iterator>::value_type CharT;
  Iterator it = first;
  if(first == last)
    {
      f(first, last, "expected letter or '_'");
      return false;
    }
  if(!recognize_alpha(*first) && *first != CharT{'_'})
    {
      f(first, last, "expected letter or '_'");
      return false;
    }
  for(++first; first != last; ++first)
    {
      if(!recognize_alnum(*first) && *first != CharT{'_'})
        {
          f(first, last, "expected letter, digit, or '_'");
          return false;
        }
    }
  result = T(it, last);
  return true;
}
} } // end namespace txpl::lexer

#endif /* TXPL_LEXER_GET_WORD_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
