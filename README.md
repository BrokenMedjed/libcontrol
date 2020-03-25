# libcontrol
A convenience library for C programmers who want to control the UNIX terminal a little better but who don't want to remember all of the control codes by heart or RTFM all the time.

It comes with most of the ECMA-48 CSI escape codes and a variadic function, `ctl_print`, to use them. You can also implement your own escape codes that I haven't added by using the `ctl_t` struct typedef that's defined in the `control.h` header file.
If you're too lazy to read it...

## Usage & examples
The definition of `ctl_t` is as follows:
```c
typedef struct {
  char ctl_name;     // control character
  uint8_t ctl_argc;  // minimum arguments for escape code
  int8_t ctl_mxargc; // maximum arguments for escape code (int8_t because -1 declares infinite max args)
} ctl_t;
```
And the definition of `ctl_print` is:
```c
uint8_t ctl_print(ctl_t c, uint8_t argc, ...);
```
where `c` is the control character, `argc` is the number of arguments passed to `c` and the following arguments are arguments for `c`.
Here's an example program that gets the cursor location using the Device Status Report (DSR) CSI and then prints it to the display in y:x format (you'll have to send an EOT to the program for it to print):
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include "control.h"

// CTL_DSR = Device Status Report, CTL_DSR_CPOS = cursor position argument for CTL_DSR
// CTL_DSR_CPOS writes \033[<y>;<x>R to stdin
int main() {
	ctl_print(CTL_DSR, 1, CTL_DSR_CPOS);
	char *pos_chr = malloc(6 * sizeof(char));
	if (!pos_chr) {
    		printf("malloc fail\n");
    		return 1;
  	}
	memset(pos_chr, 0, 6 * sizeof(char)); // I really hope you don't have a ridiculously huge terminal
	uint8_t pos_chr_idx = 0;
  	char chr;
	while ((chr = (char) fgetc(stdin)) != 'R') {
		if (chr == ';' || isdigit(chr)) {
			if (chr != ';') pos_chr[pos_chr_idx++] = chr; else {
				printf("%s:", pos_chr);
				memset(pos_chr, 0, 6 * sizeof(char));
				pos_chr_idx = 0;
			}
		}
	}
	printf("%s\n", pos_chr);
	memset(pos_chr, 0, 6 * sizeof(char));
	free(pos_chr);
	return 0;
}
```
## Compilation
Just run these on the terminal:
```sh
cd libcontrol
sh compile.sh
```
That'll create a static library, `libcontrol.a`, that you can copy to your projects along with the `control.h` header file.
