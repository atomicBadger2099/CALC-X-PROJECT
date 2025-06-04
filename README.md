<h1>THE CALC-X PROJECT</h1>

<i> fully functional calculator to be run in Linux BASH Terminal</i>


Welcome to the SYS-CALC PROJECT.

This project is an advanced calculator run on Linux Terminal, written in GNU C99.

It was created by Dwayne Brock on 6-4-2025, using the Claude AI to
	assist in coding.

This software is designated as having a GNU General Public license.

The GNU General Public license may be read at:
	https://www.gnu.org/licenses/gpl-3.0.html

You may freely copy, edit, and share this software (and are encouraged to do so!)
	as you will. You are encouraged to include the name of the original author, Dwayne Brock, 
	if you maintain the code in its original form.

This software is designated as freeware, no fee will be charged in its sharing, duplication, or use.

This project's code will handle the range of mathematics operations accurately, from basic
arithmetic, to advanced operations such as square roots, powers, and log functions, to
sine, cosine and tangent trigonometry functions.

This software is designed to be run on a Linux Terminal or BASH, using GCC for compiling.
If you use a different environment, its function is not guaranteed.
The original version was designed and tested on Ubuntu 24.04 using GCC as a compiler and run in BASH.


TO COMPILE THIS CODE IN GCC, USE THE FOLLOWING COMMAND IN BASH:

	gcc -std=c99 -Wall -Wextra -o calculator main.c basic_ops.c advanced_ops.c trigonometry.c utils.c -lm



TO USE THIS PROGRAM IN BASH:

1. Basic Usage - Simple execution:
	./calculator

2. Command-Line Options - View help information:
	./calculator --help or ./calculator -h

3. Check Version:
	./calculator --version or ./calculator -v

4. Enable Debug Mode:
	./calculator --debug or ./calculator -d
