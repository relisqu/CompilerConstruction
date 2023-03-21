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
    std::cout<< yystack_[0].value.as < sp<Expression> > ()<<"\n";
    temp->value = yystack_[0].value.as < sp<Expression> > ();
    yylhs.value.as < sp<Variable> > () = temp;
}
#line 961 "Parser.tab.cpp"
    break;

  case 9: // _var_dec: tkVar tkIdentifier tkIs _expr
#line 97 "Parser.ypp"
                                {
    ast::Type::TypeTable[yystack_[2].value.as < std::string > ()] = std::make_shared<ast::Type>(ast::Expression::getType(yystack_[0].value.as < sp<Expression> > ()));
    auto temp = std::make_shared<ast::Variable>(yystack_[2].value.as < std::string > (), yystack_[0].value.as < sp<Expression> > (), ast::Type::TypeTable[yystack_[2].value.as < std::string > ()]);
    yylhs.value.as < sp<Variable> > () = temp;
    }
#line 971 "Parser.tab.cpp"
    break;

  case 10: // _type_dec: tkType tkIdentifier tkIs _type
#line 104 "Parser.ypp"
                                          {std::cout << "get type with ident:"<<yystack_[2].value.as < std::string > ();}
#line 977 "Parser.tab.cpp"
    break;

  case 11: // _routine_dec: tkRoutine tkIdentifier tkROUND_BRACKET_START _params tkROUND_BRACKET_END tkIs _body tkEnd
#line 107 "Parser.ypp"
                                                                                                        {}
#line 983 "Parser.tab.cpp"
    break;

  case 12: // _routine_dec: tkRoutine tkIdentifier tkROUND_BRACKET_START _params tkROUND_BRACKET_END tkColon _type tkIs _body tkEnd
#line 108 "Parser.ypp"
                                                                                                          {}
#line 989 "Parser.tab.cpp"
    break;

  case 13: // _params: _param_dec
#line 111 "Parser.ypp"
                    {}
#line 995 "Parser.tab.cpp"
    break;

  case 14: // _params: _params tkComma _param_dec
#line 112 "Parser.ypp"
                             {}
#line 1001 "Parser.tab.cpp"
    break;

  case 15: // _param_dec: tkIdentifier tkColon _type
#line 115 "Parser.ypp"
                                       {}
#line 1007 "Parser.tab.cpp"
    break;

  case 16: // _type: tkIdentifier
#line 118 "Parser.ypp"
                    {}
#line 1013 "Parser.tab.cpp"
    break;

  case 17: // _type: _irb_type
#line 119 "Parser.ypp"
            {}
#line 1019 "Parser.tab.cpp"
    break;

  case 18: // _type: _arr_type
#line 120 "Parser.ypp"
            {}
#line 1025 "Parser.tab.cpp"
    break;

  case 19: // _type: _rec_type
#line 121 "Parser.ypp"
            {}
#line 1031 "Parser.tab.cpp"
    break;

  case 20: // _irb_type: tkInt
#line 124 "Parser.ypp"
                 {}
#line 1037 "Parser.tab.cpp"
    break;

  case 21: // _irb_type: tkReal
#line 125 "Parser.ypp"
         {}
#line 1043 "Parser.tab.cpp"
    break;

  case 22: // _irb_type: tkBoolean
#line 126 "Parser.ypp"
            {}
#line 1049 "Parser.tab.cpp"
    break;

  case 23: // _rec_type: tkRecord _var_dec_block tkEnd
#line 129 "Parser.ypp"
                                         {}
#line 1055 "Parser.tab.cpp"
    break;

  case 24: // _arr_type: tkArray tkSQUARE_BRACKET_START _expr tkSQUARE_BRACKET_END _type
#line 132 "Parser.ypp"
                                                                           {}
#line 1061 "Parser.tab.cpp"
    break;

  case 25: // _arr_type: tkArray tkSQUARE_BRACKET_START tkSQUARE_BRACKET_END _type
#line 133 "Parser.ypp"
                                                            {}
#line 1067 "Parser.tab.cpp"
    break;

  case 26: // _body: %empty
#line 136 "Parser.ypp"
       {}
#line 1073 "Parser.tab.cpp"
    break;

  case 27: // _body: _body _var_dec
#line 137 "Parser.ypp"
                 {}
#line 1079 "Parser.tab.cpp"
    break;

  case 28: // _body: _body _type_dec
#line 138 "Parser.ypp"
                  {}
#line 1085 "Parser.tab.cpp"
    break;

  case 29: // _body: _body _statement
#line 139 "Parser.ypp"
                   {}
#line 1091 "Parser.tab.cpp"
    break;

  case 30: // _statement: _assign
#line 141 "Parser.ypp"
                    {}
#line 1097 "Parser.tab.cpp"
    break;

  case 31: // _statement: _routine
#line 142 "Parser.ypp"
           {}
#line 1103 "Parser.tab.cpp"
    break;

  case 32: // _statement: _while
#line 143 "Parser.ypp"
         {}
#line 1109 "Parser.tab.cpp"
    break;

  case 33: // _statement: _for
#line 144 "Parser.ypp"
       {}
#line 1115 "Parser.tab.cpp"
    break;

  case 34: // _statement: _if
#line 145 "Parser.ypp"
      {}
#line 1121 "Parser.tab.cpp"
    break;

  case 35: // _statement: _return
#line 146 "Parser.ypp"
          {}
#line 1127 "Parser.tab.cpp"
    break;

  case 36: // _return: tkReturn
#line 149 "Parser.ypp"
                  {}
#line 1133 "Parser.tab.cpp"
    break;

  case 37: // _return: tkReturn _expr
#line 150 "Parser.ypp"
                 {}
#line 1139 "Parser.tab.cpp"
    break;

  case 38: // _assign: _modval tkCOLON_EQUALS _expr
#line 153 "Parser.ypp"
                                      {}
#line 1145 "Parser.tab.cpp"
    break;

  case 39: // _routine: tkIdentifier tkROUND_BRACKET_START _args tkROUND_BRACKET_END
#line 156 "Parser.ypp"
                                                                       {}
#line 1151 "Parser.tab.cpp"
    break;

  case 40: // _while: tkWhile _expr tkLoop _body tkEnd
#line 159 "Parser.ypp"
                                         {}
#line 1157 "Parser.tab.cpp"
    break;

  case 41: // _for: tkFor tkIdentifier _range tkLoop _body tkEnd
#line 162 "Parser.ypp"
                                                   {}
#line 1163 "Parser.tab.cpp"
    break;

  case 42: // _range: tkIn _expr tkDOT_DOT _expr
#line 164 "Parser.ypp"
                                   {}
#line 1169 "Parser.tab.cpp"
    break;

  case 43: // _range: tkIn tkReverse _expr tkDOT_DOT _expr
#line 165 "Parser.ypp"
                                       {}
#line 1175 "Parser.tab.cpp"
    break;

  case 44: // _if: tkIf _expr tkThen _body tkEnd
#line 168 "Parser.ypp"
                                   {}
#line 1181 "Parser.tab.cpp"
    break;

  case 45: // _if: tkIf _expr tkThen _body tkElse _body tkEnd
#line 169 "Parser.ypp"
                                             {}
#line 1187 "Parser.tab.cpp"
    break;

  case 46: // _var_dec_block: %empty
#line 172 "Parser.ypp"
                {}
#line 1193 "Parser.tab.cpp"
    break;

  case 47: // _var_dec_block: _var_dec_block _var_dec
#line 173 "Parser.ypp"
                          {}
#line 1199 "Parser.tab.cpp"
    break;

  case 48: // _var_dec_block: _var_dec_block EOL
#line 174 "Parser.ypp"
                     {}
#line 1205 "Parser.tab.cpp"
    break;

  case 49: // _expr: _primary
#line 177 "Parser.ypp"
                { yylhs.value.as < sp<Expression> > () = yystack_[0].value.as < sp<Expression> > ();}
#line 1211 "Parser.tab.cpp"
    break;

  case 50: // _expr: _expr tkPlus _expr
#line 178 "Parser.ypp"
                     { yylhs.value.as < sp<Expression> > () = std::make_shared<ast::Expression>("+", yystack_[2].value.as < sp<Expression> > (), yystack_[0].value.as < sp<Expression> > ());}
#line 1217 "Parser.tab.cpp"
    break;

  case 51: // _expr: _expr tkMinus _expr
#line 179 "Parser.ypp"
                      {  yylhs.value.as < sp<Expression> > () = std::make_shared<ast::Expression>("-", yystack_[2].value.as < sp<Expression> > (), yystack_[0].value.as < sp<Expression> > ()); }
#line 1223 "Parser.tab.cpp"
    break;

  case 52: // _expr: _expr tkMultiple _expr
#line 180 "Parser.ypp"
                         { yylhs.value.as < sp<Expression> > () = std::make_shared<ast::Expression>("*", yystack_[2].value.as < sp<Expression> > (), yystack_[0].value.as < sp<Expression> > ()); }
#line 1229 "Parser.tab.cpp"
    break;

  case 53: // _expr: _expr tkMod _expr
#line 181 "Parser.ypp"
                    { yylhs.value.as < sp<Expression> > () = std::make_shared<ast::Expression>("%", yystack_[2].value.as < sp<Expression> > (), yystack_[0].value.as < sp<Expression> > ()); }
#line 1235 "Parser.tab.cpp"
    break;

  case 54: // _expr: _expr tkDivide _expr
#line 182 "Parser.ypp"
                       { yylhs.value.as < sp<Expression> > () = std::make_shared<ast::Expression>("/", yystack_[2].value.as < sp<Expression> > (), yystack_[0].value.as < sp<Expression> > ()); }
#line 1241 "Parser.tab.cpp"
    break;

  case 55: // _expr: _expr tkLess _expr
#line 183 "Parser.ypp"
                     {  yylhs.value.as < sp<Expression> > () = std::make_shared<ast::Expression>("<", yystack_[2].value.as < sp<Expression> > (), yystack_[0].value.as < sp<Expression> > ()); }
#line 1247 "Parser.tab.cpp"
    break;

  case 56: // _expr: _expr tkLessEquals _expr
#line 184 "Parser.ypp"
                           {  yylhs.value.as < sp<Expression> > () = std::make_shared<ast::Expression>("<=", yystack_[2].value.as < sp<Expression> > (), yystack_[0].value.as < sp<Expression> > ()); }
#line 1253 "Parser.tab.cpp"
    break;

  case 57: // _expr: _expr tkGreater _expr
#line 185 "Parser.ypp"
                        {  yylhs.value.as < sp<Expression> > () = std::make_shared<ast::Expression>(">", yystack_[2].value.as < sp<Expression> > (), yystack_[0].value.as < sp<Expression> > ()); }
#line 1259 "Parser.tab.cpp"
    break;

  case 58: // _expr: _expr tkGreaterEquals _expr
#line 186 "Parser.ypp"
                              {  yylhs.value.as < sp<Expression> > () = std::make_shared<ast::Expression>(">=", yystack_[2].value.as < sp<Expression> > (), yystack_[0].value.as < sp<Expression> > ()); }
#line 1265 "Parser.tab.cpp"
    break;

  case 59: // _expr: _expr tkEquals _expr
#line 187 "Parser.ypp"
                       {  yylhs.value.as < sp<Expression> > () = std::make_shared<ast::Expression>("=", yystack_[2].value.as < sp<Expression> > (), yystack_[0].value.as < sp<Expression> > ()); }
#line 1271 "Parser.tab.cpp"
    break;

  case 60: // _expr: _expr tkNotEquals _expr
#line 188 "Parser.ypp"
                          {  yylhs.value.as < sp<Expression> > () = std::make_shared<ast::Expression>("/=", yystack_[2].value.as < sp<Expression> > (), yystack_[0].value.as < sp<Expression> > ()); }
#line 1277 "Parser.tab.cpp"
    break;

  case 61: // _expr: _expr tkBoolAnd _expr
#line 189 "Parser.ypp"
                        { yylhs.value.as < sp<Expression> > () = std::make_shared<ast::Expression>("and", yystack_[2].value.as < sp<Expression> > (), yystack_[0].value.as < sp<Expression> > ()); }
#line 1283 "Parser.tab.cpp"
    break;

  case 62: // _expr: _expr tkBoolOr _expr
#line 190 "Parser.ypp"
                       { yylhs.value.as < sp<Expression> > () = std::make_shared<ast::Expression>("or", yystack_[2].value.as < sp<Expression> > (), yystack_[0].value.as < sp<Expression> > ()); }
#line 1289 "Parser.tab.cpp"
    break;

  case 63: // _expr: _expr tkBoolXor _expr
#line 191 "Parser.ypp"
                        { yylhs.value.as < sp<Expression> > () = std::make_shared<ast::Expression>("xor", yystack_[2].value.as < sp<Expression> > (), yystack_[0].value.as < sp<Expression> > ()); }
#line 1295 "Parser.tab.cpp"
    break;

  case 64: // _expr: tkROUND_BRACKET_START _expr tkROUND_BRACKET_START
#line 192 "Parser.ypp"
                                                    {  yylhs.value.as < sp<Expression> > () = yystack_[1].value.as < sp<Expression> > (); }
#line 1301 "Parser.tab.cpp"
    break;

  case 65: // _args: _expr
#line 195 "Parser.ypp"
             {}
#line 1307 "Parser.tab.cpp"
    break;

  case 66: // _args: _args tkComma _expr
#line 196 "Parser.ypp"
                      {}
#line 1313 "Parser.tab.cpp"
    break;

  case 67: // _primary: tkConstInt
#line 198 "Parser.ypp"
                     {}
#line 1319 "Parser.tab.cpp"
    break;

  case 68: // _primary: tkConstReal
#line 199 "Parser.ypp"
              {}
#line 1325 "Parser.tab.cpp"
    break;

  case 69: // _primary: tkConstBoolean
#line 200 "Parser.ypp"
                 {}
#line 1331 "Parser.tab.cpp"
    break;

  case 70: // _primary: _modval
#line 201 "Parser.ypp"
          {}
#line 1337 "Parser.tab.cpp"
    break;

  case 71: // _primary: _routine
#line 202 "Parser.ypp"
           {}
#line 1343 "Parser.tab.cpp"
    break;

  case 72: // _getvar: %empty
#line 205 "Parser.ypp"
         {}
#line 1349 "Parser.tab.cpp"
    break;

  case 73: // _getvar: _getvar tkDot tkIdentifier
#line 206 "Parser.ypp"
                             {}
#line 1355 "Parser.tab.cpp"
    break;

  case 74: // _getvar: _getvar tkSQUARE_BRACKET_START _expr tkSQUARE_BRACKET_END
#line 207 "Parser.ypp"
                                                            {}
#line 1361 "Parser.tab.cpp"
    break;

  case 75: // _modval: tkIdentifier _getvar
#line 210 "Parser.ypp"
                              {}
#line 1367 "Parser.tab.cpp"
    break;


#line 1371 "Parser.tab.cpp"

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









  const signed char parser::yypact_ninf_ = -45;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
     -45,    39,   -45,    -2,    -1,     2,   -45,   -45,   -45,   -45,
       4,   -17,   -15,     6,   417,   417,    34,   -45,   -45,   -45,
      -7,     6,   -45,   334,   -45,   -45,   -45,   -45,   -45,     7,
     -45,   -45,    31,   -45,   -45,   -45,   -45,    17,   -38,   -45,
       6,    12,   103,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     0,    33,     6,
     417,    34,    10,   334,   -10,    51,     6,   -45,   379,   351,
     368,    44,    44,    44,    44,   390,   390,   -45,   -45,   -45,
     -45,   -45,   417,   120,   -45,   -45,   -45,   334,   -45,   -45,
     -45,   417,     6,   -45,   -45,   139,   -45,   417,   173,    36,
     334,   -45,   -45,     6,   -45,    63,     6,     6,   -45,   -45,
     -45,   -45,   -45,   -45,   -45,   -45,   -45,    27,   -45,   314,
      50,   295,   334,     6,   181,   -45,     3,    53,   -45,   334,
     -45,   165,     6,   253,   -45,   214,   -45,   -45,   274,     6,
     222,   -45,   230,     6,   334,   -45,   -45,   334
  };

  const signed char
  parser::yydefact_[] =
  {
       2,     0,     1,     0,     0,     0,     6,     3,     4,     5,
       0,     0,     0,     0,     0,     0,     0,    67,    68,    69,
      72,     0,    71,     9,    49,    70,    20,    21,    22,     0,
      46,    16,     7,    17,    19,    18,    10,     0,     0,    13,
       0,    75,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    65,     0,     0,     0,    64,    61,    62,
      63,    55,    56,    57,    58,    59,    60,    50,    51,    52,
      53,    54,     0,     0,    23,    48,    47,     8,    15,    14,
      26,     0,     0,    39,    73,     0,    25,     0,     0,     0,
      66,    74,    24,     0,    11,     0,     0,    36,    27,    28,
      29,    35,    30,    31,    32,    33,    34,     0,    26,     0,
       0,     0,    37,     0,     0,    26,     0,     0,    26,    38,
      12,     0,     0,     0,    26,     0,    26,    44,     0,     0,
       0,    40,     0,     0,    42,    41,    45,    43
  };

  const signed char
  parser::yypgoto_[] =
  {
     -45,   -45,     1,    94,   -45,   -45,    42,   -14,   -45,   -45,
     -45,   -24,   -45,   -45,   -45,   -44,   -45,   -45,   -45,   -45,
     -45,   -21,   -45,   -45,   -45,   -43
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     1,   108,   109,     9,    38,    39,    32,    33,    34,
      35,    98,   110,   111,   112,    22,   114,   115,   127,   116,
      58,    23,    64,    24,    41,    25
  };

  const unsigned char
  parser::yytable_[] =
  {
      42,    36,     7,    17,    18,    19,    17,    18,    19,    17,
      18,    19,    61,    10,    11,    20,    15,    12,    20,    63,
      62,    20,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    83,    13,    87,     2,
      92,     3,    16,    90,   132,    95,    88,     3,    93,    37,
      40,     4,    14,     5,   113,   117,    82,    21,    91,    86,
      21,    65,    57,    21,    59,    60,    94,    66,    96,   118,
      84,   100,    52,    53,    54,    55,    56,    99,   120,   123,
     113,   117,   119,   102,    85,   121,   122,   113,   117,   126,
       6,   113,   117,   134,   124,     8,   113,   117,   113,   117,
       0,   131,   129,    89,   135,   133,     0,     0,     0,     0,
     140,   138,   142,     0,     0,     0,     0,     0,   144,    43,
      44,    45,   147,     0,     0,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    43,    44,    45,     0,
       0,     0,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,     0,     0,    43,    44,    45,     0,     0,
      67,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,     0,     3,     0,     0,    97,     4,     0,     0,
      20,     3,     0,     0,     0,     4,     0,     0,    20,     3,
       0,     0,     0,     4,     0,   101,    20,     0,     0,   103,
       0,   136,   137,   105,     0,     0,     0,   103,   106,   107,
     104,   105,     0,     0,     0,   103,   106,   107,   130,   105,
       0,     0,     3,     0,   106,   107,     4,     0,     0,    20,
       3,     0,     0,     0,     4,     0,     0,    20,     3,     0,
       0,     0,     4,     0,     0,    20,     0,     0,   103,     0,
       0,   141,   105,     0,     0,     0,   103,   106,   107,   145,
     105,     0,     0,     0,   103,   106,   107,   146,   105,    43,
      44,    45,     0,   106,   107,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,     0,     0,     0,     0,
      43,    44,    45,     0,     0,   139,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,     0,     0,     0,
       0,    43,    44,    45,     0,     0,   143,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,     0,     0,
      43,    44,    45,     0,     0,   128,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,     0,     0,   125,
      43,    44,    45,     0,     0,     0,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    43,     0,    45,
       0,     0,     0,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    43,     0,     0,     0,     0,     0,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    46,    47,    48,    49,     0,     0,    52,    53,
      54,    55,    56,    26,    27,     0,    28,     0,    29,     0,
      30,     0,    31
  };

  const short
  parser::yycheck_[] =
  {
      21,    15,     1,     3,     4,     5,     3,     4,     5,     3,
       4,     5,    50,    15,    15,    15,    33,    15,    15,    40,
      58,    15,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    33,    59,     0,
      50,     8,    57,    33,    41,    66,    60,     8,    58,    15,
      57,    12,    48,    14,    98,    98,    56,    57,    48,    58,
      57,    49,    55,    57,    33,    48,    15,    55,    82,    33,
      37,    92,    28,    29,    30,    31,    32,    91,    15,    52,
     124,   124,   103,    97,    51,   106,   107,   131,   131,    39,
      51,   135,   135,    40,   118,     1,   140,   140,   142,   142,
      -1,   125,   123,    61,   128,   126,    -1,    -1,    -1,    -1,
     134,   132,   136,    -1,    -1,    -1,    -1,    -1,   139,    16,
      17,    18,   143,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    16,    17,    18,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    -1,    -1,    16,    17,    18,    -1,    -1,
      57,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,     8,    -1,    -1,    56,    12,    -1,    -1,
      15,     8,    -1,    -1,    -1,    12,    -1,    -1,    15,     8,
      -1,    -1,    -1,    12,    -1,    56,    15,    -1,    -1,    34,
      -1,    36,    37,    38,    -1,    -1,    -1,    34,    43,    44,
      37,    38,    -1,    -1,    -1,    34,    43,    44,    37,    38,
      -1,    -1,     8,    -1,    43,    44,    12,    -1,    -1,    15,
       8,    -1,    -1,    -1,    12,    -1,    -1,    15,     8,    -1,
      -1,    -1,    12,    -1,    -1,    15,    -1,    -1,    34,    -1,
      -1,    37,    38,    -1,    -1,    -1,    34,    43,    44,    37,
      38,    -1,    -1,    -1,    34,    43,    44,    37,    38,    16,
      17,    18,    -1,    43,    44,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      16,    17,    18,    -1,    -1,    42,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    16,    17,    18,    -1,    -1,    42,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    -1,    -1,
      16,    17,    18,    -1,    -1,    40,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    -1,    -1,    35,
      16,    17,    18,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    16,    -1,    18,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    16,    -1,    -1,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    22,    23,    24,    25,    -1,    -1,    28,    29,
      30,    31,    32,     6,     7,    -1,     9,    -1,    11,    -1,
      13,    -1,    15
  };

  const signed char
  parser::yystos_[] =
  {
       0,    65,     0,     8,    12,    14,    51,    66,    67,    68,
      15,    15,    15,    33,    48,    33,    57,     3,     4,     5,
      15,    57,    79,    85,    87,    89,     6,     7,     9,    11,
      13,    15,    71,    72,    73,    74,    71,    15,    69,    70,
      57,    88,    85,    16,    17,    18,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    55,    84,    33,
      48,    50,    58,    85,    86,    49,    55,    57,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    56,    85,    37,    51,    66,    85,    71,    70,
      33,    48,    50,    58,    15,    85,    71,    56,    75,    71,
      85,    56,    71,    34,    37,    38,    43,    44,    66,    67,
      76,    77,    78,    79,    80,    81,    83,    89,    33,    85,
      15,    85,    85,    52,    75,    35,    39,    82,    40,    85,
      37,    75,    41,    85,    40,    75,    36,    37,    85,    42,
      75,    37,    75,    42,    85,    37,    37,    85
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    64,    65,    65,    65,    65,    65,    66,    66,    66,
      67,    68,    68,    69,    69,    70,    71,    71,    71,    71,
      72,    72,    72,    73,    74,    74,    75,    75,    75,    75,
      76,    76,    76,    76,    76,    76,    77,    77,    78,    79,
      80,    81,    82,    82,    83,    83,    84,    84,    84,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    86,    86,    87,    87,    87,
      87,    87,    88,    88,    88,    89
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     0,     2,     2,     2,     2,     4,     6,     4,
       4,     8,    10,     1,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     3,     5,     4,     0,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     4,
       5,     6,     4,     5,     5,     7,     0,     2,     2,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     3,     1,     1,     1,
       1,     1,     0,     3,     4,     2
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
       0,    82,    82,    83,    84,    85,    86,    90,    91,    97,
     104,   107,   108,   111,   112,   115,   118,   119,   120,   121,
     124,   125,   126,   129,   132,   133,   136,   137,   138,   139,
     141,   142,   143,   144,   145,   146,   149,   150,   153,   156,
     159,   162,   164,   165,   168,   169,   172,   173,   174,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   195,   196,   198,   199,   200,
     201,   202,   205,   206,   207,   210
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
#line 1835 "Parser.tab.cpp"

#line 213 "Parser.ypp"

namespace yy
{
    void parser::error(const std::string& msg)
    {
        std::cout <<"Syntax error\n";
    }
}
