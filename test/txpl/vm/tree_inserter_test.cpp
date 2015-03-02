// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_vm_tree_inserter

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_VM_TREE_INSERTER

#include <txpl/vm/tree_inserter.hpp>
#include <boost/variant/recursive_variant.hpp>
#include <boost/variant/get.hpp>
#include <map>
#include <string>
#include <type_traits>

struct Detail
  {
    static constexpr const char* separator() noexcept { return "::"; }
    //
    template<typename Range>
    static std::string
    strerr_malformed_name(Range const& path)
    {
      if(path.empty())
        return "empty names not allowed";
      else
        return "malformed name " + std::string(path.begin(), path.end());
    }
  };

struct Ehandler
{
  typedef void result_type;
  Ehandler(std::string& emsg) : _emsg(emsg) { }
  void operator()(std::string const& emsg) const { _emsg = emsg; }
private:
  std::string& _emsg;
};

typedef boost::make_recursive_variant<int, std::map<std::string, boost::recursive_variant_> >::type Variant;
typedef std::map<std::string, Variant> Map;

BOOST_AUTO_TEST_CASE(test_sep_inserter_typedefs)
{
  using std::is_same;
  using namespace txpl::vm;
  BOOST_CHECK((is_same<tree_inserter<Detail, Variant, Ehandler>::result_type, bool>::value));
  BOOST_CHECK((is_same<tree_inserter<Detail, Variant, Ehandler>::detail_type, Detail>::value));
  BOOST_CHECK((is_same<tree_inserter<Detail, Variant, Ehandler>::variant_type, Variant>::value));
  BOOST_CHECK((is_same<tree_inserter<Detail, Variant, Ehandler>::error_handler_type, Ehandler>::value));
}
BOOST_AUTO_TEST_CASE(test_tree_inserter__initially_empty)
{
  using namespace txpl::vm;
  using boost::get;

  typedef tree_inserter<Detail, Variant, Ehandler> TI;

  std::string emsg;
  Ehandler eh(emsg);

  {
    Map m;
    const char *str = "i10";
    const char *first = str, *last = first + 3;
    emsg = "";
    int x = 654;
    BOOST_CHECK(TI(10, eh)(m, first, last));
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK_NO_THROW(x = get<int>(m["i10"]));
    BOOST_CHECK_EQUAL(x, 10);
  }
  {
    Map m;
    Map m0;
    const char *str = "m0::i10";
    const char *first = str, *last = first + 7;
    emsg = "";
    int x = 654;
    BOOST_CHECK(TI(10, eh)(m, first, last));
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK_NO_THROW(m0 = get<Map>(m["m0"]));
    BOOST_CHECK_NO_THROW(x = get<int>(m0["i10"]));
    BOOST_CHECK_EQUAL(x, 10);
  }
  //
  {
    Map m;
    const char *str = "";
    const char *first = str, *last = first;
    emsg = "";
    BOOST_CHECK(!TI(0, eh)(m, first, last));
    BOOST_CHECK_EQUAL(emsg, "empty names not allowed");
  }
  {
    Map m;
    const char *str = "::xyz";
    const char *first = str, *last = first+5;
    emsg = "";
    BOOST_CHECK(!TI(0, eh)(m, first, last));
    BOOST_CHECK_EQUAL(emsg, "malformed name ::xyz");
  }
  {
    Map m;
    const char *str = "xyz::";
    const char *first = str, *last = first+5;
    emsg = "";
    BOOST_CHECK(!TI(0, eh)(m, first, last));
    BOOST_CHECK_EQUAL(emsg, "malformed name xyz::");
  }
}

BOOST_AUTO_TEST_CASE(test_tree_inserter__initially_nonempty)
{
  using namespace txpl::vm;
  using boost::get;

  typedef tree_inserter<Detail, Variant, Ehandler> TI;

  std::string emsg;
  Ehandler eh(emsg);

  Map m;
  Map m1;
  Map m2;

  m2["i21"] = 21;
  
  m1["m2"] = m2;
  m1["i11"] = 11;

  m["m1"] = m1;
  m["i1"] = 1;

  {
    Map mx;

    const char *str = "m1::i12";
    const char *first = str, *last = first + 7;
    emsg = "";
    int x = 654;
    BOOST_CHECK(TI(12, eh)(m, first, last));
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK_NO_THROW(mx = get<Map>(m["m1"]));
    BOOST_CHECK_NO_THROW(x = get<int>(mx["i12"]));
    BOOST_CHECK_EQUAL(x, 12);
    // Check if we didn't destroy other entries
    // i1
    emsg = "";
    x = 654;
    BOOST_CHECK_NO_THROW(x = get<int>(m["i1"]));
    BOOST_CHECK_EQUAL(x, 1);
    BOOST_CHECK_EQUAL(emsg, "");
    // m1::i11
    emsg = "";
    x = 654;
    BOOST_CHECK_NO_THROW(mx = get<Map>(m["m1"]));
    BOOST_CHECK_NO_THROW(x = get<int>(mx["i11"]));
    BOOST_CHECK_EQUAL(x, 11);
    // m1::m2::i21
    emsg = "";
    x = 654;
    BOOST_CHECK_NO_THROW(mx = get<Map>(m["m1"]));
    BOOST_CHECK_NO_THROW(mx = get<Map>(mx["m2"]));
    BOOST_CHECK_NO_THROW(x = get<int>(mx["i21"]));
    BOOST_CHECK_EQUAL(x, 21);
  }
  {
    // replace map with int
    Map mx;
    const char *str = "m1::m2";
    const char *first = str, *last = str + 6;
    emsg = "";
    int x = 654;
    BOOST_CHECK(TI(2, eh)(m, first, last));
    BOOST_CHECK_NO_THROW(mx = get<Map>(m["m1"]));
    BOOST_CHECK_THROW(get<Map>(mx["m2"]), boost::bad_get);
    BOOST_CHECK_EQUAL(x, 654);
    BOOST_CHECK_EQUAL(emsg, "");

    BOOST_CHECK_NO_THROW(x = get<int>(mx["m2"]));
    BOOST_CHECK_EQUAL(x, 2);
  }
  {
    // replace int with map
    Map mx;
    Map mm;

    mm["imm"] = 21;
    const char *str = "m1::i11";
    const char *first = str, *last = str + 7;
    emsg = "";
    int x = 654;
    BOOST_CHECK(TI(mm, eh)(m, first, last));
    BOOST_CHECK_EQUAL(emsg, "");

    BOOST_CHECK_NO_THROW(mx = get<Map>(m["m1"]));
    BOOST_CHECK_THROW(get<int>(mx["i11"]), boost::bad_get);

    BOOST_CHECK_NO_THROW(mx = get<Map>(mx["i11"]));
    BOOST_CHECK_NO_THROW(x = get<int>(mx["imm"]));
    BOOST_CHECK_EQUAL(x, 21);
  }

  {
    // replace int with map 2
    Map mx;

    const char *str = "i1::xx::i13";
    const char *first = str, *last = str + 11;
    emsg = "";
    int x = 654;
    BOOST_CHECK(TI(13, eh)(m, first, last));
    BOOST_CHECK_EQUAL(emsg, "");

    BOOST_CHECK_NO_THROW(mx = get<Map>(m["i1"]));
    BOOST_CHECK_NO_THROW(mx = get<Map>(mx["xx"]));
    BOOST_CHECK_NO_THROW(x = get<int>(mx["i13"]));
    BOOST_CHECK_EQUAL(x, 13);
  }
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{
  BOOST_CHECK(true);
}
#endif
