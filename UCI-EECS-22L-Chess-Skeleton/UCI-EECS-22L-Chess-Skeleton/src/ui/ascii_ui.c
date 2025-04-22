
#include <stdio.h>
#include "ui.h"

void ui_init() {}

void ui_draw_board() {
    printf("  a b c d e f g h\n");
    for (int i = 8; i >= 1; i--) {
        printf("%d ", i);
        for (int j = 0; j < 8; j++) {
            printf(". ");
        }
        printf("%d\n", i);
    }
    printf("  a b c d e f g h\n");
}

void ui_show_message(const char* msg) {
    printf("%s\n", msg);
}

void ui_cleanup() {}
