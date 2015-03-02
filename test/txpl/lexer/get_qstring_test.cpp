// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt
#define BOOST_TEST_MODULE test_txpl_lexer_get_qstring

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_LEXER_GET_QSTRING

#include <txpl/lexer/get_qstring.hpp>
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
    BOOST_CHECK(!get_qstring(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, "x");
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "expected opening double-quote");
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "s";
    const char *first = str, *last = first+1;
    efirst = elast = nullptr; emsg = "";
    std::string x = "x";
    BOOST_CHECK(!get_qstring(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, "x");
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "expected opening double-quote");
    BOOST_CHECK(first == str);
  }
  {
    const char *str = "\"a\t\"";
    const char *first = str, *last = first + 4;
    efirst = elast = nullptr; emsg = "";
    std::string x = "x";
    BOOST_CHECK(!get_qstring(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, "x");
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "non-printable character in character specification");
    BOOST_CHECK(first == str+2);
  }
  {
    const char *str = "\"";
    const char *first = str, *last = first+1;
    efirst = elast = nullptr; emsg = "";
    std::string x = "x";
    BOOST_CHECK(!get_qstring(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, "x");
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "incomplete double-quoted string");
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "\"simple";
    const char *first = str, *last = first+7;
    efirst = elast = nullptr; emsg = "";
    std::string x = "x";
    BOOST_CHECK(!get_qstring(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, "x");
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "incomplete double-quoted string");
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "\"\"";
    const char *first = str, *last = first + 2;
    efirst = elast = nullptr; emsg = "";
    std::string x = "x";
    BOOST_CHECK(get_qstring(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, "");
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "\"\\\"\\\'\\\?\\\\\\a\\b\\f\\n\\r\\t\\v\"";
    const char *first = str, *last = first + 24;
    efirst = elast = nullptr; emsg = "";
    std::string x = "x";
    BOOST_CHECK(get_qstring(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, "\"\'\?\\\a\b\f\n\r\t\v");
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "\"s\"imple";
    const char *first = str, *last = first+8;
    efirst = elast = nullptr; emsg = "";
    std::string x = "x";
    BOOST_CHECK(get_qstring(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, "s");
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == str+3);
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
    BOOST_CHECK(!get_qstring(first, last, x, eh));
    BOOST_CHECK(x == L"x");
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "expected opening double-quote");
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"s";
    const wchar_t *first = str, *last = first+1;
    efirst = elast = nullptr; emsg = "";
    std::wstring x = L"x";
    BOOST_CHECK(!get_qstring(first, last, x, eh));
    BOOST_CHECK(x == L"x");
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "expected opening double-quote");
    BOOST_CHECK(first == str);
  }
  {
    const wchar_t *str = L"\"a\t\"";
    const wchar_t *first = str, *last = first + 4;
    efirst = elast = nullptr; emsg = "";
    std::wstring x = L"x";
    BOOST_CHECK(!get_qstring(first, last, x, eh));
    BOOST_CHECK(x == L"x");
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "non-printable character in character specification");
    BOOST_CHECK(first == str+2);
  }
  {
    const wchar_t *str = L"\"";
    const wchar_t *first = str, *last = first+1;
    efirst = elast = nullptr; emsg = "";
    std::wstring x = L"x";
    BOOST_CHECK(!get_qstring(first, last, x, eh));
    BOOST_CHECK(x == L"x");
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "incomplete double-quoted string");
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"\"simple";
    const wchar_t *first = str, *last = first+7;
    efirst = elast = nullptr; emsg = "";
    std::wstring x = L"x";
    BOOST_CHECK(!get_qstring(first, last, x, eh));
    BOOST_CHECK(x == L"x");
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "incomplete double-quoted string");
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"\"\"";
    const wchar_t *first = str, *last = first + 2;
    efirst = elast = nullptr; emsg = "";
    std::wstring x = L"x";
    BOOST_CHECK(get_qstring(first, last, x, eh));
    BOOST_CHECK(x == L"");
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"\"\\\"\\\'\\\?\\\\\\a\\b\\f\\n\\r\\t\\v\"";
    const wchar_t *first = str, *last = first + 24;
    efirst = elast = nullptr; emsg = "";
    std::wstring x = L"x";
    BOOST_CHECK(get_qstring(first, last, x, eh));
    BOOST_CHECK(x == L"\"\'\?\\\a\b\f\n\r\t\v");
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"\"s\"imple";
    const wchar_t *first = str, *last = first+8;
    efirst = elast = nullptr; emsg = "";
    std::wstring x = L"x";
    BOOST_CHECK(get_qstring(first, last, x, eh));
    BOOST_CHECK(x == L"s");
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
