#ifndef LYX_BEAMER_PARSER_H
#define LYX_BEAMER_PARSER_H

#include "parser.h"
#include "lyx.h"

void print_lyxbeamer_node_tree(MMD_GString *out, node *list, scratch_pad *scratch,bool no_newline);
void print_lyxbeamer_node(MMD_GString *out, node *n, scratch_pad *scratch,bool no_newline);
void print_lyxbeamer_endnotes(MMD_GString *out, scratch_pad *scratch);

#endif
