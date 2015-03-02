// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/tokenize.hpp

/** // doc: txpl/lexer/tokenize.hpp {{{
 * \file txpl/lexer/tokenize.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_LEXER_TOKENIZE_HPP_INCLUDED
#define TXPL_LEXER_TOKENIZE_HPP_INCLUDED

#include <txpl/lexer/try_token.hpp>
#include <txpl/lexer/token_t.hpp>
#include <txpl/lexer/token.hpp>

namespace txpl { namespace lexer {
/** // doc: tokenize() {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename Tokens>
bool tokenize(Iterator& first, Iterator const& last, Tokens& tokens, bool skipws = true)
{
  Iterator next;
  while(first != last)
    {
      lexer::token_t const tok = lexer::try_token(first, last, next);
      if(tok == lexer::token_t::invalid_) return false;
      if(!skipws || tok != lexer::token_t::spaces_)
        tokens.push_back(lexer::token<Iterator>(tok, first, next));
      first = next;
    }
  return true;
}
} } // end namespace txpl::lexer

#endif /* TXPL_LEXER_TOKENIZE_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
