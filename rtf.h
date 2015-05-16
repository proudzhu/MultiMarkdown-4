#ifndef RTF_PARSER_H
#define RTF_PARSER_H

#include "parser.h"
#include "writer.h"

void begin_rtf_output(MMD_GString *out, node* list, scratch_pad *scratch);
void end_rtf_output(MMD_GString *out, node* list, scratch_pad *scratch);
void print_rtf_node_tree(MMD_GString *out, node *list, scratch_pad *scratch);
void print_rtf_node(MMD_GString *out, node *n, scratch_pad *scratch);
void print_rtf_localized_typography(MMD_GString *out, int character, scratch_pad *scratch);
void print_rtf_string(MMD_GString *out, char *str, scratch_pad *scratch);
void print_rtf_code_string(MMD_GString *out, char *str, scratch_pad *scratch);
void print_rtf_endnotes(MMD_GString *out, scratch_pad *scratch);
void pad_rtf(MMD_GString *out, int pad, scratch_pad *scratch);

#endif
