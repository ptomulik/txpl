// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/disambiguate.hpp

/** // doc: txpl/vm/disambiguate.hpp {{{
 * \file txpl/vm/disambiguate.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_VM_DISAMBIGUATE_HPP_INCLUDED
#define TXPL_VM_DISAMBIGUATE_HPP_INCLUDED

#include <txpl/vm/disambiguate_type.hpp>

namespace txpl { namespace vm {
/** // doc: disambiguate() {{{
 * \todo Write documentation
 */ // }}}
template<typename BasicTypes, typename T>
constexpr typename disambiguate_type<BasicTypes,T>::type
disambiguate(T const& x)
{ return static_cast<typename disambiguate_type<BasicTypes,T>::type>(x); } 
/** // doc: disambiguate() {{{
 * \todo Write documentation
 */ // }}}
template<typename BasicTypes>
constexpr typename BasicTypes::char_type
disambiguate(typename BasicTypes::char_type x) noexcept
{ return x; } 
/** // doc: disambiguate() {{{
 * \todo Write documentation
 */ // }}}
template<typename BasicTypes>
constexpr typename BasicTypes::int_type
disambiguate(typename BasicTypes::int_type x) noexcept
{ return x; } 
/** // doc: disambiguate() {{{
 * \todo Write documentation
 */ // }}}
template<typename BasicTypes>
constexpr typename BasicTypes::bool_type
disambiguate(typename BasicTypes::bool_type x) noexcept
{ return x; } 
/** // doc: disambiguate() {{{
 * \todo Write documentation
 */ // }}}
template<typename BasicTypes>
constexpr typename BasicTypes::real_type
disambiguate(typename BasicTypes::real_type x) noexcept
{ return x; } 
/** // doc: disambiguate() {{{
 * \todo Write documentation
 */ // }}}
template<typename BasicTypes>
constexpr typename BasicTypes::string_type const&
disambiguate(typename BasicTypes::string_type const& x) noexcept
{ return x; } 
/** // doc: disambiguate() {{{
 * \todo Write documentation
 */ // }}}
template<typename BasicTypes>
constexpr typename BasicTypes::regex_type const&
disambiguate(typename BasicTypes::regex_type const& x) noexcept
{ return x; } 
} } // end namespace txpl::vm

#endif /* TXPL_VM_DISAMBIGUATE_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
