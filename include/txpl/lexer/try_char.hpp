// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/try_char.hpp

/** // doc: txpl/lexer/try_char.hpp {{{
 * \file txpl/lexer/try_char.hpp
 * \brief Implements \ref txpl::lexer::try_char() "lexer::try_char()"
 */ // }}}
#ifndef TXPL_LEXER_TRY_CHAR_HPP_INCLUDED
#define TXPL_LEXER_TRY_CHAR_HPP_INCLUDED

#include <txpl/lexer/recognize_oct_digit.hpp>
#include <txpl/lexer/recognize_printable.hpp>
#include <txpl/lexer/try_hex_number.hpp>
#include <txpl/lexer/try_oct_number.hpp>
#include <iterator>

namespace txpl { namespace lexer {
/** // doc: try_char() {{{
 * \ingroup LexerGroup
 * \brief Scan for a single character
 *
 * \param first   iterator pointing to the first character of the input to be
 *                scanned,
 * \param last    iterator pointing one after the last input character allowed
 *                to be scanned,
 * \returns `true` on success of `false` otherwise
 *
 * \par Description
 *
 * The function implements lexer rule \ref ExpressionSyntaxLexerRules "char"
 * without semantic value retrieval.
 *
 * This function scans the content between iterators \e first and \e last
 * trying to recognize a single character. It automatically handles all the
 * supported escape sequences. On success, the iterator \e first is
 * moved to the next position after the last scanned input character.
 * On error, the iterator \e first is moved to the character at which the error
 * has been detected and the function returns `false`.
 *
 * \note This operation may leave un-scanned input characters and still be
 *       successful, that is it is possible that ``first != last`` at exit
 *       while the function returns `true`.
 */ // }}}
template<typename Iterator>
bool try_char(Iterator& first, Iterator const& last)
{
  typedef typename std::iterator_traits<Iterator>::value_type CharT;
  if(first == last)                     return false;
  if(*first != CharT{'\\'})
    {
      if(!recognize_printable(*first))  return false;
      ++first;
      return true;
    }
  if(++first == last)                   return false;
  if(recognize_oct_digit(*first) != 0)
    {
      Iterator ahead = first;
      // The following loop has same effect as:
      //  std::advance(ahead, std::min(3, std::distance(first, last)));
      for(size_t n = 3; n>0 && ahead != last; --n, ++ahead) { }
      if(!try_oct_number(first, ahead)) return false;
    }
  else if(*first == 'x' || *first == 'X')
    {
      if((++first) == last)             return false;
      if(!try_hex_number(first, last))  return false;
    }
  else
    {
      switch(*first)
        {
          case CharT{'\"'}:
          case CharT{'\''}:
          case CharT{'\?'}:
          case CharT{'\\'}:
          case CharT{'a'}:
          case CharT{'b'}:
          case CharT{'f'}:
          case CharT{'n'}:
          case CharT{'r'}:
          case CharT{'t'}:
          case CharT{'v'}:
            break;
          default:
            return false;
        }
      ++first;
    }
  return true;
}
} } // end namespace txpl::lexer

#endif /* TXPL_LEXER_TRY_CHAR_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
