// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_lexer_get_hex_digit

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_LEXER_GET_HEX_DIGIT

#include <txpl/lexer/get_hex_digit.hpp>

BOOST_AUTO_TEST_CASE(char__char)
{
  using txpl::lexer::get_hex_digit;
  char x = 123;
  BOOST_CHECK(get_hex_digit('0',x)); 
  BOOST_CHECK_EQUAL(x,  char{0});
  BOOST_CHECK(get_hex_digit('1',x)); 
  BOOST_CHECK_EQUAL(x,  char{1});
  BOOST_CHECK(get_hex_digit('2',x)); 
  BOOST_CHECK_EQUAL(x,  char{2});
  BOOST_CHECK(get_hex_digit('3',x)); 
  BOOST_CHECK_EQUAL(x,  char{3});
  BOOST_CHECK(get_hex_digit('4',x)); 
  BOOST_CHECK_EQUAL(x,  char{4});
  BOOST_CHECK(get_hex_digit('5',x)); 
  BOOST_CHECK_EQUAL(x,  char{5});
  BOOST_CHECK(get_hex_digit('6',x)); 
  BOOST_CHECK_EQUAL(x,  char{6});
  BOOST_CHECK(get_hex_digit('7',x)); 
  BOOST_CHECK_EQUAL(x,  char{7});
  BOOST_CHECK(get_hex_digit('8',x)); 
  BOOST_CHECK_EQUAL(x,  char{8});
  BOOST_CHECK(get_hex_digit('9',x)); 
  BOOST_CHECK_EQUAL(x,  char{9});
  BOOST_CHECK(get_hex_digit('A',x)); 
  BOOST_CHECK_EQUAL(x,char{0xA});
  BOOST_CHECK(get_hex_digit('B',x)); 
  BOOST_CHECK_EQUAL(x,char{0xB});
  BOOST_CHECK(get_hex_digit('C',x)); 
  BOOST_CHECK_EQUAL(x,char{0xC});
  BOOST_CHECK(get_hex_digit('D',x)); 
  BOOST_CHECK_EQUAL(x,char{0xD});
  BOOST_CHECK(get_hex_digit('E',x)); 
  BOOST_CHECK_EQUAL(x,char{0xE});
  BOOST_CHECK(get_hex_digit('F',x)); 
  BOOST_CHECK_EQUAL(x,char{0xF});
  // invalid digits
  BOOST_CHECK(!get_hex_digit('G',x)); 
}
BOOST_AUTO_TEST_CASE(char__int)
{

  using txpl::lexer::get_hex_digit;
  int x = 123;
  BOOST_CHECK(get_hex_digit('0',x)); 
  BOOST_CHECK_EQUAL(x,       0);
  BOOST_CHECK(get_hex_digit('1',x)); 
  BOOST_CHECK_EQUAL(x,       1);
  BOOST_CHECK(get_hex_digit('2',x)); 
  BOOST_CHECK_EQUAL(x,       2);
  BOOST_CHECK(get_hex_digit('3',x)); 
  BOOST_CHECK_EQUAL(x,       3);
  BOOST_CHECK(get_hex_digit('4',x)); 
  BOOST_CHECK_EQUAL(x,       4);
  BOOST_CHECK(get_hex_digit('5',x)); 
  BOOST_CHECK_EQUAL(x,       5);
  BOOST_CHECK(get_hex_digit('6',x)); 
  BOOST_CHECK_EQUAL(x,       6);
  BOOST_CHECK(get_hex_digit('7',x)); 
  BOOST_CHECK_EQUAL(x,       7);
  BOOST_CHECK(get_hex_digit('8',x)); 
  BOOST_CHECK_EQUAL(x,       8);
  BOOST_CHECK(get_hex_digit('9',x)); 
  BOOST_CHECK_EQUAL(x,       9);
  BOOST_CHECK(get_hex_digit('A',x)); 
  BOOST_CHECK_EQUAL(x,     0xA);
  BOOST_CHECK(get_hex_digit('B',x)); 
  BOOST_CHECK_EQUAL(x,     0xB);
  BOOST_CHECK(get_hex_digit('C',x)); 
  BOOST_CHECK_EQUAL(x,     0xC);
  BOOST_CHECK(get_hex_digit('D',x)); 
  BOOST_CHECK_EQUAL(x,     0xD);
  BOOST_CHECK(get_hex_digit('E',x)); 
  BOOST_CHECK_EQUAL(x,     0xE);
  BOOST_CHECK(get_hex_digit('F',x)); 
  BOOST_CHECK_EQUAL(x,     0xF);
  // invalid digits
  BOOST_CHECK(!get_hex_digit('G',x)); 
}

BOOST_AUTO_TEST_CASE(wchar_t__char)
{
  using txpl::lexer::get_hex_digit;
  char x = 123;
  BOOST_CHECK(get_hex_digit(L'0',x)); 
  BOOST_CHECK_EQUAL(x,   char{0});
  BOOST_CHECK(get_hex_digit(L'1',x)); 
  BOOST_CHECK_EQUAL(x,   char{1});
  BOOST_CHECK(get_hex_digit(L'2',x)); 
  BOOST_CHECK_EQUAL(x,   char{2});
  BOOST_CHECK(get_hex_digit(L'3',x)); 
  BOOST_CHECK_EQUAL(x,   char{3});
  BOOST_CHECK(get_hex_digit(L'4',x)); 
  BOOST_CHECK_EQUAL(x,   char{4});
  BOOST_CHECK(get_hex_digit(L'5',x)); 
  BOOST_CHECK_EQUAL(x,   char{5});
  BOOST_CHECK(get_hex_digit(L'6',x)); 
  BOOST_CHECK_EQUAL(x,   char{6});
  BOOST_CHECK(get_hex_digit(L'7',x)); 
  BOOST_CHECK_EQUAL(x,   char{7});
  BOOST_CHECK(get_hex_digit(L'8',x)); 
  BOOST_CHECK_EQUAL(x,   char{8});
  BOOST_CHECK(get_hex_digit(L'9',x)); 
  BOOST_CHECK_EQUAL(x,   char{9});
  BOOST_CHECK(get_hex_digit('A',x)); 
  BOOST_CHECK_EQUAL(x, int{0xA});
  BOOST_CHECK(get_hex_digit('B',x)); 
  BOOST_CHECK_EQUAL(x, int{0xB});
  BOOST_CHECK(get_hex_digit('C',x)); 
  BOOST_CHECK_EQUAL(x, int{0xC});
  BOOST_CHECK(get_hex_digit('D',x)); 
  BOOST_CHECK_EQUAL(x, int{0xD});
  BOOST_CHECK(get_hex_digit('E',x)); 
  BOOST_CHECK_EQUAL(x, int{0xE});
  BOOST_CHECK(get_hex_digit('F',x)); 
  BOOST_CHECK_EQUAL(x, int{0xF});
  // invalid digits
  BOOST_CHECK(!get_hex_digit('G',x)); 
}
BOOST_AUTO_TEST_CASE(wchar_t__int)
{
  using txpl::lexer::get_hex_digit;
  int x = 123;
  BOOST_CHECK(get_hex_digit('0',x)); 
  BOOST_CHECK_EQUAL(x,       0);
  BOOST_CHECK(get_hex_digit('1',x)); 
  BOOST_CHECK_EQUAL(x,       1);
  BOOST_CHECK(get_hex_digit('2',x)); 
  BOOST_CHECK_EQUAL(x,       2);
  BOOST_CHECK(get_hex_digit('3',x)); 
  BOOST_CHECK_EQUAL(x,       3);
  BOOST_CHECK(get_hex_digit('4',x)); 
  BOOST_CHECK_EQUAL(x,       4);
  BOOST_CHECK(get_hex_digit('5',x)); 
  BOOST_CHECK_EQUAL(x,       5);
  BOOST_CHECK(get_hex_digit('6',x)); 
  BOOST_CHECK_EQUAL(x,       6);
  BOOST_CHECK(get_hex_digit('7',x)); 
  BOOST_CHECK_EQUAL(x,       7);
  BOOST_CHECK(get_hex_digit('8',x)); 
  BOOST_CHECK_EQUAL(x,       8);
  BOOST_CHECK(get_hex_digit('9',x)); 
  BOOST_CHECK_EQUAL(x,       9);
  BOOST_CHECK(get_hex_digit('A',x)); 
  BOOST_CHECK_EQUAL(x,     0xA);
  BOOST_CHECK(get_hex_digit('B',x)); 
  BOOST_CHECK_EQUAL(x,     0xB);
  BOOST_CHECK(get_hex_digit('C',x)); 
  BOOST_CHECK_EQUAL(x,     0xC);
  BOOST_CHECK(get_hex_digit('D',x)); 
  BOOST_CHECK_EQUAL(x,     0xD);
  BOOST_CHECK(get_hex_digit('E',x)); 
  BOOST_CHECK_EQUAL(x,     0xE);
  BOOST_CHECK(get_hex_digit('F',x)); 
  BOOST_CHECK_EQUAL(x,     0xF);
  // invalid digits
  BOOST_CHECK(!get_hex_digit('G',x)); 
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{ 
  BOOST_CHECK(true);
}
#endif
