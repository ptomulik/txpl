// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_ast_expr

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_AST_EXPR

#include <txpl/ast/expr.hpp>
#include <txpl/ast/basic_types.hpp>
#include <txpl/ast/squash_heads.hpp>
#include <yaul/variant/get.hpp>

BOOST_AUTO_TEST_CASE(test__expr__literal)
{
  using namespace txpl::ast;
  using yaul::get;

  typedef const char* Iterator; // this should be token iterator in fact

  expr<Iterator> e;
  literal<Iterator> l1;
  literal<Iterator> l2;
  {
    typedef basic_types<>::char_type char_type;
    l1.value = char_type{'a'};
    squash_heads(e) = l1;
    char_type x = char_type{'z'};
    BOOST_CHECK_NO_THROW(l2 = get<literal<Iterator> >(squash_heads(e)));
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
