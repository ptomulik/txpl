// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/try_real.hpp

/** // doc: txpl/lexer/try_real.hpp {{{
 * \file txpl/lexer/try_real.hpp
 * \brief Implements \ref txpl::lexer::try_real() "lexer::try_real()"
 */ // }}}
#ifndef TXPL_LEXER_TRY_REAL_HPP_INCLUDED
#define TXPL_LEXER_TRY_REAL_HPP_INCLUDED

#include <txpl/lexer/try_dec_number.hpp>
#include <iterator>

namespace txpl { namespace lexer {
/** // doc: try_exponent {{{
 * \ingroup LexerGroup
 * \brief Scan for real number's exponent
 *
 * \param first   iterator pointing to the first character of the input to be
 *                scanned,
 * \param last    iterator pointing one after the last input character allowed
 *                to be scanned,
 * \returns `true` on success of `false` otherwise
 *
 * \par Description
 *
 * The function implements lexer rule \ref ExpressionSyntaxLexerRules "exp"
 * without semantic value retrieval.
 *
 * This function scans the content between iterators \e first and \e last
 * trying to recognize a real number's exponent. On success, the iterator \e
 * first is moved to the next position after the last scanned input character.
 * On error, the iterator \e first is moved to the character at which the error
 * has been detected and the function returns `false`.
 *
 * \note This operation may leave un-scanned input characters and still be
 *       successful, that is it is possible that ``first != last`` at exit
 *       while the function returns `true`.
 */ // }}}
template<typename Iterator>
bool try_exponent(Iterator& first, Iterator const& last)
{
  typedef typename std::iterator_traits<Iterator>::value_type CharT;
  if(first == last)                                 return false;
  if(*first != CharT{'e'} && *first != CharT{'E'})  return false;
  if(++first == last)                               return false;
  if(*first == CharT{'-'} || *first == CharT{'+'})  ++first;
  if(!try_dec_number(first, last))                  return false;
  return true;
}
/** // doc: try_real {{{
 * \ingroup LexerGroup
 * \brief Scan for a real number
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
 * "real" without semantic value retrieval.
 *
 * This function scans the content between iterators \e first and \e last
 * trying to recognize a real number. On success, the iterator \e first is
 * moved to the next position after the last scanned input character.
 * On error, the iterator \e first is moved to the character at which the error
 * has been detected and the function returns `false`.
 *
 * \note This operation may leave un-scanned input characters and still be
 *       successful, that is it is possible that ``first != last`` at exit
 *       while the function returns `true`.
 */ // }}}
template<typename Iterator>
bool try_real(Iterator& first, Iterator const& last)
{
  typedef typename std::iterator_traits<Iterator>::value_type CharT;
  if(try_dec_number(first, last))
    {
      if(*first == CharT{'.'})
        try_dec_number(++first, last);
      else
        return try_exponent(first, last);
    }
  else
    {
      if(*first != CharT{'.'})          return false;
      if(!try_dec_number(++first,last)) return false;
    }
  Iterator tmp = first;
  if(try_exponent(first, last))     return true;
  if(tmp != first)                  return false; // exponent has no digits
  return true;
}
} } // end namespace txpl::lexer

#endif /* TXPL_LEXER_TRY_REAL_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
