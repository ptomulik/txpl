// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_parser_parse_impl_expr0

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_PARSER_PARSE_IMPL_EXPR0

#include <txpl/parser/parse_impl_expr.hpp>
#include <txpl/lexer/token.hpp>
#include <txpl/lexer/token_t.hpp>
#include <txpl/ast/basic_types.hpp>
#include <txpl/ast/value.hpp>
#include <boost/variant/get.hpp>

BOOST_AUTO_TEST_CASE(test__parse__expr_0)
{
  using namespace txpl::parser;
  using namespace txpl;

  typedef lexer::token<> const* token_iterator;

  ast::expr<token_iterator, ast::value<>, 0> e;
  {
    lexer::token<> tok;
    lexer::token<> const *first = &tok, *last = first;
    BOOST_CHECK(!parse(first, last, e));
    BOOST_CHECK(first == last);
  }
}
BOOST_AUTO_TEST_CASE(test__parse__expr_0__literal)
{
  using namespace txpl::parser;
  using namespace txpl;
  using boost::get;

  typedef lexer::token<> const* token_iterator;

  ast::expr<token_iterator, ast::value<>, 0> e;
  ast::literal<token_iterator> l;
  {
    typedef ast::basic_types<>::real_type real_type;
    const char *beg[] = { ".123" };
    const char *end[] = { beg[0]+4 };
    lexer::token<> tok[] = {
      lexer::token<>(lexer::token_t::real_, beg[0], end[0])
    };
    lexer::token<> const* first = tok, *last = first + 1;

    real_type x = real_type{.456};

    BOOST_CHECK(parse(first, last, e));
    BOOST_CHECK_NO_THROW(l = get<ast::literal<token_iterator> >(e.expr));
    BOOST_CHECK_NO_THROW(x = get<real_type>(l.value));
    BOOST_CHECK_EQUAL(x, real_type{.123});
  }
  {
    typedef ast::basic_types<>::bool_type bool_type;
    const char *beg[] = { "true" };
    const char *end[] = { beg[0]+4 };
    lexer::token<> tok[] = {
      lexer::token<>(lexer::token_t::word_, beg[0], end[0])
    };
    lexer::token<> const* first = tok, *last = first + 1;

    bool_type x = bool_type{false};

    BOOST_CHECK(parse(first, last, e));
    BOOST_CHECK_NO_THROW(l = get<ast::literal<token_iterator> >(e.expr));
    BOOST_CHECK_NO_THROW(x = get<bool_type>(l.value));
    BOOST_CHECK_EQUAL(x, bool_type{true});
  }
  {
    typedef ast::basic_types<>::bool_type bool_type;
    const char *beg[] = { "false" };
    const char *end[] = { beg[0]+5 };
    lexer::token<> tok[] = {
      lexer::token<>(lexer::token_t::word_, beg[0], end[0])
    };
    lexer::token<> const* first = tok, *last = first + 1;

    bool_type x = bool_type{true};

    BOOST_CHECK(parse(first, last, e));
    BOOST_CHECK_NO_THROW(l = get<ast::literal<token_iterator> >(e.expr));
    BOOST_CHECK_NO_THROW(x = get<bool_type>(l.value));
    BOOST_CHECK_EQUAL(x, bool_type{false});
  }
}

#else
BOOST_AUTO_TEST_CASE(dummy)
{
  BOOST_CHECK(true);
}
#endif
