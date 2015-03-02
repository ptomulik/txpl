// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost::org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_vm_object_insert

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_VM_OBJECT_INSERT

#include <txpl/vm/object_insert.hpp>
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


BOOST_AUTO_TEST_CASE(test__object_insert__to_empty)
{
  using namespace txpl::vm;
  using boost::get;

  typedef basic_types<>::int_type int_type;

  std::string emsg;
  error_handler eh(emsg);

  {
    object<> obj;
    emsg = "";
    BOOST_CHECK(object_insert(obj, "obj", "v", int_type{10}, eh));
    BOOST_CHECK_EQUAL(emsg, "");
    int_type x = int_type{654};
    BOOST_CHECK_NO_THROW(x = get<int_type>(obj.at("v")));
    BOOST_CHECK(x == int_type{10});
  }

  {
    object<> obj;
    object<> v;
    emsg = "";
    BOOST_CHECK(object_insert(obj, "obj", "v.w", int_type{10}, eh));
    BOOST_CHECK_EQUAL(emsg, "");
    int_type x = int_type{654};
    BOOST_CHECK_NO_THROW(v = get<object<> >(obj.at("v")));
    BOOST_CHECK_NO_THROW(x = get<int_type>(v.at("w")));
    BOOST_CHECK(x == int_type{10});
  }
}
BOOST_AUTO_TEST_CASE(test__object_insert__to_nonempty)
{
  using namespace txpl::vm;
  using boost::get;
  typedef basic_types<>::int_type int_type;

  std::string emsg;
  error_handler eh(emsg);

  object<> ob0;
  object<> ob1;
  object<> ob2;

  ob0["i0"] = int_type{0};
  ob1["i0"] = int_type{10};
  ob2["i0"] = int_type{20};

  ob1["ob2"] = ob2;
  ob0["ob1"] = ob1;

  {
    object<> v;
    object<> w;

    emsg = "";
    BOOST_CHECK(object_insert(ob0, "ob0", "i1", int_type{1}, eh));
    BOOST_CHECK_EQUAL(emsg, "");
    emsg = "";
    BOOST_CHECK(object_insert(ob0, "ob0", "ob1.i1", int_type{11}, eh));
    BOOST_CHECK_EQUAL(emsg, "");
    emsg = "";
    BOOST_CHECK(object_insert(ob0, "ob0", "ob1.ob2.i1", int_type{21}, eh));
    BOOST_CHECK_EQUAL(emsg, "");

    // Ensure the inserted entries are present in object
    BOOST_CHECK_NO_THROW(v = get<object<> >(ob0.at("ob1")));
    BOOST_CHECK_NO_THROW(w = get<object<> >(v.at("ob2")));
    int_type x = int_type{654};
    BOOST_CHECK_NO_THROW(x = get<int_type>(ob0.at("i1")));
    BOOST_CHECK(x == int_type{1});
    BOOST_CHECK_NO_THROW(x = get<int_type>(v.at("i1")));
    BOOST_CHECK(x == int_type{11});
    BOOST_CHECK_NO_THROW(x = get<int_type>(w.at("i1")));
    BOOST_CHECK(x == int_type{21});

    // Ensure that we haven't messed up existing members
    BOOST_CHECK_NO_THROW(x = get<int_type>(ob0.at("i0")));
    BOOST_CHECK(x == int_type{0});
    BOOST_CHECK_NO_THROW(x = get<int_type>(v.at("i0")));
    BOOST_CHECK(x == int_type{10});
    BOOST_CHECK_NO_THROW(x = get<int_type>(w.at("i0")));
    BOOST_CHECK(x == int_type{20});
  }

}
BOOST_AUTO_TEST_CASE(test__object_insert__erroneous)
{
  using namespace txpl::vm;
  typedef basic_types<>::int_type int_type;

  std::string emsg;
  error_handler eh(emsg);
  {
    object<> obj;
    emsg = "";
    BOOST_CHECK(!object_insert(obj, "obj", "", int_type{10}, eh));
    BOOST_CHECK_EQUAL(emsg, "empty names not allowed");
  }
  {
    object<> obj;
    emsg = "";
    BOOST_CHECK(!object_insert(obj, "obj", ".foo.bar", int_type{10}, eh));
    BOOST_CHECK_EQUAL(emsg, "malformed member name .foo.bar");
  }
  {
    object<> obj;
    emsg = "";
    BOOST_CHECK(!object_insert(obj, "obj", "foo.bar.", int_type{10}, eh));
    BOOST_CHECK_EQUAL(emsg, "malformed member name bar.");
  }
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{
  BOOST_CHECK(true);
}
#endif
