// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_ast_symbol

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_AST_SYMBOL

#include <txpl/ast/symbol.hpp>

BOOST_AUTO_TEST_CASE(test__symbol)
{
  using namespace txpl::ast;

  typedef const char* Iterator; // this should be token iterator in fact

  BOOST_CHECK_NO_THROW(symbol<Iterator>());
  {
    symbol<Iterator> sym;
    BOOST_CHECK_NO_THROW(sym.name = "n1");
    BOOST_CHECK_EQUAL(sym.name.size(),2);
  }
}

#else
BOOST_AUTO_TEST_CASE(dummy)
{
  using namespace txpl::ast;
  BOOST_CHECK(true);
}
#endif
