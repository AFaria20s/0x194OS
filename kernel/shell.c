#include "../include/vga.h"

#define BUFFER_SIZE 256

static char input_buffer[BUFFER_SIZE];
static int buffer_index = 0;

void shell_prompt(void) {
    t_print("$c404$f@$30x194$f:~$ ");
}

void shell_process(void) {
    input_buffer[buffer_index] = '\0'; // terminate string

    t_putchar('\n');

    buffer_index = 0;
    shell_prompt();
}

void shell_input(char c) {
    if (c == '\n') {
        shell_process();
    } else if (c == '\b') {
        if (buffer_index > 0) {
            buffer_index--;
            if (t_column > 0) t_column--;
            t_putentryat(' ', t_color, t_column, t_row);
        }
    } else if (buffer_index < BUFFER_SIZE - 1) {
        input_buffer[buffer_index++] = c;
        t_putchar(c);
    }
}