/*
 *	GLibFacade.h
 *	MultiMarkdown
 *	
 *	Created by Daniel Jalkut on 7/26/11.
 *  Modified by Fletcher T. Penney on 9/15/11 and 12/3/13.
 *	Modified by Dan Lowe on 1/3/12.
 *
 *	License for original code by Daniel Jalkut:
 *	
 *	Copyright 2011 Daniel Jalkut. All rights reserved.
 *	
 *	Permission is hereby granted, free of charge, to any person obtaining a copy of
 *	this software and associated documentation files (the “Software”), to deal in
 *	the Software without restriction, including without limitation the rights to
 *	use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 *	of the Software, and to permit persons to whom the Software is furnished to do
 *	so, subject to the following conditions:
 *	
 *	The above copyright notice and this permission notice shall be included in all
 *	copies or substantial portions of the Software.
 *	
 *	THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *	SOFTWARE.
 */

#ifndef __MARKDOWN_GLIB_FACADE__
#define __MARKDOWN_GLIB_FACADE__

/* peg_markdown uses the link symbol for its own purposes */
#define link MARKDOWN_LINK_IGNORED
#include <unistd.h>
#undef link

#include <stdbool.h>
#include <ctype.h>

typedef int gboolean;
typedef char gchar;

/* This style of bool is used in shared source code */
#if !defined(FALSE)
#define FALSE false
#endif
#if !defined(TRUE)
#define TRUE true
#endif

/* WE implement minimal mirror implementations of GLib's GString and GSList 
 * sufficient to cover the functionality required by MultiMarkdown.
 *
 * NOTE: THese are 100% clean, from-scratch implementations using only the 
 * GLib function prototype as guide for behavior.
 */

typedef struct 
{	
	/* Current UTF8 byte stream this string represents */
	char* str;

	/* Where in the str buffer will we add new characters */
	/* or append new strings? */
	unsigned long currentStringBufferSize;
	unsigned long currentStringLength;
} MMD_GString;

MMD_GString* mmd_g_string_new(char *startingString);
char* mmd_g_string_free(MMD_GString* ripString, bool freeCharacterData);

void mmd_g_string_append_c(MMD_GString* baseString, char appendedCharacter);
void mmd_g_string_append(MMD_GString* baseString, char *appendedString);

void mmd_g_string_prepend(MMD_GString* baseString, char* prependedString);

void mmd_g_string_append_printf(MMD_GString* baseString, char* format, ...);

void mmd_g_string_insert(MMD_GString* baseString, size_t pos, char * insertedString);
void mmd_g_string_insert_c(MMD_GString* baseString, size_t pos, char insertedCharacter);
void mmd_g_string_insert_printf(MMD_GString* baseString, size_t pos, char* format, ...);

void mmd_g_string_erase(MMD_GString* baseString, size_t pos, size_t len);

/* Just implement a very simple singly linked list. */

typedef struct _MMD_GSList
{
	void* data;	
	struct _MMD_GSList* next;
} MMD_GSList;

void mmd_g_slist_free(MMD_GSList* ripList);
MMD_GSList* mmd_g_slist_prepend(MMD_GSList* targetElement, void* newElementData);
MMD_GSList* mmd_g_slist_reverse(MMD_GSList* theList);

#endif
