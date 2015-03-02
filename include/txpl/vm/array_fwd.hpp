// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/array_fwd.hpp

/** // doc: txpl/vm/array_fwd.hpp {{{
 * \file txpl/vm/array_fwd.hpp
 * \brief Provides forward declaration of the \ref txpl::vm::array "vm::array<>"
 */ // }}}
#ifndef TXPL_VM_ARRAY_FWD_HPP
#define TXPL_VM_ARRAY_FWD_HPP

#include <vector>

namespace txpl { namespace vm {
/** // doc: array {{{
 * \ingroup VmGroup
 * \brief Forward declaration for the \ref txpl::vm::array<> "vm::array"
 */ // }}}
template<typename Value>
using array_fwd = std::vector<Value>;
} } // end namespace txpl::vm

#endif /* TXPL_VM_ARRAY_FWD_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
