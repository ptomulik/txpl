// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_lexer_try_qchar

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_LEXER_TRY_QCHAR

#include <txpl/lexer/try_qchar.hpp>

BOOST_AUTO_TEST_CASE(cstr)
{
  using namespace txpl::lexer;
  {
    const char *str = "'a'";
    const char *first = str, *last = first + 3;
    BOOST_CHECK(try_qchar(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "'\\a'";
    const char *first = str, *last = first + 4;
    BOOST_CHECK(try_qchar(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "'\\n'";
    const char *first = str, *last = first + 4;
    BOOST_CHECK(try_qchar(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "'\\13'";
    const char *first = str, *last = first + 5;
    BOOST_CHECK(try_qchar(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "'\\x13'";
    const char *first = str, *last = first + 6;
    BOOST_CHECK(try_qchar(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "'a'sd";
    const char *first = str, *last = first + 5;
    BOOST_CHECK(try_qchar(first, last));
    BOOST_CHECK(first == str+3);
  }
  {
    const char *str = "";
    const char *first = str, *last = first;
    BOOST_CHECK(!try_qchar(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "'";
    const char *first = str, *last = first+1;
    BOOST_CHECK(!try_qchar(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "''";
    const char *first = str, *last = first+2;
    BOOST_CHECK(!try_qchar(first, last));
    BOOST_CHECK(first == str+1);
  }
  {
    const char *str = "'a";
    const char *first = str, *last = first+2;
    BOOST_CHECK(!try_qchar(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "'as'";
    const char *first = str, *last = first+4;
    BOOST_CHECK(!try_qchar(first, last));
    BOOST_CHECK(first == str+2);
  }
}
BOOST_AUTO_TEST_CASE(cwstr)
{
  using namespace txpl::lexer;
  {
    const wchar_t *str = L"'a'";
    const wchar_t *first = str, *last = first + 3;
    BOOST_CHECK(try_qchar(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"'\\a'";
    const wchar_t *first = str, *last = first + 4;
    BOOST_CHECK(try_qchar(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"'\\n'";
    const wchar_t *first = str, *last = first + 4;
    BOOST_CHECK(try_qchar(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"'\\13'";
    const wchar_t *first = str, *last = first + 5;
    BOOST_CHECK(try_qchar(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"'\\x13'";
    const wchar_t *first = str, *last = first + 6;
    BOOST_CHECK(try_qchar(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"'a'sd";
    const wchar_t *first = str, *last = first + 5;
    BOOST_CHECK(try_qchar(first, last));
    BOOST_CHECK(first == str+3);
  }
  {
    const wchar_t *str = L"";
    const wchar_t *first = str, *last = first;
    BOOST_CHECK(!try_qchar(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"'";
    const wchar_t *first = str, *last = first+1;
    BOOST_CHECK(!try_qchar(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"''";
    const wchar_t *first = str, *last = first+2;
    BOOST_CHECK(!try_qchar(first, last));
    BOOST_CHECK(first == str+1);
  }
  {
    const wchar_t *str = L"'a";
    const wchar_t *first = str, *last = first+2;
    BOOST_CHECK(!try_qchar(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"'as'";
    const wchar_t *first = str, *last = first+4;
    BOOST_CHECK(!try_qchar(first, last));
  }
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{ 
  BOOST_CHECK(true);
}
#endif
