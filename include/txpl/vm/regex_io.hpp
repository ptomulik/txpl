// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/regex_io.hpp

/** // doc: txpl/vm/regex_io.hpp {{{
 * \file txpl/vm/regex_io.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_VM_REGEX_IO_HPP
#define TXPL_VM_REGEX_IO_HPP

#include <regex>
#include <ostream>

namespace std {
/** // doc: operator<<() {{{
 * \ingroup VmGroup
 * \brief Overloaded ostream \c operator<< for `std::basic_regex<>`
 *
 * \param os output stream,
 * \param x  regex.
 * \returns  the modified output stream \e os.
 *
 * The function outputs its argument \e x to the output stream \e os
 */ // }}}
template<typename CharT, typename Traits, typename CharT2, typename Traits2>
basic_ostream<CharT, Traits>&
operator<<(basic_ostream<CharT, Traits>& os, basic_regex<CharT2, Traits2> const&)
{
  os << "(a regular expression)";
  return os;
}
} // end namespace std

#endif /* TXPL_VM_REGEX_IO_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
