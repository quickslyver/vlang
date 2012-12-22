#ifndef TOKEN_KIND_H
#define TOKEN_KIND_H


enum TokenKind{
  tok_invalid,
  tok_eof,
  tok_literal,
  tok_identifier,
  tok_comment,
  tok_newline,
//special characters:
  tok_ampersand,
  tok_tick,
  tok_lparen,
  tok_rparen,
  tok_mul,
  tok_plus,
  tok_comma,
  tok_minus,
  tok_dot,
  tok_divide,
  tok_colon,
  tok_semicolon,
  tok_less,
  tok_equal,
  tok_greater,
  tok_vertical_line,
  tok_lbracket,
  tok_rbracket,
  tok_arrow,                   // =>
  tok_exp,                     // **
  tok_var_assign,              // :=
  tok_inequal,                 // /=
  tok_greater_or_equal,        // >=
  tok_less_or_equal_or_assign, // <=
  tok_box,                     // <>
//keywords:
  tok_kw_abs,
  tok_kw_access,
  tok_kw_after,
  tok_kw_alias,
  tok_kw_all,
  tok_kw_and,
  tok_kw_architecture,
  tok_kw_array,
  tok_kw_assert,
  tok_kw_attribute,
  tok_kw_begin,
  tok_kw_block,
  tok_kw_body,
  tok_kw_buffer,
  tok_kw_bus,
  tok_kw_case ,
  tok_kw_component,
  tok_kw_configuration,
  tok_kw_constant,
  tok_kw_disconnect,
  tok_kw_downto,
  tok_kw_else,
  tok_kw_elsif,
  tok_kw_end,
  tok_kw_entity,
  tok_kw_exit,
  tok_kw_file,
  tok_kw_for,
  tok_kw_function,
  tok_kw_generate,
  tok_kw_generic,
  tok_kw_group,
  tok_kw_guarded,
  tok_kw_if,
  tok_kw_impure,
  tok_kw_in,
  tok_kw_inertial,
  tok_kw_inout,
  tok_kw_is,
  tok_kw_label,
  tok_kw_library,
  tok_kw_linkage,
  tok_kw_literal,
  tok_kw_loop,
  tok_kw_map,
  tok_kw_mod,
  tok_kw_nand,
  tok_kw_new,
  tok_kw_next,
  tok_kw_nor,
  tok_kw_not,
  tok_kw_null,
  tok_kw_of,
  tok_kw_on,
  tok_kw_open,
  tok_kw_or,
  tok_kw_others,
  tok_kw_out,
  tok_kw_package,
  tok_kw_port,
  tok_kw_postponed,
  tok_kw_procedural,
  tok_kw_procedure,
  tok_kw_process,
  tok_kw_protected,
  tok_kw_pure,
  tok_kw_range,
  tok_kw_record,
  tok_kw_reference,
  tok_kw_register,
  tok_kw_reject,
  tok_kw_rem,
  tok_kw_report,
  tok_kw_return,
  tok_kw_rol,
  tok_kw_ror,
  tok_kw_select,
  tok_kw_severity,
  tok_kw_signal,
  tok_kw_shared,
  tok_kw_sla,
  tok_kw_sll,
  tok_kw_sra,
  tok_kw_srl,
  tok_kw_subtype,
  tok_kw_then,
  tok_kw_to,
  tok_kw_transport,
  tok_kw_type,
  tok_kw_unaffected,
  tok_kw_units,
  tok_kw_until,
  tok_kw_use,
  tok_kw_variable,
  tok_kw_wait,
  tok_kw_when,
  tok_kw_while,
  tok_kw_with,
  tok_kw_xnor,
  tok_kw_xor
};

static const char* toString(enum TokenKind tok){
  switch(tok){
  case tok_invalid          : return "invalid";
  case tok_eof              : return "eof";
  case tok_literal          : return "literal";
  case tok_identifier       : return "identifier";
  case tok_comment          : return "comment";
  case tok_newline          : return "newline";
//special characters:
  case tok_ampersand        : return "ampersand";
  case tok_tick             : return "tick";
  case tok_lparen           : return "lparen";
  case tok_rparen           : return "rparen";
  case tok_mul              : return "mul";
  case tok_plus             : return "plus";
  case tok_comma            : return "comma";
  case tok_minus            : return "minus";
  case tok_dot              : return "dot";
  case tok_divide           : return "divide";
  case tok_colon            : return "colon";
  case tok_semicolon        : return "semicolon";
  case tok_less             : return "less";
  case tok_equal            : return "equal";
  case tok_greater          : return "greater";
  case tok_vertical_line    : return "vertical_line";
  case tok_lbracket         : return "lbracket";
  case tok_rbracket         : return "rbracket";
  case tok_arrow            : return "arrow";
  case tok_exp              : return "exp";
  case tok_var_assign       : return "var_assign";
  case tok_inequal          : return "inequal";
  case tok_greater_or_equal : return "greater_or_equal";
  case tok_less_or_equal_or_assign : return "less_or_equal_or_assign";
  case tok_box              : return "box";
//keywords:
  case tok_kw_abs           : return "kw_abs";
  case tok_kw_access        : return "kw_access";
  case tok_kw_after         : return "kw_after";
  case tok_kw_alias         : return "kw_alias";
  case tok_kw_all           : return "kw_all";
  case tok_kw_and           : return "kw_and";
  case tok_kw_architecture  : return "kw_architecture";
  case tok_kw_array         : return "kw_array";
  case tok_kw_assert        : return "kw_assert";
  case tok_kw_attribute     : return "kw_attribute";
  case tok_kw_begin         : return "kw_begin";
  case tok_kw_block         : return "kw_block";
  case tok_kw_body          : return "kw_body";
  case tok_kw_buffer        : return "kw_buffer";
  case tok_kw_bus           : return "kw_bus";
  case tok_kw_case          : return "kw_case";
  case tok_kw_component     : return "kw_component";
  case tok_kw_configuration : return "kw_configuration";
  case tok_kw_constant      : return "kw_constant";
  case tok_kw_disconnect    : return "kw_disconnect";
  case tok_kw_downto        : return "kw_downto";
  case tok_kw_else          : return "kw_else";
  case tok_kw_elsif         : return "kw_elsif";
  case tok_kw_end           : return "kw_end";
  case tok_kw_entity        : return "kw_entity";
  case tok_kw_exit          : return "kw_exit";
  case tok_kw_file          : return "kw_file";
  case tok_kw_for           : return "kw_for";
  case tok_kw_function      : return "kw_function";
  case tok_kw_generate      : return "kw_generate";
  case tok_kw_generic       : return "kw_generic";
  case tok_kw_group         : return "kw_group";
  case tok_kw_guarded       : return "kw_guarded";
  case tok_kw_if            : return "kw_if";
  case tok_kw_impure        : return "kw_impure";
  case tok_kw_in            : return "kw_in";
  case tok_kw_inertial      : return "kw_inertial";
  case tok_kw_inout         : return "kw_inout";
  case tok_kw_is            : return "kw_is";
  case tok_kw_label         : return "kw_label";
  case tok_kw_library       : return "kw_library";
  case tok_kw_linkage       : return "kw_linkage";
  case tok_kw_literal       : return "kw_literal";
  case tok_kw_loop          : return "kw_loop";
  case tok_kw_map           : return "kw_map";
  case tok_kw_mod           : return "kw_mod";
  case tok_kw_nand          : return "kw_nand";
  case tok_kw_new           : return "kw_new";
  case tok_kw_next          : return "kw_next";
  case tok_kw_nor           : return "kw_nor";
  case tok_kw_not           : return "kw_not";
  case tok_kw_null          : return "kw_null";
  case tok_kw_of            : return "kw_of";
  case tok_kw_on            : return "kw_on";
  case tok_kw_open          : return "kw_open";
  case tok_kw_or            : return "kw_or";
  case tok_kw_others        : return "kw_others";
  case tok_kw_out           : return "kw_out";
  case tok_kw_package       : return "kw_package";
  case tok_kw_port          : return "kw_port";
  case tok_kw_postponed     : return "kw_postponed";
  case tok_kw_procedural    : return "kw_procedural";
  case tok_kw_procedure     : return "kw_procedure";
  case tok_kw_process       : return "kw_process";
  case tok_kw_protected     : return "kw_protected";
  case tok_kw_pure          : return "kw_pure";
  case tok_kw_range         : return "kw_range";
  case tok_kw_record        : return "kw_record";
  case tok_kw_reference     : return "kw_reference";
  case tok_kw_register      : return "kw_register";
  case tok_kw_reject        : return "kw_reject";
  case tok_kw_rem           : return "kw_rem";
  case tok_kw_report        : return "kw_report";
  case tok_kw_return        : return "kw_return";
  case tok_kw_rol           : return "kw_rol";
  case tok_kw_ror           : return "kw_ror";
  case tok_kw_select        : return "kw_select";
  case tok_kw_severity      : return "kw_severity";
  case tok_kw_signal        : return "kw_signal";
  case tok_kw_shared        : return "kw_shared";
  case tok_kw_sla           : return "kw_sla";
  case tok_kw_sll           : return "kw_sll";
  case tok_kw_sra           : return "kw_sra";
  case tok_kw_srl           : return "kw_srl";
  case tok_kw_subtype       : return "kw_subtype";
  case tok_kw_then          : return "kw_then";
  case tok_kw_to            : return "kw_to";
  case tok_kw_transport     : return "kw_transport";
  case tok_kw_type          : return "kw_type";
  case tok_kw_unaffected    : return "kw_unaffected";
  case tok_kw_units         : return "kw_units";
  case tok_kw_until         : return "kw_until";
  case tok_kw_use           : return "kw_use";
  case tok_kw_variable      : return "kw_variable";
  case tok_kw_wait          : return "kw_wait";
  case tok_kw_when          : return "kw_when";
  case tok_kw_while         : return "kw_while";
  case tok_kw_with          : return "kw_with";
  case tok_kw_xnor          : return "kw_xnor";
  case tok_kw_xor           : return "kw_xor";
  }
  return "<unknown>";
}

#endif
