// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/scope_erase.hpp

/** // doc: txpl/vm/scope_erase.hpp {{{
 * \file txpl/vm/scope_erase.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_VM_SCOPE_ERASE_HPP
#define TXPL_VM_SCOPE_ERASE_HPP

#include <txpl/vm/scope.hpp>
#include <txpl/vm/tree_eraser.hpp>
#include <txpl/vm/scope_op_detail.hpp>
#include <txpl/util/fake_functor.hpp>
#include <string>

namespace txpl { namespace vm {
/** // doc: scope_erase() {{{
 * \todo Write documentation
 */ // }}}
template<typename Symbol, typename Iterator, typename Ehandler>
bool scope_erase(scope<Symbol>& s, Iterator const& first, Iterator const& last,
                 Ehandler f)
{ return tree_eraser<scope_op_detail, Ehandler>(f)(s, first, last); }
/** // doc: scope_erase() {{{
 * \todo Write documentation
 */ // }}}
template<typename Symbol, typename Iterator>
bool scope_erase(scope<Symbol>& s, Iterator const& first, Iterator const& last)
{ return scope_erase(s, first, last, util::fake_functor<void>()); }
/** // doc: scope_erase() {{{
 * \todo Write documentation
 */ // }}}
template<typename Symbol, typename Ehandler>
bool scope_erase(scope<Symbol>& s, std::string const& fqdn, Ehandler f)
{ return scope_erase(s, fqdn.begin(), fqdn.end(), f); }
/** // doc: scope_erase() {{{
 * \todo Write documentation
 */ // }}}
template<typename Symbol>
bool scope_erase(scope<Symbol>& s, std::string const& fqdn)
{ return scope_erase(s, fqdn.begin(), fqdn.end()); }
} } // end txpl::vm

#endif /* TXPL_VM_SCOPE_ERASE_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
