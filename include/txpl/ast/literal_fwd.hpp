// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/ast/literal_fwd.hpp

/** // doc: txpl/ast/literal_fwd.hpp {{{
 * \file txpl/ast/literal_fwd.hpp
 * \brief Forward declaration of \ref txpl::ast::literal "literal<>"
 */ // }}}
#ifndef TXPL_AST_LITERAL_FWD_HPP_INCLUDED
#define TXPL_AST_LITERAL_FWD_HPP_INCLUDED

#include <txpl/ast/value.hpp>

namespace txpl { namespace ast {
/** // doc: literal {{{
 * \ingroup AstGroup
 * \brief AST node used to represent literals
 *
 * \tparam Iterator token iterator type used,
 * \tparam Value value type used to represent the actual value of the literal
 *
 * This node type is used to represent parsed \ref ExpressionSyntaxParserRules
 * "literal".
 */ // }}}
template<typename Iterator, typename Value = value<> > struct literal;
} } // end namespace ast

#endif /* TXPL_AST_LITERAL_FWD_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
