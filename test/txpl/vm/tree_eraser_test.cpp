// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_vm_tree_eraser

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_VM_TREE_ERASER

#include <txpl/vm/tree_eraser.hpp>
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

BOOST_AUTO_TEST_CASE(test_sep_eraser_typedefs)
{
  using std::is_same;
  using namespace txpl::vm;
  BOOST_CHECK((is_same<tree_eraser<Detail,Ehandler>::result_type, bool>::value));
  BOOST_CHECK((is_same<tree_eraser<Detail,Ehandler>::detail_type, Detail>::value));
  BOOST_CHECK((is_same<tree_eraser<Detail,Ehandler>::error_handler_type, Ehandler>::value));
}
BOOST_AUTO_TEST_CASE(test_tree_eraser__initially_empty)
{
  using namespace txpl::vm;
  using yaul::get;

  typedef tree_eraser<Detail, Ehandler> TE;

  std::string emsg;
  Ehandler eh(emsg);

  {
    Map m;
    const char *str = "i10";
    const char *first = str, *last = first + 3;
    emsg = "";
    BOOST_CHECK(!TE(eh)(m, first, last));
    BOOST_CHECK_EQUAL(emsg, "i10 not found");
  }
  //
  {
    Map m;
    const char *str = "";
    const char *first = str, *last = first;
    emsg = "";
    BOOST_CHECK(!TE(eh)(m, first, last));
    BOOST_CHECK_EQUAL(emsg, "empty names not allowed");
  }
  {
    Map m;
    const char *str = "::xyz";
    const char *first = str, *last = first+5;
    emsg = "";
    BOOST_CHECK(!TE(eh)(m, first, last));
    BOOST_CHECK_EQUAL(emsg, "malformed name ::xyz");
  }
  {
    Map m;
    const char *str = "xyz::";
    const char *first = str, *last = first+5;
    emsg = "";
    BOOST_CHECK(!TE(eh)(m, first, last));
    BOOST_CHECK_EQUAL(emsg, "malformed name xyz::");
  }
}

BOOST_AUTO_TEST_CASE(test_tree_eraser__initially_nonempty)
{
  using namespace txpl::vm;
  using yaul::get;

  typedef tree_eraser<Detail, Ehandler> TE;

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

    const char *str = "m1::m2::i21";
    const char *first = str, *last = first + 11;
    int x = 654;
    emsg = "";
    BOOST_CHECK(TE(eh)(m, first, last));
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK_NO_THROW(mx = get<Map>(m.at("m1")));
    BOOST_CHECK_NO_THROW(mx = get<Map>(mx.at("m2")));
    BOOST_CHECK(mx.empty()); 
    // Check if we didn't destroy other entries
    // i1
    x = 654;
    BOOST_CHECK_NO_THROW(x = get<int>(m.at("i1")));
    BOOST_CHECK_EQUAL(x, 1);
    // m1::i11
    x = 654;
    BOOST_CHECK_NO_THROW(mx = get<Map>(m.at("m1")));
    BOOST_CHECK_NO_THROW(x = get<int>(mx.at("i11")));
    BOOST_CHECK_EQUAL(x, 11);
    // Erasing again same entry fails..
    BOOST_CHECK(!TE(eh)(m, first, last));
    BOOST_CHECK_EQUAL(emsg, "i21 is not a member of m1::m2");
  }
  {
    Map mx;
    const char *str = "m1::i11";
    const char *first = str, *last = str + 7;
    emsg = "";
    BOOST_CHECK(TE(eh)(m, first, last));
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK_NO_THROW(mx = get<Map>(m.at("m1")));
    BOOST_CHECK_THROW(mx.at("i11"), std::out_of_range);
    // Erasing again same entry fails..
    BOOST_CHECK(!TE(eh)(m, first, last));
    BOOST_CHECK_EQUAL(emsg, "i11 is not a member of m1");
  }
  {
    const char *str = "i1";
    const char *first = str, *last = str + 2;
    emsg = "";
    BOOST_CHECK(TE(eh)(m, first, last));
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK_THROW(m.at("i1"), std::out_of_range);
    // Erasing again same entry fails..
    BOOST_CHECK(!TE(eh)(m, first, last));
    BOOST_CHECK_EQUAL(emsg, "i1 not found");
  }
  {
    Map mx;
    const char *str = "m1::m2";
    const char *first = str, *last = str + 6;
    emsg = "";
    BOOST_CHECK(TE(eh)(m, first, last));
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK_NO_THROW(mx = get<Map>(m["m1"]));
    BOOST_CHECK_THROW(mx.at("m2"), std::out_of_range);
    // Erasing again same entry fails..
    BOOST_CHECK(!TE(eh)(m, first, last));
    BOOST_CHECK_EQUAL(emsg, "m2 is not a member of m1");
  }
  {
    const char *str = "m1";
    const char *first = str, *last = first + 2;
    emsg = "";
    BOOST_CHECK(TE(eh)(m, first, last));
    BOOST_CHECK_EQUAL(emsg, "");
    BOOST_CHECK(m.empty());
    BOOST_CHECK(!TE(eh)(m, first, last));
    BOOST_CHECK_EQUAL(emsg, "m1 not found");
  }
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{
  BOOST_CHECK(true);
}
#endif
