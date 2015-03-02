// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_ast_expr3

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_AST_EXPR3

#include <txpl/ast/expr3.hpp>
#include <txpl/ast/unary_expr.hpp>
#include <txpl/ast/literal.hpp>
#include <txpl/ast/squash_heads.hpp>
#include <boost/variant/get.hpp>

BOOST_AUTO_TEST_CASE(test__expr3__unary_expr)
{
  using namespace txpl::ast;
  using boost::get;

  typedef const char* Iterator; // this should be token iterator in fact
  typedef unary_expr<Iterator>::operator_type operator_type;

  literal<Iterator> l2;
  literal<Iterator> l1;
  expr<Iterator, value<>, 3ul> e;
  unary_expr<Iterator> u1;
  unary_expr<Iterator> u2;
  {
    typedef basic_types<>::char_type char_type;
    l1.value = char_type{'a'};
    u1.operator_ = static_cast<operator_type>('+');
    squash_heads(u1.expr) = l1;
    e.expr = u1;
    char_type x = char_type{'z'};
    BOOST_CHECK_NO_THROW(u2 = get<unary_expr<Iterator> >(e.expr));
    BOOST_CHECK_NO_THROW(l2 = get<literal<Iterator> >(squash_heads(u2.expr)));
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
