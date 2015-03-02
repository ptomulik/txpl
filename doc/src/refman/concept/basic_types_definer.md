Basic Types Definer {#BasicTypesDefinerConcept}
===================

Description
-----------

The \ref BasicTypesDefinerConcept is a type providing nested typedefs for basic
types used by TXPL.

Refinement of
-------------

None

Expression requirements
-----------------------

- `X` is a model of \ref BasicTypesDefinerConcept

|     Expression     |        Type         |    Complexity    |
| -------------------|-------------------- | ---------------- |
|  `X::blank_type`   |  Unspecified        |  Constant time   |
|  `X::char_type`    |  Character type     |  Constant time   |
|  `X::int_type`     |  Integral type      |  Constant time   |
|  `X::bool_type`    |  Boolean type       |  Constant time   |
|  `X::real_type`    |  Floating point     |  Constant time   |
|  `X::string_type`  |  String type        |  Constant time   |
|  `X::regex_type`   |  Regular expression |  Constant time   |

Expression semantics
---------------------

|     Expression     |                        Semantics                      |
| -------------------|------------------------------------------------------ |
|  `X::blank_type`   | Returns a type used to represent uninitialized values |
|  `X::char_type`    | Returns a type used to represent characters           |
|  `X::int_type`     | Returns a type used to represent integers             |
|  `X::bool_type`    | Returns a type used to represent boolean values       |
|  `X::real_type`    | Returns a type used to represent real numbers         |
|  `X::string_type`  | Returna a type used to represent strings              |
|  `X::regex_type`   | Returns a type used to represent regular expressions  |

Invariants
----------

Any two distinct expressions `E1` and `E2` from the above tables must yield
distinct types, that is:

- <tt>std::is_same<E1, E2>::value == false</tt>

Models
------

- \ref txpl::vm::basic_types "vm::basic_types"
- \ref txpl::ast::basic_types "ast::basic_types"

See also
--------

- \ref BasicTypesConcept
