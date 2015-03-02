// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/disambiguate.hpp

/** // doc: txpl/vm/disambiguate.hpp {{{
 * \file txpl/vm/disambiguate.hpp
 * \brief Provides the \ref txpl::vm::disambiguate() "vm::disambiguate()" function
 */ // }}}
#ifndef TXPL_VM_DISAMBIGUATE_HPP_INCLUDED
#define TXPL_VM_DISAMBIGUATE_HPP_INCLUDED

#include <txpl/vm/disambiguate_type.hpp>

namespace txpl { namespace vm {
/** \ingroup VmGroup
 * @{ */
/** // doc: disambiguate() {{{
 * \brief Converts a C++ value to an appropriate type supported by \ref VmGroup
 *        "virtual machine's" type system
 *
 * \tparam BasicTypes \ref BasicTypesDefinerConcept which describes the
 *         destination type system,
 * \tparam T type of the C++ value to be converted,
 *
 * \param x the C++ value to be converted.
 *
 * \returns the value \e x converted to it's nearest
 *          \ref BasicTypesConcept "basic type".
 *
 * The function converts a C++ value to one of the types specified in
 * \e BasicTypes such that the converted value fits well to the destination
 * type system. The C++ type system is much richer than the TXPL type system.
 * When evaluating an expression, the result may be of type that can't be
 * implicitly converted to the target type system. For example, `2 + 2` yields
 * `int` in C++. If then the target type system does not use `int` in its
 * type system -- but `long`, for example -- then there may be an ambiguity
 * between `long` and `char` when trying to assign the result to 
 * \ref txml::vm::value "vm::value<>". The ambiguity is resolved by the
 * \ref txpl::vm::disambiguate() "vm::disambiguate()" function.
 *
 * \b Example:
 * \snippet disambiguate1.cpp Code
 * \b Output:
 * \snippet disambiguate1.cpp Output
 */ // }}}
template<typename BasicTypes, typename T>
constexpr typename disambiguate_type<BasicTypes,T>::type
disambiguate(T const& x)
{ return static_cast<typename disambiguate_type<BasicTypes,T>::type>(x); } 
/** // doc: disambiguate() {{{
 * \brief Specializes the \ref txpl::vm::disambiguate() "vm::disambiguate()"
 *        for strings.
 */ // }}}
template<typename BasicTypes>
constexpr typename BasicTypes::string_type const&
disambiguate(typename BasicTypes::string_type const& x) noexcept
{ return x; } 
/** // doc: disambiguate() {{{
 * \brief Specializes the \ref txpl::vm::disambiguate() "vm::disambiguate()"
 *        for regular expressioins.
 */ // }}}
template<typename BasicTypes>
constexpr typename BasicTypes::regex_type const&
disambiguate(typename BasicTypes::regex_type const& x) noexcept
{ return x; } 
/** // doc: disambiguate() {{{
 * \brief Specializes the \ref txpl::vm::disambiguate() "vm::disambiguate()"
 *        for (null-terminated) C strings
 */ // }}}
template<typename BasicTypes>
constexpr typename BasicTypes::string_type
disambiguate(typename BasicTypes::string_type::value_type const* x)
{ return typename BasicTypes::string_type(x); } 
/** @} */
} } // end namespace txpl::vm

#endif /* TXPL_VM_DISAMBIGUATE_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
