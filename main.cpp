// g++ -o programa main.cpp 
// ./programa

#include "menu.h"

int main() {
    Menu menu;
   
    while (true) {
        menu.manejarEntradaUsuario();
    }
    return 0;
}

// eof - main.cpp