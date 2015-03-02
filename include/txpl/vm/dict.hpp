// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/dict.hpp

/** // doc: txpl/vm/dict.hpp {{{
 * \file txpl/vm/dict.hpp
 * \brief Defines \ref txpl::vm::dict "vm::dict<>"
 */ // }}}
#ifndef TXPL_VM_DICT_HPP
#define TXPL_VM_DICT_HPP

#include <txpl/vm/value.hpp>
#include <txpl/vm/dict_fwd.hpp>

namespace txpl { namespace vm {
/** // doc: dict {{{
 * \brief Dictionary
 *
 * \tparam Value mapped type
 *
 * This type implements a string-to-value map called a dict in our terminology.
 * At C++ side dict is identical with <tt>std::map<std::string, Value></tt>.
 */ // }}}
template<typename Value = value<> >
using dict = dict_fwd<Value>;
} } // end namespace txpl::vm

#endif /* TXPL_VM_DICT_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
