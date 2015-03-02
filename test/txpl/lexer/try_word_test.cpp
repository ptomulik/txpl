// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_lexer_try_word

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_LEXER_TRY_WORD

#include <txpl/lexer/try_word.hpp>

BOOST_AUTO_TEST_CASE(cstr)
{
  using namespace txpl::lexer;
  {
    const char *first = "", *last = first;
    BOOST_CHECK(!try_word(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *first = "0a", *last = first+2;
    BOOST_CHECK(!try_word(first, last));
    BOOST_CHECK((first+2) == last);
  }
  {
    const char *first = "_0", *last = first+2;
    BOOST_CHECK(try_word(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *first = "a0", *last = first+2;
    BOOST_CHECK(try_word(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *first = "a_", *last = first+2;
    BOOST_CHECK(try_word(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *first = "__", *last = first+2;
    BOOST_CHECK(try_word(first, last));
    BOOST_CHECK(first == last);
  }
}
BOOST_AUTO_TEST_CASE(cwstr)
{
  using namespace txpl::lexer;
  {
    const wchar_t *first = L"", *last = first;
    BOOST_CHECK(!try_word(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *first = L"0a", *last = first+2;
    BOOST_CHECK(!try_word(first, last));
    BOOST_CHECK((first+2) == last);
  }
  {
    const wchar_t *first = L"_0", *last = first+2;
    BOOST_CHECK(try_word(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *first = L"a0", *last = first+2;
    BOOST_CHECK(try_word(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *first = L"a_", *last = first+2;
    BOOST_CHECK(try_word(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *first = L"__", *last = first+2;
    BOOST_CHECK(try_word(first, last));
    BOOST_CHECK(first == last);
  }
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{ 
  BOOST_CHECK(true);
}
#endif
