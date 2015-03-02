// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/get_hex_digit.hpp

/** // doc: txpl/lexer/get_hex_digit.hpp {{{
 * \file txpl/lexer/get_hex_digit.hpp
 * \brief Implements \ref txpl::lexer::get_hex_digit() "lexer::get_hex_digit()"
 */ // }}}
#ifndef TXPL_LEXER_GET_HEX_DIGIT_HPP_INCLUDED
#define TXPL_LEXER_GET_HEX_DIGIT_HPP_INCLUDED

#include <txpl/lexer/recognize_hex_digit.hpp>

namespace txpl { namespace lexer {
/** // doc: get_hex_digit() {{{
 * \ingroup LexerGroup
 * \brief Retrieves a hexadecimal digit from input
 *
 * \param c input character
 * \param result where to store the resultant digit, a mutable reference to
 *        integer variable.
 * \returns `true` on success or `false` otherwise
 *
 * \par Description
 *
 * If \e c is a valid hexadecimal digit, that is a character matching 
 * ``[0-9a-fA-F]``, then it gets converted to appropriate integer value and
 * stored in \e result. Otherwise, the \e result remains untouched and the
 * function returns `false`.
 */ // }}}
template<typename CharT, typename T>
bool get_hex_digit(CharT c, T& result)
{
  int b = recognize_hex_digit(c);
  if(b == 0) return false;
  result = static_cast<T>(c - b);
  return true;
}
} } // end namespace txpl::lexer

#endif /* TXPL_LEXER_GET_HEX_DIGIT_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
