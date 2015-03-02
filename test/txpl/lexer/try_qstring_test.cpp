// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_lexer_try_qstring

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_LEXER_TRY_QSTRING

#include <txpl/lexer/try_qstring.hpp>

BOOST_AUTO_TEST_CASE(cstr)
{
  using namespace txpl::lexer;
  {
    const char *str = "\"\"";
    const char *first = str, *last = first + 2;
    BOOST_CHECK(try_qstring(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "\"simple string\"";
    const char *first = str, *last = first + 15;
    BOOST_CHECK(try_qstring(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "\"\\\"\\\'\\\?\\\\\\a\\b\\f\\n\\r\\t\\v\"";
    const char *first = str, *last = first + 24;
    BOOST_CHECK(try_qstring(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "";
    const char *first = str, *last = first;
    BOOST_CHECK(!try_qstring(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "simple";
    const char *first = str, *last = first+6;
    BOOST_CHECK(!try_qstring(first, last));
    BOOST_CHECK(first == str);
  }
  {
    const char *str = "\"";
    const char *first = str, *last = first+1;
    BOOST_CHECK(!try_qstring(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "\"simple";
    const char *first = str, *last = first+7;
    BOOST_CHECK(!try_qstring(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "\"s\"imple";
    const char *first = str, *last = first+8;
    BOOST_CHECK(try_qstring(first, last));
    BOOST_CHECK(first == str+3);
  }
}
BOOST_AUTO_TEST_CASE(cwstr)
{
  using namespace txpl::lexer;
  {
    const wchar_t *str = L"\"\"";
    const wchar_t *first = str, *last = first + 2;
    BOOST_CHECK(try_qstring(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"\"simple string\"";
    const wchar_t *first = str, *last = first + 15;
    BOOST_CHECK(try_qstring(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"\"\\\"\\\'\\\?\\\\\\a\\b\\f\\n\\r\\t\\v\"";
    const wchar_t *first = str, *last = first + 24;
    BOOST_CHECK(try_qstring(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"";
    const wchar_t *first = str, *last = first;
    BOOST_CHECK(!try_qstring(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"simple";
    const wchar_t *first = str, *last = first+6;
    BOOST_CHECK(!try_qstring(first, last));
    BOOST_CHECK(first == str);
  }
  {
    const wchar_t *str = L"\"";
    const wchar_t *first = str, *last = first+1;
    BOOST_CHECK(!try_qstring(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"\"simple";
    const wchar_t *first = str, *last = first+7;
    BOOST_CHECK(!try_qstring(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"\"s\"imple";
    const wchar_t *first = str, *last = first+8;
    BOOST_CHECK(try_qstring(first, last));
    BOOST_CHECK(first == str+3);
  }
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{ 
  BOOST_CHECK(true);
}
#endif
