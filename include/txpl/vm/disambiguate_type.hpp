// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/disambiguate_type.hpp

/** // doc: txpl/vm/disambiguate_type.hpp {{{
 * \file txpl/vm/disambiguate_type.hpp
 * \brief Defines the \ref txpl::vm::disambiguate_type "vm::disambiguate_type<>"
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
 * \ingroup VmGroup
 * \brief Determines to what \ref BasicTypeConcept "basic type" should be a C++
 *        type converted when disambiguating
 *
 * \tparam BasicTypes \ref BasicTypesDefinerConcept for the destination type
 *         system,
 * \tparam T C++ type at input, must be explicitly convertible to one of the
 *         basic types defined by \e BasicTypes.
 *
 * Given a set of \ref BasicTypesDefiner "basic types" defined by \e BasicTypes
 * and an input type \e T, the meta-function determines what destination
 * \ref BasicTypesConcept "basic type" should be chosen for values of type
 * \e T when storing C++ values in \ref txpl::vm::value "vm::value<>".
 * This meta-function is used as a helper by the
 * \ref txpl::vm::disambiguate() "vm::disambiguate()" to determine its return
 * type.
 *
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
struct disambiguate_type<BasicTypes, typename BasicTypes::char_type>
  : tml::identity<typename BasicTypes::char_type>
{};
/** // doc: disambiguate_type<int_type> {{{
 * \todo Write documentation
 */ // }}}
template<typename BasicTypes>
struct disambiguate_type<BasicTypes, typename BasicTypes::int_type>
  : tml::identity<typename BasicTypes::int_type>
{};
/** // doc: disambiguate_type<bool_type> {{{
 * \todo Write documentation
 */ // }}}
template<typename BasicTypes>
struct disambiguate_type<BasicTypes, typename BasicTypes::bool_type>
  : tml::identity<typename BasicTypes::bool_type>
{};
/** // doc: disambiguate_type<real_type> {{{
 * \todo Write documentation
 */ // }}}
template<typename BasicTypes>
struct disambiguate_type<BasicTypes, typename BasicTypes::real_type>
  : tml::identity<typename BasicTypes::real_type>
{};
/** // doc: disambiguate_type<string_type> {{{
 * \todo Write documentation
 */ // }}}
template<typename BasicTypes>
struct disambiguate_type<BasicTypes, typename BasicTypes::string_type>
  : tml::identity<typename BasicTypes::string_type>
{};
/** // doc: disambiguate_type<regex_type> {{{
 * \todo Write documentation
 */ // }}}
template<typename BasicTypes>
struct disambiguate_type<BasicTypes, typename BasicTypes::regex_type>
  : tml::identity<typename BasicTypes::regex_type>
{};
} } // end namespace txpl::vm

#endif /* TXPL_VM_DISAMBIGUATE_TYPE_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
