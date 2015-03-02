// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_lexer_get_hex_number

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_LEXER_GET_HEX_NUMBER

#include <txpl/lexer/get_hex_number.hpp>
#include <txpl/lexer/bind_error_handler.hpp>


BOOST_AUTO_TEST_CASE(cstr__char)
{
  using namespace txpl::lexer;
  const char* efirst = nullptr;
  const char* elast = nullptr;
  std::string emsg;
  auto eh = bind_error_handler(efirst, elast, emsg);
  {
    const char *str = "";
    const char *first = str, *last = first;
    char x = 'x';
    efirst = elast = nullptr;
    emsg.clear();
    BOOST_CHECK(!get_hex_number(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 'x');
    BOOST_CHECK(first == last);
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "hexadecimal digit expected");
  }
  {
    const char *str = "Z";
    const char *first = str, *last = first + 1;
    char x = 'x';
    efirst = elast = nullptr;
    emsg.clear();
    BOOST_CHECK(!get_hex_number(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 'x');
    BOOST_CHECK(first == str);
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "hexadecimal digit expected");
  }
  {
    const char *str = "FZ";
    const char *first = str, *last = first + 2;
    char x = 'x';
    efirst = elast = nullptr;
    emsg.clear();
    BOOST_CHECK(!get_hex_number(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 'x');
    BOOST_CHECK(first == str+1);
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "hexadecimal digit expected");
  }
  {
    const char *str= "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF";
    const char *first = str, *last = first + 32;
    char x = 'x';
    efirst = elast = nullptr;
    emsg.clear();
    BOOST_CHECK(!get_hex_number(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 'x');
    BOOST_CHECK_GT(first, str);
    BOOST_CHECK_LT(first, last);
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "integer constant too large for this type");
  }
  {
    const char *str = "2F";
    const char *first = str, *last = first + 2;
    char x = 'x';
    efirst = elast = nullptr;
    emsg.clear();
    BOOST_CHECK(get_hex_number(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, char{0x2F});
    BOOST_CHECK(first == last);
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
  }
  BOOST_CHECK(true);
}

BOOST_AUTO_TEST_CASE(cstr__int)
{
  using namespace txpl::lexer;
  const char* efirst = nullptr;
  const char* elast = nullptr;
  std::string emsg;
  auto eh = bind_error_handler(efirst, elast, emsg);
  {
    const char *str = "";
    const char *first = str, *last = first;
    int x = 654;
    efirst = elast = nullptr;
    emsg.clear();
    BOOST_CHECK(!get_hex_number(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 654);
    BOOST_CHECK(first == last);
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "hexadecimal digit expected");
  }
  {
    const char *str = "Z";
    const char *first = str, *last = first + 1;
    int x = 654;
    efirst = elast = nullptr;
    emsg.clear();
    BOOST_CHECK(!get_hex_number(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 654);
    BOOST_CHECK(first == str);
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "hexadecimal digit expected");
  }
  {
    const char *str = "FZ";
    const char *first = str, *last = first + 2;
    int x = 654;
    efirst = elast = nullptr;
    emsg.clear();
    BOOST_CHECK(!get_hex_number(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 654);
    BOOST_CHECK(first == str+1);
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "hexadecimal digit expected");
  }
  {
    const char *str= "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF";
    const char *first = str, *last = first + 32;
    int x = 654;
    efirst = elast = nullptr;
    emsg.clear();
    BOOST_CHECK(!get_hex_number(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 654);
    BOOST_CHECK_GT(first, str);
    BOOST_CHECK_LT(first, last);
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "integer constant too large for this type");
  }
  {
    const char *str = "1bF";
    const char *first = str, *last = first + 3;
    int x = 654;
    efirst = elast = nullptr;
    emsg.clear();
    BOOST_CHECK(get_hex_number(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, int{0x1BF});
    BOOST_CHECK(first == last);
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
  }
  BOOST_CHECK(true);
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{ 
  BOOST_CHECK(true);
}
#endif
