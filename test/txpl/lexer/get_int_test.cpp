// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_lexer_get_int

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_LEXER_GET_INT

#include <txpl/lexer/get_int.hpp>
#include <txpl/lexer/bind_error_handler.hpp>

BOOST_AUTO_TEST_CASE(cstr__int)
{
  using namespace txpl::lexer;
  const char *efirst;
  const char *elast;
  std::string emsg;
  auto eh = bind_error_handler(efirst, elast, emsg);
  {
    const char *str = "";
    const char *first = str, *last = first;
    int x = 654;
    efirst = elast = nullptr; emsg = "";
    BOOST_CHECK(!get_int(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 654);
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "decimal digit expected");
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "x";
    const char *first = str, *last = first+1;
    int x = 654;
    efirst = elast = nullptr; emsg = "";
    BOOST_CHECK(!get_int(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 654);
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "decimal digit expected");
    BOOST_CHECK(first == str);
  }
  {
    const char *str = "0x";
    const char *first = str, *last = first+2;
    int x = 654;
    efirst = elast = nullptr; emsg = "";
    BOOST_CHECK(!get_int(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 654);
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "hexadecimal digit expected");
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "0xZ";
    const char *first = str, *last = first+3;
    int x = 654;
    efirst = elast = nullptr; emsg = "";
    BOOST_CHECK(!get_int(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 654);
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "hexadecimal digit expected");
    BOOST_CHECK(first == str+2);
  }
  {
    const char *str = "123ab";
    const char *first = str, *last = first + 5;
    int x = 654;
    efirst = elast = nullptr; emsg = "";
    BOOST_CHECK(!get_int(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 654);
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "decimal digit expected");
    BOOST_CHECK(first == str+3);
  }
  {
    const char *str = "0";
    const char *first = str, *last = first+1;
    int x = 654;
    efirst = elast = nullptr; emsg = "";
    BOOST_CHECK(get_int(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 0);
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "0123";
    const char *first = str, *last = first+4;
    int x = 654;
    efirst = elast = nullptr; emsg = "";
    BOOST_CHECK(get_int(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 0123);
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "0x123";
    const char *first = str, *last = first+5;
    int x = 654;
    efirst = elast = nullptr; emsg = "";
    BOOST_CHECK(get_int(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 0x123);
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == last);
  }
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{ 
  BOOST_CHECK(true);
}
#endif
