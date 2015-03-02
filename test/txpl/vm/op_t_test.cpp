// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
// 
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
#define BOOST_TEST_MODULE test_txpl_vm_op_t

#include <txpl/test_config.hpp>
#include <boost/test/unit_test.hpp>

#ifndef TXPL_TEST_SKIP_VM_OP_T

#include <txpl/vm/op_t.hpp>
BOOST_AUTO_TEST_CASE(op_t__values)
{
  using namespace txpl::vm;
  BOOST_CHECK(op_t::plus_     == static_cast<op_t>('+'));
  BOOST_CHECK(op_t::minus_    == static_cast<op_t>('-'));
  BOOST_CHECK(op_t::mul_      == static_cast<op_t>('*'));
  BOOST_CHECK(op_t::div_      == static_cast<op_t>('/'));
  BOOST_CHECK(op_t::mod_      == static_cast<op_t>('%'));
  BOOST_CHECK(op_t::xor_      == static_cast<op_t>('^'));
  BOOST_CHECK(op_t::bitand_   == static_cast<op_t>('&'));
  BOOST_CHECK(op_t::bitor_    == static_cast<op_t>('|'));
  BOOST_CHECK(op_t::lt_       == static_cast<op_t>('<'));
  BOOST_CHECK(op_t::gt_       == static_cast<op_t>('>'));
  BOOST_CHECK(op_t::not_      == static_cast<op_t>('!'));
  BOOST_CHECK(op_t::neg_      == static_cast<op_t>('~'));
  BOOST_CHECK(op_t::comma_    == static_cast<op_t>(','));
  BOOST_CHECK(op_t::dot_      == static_cast<op_t>('.'));

  BOOST_CHECK(op_t::and_      == static_cast<op_t>(0x10100));
  BOOST_CHECK(op_t::or_       == static_cast<op_t>(0x10101));
  BOOST_CHECK(op_t::eq_       == static_cast<op_t>(0x10102));
  BOOST_CHECK(op_t::neq_      == static_cast<op_t>(0x10103));
  BOOST_CHECK(op_t::le_       == static_cast<op_t>(0x10104));
  BOOST_CHECK(op_t::ge_       == static_cast<op_t>(0x10105));
  BOOST_CHECK(op_t::lshift_   == static_cast<op_t>(0x10106));
  BOOST_CHECK(op_t::rshift_   == static_cast<op_t>(0x10107));
  BOOST_CHECK(op_t::match_    == static_cast<op_t>(0x10108));
  BOOST_CHECK(op_t::nmatch_   == static_cast<op_t>(0x10109));
}
BOOST_AUTO_TEST_CASE(op_t__eq__char)
{
  using namespace txpl::vm;
  BOOST_CHECK(op_t::lt_ == '<');
  BOOST_CHECK(op_t::gt_ == '>');
  BOOST_CHECK('<' == op_t::lt_);
  BOOST_CHECK('>' == op_t::gt_);
  BOOST_CHECK(!(op_t::gt_ == '<'));
  BOOST_CHECK(!('<' == op_t::gt_));
}
BOOST_AUTO_TEST_CASE(op_t__eq__wchar_t)
{
  using namespace txpl::vm;
  BOOST_CHECK(op_t::lt_ == L'<');
  BOOST_CHECK(op_t::gt_ == L'>');
  BOOST_CHECK(L'<' == op_t::lt_);
  BOOST_CHECK(L'>' == op_t::gt_);
  BOOST_CHECK(!(op_t::gt_ == L'<'));
  BOOST_CHECK(!(L'<' == op_t::gt_));
}
BOOST_AUTO_TEST_CASE(op_t__neq__char)
{
  using namespace txpl::vm;
  BOOST_CHECK(op_t::lt_ != '>');
  BOOST_CHECK(op_t::gt_ != '<');
  BOOST_CHECK('>' != op_t::lt_);
  BOOST_CHECK('<' != op_t::gt_);
  BOOST_CHECK(!(op_t::gt_ != '>'));
  BOOST_CHECK(!('>' != op_t::gt_));
}
BOOST_AUTO_TEST_CASE(op_t__neq__wchar_t)
{
  using namespace txpl::vm;
  BOOST_CHECK(op_t::lt_ != L'>');
  BOOST_CHECK(op_t::gt_ != L'<');
  BOOST_CHECK(L'>' != op_t::lt_);
  BOOST_CHECK(L'<' != op_t::gt_);
  BOOST_CHECK(!(op_t::gt_ != L'>'));
  BOOST_CHECK(!(L'>' != op_t::gt_));
}
BOOST_AUTO_TEST_CASE(op_t__lt__char)
{
  using namespace txpl::vm;
  BOOST_CHECK(op_t::lt_ < '>');
  BOOST_CHECK('<' < op_t::gt_);
  BOOST_CHECK(!(op_t::gt_ < '<'));
  BOOST_CHECK(!('>' < op_t::lt_));
}
BOOST_AUTO_TEST_CASE(op_t__lt__wchar_t)
{
  using namespace txpl::vm;
  BOOST_CHECK(op_t::lt_ < L'>');
  BOOST_CHECK(L'<' < op_t::gt_);
  BOOST_CHECK(!(op_t::gt_ < L'<'));
  BOOST_CHECK(!(L'>' < op_t::lt_));
}
BOOST_AUTO_TEST_CASE(op_t__gt__char)
{
  using namespace txpl::vm;
  BOOST_CHECK(op_t::gt_ > '<');
  BOOST_CHECK('>' > op_t::lt_);
  BOOST_CHECK(!(op_t::lt_ > '>'));
  BOOST_CHECK(!('<' > op_t::gt_));
}
BOOST_AUTO_TEST_CASE(op_t__gt__wchar_t)
{
  using namespace txpl::vm;
  BOOST_CHECK(op_t::gt_ > L'<');
  BOOST_CHECK(L'>' > op_t::lt_);
  BOOST_CHECK(!(op_t::lt_ > L'>'));
  BOOST_CHECK(!(L'<' > op_t::gt_));
}
BOOST_AUTO_TEST_CASE(op_t__le__char)
{
  using namespace txpl::vm;
  BOOST_CHECK(op_t::lt_ <= '>');
  BOOST_CHECK(op_t::lt_ <= '<');
  BOOST_CHECK('<' <= op_t::gt_);
  BOOST_CHECK('>' <= op_t::gt_);
  BOOST_CHECK(!(op_t::gt_ <= '<'));
  BOOST_CHECK(!('>' <= op_t::lt_));
}
BOOST_AUTO_TEST_CASE(op_t__le__wchar_t)
{
  using namespace txpl::vm;
  BOOST_CHECK(op_t::lt_ <= L'>');
  BOOST_CHECK(op_t::lt_ <= L'<');
  BOOST_CHECK(L'<' <= op_t::gt_);
  BOOST_CHECK(L'>' <= op_t::gt_);
  BOOST_CHECK(!(op_t::gt_ <= L'<'));
  BOOST_CHECK(!(L'>' <= op_t::lt_));
}
BOOST_AUTO_TEST_CASE(op_t__ge__char)
{
  using namespace txpl::vm;
  BOOST_CHECK(op_t::gt_ >= '<');
  BOOST_CHECK(op_t::gt_ >= '>');
  BOOST_CHECK('>' >= op_t::lt_);
  BOOST_CHECK('<' >= op_t::lt_);
  BOOST_CHECK(!(op_t::lt_ >= '>'));
  BOOST_CHECK(!('<' >= op_t::gt_));
}
BOOST_AUTO_TEST_CASE(op_t__ge__wchar_t)
{
  using namespace txpl::vm;
  BOOST_CHECK(op_t::gt_ >= L'<');
  BOOST_CHECK(op_t::gt_ >= L'>');
  BOOST_CHECK(L'>' >= op_t::lt_);
  BOOST_CHECK(L'<' >= op_t::lt_);
  BOOST_CHECK(!(op_t::lt_ >= L'>'));
  BOOST_CHECK(!(L'<' >= op_t::gt_));
}
#else
BOOST_AUTO_TEST_CASE(dummy)
{
  BOOST_CHECK(true);
}
#endif
