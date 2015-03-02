// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/array.hpp

/** // doc: txpl/vm/array.hpp {{{
 * \file txpl/vm/array.hpp
 * \brief Defines the \ref txpl::vm::array "vm::array" template
 */ // }}}
#ifndef TXPL_VM_ARRAY_HPP
#define TXPL_VM_ARRAY_HPP

#include <txpl/vm/array_fwd.hpp>
#include <txpl/vm/value.hpp>

namespace txpl { namespace vm {
/** // doc: array {{{
 * \ingroup VmGroup
 * \brief Array of values
 *
 *
 * The \ref txpl::vm::array "vm::array<>" implements one-dimensional array of
 * values. The \ref txpl::vm::array "array" has same interface as
 * <a href="http://en.cppreference.com/w/cpp/container/vector">std::vector</a>
 * (currently \ref txpl::vm::array "vm::array<>" is simply an alias to
 * \c std::vector). The \ref txpl::vm::array "vm::array<>" is intended
 * to hold values of type \ref txpl::vm::value "vm::value<>". If it's used so,
 * then the array is heterogeneous. This means that each element of a
 * \ref txpl::vm::array "vm::array<>" may contain a value of different type
 * including \ref txpl::vm::array "vm::array<>" itself.
 *
 * \tparam Value Type of the elements held in array. Defaults to
 *         \ref txpl::vm::value "vm::value<>".
 *
 * \b Example:
 * \snippet array1.cpp Code
 *
 * \b Output:
 * \snippet array1.cpp Output
 */ // }}}
template<typename Value = value<> >
using array = array_fwd<Value>;
} } // end namespace txpl::vm

#endif /* TXPL_VM_ARRAY_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
