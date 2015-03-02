// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/try_dec_number.hpp

/** // doc: txpl/lexer/try_dec_number.hpp {{{
 * \file txpl/lexer/try_dec_number.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_LEXER_TRY_DEC_NUMBER_HPP_INCLUDED
#define TXPL_LEXER_TRY_DEC_NUMBER_HPP_INCLUDED

#include <txpl/lexer/try_dec_digit.hpp>

namespace txpl { namespace lexer {
/** // doc: try_dec_number() {{{
 * \todo Write documentation
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
