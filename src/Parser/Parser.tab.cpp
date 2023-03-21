// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

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

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "Parser.tab.hpp"


// Unqualified %code blocks.
#line 23 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"

    // Our program is defined here
    sp<ast::Program> ourProgram = std::make_shared<ast::Program>();

    namespace yy
    {
        parser::symbol_type yylex();
    }

    extern yy::parser::symbol_type get_next_token();

#line 58 "Parser.tab.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 131 "Parser.tab.cpp"

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_tkConstBoolean: // tkConstBoolean
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tkConstReal: // tkConstReal
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tkConstInt: // tkConstInt
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__arr_type: // _arr_type
        value.YY_MOVE_OR_COPY< sp<Array> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__assign: // _assign
        value.YY_MOVE_OR_COPY< sp<Assignment> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__body: // _body
        value.YY_MOVE_OR_COPY< sp<Block> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__irb_type: // _irb_type
        value.YY_MOVE_OR_COPY< sp<BuiltinType> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__expr: // _expr
      case symbol_kind::S__primary: // _primary
      case symbol_kind::S__getvar: // _getvar
      case symbol_kind::S__modval: // _modval
        value.YY_MOVE_OR_COPY< sp<Expression> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__rec_type: // _rec_type
        value.YY_MOVE_OR_COPY< sp<Record> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__return: // _return
        value.YY_MOVE_OR_COPY< sp<ReturnStatement> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__routine_dec: // _routine_dec
        value.YY_MOVE_OR_COPY< sp<Routine> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__routine: // _routine
        value.YY_MOVE_OR_COPY< sp<RoutineCall>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__statement: // _statement
      case symbol_kind::S__while: // _while
      case symbol_kind::S__for: // _for
      case symbol_kind::S__if: // _if
        value.YY_MOVE_OR_COPY< sp<Statement> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__type: // _type
        value.YY_MOVE_OR_COPY< sp<Type> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__var_dec: // _var_dec
      case symbol_kind::S__param_dec: // _param_dec
        value.YY_MOVE_OR_COPY< sp<Variable> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__args: // _args
        value.YY_MOVE_OR_COPY< spv<Expression> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__params: // _params
      case symbol_kind::S__var_dec_block: // _var_dec_block
        value.YY_MOVE_OR_COPY< spv<Variable> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tkIdentifier: // tkIdentifier
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__range: // _range
        value.YY_MOVE_OR_COPY< std::tuple<sp<Expression>, sp<Expression>, bool> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_tkConstBoolean: // tkConstBoolean
        value.move< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tkConstReal: // tkConstReal
        value.move< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tkConstInt: // tkConstInt
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__arr_type: // _arr_type
        value.move< sp<Array> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__assign: // _assign
        value.move< sp<Assignment> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__body: // _body
        value.move< sp<Block> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__irb_type: // _irb_type
        value.move< sp<BuiltinType> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__expr: // _expr
      case symbol_kind::S__primary: // _primary
      case symbol_kind::S__getvar: // _getvar
      case symbol_kind::S__modval: // _modval
        value.move< sp<Expression> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__rec_type: // _rec_type
        value.move< sp<Record> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__return: // _return
        value.move< sp<ReturnStatement> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__routine_dec: // _routine_dec
        value.move< sp<Routine> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__routine: // _routine
        value.move< sp<RoutineCall>  > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__statement: // _statement
      case symbol_kind::S__while: // _while
      case symbol_kind::S__for: // _for
      case symbol_kind::S__if: // _if
        value.move< sp<Statement> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__type: // _type
        value.move< sp<Type> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__var_dec: // _var_dec
      case symbol_kind::S__param_dec: // _param_dec
        value.move< sp<Variable> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__args: // _args
        value.move< spv<Expression> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__params: // _params
      case symbol_kind::S__var_dec_block: // _var_dec_block
        value.move< spv<Variable> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tkIdentifier: // tkIdentifier
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S__range: // _range
        value.move< std::tuple<sp<Expression>, sp<Expression>, bool> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_tkConstBoolean: // tkConstBoolean
        value.copy< bool > (that.value);
        break;

      case symbol_kind::S_tkConstReal: // tkConstReal
        value.copy< double > (that.value);
        break;

      case symbol_kind::S_tkConstInt: // tkConstInt
        value.copy< int > (that.value);
        break;

      case symbol_kind::S__arr_type: // _arr_type
        value.copy< sp<Array> > (that.value);
        break;

      case symbol_kind::S__assign: // _assign
        value.copy< sp<Assignment> > (that.value);
        break;

      case symbol_kind::S__body: // _body
        value.copy< sp<Block> > (that.value);
        break;

      case symbol_kind::S__irb_type: // _irb_type
        value.copy< sp<BuiltinType> > (that.value);
        break;

      case symbol_kind::S__expr: // _expr
      case symbol_kind::S__primary: // _primary
      case symbol_kind::S__getvar: // _getvar
      case symbol_kind::S__modval: // _modval
        value.copy< sp<Expression> > (that.value);
        break;

      case symbol_kind::S__rec_type: // _rec_type
        value.copy< sp<Record> > (that.value);
        break;

      case symbol_kind::S__return: // _return
        value.copy< sp<ReturnStatement> > (that.value);
        break;

      case symbol_kind::S__routine_dec: // _routine_dec
        value.copy< sp<Routine> > (that.value);
        break;

      case symbol_kind::S__routine: // _routine
        value.copy< sp<RoutineCall>  > (that.value);
        break;

      case symbol_kind::S__statement: // _statement
      case symbol_kind::S__while: // _while
      case symbol_kind::S__for: // _for
      case symbol_kind::S__if: // _if
        value.copy< sp<Statement> > (that.value);
        break;

      case symbol_kind::S__type: // _type
        value.copy< sp<Type> > (that.value);
        break;

      case symbol_kind::S__var_dec: // _var_dec
      case symbol_kind::S__param_dec: // _param_dec
        value.copy< sp<Variable> > (that.value);
        break;

      case symbol_kind::S__args: // _args
        value.copy< spv<Expression> > (that.value);
        break;

      case symbol_kind::S__params: // _params
      case symbol_kind::S__var_dec_block: // _var_dec_block
        value.copy< spv<Variable> > (that.value);
        break;

      case symbol_kind::S_tkIdentifier: // tkIdentifier
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S__range: // _range
        value.copy< std::tuple<sp<Expression>, sp<Expression>, bool> > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_tkConstBoolean: // tkConstBoolean
        value.move< bool > (that.value);
        break;

      case symbol_kind::S_tkConstReal: // tkConstReal
        value.move< double > (that.value);
        break;

      case symbol_kind::S_tkConstInt: // tkConstInt
        value.move< int > (that.value);
        break;

      case symbol_kind::S__arr_type: // _arr_type
        value.move< sp<Array> > (that.value);
        break;

      case symbol_kind::S__assign: // _assign
        value.move< sp<Assignment> > (that.value);
        break;

      case symbol_kind::S__body: // _body
        value.move< sp<Block> > (that.value);
        break;

      case symbol_kind::S__irb_type: // _irb_type
        value.move< sp<BuiltinType> > (that.value);
        break;

      case symbol_kind::S__expr: // _expr
      case symbol_kind::S__primary: // _primary
      case symbol_kind::S__getvar: // _getvar
      case symbol_kind::S__modval: // _modval
        value.move< sp<Expression> > (that.value);
        break;

      case symbol_kind::S__rec_type: // _rec_type
        value.move< sp<Record> > (that.value);
        break;

      case symbol_kind::S__return: // _return
        value.move< sp<ReturnStatement> > (that.value);
        break;

      case symbol_kind::S__routine_dec: // _routine_dec
        value.move< sp<Routine> > (that.value);
        break;

      case symbol_kind::S__routine: // _routine
        value.move< sp<RoutineCall>  > (that.value);
        break;

      case symbol_kind::S__statement: // _statement
      case symbol_kind::S__while: // _while
      case symbol_kind::S__for: // _for
      case symbol_kind::S__if: // _if
        value.move< sp<Statement> > (that.value);
        break;

      case symbol_kind::S__type: // _type
        value.move< sp<Type> > (that.value);
        break;

      case symbol_kind::S__var_dec: // _var_dec
      case symbol_kind::S__param_dec: // _param_dec
        value.move< sp<Variable> > (that.value);
        break;

      case symbol_kind::S__args: // _args
        value.move< spv<Expression> > (that.value);
        break;

      case symbol_kind::S__params: // _params
      case symbol_kind::S__var_dec_block: // _var_dec_block
        value.move< spv<Variable> > (that.value);
        break;

      case symbol_kind::S_tkIdentifier: // tkIdentifier
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S__range: // _range
        value.move< std::tuple<sp<Expression>, sp<Expression>, bool> > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_tkConstBoolean: // tkConstBoolean
        yylhs.value.emplace< bool > ();
        break;

      case symbol_kind::S_tkConstReal: // tkConstReal
        yylhs.value.emplace< double > ();
        break;

      case symbol_kind::S_tkConstInt: // tkConstInt
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S__arr_type: // _arr_type
        yylhs.value.emplace< sp<Array> > ();
        break;

      case symbol_kind::S__assign: // _assign
        yylhs.value.emplace< sp<Assignment> > ();
        break;

      case symbol_kind::S__body: // _body
        yylhs.value.emplace< sp<Block> > ();
        break;

      case symbol_kind::S__irb_type: // _irb_type
        yylhs.value.emplace< sp<BuiltinType> > ();
        break;

      case symbol_kind::S__expr: // _expr
      case symbol_kind::S__primary: // _primary
      case symbol_kind::S__getvar: // _getvar
      case symbol_kind::S__modval: // _modval
        yylhs.value.emplace< sp<Expression> > ();
        break;

      case symbol_kind::S__rec_type: // _rec_type
        yylhs.value.emplace< sp<Record> > ();
        break;

      case symbol_kind::S__return: // _return
        yylhs.value.emplace< sp<ReturnStatement> > ();
        break;

      case symbol_kind::S__routine_dec: // _routine_dec
        yylhs.value.emplace< sp<Routine> > ();
        break;

      case symbol_kind::S__routine: // _routine
        yylhs.value.emplace< sp<RoutineCall>  > ();
        break;

      case symbol_kind::S__statement: // _statement
      case symbol_kind::S__while: // _while
      case symbol_kind::S__for: // _for
      case symbol_kind::S__if: // _if
        yylhs.value.emplace< sp<Statement> > ();
        break;

      case symbol_kind::S__type: // _type
        yylhs.value.emplace< sp<Type> > ();
        break;

      case symbol_kind::S__var_dec: // _var_dec
      case symbol_kind::S__param_dec: // _param_dec
        yylhs.value.emplace< sp<Variable> > ();
        break;

      case symbol_kind::S__args: // _args
        yylhs.value.emplace< spv<Expression> > ();
        break;

      case symbol_kind::S__params: // _params
      case symbol_kind::S__var_dec_block: // _var_dec_block
        yylhs.value.emplace< spv<Variable> > ();
        break;

      case symbol_kind::S_tkIdentifier: // tkIdentifier
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S__range: // _range
        yylhs.value.emplace< std::tuple<sp<Expression>, sp<Expression>, bool> > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 3: // program: program _var_dec
#line 83 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                   {}
#line 932 "Parser.tab.cpp"
    break;

  case 4: // program: program _type_dec
#line 84 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                    {}
#line 938 "Parser.tab.cpp"
    break;

  case 5: // program: program _routine_dec
#line 85 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                       {}
#line 944 "Parser.tab.cpp"
    break;

  case 7: // _var_dec: tkVar tkIdentifier tkColon _type
#line 92 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                                            {std::cout << "Made new variable "<< yystack_[2].value.as < std::string > ();}
#line 950 "Parser.tab.cpp"
    break;

  case 8: // _var_dec: tkVar tkIdentifier tkColon _type tkIs _expr
#line 93 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                                              {std::cout << "Made new variable "<< yystack_[4].value.as < std::string > () <<" with val: ";}
#line 956 "Parser.tab.cpp"
    break;

  case 9: // _type_dec: tkType tkIdentifier tkIs _type
#line 96 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                                          {std::cout << "get type with ident:"<<yystack_[2].value.as < std::string > ();}
#line 962 "Parser.tab.cpp"
    break;

  case 10: // _routine_dec: tkRoutine tkIdentifier tkROUND_BRACKET_START _params tkROUND_BRACKET_END tkIs _body tkEnd
#line 99 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                                                                                                        {}
#line 968 "Parser.tab.cpp"
    break;

  case 11: // _routine_dec: tkRoutine tkIdentifier tkROUND_BRACKET_START _params tkROUND_BRACKET_END tkColon _type tkIs _body tkEnd
#line 100 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                                                                                                          {}
#line 974 "Parser.tab.cpp"
    break;

  case 12: // _params: _param_dec
#line 103 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                    {}
#line 980 "Parser.tab.cpp"
    break;

  case 13: // _params: _params tkComma _param_dec
#line 104 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                             {}
#line 986 "Parser.tab.cpp"
    break;

  case 14: // _param_dec: tkIdentifier tkColon _type
#line 107 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                                       {}
#line 992 "Parser.tab.cpp"
    break;

  case 15: // _type: tkIdentifier
#line 110 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                    {}
#line 998 "Parser.tab.cpp"
    break;

  case 16: // _type: _irb_type
#line 111 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
            {}
#line 1004 "Parser.tab.cpp"
    break;

  case 17: // _type: _arr_type
#line 112 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
            {}
#line 1010 "Parser.tab.cpp"
    break;

  case 18: // _type: _rec_type
#line 113 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
            {}
#line 1016 "Parser.tab.cpp"
    break;

  case 19: // _irb_type: tkInt
#line 116 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                 {}
#line 1022 "Parser.tab.cpp"
    break;

  case 20: // _irb_type: tkReal
#line 117 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
         {}
#line 1028 "Parser.tab.cpp"
    break;

  case 21: // _irb_type: tkBoolean
#line 118 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
            {}
#line 1034 "Parser.tab.cpp"
    break;

  case 22: // _rec_type: tkRecord _var_dec_block tkEnd
#line 121 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                                         {}
#line 1040 "Parser.tab.cpp"
    break;

  case 23: // _arr_type: tkArray tkSQUARE_BRACKET_START _expr tkSQUARE_BRACKET_END _type
#line 124 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                                                                           {}
#line 1046 "Parser.tab.cpp"
    break;

  case 24: // _arr_type: tkArray tkSQUARE_BRACKET_START tkSQUARE_BRACKET_END _type
#line 125 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                                                            {}
#line 1052 "Parser.tab.cpp"
    break;

  case 25: // _body: %empty
#line 128 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
       {}
#line 1058 "Parser.tab.cpp"
    break;

  case 26: // _body: _body _var_dec
#line 129 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                 {}
#line 1064 "Parser.tab.cpp"
    break;

  case 27: // _body: _body _type_dec
#line 130 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                  {}
#line 1070 "Parser.tab.cpp"
    break;

  case 28: // _body: _body _statement
#line 131 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                   {}
#line 1076 "Parser.tab.cpp"
    break;

  case 29: // _statement: _assign
#line 133 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                    {}
#line 1082 "Parser.tab.cpp"
    break;

  case 30: // _statement: _routine
#line 134 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
           {}
#line 1088 "Parser.tab.cpp"
    break;

  case 31: // _statement: _while
#line 135 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
         {}
#line 1094 "Parser.tab.cpp"
    break;

  case 32: // _statement: _for
#line 136 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
       {}
#line 1100 "Parser.tab.cpp"
    break;

  case 33: // _statement: _if
#line 137 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
      {}
#line 1106 "Parser.tab.cpp"
    break;

  case 34: // _statement: _return
#line 138 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
          {}
#line 1112 "Parser.tab.cpp"
    break;

  case 35: // _return: tkReturn
#line 141 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                  {}
#line 1118 "Parser.tab.cpp"
    break;

  case 36: // _return: tkReturn _expr
#line 142 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                 {}
#line 1124 "Parser.tab.cpp"
    break;

  case 37: // _assign: _modval tkCOLON_EQUALS _expr
#line 145 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                                      {}
#line 1130 "Parser.tab.cpp"
    break;

  case 38: // _routine: tkIdentifier tkROUND_BRACKET_START _args tkROUND_BRACKET_END
#line 148 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                                                                       {}
#line 1136 "Parser.tab.cpp"
    break;

  case 39: // _while: tkWhile _expr tkLoop _body tkEnd
#line 151 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                                         {}
#line 1142 "Parser.tab.cpp"
    break;

  case 40: // _for: tkFor tkIdentifier _range tkLoop _body tkEnd
#line 154 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                                                   {}
#line 1148 "Parser.tab.cpp"
    break;

  case 41: // _range: tkIn _expr tkDOT_DOT _expr
#line 156 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                                   {}
#line 1154 "Parser.tab.cpp"
    break;

  case 42: // _range: tkIn tkReverse _expr tkDOT_DOT _expr
#line 157 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                                       {}
#line 1160 "Parser.tab.cpp"
    break;

  case 43: // _if: tkIf _expr tkThen _body tkEnd
#line 160 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                                   {}
#line 1166 "Parser.tab.cpp"
    break;

  case 44: // _if: tkIf _expr tkThen _body tkElse _body tkEnd
#line 161 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                                             {}
#line 1172 "Parser.tab.cpp"
    break;

  case 45: // _var_dec_block: %empty
#line 164 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                {}
#line 1178 "Parser.tab.cpp"
    break;

  case 46: // _var_dec_block: _var_dec_block _var_dec
#line 165 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                          {}
#line 1184 "Parser.tab.cpp"
    break;

  case 47: // _var_dec_block: _var_dec_block EOL
#line 166 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                     {}
#line 1190 "Parser.tab.cpp"
    break;

  case 48: // _expr: _primary
#line 169 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                {}
#line 1196 "Parser.tab.cpp"
    break;

  case 49: // _expr: _expr tkPlus _expr
#line 170 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                     {}
#line 1202 "Parser.tab.cpp"
    break;

  case 50: // _expr: _expr tkMinus _expr
#line 171 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                      {}
#line 1208 "Parser.tab.cpp"
    break;

  case 51: // _expr: _expr tkMultiple _expr
#line 172 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                         {}
#line 1214 "Parser.tab.cpp"
    break;

  case 52: // _expr: _expr tkMod _expr
#line 173 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                    {}
#line 1220 "Parser.tab.cpp"
    break;

  case 53: // _expr: _expr tkDivide _expr
#line 174 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                       {}
#line 1226 "Parser.tab.cpp"
    break;

  case 54: // _expr: _expr tkLess _expr
#line 175 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                     {}
#line 1232 "Parser.tab.cpp"
    break;

  case 55: // _expr: _expr tkLessEquals _expr
#line 176 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                           {}
#line 1238 "Parser.tab.cpp"
    break;

  case 56: // _expr: _expr tkGreater _expr
#line 177 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                        {}
#line 1244 "Parser.tab.cpp"
    break;

  case 57: // _expr: _expr tkGreaterEquals _expr
#line 178 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                              {}
#line 1250 "Parser.tab.cpp"
    break;

  case 58: // _expr: _expr tkEquals _expr
#line 179 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                       {}
#line 1256 "Parser.tab.cpp"
    break;

  case 59: // _expr: _expr tkNotEquals _expr
#line 180 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                          {}
#line 1262 "Parser.tab.cpp"
    break;

  case 60: // _expr: _expr tkBoolAnd _expr
#line 181 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                        {}
#line 1268 "Parser.tab.cpp"
    break;

  case 61: // _expr: _expr tkBoolOr _expr
#line 182 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                       {}
#line 1274 "Parser.tab.cpp"
    break;

  case 62: // _expr: _expr tkBoolXor _expr
#line 183 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                        {}
#line 1280 "Parser.tab.cpp"
    break;

  case 63: // _expr: tkROUND_BRACKET_START _expr tkROUND_BRACKET_START
#line 184 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                                                    {}
#line 1286 "Parser.tab.cpp"
    break;

  case 64: // _args: _expr
#line 187 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
             {}
#line 1292 "Parser.tab.cpp"
    break;

  case 65: // _args: _args tkComma _expr
#line 188 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                      {}
#line 1298 "Parser.tab.cpp"
    break;

  case 66: // _primary: tkConstInt
#line 190 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                     {}
#line 1304 "Parser.tab.cpp"
    break;

  case 67: // _primary: tkConstReal
#line 191 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
              {}
#line 1310 "Parser.tab.cpp"
    break;

  case 68: // _primary: tkConstBoolean
#line 192 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                 {}
#line 1316 "Parser.tab.cpp"
    break;

  case 69: // _primary: _modval
#line 193 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
          {}
#line 1322 "Parser.tab.cpp"
    break;

  case 70: // _primary: _routine
#line 194 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
           {}
#line 1328 "Parser.tab.cpp"
    break;

  case 71: // _getvar: %empty
#line 197 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
         {}
#line 1334 "Parser.tab.cpp"
    break;

  case 72: // _getvar: _getvar tkDot tkIdentifier
#line 198 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                             {}
#line 1340 "Parser.tab.cpp"
    break;

  case 73: // _getvar: _getvar tkSQUARE_BRACKET_START _expr tkSQUARE_BRACKET_END
#line 199 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                                                            {}
#line 1346 "Parser.tab.cpp"
    break;

  case 74: // _modval: tkIdentifier _getvar
#line 202 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"
                              {}
#line 1352 "Parser.tab.cpp"
    break;


#line 1356 "Parser.tab.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0









  const signed char parser::yypact_ninf_ = -70;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
     -70,    83,   -70,    -3,     2,     4,   -70,   -70,   -70,   -70,
     -28,    -9,   -17,   410,   410,    28,   -70,   -70,   -70,   -30,
     -70,   -70,    11,   -70,   -70,   -70,   -70,    -1,   -43,   -70,
      -2,     8,    70,   410,    28,   -27,   -70,   -70,   -70,    -7,
     410,    70,   -70,   113,   -70,   -70,   -70,   -70,   -70,   327,
     -70,   -70,   -70,   410,    70,   -41,   -70,    90,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,   410,   166,    15,   327,   -40,    38,    70,   -70,
     372,   344,   361,   350,   350,   350,   350,   383,   383,   -70,
     -70,   -70,   -70,   -70,   -70,    70,   -70,    61,    70,    70,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,    26,
     -70,    70,   -70,   -70,   132,   307,    41,   288,   327,    70,
     174,   327,   -70,   -70,    53,    42,   -70,   327,   -70,   158,
      70,   246,   -70,   207,   -70,   -70,   267,    70,   215,   -70,
     223,    70,   327,   -70,   -70,   327
  };

  const signed char
  parser::yydefact_[] =
  {
       2,     0,     1,     0,     0,     0,     6,     3,     4,     5,
       0,     0,     0,     0,     0,     0,    19,    20,    21,     0,
      45,    15,     7,    16,    18,    17,     9,     0,     0,    12,
       0,     0,     0,     0,     0,     0,    66,    67,    68,    71,
       0,     0,    70,     0,    48,    69,    22,    47,    46,     8,
      14,    13,    25,     0,     0,    74,    24,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    64,     0,     0,     0,    63,
      60,    61,    62,    54,    55,    56,    57,    58,    59,    49,
      50,    51,    52,    53,    23,     0,    10,     0,     0,    35,
      26,    27,    28,    34,    29,    30,    31,    32,    33,     0,
      25,     0,    38,    72,     0,     0,     0,     0,    36,     0,
       0,    65,    73,    25,     0,     0,    25,    37,    11,     0,
       0,     0,    25,     0,    25,    43,     0,     0,     0,    39,
       0,     0,    41,    40,    44,    42
  };

  const signed char
  parser::yypgoto_[] =
  {
     -70,   -70,    10,    85,   -70,   -70,    50,     9,   -70,   -70,
     -70,   -33,   -70,   -70,   -70,   -69,   -70,   -70,   -70,   -70,
     -70,   -32,   -70,   -70,   -70,   -68
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     1,   100,   101,     9,    28,    29,    22,    23,    24,
      25,    73,   102,   103,   104,    42,   106,   107,   125,   108,
      31,    43,    76,    44,    55,    45
  };

  const unsigned char
  parser::yytable_[] =
  {
      49,    36,    37,    38,   105,   109,    52,    34,    77,    57,
     111,     7,    10,    39,    78,    35,     3,    11,   112,    12,
      13,    53,    75,    26,    14,    30,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      15,    48,    50,    27,    32,    46,   114,    33,   110,    56,
      54,   105,   109,   113,    40,    41,    36,    37,    38,    47,
     105,   109,    74,   115,   105,   109,   117,   118,    39,   105,
     109,   105,   109,    36,    37,    38,   116,   120,   119,   121,
     124,    94,   132,     2,    51,    39,     8,   127,     0,     0,
     129,     3,   131,   133,   130,     4,     0,     5,   136,   138,
       0,   140,     0,     0,     0,   142,    58,    59,    60,   145,
      41,     0,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,     0,     0,     0,    41,     0,    58,
      59,    60,     0,     0,     6,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,    79,    58,    59,
      60,     0,     0,     0,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,     3,     0,     0,    72,
       4,     0,     0,    39,     3,     0,     0,     0,     4,     0,
       0,    39,     3,     0,     0,     0,     4,     0,   122,    39,
       0,     0,    95,     0,   134,   135,    97,     0,     0,     0,
      95,    98,    99,    96,    97,     0,     0,     0,    95,    98,
      99,   128,    97,     0,     0,     3,     0,    98,    99,     4,
       0,     0,    39,     3,     0,     0,     0,     4,     0,     0,
      39,     3,     0,     0,     0,     4,     0,     0,    39,     0,
       0,    95,     0,     0,   139,    97,     0,     0,     0,    95,
      98,    99,   143,    97,     0,     0,     0,    95,    98,    99,
     144,    97,    58,    59,    60,     0,    98,    99,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
       0,     0,     0,    58,    59,    60,     0,     0,   137,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,     0,     0,     0,    58,    59,    60,     0,     0,   141,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,     0,    58,    59,    60,     0,     0,   126,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,     0,   123,    58,    59,    60,     0,     0,     0,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      58,     0,    60,     0,     0,     0,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    58,    67,    68,
      69,    70,    71,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    61,    62,    63,    64,     0,
       0,    67,    68,    69,    70,    71,    16,    17,     0,    18,
       0,    19,     0,    20,     0,    21
  };

  const short
  parser::yycheck_[] =
  {
      32,     3,     4,     5,    73,    73,    33,    50,    49,    41,
      50,     1,    15,    15,    55,    58,     8,    15,    58,    15,
      48,    48,    54,    14,    33,    55,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      57,    31,    33,    15,    33,    37,    78,    48,    33,    40,
      57,   120,   120,    15,    56,    57,     3,     4,     5,    51,
     129,   129,    53,    95,   133,   133,    98,    99,    15,   138,
     138,   140,   140,     3,     4,     5,    15,   110,    52,   111,
      39,    72,    40,     0,    34,    15,     1,   119,    -1,    -1,
     123,     8,   124,   126,    41,    12,    -1,    14,   130,   132,
      -1,   134,    -1,    -1,    -1,   137,    16,    17,    18,   141,
      57,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    57,    -1,    16,
      17,    18,    -1,    -1,    51,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,    57,    16,    17,
      18,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    -1,     8,    -1,    -1,    56,
      12,    -1,    -1,    15,     8,    -1,    -1,    -1,    12,    -1,
      -1,    15,     8,    -1,    -1,    -1,    12,    -1,    56,    15,
      -1,    -1,    34,    -1,    36,    37,    38,    -1,    -1,    -1,
      34,    43,    44,    37,    38,    -1,    -1,    -1,    34,    43,
      44,    37,    38,    -1,    -1,     8,    -1,    43,    44,    12,
      -1,    -1,    15,     8,    -1,    -1,    -1,    12,    -1,    -1,
      15,     8,    -1,    -1,    -1,    12,    -1,    -1,    15,    -1,
      -1,    34,    -1,    -1,    37,    38,    -1,    -1,    -1,    34,
      43,    44,    37,    38,    -1,    -1,    -1,    34,    43,    44,
      37,    38,    16,    17,    18,    -1,    43,    44,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    16,    17,    18,    -1,    -1,    42,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    16,    17,    18,    -1,    -1,    42,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    -1,    16,    17,    18,    -1,    -1,    40,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      -1,    -1,    35,    16,    17,    18,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      16,    -1,    18,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    16,    28,    29,
      30,    31,    32,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    22,    23,    24,    25,    -1,
      -1,    28,    29,    30,    31,    32,     6,     7,    -1,     9,
      -1,    11,    -1,    13,    -1,    15
  };

  const signed char
  parser::yystos_[] =
  {
       0,    65,     0,     8,    12,    14,    51,    66,    67,    68,
      15,    15,    15,    48,    33,    57,     6,     7,     9,    11,
      13,    15,    71,    72,    73,    74,    71,    15,    69,    70,
      55,    84,    33,    48,    50,    58,     3,     4,     5,    15,
      56,    57,    79,    85,    87,    89,    37,    51,    66,    85,
      71,    70,    33,    48,    57,    88,    71,    85,    16,    17,
      18,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    56,    75,    71,    85,    86,    49,    55,    57,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    71,    34,    37,    38,    43,    44,
      66,    67,    76,    77,    78,    79,    80,    81,    83,    89,
      33,    50,    58,    15,    85,    85,    15,    85,    85,    52,
      75,    85,    56,    35,    39,    82,    40,    85,    37,    75,
      41,    85,    40,    75,    36,    37,    85,    42,    75,    37,
      75,    42,    85,    37,    37,    85
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    64,    65,    65,    65,    65,    65,    66,    66,    67,
      68,    68,    69,    69,    70,    71,    71,    71,    71,    72,
      72,    72,    73,    74,    74,    75,    75,    75,    75,    76,
      76,    76,    76,    76,    76,    77,    77,    78,    79,    80,
      81,    82,    82,    83,    83,    84,    84,    84,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    86,    86,    87,    87,    87,    87,
      87,    88,    88,    88,    89
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     0,     2,     2,     2,     2,     4,     6,     4,
       8,    10,     1,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     3,     5,     4,     0,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     4,     5,
       6,     4,     5,     5,     7,     0,     2,     2,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     3,     1,     1,     1,     1,
       1,     0,     3,     4,     2
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "tkConstInt",
  "tkConstReal", "tkConstBoolean", "tkInt", "tkReal", "tkVar", "tkBoolean",
  "tkString", "tkArray", "tkType", "tkRecord", "tkRoutine", "tkIdentifier",
  "tkBoolAnd", "tkBoolOr", "tkBoolXor", "tkBoolNot", "tkTrue", "tkFalse",
  "tkLess", "tkLessEquals", "tkGreater", "tkGreaterEquals", "tkEquals",
  "tkNotEquals", "tkPlus", "tkMinus", "tkMultiple", "tkMod", "tkDivide",
  "tkIs", "tkIf", "tkThen", "tkElse", "tkEnd", "tkFor", "tkIn", "tkLoop",
  "tkReverse", "tkDOT_DOT", "tkWhile", "tkReturn", "tkContinue", "tkBreak",
  "tkSemiColon", "tkColon", "tkDot", "tkComma", "EOL", "tkCOLON_EQUALS",
  "tkNewLine", "tkQuote", "tkSQUARE_BRACKET_START", "tkSQUARE_BRACKET_END",
  "tkROUND_BRACKET_START", "tkROUND_BRACKET_END", "tkCURLY_BRACKET_START",
  "tkCURLY_BRACKET_END", "tkBackSlash", "tkSpace", "tkTabulation",
  "$accept", "program", "_var_dec", "_type_dec", "_routine_dec", "_params",
  "_param_dec", "_type", "_irb_type", "_rec_type", "_arr_type", "_body",
  "_statement", "_return", "_assign", "_routine", "_while", "_for",
  "_range", "_if", "_var_dec_block", "_expr", "_args", "_primary",
  "_getvar", "_modval", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    82,    82,    83,    84,    85,    86,    92,    93,    96,
      99,   100,   103,   104,   107,   110,   111,   112,   113,   116,
     117,   118,   121,   124,   125,   128,   129,   130,   131,   133,
     134,   135,   136,   137,   138,   141,   142,   145,   148,   151,
     154,   156,   157,   160,   161,   164,   165,   166,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   187,   188,   190,   191,   192,   193,
     194,   197,   198,   199,   202
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 1818 "Parser.tab.cpp"

#line 205 "/home/dyllas/git/CompilerConstruction/src/Parser/Parser.ypp"

namespace yy
{
    void parser::error(const std::string& msg)
    {
        std::cout <<"Syntax error\n";
    }
}
