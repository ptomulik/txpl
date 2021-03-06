// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_lexer_get_oct_digit

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_LEXER_GET_OCT_DIGIT

#include <txpl/lexer/get_oct_digit.hpp>

BOOST_AUTO_TEST_CASE(char__char)
{
  using txpl::lexer::get_oct_digit;
  char x = 123;
  BOOST_CHECK(get_oct_digit('0',x)); 
  BOOST_CHECK_EQUAL(x, '\0');
  BOOST_CHECK(get_oct_digit('1',x)); 
  BOOST_CHECK_EQUAL(x, '\1');
  BOOST_CHECK(get_oct_digit('2',x)); 
  BOOST_CHECK_EQUAL(x, '\2');
  BOOST_CHECK(get_oct_digit('3',x)); 
  BOOST_CHECK_EQUAL(x, '\3');
  BOOST_CHECK(get_oct_digit('4',x)); 
  BOOST_CHECK_EQUAL(x, '\4');
  BOOST_CHECK(get_oct_digit('5',x)); 
  BOOST_CHECK_EQUAL(x, '\5');
  BOOST_CHECK(get_oct_digit('6',x)); 
  BOOST_CHECK_EQUAL(x, '\6');
  BOOST_CHECK(get_oct_digit('7',x)); 
  BOOST_CHECK_EQUAL(x, '\7');
  // invalid digits
  BOOST_CHECK(!get_oct_digit('8',x)); 
  BOOST_CHECK(!get_oct_digit('A',x)); 
}
BOOST_AUTO_TEST_CASE(char__int)
{

  using txpl::lexer::get_oct_digit;
  int x = 123;
  BOOST_CHECK(get_oct_digit('0',x)); 
  BOOST_CHECK_EQUAL(x, 0);
  BOOST_CHECK(get_oct_digit('1',x)); 
  BOOST_CHECK_EQUAL(x, 1);
  BOOST_CHECK(get_oct_digit('2',x)); 
  BOOST_CHECK_EQUAL(x, 2);
  BOOST_CHECK(get_oct_digit('3',x)); 
  BOOST_CHECK_EQUAL(x, 3);
  BOOST_CHECK(get_oct_digit('4',x)); 
  BOOST_CHECK_EQUAL(x, 4);
  BOOST_CHECK(get_oct_digit('5',x)); 
  BOOST_CHECK_EQUAL(x, 5);
  BOOST_CHECK(get_oct_digit('6',x)); 
  BOOST_CHECK_EQUAL(x, 6);
  BOOST_CHECK(get_oct_digit('7',x)); 
  BOOST_CHECK_EQUAL(x, 7);
  // invalid digits
  BOOST_CHECK(!get_oct_digit('8',x)); 
  BOOST_CHECK(!get_oct_digit('A',x)); 
}

BOOST_AUTO_TEST_CASE(wchar_t__char)
{
  using txpl::lexer::get_oct_digit;
  char x = 123;
  BOOST_CHECK(get_oct_digit(L'0',x)); 
  BOOST_CHECK_EQUAL(x, '\0');
  BOOST_CHECK(get_oct_digit(L'1',x)); 
  BOOST_CHECK_EQUAL(x, '\1');
  BOOST_CHECK(get_oct_digit(L'2',x)); 
  BOOST_CHECK_EQUAL(x, '\2');
  BOOST_CHECK(get_oct_digit(L'3',x)); 
  BOOST_CHECK_EQUAL(x, '\3');
  BOOST_CHECK(get_oct_digit(L'4',x)); 
  BOOST_CHECK_EQUAL(x, '\4');
  BOOST_CHECK(get_oct_digit(L'5',x)); 
  BOOST_CHECK_EQUAL(x, '\5');
  BOOST_CHECK(get_oct_digit(L'6',x)); 
  BOOST_CHECK_EQUAL(x, '\6');
  BOOST_CHECK(get_oct_digit(L'7',x)); 
  BOOST_CHECK_EQUAL(x, '\7');
  // invalid digits
  BOOST_CHECK(!get_oct_digit('8',x)); 
  BOOST_CHECK(!get_oct_digit('A',x)); 
}
BOOST_AUTO_TEST_CASE(wchar_t__int)
{
  using txpl::lexer::get_oct_digit;
  int x = 123;
  BOOST_CHECK(get_oct_digit('0',x)); 
  BOOST_CHECK_EQUAL(x, 0);
  BOOST_CHECK(get_oct_digit('1',x)); 
  BOOST_CHECK_EQUAL(x, 1);
  BOOST_CHECK(get_oct_digit('2',x)); 
  BOOST_CHECK_EQUAL(x, 2);
  BOOST_CHECK(get_oct_digit('3',x)); 
  BOOST_CHECK_EQUAL(x, 3);
  BOOST_CHECK(get_oct_digit('4',x)); 
  BOOST_CHECK_EQUAL(x, 4);
  BOOST_CHECK(get_oct_digit('5',x)); 
  BOOST_CHECK_EQUAL(x, 5);
  BOOST_CHECK(get_oct_digit('6',x)); 
  BOOST_CHECK_EQUAL(x, 6);
  BOOST_CHECK(get_oct_digit('7',x)); 
  BOOST_CHECK_EQUAL(x, 7);
  // invalid digits
  BOOST_CHECK(!get_oct_digit('8',x)); 
  BOOST_CHECK(!get_oct_digit('A',x)); 
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{ 
  BOOST_CHECK(true);
}
#endif
