Value {#VmValueConcept}
=====

Description
-----------

\ref VmValueConcept object is a recursive variant object able to store

- one of \ref BasicTypesConcept, or
- a \ref txpl::vm::array "vm::array<>" of \ref VmValueConcept "values", or
- a \ref txpl::vm::dict "vm::dict<>" with \ref VmValueConcept "values".

Refinement of
-------------

None

Expression requirements
-----------------------

Definitions:

- `x` is an object that models the \ref VmValueConcept,
- `X` is the type of `x`,
- `Blank` is the associated type used to represent uninitialized values (blank),
- `Char` is an associated character type, 
- `Int` is an associated integer type, 
- `Bool` is an associated boolean type, 
- `Real` is an associated real type, 
- `String` is an associated string type, 
- `Regex` is an associated regex type, 
- `Array` is an associated type used to implement arrays,
- `Dict` is an associated type used to implements dictionaries.

Expressions:

(note, this is quite informal, we should use a recursive variant type instead
 of the ``boost::variant`` here)

- all expressions valid for
  `boost::variant<Blank,Char,Int,Bool,Real,String,Regex,Array,Dict>` must
  also be valid for `X`,
- all expressions valid for instances of
  `boost::variant<Blank,Char,Int,Bool,Real,String,Regex,Array,Dict>` must
  also be valid for `x`.

In addition, the following expressions must be valid

|               Expression                    |   Type    |   Complexity   |
| ------------------------------------------- | --------- | -------------- |
| <tt>vm::value_traits<X>::blank_type</tt>    |  `Blank`  | Constant time  |
| <tt>vm::value_traits<X>::char_type</tt>     |  `Char`   | Constant time  |
| <tt>vm::value_traits<X>::int_type</tt>      |  `Int`    | Constant time  |
| <tt>vm::value_traits<X>::bool_type</tt>     |  `Bool`   | Constant time  |
| <tt>vm::value_traits<X>::real_type</tt>     |  `Real`   | Constant time  |
| <tt>vm::value_traits<X>::string_type</tt>   |  `String` | Constant time  |
| <tt>vm::value_traits<X>::regex_type</tt>    |  `Regex`  | Constant time  |

Expression semantics
---------------------

All valid expressions for `X` have same semantics as corresponding expressions
involving `boost::variant<Blank,Char,Int,Bool,Real,String,Regex,Array,Dict>`.
All valid expressions for `x` have same semantics as the corresponding
expressions involving an instance of
`boost::variant<Blank,Char,Int,Bool,Real,String,Regex,Array,Dict>`.

|               Expression                   |                                  Semantics                                  |
| ------------------------------------------ | --------------------------------------------------------------------------- |
| <tt>vm::value_traits<X>::blank_type</tt>   | The type associated with `X` which is used to implement uninitialized value |
| <tt>vm::value_traits<X>::char_type</tt>    | The type associated with `X` which is used to implement character           |
| <tt>vm::value_traits<X>::int_type</tt>     | The type associated with `X` which is used to implement integer numbers     |
| <tt>vm::value_traits<X>::bool_type</tt>    | The type associated with `X` which is used to implement boolean values      |
| <tt>vm::value_traits<X>::real_type</tt>    | The type associated with `X` which is used to implement real numbers        |
| <tt>vm::value_traits<X>::string_type</tt>  | The type associated with `X` which is used to implement strings             |
| <tt>vm::value_traits<X>::regex_type</tt>   | The type associated with `X` which is used to implement regular expressions |

Invariants
----------

Models
------

- \ref txpl::vm::value "vm::value<>"

See also
--------

- \ref txpl::vm::value_traits "vm::value_traits<>"

