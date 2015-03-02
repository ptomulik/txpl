// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/try_word_char.hpp

/** // doc: txpl/lexer/try_word_char.hpp {{{
 * \file txpl/lexer/try_word_char.hpp
 * \brief Implements \ref txpl::lexer::try_word_char() "lexer::try_word_char()"
 */ // }}}
#ifndef TXPL_LEXER_TRY_WORD_CHAR_HPP_INCLUDED
#define TXPL_LEXER_TRY_WORD_CHAR_HPP_INCLUDED

#include <txpl/lexer/recognize_alpha.hpp>
#include <txpl/lexer/recognize_alnum.hpp>

namespace txpl { namespace lexer {
/** // doc: try_word_char() {{{
 * \ingroup LexerGroup
 * \brief Scans for a first character in a \ref ExpressionSyntaxLexerRules "word"
 */ // }}}
template<typename Iterator>
bool try_word_char0(Iterator& first, Iterator const& last)
{
  if(first == last)                             return false;
  if(!recognize_alpha(*first) && *first != '_') return false;
  ++first;
  return true;
}
/** // doc: try_word_char() {{{
 * \brief Scans for a non-first character in a \ref ExpressionSyntaxLexerRules "word"
 */ // }}}
template<typename Iterator>
bool try_word_char(Iterator& first, Iterator const& last)
{
  if(first == last)                             return false;
  if(!recognize_alnum(*first) && *first != '_') return false;
  ++first;
  return true;
}
} } // end namespace txpl::lexer

#endif /* TXPL_LEXER_TRY_WORD_CHAR_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
