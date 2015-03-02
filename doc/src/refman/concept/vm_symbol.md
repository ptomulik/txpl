Scope Symbol {#VmSymbolConcept}
============

Description
-----------

\ref VmSymbolConcept is a variant object able to store

- blank symbol (to represent uninitialized symbol), or
- a \ref VmValueConcept "value" (used to implement variables), or
- a \ref VmScopeConcept "scope" (used to implement nested scopes).

A \ref VmSymbolConcept type is a parametrized type with associated types

- `Blank` - blank symbol type,
- `Value` - \ref VmValueConcept type,
- `Scope` - \ref VmScopeConcept type.

The \ref VmSymbolConcept is used as a mapped value in a symbol map
called \ref VmScopeConcept "scope".

Refinement of
-------------

None

Expression requirements
-----------------------

Definitions:

- `x` is an object that models the \ref VmSymbolConcept,
- `X` is the type of `x`,
- `Blank` is the associated type used to represent an uninitialized symbol (blank),
- `Value` is the associated \ref VmValueConcept type,
- `Scope` is the associated \ref VmScopeConcept type.

Expressions:

- all expressions valid for `boost::variant<Blank,Value,Scope>` must also be
  valid for X,
- all expressions valid for instances of `boost::variant<Blank,Value,Scope>`
  must also be valid for `x`.

In addition, the following expressions must be valid

|               Expression                   |   Type    |   Complexity   |
| ------------------------------------------ | --------- | -------------- |
| <tt>vm::symbol_traits<X>::blank_type</tt>  |  `Blank`  | Constant time  |
| <tt>vm::symbol_traits<X>::value_type</tt>  |  `Value`  | Constant time  |
| <tt>vm::symbol_traits<X>::scope_type</tt>  |  `Scope`  | Constant time  |

Expression semantics
---------------------

All valid expressions for `X` have same semantics as corresponding expressions
involving `boost::variant<Blank,Value,Scope>`. All valid expressions for `x`
have same semantics as the corresponding expressions involving an instance of
`boost::variant<Blank,Value,Scope>`.

|               Expression                   |                                  Semantics                                  |
| ------------------------------------------ | --------------------------------------------------------------------------- |
| <tt>vm::symbol_traits<X>::blank_type</tt>  | The type associated with `X` which is used to implement blank symbol        |
| <tt>vm::symbol_traits<X>::value_type</tt>  | The type associated with `X` which is used to implement \ref VmValueConcept |
| <tt>vm::symbol_traits<X>::scope_type</tt>  | The type associated with `X` which is used to implement \ref VmScopeConcept |

Invariants
----------

\verbatim
std::is_same<vm::symbol_traits<X>::scope_type::mapped_type, X>::value == true
\endverbatim

Models
------

- \ref txpl::vm::symbol "vm::symbol<>"

See also
--------

- \ref txpl::vm::symbol_traits "vm::symbol_traits<>"

