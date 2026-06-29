#ifndef INIT_H
#define INIT_H

using AnsiString = const char*;
inline char* const video_memory = (char*) 0xb8000;

inline int cursor_x = 0;
inline int cursor_y = 0;

inline void init() {
    for (int i = 0; i < 4000; i += 2) {
        video_memory[i] = ' ';
        video_memory[i+1] = 0x07;
    }
    cursor_x = 0;
    cursor_y = 0;
}

#endif