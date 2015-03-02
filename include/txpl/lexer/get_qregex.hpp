// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/get_qregex.hpp

/** // doc: txpl/lexer/get_qregex.hpp {{{
 * \file txpl/lexer/get_qregex.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_LEXER_GET_QREGEX_HPP_INCLUDED
#define TXPL_LEXER_GET_QREGEX_HPP_INCLUDED

#include <txpl/lexer/get_regex_char.hpp>
#include <regex>
#include <iterator>

namespace txpl { namespace lexer {
/** // doc: get_qregex() {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename T, typename Ehandler>
bool get_qregex(Iterator& first, Iterator const& last, T& result, Ehandler f)
{
  typedef typename std::iterator_traits<Iterator>::value_type CharT;
  typedef typename T::string_type String;
  typedef typename T::flag_type Flag;
  typedef typename String::value_type C;

  if(first == last)
    {
      f(first, last, "expected regex-type specifier");
      return false;
    }
  Flag o = std::regex_constants::ECMAScript;
  switch(*first)
    {
      case CharT{'r'}: o = std::regex_constants::ECMAScript;  break;
      case CharT{'b'}: o = std::regex_constants::basic;       break;
      case CharT{'x'}: o = std::regex_constants::extended;    break;
      case CharT{'a'}: o = std::regex_constants::awk;         break;
      case CharT{'g'}: o = std::regex_constants::grep;        break;
      case CharT{'e'}: o = std::regex_constants::egrep;       break;
      default:
        f(first, last, "expected regex-type specifier");
        return false;
    }
  ++first;
  if(first == last)
    {
      f(first, last, "expected opening double-quote");
      return false;
    }
  if(*first != CharT{'\"'})
    {
      f(first, last, "expected opening double-quote");
      return false;
    }
  ++first;
  if(first == last)
    {
      f(first, last, "incomplete regex string");
      return false;
    }
  String s;
  while(*first != CharT{'\"'})
    {
      C c;
      if(!get_regex_char(first, last, c, f))
        return false;
      if(first == last)
        {
          f(first, last, "expected closing double-quote");
          return false;
        }
      s.push_back(c);
    }
  ++first;
  for(size_t n=0; n < 2 && first != last; ++n)
    {
      switch(*first)
        {
          case CharT{'i'}:
            if(!(o & std::regex_constants::icase))
              {
                o |= std::regex_constants::icase;
                ++first;
              }
            else
              n = 2;
            break;
          case CharT{'c'}:
            if(!(o & std::regex_constants::collate))
              {
                o |= std::regex_constants::collate;
                ++first;
              }
            else
              n = 2;
            break;
          default:
            n = 2;
            break;
        }
    }
  try {
    // The static_cast<T const&>() is a workaround for a std::regex bug in
    // libstc++ (gcc 4.9.2). For more details see: 
    //      https://gcc.gnu.org/ml/libstdc++/2015-02/msg00042.html
    result = static_cast<T const&>(T(s,o));
  } catch(std::regex_error const& e) {
    f(first, last, e.what());
    return false;
  }
  return true;
}
} } // end namespace txpl::lexer

#endif /* TXPL_LEXER_GET_QREGEX_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
