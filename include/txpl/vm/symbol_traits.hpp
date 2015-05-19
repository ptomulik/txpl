// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/symbol_traits.hpp

/** // doc: txpl/vm/symbol_traits.hpp {{{
 * \file txpl/vm/symbol_traits.hpp
 * \brief Defines the \ref txpl::vm::symbol_traits "vm::symbol_traits<>"
 */ // }}}
#ifndef TXPL_VM_SYMBOL_TRAITS_HPP
#define TXPL_VM_SYMBOL_TRAITS_HPP

#include <boost/mpl/at.hpp>
#include <yaul/tml/enable_if_type.hpp>

namespace txpl { namespace vm {
/** \ingroup VmGroup
 * @{ */
/** // doc: symbol_traits {{{
 * \todo Write documentation
 */ // }}}
template<typename Symbol, typename Enable = void> struct symbol_traits;
/** // doc: symbol_traits {{{
 * \todo Write documentation
 */ // }}}
template<typename Symbol>
struct symbol_traits<
    Symbol
  , typename yaul::tml::enable_if_type<
      typename boost::mpl::at_c<typename Symbol::types, 2>::type
    >::type
  >
{
  /** // doc: blank_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename boost::mpl::at_c<typename Symbol::types, 0>::type blank_type;
  /** // doc: value_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename boost::mpl::at_c<typename Symbol::types, 1>::type value_type;
  /** // doc: scope_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename boost::mpl::at_c<typename Symbol::types, 2>::type scope_type;
};
/** @} */
} } // end namespace txpl::vm

#endif /* TXPL_VM_SYMBOL_TRAITS_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
