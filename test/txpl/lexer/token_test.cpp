// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_lexer_token

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_LEXER_TOKEN

#include <txpl/lexer/token.hpp>

BOOST_AUTO_TEST_CASE(token__default__typedefs)
{
  using namespace txpl::lexer;
  using std::is_same;
  BOOST_CHECK((is_same<token<>::iterator_type, const char*>::value));
}
BOOST_AUTO_TEST_CASE(token__wchar_t__typedefs)
{
  using namespace txpl::lexer;
  using std::is_same;
  BOOST_CHECK((is_same<token<const wchar_t*>::iterator_type, const wchar_t*>::value));
}
BOOST_AUTO_TEST_CASE(token__default_ctor)
{
  using namespace txpl::lexer;
  BOOST_CHECK_NO_THROW(token<>());
  BOOST_CHECK(token<>().id() == token_t::invalid_);
  BOOST_CHECK(!token<>().is_valid());
}
BOOST_AUTO_TEST_CASE(token__ctor_1)
{
  using namespace txpl::lexer;
  const char *beg = "asd";
  const char *end = beg + 3;
  BOOST_CHECK_NO_THROW(token<>(token_t::eq_, beg, end));
  BOOST_CHECK(token<>(token_t::eq_, beg, end).id() == token_t::eq_);
  BOOST_CHECK(token<>(token_t::eq_, beg, end).begin() == beg);
  BOOST_CHECK(token<>(token_t::eq_, beg, end).end() == end);
}
BOOST_AUTO_TEST_CASE(token__cast_1)
{
  using namespace txpl::lexer;
  const char *beg = "asd";
  const char *end = beg + 3;
  BOOST_CHECK(static_cast<token_t>(token<>(token_t::eq_, beg, end)) == token_t::eq_);
}
BOOST_AUTO_TEST_CASE(token__eq__token)
{
  using namespace txpl::lexer;
  const char* beg = "asd";
  const char* end = beg+3;
  BOOST_CHECK(token<>() == token<>());
  BOOST_CHECK(token<>(token_t::lparen_,nullptr,nullptr) == token<>(token_t::lparen_,nullptr,nullptr));
  BOOST_CHECK(token<>(token_t::lparen_,beg,end) == token<>(token_t::lparen_,nullptr,nullptr));
  BOOST_CHECK(!(token<>(token_t::lparen_,nullptr,nullptr) == token<>(token_t::rparen_,nullptr,nullptr)));
}
BOOST_AUTO_TEST_CASE(token__neq__token)
{
  using namespace txpl::lexer;
  const char* beg = "asd";
  const char* end = beg+3;
  BOOST_CHECK(!(token<>() != token<>()));
  BOOST_CHECK(!(token<>(token_t::lparen_,nullptr,nullptr) != token<>(token_t::lparen_,nullptr,nullptr)));
  BOOST_CHECK(!(token<>(token_t::lparen_,beg,end) != token<>(token_t::lparen_,nullptr,nullptr)));
  BOOST_CHECK(token<>(token_t::lparen_,nullptr,nullptr) != token<>(token_t::rparen_,nullptr,nullptr));
}
BOOST_AUTO_TEST_CASE(token__lt__token)
{
  using namespace txpl::lexer;
  BOOST_CHECK(!(token<>() < token<>()));
  BOOST_CHECK(!(token<>(token_t::lparen_,nullptr,nullptr) < token<>(token_t::lparen_,nullptr,nullptr)));
  BOOST_CHECK(!(token<>(token_t::rparen_,nullptr,nullptr) < token<>(token_t::lparen_,nullptr,nullptr)));
  BOOST_CHECK(token<>(token_t::lparen_,nullptr,nullptr) < token<>(token_t::rparen_,nullptr,nullptr));
}
BOOST_AUTO_TEST_CASE(token__gt__token)
{
  using namespace txpl::lexer;
  BOOST_CHECK(!(token<>() > token<>()));
  BOOST_CHECK(!(token<>(token_t::lparen_,nullptr,nullptr) > token<>(token_t::lparen_,nullptr,nullptr)));
  BOOST_CHECK(token<>(token_t::rparen_,nullptr,nullptr) > token<>(token_t::lparen_,nullptr,nullptr));
  BOOST_CHECK(!(token<>(token_t::lparen_,nullptr,nullptr) > token<>(token_t::rparen_,nullptr,nullptr)));
}
BOOST_AUTO_TEST_CASE(token__le__token)
{
  using namespace txpl::lexer;
  BOOST_CHECK(token<>() <= token<>());
  BOOST_CHECK(token<>(token_t::lparen_,nullptr,nullptr) <= token<>(token_t::lparen_,nullptr,nullptr));
  BOOST_CHECK(!(token<>(token_t::rparen_,nullptr,nullptr) <= token<>(token_t::lparen_,nullptr,nullptr)));
  BOOST_CHECK(token<>(token_t::lparen_,nullptr,nullptr) <= token<>(token_t::rparen_,nullptr,nullptr));
}
BOOST_AUTO_TEST_CASE(token__ge__token)
{
  using namespace txpl::lexer;
  BOOST_CHECK(token<>() >= token<>());
  BOOST_CHECK(token<>(token_t::lparen_,nullptr,nullptr) >= token<>(token_t::lparen_,nullptr,nullptr));
  BOOST_CHECK(token<>(token_t::rparen_,nullptr,nullptr) >= token<>(token_t::lparen_,nullptr,nullptr));
  BOOST_CHECK(!(token<>(token_t::lparen_,nullptr,nullptr) >= token<>(token_t::rparen_,nullptr,nullptr)));
}
BOOST_AUTO_TEST_CASE(token__eq__token_t)
{
  using namespace txpl::lexer;
  const char* beg = "asd";
  const char* end = beg+3;
  BOOST_CHECK(token<>() == static_cast<token_t>(0));
  BOOST_CHECK(token<>(token_t::lparen_,nullptr,nullptr) == token_t::lparen_);
  BOOST_CHECK(token<>(token_t::lparen_,beg,end) == token_t::lparen_);
  BOOST_CHECK(!(token<>(token_t::lparen_,nullptr,nullptr) == token_t::rparen_));
}
BOOST_AUTO_TEST_CASE(token__eq__char)
{
  using namespace txpl::lexer;
  const char* beg = "asd";
  const char* end = beg+3;
  BOOST_CHECK(token<>() == '\0');
  BOOST_CHECK(token<>(token_t::lparen_,nullptr,nullptr) == '(');
  BOOST_CHECK(token<>(token_t::lparen_,beg,end) == '(');
  BOOST_CHECK(!(token<>(token_t::lparen_,nullptr,nullptr) == ')'));
}
BOOST_AUTO_TEST_CASE(token__eq__wchar_t)
{
  using namespace txpl::lexer;
  const char* beg = "asd";
  const char* end = beg+3;
  BOOST_CHECK(token<>() == '\0');
  BOOST_CHECK(token<>(token_t::lparen_,nullptr,nullptr) == L'(');
  BOOST_CHECK(token<>(token_t::lparen_,beg,end) == L'(');
  BOOST_CHECK(!(token<>(token_t::lparen_,nullptr,nullptr) == L')'));
}
BOOST_AUTO_TEST_CASE(token_t__eq__token)
{
  using namespace txpl::lexer;
  BOOST_CHECK(static_cast<token_t>(0) == token<>());
  BOOST_CHECK(token_t::lparen_ == token<>(token_t::lparen_,nullptr,nullptr));
  BOOST_CHECK(!(token_t::lparen_ == token<>(token_t::rparen_,nullptr,nullptr)));
}
BOOST_AUTO_TEST_CASE(char__eq__token)
{
  using namespace txpl::lexer;
  BOOST_CHECK('\0' == token<>());
  BOOST_CHECK('(' == token<>(token_t::lparen_,nullptr,nullptr));
  BOOST_CHECK(!('(' == token<>(token_t::rparen_,nullptr,nullptr)));
}
BOOST_AUTO_TEST_CASE(wchar_t__eq__token)
{
  using namespace txpl::lexer;
  BOOST_CHECK(L'\0' == token<>());
  BOOST_CHECK(L'(' == token<>(token_t::lparen_,nullptr,nullptr));
  BOOST_CHECK(!(L'(' == token<>(token_t::rparen_,nullptr,nullptr)));
}
BOOST_AUTO_TEST_CASE(token__neq__token_t)
{
  using namespace txpl::lexer;
  BOOST_CHECK(!(token<>() != static_cast<token_t>(0)));
  BOOST_CHECK(!(token<>(token_t::lparen_,nullptr,nullptr) != token_t::lparen_));
  BOOST_CHECK(token<>(token_t::lparen_,nullptr,nullptr) != token_t::rparen_);
}
BOOST_AUTO_TEST_CASE(token__neq__char)
{
  using namespace txpl::lexer;
  BOOST_CHECK(!(token<>() != '\0'));
  BOOST_CHECK(!(token<>(token_t::lparen_,nullptr,nullptr) != '('));
  BOOST_CHECK(token<>(token_t::lparen_,nullptr,nullptr) != ')');
}
BOOST_AUTO_TEST_CASE(token__neq__wchar_t)
{
  using namespace txpl::lexer;
  BOOST_CHECK(!(token<>() != L'\0'));
  BOOST_CHECK(!(token<>(token_t::lparen_,nullptr,nullptr) != L'('));
  BOOST_CHECK(token<>(token_t::lparen_,nullptr,nullptr) != L')');
}
BOOST_AUTO_TEST_CASE(token_t__neq__token)
{
  using namespace txpl::lexer;
  BOOST_CHECK(!(static_cast<token_t>(0) != token<>()));
  BOOST_CHECK(!(token_t::lparen_ != token<>(token_t::lparen_,nullptr,nullptr)));
  BOOST_CHECK(token_t::lparen_ != token<>(token_t::rparen_,nullptr,nullptr));
}
BOOST_AUTO_TEST_CASE(char__neq__token)
{
  using namespace txpl::lexer;
  BOOST_CHECK(!('\0' != token<>()));
  BOOST_CHECK(!('(' != token<>(token_t::lparen_,nullptr,nullptr)));
  BOOST_CHECK('(' != token<>(token_t::rparen_,nullptr,nullptr));
}
BOOST_AUTO_TEST_CASE(wchar_t__neq__token)
{
  using namespace txpl::lexer;
  BOOST_CHECK(!(L'\0' != token<>()));
  BOOST_CHECK(!(L'(' != token<>(token_t::lparen_,nullptr,nullptr)));
  BOOST_CHECK(L'(' != token<>(token_t::rparen_,nullptr,nullptr));
}
BOOST_AUTO_TEST_CASE(token__lt__token_t)
{
  using namespace txpl::lexer;
  BOOST_CHECK(!(token<>() < static_cast<token_t>(0)));
  BOOST_CHECK(!(token<>(token_t::lparen_,nullptr,nullptr) < token_t::lparen_));
  BOOST_CHECK(!(token<>(token_t::rparen_,nullptr,nullptr) < token_t::lparen_));
  BOOST_CHECK(token<>(token_t::lparen_,nullptr,nullptr) < token_t::rparen_);
}
BOOST_AUTO_TEST_CASE(token__lt__char)
{
  using namespace txpl::lexer;
  BOOST_CHECK(!(token<>() < '\0'));
  BOOST_CHECK(!(token<>(token_t::lparen_,nullptr,nullptr) < '('));
  BOOST_CHECK(!(token<>(token_t::rparen_,nullptr,nullptr) < '('));
  BOOST_CHECK(token<>(token_t::lparen_,nullptr,nullptr) < ')');
}
BOOST_AUTO_TEST_CASE(token__lt__wchar_t)
{
  using namespace txpl::lexer;
  BOOST_CHECK(!(token<>() < L'\0'));
  BOOST_CHECK(!(token<>(token_t::lparen_,nullptr,nullptr) < L'('));
  BOOST_CHECK(!(token<>(token_t::rparen_,nullptr,nullptr) < L'('));
  BOOST_CHECK(token<>(token_t::lparen_,nullptr,nullptr) < L')');
}
BOOST_AUTO_TEST_CASE(token_t__lt__token)
{
  using namespace txpl::lexer;
  BOOST_CHECK(!(static_cast<token_t>(0) < token<>()));
  BOOST_CHECK(!(token_t::lparen_ < token<>(token_t::lparen_,nullptr,nullptr)));
  BOOST_CHECK(!(token_t::rparen_ < token<>(token_t::lparen_,nullptr,nullptr)));
  BOOST_CHECK(token_t::lparen_ < token<>(token_t::rparen_,nullptr,nullptr));
}
BOOST_AUTO_TEST_CASE(char__lt__token)
{
  using namespace txpl::lexer;
  BOOST_CHECK(!('\0' < token<>()));
  BOOST_CHECK(!('(' < token<>(token_t::lparen_,nullptr,nullptr)));
  BOOST_CHECK(!(')' < token<>(token_t::lparen_,nullptr,nullptr)));
  BOOST_CHECK('(' < token<>(token_t::rparen_,nullptr,nullptr));
}
BOOST_AUTO_TEST_CASE(wchar_t__lt__token)
{
  using namespace txpl::lexer;
  BOOST_CHECK(!(L'\0' < token<>()));
  BOOST_CHECK(!(L'(' < token<>(token_t::lparen_,nullptr,nullptr)));
  BOOST_CHECK(!(L')' < token<>(token_t::lparen_,nullptr,nullptr)));
  BOOST_CHECK(L'(' < token<>(token_t::rparen_,nullptr,nullptr));
}
BOOST_AUTO_TEST_CASE(token__gt__token_t)
{
  using namespace txpl::lexer;
  BOOST_CHECK(!(token<>() > static_cast<token_t>(0)));
  BOOST_CHECK(!(token<>(token_t::lparen_,nullptr,nullptr) > token_t::lparen_));
  BOOST_CHECK(token<>(token_t::rparen_,nullptr,nullptr) > token_t::lparen_);
  BOOST_CHECK(!(token<>(token_t::lparen_,nullptr,nullptr) > token_t::rparen_));
}
BOOST_AUTO_TEST_CASE(token__gt__char)
{
  using namespace txpl::lexer;
  BOOST_CHECK(!(token<>() > '\0'));
  BOOST_CHECK(!(token<>(token_t::lparen_,nullptr,nullptr) > '('));
  BOOST_CHECK(token<>(token_t::rparen_,nullptr,nullptr) > '(');
  BOOST_CHECK(!(token<>(token_t::lparen_,nullptr,nullptr) > ')'));
}
BOOST_AUTO_TEST_CASE(token__gt__wchar_t)
{
  using namespace txpl::lexer;
  BOOST_CHECK(!(token<>() > L'\0'));
  BOOST_CHECK(!(token<>(token_t::lparen_,nullptr,nullptr) > L'('));
  BOOST_CHECK(token<>(token_t::rparen_,nullptr,nullptr) > L'(');
  BOOST_CHECK(!(token<>(token_t::lparen_,nullptr,nullptr) > L')'));
}
BOOST_AUTO_TEST_CASE(token_t__gt__token)
{
  using namespace txpl::lexer;
  BOOST_CHECK(!(static_cast<token_t>(0) > token<>()));
  BOOST_CHECK(!(token_t::lparen_ > token<>(token_t::lparen_,nullptr,nullptr)));
  BOOST_CHECK(token_t::rparen_ > token<>(token_t::lparen_,nullptr,nullptr));
  BOOST_CHECK(!(token_t::lparen_ > token<>(token_t::rparen_,nullptr,nullptr)));
}
BOOST_AUTO_TEST_CASE(char__gt__token)
{
  using namespace txpl::lexer;
  BOOST_CHECK(!('\0' > token<>()));
  BOOST_CHECK(!('(' > token<>(token_t::lparen_,nullptr,nullptr)));
  BOOST_CHECK(')' > token<>(token_t::lparen_,nullptr,nullptr));
  BOOST_CHECK(!('(' > token<>(token_t::rparen_,nullptr,nullptr)));
}
BOOST_AUTO_TEST_CASE(wchar_t__gt__token)
{
  using namespace txpl::lexer;
  BOOST_CHECK(!(L'\0' > token<>()));
  BOOST_CHECK(!(L'(' > token<>(token_t::lparen_,nullptr,nullptr)));
  BOOST_CHECK(L')' > token<>(token_t::lparen_,nullptr,nullptr));
  BOOST_CHECK(!(L'(' > token<>(token_t::rparen_,nullptr,nullptr)));
}
BOOST_AUTO_TEST_CASE(token__le__token_t)
{
  using namespace txpl::lexer;
  BOOST_CHECK(token<>() <= static_cast<token_t>(0));
  BOOST_CHECK(token<>(token_t::lparen_,nullptr,nullptr) <= token_t::lparen_);
  BOOST_CHECK(!(token<>(token_t::rparen_,nullptr,nullptr) <= token_t::lparen_));
  BOOST_CHECK(token<>(token_t::lparen_,nullptr,nullptr) <= token_t::rparen_);
}
BOOST_AUTO_TEST_CASE(token__le__char)
{
  using namespace txpl::lexer;
  BOOST_CHECK(token<>() <= '\0');
  BOOST_CHECK(token<>(token_t::lparen_,nullptr,nullptr) <= '(');
  BOOST_CHECK(!(token<>(token_t::rparen_,nullptr,nullptr) <= '('));
  BOOST_CHECK(token<>(token_t::lparen_,nullptr,nullptr) <= ')');
}
BOOST_AUTO_TEST_CASE(token__le__wchar_t)
{
  using namespace txpl::lexer;
  BOOST_CHECK(token<>() <= L'\0');
  BOOST_CHECK(token<>(token_t::lparen_,nullptr,nullptr) <= L'(');
  BOOST_CHECK(!(token<>(token_t::rparen_,nullptr,nullptr) <= L'('));
  BOOST_CHECK(token<>(token_t::lparen_,nullptr,nullptr) <= L')');
}
BOOST_AUTO_TEST_CASE(token_t__le__token)
{
  using namespace txpl::lexer;
  BOOST_CHECK(static_cast<token_t>(0) <= token<>());
  BOOST_CHECK(token_t::lparen_ <= token<>(token_t::lparen_,nullptr,nullptr));
  BOOST_CHECK(!(token_t::rparen_ <= token<>(token_t::lparen_,nullptr,nullptr)));
  BOOST_CHECK(token_t::lparen_ <= token<>(token_t::rparen_,nullptr,nullptr));
}
BOOST_AUTO_TEST_CASE(char__le__token)
{
  using namespace txpl::lexer;
  BOOST_CHECK('\0' <= token<>());
  BOOST_CHECK('(' <= token<>(token_t::lparen_,nullptr,nullptr));
  BOOST_CHECK(!(')' <= token<>(token_t::lparen_,nullptr,nullptr)));
  BOOST_CHECK('(' <= token<>(token_t::rparen_,nullptr,nullptr));
}
BOOST_AUTO_TEST_CASE(wchar_t__le__token)
{
  using namespace txpl::lexer;
  BOOST_CHECK(L'\0' <= token<>());
  BOOST_CHECK(L'(' <= token<>(token_t::lparen_,nullptr,nullptr));
  BOOST_CHECK(!(L')' <= token<>(token_t::lparen_,nullptr,nullptr)));
  BOOST_CHECK(L'(' <= token<>(token_t::rparen_,nullptr,nullptr));
}
BOOST_AUTO_TEST_CASE(token__ge__token_t)
{
  using namespace txpl::lexer;
  BOOST_CHECK(token<>() >= static_cast<token_t>(0));
  BOOST_CHECK(token<>(token_t::lparen_,nullptr,nullptr) >= token_t::lparen_);
  BOOST_CHECK(token<>(token_t::rparen_,nullptr,nullptr) >= token_t::lparen_);
  BOOST_CHECK(!(token<>(token_t::lparen_,nullptr,nullptr) >= token_t::rparen_));
}
BOOST_AUTO_TEST_CASE(token__ge__char)
{
  using namespace txpl::lexer;
  BOOST_CHECK(token<>() >= '\0');
  BOOST_CHECK(token<>(token_t::lparen_,nullptr,nullptr) >= '(');
  BOOST_CHECK(token<>(token_t::rparen_,nullptr,nullptr) >= '(');
  BOOST_CHECK(!(token<>(token_t::lparen_,nullptr,nullptr) >= ')'));
}
BOOST_AUTO_TEST_CASE(token__ge__wchar_t)
{
  using namespace txpl::lexer;
  BOOST_CHECK(token<>() >= L'\0');
  BOOST_CHECK(token<>(token_t::lparen_,nullptr,nullptr) >= L'(');
  BOOST_CHECK(token<>(token_t::rparen_,nullptr,nullptr) >= L'(');
  BOOST_CHECK(!(token<>(token_t::lparen_,nullptr,nullptr) >= L')'));
}
BOOST_AUTO_TEST_CASE(token_t__ge__token)
{
  using namespace txpl::lexer;
  BOOST_CHECK(static_cast<token_t>(0) >= token<>());
  BOOST_CHECK(token_t::lparen_ >= token<>(token_t::lparen_,nullptr,nullptr));
  BOOST_CHECK(token_t::rparen_ >= token<>(token_t::lparen_,nullptr,nullptr));
  BOOST_CHECK(!(token_t::lparen_ >= token<>(token_t::rparen_,nullptr,nullptr)));
}
BOOST_AUTO_TEST_CASE(char__ge__token)
{
  using namespace txpl::lexer;
  BOOST_CHECK('\0' >= token<>());
  BOOST_CHECK('(' >= token<>(token_t::lparen_,nullptr,nullptr));
  BOOST_CHECK(')' >= token<>(token_t::lparen_,nullptr,nullptr));
  BOOST_CHECK(!('(' >= token<>(token_t::rparen_,nullptr,nullptr)));
}
BOOST_AUTO_TEST_CASE(wchar_t__ge__token)
{
  using namespace txpl::lexer;
  BOOST_CHECK(L'\0' >= token<>());
  BOOST_CHECK(L'(' >= token<>(token_t::lparen_,nullptr,nullptr));
  BOOST_CHECK(L')' >= token<>(token_t::lparen_,nullptr,nullptr));
  BOOST_CHECK(!(L'(' >= token<>(token_t::rparen_,nullptr,nullptr)));
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{ 
  BOOST_CHECK(true);
}
#endif
