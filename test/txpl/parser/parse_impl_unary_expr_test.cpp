// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_parser_parse_impl_unary_expr

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_PARSER_PARSE_IMPL_UNARY_EXPR

#include <txpl/parser/parse_impl_unary_expr.hpp>
#include <txpl/vm/basic_types.hpp>
#include <txpl/lexer/token.hpp>

BOOST_AUTO_TEST_CASE(test__parse_impl_unary_expr)
{
  using namespace txpl::parser;
  using namespace txpl;
  using boost::get;

  typedef lexer::token<> const* token_iterator;

  ast::unary_expr<token_iterator> u;
  {
    lexer::token<> tok;
    lexer::token<> const *first = &tok, *last = first;
    BOOST_CHECK(!parse(first, last, u));
    BOOST_CHECK(first == last);
  }
  {
    const char *beg[] = { "z" };
    const char *end[] = { beg[0]+1 };
    lexer::token<> tok[] = {
      lexer::token<>(lexer::token_t::word_, beg[0], end[0])
    };
    lexer::token<> const* first = tok, *last = first + 1;
    BOOST_CHECK(!parse(first, last, u));
    BOOST_CHECK((first+1) == last);
  }
  {
    typedef vm::basic_types<>::real_type real_type;
    const char *beg[] = { "-",      ".123" };
    const char *end[] = { beg[0]+1, beg[1]+4 };
    lexer::token<> tok[] = {
      lexer::token<>(lexer::token_t::minus_, beg[0], end[0]),
      lexer::token<>(lexer::token_t::real_, beg[1], end[1]),
    };
    lexer::token<> const* first = tok, *last = first + 2;

    ast::literal<token_iterator> l;
    real_type x = real_type{.456};
    BOOST_CHECK(parse(first, last, u));
    BOOST_CHECK(u.operator_ == '-');
    BOOST_CHECK_NO_THROW(l = get<ast::literal<token_iterator> >(u.expr.attrib));
    BOOST_CHECK_NO_THROW(x = get<real_type>(l.value));
    BOOST_CHECK_EQUAL(x, real_type{.123});
    BOOST_CHECK(first == last);
  }
  {
    typedef vm::basic_types<>::real_type real_type;
    const char *beg[] = { "+",      ".123" };
    const char *end[] = { beg[0]+1, beg[1]+4 };
    lexer::token<> tok[] = {
      lexer::token<>(lexer::token_t::plus_, beg[0], end[0]),
      lexer::token<>(lexer::token_t::real_, beg[1], end[1]),
    };
    lexer::token<> const* first = tok, *last = first + 2;

    ast::literal<token_iterator> l;
    real_type x = real_type{.456};
    BOOST_CHECK(parse(first, last, u));
    BOOST_CHECK(u.operator_ == '+');
    BOOST_CHECK_NO_THROW(l = get<ast::literal<token_iterator> >(u.expr.attrib));
    BOOST_CHECK_NO_THROW(x = get<real_type>(l.value));
    BOOST_CHECK_EQUAL(x, real_type{.123});
    BOOST_CHECK(first == last);
  }
  {
    typedef vm::basic_types<>::char_type char_type;
    const char *beg[] = { "!",      "'a'" };
    const char *end[] = { beg[0]+1, beg[1] + 3 };
    lexer::token<> tok[] = {
      lexer::token<>(lexer::token_t::not_, beg[0], end[0]),
      lexer::token<>(lexer::token_t::qchar_, beg[1], end[1]),
    };
    lexer::token<> const* first = tok, *last = first + 2;

    ast::literal<token_iterator> l;
    char_type x = char_type{'z'};
    BOOST_CHECK(parse(first, last, u));
    BOOST_CHECK(u.operator_ == '!');
    BOOST_CHECK_NO_THROW(l = get<ast::literal<token_iterator> >(u.expr.attrib));
    BOOST_CHECK_NO_THROW(x = get<char_type>(l.value));
    BOOST_CHECK_EQUAL(x, 'a');
    BOOST_CHECK(first == last);
  }
  {
    typedef vm::basic_types<>::int_type int_type;
    const char *beg[] = { "~",      "123" };
    const char *end[] = { beg[0]+1, beg[1] + 3 };
    lexer::token<> tok[] = {
      lexer::token<>(lexer::token_t::neg_, beg[0], end[0]),
      lexer::token<>(lexer::token_t::int_, beg[1], end[1]),
    };
    lexer::token<> const* first = tok, *last = first + 2;

    ast::literal<token_iterator> l;
    int_type x = int_type{456};
    BOOST_CHECK(parse(first, last, u));
    BOOST_CHECK(u.operator_ == '~');
    BOOST_CHECK_NO_THROW(l = get<ast::literal<token_iterator> >(u.expr.attrib));
    BOOST_CHECK_NO_THROW(x = get<int_type>(l.value));
    BOOST_CHECK_EQUAL(x, 123);
    BOOST_CHECK(first == last);
  }
}

#else
BOOST_AUTO_TEST_CASE(dummy)
{
  BOOST_CHECK(true);
}
#endif
