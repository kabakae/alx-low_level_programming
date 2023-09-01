#!/bin/bash
ar -rc liball.a *.o
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 -c *.c
