// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/ast/symbol.hpp

/** // doc: txpl/ast/symbol.hpp {{{
 * \file txpl/ast/symbol.hpp
 * \brief Defines \ref txpl::ast::symbol "ast::symbol<>"
 */ // }}}
#ifndef TXPL_AST_SYMBOL_HPP_INCLUDED
#define TXPL_AST_SYMBOL_HPP_INCLUDED

#include <txpl/ast/symbol_fwd.hpp>
#include <txpl/ast/node.hpp>

namespace txpl { namespace ast {
template<typename Iterator>
struct symbol
  : node<Iterator>
{
  /** // doc: base_type {{{
   * \brief Type of the base class
   *
   * Same as \ref txpl::ast::node "ast::node<Iterator>"
   */ // }}}
  typedef node<Iterator> base_type;
  /** // doc: name_type {{{
   * \brief String type used to represent the symbol name
   */ // }}}
  typedef typename std::string name_type;
  /** // doc: name {{{
   * \brief Symbol name
   */ // }}}
  name_type name;
};
} } // end namespace ast

#endif /* TXPL_AST_SYMBOL_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
