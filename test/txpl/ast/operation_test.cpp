// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_ast_operation

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_AST_OPERATION

#include <txpl/ast/operation.hpp>

BOOST_AUTO_TEST_CASE(test__operation)
{
  // FIXME: implement the test
  BOOST_CHECK(true);
}

#else
BOOST_AUTO_TEST_CASE(dummy)
{
  using namespace txpl::ast;
  BOOST_CHECK(true);
}
#endif
