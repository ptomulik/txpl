// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_vm_scope_erase

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_VM_SCOPE_ERASE

#include <txpl/vm/scope_erase.hpp>
#include <txpl/vm/scope_find.hpp>
#include <txpl/vm/scope_insert.hpp>
#include <txpl/vm/value.hpp>
#include <txpl/vm/basic_types.hpp>
#include <boost/variant/get.hpp>
#include <type_traits>

struct error_handler
{
  error_handler(std::string& msg) : msg(msg) { }
  void operator()(std::string const& msg) const { this->msg = msg; }
  std::string& msg;
};

BOOST_AUTO_TEST_CASE(test__scope_erase)
{
  using namespace txpl::vm;
  using boost::get;

  typedef basic_types<>::int_type int_type;

  std::string emsg;
  error_handler eh(emsg);
  {
    symbol<> sym;
    scope<> global;
    value<> v = int_type{10};
    emsg = "";
    BOOST_CHECK(scope_insert(global, "v0", v, eh));
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(scope_erase(global, "v0", eh));
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(!scope_find(global, "v0", sym, eh ));
    BOOST_CHECK_EQUAL(emsg, "v0 not found in global scope");
  }

  {
    symbol<> sym;
    scope<> global;
    value<> v = int_type{10};

    BOOST_CHECK(scope_insert(global, "ns1::v1", v, eh));
    BOOST_CHECK(scope_insert(global, "ns1::ns2::v2", v, eh));
    BOOST_CHECK(scope_insert(global, "ns1::ns2::ns3::v3", v, eh));

    BOOST_CHECK(scope_find(global, "ns1::v1", sym, eh));
    BOOST_CHECK(scope_find(global, "ns1::ns2", sym, eh));
    BOOST_CHECK(scope_find(global, "ns1::ns2::v2", sym, eh));
    BOOST_CHECK(scope_find(global, "ns1::ns2::ns3", sym, eh));
    BOOST_CHECK(scope_find(global, "ns1::ns2::ns3::v3", sym, eh));

    // Erase one element, and check what's left
    emsg = "";
    BOOST_CHECK(scope_erase(global, "ns1::ns2::ns3::v3", eh));
    BOOST_CHECK_EQUAL(emsg, "");

    BOOST_CHECK(scope_find(global, "ns1::v1", sym, eh));
    BOOST_CHECK(scope_find(global, "ns1::ns2", sym, eh));
    BOOST_CHECK(scope_find(global, "ns1::ns2::v2", sym, eh));
    BOOST_CHECK(scope_find(global, "ns1::ns2::ns3", sym, eh));
    emsg = "";
    BOOST_CHECK(!scope_find(global, "ns1::ns2::ns3::v3", sym, eh));
    BOOST_CHECK_EQUAL(emsg, "v3 not found in ns1::ns2::ns3");

    // Now it should return false
    emsg = "";
    BOOST_CHECK(!scope_erase(global, "ns1::ns2::ns3::v3", eh));
    BOOST_CHECK_EQUAL(emsg, "v3 not found in ns1::ns2::ns3");

    // Erase another element, and check what's left
    emsg = "";
    BOOST_CHECK(scope_erase(global, "ns1::ns2", eh));
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(scope_find(global, "ns1", sym, eh));
    BOOST_CHECK(scope_find(global, "ns1::v1", sym, eh));
    emsg = "";
    BOOST_CHECK(!scope_find(global, "ns1::ns2", sym, eh));
    BOOST_CHECK_EQUAL(emsg, "ns2 not found in ns1");
    emsg = "";
    BOOST_CHECK(!scope_find(global, "ns1::ns2::v2", sym, eh));
    BOOST_CHECK_EQUAL(emsg, "ns2 not found in ns1");
    emsg = "";
    BOOST_CHECK(!scope_find(global, "ns1::ns2::ns3", sym, eh));
    BOOST_CHECK_EQUAL(emsg, "ns2 not found in ns1");
    emsg = "";
    BOOST_CHECK(!scope_find(global, "ns1::ns2::ns3::v3", sym, eh));
    BOOST_CHECK_EQUAL(emsg, "ns2 not found in ns1");
  }
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{
  BOOST_CHECK(true);
}
#endif
