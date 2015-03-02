// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_lexer_tokenize

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_LEXER_TOKENIZE

#include <txpl/lexer/tokenize.hpp>

BOOST_AUTO_TEST_CASE(tokenize__empty)
{
  using namespace txpl::lexer;
  const char *first = "", *last = first;
  std::vector<token<> > tokens;
  BOOST_CHECK(tokenize(first, last, tokens));
  BOOST_CHECK(first == last);
}
BOOST_AUTO_TEST_CASE(tokenize__spaces__only)
{
  using namespace txpl::lexer;
  {
    const char *first = " \t\n\r\v", *last = first + 5;
    std::vector<token<> > tokens;
    BOOST_CHECK(tokenize(first, last, tokens));
    BOOST_CHECK(tokens.empty());
    BOOST_CHECK(first == last);
  }
  {
    const char *first = " \t\n\r\v", *last = first + 5;
    std::vector<token<> > tokens;
    BOOST_CHECK(tokenize(first, last, tokens, false));
    BOOST_CHECK(tokens.size() ==  1ul);
    BOOST_CHECK(tokens.front() ==  token_t::spaces_);
    BOOST_CHECK(first == last);
  }
}
BOOST_AUTO_TEST_CASE(tokenize__numbers)
{
  using namespace txpl::lexer;
  {
    //                 000000000011111111112
    //                 012345678901234567890
    const char *str = "123 0x123 0123 1.23 ";
    const char *first = str, *last = first + 20;

    std::vector<token<> > tokens;
    BOOST_CHECK(tokenize(first, last, tokens));
    BOOST_CHECK(tokens.size() ==  4);

    BOOST_CHECK(tokens[0] ==  token_t::int_);
    BOOST_CHECK(tokens[0].begin() == str);
    BOOST_CHECK(tokens[0].end()   == str + 3);

    BOOST_CHECK(tokens[1] ==  token_t::int_);
    BOOST_CHECK(tokens[1].begin() == str + 4);
    BOOST_CHECK(tokens[1].end()   == str + 9);

    BOOST_CHECK(tokens[2] ==  token_t::int_);
    BOOST_CHECK(tokens[2].begin() == str + 10);
    BOOST_CHECK(tokens[2].end()   == str + 14);

    BOOST_CHECK(tokens[3] ==  token_t::real_);
    BOOST_CHECK(tokens[3].begin() == str + 15);
    BOOST_CHECK(tokens[3].end()   == str + 19);

    BOOST_CHECK(first == last);
  }
}
BOOST_AUTO_TEST_CASE(tokenize__literals)
{
  using namespace txpl::lexer;
  {
    //                 000000000000111111111111222222222223333333333
    //                 012345 6789 012345 678 9012345678 90123456789
    const char *str = "123 '\\t' \"s t r\" r\"r e g e x\"ci .123E+2";
    const char *first = str, *last = first + 39;

    std::vector<token<> > tokens;
    BOOST_CHECK(tokenize(first, last, tokens));
    BOOST_CHECK(tokens.size() ==  5);

    BOOST_CHECK(tokens[0] ==  token_t::int_);
    BOOST_CHECK(tokens[0].begin() == str);
    BOOST_CHECK(tokens[0].end()   == str + 3);

    BOOST_CHECK(tokens[1] ==  token_t::qchar_);
    BOOST_CHECK(tokens[1].begin() == str + 4);
    BOOST_CHECK(tokens[1].end()   == str + 8);

    BOOST_CHECK(tokens[2] ==  token_t::qstring_);
    BOOST_CHECK(tokens[2].begin() == str + 9);
    BOOST_CHECK(tokens[2].end()   == str + 16);

    BOOST_CHECK(tokens[3] ==  token_t::qregex_);
    BOOST_CHECK(tokens[3].begin() == str + 17);
    BOOST_CHECK(tokens[3].end()   == str + 31);

    BOOST_CHECK(tokens[4] ==  token_t::real_);
    BOOST_CHECK(tokens[4].begin() == str + 32);
    BOOST_CHECK(tokens[4].end()   == str + 39);

    BOOST_CHECK(first == last);
  }
}
BOOST_AUTO_TEST_CASE(tokenize__single_chars)
{
  using namespace txpl::lexer;
  {
    //                 000000000011111111112222222
    //                 012345678901234567890123456
    const char *str = " +- * / % ^ ~,.( ) [ ] { } ";
    const char *first = str, *last = first + 27;

    std::vector<token<> > tokens;
    BOOST_CHECK(tokenize(first, last, tokens));
    BOOST_CHECK(tokens.size() ==  15);

    BOOST_CHECK(tokens[0] ==  '+');
    BOOST_CHECK(tokens[0].begin() == str + 1);
    BOOST_CHECK(tokens[0].end()   == str + 2);

    BOOST_CHECK(tokens[1] ==  '-');
    BOOST_CHECK(tokens[1].begin() == str + 2);
    BOOST_CHECK(tokens[1].end()   == str + 3);

    BOOST_CHECK(tokens[2] ==  '*');
    BOOST_CHECK(tokens[2].begin() == str + 4);
    BOOST_CHECK(tokens[2].end()   == str + 5);

    BOOST_CHECK(tokens[3] ==  '/');
    BOOST_CHECK(tokens[3].begin() == str + 6);
    BOOST_CHECK(tokens[3].end()   == str + 7);

    BOOST_CHECK(tokens[4] ==  '%');
    BOOST_CHECK(tokens[4].begin() == str + 8);
    BOOST_CHECK(tokens[4].end()   == str + 9);

    BOOST_CHECK(tokens[5] ==  '^');
    BOOST_CHECK(tokens[5].begin() == str + 10);
    BOOST_CHECK(tokens[5].end()   == str + 11);

    BOOST_CHECK(tokens[6] ==  '~');
    BOOST_CHECK(tokens[6].begin() == str + 12);
    BOOST_CHECK(tokens[6].end()   == str + 13);

    BOOST_CHECK(tokens[7] == ',');
    BOOST_CHECK(tokens[7].begin() == str + 13);
    BOOST_CHECK(tokens[7].end()   == str + 14);

    BOOST_CHECK(tokens[8] ==  '.');
    BOOST_CHECK(tokens[8].begin() == str + 14);
    BOOST_CHECK(tokens[8].end()   == str + 15);

    BOOST_CHECK(tokens[9] ==  '(');
    BOOST_CHECK(tokens[9].begin() == str + 15);
    BOOST_CHECK(tokens[9].end()   == str + 16);

    BOOST_CHECK(tokens[10] == ')');
    BOOST_CHECK(tokens[10].begin() == str + 17);
    BOOST_CHECK(tokens[10].end()   == str + 18);

    BOOST_CHECK(tokens[11] ==  '[');
    BOOST_CHECK(tokens[11].begin() == str + 19);
    BOOST_CHECK(tokens[11].end()   == str + 20);

    BOOST_CHECK(tokens[12] ==  ']');
    BOOST_CHECK(tokens[12].begin() == str + 21);
    BOOST_CHECK(tokens[12].end()   == str + 22);

    BOOST_CHECK(tokens[13] ==  '{');
    BOOST_CHECK(tokens[13].begin() == str + 23);
    BOOST_CHECK(tokens[13].end()   == str + 24);

    BOOST_CHECK(tokens[14] ==  '}');
    BOOST_CHECK(tokens[14].begin() == str + 25);
    BOOST_CHECK(tokens[14].end()   == str + 26);

    BOOST_CHECK(first == last);
  }
  {
    //                 000000000011
    //                 012345678901
    const char *str = " & | < > ! ";
    const char *first = str, *last = first + 11;

    std::vector<token<> > tokens;
    BOOST_CHECK(tokenize(first, last, tokens));
    BOOST_CHECK(tokens.size() ==  5);

    BOOST_CHECK(tokens[0] ==  '&');
    BOOST_CHECK(tokens[0].begin() == str + 1);
    BOOST_CHECK(tokens[0].end()   == str + 2);

    BOOST_CHECK(tokens[1] ==  '|');
    BOOST_CHECK(tokens[1].begin() == str + 3);
    BOOST_CHECK(tokens[1].end()   == str + 4);

    BOOST_CHECK(tokens[2] ==  '<');
    BOOST_CHECK(tokens[2].begin() == str + 5);
    BOOST_CHECK(tokens[2].end()   == str + 6);

    BOOST_CHECK(tokens[3] ==  '>');
    BOOST_CHECK(tokens[3].begin() == str + 7);
    BOOST_CHECK(tokens[3].end()   == str + 8);

    BOOST_CHECK(tokens[4] ==  '!');
    BOOST_CHECK(tokens[4].begin() == str + 9);
    BOOST_CHECK(tokens[4].end()   == str + 10);

    BOOST_CHECK(first == last);
  }
}
BOOST_AUTO_TEST_CASE(tokenize__double_chars)
{
  using namespace txpl::lexer;
  {
    //                 0000000000111111111122222222223333
    //                 0123456789012345678901234567890123
    const char *str = "&& || << <= >> >= != !~ == =~ :: ";
    const char *first = str, *last = first + 33;

    std::vector<token<> > tokens;
    BOOST_CHECK(tokenize(first, last, tokens));
    BOOST_CHECK(tokens.size() ==  11);

    BOOST_CHECK(tokens[0] ==  token_t::and_);
    BOOST_CHECK(tokens[0].begin() == str + 0);
    BOOST_CHECK(tokens[0].end()   == str + 2);

    BOOST_CHECK(tokens[1] ==  token_t::or_);
    BOOST_CHECK(tokens[1].begin() == str + 3);
    BOOST_CHECK(tokens[1].end()   == str + 5);

    BOOST_CHECK(tokens[2] ==  token_t::lshift_);
    BOOST_CHECK(tokens[2].begin() == str + 6);
    BOOST_CHECK(tokens[2].end()   == str + 8);

    BOOST_CHECK(tokens[3] ==  token_t::le_);
    BOOST_CHECK(tokens[3].begin() == str + 9);
    BOOST_CHECK(tokens[3].end()   == str + 11);

    BOOST_CHECK(tokens[4] ==  token_t::rshift_);
    BOOST_CHECK(tokens[4].begin() == str + 12);
    BOOST_CHECK(tokens[4].end()   == str + 14);

    BOOST_CHECK(tokens[5] ==  token_t::ge_);
    BOOST_CHECK(tokens[5].begin() == str + 15);
    BOOST_CHECK(tokens[5].end()   == str + 17);

    BOOST_CHECK(tokens[6] ==  token_t::neq_);
    BOOST_CHECK(tokens[6].begin() == str + 18);
    BOOST_CHECK(tokens[6].end()   == str + 20);

    BOOST_CHECK(tokens[7] ==  token_t::nmatch_);
    BOOST_CHECK(tokens[7].begin() == str + 21);
    BOOST_CHECK(tokens[7].end()   == str + 23);

    BOOST_CHECK(tokens[8] ==  token_t::eq_);
    BOOST_CHECK(tokens[8].begin() == str + 24);
    BOOST_CHECK(tokens[8].end()   == str + 26);

    BOOST_CHECK(tokens[9] ==  token_t::match_);
    BOOST_CHECK(tokens[9].begin() == str + 27);
    BOOST_CHECK(tokens[9].end()   == str + 29);

    BOOST_CHECK(tokens[10] ==  token_t::nssep_);
    BOOST_CHECK(tokens[10].begin() == str + 30);
    BOOST_CHECK(tokens[10].end()   == str + 32);

    BOOST_CHECK(first == last);
  }
}
BOOST_AUTO_TEST_CASE(tokenize__expr__00)
{
  using namespace txpl::lexer;
  //                 0000000000
  //                 0123456789
  const char *str = "_s1 == 23";
  const char *first = str, *last = first + 9;

  std::vector<token<> > tokens;
  BOOST_CHECK(tokenize(first, last, tokens));
  BOOST_CHECK(tokens.size() ==  3);

  BOOST_CHECK(tokens[0] ==  token_t::word_);
  BOOST_CHECK(tokens[0].begin() == str + 0);
  BOOST_CHECK(tokens[0].end()   == str + 3);

  BOOST_CHECK(tokens[1] ==  token_t::eq_);
  BOOST_CHECK(tokens[1].begin() == str + 4);
  BOOST_CHECK(tokens[1].end()   == str + 6);

  BOOST_CHECK(tokens[2] ==  token_t::int_);
  BOOST_CHECK(tokens[2].begin() == str + 7);
  BOOST_CHECK(tokens[2].end()   == str + 9);

  BOOST_CHECK(first == last);
}

BOOST_AUTO_TEST_CASE(tokenize__expr__01)
{
  using namespace txpl::lexer;
  //                 000000000011 1111111122 22
  //                 012345678901 2345678901 23
  const char *str = "_s::h1 =~ r\"r e g e x\"i";
  const char *first = str, *last = first + 23;

  std::vector<token<> > tokens;
  BOOST_CHECK(tokenize(first, last, tokens));
  BOOST_CHECK(tokens.size() ==  5);

  BOOST_CHECK(tokens[0] ==  token_t::word_);
  BOOST_CHECK(tokens[0].begin() == str + 0);
  BOOST_CHECK(tokens[0].end()   == str + 2);

  BOOST_CHECK(tokens[1] ==  token_t::nssep_);
  BOOST_CHECK(tokens[1].begin() == str + 2);
  BOOST_CHECK(tokens[1].end()   == str + 4);

  BOOST_CHECK(tokens[2] ==  token_t::word_);
  BOOST_CHECK(tokens[2].begin() == str + 4);
  BOOST_CHECK(tokens[2].end()   == str + 6);

  BOOST_CHECK(tokens[3] ==  token_t::match_);
  BOOST_CHECK(tokens[3].begin() == str + 7);
  BOOST_CHECK(tokens[3].end()   == str + 9);

  BOOST_CHECK(tokens[4] ==  token_t::qregex_);
  BOOST_CHECK(tokens[4].begin() == str + 10);
  BOOST_CHECK(tokens[4].end()   == str + 23);

  BOOST_CHECK(first == last);
}
BOOST_AUTO_TEST_CASE(tokenize__err__01)
{
  using namespace txpl::lexer;
  //                 000000
  //                 012345
  const char *str = " #$% ";
  const char *first = str, *last = first + 5;

  std::vector<token<> > tokens;
  BOOST_CHECK(!tokenize(first, last, tokens));
  BOOST_CHECK(tokens.empty());
  BOOST_CHECK(first == (str+1));
}
BOOST_AUTO_TEST_CASE(tokenize__err__02)
{
  using namespace txpl::lexer;
  //                 0000000000
  //                 0123456789
  const char *str = " :: + ?@ ";
  const char *first = str, *last = first + 9;

  std::vector<token<> > tokens;
  BOOST_CHECK(!tokenize(first, last, tokens));
  BOOST_CHECK(tokens.size() ==  3);

  BOOST_CHECK(tokens[0] ==  token_t::nssep_);
  BOOST_CHECK(tokens[0].begin() == str + 1);
  BOOST_CHECK(tokens[0].end()   == str + 3);

  BOOST_CHECK(tokens[1] ==  '+');
  BOOST_CHECK(tokens[1].begin() == str + 4);
  BOOST_CHECK(tokens[1].end()   == str + 5);

  BOOST_CHECK(tokens[2] ==  '?');
  BOOST_CHECK(tokens[2].begin() == str + 6);
  BOOST_CHECK(tokens[2].end()   == str + 7);

  BOOST_CHECK(first == (str+7));
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{ 
  BOOST_CHECK(true);
}
#endif
