// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_lexer_get_char

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_LEXER_GET_CHAR

#include <txpl/lexer/get_char.hpp>
#include <txpl/lexer/bind_error_handler.hpp>
#include <string>

BOOST_AUTO_TEST_CASE(cstr__char)
{
  using namespace txpl::lexer;

  const char* efirst = nullptr;
  const char* elast  = nullptr;
  std::string emsg;
  auto eh = bind_error_handler(efirst, elast, emsg);

  //
  // plain characters
  //
  {
    const char *str = "a";
    const char *first = str, *last = first + 1;
    efirst = elast = nullptr;
    emsg = "";
    char x = 'x';
    BOOST_CHECK(get_char(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 'a');
    BOOST_CHECK(first == last);
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK(emsg == "");
  }
  {
    const char *str = "A";
    const char *first = str, *last = first + 1;
    efirst = elast = nullptr;
    emsg = "";
    char x = 'x';
    BOOST_CHECK(get_char(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 'A');
    BOOST_CHECK(first == last);
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK(emsg == "");
  }
  //
  // escape sequances: single-digit octal codes
  //
  {
    const char *str = "\\0";
    const char *first = str, *last = first + 2;
    efirst = elast = nullptr;
    emsg = "";
    char x = 'x';
    BOOST_CHECK(get_char(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, '\0');
    BOOST_CHECK(first == last);
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK(emsg == "");
  }
  {
    const char *str = "\\1";
    const char *first = str, *last = first + 2;
    efirst = elast = nullptr;
    emsg = "";
    char x = 'x';
    BOOST_CHECK(get_char(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, '\1');
    BOOST_CHECK(first == last);
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK(emsg == "");
  }
  {
    const char *str = "\\2";
    const char *first = str, *last = first + 2;
    efirst = elast = nullptr;
    emsg = "";
    char x = 'x';
    BOOST_CHECK(get_char(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, '\2');
    BOOST_CHECK(first == last);
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK(emsg == "");
  }
  {
    const char *str = "\\3";
    const char *first = str, *last = first + 2;
    efirst = elast = nullptr;
    emsg = "";
    char x = 'x';
    BOOST_CHECK(get_char(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, '\3');
    BOOST_CHECK(first == last);
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK(emsg == "");
  }
  {
    const char *str = "\\4";
    const char *first = str, *last = first + 2;
    efirst = elast = nullptr;
    emsg = "";
    char x = 'x';
    BOOST_CHECK(get_char(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, '\4');
    BOOST_CHECK(first == last);
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK(emsg == "");
  }
  {
    const char *str = "\\5";
    const char *first = str, *last = first + 2;
    efirst = elast = nullptr;
    emsg = "";
    char x = 'x';
    BOOST_CHECK(get_char(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, '\5');
    BOOST_CHECK(first == last);
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK(emsg == "");
  }
  {
    const char *str = "\\6";
    const char *first = str, *last = first + 2;
    efirst = elast = nullptr;
    emsg = "";
    char x = 'x';
    BOOST_CHECK(get_char(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, '\6');
    BOOST_CHECK(first == last);
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK(emsg == "");
  }
  {
    const char *str = "\\7";
    const char *first = str, *last = first + 2;
    efirst = elast = nullptr;
    emsg = "";
    char x = 'x';
    BOOST_CHECK(get_char(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, '\7');
    BOOST_CHECK(first == last);
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK(emsg == "");
  }
  //
  // escape sequences: two-digit octal codes
  //
  {
    const char *str = "\\70";
    const char *first = str, *last = first + 3;
    efirst = elast = nullptr;
    emsg = "";
    char x = 'x';
    BOOST_CHECK(get_char(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, '\70');
    BOOST_CHECK(first == last);
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK(emsg == "");
  }
  {
    const char *str = "\\77";
    const char *first = str, *last = first + 3;
    efirst = elast = nullptr;
    emsg = "";
    char x = 'x';
    BOOST_CHECK(get_char(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, '\77');
    BOOST_CHECK(first == last);
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK(emsg == "");
  }
  //
  // escape sequences: three-digit octal codes
  //
  {
    const char *str = "\\377";
    const char *first = str, *last = first + 4;
    efirst = elast = nullptr;
    emsg = "";
    char x = 'x';
    BOOST_CHECK(get_char(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, '\377');
    BOOST_CHECK(first == last);
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK(emsg == "");
  }
  //
  // escape sequences: hexadecimal codes
  //
  {
    const char *str = "\\x0";
    const char *first = str, *last = first + 3;
    efirst = elast = nullptr;
    emsg = "";
    char x = 'x';
    BOOST_CHECK(get_char(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, '\x0');
    BOOST_CHECK(first == last);
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK(emsg == "");
  }
  {
    const char *str = "\\x12";
    const char *first = str, *last = first + 4;
    efirst = elast = nullptr;
    emsg = "";
    char x = 'x';
    BOOST_CHECK(get_char(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, '\x12');
    BOOST_CHECK(first == last);
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK(emsg == "");
  }
  {
    const char *str = "\\xaF";
    const char *first = str, *last = first + 4;
    efirst = elast = nullptr;
    emsg = "";
    char x = 'x';
    BOOST_CHECK(get_char(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, '\xAF');
    BOOST_CHECK(first == last);
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK(emsg == "");
  }
  //
  // escape sequences: special characters
  //
  {
    const char *first = "\\\"", *last = first + 2;
    efirst = elast = nullptr;
    emsg = "";
    char x = 'x';
    BOOST_CHECK(get_char(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, '\"');
    BOOST_CHECK(first == last);
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK(emsg == "");
  }
  {
    const char *str = "\\'";
    const char *first = str, *last = first + 2;
    efirst = elast = nullptr;
    emsg = "";
    char x = 'x';
    BOOST_CHECK(get_char(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, '\'');
    BOOST_CHECK(first == last);
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK(emsg == "");
  }
  {
    const char *str = "\\?";
    const char *first = str, *last = first + 2;
    efirst = elast = nullptr;
    emsg = "";
    char x = 'x';
    BOOST_CHECK(get_char(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, '\?');
    BOOST_CHECK(first == last);
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK(emsg == "");
  }
  {
    const char *str = "\\\\";
    const char *first = str, *last = first + 2;
    efirst = elast = nullptr;
    emsg = "";
    char x = 'x';
    BOOST_CHECK(get_char(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, '\\');
    BOOST_CHECK(first == last);
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK(emsg == "");
  }
  {
    const char *str = "\\a";
    const char *first = str, *last = first + 2;
    efirst = elast = nullptr;
    emsg = "";
    char x = 'x';
    BOOST_CHECK(get_char(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, '\a');
    BOOST_CHECK(first == last);
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK(emsg == "");
  }
  {
    const char *str = "\\b";
    const char *first = str, *last = first + 2;
    efirst = elast = nullptr;
    emsg = "";
    char x = 'x';
    BOOST_CHECK(get_char(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, '\b');
    BOOST_CHECK(first == last);
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK(emsg == "");
  }
  {
    const char *str = "\\f";
    const char *first = str, *last = first + 2;
    efirst = elast = nullptr;
    emsg = "";
    char x = 'x';
    BOOST_CHECK(get_char(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, '\f');
    BOOST_CHECK(first == last);
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK(emsg == "");
  }
  {
    const char *str = "\\n";
    const char *first = str, *last = first + 2;
    efirst = elast = nullptr;
    emsg = "";
    char x = 'x';
    BOOST_CHECK(get_char(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, '\n');
    BOOST_CHECK(first == last);
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK(emsg == "");
  }
  {
    const char *str = "\\r";
    const char *first = str, *last = first + 2;
    efirst = elast = nullptr;
    emsg = "";
    char x = 'x';
    BOOST_CHECK(get_char(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, '\r');
    BOOST_CHECK(first == last);
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK(emsg == "");
  }
  {
    const char *str = "\\t";
    const char *first = str, *last = first + 2;
    efirst = elast = nullptr;
    emsg = "";
    char x = 'x';
    BOOST_CHECK(get_char(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, '\t');
    BOOST_CHECK(first == last);
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK(emsg == "");
  }
  {
    const char *str = "\\v";
    const char *first = str, *last = first + 2;
    efirst = elast = nullptr;
    emsg = "";
    char x = 'x';
    BOOST_CHECK(get_char(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, '\v');
    BOOST_CHECK(first == last);
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK(emsg == "");
  }
  //
  // invalid characters (incomplete, etc.)
  //
  {
    const char *str = "";
    const char *first = str, *last = first;
    efirst = elast = nullptr;
    emsg = "";
    char x = 'x';
    BOOST_CHECK(!get_char(first, last, x, eh));
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "expected character specification");
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "\v";
    const char *first = str, *last = first+1;
    efirst = elast = nullptr;
    emsg = "";
    char x = 'x';
    BOOST_CHECK(!get_char(first, last, x, eh));
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "non-printable character in character specification");
    BOOST_CHECK(first == str);
  }
  {
    const char *str = "\\";
    const char *first = str, *last = first+1;
    efirst = elast = nullptr;
    emsg = "";
    char x = 'x';
    BOOST_CHECK(!get_char(first, last, x, eh));
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "incomplete escape sequence");
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "\\x";
    const char *first = str, *last = first+2;
    efirst = elast = nullptr;
    emsg = "";
    char x = 'x';
    BOOST_CHECK(!get_char(first, last, x, eh));
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "incomplete escape sequence");
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "\\m";
    const char *first = str, *last = first+2;
    efirst = elast = nullptr;
    emsg = "";
    char x = 'x';
    BOOST_CHECK(!get_char(first, last, x, eh));
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "invalid escape sequence");
    BOOST_CHECK(first == str+1);
  }
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{ 
  BOOST_CHECK(true);
}
#endif
