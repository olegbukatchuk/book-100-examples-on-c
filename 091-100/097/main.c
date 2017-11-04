#include <stdio.h>
#include <regex.h>
#include <ctype.h>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <sys/types.h>

#define PACKAGE "myip"
#define VERSION "1.0.0"

#define PIEXEPR "([0-9]{1,3})\\.([0-9]{1,3}\\.([0-9]{1,3})\\.([0-9]{1,3})"
#define EMEXPR  ".*@.*\\.([a-zA-Z]{1,3})$"
#define UREXPR  "(href|src)="

