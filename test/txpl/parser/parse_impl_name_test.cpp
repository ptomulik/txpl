// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_parser_parse_impl_name

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_PARSER_PARSE_IMPL_NAME

#include <txpl/parser/parse_impl_name.hpp>
#include <txpl/lexer/token.hpp>

BOOST_AUTO_TEST_CASE(test__parse__name)
{
  using namespace txpl::parser;
  using namespace txpl;
  ast::name<lexer::token<> const*> n;
  {
    lexer::token<> tok;
    lexer::token<> const *first = &tok, *last = first;
    n.value = "xyz";
    BOOST_CHECK(!parse(first, last, n));
    BOOST_CHECK_EQUAL(n.value, "xyz");
    BOOST_CHECK(first == last);
  }
  {
    const char *beg = "word0", *end = beg + 5;
    lexer::token<> tok = lexer::token<>(lexer::token_t::word_, beg, end);
    lexer::token<> const* first = &tok, *last = first + 1;

    BOOST_CHECK(parse(first, last, n));
    BOOST_CHECK_EQUAL(n.value, "word0");
    BOOST_CHECK(first == last);
  }
  {
    const char *beg[]   = { "::" };
    const char *end[]   = { beg[0]+2  };
    lexer::token<> tok[]  = {
      lexer::token<>(lexer::token_t::nssep_, beg[0], end[0])
    };
    lexer::token<> const* first = tok, *last = first + 1;

    n.value = "xyz";
    BOOST_CHECK(!parse(first, last, n));
    BOOST_CHECK_EQUAL(n.value, "xyz");
    BOOST_CHECK(first == last);
  }
  {
    const char *beg[]   = { "::",     "word1" };
    const char *end[]   = { beg[0]+2, beg[1]+5 };
    lexer::token<> tok[]  = {
      lexer::token<>(lexer::token_t::nssep_, beg[0], end[0]),
      lexer::token<>(lexer::token_t::word_, beg[1], end[1])
    };
    lexer::token<> const* first = tok, *last = first + 2;

    BOOST_CHECK(parse(first, last, n));
    BOOST_CHECK_EQUAL(n.value, "::word1");
    BOOST_CHECK(first == last);
  }
  {
    const char *beg[]   = { "word0",  "::" };
    const char *end[]   = { beg[0]+5, beg[1]+2  };
    lexer::token<> tok[]  = {
      lexer::token<>(lexer::token_t::word_, beg[0], end[0]),
      lexer::token<>(lexer::token_t::nssep_, beg[1], end[1])
    };
    lexer::token<> const* first = tok, *last = first + 2;

    n.value = "xyz";
    BOOST_CHECK(!parse(first, last, n));
    BOOST_CHECK_EQUAL(n.value, "xyz");
    BOOST_CHECK(first == last);
  }
  {
    const char *beg[]   = { "word0",  "::",     "word1" };
    const char *end[]   = { beg[0]+5, beg[1]+2, beg[2]+5 };
    lexer::token<> tok[]  = {
      lexer::token<>(lexer::token_t::word_, beg[0], end[0]),
      lexer::token<>(lexer::token_t::nssep_, beg[1], end[1]),
      lexer::token<>(lexer::token_t::word_, beg[2], end[2])
    };
    lexer::token<> const* first = tok, *last = first + 3;

    BOOST_CHECK(parse(first, last, n));
    BOOST_CHECK_EQUAL(n.value, "word0::word1");
    BOOST_CHECK(first == last);
  }
  {
    const char *beg[]   = { "::",     "word1",  "::",     "word2" };
    const char *end[]   = { beg[0]+2, beg[1]+5, beg[2]+2, beg[3]+5 };
    lexer::token<> tok[]  = {
      lexer::token<>(lexer::token_t::nssep_, beg[0], end[0]),
      lexer::token<>(lexer::token_t::word_, beg[1], end[1]),
      lexer::token<>(lexer::token_t::nssep_, beg[2], end[2]),
      lexer::token<>(lexer::token_t::word_, beg[3], end[3])
    };
    lexer::token<> const* first = tok, *last = first + 4;

    BOOST_CHECK(parse(first, last, n));
    BOOST_CHECK_EQUAL(n.value, "::word1::word2");
    BOOST_CHECK(first == last);
  }
}

#else
BOOST_AUTO_TEST_CASE(dummy)
{
  BOOST_CHECK(true);
}
#endif
