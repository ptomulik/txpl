// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/parser/is_level_op.hpp

/** // doc: txpl/parser/is_level_op.hpp {{{
 * \file txpl/parser/is_level_op.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_PARSER_IS_LEVEL_OP_HPP_INCLUDED
#define TXPL_PARSER_IS_LEVEL_OP_HPP_INCLUDED

#include <txpl/vm/op_t.hpp>

namespace txpl { namespace parser {
/** // doc: is_level_op() {{{
 * \todo Write documentation
 */ // }}}
template<size_t Level>
bool is_level_op(vm::op_t) noexcept;
/** // doc: is_level_op<14>() {{{
 * \todo Write documentation
 */ // }}}
template<>
inline bool is_level_op<14ul>(vm::op_t t) noexcept
{ return t == vm::op_t::qmark_; }
/** // doc: is_level_op<13>() {{{
 * \todo Write documentation
 */ // }}}
template<>
inline bool is_level_op<13ul>(vm::op_t t) noexcept
{ return t == vm::op_t::or_; }
/** // doc: is_level_op<12>() {{{
 * \todo Write documentation
 */ // }}}
template<>
inline bool is_level_op<12ul>(vm::op_t t) noexcept
{ return t == vm::op_t::and_; }
/** // doc: is_level_op<11>() {{{
 * \todo Write documentation
 */ // }}}
template<>
inline bool is_level_op<11ul>(vm::op_t t) noexcept
{ return t == vm::op_t::bitor_; }
/** // doc: is_level_op<10>() {{{
 * \todo Write documentation
 */ // }}}
template<>
inline bool is_level_op<10ul>(vm::op_t t) noexcept
{ return t == vm::op_t::xor_; }
/** // doc: is_level_op<9>() {{{
 * \todo Write documentation
 */ // }}}
template<>
inline bool is_level_op<9ul>(vm::op_t t) noexcept
{ return t == vm::op_t::bitand_; }
/** // doc: is_level_op<8>() {{{
 * \todo Write documentation
 */ // }}}
template<>
inline bool is_level_op<8ul>(vm::op_t t) noexcept
{
  return t == vm::op_t::eq_ || t == vm::op_t::neq_ ||
         t == vm::op_t::match_ || t == vm::op_t::nmatch_;
}
/** // doc: is_level_op<7>() {{{
 * \todo Write documentation
 */ // }}}
template<>
inline bool is_level_op<7ul>(vm::op_t t) noexcept
{
  return t == vm::op_t::lt_ || t == vm::op_t::le_ ||
         t == vm::op_t::gt_ || t == vm::op_t::ge_;
}
/** // doc: is_level_op<6>() {{{
 * \todo Write documentation
 */ // }}}
template<>
inline bool is_level_op<6ul>(vm::op_t t) noexcept
{ return t == vm::op_t::lshift_ || t == vm::op_t::rshift_; }
/** // doc: is_level_op<5>() {{{
 * \todo Write documentation
 */ // }}}
template<>
inline bool is_level_op<5ul>(vm::op_t t) noexcept
{ return t == vm::op_t::plus_ || t == vm::op_t::minus_; }
/** // doc: is_level_op<0>() {{{
 * \todo Write documentation
 */ // }}}
template<>
inline bool is_level_op<0ul>(vm::op_t t) noexcept
{ return t == vm::op_t::mul_ || t == vm::op_t::div_ || t == vm::op_t::mod_; }
} } // end namespace txpl::parser

#endif /* TXPL_PARSER_IS_LEVEL_OP_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
