// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/object_op_detail.hpp

/** // doc: txpl/vm/object_op_detail.hpp {{{
 * \file txpl/vm/object_op_detail.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_VM_OBJECT_OP_DETAIL_HPP
#define TXPL_VM_OBJECT_OP_DETAIL_HPP

#include <string>

namespace txpl { namespace vm {
/** // doc: object_op_detail {{{
 * \todo Write documentation
 */ // }}}
struct object_op_detail
{
  /** // doc: separator() {{{
   * \todo Write documentation
   */ // }}}
  constexpr static const char* separator() { return "."; }
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
      return "malformed member name " + std::string(name.begin(), name.end());
  }
  /** // doc: strerr_malformed_name() {{{
   * \todo Write documentation
   */ // }}}
  template<typename Range>
  static std::string
  strerr_not_found(Range const& obj, Range const& mem)
  {
    std::string m(std::string(mem.begin(), mem.end()));
    if(obj.empty())
      return "member " + m + " not found";
    else
      return std::string(obj.begin(), obj.end()) + " has no member named " + m;
  }
  /** // doc: strerr_malformed_name() {{{
   * \todo Write documentation
   */ // }}}
  template<typename Range>
  static std::string
  strerr_not_a_map(Range const& name)
  {
    return std::string(name.begin(), name.end()) + " is not an object";
  }
};
} } // end namespace txpl::vm

#endif /* TXPL_VM_OBJECT_OP_DETAIL_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
