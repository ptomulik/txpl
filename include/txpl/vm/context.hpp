// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/context.hpp

/** // doc: txpl/vm/context.hpp {{{
 * \file txpl/vm/context.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_VM_CONTEXT_HPP_INCLUDED
#define TXPL_VM_CONTEXT_HPP_INCLUDED

#include <txpl/vm/basic_types.hpp>
#include <txpl/vm/value.hpp>
#include <txpl/vm/scope.hpp>
#include <txpl/vm/symbol.hpp>
#include <map>

namespace txpl { namespace vm {
template<typename BasicTypes = vm::basic_types<> >
struct context
{
  /** // doc: value_type {{{
   * \todo Write documentation
   */ // }}}
  typedef txpl::vm::value<BasicTypes> value_type;
  /** // doc: symbol_type {{{
   * \todo Write documentation
   */ // }}}
  typedef txpl::vm::symbol<value_type> symbol_type;
  /** // doc: scope_type {{{
   * \todo Write documentation
   */ // }}}
  typedef txpl::vm::scope<symbol_type> scope_type;
  /** // doc: global_scope {{{
   * \todo Write documentation
   */ // }}}
  scope_type global_scope;
  /** // doc: current_scope {{{
   * \todo Write documentation
   */ // }}}
  std::string current_scope;
};
} } // end namespace txpl

#endif /* TXPL_VM_CONTEXT_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
