#include "game.h"
#include "ui/ui.h"

int main() {
    ui_init();
    game_loop();
    ui_cleanup();
    return 0;
}
