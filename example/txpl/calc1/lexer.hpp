// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/calc1/lexer.hpp

/** // doc: txpl/calc1/lexer.hpp {{{
 * \file txpl/calc1/lexer.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_CALC1_LEXER_HPP
#define TXPL_CALC1_LEXER_HPP

#include <txpl/lexer/token.hpp>
#include <list>
#include <string>

namespace txpl { namespace calc1 {

typedef lexer::token<std::string::const_iterator> token_type;
typedef std::list<token_type>                     token_list;
typedef token_list::const_iterator                token_iter;

struct ehandler;
bool tokenize(token_list&, std::string const&, ehandler);

} } // end namespace txpl::calc1

#endif /* TXPL_CALC1_LEXER_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
