#ifndef HTML_PARSER_H
#define HTML_PARSER_H

#include "parser.h"
#include "writer.h"


void print_html_node_tree(MMD_GString *out, node *list, scratch_pad *scratch);
void print_html_node(MMD_GString *out, node *n, scratch_pad *scratch);
void print_html_localized_typography(MMD_GString *out, int character, scratch_pad *scratch);
void print_html_string(MMD_GString *out, char *str, scratch_pad *scratch);
void print_html_endnotes(MMD_GString *out, scratch_pad *scratch);

#endif
