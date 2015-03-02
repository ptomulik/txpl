// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/scope.hpp

/** // doc: txpl/vm/scope.hpp {{{
 * \file txpl/vm/scope.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_VM_SCOPE_HPP
#define TXPL_VM_SCOPE_HPP

#include <txpl/vm/scope_fwd.hpp>
#include <txpl/vm/symbol.hpp>

namespace txpl { namespace vm {
/** // doc scope {{{
 * \todo Write documentation
 */ // }}}
template<typename Symbol = symbol<> >
using scope = scope_fwd<Symbol>;
} } // end txpl::vm

#endif /* TXPL_VM_SCOPE_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
