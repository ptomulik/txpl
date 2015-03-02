// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/try_int.hpp

/** // doc: txpl/lexer/try_int.hpp {{{
 * \file txpl/lexer/try_int.hpp
 * \brief Implements \ref txpl::lexer::try_int() "lexer::try_int()"
 */ // }}}
#ifndef TXPL_LEXER_TRY_INT_HPP_INCLUDED
#define TXPL_LEXER_TRY_INT_HPP_INCLUDED

#include <txpl/lexer/try_oct_number.hpp>
#include <txpl/lexer/try_dec_number.hpp>
#include <txpl/lexer/try_hex_number.hpp>
#include <iterator>

namespace txpl { namespace lexer {
/** // doc: try_int {{{
 * \ingroup LexerGroup
 * \brief Scan for an integer number
 *
 * \param first   iterator pointing to the first character of the input to be
 *                scanned,
 * \param last    iterator pointing one after the last input character allowed
 *                to be scanned,
 * \returns `true` on success of `false` otherwise
 *
 * \par Description
 *
 * The function implements lexer rule \ref ExpressionSyntaxLexerRules
 * "int" without semantic value retrieval.
 *
 * This function scans the content between iterators \e first and \e last
 * trying to recognize an integer number. On success, the iterator \e first is
 * moved to the next position after the last scanned input character.
 * On error, the iterator \e first is moved to the character at which the error
 * has been detected and the function returns `false`.
 *
 * \note This operation may leave un-scanned input characters and still be
 *       successful, that is it is possible that ``first != last`` at exit
 *       while the function returns `true`.
 */ // }}}
template<typename Iterator>
bool try_int(Iterator& first, Iterator const& last)
{
  typedef typename std::iterator_traits<Iterator>::value_type CharT;
  if(first == last) return false;
  if(*first == CharT{'0'})
    {
      ++first;
      if(first == last)                   return true;
      if(*first == CharT{'x'} || *first == CharT{'X'})
        return try_hex_number(++first, last);
      // We already have an octal value of '0', so we always return true.
      // The try_oct_number() is invoked only to scan for rest of number,
      // that is to move the 'first' iterator to proper position.
      try_oct_number(first, last);
      return true;
    }
  else
    return try_dec_number(first, last);
}
} } // end namespace txpl::lexer

#endif /* TXPL_LEXER_TRY_INT_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
