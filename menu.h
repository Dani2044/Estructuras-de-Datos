#ifndef __MENU_H__
#define __MENU_H__

#include "objeto.hxx"
#include <iostream>
#include <string>
#include <vector>

class Menu {
private:
    std::vector<Objeto> objetosCargados; // Vector para almacenar los nombres de los objetos cargados, en lugar de string debe ser de tipo Objeto cuando hagamos la estructura correspondiente.
    // Se elige un vector para facilitar el acceso aleatorio y porque solo se agregarán objetos al final del vector
    std::vector<Envoltorio> envoltoriosCargados;
public:
    Menu(); // Constructor
    bool objetoCargado(std::string& nombre_objeto); // Verifica si un objeto está cargado
    void mostrarMenu(); // Muestra el menú
    void manejarEntradaUsuario(); // Maneja la entrada del usuario
    void mostrarAyuda(); // Muestra la información de ayuda
    void salirPrograma(); // Salir del programa
    void cargarObjeto(const std::string& nombre_archivo); // Carga un objeto
    void listarObjetosCargados(); // Lista los objetos cargados
    void crearCajaDeAjuste(std::string& nombre_objeto); // Crea la caja de ajuste para un objeto específico
    void crearCajaDeAjusteGlobal(); // Crea la caja de ajuste global para todos los objetos
    void descargarObjeto(std::string& nombre_objeto); // Elimina un objeto
    void guardarObjetoEnArchivo(std::string& nombre_objeto, std::string& nombre_archivo); // Guarda un objeto
    void verticeCercanoObjeto(double px, double py, double pz, std::string& nombre_objeto); // Encuentra el vértice más cercano en un objeto específico
    void verticeCercanoTodosObjetos(double px, double py, double pz); // Encuentra el vértice más cercano en todos los objetos
    void verticesCercanosCaja(std::string& nombre_objeto); // Encuentra los vértices más cercanos a las esquinas de la caja de ajuste
    void rutaCortaVertices(int v1, int v2, std::string& nombre_objeto); // Encuentra la ruta más corta entre dos vértices de un objeto
    void rutaCortaCentro(int v1, std::string& nombre_objeto); // Encuentra la ruta más corta de un vértice al centro del objeto
};

#include "menu.hxx"

#endif // __MENU_H__

// eof - menu.h