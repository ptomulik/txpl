// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_lexer_get_word

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_LEXER_GET_WORD

#include <txpl/lexer/get_word.hpp>
#include <txpl/lexer/bind_error_handler.hpp>

BOOST_AUTO_TEST_CASE(cstr__string)
{
  using namespace txpl::lexer;
  const char *efirst;
  const char *elast;
  std::string emsg;
  auto eh = bind_error_handler(efirst, elast, emsg);
  {
    const char *str = "";
    const char *first = str, *last = first;
    efirst = elast = nullptr; emsg = "";
    std::string x = "x";
    BOOST_CHECK(!get_word(first, last, x, eh));
    BOOST_CHECK(efirst == first);
    BOOST_CHECK(elast == last);
    BOOST_CHECK_EQUAL(emsg, "expected letter or '_'");
    BOOST_CHECK(first == str);
    BOOST_CHECK_EQUAL(x, "x");
  }
  {
    const char *str = "7ab";
    const char *first = str, *last = first + 3;
    efirst = elast = nullptr; emsg = "";
    std::string x = "x";
    BOOST_CHECK(!get_word(first, last, x, eh));
    BOOST_CHECK(efirst == first);
    BOOST_CHECK(elast == last);
    BOOST_CHECK_EQUAL(emsg, "expected letter or '_'");
    BOOST_CHECK(first == str);
    BOOST_CHECK_EQUAL(x, "x");
  }
  {
    const char *str = "_a@";
    const char *first = str, *last = first + 3;
    efirst = elast = nullptr; emsg = "";
    std::string x = "x";
    BOOST_CHECK(!get_word(first, last, x, eh));
    BOOST_CHECK(efirst == first);
    BOOST_CHECK(elast == last);
    BOOST_CHECK_EQUAL(emsg, "expected letter, digit, or '_'");
    BOOST_CHECK(first == str+2);
    BOOST_CHECK_EQUAL(x, "x");
  }
  {
    const char *str = "a2_1f";
    const char *first = str, *last = first + 5; 
    efirst = elast = nullptr; emsg = "";
    std::string x = "x";
    BOOST_CHECK(get_word(first, last, x, eh));
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == last);
    BOOST_CHECK_EQUAL(x, "a2_1f");
  }
  {
    const char *str = "_foo0";
    const char *first = str, *last = first + 5; 
    efirst = elast = nullptr; emsg = "";
    std::string x = "x";
    BOOST_CHECK(get_word(first, last, x, eh));
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == last);
    BOOST_CHECK_EQUAL(x, "_foo0");
  }
}
BOOST_AUTO_TEST_CASE(cwstr__wstring)
{
  using namespace txpl::lexer;
  const wchar_t *efirst;
  const wchar_t *elast;
  std::string emsg;
  auto eh = bind_error_handler(efirst, elast, emsg);
  {
    const wchar_t *str = L"";
    const wchar_t *first = str, *last = first;
    efirst = elast = nullptr; emsg = "";
    std::wstring x = L"x";
    BOOST_CHECK(!get_word(first, last, x, eh));
    BOOST_CHECK(efirst == first);
    BOOST_CHECK(elast == last);
    BOOST_CHECK_EQUAL(emsg, "expected letter or '_'");
    BOOST_CHECK(first == str);
    BOOST_CHECK(x == L"x");
  }
  {
    const wchar_t *str = L"7ab";
    const wchar_t *first = str, *last = first + 3;
    efirst = elast = nullptr; emsg = "";
    std::wstring x = L"x";
    BOOST_CHECK(!get_word(first, last, x, eh));
    BOOST_CHECK(efirst == first);
    BOOST_CHECK(elast == last);
    BOOST_CHECK_EQUAL(emsg, "expected letter or '_'");
    BOOST_CHECK(first == str);
    BOOST_CHECK(x == L"x");
  }
  {
    const wchar_t *str = L"_a@";
    const wchar_t *first = str, *last = first + 3;
    efirst = elast = nullptr; emsg = "";
    std::wstring x = L"x";
    BOOST_CHECK(!get_word(first, last, x, eh));
    BOOST_CHECK(efirst == first);
    BOOST_CHECK(elast == last);
    BOOST_CHECK_EQUAL(emsg, "expected letter, digit, or '_'");
    BOOST_CHECK(first == str+2);
    BOOST_CHECK(x == L"x");
  }
  {
    const wchar_t *str = L"a2_1f";
    const wchar_t *first = str, *last = first + 5;
    efirst = elast = nullptr; emsg = "";
    std::wstring x = L"x";
    BOOST_CHECK(get_word(first, last, x, eh));
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == last);
    BOOST_CHECK(x == L"a2_1f");
  }
  {
    const wchar_t *str = L"_foo0";
    const wchar_t *first = str, *last = first + 5;
    efirst = elast = nullptr; emsg = "";
    std::wstring x = L"x";
    BOOST_CHECK(get_word(first, last, x, eh));
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == last);
    BOOST_CHECK(x == L"_foo0");
  }
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{ 
  BOOST_CHECK(true);
}
#endif
