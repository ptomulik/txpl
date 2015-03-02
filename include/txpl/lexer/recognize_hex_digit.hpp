// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/recognize_hex_digit.hpp

/** // doc: txpl/lexer/recognize_hex_digit.hpp {{{
 * \file txpl/lexer/recognize_hex_digit.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_LEXER_RECOGNIZE_HEX_DIGIT_HPP
#define TXPL_LEXER_RECOGNIZE_HEX_DIGIT_HPP

namespace txpl { namespace lexer {
/** // doc: recognize_hex_digit() {{{
 * \todo Write documentation
 */ // }}}
template<typename CharT>
constexpr int
recognize_hex_digit(CharT c) noexcept
{
  return (c >= CharT{'0'} && c <= CharT{'9'}) ? int{'0'} :
         ( (c >= CharT{'a'} && c <= CharT{'f'}) ? (int{'a'} - 0xA) :
           ( (c >= CharT{'A'} && c <= CharT{'F'}) ? (int{'A'} - 0xA) : 0) );
}
} } // end namespace txpl::lexer

#endif /* TXPL_LEXER_RECOGNIZE_HEX_DIGIT_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
