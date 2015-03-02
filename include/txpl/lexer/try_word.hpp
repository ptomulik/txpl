// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/try_word.hpp

/** // doc: txpl/lexer/try_word.hpp {{{
 * \file txpl/lexer/try_word.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_LEXER_TRY_WORD_HPP_INCLUDED
#define TXPL_LEXER_TRY_WORD_HPP_INCLUDED

#include <txpl/lexer/try_word_char.hpp>

namespace txpl { namespace lexer {
/** // doc: try_word() {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator>
bool try_word(Iterator& first, Iterator const& last)
{
  if(!try_word_char0(first, last)) return false;
  while(try_word_char(first, last)) { }
  return true;
}
} } // end namespace txpl::lexer

#endif /* TXPL_LEXER_TRY_WORD_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
