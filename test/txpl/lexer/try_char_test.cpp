// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_lexer_try_char

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_LEXER_TRY_CHAR

#include <txpl/lexer/try_char.hpp>

BOOST_AUTO_TEST_CASE(cstr)
{
  using namespace txpl::lexer;
  {
    const char *str = "a";
    const char *first = str, *last = first + 1;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "A";
    const char *first = str, *last = first + 1;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "\\0";
    const char *first = str, *last =  first + 2;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "\\1";
    const char *first = str, *last =  first + 2;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "\\2";
    const char *first = str, *last =  first + 2;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "\\3";
    const char *first = str, *last =  first + 2;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "\\4";
    const char *first = str, *last =  first + 2;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "\\5";
    const char *first = str, *last =  first + 2;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "\\6";
    const char *first = str, *last =  first + 2;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "\\7";
    const char *first = str, *last =  first + 2;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }

  {
    const char *str = "\\70";
    const char *first = str, *last =   first + 3;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "\\77";
    const char *first = str, *last =   first + 3;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "\\377";
    const char *first = str, *last =   first + 4;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "\\3777";
    const char *first = str, *last =   first + 5;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == str+4);
  }

  {
    const char *str = "\\x0";
    const char *first = str, *last =  first + 3;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }

  {
    const char *str = "\\x12";
    const char *first = str, *last = first + 4;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "\\xaF";
    const char *first = str, *last = first + 4;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }

  {
    const char *str = "\\\"";
    const char *first = str, *last = first + 2;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "\\'";
    const char *first = str, *last = first + 2;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "\\?";
    const char *first = str, *last = first + 2;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "\\\\";
    const char *first = str, *last = first + 2;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "\\a";
    const char *first = str, *last = first + 2;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "\\b";
    const char *first = str, *last = first + 2;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "\\f";
    const char *first = str, *last = first + 2;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "\\n";
    const char *first = str, *last =  first + 2;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "\\r";
    const char *first = str, *last =  first + 2;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "\\t";
    const char *first = str, *last =  first + 2;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "\\v";
    const char *first = str, *last =  first + 2;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }

  {
    const char *str = "\\012";
    const char *first = str, *last = first+4;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "\\01234";
    const char *first = str, *last = first+6;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == str+4);
  }
  {
    const char *str = "";
    const char *first = str, *last = first;
    BOOST_CHECK(!try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "\\";
    const char *first = str, *last = first+1;
    BOOST_CHECK(!try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "\\x";
    const char *first = str, *last = first+2;
    BOOST_CHECK(!try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const char *str = "\\m";
    const char *first = str, *last = first+2;
    BOOST_CHECK(!try_char(first, last));
    BOOST_CHECK(first == str+1);
  }
  {
    const char *str = "\t";
    const char *first = str, *last = first+1;
    BOOST_CHECK(!try_char(first, last));
    BOOST_CHECK(first == str);
  }
  {
    const char *str = "\\\t";
    const char *first = str, *last = first+2;
    BOOST_CHECK(!try_char(first, last));
    BOOST_CHECK(first == str+1);
  }
  {
    const char *str = "\\x\t";
    const char *first = str, *last = first+3;
    BOOST_CHECK(!try_char(first, last));
    BOOST_CHECK(first == str+2);
  }
}
BOOST_AUTO_TEST_CASE(cwstr)
{
  using namespace txpl::lexer;
  {
    const wchar_t *str = L"a";
    const wchar_t *first = str, *last = first + 1;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"A";
    const wchar_t *first = str, *last = first + 1;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }

  {
    const wchar_t *str = L"\\0";
    const wchar_t *first = str, *last =  first + 2;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"\\1";
    const wchar_t *first = str, *last =  first + 2;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"\\2";
    const wchar_t *first = str, *last =  first + 2;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"\\3";
    const wchar_t *first = str, *last =  first + 2;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"\\4";
    const wchar_t *first = str, *last =  first + 2;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"\\5";
    const wchar_t *first = str, *last =  first + 2;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"\\6";
    const wchar_t *first = str, *last =  first + 2;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"\\7";
    const wchar_t *first = str, *last =  first + 2;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }

  {
    const wchar_t *str = L"\\70";
    const wchar_t *first = str, *last =  first + 3;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"\\77";
    const wchar_t *first = str, *last =  first + 3;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"\\377";
    const wchar_t *first = str, *last = first + 4;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }


  {
    const wchar_t *str = L"\\x0";
    const wchar_t *first = str, *last = first + 3;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"\\x12";
    const wchar_t *first = str, *last = first + 4;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"\\xaF";
    const wchar_t *first = str, *last = first + 4;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }

  {
    const wchar_t *str = L"\\\"";
    const wchar_t *first = str, *last =  first + 2;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"\\'";
    const wchar_t *first = str, *last =  first + 2;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"\\?";
    const wchar_t *first = str, *last =  first + 2;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"\\\\";
    const wchar_t *first = str, *last =  first + 2;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"\\a";
    const wchar_t *first = str, *last =  first + 2;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"\\b";
    const wchar_t *first = str, *last =  first + 2;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"\\f";
    const wchar_t *first = str, *last =  first + 2;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"\\n";
    const wchar_t *first = str, *last =  first + 2;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"\\r";
    const wchar_t *first = str, *last =  first + 2;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"\\t";
    const wchar_t *first = str, *last =  first + 2;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"\\v";
    const wchar_t *first = str, *last =  first + 2;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"\\012";
    const wchar_t *first = str, *last = first+4;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"\\01234";
    const wchar_t *first = str, *last = first+6;
    BOOST_CHECK(try_char(first, last));
    BOOST_CHECK(first == str+4);
  }
  {
    const wchar_t *str = L"";
    const wchar_t *first = str, *last = first;
    BOOST_CHECK(!try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"\\";
    const wchar_t *first = str, *last = first+1;
    BOOST_CHECK(!try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"\\x";
    const wchar_t *first = str, *last = first+2;
    BOOST_CHECK(!try_char(first, last));
    BOOST_CHECK(first == last);
  }
  {
    const wchar_t *str = L"\\m";
    const wchar_t *first = str, *last = first+2;
    BOOST_CHECK(!try_char(first, last));
    BOOST_CHECK(first == str+1);
  }
  {
    const wchar_t *str = L"\t";
    const wchar_t *first = str, *last = first+1;
    BOOST_CHECK(!try_char(first, last));
    BOOST_CHECK(first == str);
  }
  {
    const wchar_t *str = L"\\\t";
    const wchar_t *first = str, *last = first+2;
    BOOST_CHECK(!try_char(first, last));
    BOOST_CHECK(first == str+1);
  }
  {
    const wchar_t *str = L"\\x\t";
    const wchar_t *first = str, *last = first+3;
    BOOST_CHECK(!try_char(first, last));
    BOOST_CHECK(first == str+2);
  }
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{ 
  BOOST_CHECK(true);
}
#endif
