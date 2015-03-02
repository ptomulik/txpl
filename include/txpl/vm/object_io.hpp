// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/object_io.hpp

/** // doc: txpl/vm/object_io.hpp {{{
 * \file txpl/vm/object_io.hpp
 * \brief Provides overloaded ostream operator<< for \ref txpl::vm::object "vm::object"
 */ // }}}
#ifndef TXPL_VM_OBJECT_IO_HPP
#define TXPL_VM_OBJECT_IO_HPP

#include <txpl/vm/object.hpp>
#include <ostream>
#include <string>

namespace std {
/** // doc: operator<<() {{{
 * \ingroup VmGroup
 * \brief Overloaded ostream \c operator<< for \ref txpl::vm::object "vm::object"
 *
 * \param os output stream,
 * \param x  input object.
 * \returns  the modified output stream \e os.
 *
 * The function outputs its argument \e x to the output stream \e os
 *
 * \b Example:
 * \snippet object_io1.cpp Code
 * \b Output:
 * \snippet object_io1.cpp Output
 */ // }}}
template<typename CharT, typename Traits, typename Value>
basic_ostream<CharT, Traits>&
operator<<(basic_ostream<CharT, Traits>& os, txpl::vm::object<Value> const& x)
{
  os << CharT{'{'};
  auto it = x.begin();
  if(it != x.end())
    {
      basic_string<CharT, Traits> key(it->first.begin(), it->first.end());
      os << key << CharT{':'} << CharT{' '} << it->second;
      for(++it;it != x.end();++it)
        {
          basic_string<CharT, Traits> key(it->first.begin(), it->first.end());
          os << CharT{','} << CharT{' '}
             << key
             << CharT{':'} << CharT{' '}
             << it->second;
        }
    }
  os << CharT{'}'};
  return os;
}
} // end namespace std

#endif /* TXPL_VM_OBJECT_IO_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
