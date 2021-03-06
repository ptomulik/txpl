// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_lexer_get_oct_number

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_LEXER_GET_OCT_NUMBER

#include <txpl/lexer/get_oct_number.hpp>
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
    BOOST_CHECK(!get_oct_number(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 'x');
    BOOST_CHECK(first == last);
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "octal digit expected");
  }
  {
    const char *str = "8";
    const char *first = str, *last = first + 1;
    char x = 'x';
    efirst = elast = nullptr;
    emsg.clear();
    BOOST_CHECK(!get_oct_number(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 'x');
    BOOST_CHECK(first == str);
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "octal digit expected");
  }
  {
    const char *str = "08";
    const char *first = str, *last = first + 2;
    char x = 'x';
    efirst = elast = nullptr;
    emsg.clear();
    BOOST_CHECK(!get_oct_number(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 'x');
    BOOST_CHECK(first == str+1);
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "octal digit expected");
  }
  {
    const char *str= "07777777777777777777777777777777";
    const char *first = str, *last = first + 32;
    char x = 'x';
    efirst = elast = nullptr;
    emsg.clear();
    BOOST_CHECK(!get_oct_number(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 'x');
    BOOST_CHECK_GT(first, str);
    BOOST_CHECK_LT(first, last);
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "integer constant too large for this type");
  }
  {
    const char *first = "0123", *last = first + 4;
    char x = 'x';
    efirst = elast = nullptr;
    emsg.clear();
    BOOST_CHECK(get_oct_number(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, char{0123});
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
    BOOST_CHECK(!get_oct_number(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 654);
    BOOST_CHECK(first == last);
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "octal digit expected");
  }
  {
    const char *str = "8";
    const char *first = str, *last = first + 1;
    int x = 654;
    efirst = elast = nullptr;
    emsg.clear();
    BOOST_CHECK(!get_oct_number(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 654);
    BOOST_CHECK(first == str);
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "octal digit expected");
  }
  {
    const char *str = "08";
    const char *first = str, *last = first + 2;
    int x = 654;
    efirst = elast = nullptr;
    emsg.clear();
    BOOST_CHECK(!get_oct_number(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 654);
    BOOST_CHECK(first == str+1);
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "octal digit expected");
  }
  {
    const char *str= "07777777777777777777777777777777";
    const char *first = str, *last = first + 32;
    int x = 654;
    efirst = elast = nullptr;
    emsg.clear();
    BOOST_CHECK(!get_oct_number(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 654);
    BOOST_CHECK_GT(first, str);
    BOOST_CHECK_LT(first, last);
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "integer constant too large for this type");
  }
  {
    const char *first = "0123", *last = first + 4;
    int x = 654;
    efirst = elast = nullptr;
    emsg.clear();
    BOOST_CHECK(get_oct_number(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, int{0123});
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
