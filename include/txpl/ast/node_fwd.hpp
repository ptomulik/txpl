// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/ast/node_fwd.hpp

/** // doc: txpl/ast/node_fwd.hpp {{{
 * \file txpl/ast/node_fwd.hpp
 * \brief Forward declaration of \ref txpl::ast::node "ast::node<>"
 */ // }}}
#ifndef TXPL_AST_NODE_FWD_HPP
#define TXPL_AST_NODE_FWD_HPP

namespace txpl { namespace ast {
/** // doc: node {{{
 * \brief Base class for all the AST nodes
 *
 * \tparam Iterator type of token iterator; \e Iterators are stored in node
 *         to mark the positions of subexpressions represented by given nodes.
 */ // }}}
template<typename Iterator> struct node;
} } // end txpl::ast

#endif /* TXPL_AST_NODE_FWD_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
