// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/ast/value.hpp

/** // doc: txpl/ast/value.hpp {{{
 * \file txpl/ast/value.hpp
 * \brief Defines \ref txpl::ast::value "ast::value<>"
 */ // }}}
#ifndef TXPL_AST_VALUE_HPP
#define TXPL_AST_VALUE_HPP

#include <txpl/ast/basic_types.hpp>
#include <boost/variant/variant.hpp>

namespace txpl { namespace ast {
/** // doc: value {{{
 * \todo Write documenation
 */ // }}}
template<typename BasicTypes = basic_types<> >
using value = boost::variant<
      typename BasicTypes::blank_type
    , typename BasicTypes::char_type
    , typename BasicTypes::int_type
    , typename BasicTypes::bool_type
    , typename BasicTypes::real_type
    , typename BasicTypes::string_type
    , typename BasicTypes::regex_type
>;
} } // end namespace txpl::ast

#include <txpl/ast/value_traits.hpp>
namespace txpl { namespace ast {
/** // doc: value_traits {{{
 * \todo Write documenation
 */ // }}}
template<
    typename Blank
  , typename Char
  , typename Int
  , typename Bool
  , typename Real
  , typename String
  , typename Regex
  >
struct value_traits<boost::variant<Blank, Char, Int, Bool, Real, String, Regex> >
{
  /** // doc: blank_type {{{
   * \todo Write documentation
   */ // }}}
  typedef Blank blank_type;
  /** // doc: blank_type {{{
   * \todo Write documentation
   */ // }}}
  typedef Char char_type;
  /** // doc: blank_type {{{
   * \todo Write documentation
   */ // }}}
  typedef Int int_type;
  /** // doc: blank_type {{{
   * \todo Write documentation
   */ // }}}
  typedef Bool bool_type;
  /** // doc: blank_type {{{
   * \todo Write documentation
   */ // }}}
  typedef Real real_type;
  /** // doc: blank_type {{{
   * \todo Write documentation
   */ // }}}
  typedef String string_type;
  /** // doc: blank_type {{{
   * \todo Write documentation
   */ // }}}
  typedef Regex regex_type;
};
} } // end namespace txpl::ast


#endif /* TXPL_AST_VALUE_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
