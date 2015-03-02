// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/recognize_alnum.hpp

/** // doc: txpl/lexer/recognize_alnum.hpp {{{
 * \file txpl/lexer/recognize_alnum.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_LEXER_RECOGNIZE_ALNUM_HPP
#define TXPL_LEXER_RECOGNIZE_ALNUM_HPP

#include <txpl/lexer/recognize_alpha.hpp>
#include <txpl/lexer/recognize_dec_digit.hpp>

namespace txpl { namespace lexer {
/** // doc: recognize_alnum() {{{
 * \todo Write documentation
 */ // }}}
template<typename CharT>
constexpr bool
recognize_alnum(CharT c) noexcept
{ return recognize_alpha(c) || (recognize_dec_digit(c) != 0); }
} } // end namespace txpl::lexer

#endif /* TXPL_LEXER_RECOGNIZE_ALNUM_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
