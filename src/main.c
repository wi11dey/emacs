/*
 *	main.c

 *	uEmacs/PK 4.0
 *
 *	Based on:
 *
 *	MicroEMACS 3.9
 *	Written by Dave G. Conroy.
 *	Substantially modified by Daniel M. Lawrence
 *	Modified by Petri Kutvonen
 *
 *	MicroEMACS 3.9 (c) Copyright 1987 by Daniel M. Lawrence
 *
 *	Original statement of copying policy:
 *
 *	MicroEMACS 3.9 can be copied and distributed freely for any
 *	non-commercial purposes. MicroEMACS 3.9 can only be incorporated
 *	into commercial software with the permission of the current author.
 *
 *	No copyright claimed for modifications made by Petri Kutvonen.
 *
 *	This file contains the main driving routine, and some keyboard
 *	processing code.
 *
 * REVISION HISTORY:
 *
 * 1.0  Steve Wilhite, 30-Nov-85
 *
 * 2.0  George Jones, 12-Dec-85
 *
 * 3.0  Daniel Lawrence, 29-Dec-85
 *
 * 3.2-3.6 Daniel Lawrence, Feb...Apr-86
 *
 * 3.7	Daniel Lawrence, 14-May-86
 *
 * 3.8	Daniel Lawrence, 18-Jan-87
 *
 * 3.9	Daniel Lawrence, 16-Jul-87
 *
 * 3.9e	Daniel Lawrence, 16-Nov-87
 *
 * After that versions 3.X and Daniel Lawrence went their own ways.
 * A modified 3.9e/PK was heavily used at the University of Helsinki
 * for several years on different UNIX, VMS, and MSDOS platforms.
 *
 * This modified version is now called eEmacs/PK.
 *
 * 4.0	Petri Kutvonen, 1-Sep-91
 *
 */

#include "stdlib.hh"

#include "main.hh"

void usage(int status)
{
  printf("Usage: emacs\n");
  printf("   or: emacs [options]\n\n");
  printf("      +          start at the end of file\n");
  printf("      +<n>       start at line <n>\n");
  printf("      -g[G]<n>   go to line <n>\n");
  printf("      --help     display this help and exit\n");
  printf("      --version  output version information and exit\n");

  exit(status);
}

uint8_t* heap;
uint8_t* data;
char* cbuf;

int main(int argc, char **argv)
{
	heap = data = reinterpret_cast<uint8_t*>(round_up(reinterpret_cast<uintptr_t>(end), PAGESIZE));
	cbuf = (char*) malloc(1);

	if (argc < 2) {
		usage(1);
	}

	return 0;
}
