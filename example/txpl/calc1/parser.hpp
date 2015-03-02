// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/calc1/parser.hpp

/** // doc: txpl/calc1/parser.hpp {{{
 * \file txpl/calc1/parser.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_CALC1_PARSER_HPP
#define TXPL_CALC1_PARSER_HPP

#include <txpl/ast/expr_fwd.hpp>
#include <txpl/calc1/lexer.hpp>
#include <txpl/calc1/ehandler.hpp>

namespace txpl { namespace calc1 {
bool parse(ast::expr<token_iter>&, token_list const&, ehandler);
} } // end namespace txpl::calc1

#endif /* TXPL_CALC1_PARSER_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
