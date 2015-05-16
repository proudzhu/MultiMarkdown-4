#ifndef OPML_PARSER_H
#define OPML_PARSER_H

#include "parser.h"
#include "writer.h"

void begin_opml_output(MMD_GString *out, node* list, scratch_pad *scratch);
void print_opml_node_tree(MMD_GString *out, node *list, scratch_pad *scratch);
void print_opml_node(MMD_GString *out, node *n, scratch_pad *scratch);
void print_opml_section_and_children(MMD_GString *out, node *list, scratch_pad *scratch);
void end_opml_output(MMD_GString *out, node* list, scratch_pad *scratch);
void print_opml_string(MMD_GString *out, char *str);


#endif
