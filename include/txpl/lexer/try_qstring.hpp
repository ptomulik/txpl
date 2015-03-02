// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/try_qstring.hpp

/** // doc: txpl/lexer/try_qstring.hpp {{{
 * \file txpl/lexer/try_qstring.hpp
 * \brief Implements \ref txpl::lexer::try_qstring() "lexer::try_qstring()"
 */ // }}}
#ifndef TXPL_LEXER_TRY_QSTRING_HPP_INCLUDED
#define TXPL_LEXER_TRY_QSTRING_HPP_INCLUDED

#include <txpl/lexer/try_char.hpp>
#include <iterator>

namespace txpl { namespace lexer {
/** // doc: try_qstring {{{
 * \ingroup LexerGroup
 * \brief Scan for a double-quoted string
 *
 * \param first   iterator pointing to the first character of the input to be
 *                scanned,
 * \param last    iterator pointing one after the last input character allowed
 *                to be scanned,
 * \returns `true` on success of `false` otherwise
 *
 * \par Description
 *
 * The function implements lexer rule \ref ExpressionSyntaxLexerRules "qstring"
 * without semantic value retrieval.
 *
 * This function scans the content between iterators \e first and \e last
 * trying to recognize a double-quoted string. It automatically handles
 * all the supported escape sequences in the stirng. On success, the iterator
 * \e first is moved to the next position after the last scanned input
 * character. On error, the iterator \e first is moved to the character at
 * which the error has been detected and the function returns `false`.
 *
 * \note This operation may leave un-scanned input characters and still be
 *       successful, that is it is possible that ``first != last`` at exit
 *       while the function returns `true`.
 */ // }}}
template<typename Iterator>
bool try_qstring(Iterator& first, Iterator const& last)
{
  typedef typename std::iterator_traits<Iterator>::value_type CharT;

  if(first == last)         return false;
  if(*first != CharT{'\"'}) return false;
  if(++first == last)       return false;
  while(*first != CharT{'\"'})
    {
      if(!try_char(first, last))  return false;
      if(first == last)           return false;
    }
  ++first;
  return true;
}
} } // end namespace txpl::lexer

#endif /* TXPL_LEXER_TRY_QSTRING_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
