#ifndef BEAMER_PARSER_H
#define BEAMER_PARSER_H

#include "parser.h"
#include "latex.h"

void print_beamer_node_tree(MMD_GString *out, node *list, scratch_pad *scratch);
void print_beamer_node(MMD_GString *out, node *n, scratch_pad *scratch);
void print_beamer_endnotes(MMD_GString *out, scratch_pad *scratch);

#endif
