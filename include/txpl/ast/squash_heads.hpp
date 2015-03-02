// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/ast/squash_heads.hpp

/** // doc: txpl/ast/squash_heads.hpp {{{
 * \file txpl/ast/squash_heads.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_AST_SQUASH_HEADS_HPP_INCLUDED
#define TXPL_AST_SQUASH_HEADS_HPP_INCLUDED

#include <txpl/ast/nodes.hpp>

namespace txpl { namespace ast {
/** // doc: squash_heads() {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename BasicTypes>
static typename ast::expr<Iterator, BasicTypes, 0ul>::attrib_type const&
squash_heads(ast::expr<Iterator, BasicTypes, 0ul> const& x)
{ return x.attrib; }
/** // doc: squash_heads() {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename BasicTypes>
static typename ast::expr<Iterator, BasicTypes, 0ul>::attrib_type&
squash_heads(ast::expr<Iterator, BasicTypes, 0ul>& x)
{ return x.attrib; }
/** // doc: squash_heads() {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename BasicTypes, size_t Level>
static typename ast::expr<Iterator, BasicTypes, 0ul>::attrib_type const&
squash_heads(ast::expr<Iterator, BasicTypes, Level> const& x)
{ return squash_heads(x.head); }
/** // doc: squash_heads() {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename BasicTypes, size_t Level>
static typename ast::expr<Iterator, BasicTypes, 0ul>::attrib_type&
squash_heads(ast::expr<Iterator, BasicTypes, Level>& x)
{ return squash_heads(x.head); }
} } // end namespace txpl::ast

#endif /* TXPL_AST_SQUASH_HEADS_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
