// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_vm_scope_lookup

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_VM_SCOPE_LOOKUP

#include <txpl/vm/scope_lookup.hpp>
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

BOOST_AUTO_TEST_CASE(test_lookup)
{
  using namespace txpl::vm;
  using yaul::get;

  typedef basic_types<>::int_type int_type;

  std::string emsg;
  error_handler eh(emsg);

  scope<> global;
  scope<> ns1;
  scope<> ns2;
  scope<> ns3;

  value<> v0 = int_type{0};
  value<> v1 = int_type{1};
  value<> v2 = int_type{2};
  value<> v3 = int_type{3};


  ns3["v"]      = v3;

  ns2["ns3"]    = ns3;
  ns2["v"]      = v2;

  ns1["ns2"]    = ns2;
  ns1["v"]      = v1;

  global["ns1"] = ns1;
  global["v"]   = v0;


  {
    symbol<> sym;
    value<> v;
    int_type x = int_type{654};
    emsg = "";
    BOOST_CHECK(scope_lookup(global, "", "v", sym, eh));
    BOOST_CHECK_NO_THROW(v = get<value<> >(sym));
    BOOST_CHECK_NO_THROW(x = get<int_type>(v));
    BOOST_CHECK(x == int_type{0});
    BOOST_CHECK_EQUAL(emsg, "");
  }
  {
    symbol<> sym;
    value<> v;
    int_type x = int_type{654};
    emsg = "";
    BOOST_CHECK(scope_lookup(global, "ns1", "v", sym, eh));
    BOOST_CHECK_NO_THROW(v = get<value<> >(sym));
    BOOST_CHECK_NO_THROW(x = get<int_type>(v));
    BOOST_CHECK(x == int_type{1});
    BOOST_CHECK_EQUAL(emsg, "");
  }
  {
    symbol<> sym;
    value<> v;
    int_type x = int_type{654};
    emsg = "";
    BOOST_CHECK(scope_lookup(global, "ns1::ns2", "v", sym, eh));
    BOOST_CHECK_NO_THROW(v = get<value<> >(sym));
    BOOST_CHECK_NO_THROW(x = get<int_type>(v));
    BOOST_CHECK(x == int_type{2});
    BOOST_CHECK_EQUAL(emsg, "");
  }
  {
    symbol<> sym;
    value<> v;
    int_type x = int_type{654};
    emsg = "";
    BOOST_CHECK(scope_lookup(global, "ns1::ns2::ns3", "v", sym, eh));
    BOOST_CHECK_NO_THROW(v = get<value<> >(sym));
    BOOST_CHECK_NO_THROW(x = get<int_type>(v));
    BOOST_CHECK(x == int_type{3});
    BOOST_CHECK_EQUAL(emsg, "");
  }
  {
    symbol<> sym;
    value<> v;
    int_type x = int_type{654};
    emsg = "";
    BOOST_CHECK(scope_lookup(global, "ns1::ns2::ns3", "ns1::v", sym, eh));
    BOOST_CHECK_NO_THROW(v = get<value<> >(sym));
    BOOST_CHECK_NO_THROW(x = get<int_type>(v));
    BOOST_CHECK(x == int_type{1});
    BOOST_CHECK_EQUAL(emsg, "");
  }
  {
    symbol<> sym;
    value<> v;
    int_type x = int_type{654};
    emsg = "";
    BOOST_CHECK(scope_lookup(global, "ns1::ns2::ns3", "ns2::v", sym, eh));
    BOOST_CHECK_NO_THROW(v = get<value<> >(sym));
    BOOST_CHECK_NO_THROW(x = get<int_type>(v));
    BOOST_CHECK(x == int_type{2});
    BOOST_CHECK_EQUAL(emsg, "");
  }
  {
    symbol<> sym;
    value<> v;
    int_type x = int_type{654};
    emsg = "";
    BOOST_CHECK(scope_lookup(global, "ns1::ns2::ns3", "ns1::ns2::v", sym, eh));
    BOOST_CHECK_NO_THROW(v = get<value<> >(sym));
    BOOST_CHECK_NO_THROW(x = get<int_type>(v));
    BOOST_CHECK(x == int_type{2});
    BOOST_CHECK_EQUAL(emsg, "");
  }
  {
    symbol<> sym;
    value<> v;
    int_type x = int_type{654};
    emsg = "";
    BOOST_CHECK(scope_lookup(global, "ns1", "ns2::ns3::v", sym, eh));
    BOOST_CHECK_NO_THROW(v = get<value<> >(sym));
    BOOST_CHECK_NO_THROW(x = get<int_type>(v));
    BOOST_CHECK(x == int_type{3});
    BOOST_CHECK_EQUAL(emsg, "");
  }
  {
    symbol<> sym;
    emsg = "";
    BOOST_CHECK(!scope_lookup(global, "ns1::nsX", "ns3::v", sym, eh));
    BOOST_CHECK_EQUAL(emsg, "nsX not found in ns1");
  }
  {
    symbol<> sym;
    emsg = "";
    BOOST_CHECK(!scope_lookup(global, "ns1::v", "v", sym, eh));
    BOOST_CHECK_EQUAL(emsg, "ns1::v is not a scope");
  }
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{
  BOOST_CHECK(true);
}
#endif
