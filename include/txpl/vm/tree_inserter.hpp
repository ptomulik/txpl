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
#ifndef TXPL_VM_TREE_INSERTER_HPP
#define TXPL_VM_TREE_INSERTER_HPP

#include <boost/algorithm/string/find.hpp>
#include <boost/range/iterator_range_core.hpp>
#include <yaul/variant/get.hpp>
#include <string>
#include <utility>

namespace txpl { namespace vm {
/** // doc: tree_inserter {{{
 * \todo Write documentation
 */ // }}}
template<typename Detail, typename Variant, typename Ehandler>
struct tree_inserter
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
  /** // doc: tree_inserter() {{{
   * \todo Write documentation
   */ // }}}
  tree_inserter(Variant const& value, Ehandler eh)
    : _value(value), _ehandler(eh)
  { }
  /** // doc: operator(){{{
   * \todo Write documentation
   */ // }}}
  template<typename Map, typename Iterator>
  bool operator()(Map& map,
                  Iterator const& head_first,
                  Iterator const& head_last,
                  Iterator const& tail_first,
                  Iterator const& tail_last) const
  {
    return _insert(map, boost::make_iterator_range(head_first, head_last),
                        boost::make_iterator_range(tail_first, tail_last));
  }
  /** // doc: operator(){{{
   * \todo Write documentation
   */ // }}}
  template<typename Map, typename Iterator>
  bool operator()(Map& map, Iterator const& first, Iterator const& last) const
  {
    return _insert(map, boost::make_iterator_range(first, first),
                        boost::make_iterator_range(first, last));
  }
private:
  template<typename Map, typename Range>
  bool _insert(Map& map, Range const& head, Range const& tail) const
  {
    using namespace boost::algorithm;
    typedef typename Map::key_type key_type;
    typedef typename Map::value_type pair_type;

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

    if(sep.begin() == tail.end())
      {
        // Insert terminal symbol (or replace with a terminal symbol)
        map[key_type(tail.begin(), tail.end())] = _value;
        return true;
      }
    else
      {
        // Insert non-terminal symbol
        Range newhead = Range(head.begin(), sep.begin());
        Range newtail = Range(sep.end(), tail.end());
        auto it = map.find(key_type(tail.begin(), sep.begin()));
        if(it == map.end())
          {
            Map m;
            if(!_insert(m, newhead, newtail)) return false;
            map.insert(pair_type(key_type(tail.begin(), sep.begin()), std::move(m)));
            return true;
          }
        else
          {
            Map* mp = yaul::get<Map>(&it->second);
            if(mp)
              {
                // Use existing map found in it->second
                return _insert(*mp, newhead, newtail);
              }
            else
              {
                // Overwrite not-a-map entry found in it->second with a newly
                // created map
                Map m;
                if(!_insert(m, newhead, newtail)) return false;
                it->second = std::move(m);
                return true;
              }
          }
      }
  }
private:
  Variant const& _value;
  Ehandler       _ehandler;
};
} } // end namespace txpl::vm

#endif /* TXPL_VM_TREE_INSERTER_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
