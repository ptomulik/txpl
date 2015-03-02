// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_ast_braced_expr

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_AST_BRACED_EXPR

#include <txpl/ast/braced_expr.hpp>
#include <txpl/ast/basic_types.hpp>
#include <txpl/ast/squash_heads.hpp>
#include <boost/variant/get.hpp>

BOOST_AUTO_TEST_CASE(test__braced_expr__literal)
{
  using namespace txpl::ast;
  using boost::get;

  typedef const char* Iterator; // this should be token iterator in fact

  braced_expr<Iterator> b;
  literal<Iterator> l1;
  literal<Iterator> l2;
  {
    typedef basic_types<>::char_type char_type;
    l1.value = char_type{'a'};
    squash_heads(b.expr) = l1;
    char_type x = char_type{'z'};
    BOOST_CHECK_NO_THROW(l2 = get<literal<Iterator> >(squash_heads(b.expr)));
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
