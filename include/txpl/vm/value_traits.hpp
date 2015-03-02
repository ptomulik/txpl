// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/value_traits.hpp

/** // doc: txpl/vm/value_traits.hpp {{{
 * \file txpl/vm/value_traits.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_VM_VALUE_TRAITS_HPP
#define TXPL_VM_VALUE_TRAITS_HPP

#include <boost/mpl/at.hpp>
#include <tml/enable_if_type.hpp>

namespace txpl { namespace vm {
/** // doc: value_traits {{{
 * \todo Write documentation
 */ // }}}
template<typename Value, typename Enable = void> struct value_traits;
/** // doc: value_traits {{{
 * \todo Write documentation
 */ // }}}
template<typename Value>
struct value_traits<
    Value
  , typename tml::enable_if_type<
      typename boost::mpl::at_c<typename Value::types, 6>::type
    >::type
  >
{
  /** // doc: blank_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename boost::mpl::at_c<typename Value::types, 0>::type blank_type;
  /** // doc: char_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename boost::mpl::at_c<typename Value::types, 1>::type char_type;
  /** // doc: int_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename boost::mpl::at_c<typename Value::types, 2>::type int_type;
  /** // doc: bool_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename boost::mpl::at_c<typename Value::types, 3>::type bool_type;
  /** // doc: real_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename boost::mpl::at_c<typename Value::types, 4>::type real_type;
  /** // doc: string_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename boost::mpl::at_c<typename Value::types, 5>::type string_type;
  /** // doc: regex_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename boost::mpl::at_c<typename Value::types, 6>::type regex_type;
};
} } // end namespace txpl::vm

#endif /* TXPL_VM_VALUE_TRAITS_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
