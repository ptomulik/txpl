// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost::org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_vm_object_find

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_VM_OBJECT_FIND

#include <txpl/vm/object_find.hpp>
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

BOOST_AUTO_TEST_CASE(test__object_find)
{
  using namespace txpl::vm;
  using boost::get;

  typedef basic_types<>::int_type int_type;

  std::string emsg;
  error_handler eh(emsg);

  object<value<> > ob0;
  object<value<> > ob1;
  object<value<> > ob2;
  object<value<> > ob3;

  value<> v0 = int_type{0};
  value<> v1 = int_type{1};
  value<> v2 = int_type{2};
  value<> v3 = int_type{3};


  ob3["v3"] = v3;

  ob2["ob3"] = ob3;
  ob2["v2"] = v2;

  ob1["ob2"] = ob2;
  ob1["v1"] = v1;

  ob0["ob1"] = ob1;
  ob0["v0"] = v0;


  {
    value<> val;
    emsg = "";
    BOOST_CHECK(object_find(ob0, "ob0", "ob1", val, eh));
    BOOST_CHECK_NO_THROW(get<object<value<> > >(val));
    BOOST_CHECK_EQUAL(emsg, "");
  }
  {
    value<> val;
    emsg = "";
    BOOST_CHECK(object_find(ob0, "ob0", "ob1.ob2", val, eh));
    BOOST_CHECK_NO_THROW(get<object<value<> > >(val));
    BOOST_CHECK_EQUAL(emsg, "");
  }
  {
    value<> val;
    emsg = "";
    BOOST_CHECK(object_find(ob0, "ob0", "ob1.ob2.ob3", val, eh));
    BOOST_CHECK_NO_THROW(get<object<value<> > >(val));
    BOOST_CHECK_EQUAL(emsg, "");
  }
  {
    value<> val;
    value<> v;
    int_type x = int_type{654};
    emsg = "";
    BOOST_CHECK(object_find(ob0, "ob0", "v0", val, eh));
    BOOST_CHECK_NO_THROW(x = get<int_type>(val));
    BOOST_CHECK(x == int_type{0});
    BOOST_CHECK_EQUAL(emsg, "");
  }
  {
    value<> val;
    value<> v;
    int_type x = int_type{654};
    emsg = "";
    BOOST_CHECK(object_find(ob0, "ob0", "ob1.v1", val, eh));
    BOOST_CHECK_NO_THROW(x = get<int_type>(val));
    BOOST_CHECK(x == int_type{1});
    BOOST_CHECK_EQUAL(emsg, "");
  }
  {
    value<> val;
    value<> v;
    emsg = "";
    int_type x = int_type{654};
    BOOST_CHECK(object_find(ob0, "ob0", "ob1.ob2.v2", val, eh));
    BOOST_CHECK_NO_THROW(x = get<int_type>(val));
    BOOST_CHECK(x == int_type{2});
    BOOST_CHECK_EQUAL(emsg, "");
  }
  {
    value<> val;
    value<> v;
    emsg = "";
    int_type x = int_type{654};
    BOOST_CHECK(object_find(ob0, "ob0", "ob1.ob2.ob3.v3", val, eh));
    BOOST_CHECK_NO_THROW(x = get<int_type>(val));
    BOOST_CHECK(x == int_type{3});
    BOOST_CHECK_EQUAL(emsg, "");
  }


  {
    value<> val;
    value<> v;
    emsg = "";
    int_type x = int_type{654};
    BOOST_CHECK(object_find(ob2, "ob1.ob2", "ob3.v3", val, eh));
    BOOST_CHECK_NO_THROW(x = get<int_type>(val));
    BOOST_CHECK(x == int_type{3});
    BOOST_CHECK_EQUAL(emsg, "");
  }


  {
    value<> val;
    emsg = "";
    BOOST_CHECK(!object_find(ob0, "ob0", "", val, eh));
    BOOST_CHECK_EQUAL(emsg, "empty names not allowed");
  }
  {
    value<> val;
    emsg = "";
    BOOST_CHECK(!object_find(ob0, "ob0", ".", val, eh));
    BOOST_CHECK_EQUAL(emsg, "malformed member name .");
  }
  {
    value<> val;
    emsg = "";
    BOOST_CHECK(!object_find(ob0, "ob0", ".ob1", val, eh));
    BOOST_CHECK_EQUAL(emsg, "malformed member name .ob1");
  }
  {
    value<> val;
    emsg = "";
    BOOST_CHECK(!object_find(ob0, "ob0", "ob1.", val, eh));
    BOOST_CHECK_EQUAL(emsg, "malformed member name ob1.");
  }
  {
    value<> val;
    emsg = "";
    BOOST_CHECK(!object_find(ob0, "ob0", ".ob1.", val, eh));
    BOOST_CHECK_EQUAL(emsg, "malformed member name .ob1.");
  }
  {
    value<> val;
    emsg = "";
    BOOST_CHECK(!object_find(ob0, "ob0", ".ob1.foo", val, eh));
    BOOST_CHECK_EQUAL(emsg, "malformed member name .ob1.foo");
  }
  {
    value<> val;
    emsg = "";
    BOOST_CHECK(!object_find(ob0, "ob0", "foo", val, eh));
    BOOST_CHECK_EQUAL(emsg, "ob0 has no member named foo");
  }
  {
    value<> val;
    emsg = "";
    BOOST_CHECK(!object_find(ob0, "ob0", "ob1.foo", val, eh));
    BOOST_CHECK_EQUAL(emsg, "ob0.ob1 has no member named foo");
  }
  {
    value<> val;
    emsg = "";
    BOOST_CHECK(!object_find(ob0, "ob0", "ob1.foo.ob3", val, eh));
    BOOST_CHECK_EQUAL(emsg, "ob0.ob1 has no member named foo");
  }
  {
    value<> val;
    emsg = "";
    BOOST_CHECK(!object_find(ob0, "ob0", "ob1.ob2.foo", val, eh));
    BOOST_CHECK_EQUAL(emsg, "ob0.ob1.ob2 has no member named foo");
  }
  {
    value<> val;
    emsg = "";
    BOOST_CHECK(!object_find(ob0, "ob0", "ob1.ob2.ob3.foo", val, eh));
    BOOST_CHECK_EQUAL(emsg, "ob0.ob1.ob2.ob3 has no member named foo");
  }
  {
    value<> val;
    emsg = "";
    BOOST_CHECK(!object_find(ob0, "ob0", "v0.foo", val, eh));
    BOOST_CHECK_EQUAL(emsg, "ob0.v0 is not an object");
  }
  {
    value<> val;
    emsg = "";
    BOOST_CHECK(!object_find(ob0, "ob0", "ob1.v1.foo", val, eh));
    BOOST_CHECK_EQUAL(emsg, "ob0.ob1.v1 is not an object");
  }
  {
    value<> val;
    emsg = "";
    BOOST_CHECK(!object_find(ob0, "ob0", "ob1.ob2.v2.foo", val, eh));
    BOOST_CHECK_EQUAL(emsg, "ob0.ob1.ob2.v2 is not an object");
  }
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{
  BOOST_CHECK(true);
}
#endif
