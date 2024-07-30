#include "menu.h"

int main() {
    Menu menu;
    menu.mostrarMenu();
    while (true) {
        menu.manejarEntradaUsuario();
    }
    return 0;
}

// eof - main.cpp
