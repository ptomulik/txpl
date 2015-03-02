// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_lexer_try_hex_number

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_LEXER_TRY_HEX_NUMBER

#include <txpl/lexer/try_hex_number.hpp>

BOOST_AUTO_TEST_CASE(cstr)
{
  using namespace txpl::lexer;
  {
    const char *str = "00";
    const char *first = str, *last = first + 2;
    BOOST_CHECK(try_hex_number(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "AB";
    const char *first = str, *last = first + 2;
    BOOST_CHECK(try_hex_number(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "cD";
    const char *first = str, *last = first + 2;
    BOOST_CHECK(try_hex_number(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "Ef";
    const char *first = str, *last = first + 2;
    BOOST_CHECK(try_hex_number(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "1A";
    const char *first = str, *last = first+2;
    BOOST_CHECK(try_hex_number(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "2Bz";
    const char *first = str, *last = first+3;
    BOOST_CHECK(try_hex_number(first, last));
    BOOST_CHECK(first == str+2);
  }
  {
    const char *str = "";
    const char *first = str, *last = first;
    BOOST_CHECK(!try_hex_number(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "@1A";
    const char *first = str, *last = first+3;
    BOOST_CHECK(!try_hex_number(first, last));
    BOOST_CHECK(first == str);
  }
}
BOOST_AUTO_TEST_CASE(cwstr)
{
  using namespace txpl::lexer;
  {
    const wchar_t *str = L"00";
    const wchar_t *first = str, *last = first + 2;
    BOOST_CHECK(try_hex_number(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"AB";
    const wchar_t *first = str, *last = first + 2;
    BOOST_CHECK(try_hex_number(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"cD";
    const wchar_t *first = str, *last = first + 2;
    BOOST_CHECK(try_hex_number(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"Ef";
    const wchar_t *first = str, *last = first + 2;
    BOOST_CHECK(try_hex_number(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"1A";
    const wchar_t *first = str, *last = first+2;
    BOOST_CHECK(try_hex_number(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"2Bz";
    const wchar_t *first = str, *last = first+3;
    BOOST_CHECK(try_hex_number(first, last));
    BOOST_CHECK(first == str+2);
  }
  {
    const wchar_t *str = L"";
    const wchar_t *first = str, *last = first;
    BOOST_CHECK(!try_hex_number(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"@1A";
    const wchar_t *first = str, *last = first+3;
    BOOST_CHECK(!try_hex_number(first, last));
    BOOST_CHECK(first == str);
  }
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{ 
  BOOST_CHECK(true);
}
#endif
