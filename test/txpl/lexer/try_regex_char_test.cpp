// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_lexer_try_regex_char

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_LEXER_TRY_REGEX_CHAR

#include <txpl/lexer/try_regex_char.hpp>

BOOST_AUTO_TEST_CASE(cstr)
{
  using namespace txpl::lexer;
  {
    const char *str = "a";
    const char *first = str, *last = first + 1;
    BOOST_CHECK(try_regex_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "A";
    const char *first = str, *last = first + 1;
    BOOST_CHECK(try_regex_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "\\0";
    const char *first = str, *last = first + 2;
    BOOST_CHECK(try_regex_char(first, last));
    BOOST_CHECK(first == str+1);
  }
  {
    const char *str = "\\1";
    const char *first = str, *last = first + 2;
    BOOST_CHECK(try_regex_char(first, last));
    BOOST_CHECK(first == str+1);
  }
  {
    const char *str = "\\\"";
    const char *first = str, *last = first + 2;
    BOOST_CHECK(try_regex_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "\\";
    const char *first = str, *last = first+1;
    BOOST_CHECK(try_regex_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "\\x1";
    const char *first = str, *last = first+3;
    BOOST_CHECK(try_regex_char(first, last));
    BOOST_CHECK(first == str+1);
  }
  {
    const char *str = "";
    const char *first = str, *last = first;
    BOOST_CHECK(!try_regex_char(first, last));
    BOOST_CHECK(first == last);
  }
}
BOOST_AUTO_TEST_CASE(cwstr)
{
  using namespace txpl::lexer;
  {
    const wchar_t *str = L"a";
    const wchar_t *first = str, *last = first + 1;
    BOOST_CHECK(try_regex_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"A";
    const wchar_t *first = str, *last = first + 1;
    BOOST_CHECK(try_regex_char(first, last));
    BOOST_CHECK(first == last);
  }

  {
    const wchar_t *str = L"\\0";
    const wchar_t *first = str, *last = first + 2;
    BOOST_CHECK(try_regex_char(first, last));
    BOOST_CHECK(first == str+1);
  }
  {
    const wchar_t *str = L"\\1";
    const wchar_t *first = str, *last = first + 2;
    BOOST_CHECK(try_regex_char(first, last));
    BOOST_CHECK(first == str+1);
  }
  {
    const wchar_t *str = L"\\\"";
    const wchar_t *first = str, *last = first + 2;
    BOOST_CHECK(try_regex_char(first, last));
    BOOST_CHECK(first == last);
  }

  {
    const wchar_t *str = L"\\";
    const wchar_t *first = str, *last = first+1;
    BOOST_CHECK(try_regex_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"\\x1";
    const wchar_t *first = str, *last = first+3;
    BOOST_CHECK(try_regex_char(first, last));
    BOOST_CHECK(first == str+1);
  }
  {
    const wchar_t *str = L"";
    const wchar_t *first = str, *last = first;
    BOOST_CHECK(!try_regex_char(first, last));
    BOOST_CHECK(first == last);
  }
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{ 
  BOOST_CHECK(true);
}
#endif
