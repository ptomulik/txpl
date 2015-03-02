// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_lexer_try_token

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_LEXER_TRY_TOKEN

#include <txpl/lexer/try_token.hpp>

BOOST_AUTO_TEST_CASE(empty)
{
  using namespace txpl::lexer;
  const char *first = "", *last = first;
  const char *next = nullptr;
  BOOST_CHECK(try_token(first, last, next) == token_t::invalid_);
  BOOST_CHECK(next == first);
}
BOOST_AUTO_TEST_CASE(plus)
{
  using namespace txpl::lexer;
  {
    const char *first = "+", *last = first+1;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == '+');
    BOOST_CHECK(next == last);
  }
  {
    const char *first = "+a", *last = first+2;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == '+');
    BOOST_CHECK((next+1) == last);
  }
}
BOOST_AUTO_TEST_CASE(minus)
{
  using namespace txpl::lexer;
  {
    const char *first = "-", *last = first+1;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == '-');
    BOOST_CHECK(next == last);
  }
  {
    const char *first = "-a", *last = first+2;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == '-');
    BOOST_CHECK((next+1) == last);
  }
}
BOOST_AUTO_TEST_CASE(mul)
{
  using namespace txpl::lexer;
  {
    const char *first = "*", *last = first+1;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == '*');
    BOOST_CHECK(next == last);
  }
  {
    const char *first = "*a", *last = first+2;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == '*');
    BOOST_CHECK((next+1) == last);
  }
}
BOOST_AUTO_TEST_CASE(div_)
{
  using namespace txpl::lexer;
  {
    const char *first = "/", *last = first+1;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == '/');
    BOOST_CHECK(next == last);
  }
  {
    const char *first = "/a", *last = first+2;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == '/');
    BOOST_CHECK((next+1) == last);
  }
}
BOOST_AUTO_TEST_CASE(mod)
{
  using namespace txpl::lexer;
  {
    const char *first = "%", *last = first+1;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == '%');
    BOOST_CHECK(next == last);
  }
  {
    const char *first = "%a", *last = first+2;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == '%');
    BOOST_CHECK((next+1) == last);
  }
}
BOOST_AUTO_TEST_CASE(xor_)
{
  using namespace txpl::lexer;
  {
    const char *first = "^", *last = first+1;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == '^');
    BOOST_CHECK(next == last);
  }
  {
    const char *first = "^a", *last = first+2;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == '^');
    BOOST_CHECK((next+1) == last);
  }
}
BOOST_AUTO_TEST_CASE(neg)
{
  using namespace txpl::lexer;
  {
    const char *first = "~", *last = first+1;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == '~');
    BOOST_CHECK(next == last);
  }
  {
    const char *first = "~a", *last = first+2;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == '~');
    BOOST_CHECK((next+1) == last);
  }
}
BOOST_AUTO_TEST_CASE(comma)
{
  using namespace txpl::lexer;
  {
    const char *first = ",", *last = first+1;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == ',');
    BOOST_CHECK(next == last);
  }
  {
    const char *first = ",a", *last = first+2;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == ',');
    BOOST_CHECK((next+1) == last);
  }
}
BOOST_AUTO_TEST_CASE(dot)
{
  using namespace txpl::lexer;
  {
    const char *first = ".", *last = first+1;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == '.');
    BOOST_CHECK(next == last);
  }
  {
    const char *first = ".a", *last = first+2;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == '.');
    BOOST_CHECK((next+1) == last);
  }
}
BOOST_AUTO_TEST_CASE(lparen)
{
  using namespace txpl::lexer;
  {
    const char *first = "(", *last = first+1;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == '(');
    BOOST_CHECK(next == last);
  }
  {
    const char *first = "(a", *last = first+2;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == '(');
    BOOST_CHECK((next+1) == last);
  }
}
BOOST_AUTO_TEST_CASE(rparen)
{
  using namespace txpl::lexer;
  {
    const char *first = ")", *last = first+1;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == ')');
    BOOST_CHECK(next == last);
  }
  {
    const char *first = ")a", *last = first+2;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == ')');
    BOOST_CHECK((next+1) == last);
  }
}
BOOST_AUTO_TEST_CASE(lbracket)
{
  using namespace txpl::lexer;
  {
    const char *first = "[", *last = first+1;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == '[');
    BOOST_CHECK(next == last);
  }
  {
    const char *first = "[a", *last = first+2;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == '[');
    BOOST_CHECK((next+1) == last);
  }
}
BOOST_AUTO_TEST_CASE(rbracket)
{
  using namespace txpl::lexer;
  {
    const char *first = "]", *last = first+1;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == ']');
    BOOST_CHECK(next == last);
  }
  {
    const char *first = "]a", *last = first+2;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == ']');
    BOOST_CHECK((next+1) == last);
  }
}
BOOST_AUTO_TEST_CASE(lbrace)
{
  using namespace txpl::lexer;
  {
    const char *first = "{", *last = first+1;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == '{');
    BOOST_CHECK(next == last);
  }
  {
    const char *first = "{a", *last = first+2;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == '{');
    BOOST_CHECK((next+1) == last);
  }
}
BOOST_AUTO_TEST_CASE(rbrace)
{
  using namespace txpl::lexer;
  {
    const char *first = "}", *last = first+1;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == '}');
    BOOST_CHECK(next == last);
  }
  {
    const char *first = "}a", *last = first+2;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == '}');
    BOOST_CHECK((next+1) == last);
  }
}
BOOST_AUTO_TEST_CASE(bitand_)
{
  using namespace txpl::lexer;
  {
    const char *first = "&", *last = first+1;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == '&');
    BOOST_CHECK(next == last);
  }
  {
    const char *first = "&a", *last = first+2;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == '&');
    BOOST_CHECK((next+1) == last);
  }
}
BOOST_AUTO_TEST_CASE(bitor_)
{
  using namespace txpl::lexer;
  {
    const char *first = "|", *last = first+1;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == '|');
    BOOST_CHECK(next == last);
  }
  {
    const char *first = "|a", *last = first+2;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == '|');
    BOOST_CHECK((next+1) == last);
  }
}
BOOST_AUTO_TEST_CASE(lt)
{
  using namespace txpl::lexer;
  {
    const char *first = "<", *last = first+1;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == '<');
    BOOST_CHECK(next == last);
  }
  {
    const char *first = "<a", *last = first+2;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == '<');
    BOOST_CHECK((next+1) == last);
  }
}
BOOST_AUTO_TEST_CASE(gt)
{
  using namespace txpl::lexer;
  {
    const char *first = ">", *last = first+1;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == '>');
    BOOST_CHECK(next == last);
  }
  {
    const char *first = ">a", *last = first+2;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == '>');
    BOOST_CHECK((next+1) == last);
  }
}
BOOST_AUTO_TEST_CASE(not_)
{
  using namespace txpl::lexer;
  {
    const char *first = "!", *last = first+1;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == '!');
    BOOST_CHECK(next == last);
  }
  {
    const char *first = "!a", *last = first+2;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == '!');
    BOOST_CHECK((next+1) == last);
  }
}
BOOST_AUTO_TEST_CASE(qmark_)
{
  using namespace txpl::lexer;
  {
    const char *first = "?", *last = first+1;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == '?');
    BOOST_CHECK(next == last);
  }
  {
    const char *first = "?a", *last = first+2;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == '?');
    BOOST_CHECK((next+1) == last);
  }
}
BOOST_AUTO_TEST_CASE(colon_)
{
  using namespace txpl::lexer;
  {
    const char *first = ":", *last = first+1;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == ':');
    BOOST_CHECK(next == last);
  }
  {
    const char *first = ":a", *last = first+2;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == ':');
    BOOST_CHECK((next+1) == last);
  }
}
BOOST_AUTO_TEST_CASE(and_)
{
  using namespace txpl::lexer;
  {
    const char *first = "&&", *last = first+2;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == token_t::and_);
    BOOST_CHECK(next == last);
  }
  {
    const char *first = "&&a", *last = first+3;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == token_t::and_);
    BOOST_CHECK((next+1) == last);
  }
}
BOOST_AUTO_TEST_CASE(or_)
{
  using namespace txpl::lexer;
  {
    const char *first = "||", *last = first+2;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == token_t::or_);
    BOOST_CHECK(next == last);
  }
  {
    const char *first = "||a", *last = first+3;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == token_t::or_);
    BOOST_CHECK((next+1) == last);
  }
}
BOOST_AUTO_TEST_CASE(eq)
{
  using namespace txpl::lexer;
  {
    const char *first = "==", *last = first+2;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == token_t::eq_);
    BOOST_CHECK(next == last);
  }
  {
    const char *first = "==a", *last = first+3;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == token_t::eq_);
    BOOST_CHECK((next+1) == last);
  }
}
BOOST_AUTO_TEST_CASE(neq)
{
  using namespace txpl::lexer;
  {
    const char *first = "!=", *last = first+2;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == token_t::neq_);
    BOOST_CHECK(next == last);
  }
  {
    const char *first = "!=a", *last = first+3;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == token_t::neq_);
    BOOST_CHECK((next+1) == last);
  }
}
BOOST_AUTO_TEST_CASE(le)
{
  using namespace txpl::lexer;
  {
    const char *first = "<=", *last = first+2;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == token_t::le_);
    BOOST_CHECK(next == last);
  }
  {
    const char *first = "<=a", *last = first+3;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == token_t::le_);
    BOOST_CHECK((next+1) == last);
  }
}
BOOST_AUTO_TEST_CASE(ge)
{
  using namespace txpl::lexer;
  {
    const char *first = ">=", *last = first+2;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == token_t::ge_);
    BOOST_CHECK(next == last);
  }
  {
    const char *first = ">=a", *last = first+3;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == token_t::ge_);
    BOOST_CHECK((next+1) == last);
  }
}
BOOST_AUTO_TEST_CASE(lshift)
{
  using namespace txpl::lexer;
  {
    const char *first = "<<", *last = first+2;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == token_t::lshift_);
    BOOST_CHECK(next == last);
  }
  {
    const char *first = "<<a", *last = first+3;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == token_t::lshift_);
    BOOST_CHECK((next+1) == last);
  }
}
BOOST_AUTO_TEST_CASE(rshift)
{
  using namespace txpl::lexer;
  {
    const char *first = ">>", *last = first+2;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == token_t::rshift_);
    BOOST_CHECK(next == last);
  }
  {
    const char *first = ">>a", *last = first+3;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == token_t::rshift_);
    BOOST_CHECK((next+1) == last);
  }
}
BOOST_AUTO_TEST_CASE(match)
{
  using namespace txpl::lexer;
  {
    const char *first = "=~", *last = first+2;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == token_t::match_);
    BOOST_CHECK(next == last);
  }
  {
    const char *first = "=~a", *last = first+3;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == token_t::match_);
    BOOST_CHECK((next+1) == last);
  }
}
BOOST_AUTO_TEST_CASE(nmatch)
{
  using namespace txpl::lexer;
  {
    const char *first = "!~", *last = first+2;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == token_t::nmatch_);
    BOOST_CHECK(next == last);
  }
  {
    const char *first = "!~a", *last = first+3;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == token_t::nmatch_);
    BOOST_CHECK((next+1) == last);
  }
}
BOOST_AUTO_TEST_CASE(nssep)
{
  using namespace txpl::lexer;
  {
    const char *first = "::", *last = first+2;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == token_t::nssep_);
    BOOST_CHECK(next == last);
  }
  {
    const char *first = "::a", *last = first+3;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == token_t::nssep_);
    BOOST_CHECK((next+1) == last);
  }
}
BOOST_AUTO_TEST_CASE(qchar)
{
  using namespace txpl::lexer;
  {
    const char *first = "'", *last = first+1;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == token_t::invalid_);
    BOOST_CHECK(next == last);
  }
  {
    const char *first = "'a", *last = first+2;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == token_t::invalid_);
    BOOST_CHECK(next == last);
  }
  {
    const char *first = "''", *last = first+2;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == token_t::invalid_);
    BOOST_CHECK(next == last);
  }
  {
    const char *first = "'as'", *last = first+4;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == token_t::invalid_);
    BOOST_CHECK(next == last);
  }
  {
    const char *first = "'x'", *last = first+3;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == token_t::qchar_);
    BOOST_CHECK(next == last);
  }
  {
    const char *first = "'\\x12'", *last = first+6;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == token_t::qchar_);
    BOOST_CHECK(next == last);
  }
}
BOOST_AUTO_TEST_CASE(qstring)
{
  using namespace txpl::lexer;
  {
    const char *first = "\"", *last = first+1;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == token_t::invalid_);
    BOOST_CHECK(next == last);
  }
  {
    const char *first = "\"a", *last = first+2;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == token_t::invalid_);
    BOOST_CHECK(next == last);
  }
  {
    const char *first = "\"\"", *last = first+2;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == token_t::qstring_);
    BOOST_CHECK(next == last);
  }
  {
    const char *first = "\"as\"", *last = first+4;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == token_t::qstring_);
    BOOST_CHECK(next == last);
  }
  {
    const char *first = "\"\\x12\\\"as\"", *last = first+10;
    const char *next = nullptr;
    BOOST_CHECK(try_token(first, last, next) == token_t::qstring_);
    BOOST_CHECK(next == last);
  }
}
BOOST_AUTO_TEST_CASE(qregex)
{
  using namespace txpl::lexer;
  {
    const char *first = "r\"", *last = first + 2;
    const char *next;
    BOOST_CHECK(try_token(first, last, next) == token_t::word_);
    BOOST_CHECK((next+1) == last);
  }
  {
    const char *first = "r\"\"", *last = first + 3;
    const char *next;
    BOOST_CHECK(try_token(first, last, next) == token_t::qregex_);
    BOOST_CHECK(next == last);
  }
  {
    const char *first = "r\"regex\"", *last = first + 8;
    const char *next;
    BOOST_CHECK(try_token(first, last, next) == token_t::qregex_);
    BOOST_CHECK(next == last);
  }
  {
    const char *first = "r\"regex\"c", *last = first + 9;
    const char *next;
    BOOST_CHECK(try_token(first, last, next) == token_t::qregex_);
    BOOST_CHECK(next == last);
  }
  {
    const char *first = "r\"regex\"i", *last = first + 9;
    const char *next;
    BOOST_CHECK(try_token(first, last, next) == token_t::qregex_);
    BOOST_CHECK(next == last);
  }
  {
    const char *first = "r\"regex\"ci", *last = first + 10;
    const char *next;
    BOOST_CHECK(try_token(first, last, next) == token_t::qregex_);
    BOOST_CHECK(next == last);
  }
  {
    const char *first = "r\"regex\"ic", *last = first + 10;
    const char *next;
    BOOST_CHECK(try_token(first, last, next) == token_t::qregex_);
    BOOST_CHECK(next == last);
  }
}
BOOST_AUTO_TEST_CASE(word)
{
  using namespace txpl::lexer;
  {
    const char *first = "_", *last = first + 1;
    const char *next;
    BOOST_CHECK(try_token(first, last, next) == token_t::word_);
    BOOST_CHECK(next == last);
  }
  {
    const char *first = "a", *last = first + 1;
    const char *next;
    BOOST_CHECK(try_token(first, last, next) == token_t::word_);
    BOOST_CHECK(next == last);
  }
  {
    const char *first = "_0", *last = first + 2;
    const char *next;
    BOOST_CHECK(try_token(first, last, next) == token_t::word_);
    BOOST_CHECK(next == last);
  }
  {
    const char *first = "_0a_b", *last = first + 5;
    const char *next;
    BOOST_CHECK(try_token(first, last, next) == token_t::word_);
    BOOST_CHECK(next == last);
  }
  {
    const char *first = "zx21", *last = first + 4;
    const char *next;
    BOOST_CHECK(try_token(first, last, next) == token_t::word_);
    BOOST_CHECK(next == last);
  }
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{ 
  BOOST_CHECK(true);
}
#endif
