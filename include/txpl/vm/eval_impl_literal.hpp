// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/eval_impl_literal.hpp.hpp

/** // doc: txpl/vm/eval_impl_literal.hpp.hpp {{{
 * \file txpl/vm/eval_impl_literal.hpp.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_VM_EVAL_IMPL_LITERAL_HPP
#define TXPL_VM_EVAL_IMPL_LITERAL_HPP

#include <txpl/ast/nodes.hpp>

namespace txpl { namespace vm {
/** // doc: eval_impl<ast::literal> {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename BasicTypes>
struct eval_impl<ast::literal<Iterator, BasicTypes> >
{
  /** // doc: node_type {{{
   * \todo Write documentation
   */ // }}}
  typedef ast::literal<Iterator, BasicTypes> node_type;
  /** // doc: char_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename BasicTypes::char_type char_type;
  /** // doc: int_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename BasicTypes::int_type int_type;
  /** // doc: bool_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename BasicTypes::bool_type bool_type;
  /** // doc: real_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename BasicTypes::real_type real_type;
  /** // doc: string_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename BasicTypes::string_type string_type;
  /** // doc: regex_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename BasicTypes::regex_type regex_type;

  /** // doc: apply() {{{
   * \todo Write documentation
   */ // }}}
  template<typename Context, typename Result, typename Ehandler>
  static bool
  apply(node_type const& node, Context const&, Result& res, Ehandler)
  {
    res = node.value;
    return true;
  }
};
} } // end namespace txpl::vm

#endif /* TXPL_VM_EVAL_IMPL_LITERAL_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
