// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_vm_disambiguate

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_VM_DISAMBIGUBTE

#include <txpl/vm/disambiguate.hpp>
#include <txpl/vm/basic_types.hpp>
#include <type_traits>

BOOST_AUTO_TEST_CASE(char_type_)
{
  using namespace txpl::vm;
  using std::is_same;
  typedef basic_types<> BT;
  typedef BT::char_type char_type;
  BOOST_CHECK((is_same<decltype(disambiguate<BT>('a')), char_type>::value));
  BOOST_CHECK((is_same<decltype(disambiguate<BT>(L'a')), char_type>::value));
  BOOST_CHECK(disambiguate<BT>('a')   == char_type{'a'});
  BOOST_CHECK(disambiguate<BT>(L'a')  == char_type{'a'});
}
BOOST_AUTO_TEST_CASE(int_type_)
{
  using namespace txpl::vm;
  using std::is_same;
  typedef basic_types<> BT;
  typedef BT::int_type int_type;
  typedef long long longlong;
  BOOST_CHECK((is_same<decltype(disambiguate<BT>(short{123})),    int_type>::value));
  BOOST_CHECK((is_same<decltype(disambiguate<BT>(int{123})),      int_type>::value));
  BOOST_CHECK((is_same<decltype(disambiguate<BT>(long{123})),     int_type>::value));
  BOOST_CHECK((is_same<decltype(disambiguate<BT>(longlong{123})), int_type>::value));
  BOOST_CHECK(disambiguate<BT>(short{123})    == int_type{123});
  BOOST_CHECK(disambiguate<BT>(int{123})      == int_type{123});
  BOOST_CHECK(disambiguate<BT>(long{123})     == int_type{123});
  BOOST_CHECK(disambiguate<BT>(longlong{123}) == int_type{123});
}
BOOST_AUTO_TEST_CASE(bool_type_)
{
  using namespace txpl::vm;
  using std::is_same;
  typedef basic_types<> BT;
  typedef BT::bool_type bool_type;
  BOOST_CHECK((is_same<decltype(disambiguate<BT>(bool{true})), bool_type>::value));
  BOOST_CHECK(disambiguate<BT>(bool{true}) == bool_type{true});
}
BOOST_AUTO_TEST_CASE(real_type_)
{
  using namespace txpl::vm;
  using std::is_same;
  typedef basic_types<> BT;
  typedef BT::real_type real_type;
  typedef long double longdouble;
  BOOST_CHECK((is_same<decltype(disambiguate<BT>(float{123})),      real_type>::value));
  BOOST_CHECK((is_same<decltype(disambiguate<BT>(double{123})),     real_type>::value));
  BOOST_CHECK((is_same<decltype(disambiguate<BT>(longdouble{123})), real_type>::value));
  BOOST_CHECK(disambiguate<BT>(float{123})      == real_type{123});
  BOOST_CHECK(disambiguate<BT>(double{123})     == real_type{123});
  BOOST_CHECK(disambiguate<BT>(longdouble{123}) == real_type{123});
}
BOOST_AUTO_TEST_CASE(string_type_)
{
  using namespace txpl::vm;
  using std::is_same;
  typedef basic_types<> BT;
  typedef BT::string_type string_type;
  string_type s;
  BOOST_CHECK((is_same<decltype(disambiguate<BT>(s)), string_type const&>::value));
  BOOST_CHECK(&disambiguate<BT>(s) == &s);
}
BOOST_AUTO_TEST_CASE(regex_type_)
{
  using namespace txpl::vm;
  using std::is_same;
  typedef basic_types<> BT;
  typedef BT::regex_type regex_type;
  regex_type re;
  BOOST_CHECK((is_same<decltype(disambiguate<BT>(re)), regex_type const&>::value));
  BOOST_CHECK(&disambiguate<BT>(re) == &re);
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{
  BOOST_CHECK(true);
}
#endif
