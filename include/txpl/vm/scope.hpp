// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/scope.hpp

/** // doc: txpl/vm/scope.hpp {{{
 * \file txpl/vm/scope.hpp
 * \brief Defines the \ref txpl::vm::scope "vm::scope<>"
 */ // }}}
#ifndef TXPL_VM_SCOPE_HPP
#define TXPL_VM_SCOPE_HPP

#include <txpl/vm/scope_fwd.hpp>
#include <txpl/vm/symbol.hpp>

namespace txpl { namespace vm {
/** // doc scope {{{
 * \ingroup VmGroup
 * \brief Recursive map of \ref VmSymbolConcept "symbols"
 *
 * \tparam Symbol symbol type, this should be a model of \ref VmSymbolConcept
 *
 * This map is used to organize \ref VmGroup "virtual machine" symbols into
 * a tree-like hierarchy. Each level is equivalent to
 * `std::map<std::string, Symbol>`. The `Symbol` is a recurcive variant type
 * having a `scope<Symbol>` as one of its types. Symbols stored in the tree
 * shall be accessed using
 * \ref txpl::vm::scope_find() "vm::scope_find()",
 * \ref txpl::vm::scope_lookup() "vm::scope_lookup()",
 * \ref txpl::vm::scope_insert() "vm::scope_insert()", and
 * \ref txpl::vm::scope_erase() "vm::scope_erase()".
 *
 * \b Example:
 * \snippet scope1.cpp Code
 * \b Output:
 * \snippet scope1.cpp Output
 *
 * \sa \ref txpl::vm::symbol "vm::symbol<>"
 */ // }}}
template<typename Symbol = symbol<> >
using scope = scope_fwd<Symbol>;
} } // end txpl::vm

#endif /* TXPL_VM_SCOPE_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
