// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost::org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_vm_dict

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_VM_DICT

#include <txpl/vm/dict.hpp>
#include <txpl/vm/basic_types.hpp>
#include <string>
#include <boost/variant/get.hpp>
#include <type_traits>

BOOST_AUTO_TEST_CASE(test__dict__type)
{
  using namespace txpl::vm;
  using std::is_same;
  BOOST_CHECK((is_same<dict<>, dict<value<> > >::value));
}

BOOST_AUTO_TEST_CASE(test__dict__typedefs)
{
  using namespace txpl::vm;
  using std::is_same;
  BOOST_CHECK((is_same<dict<>::key_type, std::string>::value));
  BOOST_CHECK((is_same<dict<>::mapped_type, value<> >::value));
}

BOOST_AUTO_TEST_CASE(test__dict__as_map)
{
  using namespace txpl::vm;
  using boost::get;
  typedef basic_types<>::int_type int_type;
  typedef basic_types<>::char_type char_type;

  dict<> obj;
  obj["i"] = int_type{10};
  obj["c"] = char_type{'a'};

  {
    int_type i;
    BOOST_CHECK_NO_THROW(i = get<int_type>(obj["i"]));
    BOOST_CHECK(i == int_type{10});
  }
  {
    char_type i;
    BOOST_CHECK_NO_THROW(i = get<char_type>(obj["c"]));
    BOOST_CHECK(i == char_type{'a'});
  }
}

#else
BOOST_AUTO_TEST_CASE(dummy)
{
  BOOST_CHECK(true);
}
#endif
