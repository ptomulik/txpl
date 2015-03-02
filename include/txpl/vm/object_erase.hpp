// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/object_erase.hpp

/** // doc: txpl/vm/object_erase.hpp {{{
 * \file txpl/vm/object_erase.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_VM_OBJECT_ERASE_HPP
#define TXPL_VM_OBJECT_ERASE_HPP

#include <txpl/vm/object.hpp>
#include <txpl/vm/object_op_detail.hpp>
#include <txpl/vm/tree_eraser.hpp>
#include <txpl/util/fake_functor.hpp>

namespace txpl { namespace vm {
/** // doc: object_erase() {{{
 * \todo Write documentation
 */ // }}}
template<typename Value, typename Iterator, typename Ehandler>
bool object_erase(object<Value>& s,
                  Iterator const& obj_first,
                  Iterator const& obj_last,
                  Iterator const& mem_first,
                  Iterator const& mem_last,
                  Ehandler f)
{
  auto erase = tree_eraser<object_op_detail, Ehandler>(f);
  return erase(s, obj_first, obj_last, mem_first, mem_last);
}
/** // doc: object_erase() {{{
 * \todo Write documentation
 */ // }}}
template<typename Value, typename Iterator>
bool object_erase(object<Value>& s,
                  Iterator const& obj_first,
                  Iterator const& obj_last,
                  Iterator const& mem_first,
                  Iterator const& mem_last)
{
  auto f = util::fake_functor<void>();
  return object_erase(s, obj_first, obj_last, mem_first, mem_last, f);
}
/** // doc: object_erase() {{{
 * \todo Write documentation
 */ // }}}
template<typename Value, typename CharT, typename Traits, typename Ehandler>
bool object_erase(object<Value>& s,
                  std::basic_string<CharT, Traits> const& obj,
                  std::basic_string<CharT, Traits> const& mem,
                  Ehandler f)
{
  typedef std::basic_string<CharT, Traits> String;
  String fqdn(obj + object_op_detail::separator() + mem);
  return object_erase(s, fqdn.begin(), fqdn.begin() + obj.size(),
                         fqdn.end() - mem.size(), fqdn.end(), f);
}
/** // doc: object_erase() {{{
 * \todo Write documentation
 */ // }}}
template<typename Value, typename CharT, typename Traits>
bool object_erase(object<Value>& s,
                  std::basic_string<CharT, Traits> const& obj,
                  std::basic_string<CharT, Traits> const& mem)
{
  typedef std::basic_string<CharT, Traits> String;
  String fqdn(obj + object_op_detail::separator() + mem);
  return object_erase(s, fqdn.begin(), fqdn.begin() + obj.size(),
                         fqdn.end() - mem.size(), fqdn.end());
}
/** // doc: object_erase() {{{
 * \todo Write documentation
 */ // }}}
template<typename Value, typename CharT, typename Ehandler>
bool object_erase(object<Value>& s,
                  CharT const* obj,
                  CharT const* mem,
                  Ehandler f)
{
  typedef std::basic_string<CharT> String;
  return object_erase(s, String(obj), String(mem), f);
}
/** // doc: object_erase() {{{
 * \todo Write documentation
 */ // }}}
template<typename Value, typename CharT>
bool object_erase(object<Value>& s,
                  CharT const* obj,
                  CharT const* mem)
{
  typedef std::basic_string<CharT> String;
  return object_erase(s, String(obj), String(mem));
}
} } // end namespace txpl::vm

#endif /* TXPL_VM_OBJECT_ERASE_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
