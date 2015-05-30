// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/ast/expr3.hpp

/** // doc: txpl/ast/expr3.hpp {{{
 * \file txpl/ast/expr3.hpp
 * \brief Defines \ref txpl::ast::expr "ast::expr<0>"
 */ // }}}
#ifndef TXPL_AST_EXPR3_HPP_INCLUDED
#define TXPL_AST_EXPR3_HPP_INCLUDED

#include <txpl/ast/expr_fwd.hpp>
#include <txpl/ast/braced_expr.hpp>
#include <txpl/ast/expr.hpp>
#include <txpl/ast/node.hpp>
#include <txpl/ast/unary_expr.hpp>
#include <yaul/variant/recursive_variant.hpp>

namespace txpl { namespace ast {
/** \ingroup AstGroup
 * @{ */
/** // doc: expr<3> {{{
 * \brief Specializes the \ref txpl::ast::expr "ast::expr<>" for \e Level == 3
 */ // }}}
template<typename Iterator, typename Value>
struct expr<Iterator, Value, 3ul>
  : node<Iterator>
{
  /** // doc: base_type {{{
   * \brief Typedef for the base class
   *
   * Same as \ref txpl::ast::node "ast::node<Iterator>"
   */ // }}}
  typedef node<Iterator> base_type;
  /** // doc:expr_type {{{
   * \brief Variant type used to represent the actual expression that was
   *        recognized by \ref ExpressionSyntaxParserRules "expr3" rule
   */ // }}}
  typedef yaul::variant<
    yaul::recursive_wrapper<unary_expr<Iterator, Value> >
  , yaul::recursive_wrapper<expr<Iterator, Value, 2ul> >
  > expr_type;
  /** doc: expr {{{
   * \brief Variant value used to store the actual AST node that was
   *        recognized by \ref ExpressionSyntaxParserRules "expr3" rule
   */ // }}}
  expr_type expr;
  /** // doc: level {{{
   * \brief Expression level, equals 3 for this specialization
   */ // }}}
  constexpr static size_t level = 3;
};
/** @} */
} } // end namespace ast

#endif /* TXPL_AST_EXPR3_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
