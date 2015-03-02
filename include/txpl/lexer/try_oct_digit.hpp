// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/try_oct_digit.hpp

/** // doc: txpl/lexer/try_oct_digit.hpp {{{
 * \file txpl/lexer/try_oct_digit.hpp
 * \brief Implements \ref txpl::lexer::try_oct_digit() "lexer::try_oct_digit()"
 */ // }}}
#ifndef TXPL_LEXER_TRY_OCT_DIGIT_HPP_INCLUDED
#define TXPL_LEXER_TRY_OCT_DIGIT_HPP_INCLUDED

#include <txpl/lexer/recognize_oct_digit.hpp>

namespace txpl { namespace lexer {
/** // doc: try_oct_digit() {{{
 * \ingroup LexerGroup
 * \brief Scan for an octal digit
 *
 * \param first   iterator pointing to the first character of the input to be
 *                scanned,
 * \param last    iterator pointing one after the last input character allowed
 *                to be scanned,
 * \returns `true` on success of `false` otherwise
 *
 * \par Description
 *
 * This function scans single character at the position indicated by \e first
 * trying to recognize a single octal digit. On success, the iterator
 * \e first is incremented and the function returns `true`. On error, the
 * iterator \e first is left at original position and the function returns
 * `false`.
 *
 * \note This operation may leave un-scanned input characters and still be
 *       successful, that is it is possible that ``first != last`` at exit
 *       while the function returns `true`.
 */ // }}}
template<typename Iterator>
bool try_oct_digit(Iterator& first, Iterator const& last)
{
  if(first == last)                return false;
  if(!recognize_oct_digit(*first)) return false;
  ++first;
  return true;
}
} } // end namespace txpl::lexer

#endif /* TXPL_LEXER_TRY_OCT_DIGIT_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
