#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "control.h"

ctl_t CTL_ICH     = {'@', 1,  1}; // insert n blank characters
ctl_t CTL_CUU     = {'A', 1,  1}; // move cursor up n lines
ctl_t CTL_CUD     = {'B', 1,  1}; // move cursor down n lines
ctl_t CTL_CUF     = {'C', 1,  1}; // move cursor forward n characters
ctl_t CTL_CUB     = {'D', 1,  1}; // move cursor backward n characters
ctl_t CTL_CNL     = {'E', 1,  1}; // move cursor down n lines to column 1
ctl_t CTL_CPL     = {'F', 1,  1}; // move cursor up n lines to column 1
ctl_t CTL_CHA     = {'G', 1,  1}; // move cursor to column n in current row
ctl_t CTL_CUP     = {'H', 2,  2}; // move cursor to y row and x column, origin at 1, 1
ctl_t CTL_ED      = {'J', 0,  1}; // erase display
ctl_t CTL_EL      = {'K', 0,  1}; // erase line
ctl_t CTL_IL      = {'L', 1,  1}; // insert n blank lines
ctl_t CTL_DL      = {'M', 1,  1}; // delete n lines
ctl_t CTL_DCH     = {'P', 1,  1}; // delete n characters from current line
ctl_t CTL_ECH     = {'X', 1,  1}; // erase n characters from current line
ctl_t CTL_HPR     = {'a', 1,  1}; // same as CTL_CUF but origin is at 0
ctl_t CTL_VPA     = {'d', 1,  1}; // move cursor to row n on current column
ctl_t CTL_VPR     = {'e', 1,  1}; // move cursor down n lines
ctl_t CTL_HVP     = {'f', 2,  2}; // same as CTL_CUP but origin is at 0, 0
ctl_t CTL_TBC     = {'g', 0,  1}; // clear tab stops
ctl_t CTL_SM      = {'h', 1,  1}; // set terminal mode
ctl_t CTL_RM      = {'l', 0,  0}; // reset terminal mode
ctl_t CTL_SGR     = {'m', 1, -1}; // set attributes (Set Graphics Rendition)
ctl_t CTL_DSR     = {'n', 1,  1}; // terminal status report
ctl_t CTL_DECLL   = {'q', 1,  1}; // set keyboard LEDs
ctl_t CTL_DECSTBM = {'r', 2,  2}; // set terminal scrolling region
ctl_t CTL_SCL     = {'s', 0,  0}; // save cursor location (abbreviation unofficial, none present in ECMA-48)
ctl_t CTL_RCL     = {'u', 0,  0}; // restore cursor location (abbreviation unofficial, none present in ECMA-48)
ctl_t CTL_HPA     = {'`', 1,  1}; // same as CTL_CHA but origin is at 0

uint8_t CTL_ED_TOC    = 1;
uint8_t CTL_ED_CLR    = 2;
uint8_t CTL_ED_CLRSCB = 3;

uint8_t CTL_EL_LTOC   = 1;
uint8_t CTL_EL_LCLR   = 2;

uint8_t CTL_DSR_TREP  = 5;
uint8_t CTL_DSR_CPOS  = 6;

uint8_t CTL_DECLL_CLR    = 0;
uint8_t CTL_DECLL_SCRLK  = 1;
uint8_t CTL_DECLL_NUMLK  = 2;
uint8_t CTL_DECLL_CAPSLK = 3;

uint8_t CTL_SGR_RESET =  0; // reset all attributes
uint8_t CTL_SGR_BOLD  =  1; // bold font
uint8_t CTL_SGR_HBR   =  2; // half brightness
uint8_t CTL_SGR_UND   =  4; // underlined text
uint8_t CTL_SGR_CBL   =  5; // blinking cursor
uint8_t CTL_SGR_RVID  =  7; // reverse video (inverse colors)
uint8_t CTL_SGR_STRTH =  9; // strikethrough
uint8_t CTL_SGR_NINT1 = 21; // disable bold font and half brightness OR enable doubly underlined text
uint8_t CTL_SGR_NINT2 = 22; // disable bold font and half brightness
uint8_t CTL_SGR_DUND  = 24; // disable underlined text
uint8_t CTL_SGR_DCBL  = 25; // disable blinking cursor
uint8_t CTL_SGR_DRVID = 27; // disable reverse video (inverse colors)
uint8_t CTL_SGR_FC256 = 38; // set foreground color for 256color terminals
uint8_t CTL_SGR_DEFFG = 39; // reset to default foreground color
uint8_t CTL_SGR_BC256 = 48; // set background color for 256color terminals

// color definition modes for 256color terminal color commands
uint8_t CTL_SGR_C256_RGB   = 2;
uint8_t CTL_SGR_C256_INDEX = 5;

// ansi colors
uint8_t CTL_SGR_COLOR_FG_BLACK   =  30;
uint8_t CTL_SGR_COLOR_FG_RED     =  31;
uint8_t CTL_SGR_COLOR_FG_GREEN   =  32;
uint8_t CTL_SGR_COLOR_FG_BROWN   =  33;
uint8_t CTL_SGR_COLOR_FG_BLUE    =  34;
uint8_t CTL_SGR_COLOR_FG_MAGENTA =  35;
uint8_t CTL_SGR_COLOR_FG_CYAN    =  36;
uint8_t CTL_SGR_COLOR_FG_LGRAY   =  37;

uint8_t CTL_SGR_COLOR_BG_BLACK   =  40;
uint8_t CTL_SGR_COLOR_BG_RED     =  41;
uint8_t CTL_SGR_COLOR_BG_GREEN   =  42;
uint8_t CTL_SGR_COLOR_BG_BROWN   =  43;
uint8_t CTL_SGR_COLOR_BG_BLUE    =  44;
uint8_t CTL_SGR_COLOR_BG_MAGENTA =  45;
uint8_t CTL_SGR_COLOR_BG_CYAN    =  46;
uint8_t CTL_SGR_COLOR_BG_LGRAY   =  47;
uint8_t CTL_SGR_COLOR_BG_DEFAULT =  48;

// 256color terminal colors
uint8_t CTL_SGR_C256_FG_DGRAY    =  90;
uint8_t CTL_SGR_C256_FG_LRED     =  91;
uint8_t CTL_SGR_C256_FG_LGREEN   =  92;
uint8_t CTL_SGR_C256_FG_YELLOW   =  93;
uint8_t CTL_SGR_C256_FG_LBLUE    =  94;
uint8_t CTL_SGR_C256_FG_LMAGENTA =  95;
uint8_t CTL_SGR_C256_FG_LCYAN    =  96;
uint8_t CTL_SGR_C256_FG_WHITE    =  97;

uint8_t CTL_SGR_C256_BG_DGRAY    = 100;
uint8_t CTL_SGR_C256_BG_LRED     = 101;
uint8_t CTL_SGR_C256_BG_LGREEN   = 102;
uint8_t CTL_SGR_C256_BG_YELLOW   = 103;
uint8_t CTL_SGR_C256_BG_LBLUE    = 104;
uint8_t CTL_SGR_C256_BG_LMAGENTA = 105;
uint8_t CTL_SGR_C256_BG_LCYAN    = 106;
uint8_t CTL_SGR_C256_BG_WHITE    = 107;

uint8_t ctl_print(ctl_t c, uint8_t argc, ...) {
	va_list args;
	va_start(args, argc);
	if (c.ctl_mxargc > -1 && argc > c.ctl_mxargc) return 1;
	if (argc < c.ctl_argc) return 1;
	printf("\033[");
	for (uint8_t i = 0; i < argc; i++) {
		printf("%d", va_arg(args, int));
		if (i < argc - 1) putchar(';');
	}
	putchar(c.ctl_name);
	va_end(args);
	return 0;
}
