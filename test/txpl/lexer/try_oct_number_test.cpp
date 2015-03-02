// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_lexer_try_oct_number

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_LEXER_TRY_OCT_NUMBER

#include <txpl/lexer/try_oct_number.hpp>

BOOST_AUTO_TEST_CASE(cstr)
{
  using namespace txpl::lexer;
  {
    const char *str = "17";
    const char *first = str, *last = first+2;
    BOOST_CHECK(try_oct_number(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "608";
    const char *first = str, *last = first+3;
    BOOST_CHECK(try_oct_number(first, last));
    BOOST_CHECK(first == str+2);
  }
  {
    const char *str = "";
    const char *first = str, *last = first;
    BOOST_CHECK(!try_oct_number(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "@17";
    const char *first = str, *last = first+3;
    BOOST_CHECK(!try_oct_number(first, last));
    BOOST_CHECK(first == str);
  }
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{ 
  BOOST_CHECK(true);
}
#endif
