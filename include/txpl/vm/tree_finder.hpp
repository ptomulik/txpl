// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/vm/tree_find.hpp

/** // doc: txpl/vm/tree_find.hpp {{{
 * \file txpl/vm/tree_find.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_VM_TREE_FINDER_HPP
#define TXPL_VM_TREE_FINDER_HPP

#include <boost/algorithm/string/find.hpp>
#include <boost/range/iterator_range_core.hpp>
#include <yaul/variant/get.hpp>
#include <string>

namespace txpl { namespace vm {
/** // doc: tree_finder {{{
 * \todo Write documentation
 */ // }}}
template<typename Detail, typename Variant, typename Ehandler>
struct tree_finder
{
  /** // doc: result_type {{{
   * \todo Write documentation
   */ // }}}
  typedef bool result_type;
  /** // doc: detail_type {{{
   * \todo Write documentation
   */ // }}}
  typedef Detail detail_type;
  /** // doc: variant_type {{{
   * \todo Write documentation
   */ // }}}
  typedef Variant variant_type;
  /** // doc: error_handler_type {{{
   * \todo Write documentation
   */ // }}}
  typedef Ehandler error_handler_type;
  /** // doc: tree_finder() {{{
   * \todo Write documentation
   */ // }}}
  tree_finder(Variant& result, Ehandler eh)
    : _result(result), _ehandler(eh)
  { }
  /** // doc: operator(){{{
   * \todo Write documentation
   */ // }}}
  template<typename Map, typename Iterator>
  bool operator()(Map const& map,
                  Iterator const& head_first,
                  Iterator const& head_last,
                  Iterator const& tail_first,
                  Iterator const& tail_last) const
  {
    return _find(map, boost::make_iterator_range(head_first, head_last),
                      boost::make_iterator_range(tail_first, tail_last));
  }
  /** // doc: operator(){{{
   * \todo Write documentation
   */ // }}}
  template<typename Map, typename Iterator>
  bool operator()(Map const& map, Iterator const& first, Iterator const& last) const
  {
    return _find(map, boost::make_iterator_range(first, first),
                      boost::make_iterator_range(first, last));
  }
private:
  template<typename Map, typename Range>
  bool _find(Map const& map, Range const& head, Range const& tail) const
  {
    using namespace boost::algorithm;
    typedef typename Map::key_type key_type;

    if(tail.begin() == tail.end())
      {
        _ehandler(detail_type::strerr_malformed_name(tail));
        return false;
      }

    Range sep = find(tail, first_finder(detail_type::separator()));
    if((sep.begin() == tail.begin()) ||
       (sep.begin() != tail.end() && sep.end() == tail.end()))
      {
        _ehandler(detail_type::strerr_malformed_name(tail));
        return false;
      }
   
    auto it = map.find(key_type(tail.begin(), sep.begin()));
    if(it == map.end())
      {
        _ehandler(detail_type::strerr_not_found(head, Range(tail.begin(), sep.begin())));
        return false;
      }

    Variant const& variant = it->second;
    if(sep.begin() == tail.end())
      {
        _result = variant;
        return true;
      }

    Range newhead = Range(head.begin(), sep.begin());
    Map const* submap = yaul::get<Map const>(&variant);
    if(!submap)
      {
        _ehandler(detail_type::strerr_not_a_map(newhead));
        return false;
      }
    Range newtail = Range(sep.end(), tail.end());
    return _find(*submap, newhead, newtail);
  }
private:
  Variant&  _result;
  Ehandler  _ehandler;
};
} } // end namespace txpl::vm

#endif /* TXPL_VM_TREE_FINDER_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
