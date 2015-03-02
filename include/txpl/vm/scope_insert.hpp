// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/scope_insert.hpp

/** // doc: txpl/vm/scope_insert.hpp {{{
 * \file txpl/vm/scope_insert.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_VM_SCOPE_INSERT_HPP
#define TXPL_VM_SCOPE_INSERT_HPP

#include <txpl/vm/scope.hpp>
#include <txpl/vm/tree_inserter.hpp>
#include <txpl/vm/scope_op_detail.hpp>
#include <txpl/util/fake_functor.hpp>
#include <string>

namespace txpl { namespace vm {
/** // doc: scope_insert() {{{
 * \todo Write documentation
 */ // }}}
template<typename Symbol, typename Iterator, typename T, typename Ehandler>
bool scope_insert(scope<Symbol>& s, Iterator const& first, Iterator const& last,
                 T const& x, Ehandler f)
{ return tree_inserter<scope_op_detail, Symbol, Ehandler>(x, f)(s, first, last); }
/** // doc: scope_insert() {{{
 * \todo Write documentation
 */ // }}}
template<typename Symbol, typename Iterator, typename T>
bool scope_insert(scope<Symbol>& s, Iterator const& first, Iterator const& last,
                 T const& x)
{ return scope_insert(s, first, last, x, util::fake_functor<void>()); }
/** // doc: scope_insert() {{{
 * \todo Write documentation
 */ // }}}
template<typename Symbol, typename T, typename Ehandler>
bool scope_insert(scope<Symbol>& s, std::string const& fqdn, T const& x, Ehandler f)
{ return scope_insert(s, fqdn.begin(), fqdn.end(), x, f); }
/** // doc: scope_insert() {{{
 * \todo Write documentation
 */ // }}}
template<typename Symbol, typename T>
bool scope_insert(scope<Symbol>& s, std::string const& fqdn, T const& x)
{ return scope_insert(s, fqdn.begin(), fqdn.end(), x); }
} } // end txpl::vm

#endif /* TXPL_VM_SCOPE_INSERT_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
