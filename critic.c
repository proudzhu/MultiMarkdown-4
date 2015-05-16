/*

	critic.c -- CriticMarkup preprocessor

	<http://criticmarkup.com>

	(c) 2013-2015 Fletcher T. Penney (http://fletcherpenney.net/).

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License or the MIT
	license.  See LICENSE for details.
	
	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

*/

#include "critic.h"

void print_critic_accept_node_tree(MMD_GString *out, node *list, scratch_pad *scratch) {
	while (list != NULL) {
		print_critic_accept_node(out, list, scratch);
		list = list->next;
	}
}

void print_critic_reject_node_tree(MMD_GString *out, node *list, scratch_pad *scratch) {
	while (list != NULL) {
		print_critic_reject_node(out, list, scratch);
		list = list->next;
	}
}

void print_critic_html_highlight_node_tree(MMD_GString *out, node *list, scratch_pad *scratch) {
	while (list != NULL) {
		print_critic_html_highlight_node(out, list, scratch);
		list = list->next;
	}
}

void print_critic_accept_node(MMD_GString *out, node *n, scratch_pad *scratch) {
	if (n == NULL)
		return;
	
	switch (n->key) {
		case LIST:
		case CRITICSUBSTITUTION:
			print_critic_accept_node_tree(out, n->children, scratch);
			break;
		case CRITICDELETION:
		case CRITICCOMMENT:
			break;
		case CRITICHIGHLIGHT:
		case CRITICADDITION:
		default:
			mmd_g_string_append_printf(out,"%s",n->str);
			break;
	}
}

void print_critic_reject_node(MMD_GString *out, node *n, scratch_pad *scratch) {
	if (n == NULL)
		return;

	switch (n->key) {
		case LIST:
		case CRITICSUBSTITUTION:
			print_critic_reject_node_tree(out, n->children, scratch);
			break;
		case CRITICADDITION:
		case CRITICCOMMENT:
			break;
		case CRITICHIGHLIGHT:
		case CRITICDELETION:
		default:
			mmd_g_string_append_printf(out,"%s",n->str);
			break;
	}
}

void print_critic_html_highlight_node(MMD_GString *out, node *n, scratch_pad *scratch) {
	if (n == NULL)
		return;
	
	switch (n->key) {
		case LIST:
			print_critic_html_highlight_node_tree(out, n->children, scratch);
			break;
		case CRITICSUBSTITUTION:
			print_critic_html_highlight_node_tree(out, n->children, scratch);
			break;
		case CRITICADDITION:
			mmd_g_string_append_printf(out,"<ins>%s</ins>",n->str);
			break;
		case CRITICCOMMENT:
			/* Hide comments for now */
			/* g_string_append_printf(out, "<span class=\"critic comment\">%s</span>", n->str); */
			break;
		case CRITICHIGHLIGHT:
			mmd_g_string_append_printf(out,"<mark>%s</mark>",n->str);
			break;
		case CRITICDELETION:
			mmd_g_string_append_printf(out,"<del>%s</del>",n->str);
			break;
		default:
			mmd_g_string_append_printf(out,"%s",n->str);
			break;
	}
}
