#ifndef CONTROL_H
#define CONTROL_H

#include <stdint.h>
#include <stdarg.h>

typedef struct {
	char ctl_name;
	uint8_t ctl_argc;
	int8_t ctl_mxargc;
} ctl_t;

uint8_t ctl_print(ctl_t c, uint8_t argc, ...);

extern ctl_t CTL_ICH;     // insert n blank characters
extern ctl_t CTL_CUU;     // move cursor up n lines
extern ctl_t CTL_CUD;     // move cursor down n lines
extern ctl_t CTL_CUF;     // move cursor forward n characters
extern ctl_t CTL_CUB;     // move cursor backward n characters
extern ctl_t CTL_CNL;     // move cursor down n lines to column 1
extern ctl_t CTL_CPL;     // move cursor up n lines to column 1
extern ctl_t CTL_CHA;     // move cursor to column n in current row
extern ctl_t CTL_CUP;     // move cursor to y row and x column, origin at 1, 1
extern ctl_t CTL_ED;      // erase display
extern ctl_t CTL_EL;      // erase line
extern ctl_t CTL_IL;      // insert n blank lines
extern ctl_t CTL_DL;      // delete n lines
extern ctl_t CTL_DCH;     // delete n characters from current line
extern ctl_t CTL_ECH;     // erase n characters from current line
extern ctl_t CTL_HPR;     // same as CTL_CUF but origin is at 0
extern ctl_t CTL_VPA;     // move cursor to row n on current column
extern ctl_t CTL_VPR;     // move cursor down n lines
extern ctl_t CTL_HVP;     // same as CTL_CUP but origin is at 0, 0
extern ctl_t CTL_TBC;     // clear tab stops
extern ctl_t CTL_SM;      // set terminal mode
extern ctl_t CTL_RM;      // reset terminal mode
extern ctl_t CTL_SGR;     // set attributes (Set Graphics Rendition)
extern ctl_t CTL_DSR;     // terminal status report
extern ctl_t CTL_DECLL;   // set keyboard LEDs
extern ctl_t CTL_DECSTBM; // set terminal scrolling region
extern ctl_t CTL_SCL;     // save cursor location (abbreviation is unofficial, none present in the ECMA48 standard)
extern ctl_t CTL_RCL;     // restore cursor location (abbreviation is unofficial, none present in the ECMA48 standard)
extern ctl_t CTL_HPA;     // same as CTL_CHA but origin is at 0

extern uint8_t CTL_ED_TOC;
extern uint8_t CTL_ED_CLR;
extern uint8_t CTL_ED_CLRSCB;

extern uint8_t CTL_EL_LTOC;
extern uint8_t CTL_EL_LCLR;

extern uint8_t CTL_DSR_TREP;
extern uint8_t CTL_DSR_CPOS;

extern uint8_t CTL_DECLL_CLR;
extern uint8_t CTL_DECLL_SCRLK;
extern uint8_t CTL_DECLL_NUMLK;
extern uint8_t CTL_DECLL_CAPSLK;

extern uint8_t CTL_SGR_RESET; // reset all attributes
extern uint8_t CTL_SGR_BOLD; // bold font
extern uint8_t CTL_SGR_HBR; // half brightness
extern uint8_t CTL_SGR_UND; // underlined text
extern uint8_t CTL_SGR_CBL; // blinking cursor
extern uint8_t CTL_SGR_RVID; // reverse video (inverse colors)
extern uint8_t CTL_SGR_STRTH; // strikethrough
extern uint8_t CTL_SGR_NINT1; // disable bold font and half brightness OR enable doubly underlined text
extern uint8_t CTL_SGR_NINT2; // disable bold font and half brightness
extern uint8_t CTL_SGR_DUND; // disable underlined text
extern uint8_t CTL_SGR_DCBL; // disable blinking cursor
extern uint8_t CTL_SGR_DRVID; // disable reverse video (inverse colors)
extern uint8_t CTL_SGR_FC256; // set foreground color for 256color terminals
extern uint8_t CTL_SGR_DEFFG; // reset to default foreground color
extern uint8_t CTL_SGR_BC256; // set background color for 256color terminals

// color definition modes for 256color terminal color commands
extern uint8_t CTL_SGR_C256_RGB;
extern uint8_t CTL_SGR_C256_INDEX;

// ansi colors
extern uint8_t CTL_SGR_COLOR_FG_BLACK;
extern uint8_t CTL_SGR_COLOR_FG_RED;
extern uint8_t CTL_SGR_COLOR_FG_GREEN;
extern uint8_t CTL_SGR_COLOR_FG_BROWN;
extern uint8_t CTL_SGR_COLOR_FG_BLUE;
extern uint8_t CTL_SGR_COLOR_FG_MAGENTA;
extern uint8_t CTL_SGR_COLOR_FG_CYAN;
extern uint8_t CTL_SGR_COLOR_FG_LGRAY;

extern uint8_t CTL_SGR_COLOR_BG_BLACK;
extern uint8_t CTL_SGR_COLOR_BG_RED;
extern uint8_t CTL_SGR_COLOR_BG_GREEN;
extern uint8_t CTL_SGR_COLOR_BG_BROWN;
extern uint8_t CTL_SGR_COLOR_BG_BLUE;
extern uint8_t CTL_SGR_COLOR_BG_MAGENTA;
extern uint8_t CTL_SGR_COLOR_BG_CYAN;
extern uint8_t CTL_SGR_COLOR_BG_LGRAY;
extern uint8_t CTL_SGR_COLOR_BG_DEFAULT;

// 256color terminal colors
extern uint8_t CTL_SGR_C256_FG_DGRAY;
extern uint8_t CTL_SGR_C256_FG_LRED;
extern uint8_t CTL_SGR_C256_FG_LGREEN;
extern uint8_t CTL_SGR_C256_FG_YELLOW;
extern uint8_t CTL_SGR_C256_FG_LBLUE;
extern uint8_t CTL_SGR_C256_FG_LMAGENTA;
extern uint8_t CTL_SGR_C256_FG_LCYAN;
extern uint8_t CTL_SGR_C256_FG_WHITE;

extern uint8_t CTL_SGR_C256_BG_DGRAY;
extern uint8_t CTL_SGR_C256_BG_LRED;
extern uint8_t CTL_SGR_C256_BG_LGREEN;
extern uint8_t CTL_SGR_C256_BG_YELLOW;
extern uint8_t CTL_SGR_C256_BG_LBLUE;
extern uint8_t CTL_SGR_C256_BG_LMAGENTA;
extern uint8_t CTL_SGR_C256_BG_LCYAN;
extern uint8_t CTL_SGR_C256_BG_WHITE;

#endif
