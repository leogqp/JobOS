#ifndef VGA_H
#define VGA_H
#include "init.h" 

inline void cout(char c) {
    if (c == '\b') {
        if (cursor_x > 0) {
            cursor_x--; 
            int index = (cursor_y * 160) + (cursor_x * 2);
            video_memory[index] = ' ';     
            video_memory[index + 1] = 0x07; 
        }
        return;
    }

    if (c == '\n') {
        cursor_x = 0;
        cursor_y++;
        if (cursor_y >= 25) cursor_y = 0; 
        return;
    }

    int index = (cursor_y * 160) + (cursor_x * 2);
    video_memory[index] = c;
    video_memory[index + 1] = 0x0F; // Blanco brillante

    cursor_x++;

    if (cursor_x >= 80) {
        cursor_x = 0;
        cursor_y++;
        if (cursor_y >= 25) cursor_y = 0;
    }
}
inline void printString(AnsiString texto) {
    for (int i = 0; texto[i] != '\0'; i++) {
        cout(texto[i]);
    }
}

#endif