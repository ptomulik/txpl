// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/eval_variant.hpp

/** // doc: txpl/vm/eval_variant.hpp {{{
 * \file txpl/vm/eval_variant.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_VM_EVAL_VARIANT_HPP
#define TXPL_VM_EVAL_VARIANT_HPP

#include <txpl/vm/eval.hpp>
#include <boost/variant/static_visitor.hpp>

namespace txpl { namespace vm {
/** // doc: eval_variant_visitor {{{
 * \todo Write documentation
 */ // }}}
template<typename Context, typename Value, typename Ehandler>
struct eval_variant_visitor
  : boost::static_visitor<bool>
{
  /** // doc: eval_variant_visitor() {{{
   * \brief Default constructor
   */ // }}}
  eval_variant_visitor(Context const& c, Value& r, Ehandler e)
    : _context(c), _result(r), _ehandler(e)
  { }
  /** // doc: operator() {{{
   * \todo Write documentation
   */ // }}}
  template<typename Node>
  bool operator()(Node const& node) const
  { return eval(node, _context, _result, _ehandler); }
private:
  Context const& _context;
  Value& _result;
  Ehandler _ehandler;
};
/** // doc: eval_variant() {{{
 * \todo Write documentation
 */ // }}}
template<typename Context, typename Value, typename Ehandler>
eval_variant_visitor<Context, Value, Ehandler>
eval_variant(Context const& c, Value& r, Ehandler f)
{ return eval_variant_visitor<Context, Value, Ehandler>(c, r, f); }
} } // end namespace txpl::vm

#endif /* TXPL_VM_EVAL_VARIANT_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
