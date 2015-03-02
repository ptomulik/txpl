// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/ast/nodes_fwd.hpp

/** // doc: txpl/ast/nodes_fwd.hpp {{{
 * \file txpl/ast/nodes_fwd.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_AST_NODES_FWD_HPP_INCLUDED
#define TXPL_AST_NODES_FWD_HPP_INCLUDED

#include <txpl/vm/basic_types.hpp>

// NOTE: AST stands for Abstract Syntax Tree

namespace txpl { namespace ast {
/** // doc: expr {{{
 * \todo Write documentation
 */ // }}}
template <
    typename Iterator
  , typename BasicTypes = vm::basic_types<>
  , size_t Level = 15
> struct expr;
/** // doc: operation {{{
 * \todo Write documentation
 */ // }}}
template <
    typename Iterator
  , typename BasicTypes = vm::basic_types<>
  , size_t Level = 14
> struct operation;
/** // doc: name {{{
 * \todo Write documentation
 */ // }}}
template<
    typename Iterator
  , typename BasicTypes = vm::basic_types<>
> struct name;
/** // doc: literal {{{
 * \todo Write documentation
 */ // }}}
template<
    typename Iterator
  , typename BasicTypes = vm::basic_types<>
> struct literal;
/** // doc: braced_expr {{{
 * \todo Write documentation
 */ // }}}
template<
    typename Iterator
  , typename BasicTypes = vm::basic_types<>
> struct braced_expr;
/** // doc: unary_expr {{{
 * \todo Write documentation
 */ // }}}
template<
    typename Iterator
  , typename BasicTypes = vm::basic_types<>
> struct unary_expr;
} } // end namespace ast

#endif /* TXPL_AST_NODES_FWD_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
