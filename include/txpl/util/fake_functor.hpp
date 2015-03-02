// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/util/fake_functor.hpp

/** // doc: txpl/util/fake_functor.hpp {{{
 * \file txpl/util/fake_functor.hpp
 * \brief Implements the \ref txpl::util::fake_functor "util::fake_functor<>"
 */ // }}}
#ifndef TXPL_UTIL_FAKE_FUNCTOR_HPP
#define TXPL_UTIL_FAKE_FUNCTOR_HPP

namespace txpl { namespace util {
/** // doc: fake_functor {{{
 * \brief Fake functor
 *
 * \tparam Result type of the value returned by functor
 *
 * This is a callable object which accepts any number of arguments and does
 * nothing.
 */ // }}}
template<typename Result = void>
struct fake_functor
{
  /** // doc: fake_functor {{{
   * \brief Default constructor
   */ // }}}
  fake_functor() : _result() { }
  /** // doc: fake_functor {{{
   * \brief Constructor
   *
   * \param r Value to be returned by the functor
   */ // }}}
  fake_functor(Result const& r) :_result(r) { }
  /** // doc: result_type {{{
   * \brief Type of the value being returned by functor
   *
   * Same as the \e Result template parameter
   */ // }}}
  typedef Result result_type;
  /** // doc: operator() {{{
   * \brief Function call operator
   * \returns a value provided as the \e r argument to the
   *          \ref fake_functor(Result const&) "constructor"
   *
   * Apart from returning a predefined value, the function merely does nothing.
   */ // }}}
  template<typename... T>
  result_type operator()(T...) const noexcept 
  { return _result; }
private:
  result_type _result;
};
/** // doc: fake_functor {{{
 * \brief Specialization of the \ref txpl::vm::fake_functor for void return type
 */ // }}}
template<>
struct fake_functor<void>
{
  /** // doc: result_type {{{
   * \brief Return type, void
   */ // }}}
  typedef void result_type;
  /** // doc: operator() {{{
   * \brief Function-call operator, does nothing
   */ // }}}
  template<typename... T>
  void operator()(T...) const noexcept { }
};

} } // end namespace txpl::util

#endif /* TXPL_UTIL_FAKE_FUNCTOR_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
