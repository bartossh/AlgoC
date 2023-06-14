#ifndef DIAMOND_H
#define DIAMOND_H

void set(char *original, int len, int pos, char l);
char **make_diamond(const char letter);
void free_diamond(char **diamond);

#endif
