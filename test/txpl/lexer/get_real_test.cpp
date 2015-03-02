// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_lexer_get_real

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_LEXER_GET_REAL

#include <txpl/lexer/get_real.hpp>
#include <txpl/lexer/bind_error_handler.hpp>

BOOST_AUTO_TEST_CASE(cstr__double)
{
  using namespace txpl::lexer;
  const char *efirst;
  const char *elast;
  std::string emsg;
  auto eh = bind_error_handler(efirst, elast, emsg);
  {
    const char *str = "";
    const char *first = str, *last = first;
    efirst = elast = nullptr; emsg = "";
    double x = .654;
    BOOST_CHECK(!get_real(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, .654);
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "real number expected");
    BOOST_CHECK(first == last);
  }
  {
    const char *str = ".";
    const char *first = str, *last = first + 1;
    efirst = elast = nullptr; emsg = "";
    double x = .654;
    BOOST_CHECK(!get_real(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, .654);
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "real number expected");
    BOOST_CHECK(first == str);
  }
  {
    const char *str = "1E+12345";
    const char *first = str, *last = first + 8;
    efirst = elast = nullptr; emsg = "";
    double x = .654;
    BOOST_CHECK(!get_real(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, .654);
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "real constant out of range for the given data type");
    BOOST_CHECK(first == str);
  }
  {
    const char *str = "1E-12345";
    const char *first = str, *last = first + 8;
    efirst = elast = nullptr; emsg = "";
    double x = .654;
    BOOST_CHECK(!get_real(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, .654);
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "real constant out of range for the given data type");
    BOOST_CHECK(first == str);
  }
  {
    const char *str = "0.";
    const char *first = str, *last = first + 2;
    efirst = elast = nullptr; emsg = "";
    double x = .654;
    BOOST_CHECK(get_real(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 0.);
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "219721.03839999999";
    const char *first = str, *last = first + 18;
    efirst = elast = nullptr; emsg = "";
    double x = .654;
    BOOST_CHECK(get_real(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 219721.03839999999);
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "1E";
    const char *first = str, *last = first + 2;
    efirst = elast = nullptr; emsg = "";
    double x = .654;
    BOOST_CHECK(get_real(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 1.0);
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == str+1);
  }
  {
    const char *str = "1E+";
    const char *first = str, *last = first + 3;
    efirst = elast = nullptr; emsg = "";
    double x = .654;
    BOOST_CHECK(get_real(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 1.0);
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == str+1);
  }
  {
    const char *str = "1E1";
    const char *first = str, *last = first + 3;
    efirst = elast = nullptr; emsg = "";
    double x = .654;
    BOOST_CHECK(get_real(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 1E1);
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "1E+1";
    const char *first = str, *last = first + 4;
    efirst = elast = nullptr; emsg = "";
    double x = .654;
    BOOST_CHECK(get_real(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 1E+1);
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == last);
  }
}
BOOST_AUTO_TEST_CASE(cwstr__float)
{
  using namespace txpl::lexer;
  const wchar_t *efirst;
  const wchar_t *elast;
  std::string emsg;
  auto eh = bind_error_handler(efirst, elast, emsg);
  {
    const wchar_t *str = L"";
    const wchar_t *first = str, *last = first;
    efirst = elast = nullptr; emsg = "";
    float x = .654f;
    BOOST_CHECK(!get_real(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, .654f);
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "real number expected");
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"0.";
    const wchar_t *first = str, *last = first + 2;
    efirst = elast = nullptr; emsg = "";
    float x = .654f;
    BOOST_CHECK(get_real(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 0.f);
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"219721.03839999999";
    const wchar_t *first = str, *last = first + 18;
    efirst = elast = nullptr; emsg = "";
    float x = .654f;
    BOOST_CHECK(get_real(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 219721.03839999999f);
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L".";
    const wchar_t *first = str, *last = first + 1;
    efirst = elast = nullptr; emsg = "";
    float x = .654f;
    BOOST_CHECK(!get_real(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, .654f);
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "real number expected");
    BOOST_CHECK(first == str);
  }
  {
    const wchar_t *str = L"1E-12345";
    const wchar_t *first = str, *last = first + 8;
    efirst = elast = nullptr; emsg = "";
    float x = .654f;
    BOOST_CHECK(!get_real(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, .654f);
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "real constant out of range for the given data type");
    BOOST_CHECK(first == str);
  }
  {
    const wchar_t *str = L"1E-12345";
    const wchar_t *first = str, *last = first + 8;
    efirst = elast = nullptr; emsg = "";
    float x = .654f;
    BOOST_CHECK(!get_real(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, .654f);
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "real constant out of range for the given data type");
    BOOST_CHECK(first == str);
  }
  {
    const wchar_t *str = L"1E";
    const wchar_t *first = str, *last = first + 2;
    efirst = elast = nullptr; emsg = "";
    float x = .654f;
    BOOST_CHECK(get_real(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 1.0f);
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == str+1);
  }
  {
    const wchar_t *str = L"1E+";
    const wchar_t *first = str, *last = first + 3;
    efirst = elast = nullptr; emsg = "";
    float x = .654f;
    BOOST_CHECK(get_real(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 1.0f);
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == str+1);
  }
  {
    const wchar_t *str = L"1E1";
    const wchar_t *first = str, *last = first + 3;
    efirst = elast = nullptr; emsg = "";
    float x = .654f;
    BOOST_CHECK(get_real(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 1E1f);
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"1E+1";
    const wchar_t *first = str, *last = first + 4;
    efirst = elast = nullptr; emsg = "";
    float x = .654f;
    BOOST_CHECK(get_real(first, last, x, eh));
    BOOST_CHECK_EQUAL(x, 1E+1f);
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
