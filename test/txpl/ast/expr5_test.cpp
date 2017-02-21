// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_ast_expr5

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_AST_EXPR5

#include <txpl/ast/expr5.hpp>

BOOST_AUTO_TEST_CASE(test__expr5__literal)
{
  using namespace txpl::ast;
  using yaul::get;

  // FIXME: implement some tests
  BOOST_CHECK(true);
}

#else
BOOST_AUTO_TEST_CASE(dummy)
{
  using namespace txpl::ast;
  BOOST_CHECK(true);
}
#endif
