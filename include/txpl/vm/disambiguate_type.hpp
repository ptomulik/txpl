// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/disambiguate_type.hpp

/** // doc: txpl/vm/disambiguate_type.hpp {{{
 * \file txpl/vm/disambiguate_type.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_VM_DISAMBIGUATE_TYPE_HPP_INCLUDED
#define TXPL_VM_DISAMBIGUATE_TYPE_HPP_INCLUDED

#include <tml/if.hpp>
#include <tml/or.hpp>
#include <tml/bool.hpp>
#include <tml/identity.hpp>
#include <cwchar>
#include <type_traits>

namespace txpl { namespace vm {
/** // doc: disambiguate_type<...> {{{
 * \todo Write documentation
 */ // }}}
template<typename BasicTypes, typename T>
struct disambiguate_type
  : tml::if_<
      typename tml::or_<
        tml::bool_<std::is_same<T,char>::value>
      , tml::bool_<std::is_same<T,wchar_t>::value>
      >::type
    , tml::identity<typename BasicTypes::char_type> 
    , typename tml::if_<
        tml::bool_<std::is_same<T,bool>::value>
      , tml::identity<typename BasicTypes::bool_type>
      , typename tml::if_<
          tml::bool_<std::is_integral<T>::value>
        , tml::identity<typename BasicTypes::int_type>
        , typename tml::if_<
            tml::bool_<std::is_floating_point<T>::value>
          , tml::identity<typename BasicTypes::real_type>
          , tml::identity<T>
          >::type
        >::type
      >::type
    >::type
{};
/** // doc: disambiguate_type<char_type> {{{
 * \todo Write documentation
 */ // }}}
template<typename BasicTypes>
struct disambiguate_type<typename BasicTypes::char_type, BasicTypes>
  : tml::identity<typename BasicTypes::char_type>
{};
/** // doc: disambiguate_type<int_type> {{{
 * \todo Write documentation
 */ // }}}
template<typename BasicTypes>
struct disambiguate_type<typename BasicTypes::int_type, BasicTypes>
  : tml::identity<typename BasicTypes::int_type>
{};
/** // doc: disambiguate_type<bool_type> {{{
 * \todo Write documentation
 */ // }}}
template<typename BasicTypes>
struct disambiguate_type<typename BasicTypes::bool_type, BasicTypes>
  : tml::identity<typename BasicTypes::bool_type>
{};
/** // doc: disambiguate_type<real_type> {{{
 * \todo Write documentation
 */ // }}}
template<typename BasicTypes>
struct disambiguate_type<typename BasicTypes::real_type, BasicTypes>
  : tml::identity<typename BasicTypes::real_type>
{};
/** // doc: disambiguate_type<string_type> {{{
 * \todo Write documentation
 */ // }}}
template<typename BasicTypes>
struct disambiguate_type<typename BasicTypes::string_type, BasicTypes>
  : tml::identity<typename BasicTypes::string_type>
{};
/** // doc: disambiguate_type<regex_type> {{{
 * \todo Write documentation
 */ // }}}
template<typename BasicTypes>
struct disambiguate_type<typename BasicTypes::regex_type, BasicTypes>
  : tml::identity<typename BasicTypes::regex_type>
{};
} } // end namespace txpl::vm

#endif /* TXPL_VM_DISAMBIGUATE_TYPE_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
