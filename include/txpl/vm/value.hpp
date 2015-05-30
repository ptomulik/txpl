// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/value.hpp

/** // doc: txpl/vm/value.hpp {{{
 * \file txpl/vm/value.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_VM_VALUE_HPP
#define TXPL_VM_VALUE_HPP

#include <txpl/vm/basic_types.hpp>
#include <txpl/vm/array_fwd.hpp>
#include <txpl/vm/dict_fwd.hpp>
#include <yaul/variant/recursive_variant.hpp>

namespace txpl { namespace vm {
/** // doc: value {{{
 * \todo Write documenation
 */ // }}}
template<typename BasicTypes = basic_types<> >
using value = typename yaul::make_recursive_variant<
      typename BasicTypes::blank_type
    , typename BasicTypes::char_type
    , typename BasicTypes::int_type
    , typename BasicTypes::bool_type
    , typename BasicTypes::real_type
    , typename BasicTypes::string_type
    , typename BasicTypes::regex_type
    , array_fwd<yaul::recursive_variant_>
    , dict_fwd<yaul::recursive_variant_>
>::type;
} } // end namespace txpl::vm

#endif /* TXPL_VM_VALUE_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
