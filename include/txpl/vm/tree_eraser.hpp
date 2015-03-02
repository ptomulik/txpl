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
#ifndef TXPL_VM_TREE_ERASER_HPP
#define TXPL_VM_TREE_ERASER_HPP

#include <boost/algorithm/string/find.hpp>
#include <boost/range/iterator_range_core.hpp>
#include <boost/variant/get.hpp>
#include <string>

namespace txpl { namespace vm {
/** // doc: tree_eraser {{{
 * \todo Write documentation
 */ // }}}
template<typename Detail, typename Ehandler>
struct tree_eraser
{
  /** // doc: result_type {{{
   * \todo Write documentation
   */ // }}}
  typedef bool result_type;
  /** // doc: detail_type {{{
   * \todo Write documentation
   */ // }}}
  typedef Detail detail_type;
  /** // doc: error_handler_type {{{
   * \todo Write documentation
   */ // }}}
  typedef Ehandler error_handler_type;
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
    return _erase(map, boost::make_iterator_range(head_first, head_last),
                       boost::make_iterator_range(tail_first, tail_last));
  }
  /** // doc: operator(){{{
   * \todo Write documentation
   */ // }}}
  template<typename Map, typename Iterator>
  bool operator()(Map& map, Iterator const& first, Iterator const& last) const
  {
    return _erase(map, boost::make_iterator_range(first, first),
                       boost::make_iterator_range(first, last));
  }
  /** // doc: tree_eraser() {{{
   * \todo Write documentation
   */ // }}}
  tree_eraser(Ehandler ehandler)
    : _ehandler(ehandler)
  { }
private:
  template<typename Map, typename Range>
  bool _erase(Map& map, Range const& head, Range const& tail) const
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

    if(sep.begin() == tail.end())
      {
        // Erase terminal symbol 
        return static_cast<bool>(map.erase(key_type(tail.begin(), tail.end())));
      }
    else
      {
        // Recursion (if it's map)
        Range newhead = Range(head.begin(), sep.begin());
        Range newtail = Range(sep.end(), tail.end());
        Map* mp = boost::get<Map>(&it->second);
        if(!mp)
          {
            _ehandler(detail_type::strerr_not_a_map(newhead));
            return false;
          }
        return _erase(*mp, newhead, newtail);
      }
  }
protected:
  tree_eraser();
private:
  Ehandler _ehandler;
};
} } // end namespace txpl::vm

#endif /* TXPL_VM_TREE_ERASER_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
