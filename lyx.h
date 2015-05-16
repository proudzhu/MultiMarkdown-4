#ifndef LYX_PARSER_H
#define LYX_PARSER_H

#include "parser.h"
#include "writer.h"

/* allow the user to change the heading levels */

extern MMD_GString *heading_name[7];

/* Lyx likes to wrap strings in "environments" */
enum lyx_environment{
  LYX_NONE,
  LYX_STANDARD,
  LYX_CODE,
  LYX_PLAIN	
};


void perform_lyx_output(MMD_GString *out, node* list, scratch_pad *scratch);
bool begin_lyx_output(MMD_GString *out, node* list, scratch_pad *scratch);
void print_lyx_node_tree(MMD_GString *out, node *list, scratch_pad *scratch, bool no_newline);
void end_lyx_output(MMD_GString *out, node* list, scratch_pad *scratch);
void print_lyx_node(MMD_GString *out, node *n, scratch_pad *scratch, bool no_newline);
void print_lyx_localized_typography(MMD_GString *out, unsigned char character, scratch_pad *scratch);
void print_lyx_string(MMD_GString *out,char *str, scratch_pad *scratch,short environment);
void print_lyx_url(MMD_GString *out, char *str, scratch_pad *scratch);
void print_lyx_endnotes(MMD_GString *out, scratch_pad *scratch);
void lyx_get_table_dimensions(node* list, int *rows, int *cols, scratch_pad *scratch);
void add_prefixes(node *list, node *root, scratch_pad *scratch);
void update_links(char *label,char *prefix, scratch_pad *scratch);
char *prefix_label(char *prefix, char *label, bool pound);
void update_link_source(char *source, char *prefix,node *n);
void print_escaped_node_tree(MMD_GString *out, node *n);
void print_escaped_node(MMD_GString *out, node *n);
char * escape_string(char *str);
#endif
