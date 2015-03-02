// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/try_dec_number.hpp

/** // doc: txpl/lexer/try_dec_number.hpp {{{
 * \file txpl/lexer/try_dec_number.hpp
 * \brief Implements \ref txpl::lexer::get_dec_number() "lexer::get_dec_number()"
 */ // }}}
#ifndef TXPL_LEXER_TRY_DEC_NUMBER_HPP_INCLUDED
#define TXPL_LEXER_TRY_DEC_NUMBER_HPP_INCLUDED

#include <txpl/lexer/try_dec_digit.hpp>

namespace txpl { namespace lexer {
/** // doc: try_dec_number() {{{
 * \ingroup LexerGroup
 * \brief Scan for a decimal number
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
 * "dec-number" without semantic value retrieval.
 *
 * This function scans the content between iterators \e first and \e last
 * trying to recognize a decimal number. On success, the iterator \e first is
 * moved to the next position after the last scanned input character.
 * On error, the iterator \e first is moved to the character at which the error
 * has been detected and the function returns `false`.
 *
 * \note This operation may leave un-scanned input characters and still be
 *       successful, that is it is possible that ``first != last`` at exit
 *       while the function returns `true`.
 */ // }}}
template<typename Iterator>
bool try_dec_number(Iterator& first, Iterator const& last)
{
  if(!try_dec_digit(first, last)) return false;
  while(try_dec_digit(first, last)) {}
  return true;
}
} } // end namespace txpl::lexer

#endif /* TXPL_LEXER_TRY_DEC_NUMBER_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
