// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_vm_tree_finder

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_VM_TREE_FINDER

#include <txpl/vm/tree_finder.hpp>
#include <yaul/variant/recursive_variant.hpp>
#include <yaul/variant/get.hpp>
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
    //
    template<typename Range>
    static std::string
    strerr_not_found(Range const& head, Range const& key)
    {
      if(head.empty())
        return std::string(key.begin(), key.end()) + " not found";
      else
        return std::string(key.begin(), key.end()) + " is not a member of "
            +  std::string(head.begin(), head.end());
    }
    //
    template<typename Range>
    static std::string
    strerr_not_a_map(Range const& path)
    { return std::string(path.begin(), path.end()) + " is not a map"; }
  };

struct Ehandler
{
  typedef void result_type;
  Ehandler(std::string& emsg) : _emsg(emsg) { }
  void operator()(std::string const& emsg) const { _emsg = emsg; }
private:
  std::string& _emsg;
};

typedef yaul::make_recursive_variant<int, std::map<std::string, yaul::recursive_variant_> >::type Variant;
typedef std::map<std::string, Variant> Map;

BOOST_AUTO_TEST_CASE(test_sep_finder_typedefs)
{
  using std::is_same;
  using namespace txpl::vm;
  BOOST_CHECK((is_same<tree_finder<Detail, Variant, Ehandler>::result_type, bool>::value));
  BOOST_CHECK((is_same<tree_finder<Detail, Variant, Ehandler>::detail_type, Detail>::value));
  BOOST_CHECK((is_same<tree_finder<Detail, Variant, Ehandler>::variant_type, Variant>::value));
  BOOST_CHECK((is_same<tree_finder<Detail, Variant, Ehandler>::error_handler_type, Ehandler>::value));
}
BOOST_AUTO_TEST_CASE(test_tree_finder__1)
{
  using namespace txpl::vm;
  using yaul::get;

  typedef tree_finder<Detail,Variant,Ehandler> TF;

  Map m03;
  m03["t030"] = 3;

  Map m0;
  m0["t01"] = 1;
  m0["t02"] = 2;
  m0["t03"] = m03;

  std::string emsg;
  Ehandler eh(emsg);


  {
    Variant r;
    const char *str = "t01";
    const char *first = str, *last = first + 3;
    int x = 654;
    emsg = "";
    BOOST_CHECK(TF(r, eh)(m0, first, last));
    BOOST_CHECK_NO_THROW(x = get<int>(r));
    BOOST_CHECK_EQUAL(x, 1);
    BOOST_CHECK_EQUAL(emsg, "");
  }
  {
    Variant r;
    const char *str = "t02";
    const char *first = str, *last = first + 3;
    int x = 654;
    emsg = "";
    BOOST_CHECK(TF(r, eh)(m0, first, last));
    BOOST_CHECK_NO_THROW(x = get<int>(r));
    BOOST_CHECK_EQUAL(x, 2);
    BOOST_CHECK_EQUAL(emsg, "");
  }
  {
    Variant r;
    const char *str = "t03";
    const char *first = str, *last = first + 3;
    Map m;
    emsg = "";
    BOOST_CHECK(TF(r, eh)(m0, first, last));
    BOOST_CHECK_NO_THROW(m = get<Map>(r));
    BOOST_CHECK(m.find("t030") != m.end());
    BOOST_CHECK_EQUAL(emsg, "");
  }
  {
    Variant r;
    const char *str = "t03::t030";
    const char *first = str, *last = first + 9;
    int x = 654;
    emsg = "";
    BOOST_CHECK(TF(r, eh)(m0, first, last));
    BOOST_CHECK_NO_THROW(x = get<int>(r));
    BOOST_CHECK_EQUAL(x, 3);
    BOOST_CHECK_EQUAL(emsg, "");
  }
  //
  {
    Variant r;
    const char *str = "xxx";
    const char *first = str, *last = first + 3;
    emsg = "";
    BOOST_CHECK(!TF(r, eh)(m0, first, last));
    BOOST_CHECK_EQUAL(emsg, "xxx not found");
  }
  {
    Variant r;
    const char *str = "t03::xxx";
    const char *first = str, *last = first + 8;
    emsg = "";
    BOOST_CHECK(!TF(r, eh)(m0, first, last));
    BOOST_CHECK_EQUAL(emsg, "xxx is not a member of t03");
  }
  {
    Variant r;
    const char *str = "::t03";
    const char *first = str, *last = first + 5;
    emsg = "";
    BOOST_CHECK(!TF(r, eh)(m0, first, last));
    BOOST_CHECK_EQUAL(emsg, "malformed name ::t03");
  }
  {
    Variant r;
    const char *str = "t03::";
    const char *first = str, *last = first + 5;
    emsg = "";
    BOOST_CHECK(!TF(r, eh)(m0, first, last));
    BOOST_CHECK_EQUAL(emsg, "malformed name t03::");
  }
  {
    Variant r;
    const char *str = "::";
    const char *first = str, *last = first + 2;
    emsg = "";
    BOOST_CHECK(!TF(r, eh)(m0, first, last));
    BOOST_CHECK_EQUAL(emsg, "malformed name ::");
  }
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{
  BOOST_CHECK(true);
}
#endif
