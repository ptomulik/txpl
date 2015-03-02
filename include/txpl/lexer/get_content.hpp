// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/get_content.hpp

/** // doc: txpl/lexer/get_content.hpp {{{
 * \file txpl/lexer/get_content.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_LEXER_GET_CONTENT_HPP_INCLUDED
#define TXPL_LEXER_GET_CONTENT_HPP_INCLUDED

#include <iterator>

namespace txpl { namespace lexer {
/** // doc: get_content() {{{
 * \todo Write documentation
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
