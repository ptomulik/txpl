// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_lexer_try_oct_digit

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_LEXER_TRY_OCT_DIGIT

#include <txpl/lexer/try_oct_digit.hpp>

BOOST_AUTO_TEST_CASE(foo)
{
  using namespace txpl::lexer;
  {
    const char *str = "0";
    const char *first = str, *last = first + 1;
    BOOST_CHECK(try_oct_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "1";
    const char *first = str, *last = first + 1;
    BOOST_CHECK(try_oct_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "2";
    const char *first = str, *last = first + 1;
    BOOST_CHECK(try_oct_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "3";
    const char *first = str, *last = first + 1;
    BOOST_CHECK(try_oct_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "4";
    const char *first = str, *last = first + 1;
    BOOST_CHECK(try_oct_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "5";
    const char *first = str, *last = first + 1;
    BOOST_CHECK(try_oct_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "6";
    const char *first = str, *last = first + 1;
    BOOST_CHECK(try_oct_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "7";
    const char *first = str, *last = first + 1;
    BOOST_CHECK(try_oct_digit(first, last));
    BOOST_CHECK(first == last);
  }
  //
  {
    const char *str = "321";
    const char *first = str, *last = first + 3;
    BOOST_CHECK(try_oct_digit(first, last));
    BOOST_CHECK(first == str+1);
  }
  //
  {
    const char *str = "";
    const char *first = str, *last = first;
    BOOST_CHECK(!try_oct_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "8";
    const char *first = str, *last = first;
    BOOST_CHECK(!try_oct_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "8";
    const char *first = str, *last = first + 1;
    BOOST_CHECK(!try_oct_digit(first, last));
    BOOST_CHECK((first + 1) == last);
  }
}
BOOST_AUTO_TEST_CASE(cwstr)
{
  using namespace txpl::lexer;
  {
    const wchar_t *str = L"0";
    const wchar_t *first = str, *last = first + 1;
    BOOST_CHECK(try_oct_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"1";
    const wchar_t *first = str, *last = first + 1;
    BOOST_CHECK(try_oct_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"2";
    const wchar_t *first = str, *last = first + 1;
    BOOST_CHECK(try_oct_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"3";
    const wchar_t *first = str, *last = first + 1;
    BOOST_CHECK(try_oct_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"4";
    const wchar_t *first = str, *last = first + 1;
    BOOST_CHECK(try_oct_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"5";
    const wchar_t *first = str, *last = first + 1;
    BOOST_CHECK(try_oct_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"6";
    const wchar_t *first = str, *last = first + 1;
    BOOST_CHECK(try_oct_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"7";
    const wchar_t *first = str, *last = first + 1;
    BOOST_CHECK(try_oct_digit(first, last));
    BOOST_CHECK(first == last);
  }
  //
  {
    const wchar_t *str = L"321";
    const wchar_t *first = str, *last = first + 3;
    BOOST_CHECK(try_oct_digit(first, last));
    BOOST_CHECK(first == str+1);
  }
  //
  {
    const wchar_t *str = L"";
    const wchar_t *first = str, *last = first;
    BOOST_CHECK(!try_oct_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"8";
    const wchar_t *first = str, *last = first;
    BOOST_CHECK(!try_oct_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"8";
    const wchar_t *first = str, *last = first + 1;
    BOOST_CHECK(!try_oct_digit(first, last));
    BOOST_CHECK((first + 1) == last);
  }
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{ 
  BOOST_CHECK(true);
}
#endif
