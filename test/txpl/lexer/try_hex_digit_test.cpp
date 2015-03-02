// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_lexer_try_hex_digit

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_LEXER_TRY_HEX_DIGIT

#include <txpl/lexer/try_hex_digit.hpp>

BOOST_AUTO_TEST_CASE(cstr)
{
  using namespace txpl::lexer;
  {
    const char *str = "0";
    const char *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "1";
    const char *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "2";
    const char *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "3";
    const char *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "4";
    const char *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "5";
    const char *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "6";
    const char *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "7";
    const char *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "8";
    const char *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "9";
    const char *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "a";
    const char *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "b";
    const char *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "c";
    const char *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "d";
    const char *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "e";
    const char *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "f";
    const char *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "A";
    const char *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "B";
    const char *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "C";
    const char *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "D";
    const char *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "E";
    const char *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "F";
    const char *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "a";
    const char *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "ab1";
    const char *first = str, *last = first + 3;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == str+1);
  }
  {
    const char *str = "";
    const char *first = str, *last = first;
    BOOST_CHECK(!try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "x";
    const char *first = str, *last = first;
    BOOST_CHECK(!try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "x";
    const char *first = str, *last = first + 1;
    BOOST_CHECK(!try_hex_digit(first, last));
    BOOST_CHECK(first == str);
  }
}
BOOST_AUTO_TEST_CASE(cwstr)
{
  using namespace txpl::lexer;
  {
    const wchar_t *str = L"0";
    const wchar_t *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"1";
    const wchar_t *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"2";
    const wchar_t *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"3";
    const wchar_t *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"4";
    const wchar_t *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"5";
    const wchar_t *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"6";
    const wchar_t *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"7";
    const wchar_t *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"8";
    const wchar_t *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"9";
    const wchar_t *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"a";
    const wchar_t *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"b";
    const wchar_t *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"c";
    const wchar_t *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"d";
    const wchar_t *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"e";
    const wchar_t *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"f";
    const wchar_t *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"A";
    const wchar_t *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"B";
    const wchar_t *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"C";
    const wchar_t *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"D";
    const wchar_t *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"E";
    const wchar_t *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"F";
    const wchar_t *first = str, *last = first + 1;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  //
  {
    const wchar_t *str = L"ab1";
    const wchar_t *first = str, *last = first + 3;
    BOOST_CHECK(try_hex_digit(first, last));
    BOOST_CHECK(first == str+1);
  }
  //
  {
    const wchar_t *str = L"";
    const wchar_t *first = str, *last = first;
    BOOST_CHECK(!try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"x";
    const wchar_t *first = str, *last = first;
    BOOST_CHECK(!try_hex_digit(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"x";
    const wchar_t *first = str, *last = first + 1;
    BOOST_CHECK(!try_hex_digit(first, last));
    BOOST_CHECK(first == str);
  }
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{ 
  BOOST_CHECK(true);
}
#endif
