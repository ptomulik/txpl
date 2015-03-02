// Copyright (C) 2015, Pawel Tomulik <ptomulik@meil.pw.edu.pl>
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// txpl/lexer/bind_error_handler.hpp

/** // doc: txpl/lexer/bind_error_handler.hpp {{{
 * \file txpl/lexer/bind_error_handler.hpp
 * \todo Write documentation
 */ // }}}
#ifndef TXPL_LEXER_BIND_ERROR_HANDLER_HPP
#define TXPL_LEXER_BIND_ERROR_HANDLER_HPP

namespace txpl { namespace lexer {
/** // doc: bound_error_handler {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename String>
struct bound_error_handler
{
  typedef Iterator iterator_type;
  typedef String string_type;
  /** // doc: bound_error_handler {{{
   * \todo Write documentation
   */ // }}}
  constexpr bound_error_handler(Iterator& first, Iterator& last, String& msg) noexcept
    : first_(first), last_(last), msg_(msg)
  { }
  /** // doc: operator() {{{
   * \todo Write documentation
   */ // }}}
  void operator()(Iterator const& first, Iterator const& last, String const& msg) const
  {
    this->first_ = first;
    this->last_ = last;
    this->msg_ = msg;
  }
private:
  Iterator&   first_;
  Iterator&   last_;
  String&    msg_;
};
/** // doc: bind_error_handler {{{
 * \todo Write documentation
 */ // }}}
template<typename Iterator, typename String>
bound_error_handler<Iterator, String>
bind_error_handler(Iterator& first, Iterator& last, String& msg)
{ 
  return bound_error_handler<Iterator, String>(first, last, msg);
}
} } // end namespace txpl::lexer

#endif /* TXPL_LEXER_BIND_ERROR_HANDLER_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
