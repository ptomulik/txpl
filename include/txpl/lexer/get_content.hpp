// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/get_content.hpp

/** // doc: txpl/lexer/get_content.hpp {{{
 * \file txpl/lexer/get_content.hpp
 * \brief Implements \ref txpl::lexer::get_content() "lexer::get_content()"
 */ // }}}
#ifndef TXPL_LEXER_GET_CONTENT_HPP_INCLUDED
#define TXPL_LEXER_GET_CONTENT_HPP_INCLUDED

#include <iterator>

namespace txpl { namespace lexer {
/** // doc: get_content() {{{
 * \ingroup LexerGroup
 * \brief Retrieves content of the input between two iterators
 *
 * \param first   iterator pointing to the first character of the input to be
 *                scanned,
 * \param last    iterator pointing one after the last input character allowed
 *                to be scanned,
 * \param result  where the retrieved content should be stored, a mutable
 *                reference to a string,
 * \param f       error handler.
 * \returns `true`
 *
 * \par Description
 *
 * This function copies verbatim the content between iterators \e first and \e
 * last to the \e result and returns `true`. After the operation \e first is
 * moved to the position pointed by \e last, i.e. ``first == last`` at exit.
 */ // }}}
template<typename Iterator, typename T, typename Ehandler>
bool get_content(Iterator& first, Iterator const& last, T& result, Ehandler)
{
  result = T(first, last);
  first = last;
  return true;
}
} } // end namespace txpl::lexer

#endif /* TXPL_LEXER_GET_CONTENT_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
