// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton interface for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


/**
 ** \file Parser.tab.hpp
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_PARSER_TAB_HPP_INCLUDED
# define YY_YY_PARSER_TAB_HPP_INCLUDED
// "%code requires" blocks.
#line 8 "Parser.ypp"

    #pragma once
    #include <iostream>
    #include <string>
    #include "../AST/AST.h"

    using namespace ast;

    namespace yy
    {
        class parser;
    }

#line 63 "Parser.tab.hpp"

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif

#include <typeinfo>
#ifndef YY_ASSERT
# include <cassert>
# define YY_ASSERT assert
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

namespace yy {
#line 203 "Parser.tab.hpp"




  /// A Bison parser.
  class parser
  {
  public:
#ifdef YYSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define YYSTYPE in C++, use %define api.value.type"
# endif
    typedef YYSTYPE value_type;
#else
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class value_type
  {
  public:
    /// Type of *this.
    typedef value_type self_type;

    /// Empty construction.
    value_type () YY_NOEXCEPT
      : yyraw_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    value_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      YY_ASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    value_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~value_type () YY_NOEXCEPT
    {
      YY_ASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == *that.yytypeid_);
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    value_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yyraw_;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yyraw_;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // tkConstBoolean
      char dummy1[sizeof (bool)];

      // tkConstReal
      char dummy2[sizeof (double)];

      // tkConstInt
      char dummy3[sizeof (int)];

      // _arr_type
      char dummy4[sizeof (sp<Array>)];

      // _assign
      char dummy5[sizeof (sp<Assignment>)];

      // _body
      char dummy6[sizeof (sp<Block>)];

      // _irb_type
      char dummy7[sizeof (sp<BuiltinType>)];

      // _expr
      // _primary
      // _getvar
      // _modval
      char dummy8[sizeof (sp<Expression>)];

      // _rec_type
      char dummy9[sizeof (sp<Record>)];

      // _return
      char dummy10[sizeof (sp<ReturnStatement>)];

      // _routine_dec
      char dummy11[sizeof (sp<Routine>)];

      // _routine
      char dummy12[sizeof (sp<RoutineCall> )];

      // _statement
      // _while
      // _for
      // _if
      char dummy13[sizeof (sp<Statement>)];

      // _type
      char dummy14[sizeof (sp<Type>)];

      // _var_dec
      // _param_dec
      char dummy15[sizeof (sp<Variable>)];

      // _args
      char dummy16[sizeof (spv<Expression>)];

      // _params
      // _var_dec_block
      char dummy17[sizeof (spv<Variable>)];

      // tkIdentifier
      char dummy18[sizeof (std::string)];

      // _range
      char dummy19[sizeof (std::tuple<sp<Expression>, sp<Expression>, bool>)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me_;
      /// A buffer large enough to store any of the semantic values.
      char yyraw_[size];
    };

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;


    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const std::string& m)
        : std::runtime_error (m)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        YYEMPTY = -2,
    YYEOF = 0,                     // "end of file"
    YYerror = 256,                 // error
    YYUNDEF = 257,                 // "invalid token"
    tkConstInt = 258,              // tkConstInt
    tkConstReal = 259,             // tkConstReal
    tkConstBoolean = 260,          // tkConstBoolean
    tkInt = 261,                   // tkInt
    tkReal = 262,                  // tkReal
    tkVar = 263,                   // tkVar
    tkBoolean = 264,               // tkBoolean
    tkString = 265,                // tkString
    tkArray = 266,                 // tkArray
    tkType = 267,                  // tkType
    tkRecord = 268,                // tkRecord
    tkRoutine = 269,               // tkRoutine
    tkIdentifier = 270,            // tkIdentifier
    tkBoolAnd = 271,               // tkBoolAnd
    tkBoolOr = 272,                // tkBoolOr
    tkBoolXor = 273,               // tkBoolXor
    tkBoolNot = 274,               // tkBoolNot
    tkTrue = 275,                  // tkTrue
    tkFalse = 276,                 // tkFalse
    tkLess = 277,                  // tkLess
    tkLessEquals = 278,            // tkLessEquals
    tkGreater = 279,               // tkGreater
    tkGreaterEquals = 280,         // tkGreaterEquals
    tkEquals = 281,                // tkEquals
    tkNotEquals = 282,             // tkNotEquals
    tkPlus = 283,                  // tkPlus
    tkMinus = 284,                 // tkMinus
    tkMultiple = 285,              // tkMultiple
    tkMod = 286,                   // tkMod
    tkDivide = 287,                // tkDivide
    tkIs = 288,                    // tkIs
    tkIf = 289,                    // tkIf
    tkThen = 290,                  // tkThen
    tkElse = 291,                  // tkElse
    tkEnd = 292,                   // tkEnd
    tkFor = 293,                   // tkFor
    tkIn = 294,                    // tkIn
    tkLoop = 295,                  // tkLoop
    tkReverse = 296,               // tkReverse
    tkDOT_DOT = 297,               // tkDOT_DOT
    tkWhile = 298,                 // tkWhile
    tkReturn = 299,                // tkReturn
    tkContinue = 300,              // tkContinue
    tkBreak = 301,                 // tkBreak
    tkSemiColon = 302,             // tkSemiColon
    tkColon = 303,                 // tkColon
    tkDot = 304,                   // tkDot
    tkComma = 305,                 // tkComma
    EOL = 306,                     // EOL
    tkCOLON_EQUALS = 307,          // tkCOLON_EQUALS
    tkNewLine = 308,               // tkNewLine
    tkQuote = 309,                 // tkQuote
    tkSQUARE_BRACKET_START = 310,  // tkSQUARE_BRACKET_START
    tkSQUARE_BRACKET_END = 311,    // tkSQUARE_BRACKET_END
    tkROUND_BRACKET_START = 312,   // tkROUND_BRACKET_START
    tkROUND_BRACKET_END = 313,     // tkROUND_BRACKET_END
    tkCURLY_BRACKET_START = 314,   // tkCURLY_BRACKET_START
    tkCURLY_BRACKET_END = 315,     // tkCURLY_BRACKET_END
    tkBackSlash = 316,             // tkBackSlash
    tkSpace = 317,                 // tkSpace
    tkTabulation = 318             // tkTabulation
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::token_kind_type token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 64, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_tkConstInt = 3,                        // tkConstInt
        S_tkConstReal = 4,                       // tkConstReal
        S_tkConstBoolean = 5,                    // tkConstBoolean
        S_tkInt = 6,                             // tkInt
        S_tkReal = 7,                            // tkReal
        S_tkVar = 8,                             // tkVar
        S_tkBoolean = 9,                         // tkBoolean
        S_tkString = 10,                         // tkString
        S_tkArray = 11,                          // tkArray
        S_tkType = 12,                           // tkType
        S_tkRecord = 13,                         // tkRecord
        S_tkRoutine = 14,                        // tkRoutine
        S_tkIdentifier = 15,                     // tkIdentifier
        S_tkBoolAnd = 16,                        // tkBoolAnd
        S_tkBoolOr = 17,                         // tkBoolOr
        S_tkBoolXor = 18,                        // tkBoolXor
        S_tkBoolNot = 19,                        // tkBoolNot
        S_tkTrue = 20,                           // tkTrue
        S_tkFalse = 21,                          // tkFalse
        S_tkLess = 22,                           // tkLess
        S_tkLessEquals = 23,                     // tkLessEquals
        S_tkGreater = 24,                        // tkGreater
        S_tkGreaterEquals = 25,                  // tkGreaterEquals
        S_tkEquals = 26,                         // tkEquals
        S_tkNotEquals = 27,                      // tkNotEquals
        S_tkPlus = 28,                           // tkPlus
        S_tkMinus = 29,                          // tkMinus
        S_tkMultiple = 30,                       // tkMultiple
        S_tkMod = 31,                            // tkMod
        S_tkDivide = 32,                         // tkDivide
        S_tkIs = 33,                             // tkIs
        S_tkIf = 34,                             // tkIf
        S_tkThen = 35,                           // tkThen
        S_tkElse = 36,                           // tkElse
        S_tkEnd = 37,                            // tkEnd
        S_tkFor = 38,                            // tkFor
        S_tkIn = 39,                             // tkIn
        S_tkLoop = 40,                           // tkLoop
        S_tkReverse = 41,                        // tkReverse
        S_tkDOT_DOT = 42,                        // tkDOT_DOT
        S_tkWhile = 43,                          // tkWhile
        S_tkReturn = 44,                         // tkReturn
        S_tkContinue = 45,                       // tkContinue
        S_tkBreak = 46,                          // tkBreak
        S_tkSemiColon = 47,                      // tkSemiColon
        S_tkColon = 48,                          // tkColon
        S_tkDot = 49,                            // tkDot
        S_tkComma = 50,                          // tkComma
        S_EOL = 51,                              // EOL
        S_tkCOLON_EQUALS = 52,                   // tkCOLON_EQUALS
        S_tkNewLine = 53,                        // tkNewLine
        S_tkQuote = 54,                          // tkQuote
        S_tkSQUARE_BRACKET_START = 55,           // tkSQUARE_BRACKET_START
        S_tkSQUARE_BRACKET_END = 56,             // tkSQUARE_BRACKET_END
        S_tkROUND_BRACKET_START = 57,            // tkROUND_BRACKET_START
        S_tkROUND_BRACKET_END = 58,              // tkROUND_BRACKET_END
        S_tkCURLY_BRACKET_START = 59,            // tkCURLY_BRACKET_START
        S_tkCURLY_BRACKET_END = 60,              // tkCURLY_BRACKET_END
        S_tkBackSlash = 61,                      // tkBackSlash
        S_tkSpace = 62,                          // tkSpace
        S_tkTabulation = 63,                     // tkTabulation
        S_YYACCEPT = 64,                         // $accept
        S_program = 65,                          // program
        S__var_dec = 66,                         // _var_dec
        S__type_dec = 67,                        // _type_dec
        S__routine_dec = 68,                     // _routine_dec
        S__params = 69,                          // _params
        S__param_dec = 70,                       // _param_dec
        S__type = 71,                            // _type
        S__irb_type = 72,                        // _irb_type
        S__rec_type = 73,                        // _rec_type
        S__arr_type = 74,                        // _arr_type
        S__body = 75,                            // _body
        S__statement = 76,                       // _statement
        S__return = 77,                          // _return
        S__assign = 78,                          // _assign
        S__routine = 79,                         // _routine
        S__while = 80,                           // _while
        S__for = 81,                             // _for
        S__range = 82,                           // _range
        S__if = 83,                              // _if
        S__var_dec_block = 84,                   // _var_dec_block
        S__expr = 85,                            // _expr
        S__args = 86,                            // _args
        S__primary = 87,                         // _primary
        S__getvar = 88,                          // _getvar
        S__modval = 89                           // _modval
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol () YY_NOEXCEPT
        : value ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
      {
        switch (this->kind ())
    {
      case symbol_kind::S_tkConstBoolean: // tkConstBoolean
        value.move< bool > (std::move (that.value));
        break;

      case symbol_kind::S_tkConstReal: // tkConstReal
        value.move< double > (std::move (that.value));
        break;

      case symbol_kind::S_tkConstInt: // tkConstInt
        value.move< int > (std::move (that.value));
        break;

      case symbol_kind::S__arr_type: // _arr_type
        value.move< sp<Array> > (std::move (that.value));
        break;

      case symbol_kind::S__assign: // _assign
        value.move< sp<Assignment> > (std::move (that.value));
        break;

      case symbol_kind::S__body: // _body
        value.move< sp<Block> > (std::move (that.value));
        break;

      case symbol_kind::S__irb_type: // _irb_type
        value.move< sp<BuiltinType> > (std::move (that.value));
        break;

      case symbol_kind::S__expr: // _expr
      case symbol_kind::S__primary: // _primary
      case symbol_kind::S__getvar: // _getvar
      case symbol_kind::S__modval: // _modval
        value.move< sp<Expression> > (std::move (that.value));
        break;

      case symbol_kind::S__rec_type: // _rec_type
        value.move< sp<Record> > (std::move (that.value));
        break;

      case symbol_kind::S__return: // _return
        value.move< sp<ReturnStatement> > (std::move (that.value));
        break;

      case symbol_kind::S__routine_dec: // _routine_dec
        value.move< sp<Routine> > (std::move (that.value));
        break;

      case symbol_kind::S__routine: // _routine
        value.move< sp<RoutineCall>  > (std::move (that.value));
        break;

      case symbol_kind::S__statement: // _statement
      case symbol_kind::S__while: // _while
      case symbol_kind::S__for: // _for
      case symbol_kind::S__if: // _if
        value.move< sp<Statement> > (std::move (that.value));
        break;

      case symbol_kind::S__type: // _type
        value.move< sp<Type> > (std::move (that.value));
        break;

      case symbol_kind::S__var_dec: // _var_dec
      case symbol_kind::S__param_dec: // _param_dec
        value.move< sp<Variable> > (std::move (that.value));
        break;

      case symbol_kind::S__args: // _args
        value.move< spv<Expression> > (std::move (that.value));
        break;

      case symbol_kind::S__params: // _params
      case symbol_kind::S__var_dec_block: // _var_dec_block
        value.move< spv<Variable> > (std::move (that.value));
        break;

      case symbol_kind::S_tkIdentifier: // tkIdentifier
        value.move< std::string > (std::move (that.value));
        break;

      case symbol_kind::S__range: // _range
        value.move< std::tuple<sp<Expression>, sp<Expression>, bool> > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t)
        : Base (t)
      {}
#else
      basic_symbol (typename Base::kind_type t)
        : Base (t)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, bool&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const bool& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, double&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const double& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, int&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const int& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, sp<Array>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const sp<Array>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, sp<Assignment>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const sp<Assignment>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, sp<Block>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const sp<Block>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, sp<BuiltinType>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const sp<BuiltinType>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, sp<Expression>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const sp<Expression>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, sp<Record>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const sp<Record>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, sp<ReturnStatement>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const sp<ReturnStatement>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, sp<Routine>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const sp<Routine>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, sp<RoutineCall> && v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const sp<RoutineCall> & v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, sp<Statement>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const sp<Statement>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, sp<Type>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const sp<Type>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, sp<Variable>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const sp<Variable>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, spv<Expression>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const spv<Expression>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, spv<Variable>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const spv<Variable>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::tuple<sp<Expression>, sp<Expression>, bool>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::tuple<sp<Expression>, sp<Expression>, bool>& v)
        : Base (t)
        , value (v)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }



      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_tkConstBoolean: // tkConstBoolean
        value.template destroy< bool > ();
        break;

      case symbol_kind::S_tkConstReal: // tkConstReal
        value.template destroy< double > ();
        break;

      case symbol_kind::S_tkConstInt: // tkConstInt
        value.template destroy< int > ();
        break;

      case symbol_kind::S__arr_type: // _arr_type
        value.template destroy< sp<Array> > ();
        break;

      case symbol_kind::S__assign: // _assign
        value.template destroy< sp<Assignment> > ();
        break;

      case symbol_kind::S__body: // _body
        value.template destroy< sp<Block> > ();
        break;

      case symbol_kind::S__irb_type: // _irb_type
        value.template destroy< sp<BuiltinType> > ();
        break;

      case symbol_kind::S__expr: // _expr
      case symbol_kind::S__primary: // _primary
      case symbol_kind::S__getvar: // _getvar
      case symbol_kind::S__modval: // _modval
        value.template destroy< sp<Expression> > ();
        break;

      case symbol_kind::S__rec_type: // _rec_type
        value.template destroy< sp<Record> > ();
        break;

      case symbol_kind::S__return: // _return
        value.template destroy< sp<ReturnStatement> > ();
        break;

      case symbol_kind::S__routine_dec: // _routine_dec
        value.template destroy< sp<Routine> > ();
        break;

      case symbol_kind::S__routine: // _routine
        value.template destroy< sp<RoutineCall>  > ();
        break;

      case symbol_kind::S__statement: // _statement
      case symbol_kind::S__while: // _while
      case symbol_kind::S__for: // _for
      case symbol_kind::S__if: // _if
        value.template destroy< sp<Statement> > ();
        break;

      case symbol_kind::S__type: // _type
        value.template destroy< sp<Type> > ();
        break;

      case symbol_kind::S__var_dec: // _var_dec
      case symbol_kind::S__param_dec: // _param_dec
        value.template destroy< sp<Variable> > ();
        break;

      case symbol_kind::S__args: // _args
        value.template destroy< spv<Expression> > ();
        break;

      case symbol_kind::S__params: // _params
      case symbol_kind::S__var_dec_block: // _var_dec_block
        value.template destroy< spv<Variable> > ();
        break;

      case symbol_kind::S_tkIdentifier: // tkIdentifier
        value.template destroy< std::string > ();
        break;

      case symbol_kind::S__range: // _range
        value.template destroy< std::tuple<sp<Expression>, sp<Expression>, bool> > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

#if YYDEBUG || 0
      /// The user-facing name of this symbol.
      const char *name () const YY_NOEXCEPT
      {
        return parser::symbol_name (this->kind ());
      }
#endif // #if YYDEBUG || 0


      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      value_type value;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Default constructor.
      by_kind () YY_NOEXCEPT;

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that) YY_NOEXCEPT;
#endif

      /// Copy constructor.
      by_kind (const by_kind& that) YY_NOEXCEPT;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t) YY_NOEXCEPT;



      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () YY_NOEXCEPT {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok)
        : super_type (token_kind_type (tok))
#else
      symbol_type (int tok)
        : super_type (token_kind_type (tok))
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::YYEOF
                   || (token::YYerror <= tok && tok <= token::YYUNDEF)
                   || (token::tkInt <= tok && tok <= token::tkRoutine)
                   || (token::tkBoolAnd <= tok && tok <= token::tkTabulation));
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, bool v)
        : super_type (token_kind_type (tok), std::move (v))
#else
      symbol_type (int tok, const bool& v)
        : super_type (token_kind_type (tok), v)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::tkConstBoolean);
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, double v)
        : super_type (token_kind_type (tok), std::move (v))
#else
      symbol_type (int tok, const double& v)
        : super_type (token_kind_type (tok), v)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::tkConstReal);
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, int v)
        : super_type (token_kind_type (tok), std::move (v))
#else
      symbol_type (int tok, const int& v)
        : super_type (token_kind_type (tok), v)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::tkConstInt);
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v)
        : super_type (token_kind_type (tok), std::move (v))
#else
      symbol_type (int tok, const std::string& v)
        : super_type (token_kind_type (tok), v)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::tkIdentifier);
#endif
      }
    };

    /// Build a parser object.
    parser ();
    virtual ~parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    parser (const parser&) = delete;
    /// Non copyable.
    parser& operator= (const parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param msg    a description of the syntax error.
    virtual void error (const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

#if YYDEBUG || 0
    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static const char *symbol_name (symbol_kind_type yysymbol);
#endif // #if YYDEBUG || 0


    // Implementation of make_symbol for each token kind.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYEOF ()
      {
        return symbol_type (token::YYEOF);
      }
#else
      static
      symbol_type
      make_YYEOF ()
      {
        return symbol_type (token::YYEOF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror ()
      {
        return symbol_type (token::YYerror);
      }
#else
      static
      symbol_type
      make_YYerror ()
      {
        return symbol_type (token::YYerror);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF ()
      {
        return symbol_type (token::YYUNDEF);
      }
#else
      static
      symbol_type
      make_YYUNDEF ()
      {
        return symbol_type (token::YYUNDEF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkConstInt (int v)
      {
        return symbol_type (token::tkConstInt, std::move (v));
      }
#else
      static
      symbol_type
      make_tkConstInt (const int& v)
      {
        return symbol_type (token::tkConstInt, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkConstReal (double v)
      {
        return symbol_type (token::tkConstReal, std::move (v));
      }
#else
      static
      symbol_type
      make_tkConstReal (const double& v)
      {
        return symbol_type (token::tkConstReal, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkConstBoolean (bool v)
      {
        return symbol_type (token::tkConstBoolean, std::move (v));
      }
#else
      static
      symbol_type
      make_tkConstBoolean (const bool& v)
      {
        return symbol_type (token::tkConstBoolean, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkInt ()
      {
        return symbol_type (token::tkInt);
      }
#else
      static
      symbol_type
      make_tkInt ()
      {
        return symbol_type (token::tkInt);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkReal ()
      {
        return symbol_type (token::tkReal);
      }
#else
      static
      symbol_type
      make_tkReal ()
      {
        return symbol_type (token::tkReal);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkVar ()
      {
        return symbol_type (token::tkVar);
      }
#else
      static
      symbol_type
      make_tkVar ()
      {
        return symbol_type (token::tkVar);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkBoolean ()
      {
        return symbol_type (token::tkBoolean);
      }
#else
      static
      symbol_type
      make_tkBoolean ()
      {
        return symbol_type (token::tkBoolean);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkString ()
      {
        return symbol_type (token::tkString);
      }
#else
      static
      symbol_type
      make_tkString ()
      {
        return symbol_type (token::tkString);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkArray ()
      {
        return symbol_type (token::tkArray);
      }
#else
      static
      symbol_type
      make_tkArray ()
      {
        return symbol_type (token::tkArray);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkType ()
      {
        return symbol_type (token::tkType);
      }
#else
      static
      symbol_type
      make_tkType ()
      {
        return symbol_type (token::tkType);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkRecord ()
      {
        return symbol_type (token::tkRecord);
      }
#else
      static
      symbol_type
      make_tkRecord ()
      {
        return symbol_type (token::tkRecord);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkRoutine ()
      {
        return symbol_type (token::tkRoutine);
      }
#else
      static
      symbol_type
      make_tkRoutine ()
      {
        return symbol_type (token::tkRoutine);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkIdentifier (std::string v)
      {
        return symbol_type (token::tkIdentifier, std::move (v));
      }
#else
      static
      symbol_type
      make_tkIdentifier (const std::string& v)
      {
        return symbol_type (token::tkIdentifier, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkBoolAnd ()
      {
        return symbol_type (token::tkBoolAnd);
      }
#else
      static
      symbol_type
      make_tkBoolAnd ()
      {
        return symbol_type (token::tkBoolAnd);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkBoolOr ()
      {
        return symbol_type (token::tkBoolOr);
      }
#else
      static
      symbol_type
      make_tkBoolOr ()
      {
        return symbol_type (token::tkBoolOr);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkBoolXor ()
      {
        return symbol_type (token::tkBoolXor);
      }
#else
      static
      symbol_type
      make_tkBoolXor ()
      {
        return symbol_type (token::tkBoolXor);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkBoolNot ()
      {
        return symbol_type (token::tkBoolNot);
      }
#else
      static
      symbol_type
      make_tkBoolNot ()
      {
        return symbol_type (token::tkBoolNot);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkTrue ()
      {
        return symbol_type (token::tkTrue);
      }
#else
      static
      symbol_type
      make_tkTrue ()
      {
        return symbol_type (token::tkTrue);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkFalse ()
      {
        return symbol_type (token::tkFalse);
      }
#else
      static
      symbol_type
      make_tkFalse ()
      {
        return symbol_type (token::tkFalse);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkLess ()
      {
        return symbol_type (token::tkLess);
      }
#else
      static
      symbol_type
      make_tkLess ()
      {
        return symbol_type (token::tkLess);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkLessEquals ()
      {
        return symbol_type (token::tkLessEquals);
      }
#else
      static
      symbol_type
      make_tkLessEquals ()
      {
        return symbol_type (token::tkLessEquals);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkGreater ()
      {
        return symbol_type (token::tkGreater);
      }
#else
      static
      symbol_type
      make_tkGreater ()
      {
        return symbol_type (token::tkGreater);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkGreaterEquals ()
      {
        return symbol_type (token::tkGreaterEquals);
      }
#else
      static
      symbol_type
      make_tkGreaterEquals ()
      {
        return symbol_type (token::tkGreaterEquals);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkEquals ()
      {
        return symbol_type (token::tkEquals);
      }
#else
      static
      symbol_type
      make_tkEquals ()
      {
        return symbol_type (token::tkEquals);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkNotEquals ()
      {
        return symbol_type (token::tkNotEquals);
      }
#else
      static
      symbol_type
      make_tkNotEquals ()
      {
        return symbol_type (token::tkNotEquals);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkPlus ()
      {
        return symbol_type (token::tkPlus);
      }
#else
      static
      symbol_type
      make_tkPlus ()
      {
        return symbol_type (token::tkPlus);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkMinus ()
      {
        return symbol_type (token::tkMinus);
      }
#else
      static
      symbol_type
      make_tkMinus ()
      {
        return symbol_type (token::tkMinus);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkMultiple ()
      {
        return symbol_type (token::tkMultiple);
      }
#else
      static
      symbol_type
      make_tkMultiple ()
      {
        return symbol_type (token::tkMultiple);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkMod ()
      {
        return symbol_type (token::tkMod);
      }
#else
      static
      symbol_type
      make_tkMod ()
      {
        return symbol_type (token::tkMod);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkDivide ()
      {
        return symbol_type (token::tkDivide);
      }
#else
      static
      symbol_type
      make_tkDivide ()
      {
        return symbol_type (token::tkDivide);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkIs ()
      {
        return symbol_type (token::tkIs);
      }
#else
      static
      symbol_type
      make_tkIs ()
      {
        return symbol_type (token::tkIs);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkIf ()
      {
        return symbol_type (token::tkIf);
      }
#else
      static
      symbol_type
      make_tkIf ()
      {
        return symbol_type (token::tkIf);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkThen ()
      {
        return symbol_type (token::tkThen);
      }
#else
      static
      symbol_type
      make_tkThen ()
      {
        return symbol_type (token::tkThen);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkElse ()
      {
        return symbol_type (token::tkElse);
      }
#else
      static
      symbol_type
      make_tkElse ()
      {
        return symbol_type (token::tkElse);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkEnd ()
      {
        return symbol_type (token::tkEnd);
      }
#else
      static
      symbol_type
      make_tkEnd ()
      {
        return symbol_type (token::tkEnd);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkFor ()
      {
        return symbol_type (token::tkFor);
      }
#else
      static
      symbol_type
      make_tkFor ()
      {
        return symbol_type (token::tkFor);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkIn ()
      {
        return symbol_type (token::tkIn);
      }
#else
      static
      symbol_type
      make_tkIn ()
      {
        return symbol_type (token::tkIn);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkLoop ()
      {
        return symbol_type (token::tkLoop);
      }
#else
      static
      symbol_type
      make_tkLoop ()
      {
        return symbol_type (token::tkLoop);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkReverse ()
      {
        return symbol_type (token::tkReverse);
      }
#else
      static
      symbol_type
      make_tkReverse ()
      {
        return symbol_type (token::tkReverse);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkDOT_DOT ()
      {
        return symbol_type (token::tkDOT_DOT);
      }
#else
      static
      symbol_type
      make_tkDOT_DOT ()
      {
        return symbol_type (token::tkDOT_DOT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkWhile ()
      {
        return symbol_type (token::tkWhile);
      }
#else
      static
      symbol_type
      make_tkWhile ()
      {
        return symbol_type (token::tkWhile);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkReturn ()
      {
        return symbol_type (token::tkReturn);
      }
#else
      static
      symbol_type
      make_tkReturn ()
      {
        return symbol_type (token::tkReturn);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkContinue ()
      {
        return symbol_type (token::tkContinue);
      }
#else
      static
      symbol_type
      make_tkContinue ()
      {
        return symbol_type (token::tkContinue);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkBreak ()
      {
        return symbol_type (token::tkBreak);
      }
#else
      static
      symbol_type
      make_tkBreak ()
      {
        return symbol_type (token::tkBreak);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkSemiColon ()
      {
        return symbol_type (token::tkSemiColon);
      }
#else
      static
      symbol_type
      make_tkSemiColon ()
      {
        return symbol_type (token::tkSemiColon);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkColon ()
      {
        return symbol_type (token::tkColon);
      }
#else
      static
      symbol_type
      make_tkColon ()
      {
        return symbol_type (token::tkColon);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkDot ()
      {
        return symbol_type (token::tkDot);
      }
#else
      static
      symbol_type
      make_tkDot ()
      {
        return symbol_type (token::tkDot);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkComma ()
      {
        return symbol_type (token::tkComma);
      }
#else
      static
      symbol_type
      make_tkComma ()
      {
        return symbol_type (token::tkComma);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EOL ()
      {
        return symbol_type (token::EOL);
      }
#else
      static
      symbol_type
      make_EOL ()
      {
        return symbol_type (token::EOL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkCOLON_EQUALS ()
      {
        return symbol_type (token::tkCOLON_EQUALS);
      }
#else
      static
      symbol_type
      make_tkCOLON_EQUALS ()
      {
        return symbol_type (token::tkCOLON_EQUALS);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkNewLine ()
      {
        return symbol_type (token::tkNewLine);
      }
#else
      static
      symbol_type
      make_tkNewLine ()
      {
        return symbol_type (token::tkNewLine);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkQuote ()
      {
        return symbol_type (token::tkQuote);
      }
#else
      static
      symbol_type
      make_tkQuote ()
      {
        return symbol_type (token::tkQuote);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkSQUARE_BRACKET_START ()
      {
        return symbol_type (token::tkSQUARE_BRACKET_START);
      }
#else
      static
      symbol_type
      make_tkSQUARE_BRACKET_START ()
      {
        return symbol_type (token::tkSQUARE_BRACKET_START);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkSQUARE_BRACKET_END ()
      {
        return symbol_type (token::tkSQUARE_BRACKET_END);
      }
#else
      static
      symbol_type
      make_tkSQUARE_BRACKET_END ()
      {
        return symbol_type (token::tkSQUARE_BRACKET_END);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkROUND_BRACKET_START ()
      {
        return symbol_type (token::tkROUND_BRACKET_START);
      }
#else
      static
      symbol_type
      make_tkROUND_BRACKET_START ()
      {
        return symbol_type (token::tkROUND_BRACKET_START);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkROUND_BRACKET_END ()
      {
        return symbol_type (token::tkROUND_BRACKET_END);
      }
#else
      static
      symbol_type
      make_tkROUND_BRACKET_END ()
      {
        return symbol_type (token::tkROUND_BRACKET_END);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkCURLY_BRACKET_START ()
      {
        return symbol_type (token::tkCURLY_BRACKET_START);
      }
#else
      static
      symbol_type
      make_tkCURLY_BRACKET_START ()
      {
        return symbol_type (token::tkCURLY_BRACKET_START);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkCURLY_BRACKET_END ()
      {
        return symbol_type (token::tkCURLY_BRACKET_END);
      }
#else
      static
      symbol_type
      make_tkCURLY_BRACKET_END ()
      {
        return symbol_type (token::tkCURLY_BRACKET_END);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkBackSlash ()
      {
        return symbol_type (token::tkBackSlash);
      }
#else
      static
      symbol_type
      make_tkBackSlash ()
      {
        return symbol_type (token::tkBackSlash);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkSpace ()
      {
        return symbol_type (token::tkSpace);
      }
#else
      static
      symbol_type
      make_tkSpace ()
      {
        return symbol_type (token::tkSpace);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_tkTabulation ()
      {
        return symbol_type (token::tkTabulation);
      }
#else
      static
      symbol_type
      make_tkTabulation ()
      {
        return symbol_type (token::tkTabulation);
      }
#endif


  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    parser (const parser&);
    /// Non copyable.
    parser& operator= (const parser&);
#endif


    /// Stored state numbers (used for stacks).
    typedef unsigned char state_type;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT;

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT;

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;

#if YYDEBUG || 0
    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#endif // #if YYDEBUG || 0


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const signed char yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const signed char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const unsigned char yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const signed char yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const unsigned char yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200) YY_NOEXCEPT
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range) YY_NOEXCEPT
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1) YY_NOEXCEPT;

    /// Constants.
    enum
    {
      yylast_ = 432,     ///< Last index in yytable_.
      yynnts_ = 26,  ///< Number of nonterminal symbols.
      yyfinal_ = 2 ///< Termination state number.
    };



  };

  inline
  parser::symbol_kind_type
  parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63
    };
    // Last valid token kind.
    const int code_max = 318;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
  {
    switch (this->kind ())
    {
      case symbol_kind::S_tkConstBoolean: // tkConstBoolean
        value.copy< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tkConstReal: // tkConstReal
        value.copy< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tkConstInt: // tkConstInt
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__arr_type: // _arr_type
        value.copy< sp<Array> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__assign: // _assign
        value.copy< sp<Assignment> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__body: // _body
        value.copy< sp<Block> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__irb_type: // _irb_type
        value.copy< sp<BuiltinType> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__expr: // _expr
      case symbol_kind::S__primary: // _primary
      case symbol_kind::S__getvar: // _getvar
      case symbol_kind::S__modval: // _modval
        value.copy< sp<Expression> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__rec_type: // _rec_type
        value.copy< sp<Record> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__return: // _return
        value.copy< sp<ReturnStatement> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__routine_dec: // _routine_dec
        value.copy< sp<Routine> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__routine: // _routine
        value.copy< sp<RoutineCall>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__statement: // _statement
      case symbol_kind::S__while: // _while
      case symbol_kind::S__for: // _for
      case symbol_kind::S__if: // _if
        value.copy< sp<Statement> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__type: // _type
        value.copy< sp<Type> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__var_dec: // _var_dec
      case symbol_kind::S__param_dec: // _param_dec
        value.copy< sp<Variable> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__args: // _args
        value.copy< spv<Expression> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__params: // _params
      case symbol_kind::S__var_dec_block: // _var_dec_block
        value.copy< spv<Variable> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tkIdentifier: // tkIdentifier
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__range: // _range
        value.copy< std::tuple<sp<Expression>, sp<Expression>, bool> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  parser::symbol_kind_type
  parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_tkConstBoolean: // tkConstBoolean
        value.move< bool > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_tkConstReal: // tkConstReal
        value.move< double > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_tkConstInt: // tkConstInt
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S__arr_type: // _arr_type
        value.move< sp<Array> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S__assign: // _assign
        value.move< sp<Assignment> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S__body: // _body
        value.move< sp<Block> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S__irb_type: // _irb_type
        value.move< sp<BuiltinType> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S__expr: // _expr
      case symbol_kind::S__primary: // _primary
      case symbol_kind::S__getvar: // _getvar
      case symbol_kind::S__modval: // _modval
        value.move< sp<Expression> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S__rec_type: // _rec_type
        value.move< sp<Record> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S__return: // _return
        value.move< sp<ReturnStatement> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S__routine_dec: // _routine_dec
        value.move< sp<Routine> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S__routine: // _routine
        value.move< sp<RoutineCall>  > (YY_MOVE (s.value));
        break;

      case symbol_kind::S__statement: // _statement
      case symbol_kind::S__while: // _while
      case symbol_kind::S__for: // _for
      case symbol_kind::S__if: // _if
        value.move< sp<Statement> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S__type: // _type
        value.move< sp<Type> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S__var_dec: // _var_dec
      case symbol_kind::S__param_dec: // _param_dec
        value.move< sp<Variable> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S__args: // _args
        value.move< spv<Expression> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S__params: // _params
      case symbol_kind::S__var_dec_block: // _var_dec_block
        value.move< spv<Variable> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_tkIdentifier: // tkIdentifier
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S__range: // _range
        value.move< std::tuple<sp<Expression>, sp<Expression>, bool> > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

  }

  // by_kind.
  inline
  parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  inline
  parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  inline
  parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  inline
  void
  parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  inline
  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  inline
  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  inline
  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


} // yy
#line 2976 "Parser.tab.hpp"




#endif // !YY_YY_PARSER_TAB_HPP_INCLUDED
