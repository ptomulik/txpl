// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_parser_parse_impl_literal

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_PARSER_PARSE_IMPL_LITERAL

#include <txpl/parser/parse_impl_literal.hpp>
#include <txpl/vm/basic_types.hpp>
#include <txpl/lexer/token.hpp>

BOOST_AUTO_TEST_CASE(test__parse_impl_literal)
{
  using namespace txpl::parser;
  using namespace txpl;
  using boost::get;

  ast::literal<lexer::token<> const*> l;
  {
    lexer::token<> tok;
    lexer::token<> const *first = &tok, *last = first;
    BOOST_CHECK(!parse(first, last, l));
    BOOST_CHECK(first == last);
  }
  {
    const char *beg = "::", *end = beg + 2;
    lexer::token<> tok = lexer::token<>(lexer::token_t::nssep_, beg, end);
    lexer::token<> const* first = &tok, *last = first + 1;

    BOOST_CHECK(!parse(first, last, l));
    BOOST_CHECK((first+1) == last);
  }
  {
    typedef vm::basic_types<>::char_type char_type;
    const char *beg = "'a'", *end = beg + 3;
    lexer::token<> tok = lexer::token<>(lexer::token_t::qchar_, beg, end);
    lexer::token<> const* first = &tok, *last = first + 1;

    char_type x = char_type{'z'};

    BOOST_CHECK(parse(first, last, l));
    BOOST_CHECK_NO_THROW(x = get<char_type>(l.value));
    BOOST_CHECK_EQUAL(x, char_type{'a'});
    BOOST_CHECK(first == last);
  }
  {
    typedef vm::basic_types<>::int_type int_type;
    const char *beg = "123", *end = beg + 3;
    lexer::token<> tok = lexer::token<>(lexer::token_t::int_, beg, end);
    lexer::token<> const* first = &tok, *last = first + 1;

    int_type x = int_type{456};

    BOOST_CHECK(parse(first, last, l));
    BOOST_CHECK_NO_THROW(x = get<int_type>(l.value));
    BOOST_CHECK_EQUAL(x, int_type{123});
    BOOST_CHECK(first == last);
  }
  {
    typedef vm::basic_types<>::bool_type bool_type;
    const char *beg = "true", *end = beg + 4;
    lexer::token<> tok = lexer::token<>(lexer::token_t::word_, beg, end);
    lexer::token<> const* first = &tok, *last = first + 1;

    bool_type x = bool_type{false};

    BOOST_CHECK(parse(first, last, l));
    BOOST_CHECK_NO_THROW(x = get<bool_type>(l.value));
    BOOST_CHECK_EQUAL(x, bool_type{true});
    BOOST_CHECK(first == last);
  }
  {
    typedef vm::basic_types<>::bool_type bool_type;
    const char *beg = "false", *end = beg + 5;
    lexer::token<> tok = lexer::token<>(lexer::token_t::word_, beg, end);
    lexer::token<> const* first = &tok, *last = first + 1;

    bool_type x = bool_type{true};

    BOOST_CHECK(parse(first, last, l));
    BOOST_CHECK_NO_THROW(x = get<bool_type>(l.value));
    BOOST_CHECK_EQUAL(x, bool_type{false});
    BOOST_CHECK(first == last);
  }
  {
    typedef vm::basic_types<>::real_type real_type;
    const char *beg = ".123", *end = beg + 4;
    lexer::token<> tok = lexer::token<>(lexer::token_t::real_, beg, end);
    lexer::token<> const* first = &tok, *last = first + 1;

    real_type x = real_type{.456};

    BOOST_CHECK(parse(first, last, l));
    BOOST_CHECK_NO_THROW(x = get<real_type>(l.value));
    BOOST_CHECK_EQUAL(x, real_type{.123});
    BOOST_CHECK(first == last);
  }
  {
    typedef vm::basic_types<>::string_type string_type;
    const char *beg = "\"s t r\"", *end = beg + 7;
    lexer::token<> tok = lexer::token<>(lexer::token_t::qstring_, beg, end);
    lexer::token<> const* first = &tok, *last = first + 1;

    string_type x = string_type("bla");

    BOOST_CHECK(parse(first, last, l));
    BOOST_CHECK_NO_THROW(x = get<string_type>(l.value));
    BOOST_CHECK_EQUAL(x, string_type(beg+1, end-1));
    BOOST_CHECK(first == last);
  }
  {
    typedef vm::basic_types<>::regex_type regex_type;
    const char *beg = "r\"r e g e x\"", *end = beg + 12;
    lexer::token<> tok = lexer::token<>(lexer::token_t::qregex_, beg, end);
    lexer::token<> const* first = &tok, *last = first + 1;

    regex_type x = regex_type("bla");

    BOOST_CHECK(parse(first, last, l));
    BOOST_CHECK_NO_THROW(x = get<regex_type>(l.value));
    BOOST_CHECK(std::regex_match("r e g e x", x));
    BOOST_CHECK(first == last);
  }
}

#else
BOOST_AUTO_TEST_CASE(dummy)
{
  BOOST_CHECK(true);
}
#endif
