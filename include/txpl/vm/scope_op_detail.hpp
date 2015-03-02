// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/scope_op_detail.hpp

/** // doc: txpl/vm/scope_op_detail.hpp {{{
 * \file txpl/vm/scope_op_detail.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_VM_SCOPE_OP_DETAIL_HPP
#define TXPL_VM_SCOPE_OP_DETAIL_HPP

#include <string>

namespace txpl { namespace vm {
/** // doc: scope_op_detail {{{
 * \todo Write documentation
 */ // }}}
struct scope_op_detail
{
  /** // doc: separator() {{{
   * \todo Write documentation
   */ // }}}
  constexpr static const char* separator() { return "::"; }
  /** // doc: strerr_malformed_name() {{{
   * \todo Write documentation
   */ // }}}
  template<typename Range>
  static std::string
  strerr_malformed_name(Range const& name)
  {
    if(name.empty())
      return "empty names not allowed";
    else
      return "malformed symbol name " + std::string(name.begin(), name.end());
  }
  /** // doc: strerr_malformed_name() {{{
   * \todo Write documentation
   */ // }}}
  template<typename Range>
  static std::string
  strerr_not_found(Range const& scope, Range const& mem)
  {
    std::string member(std::string(mem.begin(), mem.end()));
    if(scope.empty())
      return member + " not found in global scope";
    else
      return member + " not found in " + std::string(scope.begin(), scope.end());
  }
  /** // doc: strerr_malformed_name() {{{
   * \todo Write documentation
   */ // }}}
  template<typename Range>
  static std::string
  strerr_not_a_map(Range const& name)
  { return std::string(name.begin(), name.end()) + " is not a scope"; }
};
} } // end txpl::vm

#endif /* TXPL_VM_SCOPE_OP_DETAIL_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
