// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/scope_fwd.hpp

/** // doc: txpl/vm/scope_fwd.hpp {{{
 * \file txpl/vm/scope_fwd.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_VM_SCOPE_FWD_HPP
#define TXPL_VM_SCOPE_FWD_HPP

#include <map>
#include <string>

namespace txpl { namespace vm {
/** // doc: scope_fwd {{{
 * \todo Write documentation
 */ // }}}
template<typename Symbol>
using scope_fwd = std::map<std::string, Symbol>;
} } // end namespace txpl::vm

#endif /* TXPL_VM_SCOPE_FWD_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
