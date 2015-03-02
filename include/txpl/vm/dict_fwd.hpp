// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/dict_fwd.hpp

/** // doc: txpl/vm/dict_fwd.hpp {{{
 * \file txpl/vm/dict_fwd.hpp
 * \brief Forward declaration of \ref txpl::vm::dict "vm::dict<>"
 */ // }}}
#ifndef TXPL_VM_DICT_FWD_HPP
#define TXPL_VM_DICT_FWD_HPP

#include <map>
#include <string>

namespace txpl { namespace vm {
/** // doc: dict {{{
 * \brief Forward declaration of \ref txpl::vm::dict "vm::dict<>"
 */ // }}}
template<typename Value>
using dict_fwd = std::map<std::string, Value>;
} } // end namespace txpl::vm

#endif /* TXPL_VM_DICT_FWD_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
