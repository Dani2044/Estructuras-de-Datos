// Implementación de operaciones relacionadas con vértices más cercanos (solo mensajes implementados)

#include "menu.h"

// Encuentra el vértice más cercano en un objeto específico
void Menu::verticeCercanoObjeto(double px, double py, double pz, std::string& nombre_objeto) {
    if (!objetoCargado(nombre_objeto)) {
        std::cout << "El objeto " << nombre_objeto << " no ha sido cargado en memoria." << std::endl;
        return;
    }

    std::cout << "El vértice más cercano al punto (" << px << ", " << py << ", " << pz << ") es el vértice i con coordenadas (vx, vy, vz) a una distancia de valor_distancia." << std::endl;
}

// Encuentra el vértice más cercano en todos los objetos
void Menu::verticeCercanoTodosObjetos(double px, double py, double pz) {
    if (objetosCargados.empty()) {
        std::cout << "Ningún objeto ha sido cargado en memoria." << std::endl;
        return;
    }

    std::cout << "El vértice más cercano al punto (" << px << ", " << py << ", " << pz << ") es el vértice i del objeto nombre_objeto con coordenadas (vx, vy, vz) a una distancia de valor_distancia." << std::endl;
}

// Encuentra los vértices más cercanos a las esquinas de la caja de ajuste
void Menu::verticesCercanosCaja(std::string& nombre_objeto) {
    if (!objetoCargado(nombre_objeto)) {
        std::cout << "El objeto " << nombre_objeto << " no ha sido cargado en memoria." << std::endl;
        return;
    }

    std::cout << "Los vértices del objeto " << nombre_objeto << " más cercanos a las esquinas de la caja de ajuste son: vértices_x, vértices_y, vértices_z." << std::endl;
}