// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/token_t.hpp

/** // doc: txpl/lexer/token_t.hpp {{{
 * \file txpl/lexer/token_t.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_LEXER_TOKEN_T_HPP_INCLUDED
#define TXPL_LEXER_TOKEN_T_HPP_INCLUDED

namespace txpl { namespace lexer {
/** \ingroup txpl_lexer
 * @{ */
/** // doc: token_t {{{
 * \todo Write documentation
 */ // }}}
enum class token_t : int
{
  /** // doc: invalid_ {{{
   * \todo Write documentation
   */ // }}}
  invalid_  = 0,
  /** // doc: plus_ {{{
   * \todo Write documentation
   */ // }}}
  plus_     = int{'+'},
  /** // doc: minus_ {{{
   * \todo Write documentation
   */ // }}}
  minus_    = int{'-'},
  /** // doc: mul_ {{{
   * \todo Write documentation
   */ // }}}
  mul_      = int{'*'},
  /** // doc: div_ {{{
   * \todo Write documentation
   */ // }}}
  div_      = int{'/'},
  /** // doc: mod_ {{{
   * \todo Write documentation
   */ // }}}
  mod_      = int{'%'},
  /** // doc: xor_ {{{
   * \todo Write documentation
   */ // }}}
  xor_      = int{'^'},
  /** // doc: bitand_ {{{
   * \todo Write documentation
   */ // }}}
  bitand_   = int{'&'},
  /** // doc: bitor_ {{{
   * \todo Write documentation
   */ // }}}
  bitor_    = int{'|'},
  /** // doc: lt_ {{{
   * \todo Write documentation
   */ // }}}
  lt_       = int{'<'},
  /** // doc: gt_ {{{
   * \todo Write documentation
   */ // }}}
  gt_       = int{'>'},
  /** // doc: not_ {{{
   * \todo Write documentation
   */ // }}}
  not_      = int{'!'},
  /** // doc: neg_ {{{
   * \todo Write documentation
   */ // }}}
  neg_      = int{'~'},
  /** // doc: comma_ {{{
   * \todo Write documentation
   */ // }}}
  comma_    = int{','},
  /** // doc: dot_ {{{
   * \todo Write documentation
   */ // }}}
  dot_      = int{'.'},
  /** // doc: lparen_ {{{
   * \todo Write documentation
   */ // }}}
  lparen_   = int{'('},
  /** // doc: rparen_ {{{
   * \todo Write documentation
   */ // }}}
  rparen_   = int{')'},
  /** // doc: lbracket_ {{{
   * \todo Write documentation
   */ // }}}
  lbracket_ = int{'['},
  /** // doc: rbracket_ {{{
   * \todo Write documentation
   */ // }}}
  rbracket_ = int{']'},
  /** // doc: lbrace_ {{{
   * \todo Write documentation
   */ // }}}
  lbrace_   = int{'{'},
  /** // doc: rbrace_ {{{
   * \todo Write documentation
   */ // }}}
  rbrace_   = int{'}'},
  /** // doc: qmark_ {{{
   * \todo Write documentation
   */ // }}}
  qmark_    = int{'?'},
  /** // doc: colon_ {{{
   * \todo Write documentation
   */ // }}}
  colon_    = int{':'},
  /** // doc: token_min_ {{{
   * \todo Write documentation
   */ // }}}
  token_min_ = 0x10000,
  /** // doc: qchar_{{{
   * \todo Write documentation
   */ // }}}
  qchar_ = token_min_,
  /** // doc: qstring_{{{
   * \todo Write documentation
   */ // }}}
  qstring_,
  /** // doc: qregex_{{{
   * \todo Write documentation
   */ // }}}
  qregex_,
  /** // doc: word_{{{
   * \todo Write documentation
   */ // }}}
  word_,
  /** // doc: real_{{{
   * \todo Write documentation
   */ // }}}
  real_,
  /** // doc: int_ {{{
   * \todo Write documentation
   */ // }}}
  int_,
  /** // doc: bool_ {{{
   * \todo Write documentation
   */ // }}}
  bool_,
  /** // doc: and_ {{{
   * \todo Write documentation
   */ // }}}
  and_    = 0x10100,
  /** // doc: or_ {{{
   * \todo Write documentation
   */ // }}}
  or_     = 0x10101,
  /** // doc: eq_ {{{
   * \todo Write documentation
   */ // }}}
  eq_     = 0x10102,
  /** // doc: neq_ {{{
   * \todo Write documentation
   */ // }}}
  neq_    = 0x10103,
  /** // doc: le_ {{{
   * \todo Write documentation
   */ // }}}
  le_     = 0x10104,
  /** // doc: ge_ {{{
   * \todo Write documentation
   */ // }}}
  ge_     = 0x10105,
  /** // doc: lshift_ {{{
   * \todo Write documentation
   */ // }}}
  lshift_ = 0x10106,
  /** // doc: rshift_ {{{
   * \todo Write documentation
   */ // }}}
  rshift_ = 0x10107,
  /** // doc: match_ {{{
   * \todo Write documentation
   */ // }}}
  match_  = 0x10108,
  /** // doc: nmatch_ {{{
   * \todo Write documentation
   */ // }}}
  nmatch_ = 0x10109,
  /** // doc: nssep_ {{{
   * \todo Write documentation
   */ // }}}
  nssep_,
  /** // doc: spaces_ {{{
   * \todo Write documentation
   */ // }}}
  spaces_,
  /** // doc: other_ {{{
   * \todo Write documentation
   */ // }}}
  other_
};

/** // doc: operator== {{{
 * \todo Write documentation
 */ // }}}
constexpr bool operator==(token_t lhs, int rhs)
{ return static_cast<int>(lhs) == rhs; }
/** // doc: operator== {{{
 * \todo Write documentation
 */ // }}}
constexpr bool operator==(int lhs, token_t rhs)
{ return lhs == static_cast<int>(rhs); }
/** // doc: operator!= {{{
 * \todo Write documentation
 */ // }}}
constexpr bool operator!=(token_t lhs, int rhs)
{ return static_cast<int>(lhs) != rhs; }
/** // doc: operator!= {{{
 * \todo Write documentation
 */ // }}}
constexpr bool operator!=(int lhs, token_t rhs)
{ return lhs != static_cast<int>(rhs); }
/** // doc: operator< {{{
 * \todo Write documentation
 */ // }}}
constexpr bool operator<(token_t lhs, int rhs)
{ return static_cast<int>(lhs) < rhs; }
/** // doc: operator< {{{
 * \todo Write documentation
 */ // }}}
constexpr bool operator<(int lhs, token_t rhs)
{ return lhs < static_cast<int>(rhs); }
/** // doc: operator> {{{
 * \todo Write documentation
 */ // }}}
constexpr bool operator>(token_t lhs, int rhs)
{ return static_cast<int>(lhs) > rhs; }
/** // doc: operator> {{{
 * \todo Write documentation
 */ // }}}
constexpr bool operator>(int lhs, token_t rhs)
{ return lhs > static_cast<int>(rhs); }
/** // doc: operator<= {{{
 * \todo Write documentation
 */ // }}}
constexpr bool operator<=(token_t lhs, int rhs)
{ return static_cast<int>(lhs) <= rhs; }
/** // doc: operator<= {{{
 * \todo Write documentation
 */ // }}}
constexpr bool operator<=(int lhs, token_t rhs)
{ return lhs <= static_cast<int>(rhs); }
/** // doc: operator>= {{{
 * \todo Write documentation
 */ // }}}
constexpr bool operator>=(token_t lhs, int rhs)
{ return static_cast<int>(lhs) >= rhs; }
/** // doc: operator>= {{{
 * \todo Write documentation
 */ // }}}
constexpr bool operator>=(int lhs, token_t rhs)
{ return lhs >= static_cast<int>(rhs); }
/** @} */
} } // end namespace txpl::lexer

#endif /* TXPL_LEXER_TOKEN_T_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
