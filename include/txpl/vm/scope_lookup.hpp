// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/scope_lookup.hpp

/** // doc: txpl/vm/scope_lookup.hpp {{{
 * \file txpl/vm/scope_lookup.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_VM_SCOPE_LOOKUP_HPP
#define TXPL_VM_SCOPE_LOOKUP_HPP

#include <txpl/vm/scope.hpp>
#include <txpl/vm/scope_find.hpp>
#include <txpl/util/fake_functor.hpp>
#include <string>

namespace txpl { namespace vm {
/** // doc: scope_lookup() {{{
 * \todo Write documentation
 */ // }}}
template<typename Symbol, typename Ehandler>
bool scope_lookup(scope<Symbol> const& s, std::string const& start,
                  std::string const& name, Symbol& result, Ehandler f)
{
  if(!start.empty())
    {
      Symbol sym;
      if(!scope_find(s, start, sym, f))
        return false;

      scope<Symbol> const* sp = yaul::get<scope<Symbol> >(&sym);
      if(!sp)
        {
          f(scope_op_detail::strerr_not_a_map(start));
          return false;
        }
    }

  if(name.find(scope_op_detail::separator()) == 0ul)
    {
      // absolute name lookup
      return scope_find(s, name.begin()+2, name.end(), result, f);
    }
  else
    {
      // relative name lookup
      std::string ns(start.begin(), start.end());
      while(!ns.empty())
        {
          std::string fqdn(ns + scope_op_detail::separator() + name);
          if(scope_find(s, fqdn, result, util::fake_functor<void>()))
            return true;
          size_t pos = ns.rfind(scope_op_detail::separator());
          if(pos != std::string::npos)
            ns = ns.substr(0, pos);
          else
            ns.clear();
        }
      return scope_find(s, name, result, f);
    }
}
/** // doc: scope_lookup() {{{
 * \todo Write documentation
 */ // }}}
template<typename Symbol>
bool scope_lookup(scope<Symbol> const& s, std::string const& start,
                  std::string const& name, Symbol& result)
{ return scope_lookup(s, start, name, result, util::fake_functor<void>()); }
} } // end txpl::vm

#endif /* TXPL_VM_SCOPE_LOOKUP_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
