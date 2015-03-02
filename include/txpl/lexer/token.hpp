// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/token.hpp

/** // doc: txpl/lexer/token.hpp {{{
 * \file txpl/lexer/token.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_LEXER_TOKEN_HPP_INCLUDED
#define TXPL_LEXER_TOKEN_HPP_INCLUDED

#include <txpl/lexer/token_t.hpp>

namespace txpl { namespace lexer {
/** \ingroup txpl_lexer
 * @{ */
/** // doc: token {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator = const char*>
struct token
{
  /** // doc: iterator_type {{{
   * \todo Write documentation
   */ // }}}
  typedef Iterator iterator_type;
  /** // doc: token() {{{
   * \todo Write documentation
   */ // }}}
  token()
    : id_(token_t::invalid_)
  { }
  /** // doc: token(id, begin, end) {{{
   * \todo Write documentation
   */ // }}}
  token(token_t id, Iterator const& begin, Iterator const& end)
    : id_(id), begin_(begin), end_(end)
  { }
  /** // doc: id() {{{
   * \todo Write documentation
   */ // }}}
  token_t id() const noexcept
  { return this->id_; }
  /** // doc: begin {{{
   * \todo Write documentation
   */ // }}}
  iterator_type const& begin() const noexcept
  { return this->begin_; }
  /** // doc: end {{{
   * \todo Write documentation
   */ // }}}
  iterator_type const& end() const noexcept
  { return this->end_; }
  /** // doc: is_valid() {{{
   * \todo Write documentation
   */ // }}}
  bool is_valid() const noexcept
  { return id_ != token_t::invalid_; }
  /** // doc: operator token_t() {{{
   * \todo Write documentation
   */ // }}}
  explicit operator token_t() const noexcept
  { return id_; }
private:
  token_t id_;
  iterator_type begin_;
  iterator_type end_;
};
/** // doc: operator== {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator1, typename Iterator2>
constexpr bool operator==(token<Iterator1> const& lhs, token<Iterator2> const& rhs)
{ return lhs.id() == rhs.id(); }
/** // doc: operator!= {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator1, typename Iterator2>
constexpr bool operator!=(token<Iterator1> const& lhs, token<Iterator2> const& rhs)
{ return lhs.id() != rhs.id(); }
/** // doc: operator< {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator1, typename Iterator2>
constexpr bool operator<(token<Iterator1> const& lhs, token<Iterator2> const& rhs)
{ return lhs.id() < rhs.id(); }
/** // doc: operator> {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator1, typename Iterator2>
constexpr bool operator>(token<Iterator1> const& lhs, token<Iterator2> const& rhs)
{ return lhs.id() > rhs.id(); }
/** // doc: operator<= {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator1, typename Iterator2>
constexpr bool operator<=(token<Iterator1> const& lhs, token<Iterator2> const& rhs)
{ return lhs.id() <= rhs.id(); }
/** // doc: operator>= {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator1, typename Iterator2>
constexpr bool operator>=(token<Iterator1> const& lhs, token<Iterator2> const& rhs)
{ return lhs.id() >= rhs.id(); }

/** // doc: operator== {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator>
constexpr bool operator==(token<Iterator> const& lhs, token_t rhs)
{ return lhs.id() == rhs; }
/** // doc: operator== {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator>
constexpr bool operator==(token_t lhs, token<Iterator> const& rhs)
{ return lhs == rhs.id(); }
/** // doc: operator!= {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator>
constexpr bool operator!=(token<Iterator> const& lhs, token_t rhs)
{ return lhs.id() != rhs; }
/** // doc: operator!= {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator>
constexpr bool operator!=(token_t lhs, token<Iterator> const& rhs)
{ return lhs != rhs.id(); }
/** // doc: operator< {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator>
constexpr bool operator<(token<Iterator> const& lhs, token_t rhs)
{ return lhs.id() < rhs; }
/** // doc: operator< {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator>
constexpr bool operator<(token_t lhs, token<Iterator> const& rhs)
{ return lhs < rhs.id(); }
/** // doc: operator> {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator>
constexpr bool operator>(token<Iterator> const& lhs, token_t rhs)
{ return lhs.id() > rhs; }
/** // doc: operator> {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator>
constexpr bool operator>(token_t lhs, token<Iterator> const& rhs)
{ return lhs > rhs.id(); }
/** // doc: operator<= {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator>
constexpr bool operator<=(token<Iterator> const& lhs, token_t rhs)
{ return lhs.id() <= rhs; }
/** // doc: operator<= {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator>
constexpr bool operator<=(token_t lhs, token<Iterator> const& rhs)
{ return lhs <= rhs.id(); }
/** // doc: operator>= {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator>
constexpr bool operator>=(token<Iterator> const& lhs, token_t rhs)
{ return lhs.id() >= rhs; }
/** // doc: operator>= {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator>
constexpr bool operator>=(token_t lhs, token<Iterator> const& rhs)
{ return lhs >= rhs.id(); }

/** // doc: operator== {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator>
constexpr bool operator==(token<Iterator> const& lhs, int rhs)
{ return lhs.id() == rhs; }
/** // doc: operator== {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator>
constexpr bool operator==(int lhs, token<Iterator> const& rhs)
{ return lhs == rhs.id(); }
/** // doc: operator!= {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator>
constexpr bool operator!=(token<Iterator> const& lhs, int rhs)
{ return lhs.id() != rhs; }
/** // doc: operator!= {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator>
constexpr bool operator!=(int lhs, token<Iterator> const& rhs)
{ return lhs != rhs.id(); }
/** // doc: operator< {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator>
constexpr bool operator<(token<Iterator> const& lhs, int rhs)
{ return lhs.id() < rhs; }
/** // doc: operator< {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator>
constexpr bool operator<(int lhs, token<Iterator> const& rhs)
{ return lhs < rhs.id(); }
/** // doc: operator> {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator>
constexpr bool operator>(token<Iterator> const& lhs, int rhs)
{ return lhs.id() > rhs; }
/** // doc: operator> {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator>
constexpr bool operator>(int lhs, token<Iterator> const& rhs)
{ return lhs > rhs.id(); }
/** // doc: operator<= {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator>
constexpr bool operator<=(token<Iterator> const& lhs, int rhs)
{ return lhs.id() <= rhs; }
/** // doc: operator<= {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator>
constexpr bool operator<=(int lhs, token<Iterator> const& rhs)
{ return lhs <= rhs.id(); }
/** // doc: operator>= {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator>
constexpr bool operator>=(token<Iterator> const& lhs, int rhs)
{ return lhs.id() >= rhs; }
/** // doc: operator>= {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator>
constexpr bool operator>=(int lhs, token<Iterator> const& rhs)
{ return lhs >= rhs.id(); }
/** @} */
} } // end namespace txpl::lexer

#endif /* TXPL_LEXER_TOKEN_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
