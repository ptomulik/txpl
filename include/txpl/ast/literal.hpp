// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/ast/literal.hpp

/** // doc: txpl/ast/literal.hpp {{{
 * \file txpl/ast/literal.hpp
 * \brief Defines \ref txpl::ast::literal "ast::literal<>"
 */ // }}}
#ifndef TXPL_AST_LITERAL_HPP_INCLUDED
#define TXPL_AST_LITERAL_HPP_INCLUDED

#include <txpl/ast/literal_fwd.hpp>
#include <txpl/ast/node.hpp>

namespace txpl { namespace ast {
/** \ingroup AstGroup
 * @{ */
template<typename Iterator, typename Value>
struct literal
  : node<Iterator>
{
  /** // doc: base_type {{{
   * \brief Type of the base class
   *
   * Same as \ref txpl::ast::node "ast::node<Iterator>"
   */ // }}}
  typedef node<Iterator> base_type;
  /** // doc: value_type {{{
   * \brief Same as the \e Value template parameter
   */ // }}}
  typedef Value value_type;
  /** // doc: value {{{
   * \brief Actual value of the parsed literal
   */ // }}}
  value_type value;
};
/** @} */
} } // end namespace ast

#endif /* TXPL_AST_LITERAL_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
