// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/ast/symbol_fwd.hpp

/** // doc: txpl/ast/symbol_fwd.hpp {{{
 * \file txpl/ast/symbol_fwd.hpp
 * \brief Forward declaration of \ref txpl::ast::symbol "ast::symbol<>"
 */ // }}}
#ifndef TXPL_AST_SYMBOL_FWD_HPP_INCLUDED
#define TXPL_AST_SYMBOL_FWD_HPP_INCLUDED

namespace txpl { namespace ast {
/** // doc: symbol {{{
 * \ingroup AstGroup
 * \brief AST node used to represent a \ref ExpressionSyntaxParserRules "symbol"
 *
 * \tparam Iterator token iterator type used
 *
 * This type is used to represent a parsed expression described by the
 * production rule \ref ExpressionSyntaxParserRUles "symbol"
 */ // }}}
template<typename Iterator> struct symbol;
} } // end namespace ast

#endif /* TXPL_AST_SYMBOL_FWD_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
