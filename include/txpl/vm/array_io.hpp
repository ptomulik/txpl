// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/array_io.hpp

/** // doc: txpl/vm/array_io.hpp {{{
 * \file txpl/vm/array_io.hpp
 * \brief Provides overloaded ostream operator<< for \ref txpl::vm::array "vm::array"
 */ // }}}
#ifndef TXPL_VM_ARRAY_IO_HPP
#define TXPL_VM_ARRAY_IO_HPP

#include <txpl/vm/array.hpp>
#include <ostream>

namespace std {
/** // doc: operator<<() {{{
 * \ingroup VmGroup
 * \brief Overloaded ostream \c operator<< for \ref txpl::vm::array "vm::array"
 *
 * \param os output stream,
 * \param x  input array.
 * \returns  the modified output stream \e os.
 *
 * The function outputs its argument \e x to the output stream \e os
 *
 * \b Example:
 * \snippet array_io1.cpp Code
 * \b Output:
 * \snippet array_io1.cpp Output
 */ // }}}
template<typename CharT, typename Traits, typename Value>
basic_ostream<CharT, Traits>&
operator<<(basic_ostream<CharT, Traits>& os, txpl::vm::array<Value> const& x)
{
  os << CharT{'['};
  auto it = x.begin();
  if(it != x.end())
    {
      os << *it++;
      for(;it != x.end();++it)
        { os << CharT{','} << CharT{' '} << *it; }
    }
  os << CharT{']'};
  return os;
}
} // end namespace std

#endif /* TXPL_VM_ARRAY_IO_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
