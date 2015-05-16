#ifndef TOC_PARSER_H
#define TOC_PARSER_H

#include "parser.h"
#include "writer.h"

void begin_toc_output(MMD_GString *out, node* list, scratch_pad *scratch);
void print_toc_node_tree(MMD_GString *out, node *list, scratch_pad *scratch);
void print_toc_node(MMD_GString *out, node *n, scratch_pad *scratch);
void print_toc_section_and_children(MMD_GString *out, node *list, scratch_pad *scratch);
void end_toc_output(MMD_GString *out, node* list, scratch_pad *scratch);
void print_toc_string(MMD_GString *out, char *str);


#endif
