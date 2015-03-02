// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/parser/parse.hpp

/** // doc: txpl/parser/parse.hpp {{{
 * \file txpl/parser/parse.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_PARSER_PARSE_HPP_INCLUDED
#define TXPL_PARSER_PARSE_HPP_INCLUDED

#include <txpl/parser/parse_fwd.hpp>
#include <txpl/parser/parse_impl_fwd.hpp>
#include <txpl/util/fake_functor.hpp>

namespace txpl { namespace parser {
template<typename Iterator, typename Node, typename Ehandler>
bool parse(Iterator& first, Iterator const& last, Node& node, Ehandler f)
{
  Iterator beg = first;
  if(!parse_impl<Node>::apply(first, last, node, f)) return false;
  node.set_range(beg, first);
  return true;
}
template<typename Iterator, typename Node>
bool parse(Iterator& first, Iterator const& last, Node& node)
{ return parse(first, last, node, util::fake_functor<void>()); }
} } // end namespace txpl::parser

#include <txpl/parser/parse_impl.hpp>

#endif /* TXPL_PARSER_PARSE_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
