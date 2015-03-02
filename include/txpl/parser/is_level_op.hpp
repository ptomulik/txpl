// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/parser/is_level_op.hpp

/** // doc: txpl/parser/is_level_op.hpp {{{
 * \file txpl/parser/is_level_op.hpp
 * \brief Implements \ref txpl::parser::is_level_op() "lexer::is_level_op()"
 */ // }}}
#ifndef TXPL_PARSER_IS_LEVEL_OP_HPP_INCLUDED
#define TXPL_PARSER_IS_LEVEL_OP_HPP_INCLUDED

#include <txpl/vm/op_t.hpp>

namespace txpl { namespace parser {
/** \ingroup ParserGroup
 * @{ */
/** // doc: is_level_op() {{{
 * \brief Checks whether operation \e op is a level \e N operation
 *
 * \tparam N the level for which we expect the operator \e op works.
 *
 * \param op operator identifier, see \ref txpl::vm::op_t "vm::op_t",
 * \returns `true` if the operator is a level-N operation or `false` otherwise.
 *
 * \par Description
 *
 * This function is used  to determine whether the operator \e op appears in
 * the specificaiton of a level-N operation. This is strictly related
 * to the \ref ExpressionSyntaxParserRules "expression syntax" where
 * expressions have assigned level numbers according to their precedence.
 * For example, the production rule for the level-14 expression is
 *
 * \e expr14 := \e expr13 (<tt>'||'</tt> \e expr13)*
 *
 * The subexpression (<tt>'||'</tt> \e expr13) is called a level-13 operation
 * in our terminology. As it's seen it accepts only a logical \e or operator
 * `||`, so in this case we have:
 *
 * \code
 *  parser::is_level_op<13ul>(vm::op_t::or_) == true
 * \endcode
 *
 * and
 *
 * \code
 *  parser::is_level_op<13ul>(op) == false
 * \endcode
 *
 * for all other values of \e op.
 */ // }}}
template<size_t N>
bool is_level_op(vm::op_t op) noexcept;
/** // doc: is_level_op<14>() {{{
 * \brief Specialization of the \ref txpl::parser::is_level_op()
 *        "parser::is_level_op()" for level 14.
 */ // }}}
template<>
inline bool is_level_op<14ul>(vm::op_t t) noexcept
{ return t == vm::op_t::qmark_; }
/** // doc: is_level_op<13>() {{{
 * \brief Specialization of the \ref txpl::parser::is_level_op()
 *        "parser::is_level_op()" for level 13.
 */ // }}}
template<>
inline bool is_level_op<13ul>(vm::op_t t) noexcept
{ return t == vm::op_t::or_; }
/** // doc: is_level_op<12>() {{{
 * \brief Specialization of the \ref txpl::parser::is_level_op()
 *        "parser::is_level_op()" for level 12.
 */ // }}}
template<>
inline bool is_level_op<12ul>(vm::op_t t) noexcept
{ return t == vm::op_t::and_; }
/** // doc: is_level_op<11>() {{{
 * \brief Specialization of the \ref txpl::parser::is_level_op()
 *        "parser::is_level_op()" for level 11.
 */ // }}}
template<>
inline bool is_level_op<11ul>(vm::op_t t) noexcept
{ return t == vm::op_t::bitor_; }
/** // doc: is_level_op<10>() {{{
 * \brief Specialization of the \ref txpl::parser::is_level_op()
 *        "parser::is_level_op()" for level 10.
 */ // }}}
template<>
inline bool is_level_op<10ul>(vm::op_t t) noexcept
{ return t == vm::op_t::xor_; }
/** // doc: is_level_op<9>() {{{
 * \brief Specialization of the \ref txpl::parser::is_level_op()
 *        "parser::is_level_op()" for level 9.
 */ // }}}
template<>
inline bool is_level_op<9ul>(vm::op_t t) noexcept
{ return t == vm::op_t::bitand_; }
/** // doc: is_level_op<8>() {{{
 * \brief Specialization of the \ref txpl::parser::is_level_op()
 *        "parser::is_level_op()" for level 8.
 */ // }}}
template<>
inline bool is_level_op<8ul>(vm::op_t t) noexcept
{
  return t == vm::op_t::eq_ || t == vm::op_t::neq_ ||
         t == vm::op_t::match_ || t == vm::op_t::nmatch_;
}
/** // doc: is_level_op<7>() {{{
 * \brief Specialization of the \ref txpl::parser::is_level_op()
 *        "parser::is_level_op()" for level 7.
 */ // }}}
template<>
inline bool is_level_op<7ul>(vm::op_t t) noexcept
{
  return t == vm::op_t::lt_ || t == vm::op_t::le_ ||
         t == vm::op_t::gt_ || t == vm::op_t::ge_;
}
/** // doc: is_level_op<6>() {{{
 * \brief Specialization of the \ref txpl::parser::is_level_op()
 *        "parser::is_level_op()" for level 6.
 */ // }}}
template<>
inline bool is_level_op<6ul>(vm::op_t t) noexcept
{ return t == vm::op_t::lshift_ || t == vm::op_t::rshift_; }
/** // doc: is_level_op<5>() {{{
 * \brief Specialization of the \ref txpl::parser::is_level_op()
 *        "parser::is_level_op()" for level 5.
 */ // }}}
template<>
inline bool is_level_op<5ul>(vm::op_t t) noexcept
{ return t == vm::op_t::plus_ || t == vm::op_t::minus_; }
/** // doc: is_level_op<3>() {{{
 * \brief Specialization of the \ref txpl::parser::is_level_op()
 *        "parser::is_level_op()" for level 3.
 */ // }}}
template<>
inline bool is_level_op<3ul>(vm::op_t t) noexcept
{ return t == vm::op_t::mul_ || t == vm::op_t::div_ || t == vm::op_t::mod_; }
/** // doc: is_level_op<1>() {{{
 * \brief Specialization of the \ref txpl::parser::is_level_op()
 *        "parser::is_level_op()" for level 1.
 */ // }}}
template<>
inline bool is_level_op<1ul>(vm::op_t t) noexcept
{ return t == vm::op_t::subscript_; }
/** @} */
} } // end namespace txpl::parser

#endif /* TXPL_PARSER_IS_LEVEL_OP_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
