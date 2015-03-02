// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/try_hex_digit.hpp

/** // doc: txpl/lexer/try_hex_digit.hpp {{{
 * \file txpl/lexer/try_hex_digit.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_LEXER_TRY_HEX_DIGIT_HPP_INCLUDED
#define TXPL_LEXER_TRY_HEX_DIGIT_HPP_INCLUDED

#include <txpl/lexer/recognize_hex_digit.hpp>

namespace txpl { namespace lexer {
/** // doc: try_hex_digit() {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator>
bool try_hex_digit(Iterator& first, Iterator const& last)
{
  if(first == last)                return false;
  if(!recognize_hex_digit(*first)) return false;
  ++first;
  return true;
}
} } // end namespace txpl::lexer

#endif /* TXPL_LEXER_TRY_HEX_DIGIT_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
