// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/object_find.hpp

/** // doc: txpl/vm/object_find.hpp {{{
 * \file txpl/vm/object_find.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_VM_OBJECT_FIND_HPP
#define TXPL_VM_OBJECT_FIND_HPP

#include <txpl/vm/object.hpp>
#include <txpl/vm/object_op_detail.hpp>
#include <txpl/vm/tree_finder.hpp>
#include <txpl/util/fake_functor.hpp>

namespace txpl { namespace vm {
/** // doc: object_find() {{{
 * \todo Write documentation
 */ // }}}
template<typename Value, typename Iterator, typename Ehandler>
bool object_find(object<Value> const& s,
                 Iterator const& obj_first,
                 Iterator const& obj_last,
                 Iterator const& mem_first,
                 Iterator const& mem_last,
                 Value& result,
                 Ehandler f)
{
  auto find = tree_finder<object_op_detail, Value, Ehandler>(result, f);
  return find(s, obj_first, obj_last, mem_first, mem_last);
}
/** // doc: object_find() {{{
 * \todo Write documentation
 */ // }}}
template<typename Value, typename Iterator>
bool object_find(object<Value> const& s,
                 Iterator const& obj_first,
                 Iterator const& obj_last,
                 Iterator const& mem_first,
                 Iterator const& mem_last,
                 Value& result)
{
  auto f = util::fake_functor<void>();
  return object_find(s, obj_first, obj_last, mem_first, mem_last, result, f);
}
/** // doc: object_find() {{{
 * \todo Write documentation
 */ // }}}
template<typename Value, typename CharT, typename Traits, typename Ehandler>
bool object_find(object<Value> const& s,
                 std::basic_string<CharT, Traits> const& obj,
                 std::basic_string<CharT, Traits> const& mem,
                 Value& result,
                 Ehandler f)
{
  typedef std::basic_string<CharT, Traits> String;
  String fqdn(obj + object_op_detail::separator() + mem);
  return object_find(s, fqdn.begin(), fqdn.begin() + obj.size(),
                        fqdn.end() - mem.size(), fqdn.end(), result, f);
}
/** // doc: object_find() {{{
 * \todo Write documentation
 */ // }}}
template<typename Value, typename CharT, typename Traits>
bool object_find(object<Value> const& s,
                 std::basic_string<CharT, Traits> const& obj,
                 std::basic_string<CharT, Traits> const& mem,
                 Value& result)
{
  typedef std::basic_string<CharT, Traits> String;
  String fqdn(obj + object_op_detail::separator() + mem);
  return object_find(s, fqdn.begin(), fqdn.begin() + obj.size(),
                        fqdn.end() - mem.size(), fqdn.end(), result);
}
/** // doc: object_find() {{{
 * \todo Write documentation
 */ // }}}
template<typename Value, typename CharT, typename Ehandler>
bool object_find(object<Value> const& s,
                 CharT const* obj,
                 CharT const* mem,
                 Value& result,
                 Ehandler f)
{
  typedef std::basic_string<CharT> String;
  return object_find(s, String(obj), String(mem), result, f);
}
/** // doc: object_find() {{{
 * \todo Write documentation
 */ // }}}
template<typename Value, typename CharT>
bool object_find(object<Value> const& s,
                 CharT const* obj,
                 CharT const* mem,
                 Value& result)
{
  typedef std::basic_string<CharT> String;
  return object_find(s, String(obj), String(mem), result);
}
} } // end namespace txpl::vm

#endif /* TXPL_VM_OBJECT_FIND_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
