// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/get_char.hpp

/** // doc: txpl/lexer/get_char.hpp {{{
 * \file txpl/lexer/get_char.hpp
 * \brief Implements \ref txpl::lexer::get_char() "lexer::get_char()"
 */ // }}}
#ifndef TXPL_LEXER_GET_CHAR_HPP_INCLUDED
#define TXPL_LEXER_GET_CHAR_HPP_INCLUDED

#include <txpl/lexer/get_oct_number.hpp>
#include <txpl/lexer/get_hex_number.hpp>
#include <txpl/lexer/recognize_printable.hpp>
#include <iterator>
#include <type_traits>

namespace txpl { namespace lexer {
/** // doc: get_char() {{{
 * \ingroup LexerGroup
 * \brief Get content of a single character
 *
 * \param first   iterator pointing to the first character of the input to be
 *                scanned,
 * \param last    iterator pointing one after the last input character allowed
 *                to be scanned,
 * \param result  where the decoded character should be stored,
 * \param f       error handler.
 * \returns `true` on success of `false` otherwise
 *
 * \par Description
 *
 * The function implements lexer rule \ref ExpressionSyntaxLexerRules "char"
 * with semantic value retrieval.
 *
 * This function scans the content between iterators \e first and \e last
 * trying to decode a single character. It automatically handles all the
 * supported escape sequences. On success, the iterator \e first is
 * moved to the next position after the last scanned input character, the
 * decoded character gets stored to \e result and the function returns `true`.
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
 * \note This operation may leave un-scanned input characters and still be
 *       successful, that is it is possible that ``first != last`` at exit
 *       while the function returns `true`.
 */ // }}}
template<typename Iterator, typename T, typename Ehandler>
bool get_char(Iterator& first, Iterator const& last, T& result, Ehandler f)
{
  // The TU type is used to avoid some overflow errors from get_oct_number(),
  // and get_hex_number(). For example, if `char' is a signed type on given
  // platform, then `\xFF' would cause an overflow error, whereas the same
  // code would not cause overflows for `unsigned char'.
  typedef typename std::make_unsigned<T>::type TU;
  typedef typename std::iterator_traits<Iterator>::value_type CharT;
  if(first == last)
    {
      f(first, last, "expected character specification");
      return false;
    }
  if(*first != '\\')
    {
      if(!recognize_printable(*first))
        {
          f(first, last, "non-printable character in character specification");
          return false;
        }
      result = static_cast<T>(*first++);
      return true;
    }
  ++first;
  if(first == last)
    {
      f(first, last, "incomplete escape sequence");
      return false;
    }

  if(recognize_oct_digit(*first))
    {
      TU x;
      if(!get_oct_number(first, last, x, f)) return false;
      result = static_cast<T>(x);
      return true;
    }
  else if(*first == 'x' || *first == 'X')
    {
      ++first;
      if(first == last)
        {
          f(first, last, "incomplete escape sequence");
          return false;
        }
      TU x;
      if(!get_hex_number(first, last, x, f)) return false;
      result = static_cast<T>(x);
      return true;
    }
  else
    {
      switch(*first)
        {
          case CharT{'\"'}:  result = T{'\"'}; break;
          case CharT{'\''}:  result = T{'\''}; break;
          case CharT{'\?'}:  result = T{'\?'}; break;
          case CharT{'\\'}:  result = T{'\\'}; break;
          case CharT{'a'}:   result = T{'\a'}; break;
          case CharT{'b'}:   result = T{'\b'}; break;
          case CharT{'f'}:   result = T{'\f'}; break;
          case CharT{'n'}:   result = T{'\n'}; break;
          case CharT{'r'}:   result = T{'\r'}; break;
          case CharT{'t'}:   result = T{'\t'}; break;
          case CharT{'v'}:   result = T{'\v'}; break;
          default:
            f(first, last, "invalid escape sequence");
            return false;
        }
      ++first;
      return true;
    }
}
} } // end namespace txpl::lexer

#endif /* TXPL_LEXER_GET_CHAR_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
