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
#line 23 "Parser.ypp"

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
#line 83 "Parser.ypp"
                   {  ourProgram->variables.push_back(yystack_[0].value.as < sp<Variable> > ());  }
#line 932 "Parser.tab.cpp"
    break;

  case 4: // program: program _type_dec
#line 84 "Parser.ypp"
                    {}
#line 938 "Parser.tab.cpp"
    break;

  case 5: // program: program _routine_dec
#line 85 "Parser.ypp"
                       {}
#line 944 "Parser.tab.cpp"
    break;

  case 7: // _var_dec: tkVar tkIdentifier tkColon _type
#line 90 "Parser.ypp"
                                            { yylhs.value.as < sp<Variable> > () = std::make_shared<ast::Variable>(yystack_[2].value.as < std::string > (), yystack_[0].value.as < sp<Type> > ());  }
#line 950 "Parser.tab.cpp"
    break;

  case 8: // _var_dec: tkVar tkIdentifier tkColon _type tkIs _expr
#line 91 "Parser.ypp"
                                              {
    auto temp = std::make_shared<ast::Variable>(yystack_[4].value.as < std::string > (), yystack_[2].value.as < sp<Type> > ());
    temp->value = yystack_[0].value.as < sp<Expression> > ();
    yylhs.value.as < sp<Variable> > () = temp;
}
#line 960 "Parser.tab.cpp"
    break;

  case 9: // _var_dec: tkVar tkIdentifier tkIs _expr
#line 96 "Parser.ypp"
                                {
    ast::Type::TypeTable[yystack_[2].value.as < std::string > ()] = std::make_shared<ast::Type>(ast::Expression::getType(yystack_[0].value.as < sp<Expression> > ()));
    auto temp = std::make_shared<ast::Variable>(yystack_[2].value.as < std::string > (), yystack_[0].value.as < sp<Expression> > (), ast::Type::TypeTable[yystack_[2].value.as < std::string > ()]);
    yylhs.value.as < sp<Variable> > () = temp;
    }
#line 970 "Parser.tab.cpp"
    break;

  case 10: // _type_dec: tkType tkIdentifier tkIs _type
#line 103 "Parser.ypp"
                                          { ast::Type::TypeTable.insert({yystack_[2].value.as < std::string > (),yystack_[0].value.as < sp<Type> > ()}); }
#line 976 "Parser.tab.cpp"
    break;

  case 11: // _routine_dec: tkRoutine tkIdentifier tkROUND_BRACKET_START _params tkROUND_BRACKET_END tkIs _body tkEnd
#line 106 "Parser.ypp"
                                                                                                        {
yylhs.value.as < sp<Routine> > () = std::make_shared<ast::Routine>(yystack_[6].value.as < std::string > (), yystack_[4].value.as < spv<Variable> > (), yystack_[1].value.as < sp<Block> > (), nullptr);
}
#line 984 "Parser.tab.cpp"
    break;

  case 12: // _routine_dec: tkRoutine tkIdentifier tkROUND_BRACKET_START _params tkROUND_BRACKET_END tkColon _type tkIs _body tkEnd
#line 109 "Parser.ypp"
                                                                                                          {
 yylhs.value.as < sp<Routine> > () = std::make_shared<ast::Routine>(yystack_[8].value.as < std::string > (), yystack_[6].value.as < spv<Variable> > (), yystack_[1].value.as < sp<Block> > (), yystack_[3].value.as < sp<Type> > ());
 ast::Type::TypeTable[yystack_[8].value.as < std::string > ()] = yystack_[3].value.as < sp<Type> > ();
}
#line 993 "Parser.tab.cpp"
    break;

  case 13: // _params: _param_dec
#line 115 "Parser.ypp"
                    { (yylhs.value.as < spv<Variable> > ()).push_back(yystack_[0].value.as < sp<Variable> > ()); }
#line 999 "Parser.tab.cpp"
    break;

  case 14: // _params: _params tkComma _param_dec
#line 116 "Parser.ypp"
                             { swap(yystack_[2].value.as < spv<Variable> > (), yylhs.value.as < spv<Variable> > ());  (yylhs.value.as < spv<Variable> > ()).push_back(yystack_[0].value.as < sp<Variable> > ()); }
#line 1005 "Parser.tab.cpp"
    break;

  case 15: // _param_dec: tkIdentifier tkColon _type
#line 119 "Parser.ypp"
                                       { yylhs.value.as < sp<Variable> > () = std::make_shared<ast::Variable>(yystack_[2].value.as < std::string > (), yystack_[0].value.as < sp<Type> > ()); }
#line 1011 "Parser.tab.cpp"
    break;

  case 16: // _param_dec: %empty
#line 120 "Parser.ypp"
  {}
#line 1017 "Parser.tab.cpp"
    break;

  case 17: // _type: tkIdentifier
#line 123 "Parser.ypp"
                    { yylhs.value.as < sp<Type> > () = std::make_shared<ast::Type>(yystack_[0].value.as < std::string > ()); }
#line 1023 "Parser.tab.cpp"
    break;

  case 18: // _type: _irb_type
#line 124 "Parser.ypp"
            {  yylhs.value.as < sp<Type> > () = yystack_[0].value.as < sp<BuiltinType> > (); }
#line 1029 "Parser.tab.cpp"
    break;

  case 19: // _type: _arr_type
#line 125 "Parser.ypp"
            { yylhs.value.as < sp<Type> > () = yystack_[0].value.as < sp<Array> > (); }
#line 1035 "Parser.tab.cpp"
    break;

  case 20: // _type: _rec_type
#line 126 "Parser.ypp"
            { yylhs.value.as < sp<Type> > () = yystack_[0].value.as < sp<Record> > (); }
#line 1041 "Parser.tab.cpp"
    break;

  case 21: // _irb_type: tkInt
#line 129 "Parser.ypp"
                 { yylhs.value.as < sp<BuiltinType> > () = std::make_shared<ast::BuiltinType>("integer"); }
#line 1047 "Parser.tab.cpp"
    break;

  case 22: // _irb_type: tkReal
#line 130 "Parser.ypp"
         {  yylhs.value.as < sp<BuiltinType> > () =  std::make_shared<ast::BuiltinType> ("real"); }
#line 1053 "Parser.tab.cpp"
    break;

  case 23: // _irb_type: tkBoolean
#line 131 "Parser.ypp"
            {   yylhs.value.as < sp<BuiltinType> > () =  std::make_shared<ast::BuiltinType> ("boolean"); }
#line 1059 "Parser.tab.cpp"
    break;

  case 24: // _rec_type: tkRecord _var_dec_block tkEnd
#line 134 "Parser.ypp"
                                         {  yylhs.value.as < sp<Record> > () = std::make_shared<ast::Record>("Record", yystack_[1].value.as < spv<Variable> > ()); }
#line 1065 "Parser.tab.cpp"
    break;

  case 25: // _arr_type: tkArray tkSQUARE_BRACKET_START _expr tkSQUARE_BRACKET_END _type
#line 137 "Parser.ypp"
                                                                           { yylhs.value.as < sp<Array> > () = std::make_shared<ast::Array>("Array"); }
#line 1071 "Parser.tab.cpp"
    break;

  case 26: // _arr_type: tkArray tkSQUARE_BRACKET_START tkSQUARE_BRACKET_END _type
#line 138 "Parser.ypp"
                                                            { yylhs.value.as < sp<Array> > () = std::make_shared<ast::Array>("Array"); }
#line 1077 "Parser.tab.cpp"
    break;

  case 27: // _body: %empty
#line 141 "Parser.ypp"
       { yylhs.value.as < sp<Block> > () = std::make_shared<ast::Block>(); }
#line 1083 "Parser.tab.cpp"
    break;

  case 28: // _body: _body _var_dec
#line 142 "Parser.ypp"
                 { (yystack_[1].value.as < sp<Block> > ())->addVariable(yystack_[0].value.as < sp<Variable> > ()); yylhs.value.as < sp<Block> > () = yystack_[1].value.as < sp<Block> > (); }
#line 1089 "Parser.tab.cpp"
    break;

  case 29: // _body: _body _type_dec
#line 143 "Parser.ypp"
                  {}
#line 1095 "Parser.tab.cpp"
    break;

  case 30: // _body: _body _statement
#line 144 "Parser.ypp"
                   { (yystack_[1].value.as < sp<Block> > ())->addStatement(yystack_[0].value.as < sp<Statement> > ()); yylhs.value.as < sp<Block> > () = yystack_[1].value.as < sp<Block> > (); }
#line 1101 "Parser.tab.cpp"
    break;

  case 31: // _body: _body EOL
#line 145 "Parser.ypp"
  { yylhs.value.as < sp<Block> > () = yystack_[1].value.as < sp<Block> > (); }
#line 1107 "Parser.tab.cpp"
    break;

  case 32: // _statement: _assign
#line 148 "Parser.ypp"
                    {yylhs.value.as < sp<Statement> > () = yystack_[0].value.as < sp<Assignment> > ();}
#line 1113 "Parser.tab.cpp"
    break;

  case 33: // _statement: _routine
#line 149 "Parser.ypp"
           {yylhs.value.as < sp<Statement> > () = yystack_[0].value.as < sp<RoutineCall>  > ();}
#line 1119 "Parser.tab.cpp"
    break;

  case 34: // _statement: _while
#line 150 "Parser.ypp"
         {yylhs.value.as < sp<Statement> > () = yystack_[0].value.as < sp<Statement> > ();}
#line 1125 "Parser.tab.cpp"
    break;

  case 35: // _statement: _for
#line 151 "Parser.ypp"
       {yylhs.value.as < sp<Statement> > () = yystack_[0].value.as < sp<Statement> > ();}
#line 1131 "Parser.tab.cpp"
    break;

  case 36: // _statement: _if
#line 152 "Parser.ypp"
      {yylhs.value.as < sp<Statement> > () = yystack_[0].value.as < sp<Statement> > ();}
#line 1137 "Parser.tab.cpp"
    break;

  case 37: // _statement: _return
#line 153 "Parser.ypp"
          {yylhs.value.as < sp<Statement> > () = yystack_[0].value.as < sp<ReturnStatement> > ();}
#line 1143 "Parser.tab.cpp"
    break;

  case 38: // _return: tkReturn EOL
#line 156 "Parser.ypp"
                     {   yylhs.value.as < sp<ReturnStatement> > () = std::make_shared<ast::ReturnStatement>(nullptr);  }
#line 1149 "Parser.tab.cpp"
    break;

  case 39: // _return: tkReturn _expr
#line 157 "Parser.ypp"
                 {     yylhs.value.as < sp<ReturnStatement> > () = std::make_shared<ast::ReturnStatement>(yystack_[0].value.as < sp<Expression> > ());   }
#line 1155 "Parser.tab.cpp"
    break;

  case 40: // _assign: _modval tkCOLON_EQUALS _expr
#line 160 "Parser.ypp"
                                      { yylhs.value.as < sp<Assignment> > () = std::make_shared<ast::Assignment>(std::get<0>((yystack_[2].value.as < sp<Expression> > ())->value), yystack_[0].value.as < sp<Expression> > ()); }
#line 1161 "Parser.tab.cpp"
    break;

  case 41: // _routine: tkIdentifier tkROUND_BRACKET_START _args tkROUND_BRACKET_END
#line 163 "Parser.ypp"
                                                                       { yylhs.value.as < sp<RoutineCall>  > () = std::make_shared<ast::RoutineCall>(yystack_[3].value.as < std::string > ()); (yylhs.value.as < sp<RoutineCall>  > ())->args = std::move(yystack_[1].value.as < spv<Expression> > ()); }
#line 1167 "Parser.tab.cpp"
    break;

  case 42: // _while: tkWhile _expr tkLoop _body tkEnd
#line 166 "Parser.ypp"
                                         { yylhs.value.as < sp<Statement> > () = std::make_shared<ast::WhileLoop>(yystack_[3].value.as < sp<Expression> > (), yystack_[1].value.as < sp<Block> > ()); }
#line 1173 "Parser.tab.cpp"
    break;

  case 43: // _for: tkFor tkIdentifier _range tkLoop _body tkEnd
#line 169 "Parser.ypp"
                                                   { yylhs.value.as < sp<Statement> > () = std::make_shared<ast::ForLoop>(yystack_[4].value.as < std::string > (), yystack_[3].value.as < std::tuple<sp<Expression>, sp<Expression>, bool> > (), yystack_[1].value.as < sp<Block> > ()); }
#line 1179 "Parser.tab.cpp"
    break;

  case 44: // _range: tkIn _expr tkDOT_DOT _expr
#line 171 "Parser.ypp"
                                   { yylhs.value.as < std::tuple<sp<Expression>, sp<Expression>, bool> > () = std::make_tuple(yystack_[2].value.as < sp<Expression> > (),yystack_[0].value.as < sp<Expression> > (), false);  }
#line 1185 "Parser.tab.cpp"
    break;

  case 45: // _range: tkIn tkReverse _expr tkDOT_DOT _expr
#line 172 "Parser.ypp"
                                       { yylhs.value.as < std::tuple<sp<Expression>, sp<Expression>, bool> > () = std::make_tuple(yystack_[2].value.as < sp<Expression> > (),yystack_[0].value.as < sp<Expression> > (), true); }
#line 1191 "Parser.tab.cpp"
    break;

  case 46: // _if: tkIf _expr tkThen _body tkEnd
#line 175 "Parser.ypp"
                                   { yylhs.value.as < sp<Statement> > () = std::make_shared<ast::IfStatement>(yystack_[3].value.as < sp<Expression> > (), yystack_[1].value.as < sp<Block> > (), nullptr); }
#line 1197 "Parser.tab.cpp"
    break;

  case 47: // _if: tkIf _expr tkThen _body EOL tkElse _body tkEnd
#line 176 "Parser.ypp"
                                                 { yylhs.value.as < sp<Statement> > () = std::make_shared<ast::IfStatement>(yystack_[6].value.as < sp<Expression> > (), yystack_[4].value.as < sp<Block> > (), yystack_[1].value.as < sp<Block> > ()); }
#line 1203 "Parser.tab.cpp"
    break;

  case 48: // _var_dec_block: %empty
#line 179 "Parser.ypp"
                {}
#line 1209 "Parser.tab.cpp"
    break;

  case 49: // _var_dec_block: _var_dec_block _var_dec
#line 180 "Parser.ypp"
                          { swap(yystack_[1].value.as < spv<Variable> > (),yylhs.value.as < spv<Variable> > ()); (yylhs.value.as < spv<Variable> > ()).push_back(yystack_[0].value.as < sp<Variable> > ()); }
#line 1215 "Parser.tab.cpp"
    break;

  case 50: // _var_dec_block: _var_dec_block EOL
#line 181 "Parser.ypp"
                     { swap(yystack_[1].value.as < spv<Variable> > (),yylhs.value.as < spv<Variable> > ()); }
#line 1221 "Parser.tab.cpp"
    break;

  case 51: // _expr: _primary
#line 184 "Parser.ypp"
                { yylhs.value.as < sp<Expression> > () = yystack_[0].value.as < sp<Expression> > ();}
#line 1227 "Parser.tab.cpp"
    break;

  case 52: // _expr: _expr tkPlus _expr
#line 185 "Parser.ypp"
                     { yylhs.value.as < sp<Expression> > () = std::make_shared<ast::Expression>("+", yystack_[2].value.as < sp<Expression> > (), yystack_[0].value.as < sp<Expression> > ());}
#line 1233 "Parser.tab.cpp"
    break;

  case 53: // _expr: _expr tkMinus _expr
#line 186 "Parser.ypp"
                      {  yylhs.value.as < sp<Expression> > () = std::make_shared<ast::Expression>("-", yystack_[2].value.as < sp<Expression> > (), yystack_[0].value.as < sp<Expression> > ()); }
#line 1239 "Parser.tab.cpp"
    break;

  case 54: // _expr: _expr tkMultiple _expr
#line 187 "Parser.ypp"
                         { yylhs.value.as < sp<Expression> > () = std::make_shared<ast::Expression>("*", yystack_[2].value.as < sp<Expression> > (), yystack_[0].value.as < sp<Expression> > ()); }
#line 1245 "Parser.tab.cpp"
    break;

  case 55: // _expr: _expr tkMod _expr
#line 188 "Parser.ypp"
                    { yylhs.value.as < sp<Expression> > () = std::make_shared<ast::Expression>("%", yystack_[2].value.as < sp<Expression> > (), yystack_[0].value.as < sp<Expression> > ()); }
#line 1251 "Parser.tab.cpp"
    break;

  case 56: // _expr: _expr tkDivide _expr
#line 189 "Parser.ypp"
                       { yylhs.value.as < sp<Expression> > () = std::make_shared<ast::Expression>("/", yystack_[2].value.as < sp<Expression> > (), yystack_[0].value.as < sp<Expression> > ()); }
#line 1257 "Parser.tab.cpp"
    break;

  case 57: // _expr: _expr tkLess _expr
#line 190 "Parser.ypp"
                     {  yylhs.value.as < sp<Expression> > () = std::make_shared<ast::Expression>("<", yystack_[2].value.as < sp<Expression> > (), yystack_[0].value.as < sp<Expression> > ()); }
#line 1263 "Parser.tab.cpp"
    break;

  case 58: // _expr: _expr tkLessEquals _expr
#line 191 "Parser.ypp"
                           {  yylhs.value.as < sp<Expression> > () = std::make_shared<ast::Expression>("<=", yystack_[2].value.as < sp<Expression> > (), yystack_[0].value.as < sp<Expression> > ()); }
#line 1269 "Parser.tab.cpp"
    break;

  case 59: // _expr: _expr tkGreater _expr
#line 192 "Parser.ypp"
                        {  yylhs.value.as < sp<Expression> > () = std::make_shared<ast::Expression>(">", yystack_[2].value.as < sp<Expression> > (), yystack_[0].value.as < sp<Expression> > ()); }
#line 1275 "Parser.tab.cpp"
    break;

  case 60: // _expr: _expr tkGreaterEquals _expr
#line 193 "Parser.ypp"
                              {  yylhs.value.as < sp<Expression> > () = std::make_shared<ast::Expression>(">=", yystack_[2].value.as < sp<Expression> > (), yystack_[0].value.as < sp<Expression> > ()); }
#line 1281 "Parser.tab.cpp"
    break;

  case 61: // _expr: _expr tkEquals _expr
#line 194 "Parser.ypp"
                       {  yylhs.value.as < sp<Expression> > () = std::make_shared<ast::Expression>("=", yystack_[2].value.as < sp<Expression> > (), yystack_[0].value.as < sp<Expression> > ()); }
#line 1287 "Parser.tab.cpp"
    break;

  case 62: // _expr: _expr tkNotEquals _expr
#line 195 "Parser.ypp"
                          {  yylhs.value.as < sp<Expression> > () = std::make_shared<ast::Expression>("/=", yystack_[2].value.as < sp<Expression> > (), yystack_[0].value.as < sp<Expression> > ()); }
#line 1293 "Parser.tab.cpp"
    break;

  case 63: // _expr: _expr tkBoolAnd _expr
#line 196 "Parser.ypp"
                        { yylhs.value.as < sp<Expression> > () = std::make_shared<ast::Expression>("and", yystack_[2].value.as < sp<Expression> > (), yystack_[0].value.as < sp<Expression> > ()); }
#line 1299 "Parser.tab.cpp"
    break;

  case 64: // _expr: _expr tkBoolOr _expr
#line 197 "Parser.ypp"
                       { yylhs.value.as < sp<Expression> > () = std::make_shared<ast::Expression>("or", yystack_[2].value.as < sp<Expression> > (), yystack_[0].value.as < sp<Expression> > ()); }
#line 1305 "Parser.tab.cpp"
    break;

  case 65: // _expr: _expr tkBoolXor _expr
#line 198 "Parser.ypp"
                        { yylhs.value.as < sp<Expression> > () = std::make_shared<ast::Expression>("xor", yystack_[2].value.as < sp<Expression> > (), yystack_[0].value.as < sp<Expression> > ()); }
#line 1311 "Parser.tab.cpp"
    break;

  case 66: // _expr: tkROUND_BRACKET_START _expr tkROUND_BRACKET_START
#line 199 "Parser.ypp"
                                                    {  yylhs.value.as < sp<Expression> > () = yystack_[1].value.as < sp<Expression> > (); }
#line 1317 "Parser.tab.cpp"
    break;

  case 67: // _args: _expr
#line 202 "Parser.ypp"
             { (yylhs.value.as < spv<Expression> > ()).push_back(yystack_[0].value.as < sp<Expression> > ()); }
#line 1323 "Parser.tab.cpp"
    break;

  case 68: // _args: _args tkComma _expr
#line 203 "Parser.ypp"
                      { swap(yylhs.value.as < spv<Expression> > (),yystack_[2].value.as < spv<Expression> > ()); (yylhs.value.as < spv<Expression> > ()).push_back(yystack_[0].value.as < sp<Expression> > ()); }
#line 1329 "Parser.tab.cpp"
    break;

  case 69: // _primary: tkConstInt
#line 205 "Parser.ypp"
                     {   yylhs.value.as < sp<Expression> > () = std::make_shared<ast::Expression>(yystack_[0].value.as < int > (), false);  }
#line 1335 "Parser.tab.cpp"
    break;

  case 70: // _primary: tkConstReal
#line 206 "Parser.ypp"
              {yylhs.value.as < sp<Expression> > () = std::make_shared<ast::Expression>(yystack_[0].value.as < double > ()); }
#line 1341 "Parser.tab.cpp"
    break;

  case 71: // _primary: tkConstBoolean
#line 207 "Parser.ypp"
                 {yylhs.value.as < sp<Expression> > () = std::make_shared<ast::Expression>(yystack_[0].value.as < bool > ()); }
#line 1347 "Parser.tab.cpp"
    break;

  case 72: // _primary: _modval
#line 208 "Parser.ypp"
          {  yylhs.value.as < sp<Expression> > () = yystack_[0].value.as < sp<Expression> > ();}
#line 1353 "Parser.tab.cpp"
    break;

  case 73: // _primary: _routine
#line 209 "Parser.ypp"
           { yylhs.value.as < sp<Expression> > () = std::make_shared<ast::Expression>((yystack_[0].value.as < sp<RoutineCall>  > ())->name); }
#line 1359 "Parser.tab.cpp"
    break;

  case 74: // _getvar: %empty
#line 212 "Parser.ypp"
         {yylhs.value.as < sp<Expression> > () = nullptr;}
#line 1365 "Parser.tab.cpp"
    break;

  case 75: // _getvar: _getvar tkDot tkIdentifier
#line 213 "Parser.ypp"
                             {
sp<ast::Expression> temp = std::make_shared<ast::Expression>(yystack_[0].value.as < std::string > ());
yylhs.value.as < sp<Expression> > () = std::make_shared<ast::Expression>(".",temp, yystack_[2].value.as < sp<Expression> > ());
}
#line 1374 "Parser.tab.cpp"
    break;

  case 76: // _getvar: _getvar tkSQUARE_BRACKET_START _expr tkSQUARE_BRACKET_END
#line 217 "Parser.ypp"
                                                            {
yylhs.value.as < sp<Expression> > () = std::make_shared<ast::Expression>(".",yystack_[1].value.as < sp<Expression> > (), yystack_[3].value.as < sp<Expression> > (), true);
}
#line 1382 "Parser.tab.cpp"
    break;

  case 77: // _modval: tkIdentifier _getvar
#line 224 "Parser.ypp"
                              {

sp<ast::Expression> temp = std::make_shared<ast::Expression>(yystack_[1].value.as < std::string > ());
if(yystack_[0].value.as < sp<Expression> > () != nullptr)
  yylhs.value.as < sp<Expression> > () = std::make_shared<ast::Expression>(".",temp, yystack_[0].value.as < sp<Expression> > ());
else
  yylhs.value.as < sp<Expression> > () = temp;

}
#line 1396 "Parser.tab.cpp"
    break;


#line 1400 "Parser.tab.cpp"

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









  const signed char parser::yypact_ninf_ = -46;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
     -46,    58,   -46,    -8,    -2,    -1,   -46,   -46,   -46,   -46,
     -27,   -16,   -17,    45,   112,   112,    28,   -46,   -46,   -46,
     -12,    45,   -46,   348,   -46,   -46,   -46,   -46,   -46,     9,
     -46,   -46,    21,   -46,   -46,   -46,   -46,    17,   -41,   -46,
      45,   -36,   213,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,     0,   104,    45,
     112,    28,     4,   348,     8,    52,    45,   -46,   393,   365,
     382,   133,   133,   133,   133,   404,   404,   -46,   -46,   -46,
     -46,   -46,   112,   230,   -46,   -46,   -46,   348,   -46,   -46,
     -46,   112,    45,   -46,   -46,   248,   -46,   112,    94,    36,
     348,   -46,   -46,    45,   -46,    59,    45,    37,   -46,   -46,
     -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,    22,   -46,
     328,    39,   309,   -46,   348,    45,   102,   -46,     6,    35,
     -46,   348,   -46,   135,    45,   265,   -46,   143,   -46,    40,
     288,    45,   176,   -46,   -46,    45,   348,   -46,   184,   348,
     -46
  };

  const signed char
  parser::yydefact_[] =
  {
       2,     0,     1,     0,     0,     0,     6,     3,     4,     5,
       0,     0,     0,     0,     0,     0,    16,    69,    70,    71,
      74,     0,    73,     9,    51,    72,    21,    22,    23,     0,
      48,    17,     7,    18,    20,    19,    10,     0,     0,    13,
       0,    77,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    16,     0,    67,     0,     0,     0,    66,    63,    64,
      65,    57,    58,    59,    60,    61,    62,    52,    53,    54,
      55,    56,     0,     0,    24,    50,    49,     8,    15,    14,
      27,     0,     0,    41,    75,     0,    26,     0,     0,     0,
      68,    76,    25,     0,    11,     0,     0,     0,    31,    28,
      29,    30,    37,    32,    33,    34,    35,    36,     0,    27,
       0,     0,     0,    38,    39,     0,     0,    27,     0,     0,
      27,    40,    12,     0,     0,     0,    27,     0,    46,    31,
       0,     0,     0,    42,    27,     0,    44,    43,     0,    45,
      47
  };

  const signed char
  parser::yypgoto_[] =
  {
     -46,   -46,     1,    78,   -46,   -46,    19,   -14,   -46,   -46,
     -46,    30,   -46,   -46,   -46,   -45,   -46,   -46,   -46,   -46,
     -46,   -21,   -46,   -46,   -46,   -37
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     1,   109,   110,     9,    38,    39,    32,    33,    34,
      35,    98,   111,   112,   113,    22,   115,   116,   129,   117,
      58,    23,    64,    24,    41,    25
  };

  const unsigned char
  parser::yytable_[] =
  {
      42,    36,     7,    17,    18,    19,    13,    10,    61,    17,
      18,    19,    65,    11,    12,    20,    62,    15,    66,    63,
      14,    20,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    83,    90,    87,    16,
      17,    18,    19,    37,    40,    95,    88,   134,    17,    18,
      19,    91,    20,   114,    59,    82,    21,    92,     2,    86,
      20,   118,    21,    57,    60,    93,     3,    94,    96,   119,
       4,   100,     5,   125,   121,   136,   144,    99,   128,     8,
      89,   114,   120,   102,     0,   122,   124,   123,   114,   118,
       0,     0,   114,    21,     0,     0,   118,   114,     0,     0,
     118,    21,     3,   114,   131,   118,     4,   135,     6,    20,
       3,   118,     3,   140,     4,     0,     0,    20,    26,    27,
     146,    28,     0,    29,   149,    30,     0,    31,   103,     0,
       0,   104,   105,     0,     0,     0,   103,   106,   107,   132,
     105,    84,     0,     3,   108,   106,   107,     4,     0,   126,
      20,     3,   108,     0,    85,     4,     0,   133,    20,     0,
     137,    52,    53,    54,    55,    56,   142,     0,     0,   103,
       0,     0,   138,   105,   148,     0,     0,   103,   106,   107,
     143,   105,     0,     0,     3,   139,   106,   107,     4,     0,
       0,    20,     3,   108,     0,     0,     4,     0,     0,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     103,     0,     0,   147,   105,     0,     0,     0,   103,   106,
     107,   150,   105,     0,     0,     0,   108,   106,   107,    43,
      44,    45,     0,     0,   108,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    43,    44,    45,     0,
       0,     0,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,     0,    43,    44,    45,     0,     0,    67,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    43,    44,    45,     0,    97,     0,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,     0,     0,
       0,     0,     0,   101,    43,    44,    45,   141,     0,     0,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,     0,     0,     0,     0,    43,    44,    45,     0,     0,
     145,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,     0,     0,    43,    44,    45,     0,     0,   130,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,     0,     0,   127,    43,    44,    45,     0,     0,     0,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    43,     0,    45,     0,     0,     0,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    43,     0,
       0,     0,     0,     0,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    46,    47,    48,    49,
       0,     0,    52,    53,    54,    55,    56
  };

  const short
  parser::yycheck_[] =
  {
      21,    15,     1,     3,     4,     5,    33,    15,    49,     3,
       4,     5,    48,    15,    15,    15,    57,    33,    54,    40,
      47,    15,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    33,    59,    56,
       3,     4,     5,    15,    56,    66,    60,    41,     3,     4,
       5,    47,    15,    98,    33,    55,    56,    49,     0,    58,
      15,    98,    56,    54,    47,    57,     8,    15,    82,    33,
      12,    92,    14,    51,    15,    40,    36,    91,    39,     1,
      61,   126,   103,    97,    -1,   106,   107,    50,   133,   126,
      -1,    -1,   137,    56,    -1,    -1,   133,   142,    -1,    -1,
     137,    56,     8,   148,   125,   142,    12,   128,    50,    15,
       8,   148,     8,   134,    12,    -1,    -1,    15,     6,     7,
     141,     9,    -1,    11,   145,    13,    -1,    15,    34,    -1,
      -1,    37,    38,    -1,    -1,    -1,    34,    43,    44,    37,
      38,    37,    -1,     8,    50,    43,    44,    12,    -1,   119,
      15,     8,    50,    -1,    50,    12,    -1,   127,    15,    -1,
     130,    28,    29,    30,    31,    32,   136,    -1,    -1,    34,
      -1,    -1,    37,    38,   144,    -1,    -1,    34,    43,    44,
      37,    38,    -1,    -1,     8,    50,    43,    44,    12,    -1,
      -1,    15,     8,    50,    -1,    -1,    12,    -1,    -1,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    -1,    -1,    37,    38,    -1,    -1,    -1,    34,    43,
      44,    37,    38,    -1,    -1,    -1,    50,    43,    44,    16,
      17,    18,    -1,    -1,    50,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    16,    17,    18,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    -1,    16,    17,    18,    -1,    -1,    56,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    16,    17,    18,    -1,    55,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    55,    16,    17,    18,    42,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    16,    17,    18,    -1,    -1,
      42,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    -1,    16,    17,    18,    -1,    -1,    40,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    -1,    35,    16,    17,    18,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    16,    -1,    18,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    16,    -1,
      -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    22,    23,    24,    25,
      -1,    -1,    28,    29,    30,    31,    32
  };

  const signed char
  parser::yystos_[] =
  {
       0,    64,     0,     8,    12,    14,    50,    65,    66,    67,
      15,    15,    15,    33,    47,    33,    56,     3,     4,     5,
      15,    56,    78,    84,    86,    88,     6,     7,     9,    11,
      13,    15,    70,    71,    72,    73,    70,    15,    68,    69,
      56,    87,    84,    16,    17,    18,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    54,    83,    33,
      47,    49,    57,    84,    85,    48,    54,    56,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    55,    84,    37,    50,    65,    84,    70,    69,
      33,    47,    49,    57,    15,    84,    70,    55,    74,    70,
      84,    55,    70,    34,    37,    38,    43,    44,    50,    65,
      66,    75,    76,    77,    78,    79,    80,    82,    88,    33,
      84,    15,    84,    50,    84,    51,    74,    35,    39,    81,
      40,    84,    37,    74,    41,    84,    40,    74,    37,    50,
      84,    42,    74,    37,    36,    42,    84,    37,    74,    84,
      37
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    63,    64,    64,    64,    64,    64,    65,    65,    65,
      66,    67,    67,    68,    68,    69,    69,    70,    70,    70,
      70,    71,    71,    71,    72,    73,    73,    74,    74,    74,
      74,    74,    75,    75,    75,    75,    75,    75,    76,    76,
      77,    78,    79,    80,    81,    81,    82,    82,    83,    83,
      83,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    85,    85,    86,
      86,    86,    86,    86,    87,    87,    87,    88
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     0,     2,     2,     2,     2,     4,     6,     4,
       4,     8,    10,     1,     3,     3,     0,     1,     1,     1,
       1,     1,     1,     1,     3,     5,     4,     0,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     2,     2,
       3,     4,     5,     6,     4,     5,     5,     8,     0,     2,
       2,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     3,     1,
       1,     1,     1,     1,     0,     3,     4,     2
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
  "tkColon", "tkDot", "tkComma", "EOL", "tkCOLON_EQUALS", "tkNewLine",
  "tkQuote", "tkSQUARE_BRACKET_START", "tkSQUARE_BRACKET_END",
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
       0,    82,    82,    83,    84,    85,    86,    90,    91,    96,
     103,   106,   109,   115,   116,   119,   120,   123,   124,   125,
     126,   129,   130,   131,   134,   137,   138,   141,   142,   143,
     144,   145,   148,   149,   150,   151,   152,   153,   156,   157,
     160,   163,   166,   169,   171,   172,   175,   176,   179,   180,
     181,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   202,   203,   205,
     206,   207,   208,   209,   212,   213,   217,   224
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
#line 1867 "Parser.tab.cpp"

#line 235 "Parser.ypp"

namespace yy
{

    void parser::error(const std::string& msg)
    {
        std::cout <<"Syntax error\n";
    }
}
