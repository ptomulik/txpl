// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_lexer_get_qchar

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_LEXER_GET_QCHAR

#include <txpl/lexer/get_qchar.hpp>
#include <txpl/lexer/bind_error_handler.hpp>

BOOST_AUTO_TEST_CASE(cstr__char)
{
  using namespace txpl::lexer;
  const char *efirst;
  const char *elast;
  std::string emsg;
  auto eh = bind_error_handler(efirst, elast, emsg);
  {
    const char *str = "";
    const char *first = str, *last = first;
    char x = 'x';
    efirst = elast = nullptr; emsg = "";
    BOOST_CHECK(!get_qchar(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 'x');
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "expected opening single-quote");
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "a";
    const char *first = str, *last = first+1;
    char x = 'x';
    efirst = elast = nullptr; emsg = "";
    BOOST_CHECK(!get_qchar(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 'x');
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "expected opening single-quote");
    BOOST_CHECK(first == str);
  }
  {
    const char *str = "'";
    const char *first = str, *last = first+1;
    char x = 'x';
    efirst = elast = nullptr; emsg = "";
    BOOST_CHECK(!get_qchar(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 'x');
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "incomplete quoted-character");
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "''";
    const char *first = str, *last = first+2;
    char x = 'x';
    efirst = elast = nullptr; emsg = "";
    BOOST_CHECK(!get_qchar(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 'x');
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "unexpected single-quote");
    BOOST_CHECK(first == str+1);
  }
  {
    const char *str = "'a";
    const char *first = str, *last = first+2;
    char x = 'x';
    efirst = elast = nullptr; emsg = "";
    BOOST_CHECK(!get_qchar(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 'x');
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "expected closing single-quote");
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "'as'";
    const char *first = str, *last = first+4;
    char x = 'x';
    efirst = elast = nullptr; emsg = "";
    BOOST_CHECK(!get_qchar(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 'x');
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "expected closing single-quote");
    BOOST_CHECK(first == str+2);
  }
  {
    const char *str = "'a'";
    const char *first = str, *last = first + 3;
    char x = 'x';
    efirst = elast = nullptr; emsg = "";
    BOOST_CHECK(get_qchar(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 'a');
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "'a'sd";
    const char *first = str, *last = first + 5;
    char x = 'x';
    efirst = elast = nullptr; emsg = "";
    BOOST_CHECK(get_qchar(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 'a');
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == str+3);
  }
}
BOOST_AUTO_TEST_CASE(cwstr__wchar_t)
{
  using namespace txpl::lexer;
  const wchar_t *efirst;
  const wchar_t *elast;
  std::string emsg;
  auto eh = bind_error_handler(efirst, elast, emsg);
  {
    const wchar_t *str = L"";
    const wchar_t *first = str, *last = first;
    wchar_t x = L'x';
    efirst = elast = nullptr; emsg = "";
    BOOST_CHECK(!get_qchar(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, L'x');
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "expected opening single-quote");
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"a";
    const wchar_t *first = str, *last = first+1;
    wchar_t x = L'x';
    efirst = elast = nullptr; emsg = "";
    BOOST_CHECK(!get_qchar(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, L'x');
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "expected opening single-quote");
    BOOST_CHECK(first == str);
  }
  {
    const wchar_t *str = L"'";
    const wchar_t *first = str, *last = first+1;
    wchar_t x = L'x';
    efirst = elast = nullptr; emsg = "";
    BOOST_CHECK(!get_qchar(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, L'x');
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "incomplete quoted-character");
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"''";
    const wchar_t *first = str, *last = first+2;
    wchar_t x = L'x';
    efirst = elast = nullptr; emsg = "";
    BOOST_CHECK(!get_qchar(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, L'x');
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "unexpected single-quote");
    BOOST_CHECK(first == str+1);
  }
  {
    const wchar_t *str = L"'a";
    const wchar_t *first = str, *last = first+2;
    wchar_t x = L'x';
    efirst = elast = nullptr; emsg = "";
    BOOST_CHECK(!get_qchar(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, L'x');
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "expected closing single-quote");
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"'as'";
    const wchar_t *first = str, *last = first+4;
    wchar_t x = L'x';
    efirst = elast = nullptr; emsg = "";
    BOOST_CHECK(!get_qchar(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, L'x');
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "expected closing single-quote");
    BOOST_CHECK(first == str+2);
  }
  {
    const wchar_t *str = L"'a'";
    const wchar_t *first = str, *last = first + 3;
    wchar_t x = L'x';
    efirst = elast = nullptr; emsg = "";
    BOOST_CHECK(get_qchar(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, L'a');
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"'a'sd";
    const wchar_t *first = str, *last = first + 5;
    wchar_t x = L'x';
    efirst = elast = nullptr; emsg = "";
    BOOST_CHECK(get_qchar(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, L'a');
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == str+3);
  }
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{ 
  BOOST_CHECK(true);
}
#endif
