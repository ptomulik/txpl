// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/object.hpp

/** // doc: txpl/vm/object.hpp {{{
 * \file txpl/vm/object.hpp
 * \brief Defines \ref txpl::vm::object "vm::object<>"
 */ // }}}
#ifndef TXPL_VM_OBJECT_HPP
#define TXPL_VM_OBJECT_HPP

#include <txpl/vm/value.hpp>
#include <txpl/vm/object_fwd.hpp>

namespace txpl { namespace vm {
/** // doc: object {{{
 * \todo Write documentation
 */ // }}}
template<typename Value = value<> >
using object = object_fwd<Value>;
} } // end namespace txpl::vm

#endif /* TXPL_VM_OBJECT_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
