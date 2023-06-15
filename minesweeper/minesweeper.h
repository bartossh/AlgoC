#ifndef MINESWEEPER_H
#define MINESWEEPER_H
#include <stddef.h>


void count_and_mark(char **annotation, int i, int j, int rows, int len);
char **annotate(const char **minefield, const size_t rows);
void free_annotation(char **annotation);

#endif
