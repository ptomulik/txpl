// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/unit.hpp

/** // doc: txpl/unit.hpp {{{
 * \file txpl/unit.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_VM_BASIC_TYPES_HPP
#define TXPL_VM_BASIC_TYPES_HPP

#include <boost/blank.hpp>
#include <string>
#include <regex>

namespace txpl { namespace vm {
/** // doc: basic_types {{{
 * \todo Write documentation
 */ // }}}
template< typename Char = char
        , typename Int = long
        , typename Bool = bool
        , typename Real = double
        , typename String = std::basic_string<Char>
        , typename Regex = std::basic_regex<Char>
        , typename Blank = boost::blank>
struct basic_types
{
  /** // doc: char_type {{{
   * \todo Write documentation
   */ // }}}
  typedef Char    char_type;
  /** // doc: int_type {{{
   * \todo Write documentation
   */ // }}}
  typedef Int     int_type;
  /** // doc: bool_type {{{
   * \todo Write documentation
   */ // }}}
  typedef Bool    bool_type;
  /** // doc: real_type {{{
   * \todo Write documentation
   */ // }}}
  typedef Real    real_type;
  /** // doc: string_type {{{
   * \todo Write documentation
   */ // }}}
  typedef String  string_type;
  /** // doc: regex_type {{{
   * \todo Write documentation
   */ // }}}
  typedef Regex   regex_type;
  /** // doc: blank_type {{{
   * \todo Write documentation
   */ // }}}
  typedef Blank   blank_type;
};
} } // end namespace txpl::vm

#endif /* TXPL_VM_BASIC_TYPES_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
