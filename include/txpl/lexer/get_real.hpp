// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/get_real.hpp

/** // doc: txpl/lexer/get_real.hpp {{{
 * \file txpl/lexer/get_real.hpp
 * \brief Implements \ref txpl::lexer::get_real() "lexer::get_real()"
 */ // }}}
#ifndef TXPL_LEXER_GET_REAL_HPP_INCLUDED
#define TXPL_LEXER_GET_REAL_HPP_INCLUDED

#include <iterator>
#include <string>
#include <stdexcept>

namespace txpl { namespace lexer {
/** // doc: stor_impl {{{
 * \todo Write documentation
 */ // }}}
template<typename T>
struct stor_impl;
/** // doc: stor_impl {{{
 * \todo Write documentation
 */ // }}}
template<>
struct stor_impl<float>
{
  template<typename String>
  static float
  apply(String const& s, std::size_t* pos)
  { return std::stof(s,pos); }
};
/** // doc: stor_impl {{{
 * \todo Write documentation
 */ // }}}
template<>
struct stor_impl<double>
{
  template<typename String>
  static double
  apply(String const& s, std::size_t* pos)
  { return std::stod(s,pos); }
};
/** // doc: stor() {{{
 * \todo Write documentation
 */ // }}}
template<typename T, typename String>
T stor(String const& s, std::size_t* pos = nullptr)
{
  return stor_impl<T>::apply(s, pos);
}
/** // doc: get_real() {{{
 * \ingroup LexerGroup
 * \brief Scan input for a real number
 *
 * \param first   iterator pointing to the first character of the input to be
 *                scanned,
 * \param last    iterator pointing one after the last input character allowed
 *                to be scanned,
 * \param result  where the decoded number should be stored, a mutable
 *                reference to floating-point variable,
 * \param f       error handler.
 * \returns `true` on success of `false` otherwise
 *
 * \par Description
 *
 * The function implements lexer rule \ref ExpressionSyntaxLexerRules
 * "real" with semantic value retrieval.
 *
 * This function scans the content between iterators \e first and \e last
 * trying to decode a real number. On success, the iterator \e first is
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
bool get_real(Iterator& first, Iterator const& last, T& result, Ehandler f)
{
  // As you see I wasn't too apt to implement my own float-number parser.
  // This would take too much of my time and would result with buggy and
  // error-prone parser. The downside is that the current implementation does
  // not set the "first" iterator very preciselly in case of errors. The other
  // downside is speed -- this version requires string allocation, whereas my
  // own would operate on iterators, without dynamic memory allocation.
  typedef typename std::iterator_traits<Iterator>::value_type CharT;
  typedef std::basic_string<CharT> String;
  if(first == last)
    {
      f(first, last, "real number expected");
      return false;
    }
  std::size_t n = 0;
  String s(first, last);
  double d;
  try {
    d = stor<T>(s, &n);
  } catch(std::invalid_argument const&) {
    f(first, last, "real number expected");
    return false;
  } catch(std::out_of_range const&) {
    f(first, last, "real constant out of range for the given data type");
    return false;
  }
  std::advance(first, n);
  result = d;
  return true;
}
} } // end namespace txpl::lexer

#endif /* TXPL_LEXER_GET_REAL_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
