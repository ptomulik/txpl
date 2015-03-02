// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/scope_find.hpp

/** // doc: txpl/vm/scope_find.hpp {{{
 * \file txpl/vm/scope_find.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_VM_SCOPE_FIND_HPP
#define TXPL_VM_SCOPE_FIND_HPP

#include <txpl/vm/scope.hpp>
#include <txpl/vm/tree_finder.hpp>
#include <txpl/vm/scope_op_detail.hpp>
#include <txpl/util/fake_functor.hpp>
#include <string>

namespace txpl { namespace vm {
/** // doc: scope_find() {{{
 * \todo Write documentation
 */ // }}}
template<typename Symbol, typename Iterator, typename Ehandler>
bool scope_find(scope<Symbol> const& s, Iterator const& first, Iterator const& last,
                Symbol& result, Ehandler f)
{ return tree_finder<scope_op_detail, Symbol, Ehandler>(result, f)(s, first, last); }
/** // doc: scope_find() {{{
 * \todo Write documentation
 */ // }}}
template<typename Symbol, typename Iterator>
bool scope_find(scope<Symbol> const& s, Iterator const& first, Iterator const& last,
                Symbol& result)
{ return scope_find(s, first, last, result, util::fake_functor<void>()); }
/** // doc: scope_find() {{{
 * \todo Write documentation
 */ // }}}
template<typename Symbol, typename Ehandler>
bool scope_find(scope<Symbol> const& s, std::string const& fqdn, Symbol& result, Ehandler f)
{ return scope_find(s, fqdn.begin(), fqdn.end(), result, f); }
/** // doc: scope_find() {{{
 * \todo Write documentation
 */ // }}}
template<typename Symbol>
bool scope_find(scope<Symbol> const& s, std::string const& fqdn, Symbol& result)
{ return scope_find(s, fqdn.begin(), fqdn.end(), result); }
} } // end txpl::vm

#endif /* TXPL_VM_SCOPE_FIND_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
