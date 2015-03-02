// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_lexer_get_content

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_LEXER_GET_CONTENT

#include <txpl/lexer/get_content.hpp>
#include <txpl/lexer/bind_error_handler.hpp>

BOOST_AUTO_TEST_CASE(cstr_string)
{
  using namespace txpl::lexer;
  const char *efirst;
  const char *elast;
  std::string emsg;
  auto eh = bind_error_handler(efirst, elast, emsg);
  {
    const char *str = "";
    const char *first = str, *last = first;
    std::string x = "x";
    efirst = elast = nullptr; emsg = "";
    BOOST_CHECK(get_content(first, last, x, eh));
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == last);
    BOOST_CHECK_EQUAL(x, "");
  }
  {
    const char *str = "any string";
    const char *first = str, *last = first + 10;
    std::string x = "x";
    efirst = elast = nullptr; emsg = "";
    BOOST_CHECK(get_content(first, last, x, eh));
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == last);
    BOOST_CHECK_EQUAL(x, "any string");
  }
}
BOOST_AUTO_TEST_CASE(cwstr_wstring)
{
  using namespace txpl::lexer;
  const wchar_t *efirst;
  const wchar_t *elast;
  std::string emsg;
  auto eh = bind_error_handler(efirst, elast, emsg);
  {
    const wchar_t *str = L"";
    const wchar_t *first = str, *last = first;
    std::wstring x = L"x";
    efirst = elast = nullptr; emsg = "";
    BOOST_CHECK(get_content(first, last, x, eh));
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == last);
    BOOST_CHECK(x == L"");
  }
  {
    const wchar_t *str = L"any string";
    const wchar_t *first = str, *last = first + 10;
    std::wstring x = L"x";
    efirst = elast = nullptr; emsg = "";
    BOOST_CHECK(get_content(first, last, x, eh));
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == last);
    BOOST_CHECK(x == L"any string");
  }
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{ 
  BOOST_CHECK(true);
}
#endif
