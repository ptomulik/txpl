// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/basic_types.hpp

/** // doc: txpl/vm/basic_types.hpp {{{
 * \file txpl/vm/basic_types.hpp
 * \brief Defines the \ref txpl::vm::basic_types "vm::basic_types" template
 */ // }}}
#ifndef TXPL_VM_BASIC_TYPES_HPP
#define TXPL_VM_BASIC_TYPES_HPP

#include <boost/blank.hpp>
#include <string>
#include <regex>

namespace txpl { namespace vm {
/** // doc: basic_types {{{
 * \ingroup VmGroup
 * \brief \ref BasicTypesDefinerConcept for the \ref VmGroup "virtual machine's"
 *        type system
 *
 * \tparam Char   type used to represent characters,
 * \tparam Int    type used to represent integers,
 * \tparam Bool   type used to represent booleans,
 * \tparam Real   type used to represent real numbers,
 * \tparam String type used to represent strings,
 * \tparam Regex  type used to represent regular expressions,
 * \tparam Blank  type used to represent uninitialized value.
 *
 * This class is used to define and keep track of the \ref BasicTypesConcept
 * "basic types" used to construct type-system of the
 * \ref VmGroup "virtual machine". The type system is established at compile
 * time and may be customized by passing custom instantiations of the
 * \ref txpl::vm::basic_types "vm::basic_types<>" template as a template
 * argument to \ref txpl::vm::value "vm::value<>" or \ref txpl::ast::value
 * "ast::value<>".
 *
 * <b>Model of</b>:
 *
 * - \ref BasicTypesDefinerConcept.
 *
 * \b Example:
 * \snippet basic_types1.cpp Code
 * \b Output:
 * \snippet basic_types1.cpp Output
 *
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
  /** // doc: blank_type {{{
   * \brief Type used to represent uninitialized value
   */ // }}}
  typedef Blank   blank_type;
  /** // doc: char_type {{{
   * \brief Type used to represent characters
   */ // }}}
  typedef Char    char_type;
  /** // doc: int_type {{{
   * \brief Type used to represent integers
   */ // }}}
  typedef Int     int_type;
  /** // doc: bool_type {{{
   * \brief Type used to represent booleans
   */ // }}}
  typedef Bool    bool_type;
  /** // doc: real_type {{{
   * \brief Type used to represent real numbers
   */ // }}}
  typedef Real    real_type;
  /** // doc: string_type {{{
   * \brief Type used to represent strings
   */ // }}}
  typedef String  string_type;
  /** // doc: regex_type {{{
   * \brief Type used to represent regular expressions
   */ // }}}
  typedef Regex   regex_type;
};
} } // end namespace txpl::vm

#endif /* TXPL_VM_BASIC_TYPES_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
