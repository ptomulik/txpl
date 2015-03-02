// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/util/fake_functor.hpp

/** // doc: txpl/util/fake_functor.hpp {{{
 * \file txpl/util/fake_functor.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_UTIL_FAKE_FUNCTOR_HPP
#define TXPL_UTIL_FAKE_FUNCTOR_HPP

namespace txpl { namespace util {
/** // doc: fake_functor {{{
 * \todo Write documentation
 */ // }}}
template<typename Result = void>
struct fake_functor
{
  /** // doc: fake_functor {{{
   * \todo Write documentation
   */ // }}}
  fake_functor() : _result() { }
  /** // doc: fake_functor {{{
   * \todo Write documentation
   */ // }}}
  fake_functor(Result const& r) :_result(r) { }
  /** // doc: result_type {{{
   * \todo Write documentation
   */ // }}}
  typedef Result result_type;
  /** // doc: operator() {{{
   * \todo Write documentation
   */ // }}}
  template<typename... T>
  result_type operator()(T...) const noexcept 
  { return _result; }
private:
  result_type _result;
};
/** // doc: fake_functor {{{
 * \todo Write documentation
 */ // }}}
template<>
struct fake_functor<void>
{
  /** // doc: result_type {{{
   * \todo Write documentation
   */ // }}}
  typedef void result_type;
  /** // doc: operator() {{{
   * \todo Write documentation
   */ // }}}
  template<typename... T>
  void operator()(T...) const noexcept { }
};

} } // end namespace txpl::util

#endif /* TXPL_UTIL_FAKE_FUNCTOR_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
