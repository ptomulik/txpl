// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_ast_literal

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_AST_LITERAL

#include <txpl/ast/literal.hpp>
#include <txpl/ast/basic_types.hpp>
#include <yaul/variant/get.hpp>

BOOST_AUTO_TEST_CASE(test__literal)
{
  using namespace txpl::ast;
  using yaul::get;

  typedef basic_types<>::char_type char_type;
  typedef basic_types<>::int_type int_type;
  typedef basic_types<>::bool_type bool_type;
  typedef basic_types<>::real_type real_type;
  typedef basic_types<>::string_type string_type;
  typedef basic_types<>::regex_type regex_type;

  typedef const char* Iterator; // this should be token iterator in fact

  BOOST_CHECK_NO_THROW(literal<Iterator>());

  {
    char_type x;
    literal<Iterator> l;
    l.value = char_type{'a'};
    BOOST_CHECK_NO_THROW(x = yaul::get<char_type>(l.value));
    BOOST_CHECK_EQUAL(x, char_type{'a'});
  }
  {
    int_type x;
    literal<Iterator> l;
    l.value = int_type{123};
    BOOST_CHECK_NO_THROW(x = yaul::get<int_type>(l.value));
    BOOST_CHECK_EQUAL(x, int_type{123});
  }
  {
    bool_type x;
    literal<Iterator> l;
    l.value = bool_type{true};
    BOOST_CHECK_NO_THROW(x = yaul::get<bool_type>(l.value));
    BOOST_CHECK_EQUAL(x, bool_type{true});
  }
  {
    bool_type x;
    literal<Iterator> l;
    l.value = bool_type{false};
    BOOST_CHECK_NO_THROW(x = yaul::get<bool_type>(l.value));
    BOOST_CHECK_EQUAL(x, bool_type{false});
  }
  {
    real_type x;
    literal<Iterator> l;
    l.value = real_type{.123};
    BOOST_CHECK_NO_THROW(x = yaul::get<real_type>(l.value));
    BOOST_CHECK_EQUAL(x, real_type{.123});
  }
  {
    string_type x;
    literal<Iterator> l;
    l.value  = string_type("a string");
    BOOST_CHECK_NO_THROW(x = yaul::get<string_type>(l.value));
    BOOST_CHECK_EQUAL(x, string_type("a string"));
  }
  {
    regex_type x;
    literal<Iterator> l;
    l.value = regex_type("a regex");
    BOOST_CHECK_NO_THROW(x = yaul::get<regex_type>(l.value));
    BOOST_CHECK(std::regex_match("a regex", x));
  }
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{
  using namespace txpl::ast;
  BOOST_CHECK(true);
}
#endif
