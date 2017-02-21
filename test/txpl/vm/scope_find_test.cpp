// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_vm_scope_find

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_VM_SCOPE_FIND

#include <txpl/vm/scope_find.hpp>
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

BOOST_AUTO_TEST_CASE(test__scope_find)
{
  using namespace txpl::vm;
  using yaul::get;

  typedef basic_types<>::char_type char_type;
  typedef basic_types<>::int_type int_type;
  typedef basic_types<>::real_type real_type;

  std::string emsg;
  error_handler eh(emsg);

  scope<> global;
  scope<> ns1;
  scope<> ns2;
  scope<> ns3;

  value<> v0 = int_type{0};
  value<> v1 = char_type{'a'};
  value<> v2 = int_type{100};
  value<> v3 = real_type{.123};


  ns3["v3"] = v3;

  ns2["ns3"] = ns3;
  ns2["v2"] = v2;

  ns1["ns2"] = ns2;
  ns1["v1"] = v1;

  global["ns1"] = ns1;
  global["v0"] = v0;


  {
    symbol<> sym;
    emsg = "";
    BOOST_CHECK(!scope_find(global, "", sym, eh));
    BOOST_CHECK_EQUAL(emsg, "empty names not allowed");
  }
  {
    symbol<> sym;
    emsg = "";
    BOOST_CHECK(!scope_find(global, "::", sym, eh));
    BOOST_CHECK_EQUAL(emsg, "malformed symbol name ::");
  }
  {
    symbol<> sym;
    emsg = "";
    BOOST_CHECK(!scope_find(global, "::ns1", sym, eh));
    BOOST_CHECK_EQUAL(emsg, "malformed symbol name ::ns1");
  }
  {
    symbol<> sym;
    emsg = "";
    BOOST_CHECK(!scope_find(global, "ns1::", sym, eh));
    BOOST_CHECK_EQUAL(emsg, "malformed symbol name ns1::");
  }
  {
    symbol<> sym;
    emsg = "";
    BOOST_CHECK(!scope_find(global, "::", sym, eh));
    BOOST_CHECK_EQUAL(emsg, "malformed symbol name ::");
  }
  {
    symbol<> sym;
    emsg = "";
    BOOST_CHECK(!scope_find(global, "::ns1::", sym, eh));
    BOOST_CHECK_EQUAL(emsg, "malformed symbol name ::ns1::");
  }
  {
    symbol<> sym;
    emsg = "";
    BOOST_CHECK(!scope_find(global, "::ns1::foo", sym, eh));
    BOOST_CHECK_EQUAL(emsg, "malformed symbol name ::ns1::foo");
  }

  //
  {
    symbol<> sym;
    emsg = "";
    BOOST_CHECK(scope_find(global, "ns1", sym, eh));
    BOOST_CHECK_NO_THROW(get<scope<> >(sym));
    BOOST_CHECK_EQUAL(emsg, "");
  }
  {
    symbol<> sym;
    emsg = "";
    BOOST_CHECK(scope_find(global, "ns1::ns2", sym, eh));
    BOOST_CHECK_NO_THROW(get<scope<> >(sym));
    BOOST_CHECK_EQUAL(emsg, "");
  }
  {
    symbol<> sym;
    emsg = "";
    BOOST_CHECK(scope_find(global, "ns1::ns2::ns3", sym, eh));
    BOOST_CHECK_NO_THROW(get<scope<> >(sym));
    BOOST_CHECK_EQUAL(emsg, "");
  }
  {
    symbol<> sym;
    value<> v;
    int_type x = int_type{654};
    emsg = "";
    BOOST_CHECK(scope_find(global, "v0", sym, eh));
    BOOST_CHECK_NO_THROW(v = get<value<> >(sym));
    BOOST_CHECK_NO_THROW(x = get<int_type>(v));
    BOOST_CHECK(x == int_type{0});
    BOOST_CHECK_EQUAL(emsg, "");
  }
  {
    symbol<> sym;
    value<> v;
    char_type x = char_type{'x'};
    emsg = "";
    BOOST_CHECK(scope_find(global, "ns1::v1", sym, eh));
    BOOST_CHECK_NO_THROW(v = get<value<> >(sym));
    BOOST_CHECK_NO_THROW(x = get<char_type>(v));
    BOOST_CHECK(x == char_type{'a'});
    BOOST_CHECK_EQUAL(emsg, "");
  }
  {
    symbol<> sym;
    value<> v;
    emsg = "";
    int_type x = int_type{654};
    BOOST_CHECK(scope_find(global, "ns1::ns2::v2", sym, eh));
    BOOST_CHECK_NO_THROW(v = get<value<> >(sym));
    BOOST_CHECK_NO_THROW(x = get<int_type>(v));
    BOOST_CHECK(x == int_type{100});
    BOOST_CHECK_EQUAL(emsg, "");
  }
  {
    symbol<> sym;
    value<> v;
    emsg = "";
    real_type x = real_type{654};
    BOOST_CHECK(scope_find(global, "ns1::ns2::ns3::v3", sym, eh));
    BOOST_CHECK_NO_THROW(v = get<value<> >(sym));
    BOOST_CHECK_NO_THROW(x = get<real_type>(v));
    BOOST_CHECK(x == real_type{.123});
    BOOST_CHECK_EQUAL(emsg, "");
  }


  {
    symbol<> sym;
    value<> v;
    emsg = "";
    real_type x = real_type{654};
    BOOST_CHECK(scope_find(ns2, "ns3::v3", sym, eh));
    BOOST_CHECK_NO_THROW(v = get<value<> >(sym));
    BOOST_CHECK_NO_THROW(x = get<real_type>(v));
    BOOST_CHECK(x == real_type{.123});
    BOOST_CHECK_EQUAL(emsg, "");
  }


  {
    symbol<> sym;
    emsg = "";
    BOOST_CHECK(!scope_find(global, "foo", sym, eh));
    BOOST_CHECK_EQUAL(emsg, "foo not found in global scope");
  }
  {
    symbol<> sym;
    emsg = "";
    BOOST_CHECK(!scope_find(global, "ns1::foo", sym, eh));
    BOOST_CHECK_EQUAL(emsg, "foo not found in ns1");
  }
  {
    symbol<> sym;
    emsg = "";
    BOOST_CHECK(!scope_find(global, "ns1::ns2::foo", sym, eh));
    BOOST_CHECK_EQUAL(emsg, "foo not found in ns1::ns2");
  }
  {
    symbol<> sym;
    emsg = "";
    BOOST_CHECK(!scope_find(global, "ns1::ns2::ns3::foo", sym, eh));
    BOOST_CHECK_EQUAL(emsg, "foo not found in ns1::ns2::ns3");
  }
  {
    symbol<> sym;
    emsg = "";
    BOOST_CHECK(!scope_find(global, "v0::foo", sym, eh));
    BOOST_CHECK_EQUAL(emsg, "v0 is not a scope");
  }
  {
    symbol<> sym;
    emsg = "";
    BOOST_CHECK(!scope_find(global, "ns1::v1::foo", sym, eh));
    BOOST_CHECK_EQUAL(emsg, "ns1::v1 is not a scope");
  }
  {
    symbol<> sym;
    emsg = "";
    BOOST_CHECK(!scope_find(global, "ns1::ns2::v2::foo", sym, eh));
    BOOST_CHECK_EQUAL(emsg, "ns1::ns2::v2 is not a scope");
  }

  //
  
  {
    symbol<> sym;
    BOOST_CHECK(scope_find(global, "ns1::ns2::v2", sym));
  }
  {
    symbol<> sym;
    BOOST_CHECK(!scope_find(global, "ns1::ns2::v", sym));
  }
  {
    symbol<> sym;
    const char *str = "ns1::ns2::v2";
    const char *first = str, *last = str + 12;
    emsg = "";
    BOOST_CHECK(scope_find(global, first, last, sym, eh));
    BOOST_CHECK_EQUAL(emsg, "");
  }
  {
    symbol<> sym;
    const char *str = "ns1::ns2::v2";
    const char *first = str, *last = str + 12;
    BOOST_CHECK(scope_find(global, first, last, sym));
  }
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{
  BOOST_CHECK(true);
}
#endif
