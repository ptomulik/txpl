// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/dumper.hpp

/** // doc: txpl/vm/dumper.hpp {{{
 * \file txpl/vm/dumper.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_VM_DUMPER_HPP
#define TXPL_VM_DUMPER_HPP

#include <txpl/vm/dump_fwd.hpp>
#include <txpl/vm/value.hpp>
#include <txpl/vm/value_traits.hpp>
#include <txpl/vm/array.hpp>
#include <txpl/vm/dict.hpp>
#include <yaul/variant/static_visitor.hpp>
#include <yaul/variant/apply_visitor.hpp>
#include <regex>
#include <string>
#include <ostream>

namespace txpl { namespace vm { 
/** // doc: dumper_visitor {{{
 * \ingroup VmGroup
 * \todo Write documentation
 */ // }}}
template<typename Value, typename Ostream>
struct dumper_visitor;
/** // doc: dumper_visitor {{{
 * \ingroup VmGroup
 * \todo Write documentation
 */ // }}}
template<typename Value, typename CharT, typename Traits>
struct dumper_visitor<Value, std::basic_ostream<CharT, Traits> >
  : yaul::static_visitor<std::basic_ostream<CharT, Traits>&>
{
  /** // doc: ostream_type {{{
   * \todo Write documentation
   */ // }}}
  typedef std::basic_ostream<CharT, Traits> ostream_type;
  /** // doc: value_type {{{
   * \todo Write documentation
   */ // }}}
  typedef Value value_type;
  /** // doc: blank_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename value_traits<Value>::blank_type blank_type;
  /** // doc: char_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename value_traits<Value>::char_type char_type;
  /** // doc: int_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename value_traits<Value>::int_type int_type;
  /** // doc: bool_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename value_traits<Value>::bool_type bool_type;
  /** // doc: real_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename value_traits<Value>::real_type real_type;
  /** // doc: string_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename value_traits<Value>::string_type string_type;
  /** // doc: regex_type {{{
   * \todo Write documentation
   */ // }}}
  typedef typename value_traits<Value>::regex_type regex_type;
  /** // doc: array_type {{{
   * \todo Write documentation
   */ // }}}
  typedef array<Value> array_type;
  /** // doc: dict_type {{{
   * \todo Write documentation
   */ // }}}
  typedef dict<Value> dict_type;
  /** // doc: dumper_visitor() {{{
   * \todo Write documentation
   */ // }}}
  dumper_visitor(ostream_type& os) :_os(os) { }
  /** // doc: operator() {{{
   * \todo Write documentation
   */ // }}}
  ostream_type& operator()(blank_type) const
  { return _os; }
  /** // doc: operator() {{{
   * \todo Write documentation
   */ // }}}
  ostream_type& operator()(char_type x) const
  {
    // FIXME: implement escape sequences
    _os << CharT{'\''} << x << CharT{'\''};
    return _os;
  }
  /** // doc: operator() {{{
   * \todo Write documentation
   */ // }}}
  ostream_type& operator()(int_type x) const
  {
    _os << x;
    return _os;
  }
  /** // doc: operator() {{{
   * \todo Write documentation
   */ // }}}
  ostream_type& operator()(bool_type x) const
  {
    typedef std::basic_string<CharT,Traits> S;
    const char *f = "false";
    const char *t = "true";
    _os << (x ? S(t, t+4) : S(f, f+5));
    return _os;
  }
  /** // doc: operator() {{{
   * \todo Write documentation
   */ // }}}
  ostream_type& operator()(real_type x) const
  {
    _os << x;
    return _os;
  }
  /** // doc: operator() {{{
   * \todo Write documentation
   */ // }}}
  ostream_type& operator()(string_type x) const
  {
    // FIXME: implement escape sequences
    _os << CharT{'\"'} << x << CharT{'\"'};
    return _os;
  }
  /** // doc: operator() {{{
   * \todo Write documentation
   */ // }}}
  ostream_type& operator()(regex_type x) const
  {
    if(x.flags() & std::regex_constants::ECMAScript) _os << CharT{'r'};
    else if(x.flags() & std::regex_constants::basic) _os << CharT{'b'};
    else if(x.flags() & std::regex_constants::extended) _os << CharT{'x'};
    else if(x.flags() & std::regex_constants::awk) _os << CharT{'a'};
    else if(x.flags() & std::regex_constants::grep) _os << CharT{'g'};
    else _os << CharT{'e'};

    _os << CharT{'\"'} << "<not-implemented>" << CharT{'\"'};

    if(x.flags() & std::regex_constants::icase) _os << CharT{'i'};
    if(x.flags() & std::regex_constants::collate) _os << CharT{'c'};
    return _os;
  }
  /** // doc: operator() {{{
   * \todo Write documentation
   */ // }}}
  ostream_type& operator()(array_type x) const
  {
    _os << CharT{'['};
    if(x.size() != 0)
      { 
        _os << CharT{' '};
        auto it = x.begin();
        dump(_os, *it);
        for(++it; it != x.end(); ++it)
          {
            _os << CharT{','} << CharT{' '};
            dump(_os, *it);
          }
        _os << CharT{' '};
      }
    _os << CharT{']'};
    return _os;
  }
  /** // doc: operator() {{{
   * \todo Write documentation
   */ // }}}
  ostream_type& operator()(dict_type x) const
  {
    _os << CharT{'{'};
    if(x.size() != 0)
      { 
        _os << CharT{' '};
        auto it = x.begin();
        this->operator()(it->first);
        _os << CharT{' '} << CharT{':'} << CharT{' '};
        dump(_os, it->second);
        for(++it; it != x.end(); ++it)
          {
            _os << CharT{','} << CharT{' '};
            this->operator()(it->first);
            _os << CharT{' '} << CharT{':'} << CharT{' '};
            dump(_os, it->second);
          }
        _os << CharT{' '};
      }
    _os << CharT{'}'};
    return _os;
  }
private:
  ostream_type& _os;
};
/** // doc: dumper() {{{
 * \todo Write documentation
 */ // }}}
template<typename Value, typename Ostream>
dumper_visitor<Value, Ostream>
dumper(Ostream& os)
{ return dumper_visitor<Value, Ostream>(os); }
} } // end namespace txpl::vm

#include <txpl/vm/dump.hpp>

#endif /* TXPL_VM_DUMPER_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
