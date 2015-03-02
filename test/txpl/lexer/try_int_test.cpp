// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_lexer_try_int

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_LEXER_TRY_INT

#include <txpl/lexer/try_int.hpp>

BOOST_AUTO_TEST_CASE(cstr)
{
  using namespace txpl::lexer;
  {
    const char *str = "0";
    const char *first = str, *last = first + 1;
    BOOST_CHECK(try_int(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "00";
    const char *first = str, *last = first + 2;
    BOOST_CHECK(try_int(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "01";
    const char *first = str, *last = first + 2;
    BOOST_CHECK(try_int(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "123";
    const char *first = str, *last = first + 3;
    BOOST_CHECK(try_int(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "0123";
    const char *first = str, *last = first + 4;
    BOOST_CHECK(try_int(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "0x123";
    const char *first = str, *last = first + 5;
    BOOST_CHECK(try_int(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "123ab";
    const char *first = str, *last = first + 5;
    BOOST_CHECK(try_int(first, last));
    BOOST_CHECK(first == str+3);
  }
  {
    const char *str = "";
    const char *first = str, *last = first;
    BOOST_CHECK(!try_int(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "x";
    const char *first = str, *last = first+1;
    BOOST_CHECK(!try_int(first, last));
    BOOST_CHECK(first == str);
  }
  {
    const char *str = "0x";
    const char *first = str, *last = first+2;
    BOOST_CHECK(!try_int(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "0xZ";
    const char *first = str, *last = first+3;
    BOOST_CHECK(!try_int(first, last));
    BOOST_CHECK(first == str+2);
  }
}
BOOST_AUTO_TEST_CASE(cwstr)
{
  using namespace txpl::lexer;
  {
    const wchar_t *str = L"0";
    const wchar_t *first = str, *last = first + 1;
    BOOST_CHECK(try_int(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"00";
    const wchar_t *first = str, *last = first + 2;
    BOOST_CHECK(try_int(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"01";
    const wchar_t *first = str, *last = first + 2;
    BOOST_CHECK(try_int(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"123";
    const wchar_t *first = str, *last = first + 3;
    BOOST_CHECK(try_int(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"0123";
    const wchar_t *first = str, *last = first + 4;
    BOOST_CHECK(try_int(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"0x123";
    const wchar_t *first = str, *last = first + 5;
    BOOST_CHECK(try_int(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"123ab";
    const wchar_t *first = str, *last = first + 5;
    BOOST_CHECK(try_int(first, last));
    BOOST_CHECK(first == str+3);
  }
  {
    const wchar_t *str = L"";
    const wchar_t *first = str, *last = first;
    BOOST_CHECK(!try_int(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"x";
    const wchar_t *first = str, *last = first+1;
    BOOST_CHECK(!try_int(first, last));
    BOOST_CHECK(first == str);
  }
  {
    const wchar_t *str = L"0x";
    const wchar_t *first = str, *last = first+2;
    BOOST_CHECK(!try_int(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"0xZ";
    const wchar_t *first = str, *last = first+3;
    BOOST_CHECK(!try_int(first, last));
    BOOST_CHECK(first == str+2);
  }
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{ 
  BOOST_CHECK(true);
}
#endif
