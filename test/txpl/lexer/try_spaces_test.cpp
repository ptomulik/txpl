// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_lexer_try_spaces

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_LEXER_TRY_SPACES

#include <txpl/lexer/try_spaces.hpp>

BOOST_AUTO_TEST_CASE(cstr)
{
  using namespace txpl::lexer;
  {
    const char *str = "";
    const char *first = str, *last = first;
    BOOST_CHECK(!try_spaces(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = " \t\r\n\v";
    const char *first = str, *last = first+5;
    BOOST_CHECK(try_spaces(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "bla";
    const char *first = str, *last = first+3;
    BOOST_CHECK(!try_spaces(first, last));
    BOOST_CHECK(first == str);
  }
  {
    const char *str = "  \tqwe";
    const char *first = str, *last = first+6;
    BOOST_CHECK(try_spaces(first, last));
    BOOST_CHECK(first == str+3);
  }
}
BOOST_AUTO_TEST_CASE(cwstr)
{
  using namespace txpl::lexer;
  {
    const wchar_t *str = L"";
    const wchar_t *first = str, *last = first;
    BOOST_CHECK(!try_spaces(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L" \t\r\n\v";
    const wchar_t *first = str, *last = first+5;
    BOOST_CHECK(try_spaces(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"bla";
    const wchar_t *first = str, *last = first+3;
    BOOST_CHECK(!try_spaces(first, last));
    BOOST_CHECK(first == str);
  }
  {
    const wchar_t *str = L"  \tqwe";
    const wchar_t *first = str, *last = first+6;
    BOOST_CHECK(try_spaces(first, last));
    BOOST_CHECK(first == str+3);
  }
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{ 
  BOOST_CHECK(true);
}
#endif
