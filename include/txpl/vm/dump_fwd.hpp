// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/dump_fwd.hpp

/** // doc: txpl/vm/dump_fwd.hpp {{{
 * \file txpl/vm/dump_fwd.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_VM_DUMP_FWD_HPP
#define TXPL_VM_DUMP_FWD_HPP

namespace txpl { namespace vm { 
/** // doc: dump() {{{
 * \ingroup VmGroup
 * \todo Write documentation
 */ // }}}
template<typename Ostream, typename Value>
Ostream& dump(Ostream& os, Value const& x);
} } // end namespace txpl::vm

#endif /* TXPL_VM_DUMP_FWD_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
