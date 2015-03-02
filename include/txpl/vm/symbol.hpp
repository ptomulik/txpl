// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/symbol.hpp

/** // doc: txpl/vm/symbol.hpp {{{
 * \file txpl/vm/symbol.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_VM_SYMBOL_HPP
#define TXPL_VM_SYMBOL_HPP

#include <txpl/vm/scope_fwd.hpp>
#include <txpl/vm/value.hpp>
#include <boost/variant/recursive_variant.hpp>
#include <boost/blank.hpp>
#include <map>

namespace txpl { namespace vm {
/** // doc: symbol {{{
 * \todo Write documentation
 */ // }}}
template<typename Value = value<> >
using symbol = typename boost::make_recursive_variant<
    boost::blank
  , Value
  , scope_fwd<boost::recursive_variant_>
>::type;
} } // end namespace txpl::vm

#endif /* TXPL_VM_SYMBOL_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
