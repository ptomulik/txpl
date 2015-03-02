// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/object_fwd.hpp

/** // doc: txpl/vm/object_fwd.hpp {{{
 * \file txpl/vm/object_fwd.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_VM_OBJECT_FWD_HPP
#define TXPL_VM_OBJECT_FWD_HPP

#include <map>
#include <string>

namespace txpl { namespace vm {
/** // doc: object {{{
 * \todo Write documentation
 */ // }}}
template<typename Value>
using object_fwd = std::map<std::string, Value>;
} } // end namespace txpl::vm

#endif /* TXPL_VM_OBJECT_FWD_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
