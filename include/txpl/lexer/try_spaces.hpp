// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/try_spaces.hpp

/** // doc: txpl/lexer/try_spaces.hpp {{{
 * \file txpl/lexer/try_spaces.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_LEXER_TRY_SPACES_HPP_INCLUDED
#define TXPL_LEXER_TRY_SPACES_HPP_INCLUDED

#include <iterator>

namespace txpl { namespace lexer {
/** // doc: try_spaces() {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator>
bool try_spaces(Iterator& first, Iterator const& last)
{
  typedef typename std::iterator_traits<Iterator>::value_type CharT;

  auto isws = [](CharT c) {
    return c == CharT{' '}  || c == CharT{'\t'} || c == CharT{'\n'}
        || c == CharT{'\r'} || c == CharT{'\v'};
  };

  if(first == last) return false;
  if(!isws(*first)) return false;
  for(++first;first != last && isws(*first); ++first) { }
  return true;
}
} } // end namespace txpl::lexer

#endif /* TXPL_LEXER_TRY_SPACES_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
