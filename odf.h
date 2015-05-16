#ifndef ODF_PARSER_H
#define ODF_PARSER_H

#include "parser.h"
#include "html.h"		/* Use some of the HTML routines */
#include "writer.h"

void begin_odf_output(MMD_GString *out, node* list, scratch_pad *scratch);
void print_odf_node_tree(MMD_GString *out, node *list, scratch_pad *scratch);
void print_odf_node(MMD_GString *out, node *n, scratch_pad *scratch);
void print_odf_section_and_children(MMD_GString *out, node *list, scratch_pad *scratch);
void end_odf_output(MMD_GString *out, node* list, scratch_pad *scratch);
void print_odf_string(MMD_GString *out, char *str);
void print_odf_code_string(MMD_GString *out, char *str);
void print_odf_header(MMD_GString *out);
void print_odf_footer(MMD_GString *out);

#endif
