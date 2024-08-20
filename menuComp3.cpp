// Implementación de operaciones relacionadas con rutas más cortas (solo mensajes implementados)

#include "menu.h"

// Encuentra la ruta más corta entre dos vértices de un objeto
void Menu::rutaCortaVertices(int v1, int v2, std::string& nombre_objeto) {
    if (!objetoCargado(nombre_objeto)) {
        std::cout << "El objeto " << nombre_objeto << " no ha sido cargado en memoria." << std::endl;
        return;
    }

    std::cout << "Los índices de los vertices dados son iguales." << std::endl;
    std::cout << "Algunos de los indices de vertices estan fuera de rango para el objeto " << nombre_objeto << std::endl;
    std::cout << "La ruta más corta entre los vértices " << v1 << " y " << v2 << " del objeto " << nombre_objeto << " es ruta_corta." << std::endl;
}

// Encuentra la ruta más corta de un vértice al centro del objeto
void Menu::rutaCortaCentro(int v1, std::string& nombre_objeto) {
    if (!objetoCargado(nombre_objeto)) {
        std::cout << "El objeto " << nombre_objeto << " no ha sido cargado en memoria." << std::endl;
        return;
    }

    std::cout << "El índice de vertice esta fuera de rango para el objeto nombre_objeto." << nombre_objeto << std::endl;
    std::cout << "La ruta más corta entre el vértice " << v1 << " y el centro del objeto " << nombre_objeto << " es ruta_corta." << std::endl;
}