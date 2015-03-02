// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/unit.hpp

/** // doc: txpl/unit.hpp {{{
 * \file txpl/unit.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_LEXER_RECOGNIZE_PRINTABLE_HPP
#define TXPL_LEXER_RECOGNIZE_PRINTABLE_HPP

namespace txpl { namespace lexer {
/** // doc: isalnum() {{{
 * \todo Write documentation
 */ // }}}
template<typename CharT>
constexpr bool
recognize_printable(CharT c) noexcept
{
  return (c>=CharT{'\x20'} && c<=CharT{'\x7E'});
}
} } // end namespace txpl::lexer

#endif /* TXPL_LEXER_RECOGNIZE_PRINTABLE_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
