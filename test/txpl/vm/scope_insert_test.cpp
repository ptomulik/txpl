// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_vm_scope_insert

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_VM_SCOPE_INSERT

#include <txpl/vm/scope_insert.hpp>
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

BOOST_AUTO_TEST_CASE(test__scope_insert)
{
  using namespace txpl::vm;
  using yaul::get;

  typedef basic_types<>::int_type int_type;

  std::string emsg;
  error_handler eh(emsg);

  {
    symbol<> sym;
    scope<> global;
    value<> v = int_type{10};
    value<> w;
    int_type x = int_type{654};
    emsg = "";
    BOOST_CHECK(scope_insert(global, "v0", v, eh));
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(scope_find(global, "v0", sym, eh ));
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK_NO_THROW(w = get<value<> >(sym));
    BOOST_CHECK_NO_THROW(x = get<int_type>(w));
    BOOST_CHECK(x == int_type{10});
  }
  {
    symbol<> sym;
    scope<> global;
    value<> v = int_type{10};
    value<> w;
    int_type x = int_type{654};
    emsg = "";
    BOOST_CHECK(scope_insert(global, "ns1::v1", v, eh));
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(scope_find(global, "ns1::v1", sym, eh ));
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK_NO_THROW(w = get<value<> >(sym));
    BOOST_CHECK_NO_THROW(x = get<int_type>(w));
    BOOST_CHECK(x == int_type{10});
  }

  {
    symbol<> sym;
    scope<> global;
    scope<> s;
    value<> v1 = int_type{10};
    value<> v2 = int_type{20};
    value<> w1;
    value<> w2;
    int_type x1 = int_type{654};
    int_type x2 = int_type{654};
    emsg = "";
    BOOST_CHECK(scope_insert(global, "ns1::ns2", s, eh));
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(scope_insert(global, "ns1::v1", v1, eh));
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(scope_insert(global, "ns1::ns2::v2", v2, eh));
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(scope_find(global, "ns1::ns2", sym, eh ));
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK_NO_THROW(get<scope<> >(sym));
    BOOST_CHECK(scope_find(global, "ns1::v1", sym, eh ));
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK_NO_THROW(w1 = get<value<> >(sym));
    BOOST_CHECK_NO_THROW(x1 = get<int_type>(w1));
    BOOST_CHECK(x1 == int_type{10});
    BOOST_CHECK(scope_find(global, "ns1::ns2::v2", sym, eh ));
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK_NO_THROW(w2 = get<value<> >(sym));
    BOOST_CHECK_NO_THROW(x2 = get<int_type>(w2));
    BOOST_CHECK(x2 == int_type{20});
    //
    // now mess-up a little 
    //
    BOOST_CHECK(scope_insert(global, "ns1", v1, eh));
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(scope_find(global, "ns1", sym, eh ));
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK_NO_THROW(w1 = get<value<> >(sym));
    BOOST_CHECK_NO_THROW(x1 = get<int_type>(w1));
    BOOST_CHECK(x1 == int_type{10});
    // everyhing, except ns1, is destroyed
    emsg = "";
    BOOST_CHECK(!scope_find(global, "ns1::v1", sym, eh));
    BOOST_CHECK_EQUAL(emsg, "ns1 is not a scope");
  }


  {
    symbol<> sym;
    scope<> global;
    emsg = "";
    value<> v = int_type{10};
    BOOST_CHECK(!scope_insert(global, "", v, eh));
    BOOST_CHECK_EQUAL(emsg, "empty names not allowed");
  }
  {
    symbol<> sym;
    scope<> global;
    emsg = "";
    value<> v = int_type{10};
    BOOST_CHECK(!scope_insert(global, "::", v, eh));
    BOOST_CHECK_EQUAL(emsg, "malformed symbol name ::");
  }
  {
    symbol<> sym;
    scope<> global;
    emsg = "";
    value<> v = int_type{10};
    BOOST_CHECK(!scope_insert(global, "::ns1::", v, eh));
    BOOST_CHECK_EQUAL(emsg, "malformed symbol name ::ns1::");
  }
  {
    symbol<> sym;
    scope<> global;
    scope<> s;
    emsg = "";
    BOOST_CHECK(!scope_insert(global, "::ns1::ns2", s, eh));
    BOOST_CHECK_EQUAL(emsg, "malformed symbol name ::ns1::ns2");
  }

  //

  {
    symbol<> sym;
    scope<> global;
    scope<> s;
    const char *str = "ns1::ns2";
    const char *first = str, *last = first + 8;
    emsg = "";
    BOOST_CHECK(scope_insert(global, first, last, s, eh));
    BOOST_CHECK_EQUAL(emsg, "");
  }
  {
    symbol<> sym;
    scope<> global;
    scope<> s;
    const char *str = "ns1::ns2";
    const char *first = str, *last = first + 8;
    BOOST_CHECK(scope_insert(global, first, last, s));
  }
  {
    symbol<> sym;
    scope<> global;
    scope<> s;
    BOOST_CHECK(scope_insert(global, "ns1::ns2", s));
  }
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{
  BOOST_CHECK(true);
}
#endif
