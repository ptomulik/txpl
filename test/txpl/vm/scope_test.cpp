// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_vm_scope

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_VM_SCOPE

#include <txpl/vm/scope.hpp>
#include <txpl/vm/symbol.hpp>
#include <txpl/vm/basic_types.hpp>
#include <yaul/variant/get.hpp>
#include <string>
#include <type_traits>

struct error_handler
{
  error_handler(std::string& msg) : msg(msg) { }
  void operator()(std::string const& msg) const { this->msg = msg; }
  std::string& msg;
};

BOOST_AUTO_TEST_CASE(test__scope__type)
{
  using namespace txpl::vm;
  using std::is_same;
  BOOST_CHECK((is_same<scope<>, scope<symbol<> > >::value));
}

BOOST_AUTO_TEST_CASE(test__scope__typedefs)
{
  using namespace txpl::vm;
  using std::is_same;
  BOOST_CHECK((is_same<scope<>::key_type, std::string>::value));
  BOOST_CHECK((is_same<scope<>::mapped_type, symbol<> >::value));
}

BOOST_AUTO_TEST_CASE(test__scope__map)
{
  using namespace txpl::vm;
  using yaul::get;

  typedef basic_types<>::int_type int_type;
  scope<> s0;
  scope<> s1;

  s1["i0"] = int_type{10};
  s0["s1"] = s1;
  s0["i0"] = int_type{0};

  value<> v;

  int_type x = int_type{654};
  BOOST_CHECK_NO_THROW(v = get<value<> >(s0.at("i0")));
  BOOST_CHECK_NO_THROW(x = get<int_type>(v));
  BOOST_CHECK(x == int_type{0});

  scope<> s;
  BOOST_CHECK_NO_THROW(s = get<scope<> >(s0.at("s1")));
  BOOST_CHECK_NO_THROW(v = get<value<> >(s.at("i0")));
  BOOST_CHECK_NO_THROW(x = get<int_type>(v));
  BOOST_CHECK(x == int_type{10});
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{
  BOOST_CHECK(true);
}
#endif
