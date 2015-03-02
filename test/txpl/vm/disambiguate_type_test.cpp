// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_vm_disambiguate_type

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_VM_DISAMBIGUBTE_TYPE

#include <txpl/vm/disambiguate_type.hpp>
#include <txpl/vm/basic_types.hpp>
#include <type_traits>

BOOST_AUTO_TEST_CASE(char_type)
{
  using namespace txpl::vm;
  using std::is_same;
  typedef basic_types<> BT;
  BOOST_CHECK((is_same<disambiguate_type<BT, char>::type, BT::char_type>::value));
  BOOST_CHECK((is_same<disambiguate_type<BT, wchar_t>::type, BT::char_type>::value));
}
BOOST_AUTO_TEST_CASE(int_type)
{
  using namespace txpl::vm;
  using std::is_same;
  typedef basic_types<> BT;
  BOOST_CHECK((is_same<disambiguate_type<BT, short int>::type, BT::int_type>::value));
  BOOST_CHECK((is_same<disambiguate_type<BT, int>::type, BT::int_type>::value));
  BOOST_CHECK((is_same<disambiguate_type<BT, long int>::type, BT::int_type>::value));
  BOOST_CHECK((is_same<disambiguate_type<BT, long long int>::type, BT::int_type>::value));
}
BOOST_AUTO_TEST_CASE(bool_type)
{
  using namespace txpl::vm;
  using std::is_same;
  typedef basic_types<> BT;
  BOOST_CHECK((is_same<disambiguate_type<BT, bool>::type, BT::bool_type>::value));
}
BOOST_AUTO_TEST_CASE(real_type)
{
  using namespace txpl::vm;
  using std::is_same;
  typedef basic_types<> BT;
  BOOST_CHECK((is_same<disambiguate_type<BT, float>::type, BT::real_type>::value));
  BOOST_CHECK((is_same<disambiguate_type<BT, double>::type, BT::real_type>::value));
  BOOST_CHECK((is_same<disambiguate_type<BT, long double>::type, BT::real_type>::value));
}
BOOST_AUTO_TEST_CASE(string_type)
{
  using namespace txpl::vm;
  using std::is_same;
  typedef basic_types<> BT;
  BOOST_CHECK((is_same<disambiguate_type<BT, std::string>::type, BT::string_type>::value));
}
BOOST_AUTO_TEST_CASE(regex_type)
{
  using namespace txpl::vm;
  using std::is_same;
  typedef basic_types<> BT;
  BOOST_CHECK((is_same<disambiguate_type<BT, std::regex>::type, BT::regex_type>::value));
}

#else
BOOST_AUTO_TEST_CASE(dummy)
{
  BOOST_CHECK(true);
}
#endif
