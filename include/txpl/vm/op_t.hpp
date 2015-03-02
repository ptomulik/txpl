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
#ifndef TXPL_VM_OP_T_HPP
#define TXPL_VM_OP_T_HPP

namespace txpl { namespace vm {
/** // doc: op_t {{{
 * \todo Write documentation
 */ // }}}
enum class op_t : int
{
  /** // doc: invalid {{{
   * \todo Write documentation
   */ // }}}
  invalid_ = 0,
  /** // doc: plus {{{
   * \todo Write documentation
   */ // }}}
  plus_   = int{'+'},
  /** // doc: minus_ {{{
   * \todo Write documentation
   */ // }}}
  minus_  = int{'-'},
  /** // doc: mul_ {{{
   * \todo Write documentation
   */ // }}}
  mul_    = int{'*'},
  /** // doc: div_ {{{
   * \todo Write documentation
   */ // }}}
  div_    = int{'/'},
  /** // doc: mod_ {{{
   * \todo Write documentation
   */ // }}}
  mod_    = int{'%'},
  /** // doc: xor_ {{{
   * \todo Write documentation
   */ // }}}
  xor_    = int{'^'},
  /** // doc: bitand_ {{{
   * \todo Write documentation
   */ // }}}
  bitand_ = int{'&'},
  /** // doc: bitor_ {{{
   * \todo Write documentation
   */ // }}}
  bitor_  = int{'|'},
  /** // doc: lt_ {{{
   * \todo Write documentation
   */ // }}}
  lt_     = int{'<'},
  /** // doc: gt_ {{{
   * \todo Write documentation
   */ // }}}
  gt_     = int{'>'},
  /** // doc: not_ {{{
   * \todo Write documentation
   */ // }}}
  not_    = int{'!'},
  /** // doc: neg_ {{{
   * \todo Write documentation
   */ // }}}
  neg_    = int{'~'},
  /** // doc: comma_ {{{
   * \todo Write documentation
   */ // }}}
  comma_  = int{','},
  /** // doc: dot_ {{{
   * \todo Write documentation
   */ // }}}
  dot_    = int{'.'},
  /** // doc: qmark_ {{{
   * \todo Write documentation
   */ // }}}
  qmark_  = int{'?'},

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
};

/** // doc: operator== {{{
 * \todo Write documentation
 */ // }}}
constexpr bool operator==(op_t lhs, int rhs)
{ return static_cast<int>(lhs) == rhs; }
/** // doc: operator== {{{
 * \todo Write documentation
 */ // }}}
constexpr bool operator==(int lhs, op_t rhs)
{ return lhs == static_cast<int>(rhs); }
/** // doc: operator!= {{{
 * \todo Write documentation
 */ // }}}
constexpr bool operator!=(op_t lhs, int rhs)
{ return static_cast<int>(lhs) != rhs; }
/** // doc: operator!= {{{
 * \todo Write documentation
 */ // }}}
constexpr bool operator!=(int lhs, op_t rhs)
{ return lhs != static_cast<int>(rhs); }
/** // doc: operator< {{{
 * \todo Write documentation
 */ // }}}
constexpr bool operator<(op_t lhs, int rhs)
{ return static_cast<int>(lhs) < rhs; }
/** // doc: operator< {{{
 * \todo Write documentation
 */ // }}}
constexpr bool operator<(int lhs, op_t rhs)
{ return lhs < static_cast<int>(rhs); }
/** // doc: operator> {{{
 * \todo Write documentation
 */ // }}}
constexpr bool operator>(op_t lhs, int rhs)
{ return static_cast<int>(lhs) > rhs; }
/** // doc: operator> {{{
 * \todo Write documentation
 */ // }}}
constexpr bool operator>(int lhs, op_t rhs)
{ return lhs > static_cast<int>(rhs); }
/** // doc: operator<= {{{
 * \todo Write documentation
 */ // }}}
constexpr bool operator<=(op_t lhs, int rhs)
{ return static_cast<int>(lhs) <= rhs; }
/** // doc: operator<= {{{
 * \todo Write documentation
 */ // }}}
constexpr bool operator<=(int lhs, op_t rhs)
{ return lhs <= static_cast<int>(rhs); }
/** // doc: operator>= {{{
 * \todo Write documentation
 */ // }}}
constexpr bool operator>=(op_t lhs, int rhs)
{ return static_cast<int>(lhs) >= rhs; }
/** // doc: operator>= {{{
 * \todo Write documentation
 */ // }}}
constexpr bool operator>=(int lhs, op_t rhs)
{ return lhs >= static_cast<int>(rhs); }
} } // end namespace txpl::vm

#endif /* TXPL_VM_OP_T_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
