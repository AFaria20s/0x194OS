#ifndef VGA_H
#define VGA_H

#include <stddef.h>
#include <stdint.h>

extern size_t t_row;
extern size_t t_column;
extern uint8_t t_color;

void t_putchar(char c);
void t_putentryat(char c, uint8_t color, size_t x, size_t y);
void t_print(const char *data);
void t_setcolor(uint8_t color);

#endif