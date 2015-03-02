// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_lexer_try_real

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_LEXER_TRY_REAL

#include <txpl/lexer/try_real.hpp>

BOOST_AUTO_TEST_CASE(cstr)
{
  using namespace txpl::lexer;
  {
    const char *str = "";
    const char *first = str, *last = first;
    BOOST_CHECK(!try_real(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "x";
    const char *first = str, *last = first+1;
    BOOST_CHECK(!try_real(first, last));
    BOOST_CHECK(first == str);
  }
  {
    const char *str = "1";
    const char *first = str, *last = first+1;
    BOOST_CHECK(!try_real(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "0123456789";
    const char *first = str, *last = first+10;
    BOOST_CHECK(!try_real(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "123.";
    const char *first = str, *last = first + 4;
    BOOST_CHECK(try_real(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "123.x";
    const char *first = str, *last = first + 5;
    BOOST_CHECK(try_real(first, last));
    BOOST_CHECK(first == str+4);
  }
  {
    const char *str = ".";
    const char *first = str, *last = first+1;
    BOOST_CHECK(!try_real(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = ".e";
    const char *first = str, *last = first+2;
    BOOST_CHECK(!try_real(first, last));
    BOOST_CHECK(first == str+1);
  }
  {
    const char *str = ".E";
    const char *first = str, *last = first+2;
    BOOST_CHECK(!try_real(first, last));
    BOOST_CHECK(first == str+1);
  }
  {
    const char *str = "1.e";
    const char *first = str, *last = first+3;
    BOOST_CHECK(!try_real(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "1.E";
    const char *first = str, *last = first+3;
    BOOST_CHECK(!try_real(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = ".1e";
    const char *first = str, *last = first+3;
    BOOST_CHECK(!try_real(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = ".1E";
    const char *first = str, *last = first+3;
    BOOST_CHECK(!try_real(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = ".1e+";
    const char *first = str, *last = first+4;
    BOOST_CHECK(!try_real(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = ".1e-";
    const char *first = str, *last = first+4;
    BOOST_CHECK(!try_real(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = ".1e-2";
    const char *first = str, *last = first+5;
    BOOST_CHECK(try_real(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "1.e-2";
    const char *first = str, *last = first+5;
    BOOST_CHECK(try_real(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = ".as";
    const char *first = str, *last = first+3;
    BOOST_CHECK(!try_real(first, last));
    BOOST_CHECK(first == str+1);
  }
  {
    const char *str = "123.";
    const char *first = str, *last = first+4;
    BOOST_CHECK(try_real(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = ".123";
    const char *first = str, *last = first+4;
    BOOST_CHECK(try_real(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "123.456";
    const char *first = str, *last = first+7;
    BOOST_CHECK(try_real(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "123.456@";
    const char *first = str, *last = first+8;
    BOOST_CHECK(try_real(first, last));
    BOOST_CHECK(first == str+7);
  }
}
BOOST_AUTO_TEST_CASE(cwstr)
{
  using namespace txpl::lexer;
  {
    const wchar_t *str = L"";
    const wchar_t *first = str, *last = first;
    BOOST_CHECK(!try_real(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"x";
    const wchar_t *first = str, *last = first+1;
    BOOST_CHECK(!try_real(first, last));
    BOOST_CHECK(first == str);
  }
  {
    const wchar_t *str = L"1";
    const wchar_t *first = str, *last = first+1;
    BOOST_CHECK(!try_real(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"0123456789";
    const wchar_t *first = str, *last = first+10;
    BOOST_CHECK(!try_real(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"123.";
    const wchar_t *first = str, *last = first + 4;
    BOOST_CHECK(try_real(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"123.x";
    const wchar_t *first = str, *last = first + 5;
    BOOST_CHECK(try_real(first, last));
    BOOST_CHECK(first == str+4);
  }
  {
    const wchar_t *str = L".";
    const wchar_t *first = str, *last = first+1;
    BOOST_CHECK(!try_real(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L".e";
    const wchar_t *first = str, *last = first+2;
    BOOST_CHECK(!try_real(first, last));
    BOOST_CHECK(first == str+1);
  }
  {
    const wchar_t *str = L".E";
    const wchar_t *first = str, *last = first+2;
    BOOST_CHECK(!try_real(first, last));
    BOOST_CHECK(first == str+1);
  }
  {
    const wchar_t *str = L"1.e";
    const wchar_t *first = str, *last = first+3;
    BOOST_CHECK(!try_real(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"1.E";
    const wchar_t *first = str, *last = first+3;
    BOOST_CHECK(!try_real(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L".1e";
    const wchar_t *first = str, *last = first+3;
    BOOST_CHECK(!try_real(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L".1E";
    const wchar_t *first = str, *last = first+3;
    BOOST_CHECK(!try_real(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L".1e+";
    const wchar_t *first = str, *last = first+4;
    BOOST_CHECK(!try_real(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L".1e-";
    const wchar_t *first = str, *last = first+4;
    BOOST_CHECK(!try_real(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L".1e-2";
    const wchar_t *first = str, *last = first+5;
    BOOST_CHECK(try_real(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"1.e-2";
    const wchar_t *first = str, *last = first+5;
    BOOST_CHECK(try_real(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L".as";
    const wchar_t *first = str, *last = first+3;
    BOOST_CHECK(!try_real(first, last));
    BOOST_CHECK(first == str+1);
  }
  {
    const wchar_t *str = L"123.";
    const wchar_t *first = str, *last = first+4;
    BOOST_CHECK(try_real(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L".123";
    const wchar_t *first = str, *last = first+4;
    BOOST_CHECK(try_real(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"123.456";
    const wchar_t *first = str, *last = first+7;
    BOOST_CHECK(try_real(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"123.456@";
    const wchar_t *first = str, *last = first+8;
    BOOST_CHECK(try_real(first, last));
    BOOST_CHECK(first == str+7);
  }
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{ 
  BOOST_CHECK(true);
}
#endif
