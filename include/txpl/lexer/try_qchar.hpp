// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/try_qchar.hpp

/** // doc: txpl/lexer/try_qchar.hpp {{{
 * \file txpl/lexer/try_qchar.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_LEXER_TRY_QCHAR_HPP_INCLUDED
#define TXPL_LEXER_TRY_QCHAR_HPP_INCLUDED

#include <txpl/lexer/try_char.hpp>
#include <iterator>

namespace txpl { namespace lexer {
/** // doc: try_qchar {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator>
bool try_qchar(Iterator& first, Iterator const& last)
{
  typedef typename std::iterator_traits<Iterator>::value_type CharT;
  if(first == last)           return false;
  if(*first != CharT{'\''})   return false;
  if(++first == last)         return false;
  if(*first == CharT{'\''})   return false; // empty char not allowed...
  if(!try_char(first, last))  return false;
  if(first == last)           return false;
  if(*first != CharT{'\''})   return false;
  ++first;
  return true;
}
} } // end namespace txpl::lexer

#endif /* TXPL_LEXER_TRY_QCHAR_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
