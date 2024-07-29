#ifndef __MENU_H__
#define __MENU_H__

#include <iostream>
#include <string>
#include <vector>

class Menu {
public:
    Menu(); // Constructor
    std::vector<std::string> objetosCargados; // Vector para almacenar los nombres de los objetos cargados
    bool objetoCargado(std::string& nombreMalla); // Verifica si un objeto está cargado
    void mostrarMenu(); // Muestra el menú
    void manejarEntradaUsuario(); // Maneja la entrada del usuario
    void mostrarAyuda(); // Muestra la información de ayuda
    void salirPrograma(); // Salir del programa
    bool validarNombreArchivo(std::string& nombreArchivo); // Valida el nombre del archivo
    bool validarNombreObjeto(std::string& nombreMalla); // Valida el nombre del objeto

private:
    void cargarObjeto(std::string& nombreArchivo); // Carga un objeto
    void listarObjetosCargados(); // Lista los objetos cargados
    void crearCajaDeAjuste(std::string& nombreMalla); // Crea la caja de ajuste para un objeto específico
    void crearCajaDeAjusteGlobal(); // Crea la caja de ajuste global para todos los objetos
    void eliminarObjeto(std::string& nombreMalla); // Elimina un objeto
    void guardarObjeto(std::string& nombreMalla, std::string& nombreArchivo); // Guarda un objeto
    void verticeCercanoObjeto(double px, double py, double pz, std::string& nombreMalla); // Encuentra el vértice más cercano en un objeto específico
    void verticeCercanoTodosObjetos(double px, double py, double pz); // Encuentra el vértice más cercano en todos los objetos
    void verticesCercanosCaja(std::string& nombreMalla); // Encuentra los vértices más cercanos a las esquinas de la caja de ajuste
    void rutaCortaVertices(int v1, int v2, std::string& nombreMalla); // Encuentra la ruta más corta entre dos vértices de un objeto
    void rutaCortaCentro(int v1, std::string& nombreMalla); // Encuentra la ruta más corta de un vértice al centro del objeto
};

#include "menu.hxx"

#endif // __MENU_H__

// eof - menu.h