// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/recognize_alpha.hpp

/** // doc: txpl/lexer/recognize_alpha.hpp {{{
 * \file txpl/lexer/recognize_alpha.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_LEXER_RECOGNIZE_ALPHA_HPP
#define TXPL_LEXER_RECOGNIZE_ALPHA_HPP

namespace txpl { namespace lexer {
/** // doc: recognize_alpha() {{{
 * \todo Write documentation
 */ // }}}
template<typename CharT>
constexpr bool
recognize_alpha(CharT c) noexcept
{ return (c>=CharT{'a'} && c<=CharT{'z'}) || (c>=CharT{'A'} && c<=CharT{'Z'}); }
} } // end namespace txpl::lexer

#endif /* TXPL_LEXER_RECOGNIZE_ALPHA_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
