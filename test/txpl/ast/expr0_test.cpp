// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_ast_expr0

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_AST_EXPR0

#include <txpl/ast/expr0.hpp>
#include <txpl/ast/basic_types.hpp>
#include <txpl/ast/value.hpp>
#include <txpl/ast/squash_heads.hpp>
#include <boost/variant/get.hpp>

BOOST_AUTO_TEST_CASE(test__expr0__literal)
{
  using namespace txpl::ast;
  using boost::get;

  typedef const char* Iterator; // this should be token iterator in fact

  literal<Iterator> l2;
  literal<Iterator> l1;
  expr<Iterator, value<>, 0ul> e;
  {
    typedef basic_types<>::char_type char_type;
    l1.value = char_type{'a'};
    e.expr = l1;
    char_type x = char_type{'z'};
    BOOST_CHECK_NO_THROW(l2 = get<literal<Iterator> >(e.expr));
    BOOST_CHECK_NO_THROW(x = get<char_type>(l2.value));
    BOOST_CHECK_EQUAL(x, 'a');
  }
}
BOOST_AUTO_TEST_CASE(test__expr0__symbol)
{
  using namespace txpl::ast;
  using boost::get;

  typedef const char* Iterator; // this should be token iterator in fact

  symbol<Iterator> n2;
  symbol<Iterator> n1;
  expr<Iterator, value<>, 0ul> e;
  {
    n1.name = "the name";
    e.expr = n1;
    BOOST_CHECK_NO_THROW(n2 = get<symbol<Iterator> >(e.expr));
    BOOST_CHECK_EQUAL(n2.name, "the name");
  }
}
BOOST_AUTO_TEST_CASE(test__expr0__braced_expr)
{
  using namespace txpl::ast;
  using boost::get;

  typedef const char* Iterator; // this should be token iterator in fact

  literal<Iterator> l2;
  literal<Iterator> l1;
  expr<Iterator, value<>, 0ul> e;
  braced_expr<Iterator> b1;
  braced_expr<Iterator> b2;
  {
    typedef basic_types<>::char_type char_type;
    l1.value = char_type{'a'};
    squash_heads(b1.expr) = l1;
    e.expr = b1;
    char_type x = char_type{'z'};
    BOOST_CHECK_NO_THROW(b2 = get<braced_expr<Iterator> >(e.expr));
    BOOST_CHECK_NO_THROW(l2 = get<literal<Iterator> >(squash_heads(b2.expr)));
    BOOST_CHECK_NO_THROW(x = get<char_type>(l2.value));
    BOOST_CHECK_EQUAL(x, 'a');
  }
}

#else
BOOST_AUTO_TEST_CASE(dummy)
{
  using namespace txpl::ast;
  BOOST_CHECK(true);
}
#endif
