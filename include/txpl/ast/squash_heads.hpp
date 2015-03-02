// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/ast/squash_heads.hpp

/** // doc: txpl/ast/squash_heads.hpp {{{
 * \file txpl/ast/squash_heads.hpp
 * \brief Implements \ref txpl::ast::squash_heads() "ast::squash_heads()"
 */ // }}}
#ifndef TXPL_AST_SQUASH_HEADS_HPP_INCLUDED
#define TXPL_AST_SQUASH_HEADS_HPP_INCLUDED

#include <txpl/ast/nodes.hpp>
#include <boost/variant/get.hpp>

namespace txpl { namespace ast {
/** // doc: squash_heads() {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename Value>
static typename ast::expr<Iterator, Value, 0ul>::expr_type const&
squash_heads(ast::expr<Iterator, Value, 0ul> const& x)
{ return x.expr; }
/** // doc: squash_heads() {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename Value>
static typename ast::expr<Iterator, Value, 0ul>::expr_type&
squash_heads(ast::expr<Iterator, Value, 0ul>& x)
{ return x.expr; }
/** // doc: squash_heads() {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename Value>
static typename ast::expr<Iterator, Value, 0ul>::expr_type const&
squash_heads(ast::expr<Iterator, Value, 3ul> const& x)
{
  expr<Iterator, Value, 2ul>* expr2 = boost::get<expr<Iterator, Value, 2ul> >(&x.expr);
  if(expr2)
    return squash_heads(*expr2);
  else
    return squash_heads(boost::get<unary_expr<Iterator, Value> >(x.expr));
}
/** // doc: squash_heads() {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename Value>
static typename ast::expr<Iterator, Value, 0ul>::expr_type&
squash_heads(ast::expr<Iterator, Value, 3ul>& x)
{
  expr<Iterator, Value, 2ul>* expr2 = boost::get<expr<Iterator, Value, 2ul> >(&x.expr);
  if(expr2)
    return squash_heads(*expr2);
  else
    return squash_heads(boost::get<unary_expr<Iterator, Value> >(x.expr).expr);
}
/** // doc: squash_heads() {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename Value, size_t Level>
static typename ast::expr<Iterator, Value, 0ul>::expr_type const&
squash_heads(ast::expr<Iterator, Value, Level> const& x)
{ return squash_heads(x.head); }
/** // doc: squash_heads() {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename Value, size_t Level>
static typename ast::expr<Iterator, Value, 0ul>::expr_type&
squash_heads(ast::expr<Iterator, Value, Level>& x)
{ return squash_heads(x.head); }
} } // end namespace txpl::ast

#endif /* TXPL_AST_SQUASH_HEADS_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
