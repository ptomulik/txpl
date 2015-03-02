// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/get_int.hpp

/** // doc: txpl/lexer/get_int.hpp {{{
 * \file txpl/lexer/get_int.hpp
 * \brief Implements \ref txpl::lexer::get_int() "lexer::get_int()"
 */ // }}}
#ifndef TXPL_LEXER_GET_INT_HPP_INCLUDED
#define TXPL_LEXER_GET_INT_HPP_INCLUDED

#include <txpl/lexer/get_oct_number.hpp>
#include <txpl/lexer/get_dec_number.hpp>
#include <txpl/lexer/get_hex_number.hpp>
#include <iterator>

namespace txpl { namespace lexer {
/** // doc: get_int() {{{
 * \ingroup LexerGroup
 * \brief Scan input for an integer number
 *
 * \param first   iterator pointing to the first character of the input to be
 *                scanned,
 * \param last    iterator pointing one after the last input character allowed
 *                to be scanned,
 * \param result  where the decoded number should be stored, a mutable
 *                reference to integer variable,
 * \param f       error handler.
 * \returns `true` on success of `false` otherwise
 *
 * \par Description
 *
 * The function implements lexer rule \ref ExpressionSyntaxLexerRules
 * "int" with semantic value retrieval.
 *
 * This function scans the content between iterators \e first and \e last
 * trying to decode an integer number. On success, the iterator \e first is
 * moved to the next position after the last scanned input character, the
 * decoded number gets stored to \e result and the function returns `true`.
 * On error, the iterator \e first is moved to the character at which the error
 * has been detected, the error handler \e f gets invoked and the function
 * returns `false`. The error handler \e f is invoked as follows:
 *
 * \code
 *  f(it, last, msg)
 * \endcode
 *
 * with
 *
 *  - \e it being an iterator pointing to the erroneous character,
 *  - \e last being same as the \e last iterator provided to
 *       \ref txpl::lexer::get_char() "lexer::get_char()"
 *  - \e msg being a null-terminated C string with an error message.
 *
 * \note This function must scan all the characters between \e first and \e
 *       last to be successful.
 */ // }}}
template<typename Iterator, typename T, typename Ehandler>
bool get_int(Iterator& first, Iterator const& last, T& result, Ehandler f)
{
  typedef typename std::iterator_traits<Iterator>::value_type CharT;
  if(first == last)
    {
      f(first, last, "decimal digit expected");
      return false;
    }
  if(*first == CharT{'0'})
    {
      ++first;
      if(first == last)
        {
          result = T{0};
          return true;
        }
      if(*first == 'x' || *first == 'X')
        return get_hex_number(++first, last, result, f);
      else
        return get_oct_number(first, last, result, f);
    }
  else
    return get_dec_number(first, last, result, f);
}
} } // end namespace txpl::lexer

#endif /* TXPL_LEXER_GET_INT_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
