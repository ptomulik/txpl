// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt);
#define BOOST_TEST_MODULE test_txpl_lexer_get_qregex

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_LEXER_GET_QREGEX

#include <txpl/lexer/get_qregex.hpp>
#include <txpl/lexer/bind_error_handler.hpp>

BOOST_AUTO_TEST_CASE(cstr__regex)
{
  using namespace std::regex_constants;
  using namespace txpl::lexer;
  const char *efirst;
  const char *elast;
  std::string emsg;
  auto eh = bind_error_handler(efirst, elast, emsg);
  {
    const char *str = "";
    const char *first = str, *last = first;
    efirst = elast = nullptr; emsg = "";
    std::regex x("x");
    BOOST_CHECK(!get_qregex(first, last, x, eh));
    BOOST_CHECK(std::regex_match("x", x));
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "expected regex-type specifier");
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "z\"asd\"";
    const char *first = str, *last = first + 6;
    efirst = elast = nullptr; emsg = "";
    std::regex x("x");
    BOOST_CHECK(!get_qregex(first, last, x, eh));
    BOOST_CHECK(std::regex_match("x", x));
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "expected regex-type specifier");
    BOOST_CHECK(first == str);
  }
  {
    const char *str = "r";
    const char *first = str, *last = first + 1;
    efirst = elast = nullptr; emsg = "";
    std::regex x("x");
    BOOST_CHECK(!get_qregex(first, last, x, eh));
    BOOST_CHECK(std::regex_match("x", x));
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "expected opening double-quote");
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "rxz";
    const char *first = str, *last = first+3;
    efirst = elast = nullptr; emsg = "";
    std::regex x("x");
    BOOST_CHECK(!get_qregex(first, last, x, eh));
    BOOST_CHECK(std::regex_match("x", x));
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "expected opening double-quote");
    BOOST_CHECK(first == str+1);
  }
  {
    const char *str = "r\"";
    const char *first = str, *last = first + 2;
    efirst = elast = nullptr; emsg = "";
    std::regex x("x");
    BOOST_CHECK(!get_qregex(first, last, x, eh));
    BOOST_CHECK(std::regex_match("x", x));
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "incomplete regex string");
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "r\"asd";
    const char *first = str, *last = first + 5;
    efirst = elast = nullptr; emsg = "";
    std::regex x("x");
    BOOST_CHECK(!get_qregex(first, last, x, eh));
    BOOST_CHECK(std::regex_match("x", x));
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "expected closing double-quote");
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "r\"ECMAScript\"";
    const char *first = str, *last = first + 13;
    efirst = elast = nullptr; emsg = "";
    std::regex x("x");
    BOOST_CHECK(get_qregex(first, last, x, eh));
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(std::regex_match("ECMAScript", x));
    BOOST_CHECK_EQUAL(x.flags(), ECMAScript);
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "b\"basic\"";
    const char *first = str, *last = first + 8;
    efirst = elast = nullptr; emsg = "";
    std::regex x("x");
    BOOST_CHECK(get_qregex(first, last, x, eh));
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(std::regex_match("basic", x));
    BOOST_CHECK_EQUAL(x.flags(), basic);
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "x\"extended\"";
    const char *first = str, *last = first + 11;
    efirst = elast = nullptr; emsg = "";
    std::regex x("x");
    BOOST_CHECK(get_qregex(first, last, x, eh));
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(std::regex_match("extended", x));
    BOOST_CHECK_EQUAL(x.flags(), extended);
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "a\"awk\"";
    const char *first = str, *last = first + 6;
    efirst = elast = nullptr; emsg = "";
    std::regex x("x");
    BOOST_CHECK(get_qregex(first, last, x, eh));
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(std::regex_match("awk", x));
    BOOST_CHECK_EQUAL(x.flags(), awk);
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "g\"grep\"";
    const char *first = str, *last = first + 7;
    efirst = elast = nullptr; emsg = "";
    std::regex x("x");
    BOOST_CHECK(get_qregex(first, last, x, eh));
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(std::regex_match("grep", x));
    BOOST_CHECK_EQUAL(x.flags(), grep);
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "e\"egrep\"";
    const char *first = str, *last = first + 8;
    efirst = elast = nullptr; emsg = "";
    std::regex x("x");
    BOOST_CHECK(get_qregex(first, last, x, eh));
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(std::regex_match("egrep", x));
    BOOST_CHECK_EQUAL(x.flags(), egrep);
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "r\"a\"i";
    const char *first = str, *last = first + 5;
    efirst = elast = nullptr; emsg = "";
    std::regex x("x");
    BOOST_CHECK(get_qregex(first, last, x, eh));
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(std::regex_match("a", x));
    BOOST_CHECK_EQUAL(x.flags(), ECMAScript | icase);
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "r\"a\"c";
    const char *first = str, *last = first + 5;
    efirst = elast = nullptr; emsg = "";
    std::regex x("x");
    BOOST_CHECK(get_qregex(first, last, x, eh));
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(std::regex_match("a", x));
    BOOST_CHECK_EQUAL(x.flags(), ECMAScript | collate);
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "r\"a\"ic";
    const char *first = str, *last = first + 6;
    efirst = elast = nullptr; emsg = "";
    std::regex x("x");
    BOOST_CHECK(get_qregex(first, last, x, eh));
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(std::regex_match("a", x));
    BOOST_CHECK_EQUAL(x.flags(), ECMAScript | icase | collate);
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "r\"a\"ci";
    const char *first = str, *last = first + 6;
    efirst = elast = nullptr; emsg = "";
    std::regex x("x");
    BOOST_CHECK(get_qregex(first, last, x, eh));
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(std::regex_match("a", x));
    BOOST_CHECK_EQUAL(x.flags(), ECMAScript | icase | collate);
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "r\".+goi.*\\?\"";
    const char *first = str, *last = first + 12;
    efirst = elast = nullptr; emsg = "";
    std::regex x("x");
    BOOST_CHECK(get_qregex(first, last, x, eh));
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(std::regex_match("how is it going?",x));
    BOOST_CHECK(!std::regex_match("HOW IS IT GOING?",x));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "r\".+goi.*\\?\"i";
    const char *first = str, *last = first + 13;
    efirst = elast = nullptr; emsg = "";
    std::regex x("x");
    BOOST_CHECK(get_qregex(first, last, x, eh));
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(std::regex_match("how is it going?",x));
    BOOST_CHECK(std::regex_match("HOW IS IT GOING?",x));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "r\"\"ic";
    const char *first = str, *last = first+5;
    efirst = elast = nullptr; emsg = "";
    std::regex x("x");
    BOOST_CHECK(get_qregex(first, last, x, eh));
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "r\"\"ici";
    const char *first = str, *last = first+6;
    efirst = elast = nullptr; emsg = "";
    std::regex x("x");
    BOOST_CHECK(get_qregex(first, last, x, eh));
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == str+5);
  }
  {
    const char *str = "r\"+\"";
    const char *first = str, *last = first+4;
    efirst = elast = nullptr; emsg = "";
    std::regex x("x");
    BOOST_CHECK(!get_qregex(first, last, x, eh));
    BOOST_CHECK(efirst == first);
    BOOST_CHECK(elast == last);
    BOOST_CHECK_NE(emsg, "");
    BOOST_CHECK(first == last);
  }
}
///////////////////////////////////////////////////////////////////////
// bug in clang 3.5.0 prevents us from testing the following cases.
// currently I get the error:
//  L"shift count 32 >= width of type 'int' (32 bits)"
///////////////////////////////////////////////////////////////////////
#ifndef __clang__
BOOST_AUTO_TEST_CASE(cwstr__wregex)
{
  using namespace std::regex_constants;
  using namespace txpl::lexer;
  const wchar_t *efirst;
  const wchar_t *elast;
  std::string emsg;
  auto eh = bind_error_handler(efirst, elast, emsg);
  std::wregex x;
  using namespace std::regex_constants;
  {
    const wchar_t *str = L"";
    const wchar_t *first = str, *last = first;
    efirst = elast = nullptr; emsg = "";
    std::wregex x(L"x");
    BOOST_CHECK(!get_qregex(first, last, x, eh));
    BOOST_CHECK(std::regex_match(L"x", x));
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "expected regex-type specifier");
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"z\"asd\"";
    const wchar_t *first = str, *last = first + 6;
    efirst = elast = nullptr; emsg = "";
    std::wregex x(L"x");
    BOOST_CHECK(!get_qregex(first, last, x, eh));
    BOOST_CHECK(std::regex_match(L"x", x));
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "expected regex-type specifier");
    BOOST_CHECK(first == str);
  }
  {
    const wchar_t *str = L"r";
    const wchar_t *first = str, *last = first + 1;
    efirst = elast = nullptr; emsg = "";
    std::wregex x(L"x");
    BOOST_CHECK(!get_qregex(first, last, x, eh));
    BOOST_CHECK(std::regex_match(L"x", x));
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "expected opening double-quote");
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"rxz";
    const wchar_t *first = str, *last = first+3;
    efirst = elast = nullptr; emsg = "";
    std::wregex x(L"x");
    BOOST_CHECK(!get_qregex(first, last, x, eh));
    BOOST_CHECK(std::regex_match(L"x", x));
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "expected opening double-quote");
    BOOST_CHECK(first == str+1);
  }
  {
    const wchar_t *str = L"r\"";
    const wchar_t *first = str, *last = first + 2;
    efirst = elast = nullptr; emsg = "";
    std::wregex x(L"x");
    BOOST_CHECK(!get_qregex(first, last, x, eh));
    BOOST_CHECK(std::regex_match(L"x", x));
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "incomplete regex string");
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"r\"asd";
    const wchar_t *first = str, *last = first + 5;
    efirst = elast = nullptr; emsg = "";
    std::wregex x(L"x");
    BOOST_CHECK(!get_qregex(first, last, x, eh));
    BOOST_CHECK(std::regex_match(L"x", x));
    BOOST_CHECK_EQUAL(efirst, first);
    BOOST_CHECK_EQUAL(elast, last);
    BOOST_CHECK_EQUAL(emsg, "expected closing double-quote");
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"r\"ECMAScript\"";
    const wchar_t *first = str, *last = first + 13;
    efirst = elast = nullptr; emsg = "";
    std::wregex x(L"x");
    BOOST_CHECK(get_qregex(first, last, x, eh));
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(std::regex_match(L"ECMAScript", x));
    BOOST_CHECK_EQUAL(x.flags(), ECMAScript);
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"b\"basic\"";
    const wchar_t *first = str, *last = first + 8;
    efirst = elast = nullptr; emsg = "";
    std::wregex x(L"x");
    BOOST_CHECK(get_qregex(first, last, x, eh));
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(std::regex_match(L"basic", x));
    BOOST_CHECK_EQUAL(x.flags(), basic);
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"x\"extended\"";
    const wchar_t *first = str, *last = first + 11;
    efirst = elast = nullptr; emsg = "";
    std::wregex x(L"x");
    BOOST_CHECK(get_qregex(first, last, x, eh));
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(std::regex_match(L"extended", x));
    BOOST_CHECK_EQUAL(x.flags(), extended);
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"a\"awk\"";
    const wchar_t *first = str, *last = first + 6;
    efirst = elast = nullptr; emsg = "";
    std::wregex x(L"x");
    BOOST_CHECK(get_qregex(first, last, x, eh));
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(std::regex_match(L"awk", x));
    BOOST_CHECK_EQUAL(x.flags(), awk);
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"g\"grep\"";
    const wchar_t *first = str, *last = first + 7;
    efirst = elast = nullptr; emsg = "";
    std::wregex x(L"x");
    BOOST_CHECK(get_qregex(first, last, x, eh));
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(std::regex_match(L"grep", x));
    BOOST_CHECK_EQUAL(x.flags(), grep);
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"e\"egrep\"";
    const wchar_t *first = str, *last = first + 8;
    efirst = elast = nullptr; emsg = "";
    std::wregex x(L"x");
    BOOST_CHECK(get_qregex(first, last, x, eh));
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(std::regex_match(L"egrep", x));
    BOOST_CHECK_EQUAL(x.flags(), egrep);
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"r\"a\"i";
    const wchar_t *first = str, *last = first + 5;
    efirst = elast = nullptr; emsg = "";
    std::wregex x(L"x");
    BOOST_CHECK(get_qregex(first, last, x, eh));
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(std::regex_match(L"a", x));
    BOOST_CHECK_EQUAL(x.flags(), ECMAScript | icase);
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"r\"a\"c";
    const wchar_t *first = str, *last = first + 5;
    efirst = elast = nullptr; emsg = "";
    std::wregex x(L"x");
    BOOST_CHECK(get_qregex(first, last, x, eh));
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(std::regex_match(L"a", x));
    BOOST_CHECK_EQUAL(x.flags(), ECMAScript | collate);
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"r\"a\"ic";
    const wchar_t *first = str, *last = first + 6;
    efirst = elast = nullptr; emsg = "";
    std::wregex x(L"x");
    BOOST_CHECK(get_qregex(first, last, x, eh));
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(std::regex_match(L"a", x));
    BOOST_CHECK_EQUAL(x.flags(), ECMAScript | icase | collate);
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"r\"a\"ci";
    const wchar_t *first = str, *last = first + 6;
    efirst = elast = nullptr; emsg = "";
    std::wregex x(L"x");
    BOOST_CHECK(get_qregex(first, last, x, eh));
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(std::regex_match(L"a", x));
    BOOST_CHECK_EQUAL(x.flags(), ECMAScript | icase | collate);
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"r\".+goi.*\\?\"";
    const wchar_t *first = str, *last = first + 12;
    efirst = elast = nullptr; emsg = "";
    std::wregex x(L"x");
    BOOST_CHECK(get_qregex(first, last, x, eh));
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(std::regex_match(L"how is it going?",x));
    BOOST_CHECK(!std::regex_match(L"HOW IS IT GOING?",x));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"r\".+goi.*\\?\"i";
    const wchar_t *first = str, *last = first + 13;
    efirst = elast = nullptr; emsg = "";
    std::wregex x(L"x");
    BOOST_CHECK(get_qregex(first, last, x, eh));
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(std::regex_match(L"how is it going?",x));
    BOOST_CHECK(std::regex_match(L"HOW IS IT GOING?",x));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"r\"\"ic";
    const wchar_t *first = str, *last = first+5;
    efirst = elast = nullptr; emsg = "";
    std::wregex x(L"x");
    BOOST_CHECK(get_qregex(first, last, x, eh));
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"r\"\"ici";
    const wchar_t *first = str, *last = first+6;
    efirst = elast = nullptr; emsg = "";
    std::wregex x(L"x");
    BOOST_CHECK(get_qregex(first, last, x, eh));
    BOOST_CHECK(efirst == nullptr);
    BOOST_CHECK(elast == nullptr);
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(first == str+5);
  }
  {
    const wchar_t *str = L"r\"+\"";
    const wchar_t *first = str, *last = first+4;
    efirst = elast = nullptr; emsg = "";
    std::wregex x(L"x");
    BOOST_CHECK(!get_qregex(first, last, x, eh));
    BOOST_CHECK(std::regex_match(L"x", x));
    BOOST_CHECK(efirst == first);
    BOOST_CHECK(elast == last);
    BOOST_CHECK_NE(emsg, "");
    BOOST_CHECK(first == last);
  }
}
#endif // __clang__
#else
BOOST_AUTO_TEST_CASE(dummy)
{ 
  BOOST_CHECK(true);
}
#endif
