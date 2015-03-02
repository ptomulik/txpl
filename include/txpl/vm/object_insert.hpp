// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/object_insert.hpp

/** // doc: txpl/vm/object_insert.hpp {{{
 * \file txpl/vm/object_insert.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_VM_OBJECT_INSERT_HPP
#define TXPL_VM_OBJECT_INSERT_HPP

#include <txpl/vm/object.hpp>
#include <txpl/vm/object_op_detail.hpp>
#include <txpl/vm/tree_inserter.hpp>
#include <txpl/util/fake_functor.hpp>

namespace txpl { namespace vm {
/** // doc: object_insert() {{{
 * \todo Write documentation
 */ // }}}
template<typename Value, typename Iterator, typename T, typename Ehandler>
bool object_insert(object<Value>& s,
                   Iterator const& obj_first,
                   Iterator const& obj_last,
                   Iterator const& mem_first,
                   Iterator const& mem_last,
                   T const& x,
                   Ehandler f)
{
  auto insert = tree_inserter<object_op_detail, Value, Ehandler>(x, f);
  return insert(s, obj_first, obj_last, mem_first, mem_last);
}
/** // doc: object_insert() {{{
 * \todo Write documentation
 */ // }}}
template<typename Value, typename Iterator, typename T>
bool object_insert(object<Value>& s,
                   Iterator const& obj_first,
                   Iterator const& obj_last,
                   Iterator const& mem_first,
                   Iterator const& mem_last,
                   T const& x)
{
  auto f = util::fake_functor<void>();
  return object_insert(s, obj_first, obj_last, mem_first, mem_last, x, f);
}
/** // doc: object_insert() {{{
 * \todo Write documentation
 */ // }}}
template<typename Value, typename CharT, typename Traits, typename T, typename Ehandler>
bool object_insert(object<Value>& s,
                   std::basic_string<CharT, Traits> const& obj,
                   std::basic_string<CharT, Traits> const& mem,
                   T const& x,
                   Ehandler f)
{
  typedef std::basic_string<CharT, Traits> String;
  String fqdn(obj + object_op_detail::separator() + mem);
  return object_insert(s, fqdn.begin(), fqdn.begin() + obj.size(),
                          fqdn.end() - mem.size(), fqdn.end(), x, f);
}
/** // doc: object_insert() {{{
 * \todo Write documentation
 */ // }}}
template<typename Value, typename CharT, typename Traits, typename T>
bool object_insert(object<Value>& s,
                   std::string const& obj,
                   std::string const& mem,
                   T const& x)
{
  typedef std::basic_string<CharT, Traits> String;
  String fqdn(obj + object_op_detail::separator() + mem);
  return object_insert(s, fqdn.begin(), fqdn.begin() + obj.size(),
                           fqdn.end() - mem.size(), fqdn.end(), x);
}
/** // doc: object_insert() {{{
 * \todo Write documentation
 */ // }}}
template<typename Value, typename CharT, typename T, typename Ehandler>
bool object_insert(object<Value>& s,
                   CharT const* obj,
                   CharT const* mem,
                   T const& x,
                   Ehandler f)
{
  typedef std::basic_string<CharT> String;
  return object_insert(s, String(obj), String(mem), x, f);
}
/** // doc: object_insert() {{{
 * \todo Write documentation
 */ // }}}
template<typename Value, typename CharT, typename T>
bool object_insert(object<Value>& s,
                   CharT const* obj,
                   CharT const* mem,
                   T const& x)
{
  typedef std::basic_string<CharT> String;
  return object_insert(s, String(obj), String(mem), x);
}
} } // end namespace txpl::vm

#endif /* TXPL_VM_OBJECT_INSERT_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
