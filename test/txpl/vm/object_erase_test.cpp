// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_vm_object_erase

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_VM_OBJECT_ERASE

#include <txpl/vm/object_erase.hpp>
#include <txpl/vm/value.hpp>
#include <txpl/vm/basic_types.hpp>
#include <yaul/variant/get.hpp>
#include <type_traits>

struct error_handler
{
  error_handler(std::string& msg) : msg(msg) { }
  void operator()(std::string const& msg) const { this->msg = msg; }
  std::string& msg;
};

BOOST_AUTO_TEST_CASE(test__object_erase__from_empty)
{
  using namespace txpl::vm;
  using yaul::get;

  std::string emsg;
  error_handler eh(emsg);

  {
    object<> obj;
    emsg = "";
    BOOST_CHECK(!object_erase(obj, "obj", "foo", eh));
    BOOST_CHECK_EQUAL(emsg, "obj has no member named foo");
  }
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{
  BOOST_CHECK(true);
}
#endif
