// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/parser/parse_fwd.hpp

/** // doc: txpl/parser/parse_fwd.hpp {{{
 * \file txpl/parser/parse_fwd.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_PARSER_PARSE_FWD_HPP_INCLUDED
#define TXPL_PARSER_PARSE_FWD_HPP_INCLUDED

namespace txpl { namespace parser {
/** // doc: parse() {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename Node, typename Ehandler>
bool parse(Iterator& first, Iterator const& last, Node& node, Ehandler const& eh);
/** // doc: parse() {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename Node, typename Ehandler>
bool parse(Iterator& first, Iterator const& last, Node& node, Ehandler& eh);
/** // doc: parse() {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename Node>
bool parse(Iterator& first, Iterator const& last, Node& node);
} } // end namespace txpl::parser

#endif /* TXPL_PARSER_PARSE_FWD_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
