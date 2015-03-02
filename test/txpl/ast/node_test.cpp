// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_ast_node

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_AST_NODE

#include <txpl/ast/node.hpp>
#include <type_traits>

BOOST_AUTO_TEST_CASE(test__node__typedefs)
{
  using namespace txpl::ast;
  using std::is_same;
  BOOST_CHECK((is_same<node<const char*>::token_iterator_type, const char*>::value));
}

BOOST_AUTO_TEST_CASE(test__node__default_ctor)
{
  using namespace txpl::ast;
  BOOST_CHECK_NO_THROW(node<const char*>());
}

BOOST_AUTO_TEST_CASE(test__node__ctor_1)
{
  using namespace txpl::ast;
  const char *beg = "asd", *end = beg + 3;
  node<const char*> n(beg, end);
  BOOST_CHECK(n.begin() == beg);
  BOOST_CHECK(n.end() == end);
}

BOOST_AUTO_TEST_CASE(test__node__set_range)
{
  using namespace txpl::ast;
  const char *beg = "asd", *end = beg + 3;
  node<const char*> n;

  n.set_range(beg, end);

  BOOST_CHECK(n.begin() == beg);
  BOOST_CHECK(n.end() == end);
}

#else
BOOST_AUTO_TEST_CASE(dummy)
{
  using namespace txpl::ast;
  using namespace txpl::vm;
  BOOST_CHECK(true);
}
#endif
