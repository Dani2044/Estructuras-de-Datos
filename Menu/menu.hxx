#ifndef __MENU__HXX__
#define __MENU__HXX__

#include "menu.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

// Constructor
Menu::Menu() {
    objetosCargados.clear();
    std::cout << "Bienvenido al sistema de gestión de objetos." << std::endl;
}

// Verifica si un objeto está cargado
bool Menu::objetoCargado(std::string& nombre_objeto) {
    return std::find(objetosCargados.begin(), objetosCargados.end(), nombre_objeto) != objetosCargados.end(); // Find devuelve un iterador al primer elemento que coincide con el valor buscado o al final del contenedor si no se encuentra
}

// Muestra el menú
void Menu::mostrarMenu() {
    std::cout << "A continuación se presentan las opciones con sus respectivos comandos.\nDigite 'ayuda' para más información." << std::endl;
    std::cout << "1. Cargar objeto: cargar nombre_archivo" << std::endl;
    std::cout << "2. Listar objetos: listado" << std::endl;
    std::cout << "3. Crear caja de ajuste: envolvente nombre_objeto" << std::endl;
    std::cout << "4. Crear caja de ajuste global: envolvente" << std::endl;
    std::cout << "5. Eliminar objeto: descargar nombre_objeto" << std::endl;
    std::cout << "6. Guardar objeto: guardar nombre_objeto nombre_archivo" << std::endl;
    std::cout << "7. Buscar vértice más cercano (objeto específico): v_cercano px py pz nombre_objeto" << std::endl;
    std::cout << "8. Buscar vértice más cercano (todos los objetos): v_cercano px py pz" << std::endl;
    std::cout << "9. Buscar vértices más cercanos a su caja: v_cercanos_caja nombre_objeto" << std::endl;
    std::cout << "10. Ruta más corta entre vértices: ruta_corta i1 i2 nombre_objeto" << std::endl;
    std::cout << "11. Ruta más corta al centro: ruta_corta_centro i1 nombre_objeto" << std::endl;
    std::cout << "12. Salir: salir" << std::endl;
}

// Maneja la entrada del usuario
void Menu::manejarEntradaUsuario() {
    std::string entrada;
    std::cout << "$ ";
    std::getline(std::cin, entrada);

    std::istringstream ss(entrada);
    std::string comando;
    ss >> comando;

    if (comando == "cargar") { 
        std::string nombre_archivo;
        ss >> nombre_archivo;
        cargarObjeto(nombre_archivo);
    } else if (comando == "listado") {
        listarObjetosCargados();
    } else if (comando == "envolvente") {
        std::string nombre_objeto;
        if (ss >> nombre_objeto) {
            crearCajaDeAjuste(nombre_objeto);
        } else {
            crearCajaDeAjusteGlobal();
        }
    } else if (comando == "descargar") {
        std::string nombre_objeto;
        ss >> nombre_objeto;
        descargarObjeto(nombre_objeto);
    } else if (comando == "guardar") {
        std::string nombre_objeto, nombre_archivo;
        ss >> nombre_objeto >> nombre_archivo;
        guardarObjeto(nombre_objeto, nombre_archivo);
    } else if (comando == "v_cercano") {
        double px, py, pz;
        ss >> px >> py >> pz;
        std::string nombre_objeto;
        if (ss >> nombre_objeto) {
            verticeCercanoObjeto(px, py, pz, nombre_objeto);
        } else {
            verticeCercanoTodosObjetos(px, py, pz);
        }
    } else if (comando == "v_cercanos_caja") {
        std::string nombre_objeto;
        ss >> nombre_objeto;
        verticesCercanosCaja(nombre_objeto);
    } else if (comando == "ruta_corta") {
        int i1, i2;
        std::string nombre_objeto;
        ss >> i1 >> i2 >> nombre_objeto;
        rutaCortaVertices(i1, i2, nombre_objeto);
    } else if (comando == "ruta_corta_centro") {
        int i1;
        std::string nombre_objeto;
        ss >> i1 >> nombre_objeto;
        rutaCortaCentro(i1, nombre_objeto);
    } else if (comando == "salir") {
        salirPrograma();
    } else if (comando == "ayuda") {
        mostrarAyuda();
    } else {
        std::cout << "Opción no válida." << std::endl;
    }
}

// Muestra la información de ayuda
void Menu::mostrarAyuda() {
    std::ifstream archivo_ayuda("ayuda.txt");
    if (archivo_ayuda.is_open()) {
        std::string linea;
        while (std::getline(archivo_ayuda, linea)) {
            std::cout << linea << std::endl;
        }
        archivo_ayuda.close();
    } else {
        std::cout << "No se pudo abrir el archivo de ayuda." << std::endl;
    }
}

// Salir del programa
void Menu::salirPrograma() {
    std::cout << "Saliendo del programa..." << std::endl;
    exit(0);
}

// Carga un objeto
void Menu::cargarObjeto(std::string& nombre_archivo) {
    std::cout << "El archivo " << nombre_archivo << " no contiene un objeto 3D valido." << std::endl;
    std::cout << "El archivo " << nombre_archivo << " no existe o es ilegible." << std::endl;
    std::cout << "El objeto " << nombre_objeto << " ya ha sido cargado en memoria." << std::endl;
    Objeto objeto = Juan_implementalo;
    objetosCargados.push_back(objeto);
    std::cout << "El objeto " << nombre_objeto << " ha sido cargado exitosamente desde el archivo " << nombre_archivo << "." << std::endl;
}

// Lista los objetos cargados
void Menu::listarObjetosCargados() {
    if (objetosCargados.empty()) {
        std::cout << "Ningún objeto ha sido cargado en memoria." << std::endl;
    return;
}

    std::cout << "Hay " << objetosCargados.size() << " objetos en memoria:" << std::endl;
    for (Objeto& objeto : objetosCargados) {
        std::cout << objeto << " contiene X vértices, Y aristas y Z caras." << std::endl; // Esto toca modificarlo segundo la estructura de un objeto.
    }
}

// Crea la caja de ajuste para un objeto específico
void Menu::crearCajaDeAjuste(std::string& nombre_objeto) {
    if (!objetoCargado(nombre_objeto)) {
        std::cout << "El objeto " << nombre_objeto << " no ha sido cargado en memoria." << std::endl;
        return;
    }

    std::string nombreCaja = "env_" + nombre_objeto;
    std::cout << "La caja envolvente del objeto " << nombre_objeto << " se ha generado con el nombre " << nombreCaja << " y se ha agregado a los objetos en memoria." << std::endl;
}

// Crea la caja de ajuste global para todos los objetos
void Menu::crearCajaDeAjusteGlobal() {
    if (objetosCargados.empty()) {
        std::cout << "Ningún objeto ha sido cargado en memoria." << std::endl;
        return;
    }
    
    std::cout << "La caja envolvente global se ha generado con el nombre env_global y se ha agregado a los objetos en memoria." << std::endl;
}

// Elimina un objeto
void Menu::descargarObjeto(std::string& nombre_objeto) {
    auto iterador = std::find(objetosCargados.begin(), objetosCargados.end(), nombre_objeto);
    if (iterador == objetosCargados.end()) {
        std::cout << "El objeto " << nombre_objeto << " no ha sido cargado en memoria." << std::endl;
        return;
    }

    objetosCargados.erase(it);
    std::cout << "El objeto " << nombre_objeto << " ha sido eliminado de la memoria de trabajo." << std::endl;
}

// Guarda un objeto
void Menu::guardarObjeto(std::string& nombre_objeto, std::string& nombre_archivo) {
    if (!objetoCargado(nombre_objeto)) {
        std::cout << "El objeto " << nombre_objeto << " no ha sido cargado en memoria." << std::endl;
        return;
    }

    std::ofstream archivo(nombre_archivo);
    if (!archivo) {
        std::cout << "No se pudo abrir el archivo para guardar." << std::endl;
        return;
    }

    archivo << "Información del objeto " << nombre_archivo << std::endl; // Ejemplo básico
    std::cout << "La información del objeto " << nombre_objeto << " ha sido guardada exitosamente en el archivo " << nombre_archivo << "." << std::endl;
}

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

// Encuentra la ruta más corta entre dos vértices de un objeto
void Menu::rutaCortaVertices(int v1, int v2, std::string& nombre_objeto) {
    if (!objetoCargado(nombre_objeto)) {
        std::cout << "El objeto " << nombre_objeto << " no ha sido cargado en memoria." << std::endl;
        return;
    }

    std::cout << "Los indices de los vertices dados son iguales." << std::endl;
    std::cout << "Algunos de los indices de vertices estan fuera de rango para el objeto " << nombre_objeto << std::endl;
    std::cout << "La ruta más corta entre los vértices " << v1 << " y " << v2 << " del objeto " << nombre_objeto << " es ruta_corta." << std::endl;
}

// Encuentra la ruta más corta de un vértice al centro del objeto
void Menu::rutaCortaCentro(int v1, std::string& nombre_objeto) {
    if (!objetoCargado(nombre_objeto)) {
        std::cout << "El objeto " << nombre_objeto << " no ha sido cargado en memoria." << std::endl;
        return;
    }

    std::cout << "El indice de vertice esta fuera de rango para el objeto nombre_objeto." << nombre_objeto << std::endl;
    std::cout << "La ruta más corta entre el vértice " << v1 << " y el centro del objeto " << nombre_objeto << " es ruta_corta." << std::endl;
}

#endif // __MENU__HXX__

// eof - menu.hxx
