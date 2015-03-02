// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/array.hpp

/** // doc: txpl/vm/array.hpp {{{
 * \file txpl/vm/array.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_VM_ARRAY_HPP
#define TXPL_VM_ARRAY_HPP

#include <txpl/vm/array_fwd.hpp>
#include <txpl/vm/value.hpp>

namespace txpl { namespace vm {
/** // doc: array {{{
 * \todo Write documentation
 */ // }}}
template<typename Value = value<>>
using array = array_fwd<Value>;
} } // end namespace txpl::vm

#endif /* TXPL_VM_ARRAY_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
