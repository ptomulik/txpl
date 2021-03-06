// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_parser_parse_impl_expr13

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_PARSER_PARSE_IMPL_EXPR13

#include <txpl/parser/parse_impl_expr.hpp>
#include <txpl/lexer/token.hpp>
#include <txpl/lexer/token_t.hpp>
#include <txpl/ast/basic_types.hpp>
#include <txpl/ast/value.hpp>
#include <txpl/ast/squash_heads.hpp>
#include <boost/variant/get.hpp>

BOOST_AUTO_TEST_CASE(test__parse__expr_13__literal__op__literal)
{
  using namespace txpl::parser;
  using namespace txpl;
  using boost::get;

  typedef lexer::token<> const* token_iterator;

  ast::expr<token_iterator, ast::value<>, 13> e;
  ast::literal<token_iterator> l1;
  ast::literal<token_iterator> l2;
  {
    typedef ast::basic_types<>::int_type int_type;
    const char *beg[] = { "456",    "&&",      "123" };
    const char *end[] = { beg[0]+3, beg[1]+2, beg[2]+3 };
    lexer::token<> tok[] = {
      lexer::token<>(lexer::token_t::int_, beg[0], end[0]),
      lexer::token<>(lexer::token_t::and_, beg[1], end[1]),
      lexer::token<>(lexer::token_t::int_, beg[2], end[2])
    };
    lexer::token<> const* first = tok, *last = first + 3;

    int_type x1 = int_type{654};
    int_type x2 = int_type{654};

    BOOST_CHECK(parse(first, last, e));
    BOOST_CHECK_NO_THROW(l1 = get<ast::literal<token_iterator> >(ast::squash_heads(e.head)));
    BOOST_CHECK_NO_THROW(l2 = get<ast::literal<token_iterator> >(ast::squash_heads(e.tail.front().expr)));
    BOOST_CHECK_NO_THROW(x1 = get<int_type>(l1.value));
    BOOST_CHECK_NO_THROW(x2 = get<int_type>(l2.value));
    BOOST_CHECK(e.tail.front().operator_ == vm::op_t::and_);
    BOOST_CHECK_EQUAL(x1, int_type{456});
    BOOST_CHECK_EQUAL(x2, int_type{123});
    BOOST_CHECK(first == last);
  }
}

#else
BOOST_AUTO_TEST_CASE(dummy)
{
  BOOST_CHECK(true);
}
#endif
