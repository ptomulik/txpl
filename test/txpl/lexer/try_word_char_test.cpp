// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_lexer_try_word_char

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_LEXER_TRY_WORD_CHAR

#include <txpl/lexer/try_word_char.hpp>

BOOST_AUTO_TEST_CASE(char0_cstr)
{
  using namespace txpl::lexer;
  {
    const char *first = "", *last = first;
    BOOST_CHECK(!try_word_char0(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *first = "0", *last = first+1;
    BOOST_CHECK(!try_word_char0(first, last));
    BOOST_CHECK((first+1) == last);
  }
  {
    const char *first = "_", *last = first+1;
    BOOST_CHECK(try_word_char0(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *first = "a", *last = first+1;
    BOOST_CHECK(try_word_char0(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *first = "A", *last = first+1;
    BOOST_CHECK(try_word_char0(first, last));
    BOOST_CHECK(first == last);
  }
}

BOOST_AUTO_TEST_CASE(char0_cwstr)
{
  using namespace txpl::lexer;
  {
    const wchar_t *first = L"", *last = first;
    BOOST_CHECK(!try_word_char0(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *first = L"0", *last = first+1;
    BOOST_CHECK(!try_word_char0(first, last));
    BOOST_CHECK((first+1) == last);
  }
  {
    const wchar_t *first = L"_", *last = first+1;
    BOOST_CHECK(try_word_char0(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *first = L"a", *last = first+1;
    BOOST_CHECK(try_word_char0(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *first = L"A", *last = first+1;
    BOOST_CHECK(try_word_char0(first, last));
    BOOST_CHECK(first == last);
  }
}
BOOST_AUTO_TEST_CASE(char_cstr)
{
  using namespace txpl::lexer;
  {
    const char *first = "", *last = first;
    BOOST_CHECK(!try_word_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *first = "0", *last = first+1;
    BOOST_CHECK(try_word_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *first = "_", *last = first+1;
    BOOST_CHECK(try_word_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *first = "a", *last = first+1;
    BOOST_CHECK(try_word_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *first = "A", *last = first+1;
    BOOST_CHECK(try_word_char(first, last));
    BOOST_CHECK(first == last);
  }
}
BOOST_AUTO_TEST_CASE(char_cwstr)
{
  using namespace txpl::lexer;
  {
    const wchar_t *first = L"", *last = first;
    BOOST_CHECK(!try_word_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *first = L"0", *last = first+1;
    BOOST_CHECK(try_word_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *first = L"_", *last = first+1;
    BOOST_CHECK(try_word_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *first = L"a", *last = first+1;
    BOOST_CHECK(try_word_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *first = L"A", *last = first+1;
    BOOST_CHECK(try_word_char(first, last));
    BOOST_CHECK(first == last);
  }
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{ 
  BOOST_CHECK(true);
}
#endif
