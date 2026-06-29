// kernel.cpp
#include "init.h"
#include "vga.h"
#include "keyboard.h"

extern "C" void kmain() {
    init();
    cout('W'); cout('e'); cout('l'); cout('c'); cout('o'); cout('m'); cout('e');cout(' ');cout('t'); cout('o');cout(' ');cout('J'); cout('o'); cout('b'); cout('O'); cout('S');
    cursor_x = 0;
    cursor_y = 1;
    cout('>'); cout(' ');
    
    while(1) {
        IOKeyboard();
        __asm__ volatile("nop"); 
    }
}