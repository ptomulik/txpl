// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/object_io.hpp

/** // doc: txpl/vm/object_io.hpp {{{
 * \file txpl/vm/object_io.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_VM_OBJECT_IO_HPP
#define TXPL_VM_OBJECT_IO_HPP

#include <txpl/vm/object.hpp>
#include <ostream>

namespace std {
/** // doc: operator<<() {{{
 * \todo Write documentation
 */ // }}}
template<typename CharT, typename Traits, typename Value>
basic_ostream<CharT, Traits>&
operator<<(basic_ostream<CharT, Traits>& os, txpl::vm::object<Value> const& x)
{
  os << "{";
  auto it = x.begin();
  if(it != x.end())
    {
      os << it->first << ": " << it->second;
      for(++it;it != x.end();++it)
        { os << ", " << it->first << ": " << it->second; }
    }
  os << "}";
  return os;
}
} // end namespace std

#endif /* TXPL_VM_OBJECT_IO_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
