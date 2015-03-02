// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_lexer_get_regex_char

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_LEXER_GET_REGEX_CHAR

#include <txpl/lexer/get_regex_char.hpp>
#include <txpl/lexer/bind_error_handler.hpp>

BOOST_AUTO_TEST_CASE(cstr__char)
{
  using namespace txpl::lexer;
  const char* efirst;
  const char* elast;
  std::string emsg;
  auto eh = bind_error_handler(efirst, elast, emsg);
  {
    const char *str = "";
    const char *first = str, *last = first;
    efirst = elast = nullptr; emsg = "";
    char x = 'x';
    BOOST_CHECK(!get_regex_char(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 'x');
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "expected regex-character specification");
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "a";
    const char *first = str, *last = first + 1;
    efirst = elast = nullptr; emsg = "";
    char x = 'x';
    BOOST_CHECK(get_regex_char(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 'a');
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "\\";
    const char *first = str, *last = first+1;
    efirst = elast = nullptr; emsg = "";
    char x = 'x';
    BOOST_CHECK(get_regex_char(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, '\\');
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "\\0";
    const char *first = str, *last = first + 2;
    efirst = elast = nullptr; emsg = "";
    char x = 'x';
    BOOST_CHECK(get_regex_char(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, '\\');
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == str+1);
  }
  {
    const char *str = "\\\"";
    const char *first = str, *last = first + 2;
    efirst = elast = nullptr; emsg = "";
    char x = 'x';
    BOOST_CHECK(get_regex_char(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, '\"');
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "\\x1";
    const char *first = str, *last = first+3;
    efirst = elast = nullptr; emsg = "";
    char x = 'x';
    BOOST_CHECK(get_regex_char(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, '\\');
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == str+1);
  }
}
BOOST_AUTO_TEST_CASE(cwstr__wchar_t)
{
  using namespace txpl::lexer;
  const wchar_t* efirst;
  const wchar_t* elast;
  std::string emsg;
  auto eh = bind_error_handler(efirst, elast, emsg);
  {
    const wchar_t *str = L"";
    const wchar_t *first = str, *last = first;
    efirst = elast = nullptr; emsg = "";
    wchar_t x = L'x';
    BOOST_CHECK(!get_regex_char(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, L'x');
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "expected regex-character specification");
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"a";
    const wchar_t *first = str, *last = first + 1;
    efirst = elast = nullptr; emsg = "";
    wchar_t x = L'x';
    BOOST_CHECK(get_regex_char(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, L'a');
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"\\";
    const wchar_t *first = str, *last = first+1;
    efirst = elast = nullptr; emsg = "";
    wchar_t x = L'x';
    BOOST_CHECK(get_regex_char(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, L'\\');
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"\\0";
    const wchar_t *first = str, *last = first + 2;
    efirst = elast = nullptr; emsg = "";
    wchar_t x = L'x';
    BOOST_CHECK(get_regex_char(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, L'\\');
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == str+1);
  }
  {
    const wchar_t *str = L"\\\"";
    const wchar_t *first = str, *last = first + 2;
    efirst = elast = nullptr; emsg = "";
    wchar_t x = L'x';
    BOOST_CHECK(get_regex_char(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, L'\"');
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"\\x1";
    const wchar_t *first = str, *last = first+3;
    efirst = elast = nullptr; emsg = "";
    wchar_t x = L'x';
    BOOST_CHECK(get_regex_char(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, L'\\');
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == str+1);
  }
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{ 
  BOOST_CHECK(true);
}
#endif
