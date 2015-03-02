// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_vm_symbol

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_VM_SYMBOL

#include <txpl/vm/symbol.hpp>
#include <txpl/vm/scope.hpp>
#include <boost/variant/get.hpp>

BOOST_AUTO_TEST_CASE(defaults)
{
  using namespace txpl::vm;
  symbol<> sym;
  scope<symbol<> > s;
  value<> v;
  BOOST_CHECK_NO_THROW(boost::get<boost::blank>(sym));
  sym = v;
  BOOST_CHECK_NO_THROW(boost::get<value<> >(sym));
  sym = s;
  BOOST_CHECK_NO_THROW(boost::get<scope<symbol<> > >(sym));
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{
  BOOST_CHECK(true);
}
#endif
