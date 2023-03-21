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
#line 19 "Parser.ypp"

    namespace yy
    {
        parser::symbol_type yylex();
    }

    extern yy::parser::symbol_type get_next_token();

#line 55 "Parser.tab.cpp"


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
#line 128 "Parser.tab.cpp"

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

      case symbol_kind::S_tkIdentifier: // tkIdentifier
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
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

      case symbol_kind::S_tkIdentifier: // tkIdentifier
        value.move< std::string > (YY_MOVE (that.value));
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

      case symbol_kind::S_tkIdentifier: // tkIdentifier
        value.copy< std::string > (that.value);
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

      case symbol_kind::S_tkIdentifier: // tkIdentifier
        value.move< std::string > (that.value);
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

      case symbol_kind::S_tkIdentifier: // tkIdentifier
        yylhs.value.emplace< std::string > ();
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
#line 51 "Parser.ypp"
                   {}
#line 589 "Parser.tab.cpp"
    break;

  case 4: // program: program _type_dec
#line 52 "Parser.ypp"
                    {}
#line 595 "Parser.tab.cpp"
    break;

  case 5: // program: program _routine_dec
#line 53 "Parser.ypp"
                       {}
#line 601 "Parser.tab.cpp"
    break;

  case 7: // _var_dec: tkVar tkIdentifier tkColon _type
#line 60 "Parser.ypp"
                                            {std::cout << "Made new variable "<< yystack_[2].value.as < std::string > ();}
#line 607 "Parser.tab.cpp"
    break;

  case 8: // _var_dec: tkVar tkIdentifier tkColon _type tkIs _expr
#line 61 "Parser.ypp"
                                              {std::cout << "Made new variable "<< yystack_[4].value.as < std::string > () <<" with val: ";}
#line 613 "Parser.tab.cpp"
    break;

  case 9: // _type_dec: tkType tkIdentifier tkIs _type
#line 64 "Parser.ypp"
                                          {std::cout << "get type with ident:"<<yystack_[2].value.as < std::string > ();}
#line 619 "Parser.tab.cpp"
    break;

  case 10: // _routine_dec: tkRoutine tkIdentifier tkROUND_BRACKET_START _params tkROUND_BRACKET_END tkIs _body tkEnd
#line 67 "Parser.ypp"
                                                                                                        {}
#line 625 "Parser.tab.cpp"
    break;

  case 11: // _routine_dec: tkRoutine tkIdentifier tkROUND_BRACKET_START _params tkROUND_BRACKET_END tkColon _type tkIs _body tkEnd
#line 68 "Parser.ypp"
                                                                                                          {}
#line 631 "Parser.tab.cpp"
    break;

  case 12: // _params: _param_dec
#line 71 "Parser.ypp"
                    {}
#line 637 "Parser.tab.cpp"
    break;

  case 13: // _params: _params tkComma _param_dec
#line 72 "Parser.ypp"
                             {}
#line 643 "Parser.tab.cpp"
    break;

  case 14: // _param_dec: tkIdentifier tkColon _type
#line 75 "Parser.ypp"
                                       {}
#line 649 "Parser.tab.cpp"
    break;

  case 15: // _type: tkIdentifier
#line 78 "Parser.ypp"
                    {}
#line 655 "Parser.tab.cpp"
    break;

  case 16: // _type: _irb_type
#line 79 "Parser.ypp"
            {}
#line 661 "Parser.tab.cpp"
    break;

  case 17: // _type: _arr_type
#line 80 "Parser.ypp"
            {}
#line 667 "Parser.tab.cpp"
    break;

  case 18: // _type: _rec_type
#line 81 "Parser.ypp"
            {}
#line 673 "Parser.tab.cpp"
    break;

  case 19: // _irb_type: tkInt
#line 84 "Parser.ypp"
                 {}
#line 679 "Parser.tab.cpp"
    break;

  case 20: // _irb_type: tkReal
#line 85 "Parser.ypp"
         {}
#line 685 "Parser.tab.cpp"
    break;

  case 21: // _irb_type: tkBoolean
#line 86 "Parser.ypp"
            {}
#line 691 "Parser.tab.cpp"
    break;

  case 22: // _rec_type: tkRecord _var_dec_block tkEnd
#line 89 "Parser.ypp"
                                         {}
#line 697 "Parser.tab.cpp"
    break;

  case 23: // _arr_type: tkArray tkSQUARE_BRACKET_START _expr tkSQUARE_BRACKET_END _type
#line 92 "Parser.ypp"
                                                                           {}
#line 703 "Parser.tab.cpp"
    break;

  case 24: // _arr_type: tkArray tkSQUARE_BRACKET_START tkSQUARE_BRACKET_END _type
#line 93 "Parser.ypp"
                                                            {}
#line 709 "Parser.tab.cpp"
    break;

  case 25: // _body: %empty
#line 96 "Parser.ypp"
       {}
#line 715 "Parser.tab.cpp"
    break;

  case 26: // _body: _body _var_dec
#line 97 "Parser.ypp"
                 {}
#line 721 "Parser.tab.cpp"
    break;

  case 27: // _body: _body _type_dec
#line 98 "Parser.ypp"
                  {}
#line 727 "Parser.tab.cpp"
    break;

  case 28: // _body: _body _statement
#line 99 "Parser.ypp"
                   {}
#line 733 "Parser.tab.cpp"
    break;

  case 29: // _statement: _assign
#line 101 "Parser.ypp"
                    {}
#line 739 "Parser.tab.cpp"
    break;

  case 30: // _statement: _routine
#line 102 "Parser.ypp"
           {}
#line 745 "Parser.tab.cpp"
    break;

  case 31: // _statement: _while
#line 103 "Parser.ypp"
         {}
#line 751 "Parser.tab.cpp"
    break;

  case 32: // _statement: _for
#line 104 "Parser.ypp"
       {}
#line 757 "Parser.tab.cpp"
    break;

  case 33: // _statement: _if
#line 105 "Parser.ypp"
      {}
#line 763 "Parser.tab.cpp"
    break;

  case 34: // _statement: _return
#line 106 "Parser.ypp"
          {}
#line 769 "Parser.tab.cpp"
    break;

  case 35: // _return: tkReturn
#line 109 "Parser.ypp"
                  {}
#line 775 "Parser.tab.cpp"
    break;

  case 36: // _return: tkReturn _expr
#line 110 "Parser.ypp"
                 {}
#line 781 "Parser.tab.cpp"
    break;

  case 37: // _assign: _modval tkCOLON_EQUALS _expr
#line 113 "Parser.ypp"
                                      {}
#line 787 "Parser.tab.cpp"
    break;

  case 38: // _routine: tkIdentifier tkROUND_BRACKET_START _args tkROUND_BRACKET_END
#line 116 "Parser.ypp"
                                                                       {}
#line 793 "Parser.tab.cpp"
    break;

  case 39: // _while: tkWhile _expr tkLoop _body tkEnd
#line 119 "Parser.ypp"
                                         {}
#line 799 "Parser.tab.cpp"
    break;

  case 40: // _for: tkFor tkIdentifier _range tkLoop _body tkEnd
#line 122 "Parser.ypp"
                                                   {}
#line 805 "Parser.tab.cpp"
    break;

  case 41: // _range: tkIn _expr tkDOT_DOT _expr
#line 124 "Parser.ypp"
                                   {}
#line 811 "Parser.tab.cpp"
    break;

  case 42: // _range: tkIn tkReverse _expr tkDOT_DOT _expr
#line 125 "Parser.ypp"
                                       {}
#line 817 "Parser.tab.cpp"
    break;

  case 43: // _if: tkIf _expr tkThen _body tkEnd
#line 128 "Parser.ypp"
                                   {}
#line 823 "Parser.tab.cpp"
    break;

  case 44: // _if: tkIf _expr tkThen _body tkElse _body tkEnd
#line 129 "Parser.ypp"
                                             {}
#line 829 "Parser.tab.cpp"
    break;

  case 45: // _var_dec_block: %empty
#line 132 "Parser.ypp"
                {}
#line 835 "Parser.tab.cpp"
    break;

  case 46: // _var_dec_block: _var_dec_block _var_dec
#line 133 "Parser.ypp"
                          {}
#line 841 "Parser.tab.cpp"
    break;

  case 47: // _expr: _primary
#line 136 "Parser.ypp"
                {}
#line 847 "Parser.tab.cpp"
    break;

  case 48: // _expr: _expr tkPlus _expr
#line 137 "Parser.ypp"
                     {}
#line 853 "Parser.tab.cpp"
    break;

  case 49: // _expr: _expr tkMinus _expr
#line 138 "Parser.ypp"
                      {}
#line 859 "Parser.tab.cpp"
    break;

  case 50: // _expr: _expr tkMultiple _expr
#line 139 "Parser.ypp"
                         {}
#line 865 "Parser.tab.cpp"
    break;

  case 51: // _expr: _expr tkMod _expr
#line 140 "Parser.ypp"
                    {}
#line 871 "Parser.tab.cpp"
    break;

  case 52: // _expr: _expr tkDivide _expr
#line 141 "Parser.ypp"
                       {}
#line 877 "Parser.tab.cpp"
    break;

  case 53: // _expr: _expr tkLess _expr
#line 142 "Parser.ypp"
                     {}
#line 883 "Parser.tab.cpp"
    break;

  case 54: // _expr: _expr tkLessEquals _expr
#line 143 "Parser.ypp"
                           {}
#line 889 "Parser.tab.cpp"
    break;

  case 55: // _expr: _expr tkGreater _expr
#line 144 "Parser.ypp"
                        {}
#line 895 "Parser.tab.cpp"
    break;

  case 56: // _expr: _expr tkGreaterEquals _expr
#line 145 "Parser.ypp"
                              {}
#line 901 "Parser.tab.cpp"
    break;

  case 57: // _expr: _expr tkEquals _expr
#line 146 "Parser.ypp"
                       {}
#line 907 "Parser.tab.cpp"
    break;

  case 58: // _expr: _expr tkNotEquals _expr
#line 147 "Parser.ypp"
                          {}
#line 913 "Parser.tab.cpp"
    break;

  case 59: // _expr: _expr tkBoolAnd _expr
#line 148 "Parser.ypp"
                        {}
#line 919 "Parser.tab.cpp"
    break;

  case 60: // _expr: _expr tkBoolOr _expr
#line 149 "Parser.ypp"
                       {}
#line 925 "Parser.tab.cpp"
    break;

  case 61: // _expr: _expr tkBoolXor _expr
#line 150 "Parser.ypp"
                        {}
#line 931 "Parser.tab.cpp"
    break;

  case 62: // _expr: tkROUND_BRACKET_START _expr tkROUND_BRACKET_START
#line 151 "Parser.ypp"
                                                    {}
#line 937 "Parser.tab.cpp"
    break;

  case 63: // _args: _expr
#line 154 "Parser.ypp"
             {}
#line 943 "Parser.tab.cpp"
    break;

  case 64: // _args: _args tkComma _expr
#line 155 "Parser.ypp"
                      {}
#line 949 "Parser.tab.cpp"
    break;

  case 65: // _primary: tkConstInt
#line 157 "Parser.ypp"
                     {}
#line 955 "Parser.tab.cpp"
    break;

  case 66: // _primary: tkConstReal
#line 158 "Parser.ypp"
              {}
#line 961 "Parser.tab.cpp"
    break;

  case 67: // _primary: tkConstBoolean
#line 159 "Parser.ypp"
                 {}
#line 967 "Parser.tab.cpp"
    break;

  case 68: // _primary: _modval
#line 160 "Parser.ypp"
          {}
#line 973 "Parser.tab.cpp"
    break;

  case 69: // _primary: _routine
#line 161 "Parser.ypp"
           {}
#line 979 "Parser.tab.cpp"
    break;

  case 70: // _getvar: %empty
#line 164 "Parser.ypp"
         {}
#line 985 "Parser.tab.cpp"
    break;

  case 71: // _getvar: _getvar tkDot tkIdentifier
#line 165 "Parser.ypp"
                             {}
#line 991 "Parser.tab.cpp"
    break;

  case 72: // _getvar: _getvar tkSQUARE_BRACKET_START _expr tkSQUARE_BRACKET_END
#line 166 "Parser.ypp"
                                                            {}
#line 997 "Parser.tab.cpp"
    break;

  case 73: // _modval: tkIdentifier _getvar
#line 169 "Parser.ypp"
                              {}
#line 1003 "Parser.tab.cpp"
    break;


#line 1007 "Parser.tab.cpp"

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
     -70,     5,   -70,   -14,    -9,    -7,   -70,   -70,   -70,   -70,
     -37,   -22,   -44,   402,   402,     7,   -70,   -70,   -70,   -30,
     -70,   -70,   -10,   -70,   -70,   -70,   -70,    14,   -42,   -70,
      37,    10,    84,   402,     7,   -31,   -70,   -70,   -70,    -3,
     402,    84,   -70,   106,   -70,   -70,   -70,   -70,   319,   -70,
     -70,   -70,   402,    84,    -5,   -70,    89,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,   402,   158,    21,   319,    -1,    42,    84,   -70,   364,
     336,   353,    51,    51,    51,    51,   375,   375,   -70,   -70,
     -70,   -70,   -70,   -70,    84,   -70,    52,    84,    84,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,    24,   -70,
      84,   -70,   -70,   125,   299,    46,   280,   319,    84,   166,
     319,   -70,   -70,    69,    36,   -70,   319,   -70,   150,    84,
     238,   -70,   199,   -70,   -70,   259,    84,   207,   -70,   215,
      84,   319,   -70,   -70,   319
  };

  const signed char
  parser::yydefact_[] =
  {
       2,     0,     1,     0,     0,     0,     6,     3,     4,     5,
       0,     0,     0,     0,     0,     0,    19,    20,    21,     0,
      45,    15,     7,    16,    18,    17,     9,     0,     0,    12,
       0,     0,     0,     0,     0,     0,    65,    66,    67,    70,
       0,     0,    69,     0,    47,    68,    22,    46,     8,    14,
      13,    25,     0,     0,    73,    24,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    63,     0,     0,     0,    62,    59,
      60,    61,    53,    54,    55,    56,    57,    58,    48,    49,
      50,    51,    52,    23,     0,    10,     0,     0,    35,    26,
      27,    28,    34,    29,    30,    31,    32,    33,     0,    25,
       0,    38,    71,     0,     0,     0,     0,    36,     0,     0,
      64,    72,    25,     0,     0,    25,    37,    11,     0,     0,
       0,    25,     0,    25,    43,     0,     0,     0,    39,     0,
       0,    41,    40,    44,    42
  };

  const signed char
  parser::yypgoto_[] =
  {
     -70,   -70,    13,    93,   -70,   -70,    56,     6,   -70,   -70,
     -70,   107,   -70,   -70,   -70,   -69,   -70,   -70,   -70,   -70,
     -70,   -32,   -70,   -70,   -70,   -68
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     1,    99,   100,     9,    28,    29,    22,    23,    24,
      25,    72,   101,   102,   103,    42,   105,   106,   124,   107,
      31,    43,    75,    44,    54,    45
  };

  const unsigned char
  parser::yytable_[] =
  {
      48,    10,    51,   104,   108,     2,    11,    34,    12,    56,
      13,    14,    15,     3,     7,    35,    52,     4,     3,     5,
      26,    74,    27,    32,    30,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    49,
      36,    37,    38,    76,    47,   113,    55,    46,   110,    77,
     104,   108,    39,    53,   109,     6,   111,   112,    73,   104,
     108,    33,   114,   104,   108,   116,   117,   115,   104,   108,
     104,   108,    36,    37,    38,   118,   131,    93,   120,    66,
      67,    68,    69,    70,    39,   123,   126,    36,    37,    38,
      50,   130,    40,    41,     8,     0,     0,   135,     0,    39,
       0,     0,     0,     0,   141,    57,    58,    59,   144,     0,
     129,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    57,    58,    59,    41,     0,     0,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,     0,
      41,    57,    58,    59,     0,    78,     0,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,     3,     0,
       0,    71,     4,     0,     0,    39,     3,     0,     0,     0,
       4,     0,     0,    39,     3,     0,     0,     0,     4,     0,
     121,    39,     0,     0,    94,     0,   133,   134,    96,     0,
       0,     0,    94,    97,    98,    95,    96,     0,     0,     0,
      94,    97,    98,   127,    96,     0,     0,     3,     0,    97,
      98,     4,     0,     0,    39,     3,   119,     0,     0,     4,
       0,     0,    39,     3,     0,     0,     0,     4,     0,   128,
      39,     0,   132,    94,     0,     0,   138,    96,   137,     0,
     139,    94,    97,    98,   142,    96,     0,     0,     0,    94,
      97,    98,   143,    96,    57,    58,    59,     0,    97,    98,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,     0,     0,     0,     0,    57,    58,    59,     0,     0,
     136,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,     0,     0,     0,     0,    57,    58,    59,     0,
       0,   140,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,     0,     0,    57,    58,    59,     0,     0,
     125,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,     0,     0,   122,    57,    58,    59,     0,     0,
       0,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    57,     0,    59,     0,     0,     0,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    57,
       0,     0,     0,     0,     0,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    60,    61,    62,
      63,     0,     0,    66,    67,    68,    69,    70,    16,    17,
       0,    18,     0,    19,     0,    20,     0,    21
  };

  const short
  parser::yycheck_[] =
  {
      32,    15,    33,    72,    72,     0,    15,    49,    15,    41,
      47,    33,    56,     8,     1,    57,    47,    12,     8,    14,
      14,    53,    15,    33,    54,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    33,
       3,     4,     5,    48,    31,    77,    40,    37,    49,    54,
     119,   119,    15,    56,    33,    50,    57,    15,    52,   128,
     128,    47,    94,   132,   132,    97,    98,    15,   137,   137,
     139,   139,     3,     4,     5,    51,    40,    71,   110,    28,
      29,    30,    31,    32,    15,    39,   118,     3,     4,     5,
      34,   123,    55,    56,     1,    -1,    -1,   129,    -1,    15,
      -1,    -1,    -1,    -1,   136,    16,    17,    18,   140,    -1,
      41,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    16,    17,    18,    56,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    -1,
      56,    16,    17,    18,    -1,    56,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,     8,    -1,
      -1,    55,    12,    -1,    -1,    15,     8,    -1,    -1,    -1,
      12,    -1,    -1,    15,     8,    -1,    -1,    -1,    12,    -1,
      55,    15,    -1,    -1,    34,    -1,    36,    37,    38,    -1,
      -1,    -1,    34,    43,    44,    37,    38,    -1,    -1,    -1,
      34,    43,    44,    37,    38,    -1,    -1,     8,    -1,    43,
      44,    12,    -1,    -1,    15,     8,   109,    -1,    -1,    12,
      -1,    -1,    15,     8,    -1,    -1,    -1,    12,    -1,   122,
      15,    -1,   125,    34,    -1,    -1,    37,    38,   131,    -1,
     133,    34,    43,    44,    37,    38,    -1,    -1,    -1,    34,
      43,    44,    37,    38,    16,    17,    18,    -1,    43,    44,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    16,    17,    18,    -1,    -1,
      42,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    16,    17,    18,    -1,
      -1,    42,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    -1,    -1,    16,    17,    18,    -1,    -1,
      40,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    -1,    35,    16,    17,    18,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    16,    -1,    18,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    16,
      -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    22,    23,    24,
      25,    -1,    -1,    28,    29,    30,    31,    32,     6,     7,
      -1,     9,    -1,    11,    -1,    13,    -1,    15
  };

  const signed char
  parser::yystos_[] =
  {
       0,    64,     0,     8,    12,    14,    50,    65,    66,    67,
      15,    15,    15,    47,    33,    56,     6,     7,     9,    11,
      13,    15,    70,    71,    72,    73,    70,    15,    68,    69,
      54,    83,    33,    47,    49,    57,     3,     4,     5,    15,
      55,    56,    78,    84,    86,    88,    37,    65,    84,    70,
      69,    33,    47,    56,    87,    70,    84,    16,    17,    18,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    55,    74,    70,    84,    85,    48,    54,    56,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    70,    34,    37,    38,    43,    44,    65,
      66,    75,    76,    77,    78,    79,    80,    82,    88,    33,
      49,    57,    15,    84,    84,    15,    84,    84,    51,    74,
      84,    55,    35,    39,    81,    40,    84,    37,    74,    41,
      84,    40,    74,    36,    37,    84,    42,    74,    37,    74,
      42,    84,    37,    37,    84
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    63,    64,    64,    64,    64,    64,    65,    65,    66,
      67,    67,    68,    68,    69,    70,    70,    70,    70,    71,
      71,    71,    72,    73,    73,    74,    74,    74,    74,    75,
      75,    75,    75,    75,    75,    76,    76,    77,    78,    79,
      80,    81,    81,    82,    82,    83,    83,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    85,    85,    86,    86,    86,    86,    86,
      87,    87,    87,    88
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     0,     2,     2,     2,     2,     4,     6,     4,
       8,    10,     1,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     3,     5,     4,     0,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     4,     5,
       6,     4,     5,     5,     7,     0,     2,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     1,     1,     1,     1,     1,
       0,     3,     4,     2
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
       0,    50,    50,    51,    52,    53,    54,    60,    61,    64,
      67,    68,    71,    72,    75,    78,    79,    80,    81,    84,
      85,    86,    89,    92,    93,    96,    97,    98,    99,   101,
     102,   103,   104,   105,   106,   109,   110,   113,   116,   119,
     122,   124,   125,   128,   129,   132,   133,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   154,   155,   157,   158,   159,   160,   161,
     164,   165,   166,   169
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
#line 1467 "Parser.tab.cpp"

#line 172 "Parser.ypp"

namespace yy
{
    void parser::error(const std::string& msg)
    {
        std::cout <<"Syntax error\n";
    }
}
