// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/get_oct_digit.hpp

/** // doc: txpl/lexer/get_oct_digit.hpp {{{
 * \file txpl/lexer/get_oct_digit.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_LEXER_GET_OCT_DIGIT_HPP_INCLUDED
#define TXPL_LEXER_GET_OCT_DIGIT_HPP_INCLUDED

#include <txpl/lexer/recognize_oct_digit.hpp>

namespace txpl { namespace lexer {
/** // doc: get_oct_digit() {{{
 * \todo Write documentation
 */ // }}}
template<typename CharT, typename T>
bool get_oct_digit(CharT c, T& result)
{
  const int b = recognize_oct_digit(c);
  if(b == 0) return false;
  result = static_cast<T>(c - b);
  return true;
}
} } // end namespace txpl::lexer

#endif /* TXPL_LEXER_GET_OCT_DIGIT_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
