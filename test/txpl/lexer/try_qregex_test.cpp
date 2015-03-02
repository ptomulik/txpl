// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_lexer_try_qregex

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_LEXER_TRY_QREGEX

#include <txpl/lexer/try_qregex.hpp>

BOOST_AUTO_TEST_CASE(cstr)
{
  using namespace txpl::lexer;
  {
    const char *str = "r\"\"";
    const char *first = str, *last = first + 3;
    BOOST_CHECK(try_qregex(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "r\"ESMAScript regex\"";
    const char *first = str, *last = first + 19;
    BOOST_CHECK(try_qregex(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "b\"basic regex\"";
    const char *first = str, *last = first + 14;
    BOOST_CHECK(try_qregex(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "x\"extended regex\"";
    const char *first = str, *last = first + 17;
    BOOST_CHECK(try_qregex(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "a\"awk regex\"";
    const char *first = str, *last = first + 12;
    BOOST_CHECK(try_qregex(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "g\"grep regex\"";
    const char *first = str, *last = first + 13;
    BOOST_CHECK(try_qregex(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "e\"egrep regex\"";
    const char *first = str, *last = first + 14;
    BOOST_CHECK(try_qregex(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "r\"regex 1\"i";
    const char *first = str, *last = first + 11;
    BOOST_CHECK(try_qregex(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "r\"regex 2\"c";
    const char *first = str, *last = first + 11;
    BOOST_CHECK(try_qregex(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "r\"regex 3\"ci";
    const char *first = str, *last = first + 12;
    BOOST_CHECK(try_qregex(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "r\"regex 4\"ic";
    const char *first = str, *last = first + 12;
    BOOST_CHECK(try_qregex(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "r\".+goi.*\\?\"";
    const char *first = str, *last = first + 12;
    BOOST_CHECK(try_qregex(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "r\".+goi.*\\?\"i";
    const char *first = str, *last = first + 13;
    BOOST_CHECK(try_qregex(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "r\"\"ic";
    const char *first = str, *last = first+5;
    BOOST_CHECK(try_qregex(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "r\"\"icX";
    const char *first = str, *last = first+6;
    BOOST_CHECK(try_qregex(first, last));
    BOOST_CHECK(first == str+5);
  }
  {
    const char *str = "";
    const char *first = str, *last = first;
    BOOST_CHECK(!try_qregex(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "simple";
    const char *first = str, *last = first+6;
    BOOST_CHECK(!try_qregex(first, last));
    BOOST_CHECK(first == str);
  }
  {
    const char *str = "r";
    const char *first = str, *last = first+1;
    BOOST_CHECK(!try_qregex(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "r\"";
    const char *first = str, *last = first+2;
    BOOST_CHECK(!try_qregex(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "r\"a";
    const char *first = str, *last = first+3;
    BOOST_CHECK(!try_qregex(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "\"";
    const char *first = str, *last = first+1;
    BOOST_CHECK(!try_qregex(first, last));
    BOOST_CHECK(first == str);
  }
}
BOOST_AUTO_TEST_CASE(cwstr)
{
  using namespace txpl::lexer;
  {
    const wchar_t *str = L"r\"\"";
    const wchar_t *first = str, *last = first + 3;
    BOOST_CHECK(try_qregex(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"r\"ESMAScript regex\"";
    const wchar_t *first = str, *last = first + 19;
    BOOST_CHECK(try_qregex(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"b\"basic regex\"";
    const wchar_t *first = str, *last = first + 14;
    BOOST_CHECK(try_qregex(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"x\"extended regex\"";
    const wchar_t *first = str, *last = first + 17;
    BOOST_CHECK(try_qregex(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"a\"awk regex\"";
    const wchar_t *first = str, *last = first + 12;
    BOOST_CHECK(try_qregex(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"g\"grep regex\"";
    const wchar_t *first = str, *last = first + 13;
    BOOST_CHECK(try_qregex(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"e\"egrep regex\"";
    const wchar_t *first = str, *last = first + 14;
    BOOST_CHECK(try_qregex(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"r\"regex 1\"i";
    const wchar_t *first = str, *last = first + 11;
    BOOST_CHECK(try_qregex(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"r\"regex 2\"c";
    const wchar_t *first = str, *last = first + 11;
    BOOST_CHECK(try_qregex(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"r\"regex 3\"ci";
    const wchar_t *first = str, *last = first + 12;
    BOOST_CHECK(try_qregex(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"r\"regex 4\"ic";
    const wchar_t *first = str, *last = first + 12;
    BOOST_CHECK(try_qregex(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"r\".+goi.*\\?\"";
    const wchar_t *first = str, *last = first + 12;
    BOOST_CHECK(try_qregex(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"r\".+goi.*\\?\"i";
    const wchar_t *first = str, *last = first + 13;
    BOOST_CHECK(try_qregex(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"r\"\"ic";
    const wchar_t *first = str, *last = first+5;
    BOOST_CHECK(try_qregex(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"r\"\"icX";
    const wchar_t *first = str, *last = first+6;
    BOOST_CHECK(try_qregex(first, last));
    BOOST_CHECK(first == str+5);
  }
  {
    const wchar_t *str = L"";
    const wchar_t *first = str, *last = first;
    BOOST_CHECK(!try_qregex(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"simple";
    const wchar_t *first = str, *last = first+6;
    BOOST_CHECK(!try_qregex(first, last));
    BOOST_CHECK(first == str);
  }
  {
    const wchar_t *str = L"r";
    const wchar_t *first = str, *last = first+1;
    BOOST_CHECK(!try_qregex(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"r\"";
    const wchar_t *first = str, *last = first+2;
    BOOST_CHECK(!try_qregex(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"r\"a";
    const wchar_t *first = str, *last = first+3;
    BOOST_CHECK(!try_qregex(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"\"";
    const wchar_t *first = str, *last = first+1;
    BOOST_CHECK(!try_qregex(first, last));
    BOOST_CHECK(first == str);
  }
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{ 
  BOOST_CHECK(true);
}
#endif
