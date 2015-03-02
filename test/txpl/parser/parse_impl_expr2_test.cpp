// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_parser_parse_impl_expr2

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_PARSER_PARSE_IMPL_EXPR2

#include <txpl/parser/parse_impl_expr.hpp>
#include <txpl/lexer/token.hpp>
#include <txpl/lexer/token_t.hpp>
#include <txpl/ast/basic_types.hpp>
#include <txpl/ast/value.hpp>
#include <txpl/ast/squash_heads.hpp>
#include <boost/variant/get.hpp>
#include <string>

struct error_handler
{
  error_handler(std::string& emsg) : _emsg(emsg) {}
  template<typename Iterator>
  void operator()(Iterator const&, Iterator const&, std::string const& emsg) const
  { _emsg = emsg; }
  std::string& _emsg;
};

BOOST_AUTO_TEST_CASE(test__parse__expr2__empty)
{
  using namespace txpl::parser;
  using namespace txpl;

  typedef lexer::token<> const* token_iterator;

  ast::expr<token_iterator, ast::value<>, 2> e;
  {
    lexer::token<> tok;
    lexer::token<> const *first = &tok, *last = first;
    BOOST_CHECK(!parse(first, last, e));
    BOOST_CHECK(first == last);
  }
}

BOOST_AUTO_TEST_CASE(test__parse__expr2__literal)
{
  using namespace txpl::parser;
  using namespace txpl;
  using boost::get;

  typedef lexer::token<> const* token_iterator;

  ast::expr<token_iterator, ast::value<>, 2> e;
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
    BOOST_CHECK_NO_THROW(l = get<ast::literal<token_iterator> >(ast::squash_heads(e)));
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
    BOOST_CHECK_NO_THROW(l = get<ast::literal<token_iterator> >(ast::squash_heads(e)));
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
    BOOST_CHECK_NO_THROW(l = get<ast::literal<token_iterator> >(ast::squash_heads(e)));
    BOOST_CHECK_NO_THROW(x = get<bool_type>(l.value));
    BOOST_CHECK_EQUAL(x, bool_type{false});
  }
}

BOOST_AUTO_TEST_CASE(test__parse__expr2__symbol__subscript__literal)
{
  using namespace txpl::parser;
  using namespace txpl;
  using boost::get;

  typedef lexer::token<> const* token_iterator;

  ast::expr<token_iterator, ast::value<>, 2> e;
  ast::symbol<token_iterator> s;
  ast::literal<token_iterator> l;

  std::string emsg;
  error_handler ehandler(emsg);

  {
    typedef ast::basic_types<>::int_type int_type;

    const char  *beg[] = { "foo",      "::",       "bar",      "[",        "123" ,     "]" };
    const char  *end[] = { beg[0] + 3, beg[1] + 2, beg[2] + 3, beg[3] + 1, beg[4] + 3, beg[5] + 1};
    lexer::token<> tok[] = {
      lexer::token<>(lexer::token_t::word_,     beg[0], end[0]),
      lexer::token<>(lexer::token_t::nssep_,    beg[1], end[1]),
      lexer::token<>(lexer::token_t::word_,     beg[2], end[2]),
      lexer::token<>(lexer::token_t::lbracket_, beg[3], end[3]),
      lexer::token<>(lexer::token_t::int_,      beg[4], end[4]),
      lexer::token<>(lexer::token_t::rbracket_, beg[5], end[5])
    };
    lexer::token<> const* first = tok, *last = first + 6;

    ast::symbol<token_iterator>::name_type n = "asd";
    int_type x = int_type{654};

    emsg = "";
    BOOST_CHECK(parse(first, last, e, ehandler));
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK_EQUAL(last - first, 0l);
    BOOST_CHECK_NO_THROW(s = get<ast::symbol<token_iterator> >(ast::squash_heads(e)));
    BOOST_CHECK_EQUAL(s.name, "foo::bar");
    BOOST_CHECK_EQUAL(e.tail.size(), 1);
    if(e.tail.size() != 0)
      {
        BOOST_CHECK_NO_THROW(l = get<ast::literal<token_iterator> >(ast::squash_heads(e.tail.begin()->expr)));
        BOOST_CHECK_NO_THROW(x = get<int_type>(l.value));
        BOOST_CHECK_EQUAL(x, 123);
      }
  }
}

#else
BOOST_AUTO_TEST_CASE(dummy)
{
  BOOST_CHECK(true);
}
#endif
