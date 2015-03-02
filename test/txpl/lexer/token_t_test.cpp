// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_lexer_token_t

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_LEXER_TOKEN_T

#include <txpl/lexer/token_t.hpp>
BOOST_AUTO_TEST_CASE(token_t__values)
{
  using namespace txpl::lexer;
  BOOST_CHECK(token_t::plus_     == static_cast<token_t>('+'));
  BOOST_CHECK(token_t::minus_    == static_cast<token_t>('-'));
  BOOST_CHECK(token_t::mul_      == static_cast<token_t>('*'));
  BOOST_CHECK(token_t::div_      == static_cast<token_t>('/'));
  BOOST_CHECK(token_t::mod_      == static_cast<token_t>('%'));
  BOOST_CHECK(token_t::xor_      == static_cast<token_t>('^'));
  BOOST_CHECK(token_t::bitand_   == static_cast<token_t>('&'));
  BOOST_CHECK(token_t::bitor_    == static_cast<token_t>('|'));
  BOOST_CHECK(token_t::lt_       == static_cast<token_t>('<'));
  BOOST_CHECK(token_t::gt_       == static_cast<token_t>('>'));
  BOOST_CHECK(token_t::not_      == static_cast<token_t>('!'));
  BOOST_CHECK(token_t::neg_      == static_cast<token_t>('~'));
  BOOST_CHECK(token_t::comma_    == static_cast<token_t>(','));
  BOOST_CHECK(token_t::dot_      == static_cast<token_t>('.'));
  BOOST_CHECK(token_t::lparen_   == static_cast<token_t>('('));
  BOOST_CHECK(token_t::rparen_   == static_cast<token_t>(')'));
  BOOST_CHECK(token_t::lbracket_ == static_cast<token_t>('['));
  BOOST_CHECK(token_t::rbracket_ == static_cast<token_t>(']'));
  BOOST_CHECK(token_t::lbrace_   == static_cast<token_t>('{'));
  BOOST_CHECK(token_t::rbrace_   == static_cast<token_t>('}'));

  BOOST_CHECK(token_t::qchar_    == static_cast<token_t>(0x10000));
  BOOST_CHECK(token_t::qstring_  == static_cast<token_t>(0x10001));
  BOOST_CHECK(token_t::qregex_   == static_cast<token_t>(0x10002));
  BOOST_CHECK(token_t::word_     == static_cast<token_t>(0x10003));
  BOOST_CHECK(token_t::real_     == static_cast<token_t>(0x10004));
  BOOST_CHECK(token_t::int_      == static_cast<token_t>(0x10005));
  BOOST_CHECK(token_t::bool_     == static_cast<token_t>(0x10006));
  BOOST_CHECK(token_t::and_      == static_cast<token_t>(0x10100));
  BOOST_CHECK(token_t::or_       == static_cast<token_t>(0x10101));
  BOOST_CHECK(token_t::eq_       == static_cast<token_t>(0x10102));
  BOOST_CHECK(token_t::neq_      == static_cast<token_t>(0x10103));
  BOOST_CHECK(token_t::le_       == static_cast<token_t>(0x10104));
  BOOST_CHECK(token_t::ge_       == static_cast<token_t>(0x10105));
  BOOST_CHECK(token_t::lshift_   == static_cast<token_t>(0x10106));
  BOOST_CHECK(token_t::rshift_   == static_cast<token_t>(0x10107));
  BOOST_CHECK(token_t::match_    == static_cast<token_t>(0x10108));
  BOOST_CHECK(token_t::nmatch_   == static_cast<token_t>(0x10109));
  BOOST_CHECK(token_t::nssep_    == static_cast<token_t>(0x1010A));
  BOOST_CHECK(token_t::spaces_   == static_cast<token_t>(0x1010B));
  BOOST_CHECK(token_t::other_    == static_cast<token_t>(0x1010C));
}
BOOST_AUTO_TEST_CASE(token_t__eq__char)
{
  using namespace txpl::lexer;
  BOOST_CHECK(token_t::lparen_ == '(');
  BOOST_CHECK(token_t::rparen_ == ')');
  BOOST_CHECK('(' == token_t::lparen_);
  BOOST_CHECK(')' == token_t::rparen_);
  BOOST_CHECK(!(token_t::rparen_ == '('));
  BOOST_CHECK(!('(' == token_t::rparen_));
}
BOOST_AUTO_TEST_CASE(token_t__eq__wchar_t)
{
  using namespace txpl::lexer;
  BOOST_CHECK(token_t::lparen_ == L'(');
  BOOST_CHECK(token_t::rparen_ == L')');
  BOOST_CHECK(L'(' == token_t::lparen_);
  BOOST_CHECK(L')' == token_t::rparen_);
  BOOST_CHECK(!(token_t::rparen_ == L'('));
  BOOST_CHECK(!(L'(' == token_t::rparen_));
}
BOOST_AUTO_TEST_CASE(token_t__neq__char)
{
  using namespace txpl::lexer;
  BOOST_CHECK(token_t::lparen_ != ')');
  BOOST_CHECK(token_t::rparen_ != '(');
  BOOST_CHECK(')' != token_t::lparen_);
  BOOST_CHECK('(' != token_t::rparen_);
  BOOST_CHECK(!(token_t::rparen_ != ')'));
  BOOST_CHECK(!(')' != token_t::rparen_));
}
BOOST_AUTO_TEST_CASE(token_t__neq__wchar_t)
{
  using namespace txpl::lexer;
  BOOST_CHECK(token_t::lparen_ != L')');
  BOOST_CHECK(token_t::rparen_ != L'(');
  BOOST_CHECK(L')' != token_t::lparen_);
  BOOST_CHECK(L'(' != token_t::rparen_);
  BOOST_CHECK(!(token_t::rparen_ != L')'));
  BOOST_CHECK(!(L')' != token_t::rparen_));
}
BOOST_AUTO_TEST_CASE(token_t__lt__char)
{
  using namespace txpl::lexer;
  BOOST_CHECK(token_t::lparen_ < ')');
  BOOST_CHECK('(' < token_t::rparen_);
  BOOST_CHECK(!(token_t::rparen_ < '('));
  BOOST_CHECK(!(')' < token_t::lparen_));
}
BOOST_AUTO_TEST_CASE(token_t__lt__wchar_t)
{
  using namespace txpl::lexer;
  BOOST_CHECK(token_t::lparen_ < L')');
  BOOST_CHECK(L'(' < token_t::rparen_);
  BOOST_CHECK(!(token_t::rparen_ < L'('));
  BOOST_CHECK(!(L')' < token_t::lparen_));
}
BOOST_AUTO_TEST_CASE(token_t__gt__char)
{
  using namespace txpl::lexer;
  BOOST_CHECK(token_t::rparen_ > '(');
  BOOST_CHECK(')' > token_t::lparen_);
  BOOST_CHECK(!(token_t::lparen_ > ')'));
  BOOST_CHECK(!('(' > token_t::rparen_));
}
BOOST_AUTO_TEST_CASE(token_t__gt__wchar_t)
{
  using namespace txpl::lexer;
  BOOST_CHECK(token_t::rparen_ > L'(');
  BOOST_CHECK(L')' > token_t::lparen_);
  BOOST_CHECK(!(token_t::lparen_ > L')'));
  BOOST_CHECK(!(L'(' > token_t::rparen_));
}
BOOST_AUTO_TEST_CASE(token_t__le__char)
{
  using namespace txpl::lexer;
  BOOST_CHECK(token_t::lparen_ <= ')');
  BOOST_CHECK(token_t::lparen_ <= '(');
  BOOST_CHECK('(' <= token_t::rparen_);
  BOOST_CHECK(')' <= token_t::rparen_);
  BOOST_CHECK(!(token_t::rparen_ <= '('));
  BOOST_CHECK(!(')' <= token_t::lparen_));
}
BOOST_AUTO_TEST_CASE(token_t__le__wchar_t)
{
  using namespace txpl::lexer;
  BOOST_CHECK(token_t::lparen_ <= L')');
  BOOST_CHECK(token_t::lparen_ <= L'(');
  BOOST_CHECK(L'(' <= token_t::rparen_);
  BOOST_CHECK(L')' <= token_t::rparen_);
  BOOST_CHECK(!(token_t::rparen_ <= L'('));
  BOOST_CHECK(!(L')' <= token_t::lparen_));
}
BOOST_AUTO_TEST_CASE(token_t__ge__char)
{
  using namespace txpl::lexer;
  BOOST_CHECK(token_t::rparen_ >= '(');
  BOOST_CHECK(token_t::rparen_ >= ')');
  BOOST_CHECK(')' >= token_t::lparen_);
  BOOST_CHECK('(' >= token_t::lparen_);
  BOOST_CHECK(!(token_t::lparen_ >= ')'));
  BOOST_CHECK(!('(' >= token_t::rparen_));
}
BOOST_AUTO_TEST_CASE(token_t__ge__wchar_t)
{
  using namespace txpl::lexer;
  BOOST_CHECK(token_t::rparen_ >= L'(');
  BOOST_CHECK(token_t::rparen_ >= L')');
  BOOST_CHECK(L')' >= token_t::lparen_);
  BOOST_CHECK(L'(' >= token_t::lparen_);
  BOOST_CHECK(!(token_t::lparen_ >= L')'));
  BOOST_CHECK(!(L'(' >= token_t::rparen_));
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{ 
  BOOST_CHECK(true);
}
#endif
