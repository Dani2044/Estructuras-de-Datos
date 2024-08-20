#ifndef __MENU_H__
#define __MENU_H__

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <climits>
#include "objeto.h"

class Menu {
private:
    std::vector<Objeto> objetosCargados; 
public:
    Menu();
    bool objetoCargado(const std::string& nombre_archivo);
    void mostrarMenu();
    void manejarEntradaUsuario();
    void mostrarAyuda();
    void salirPrograma();
    void cargarObjeto(const std::string& nombre_archivo);
    void listarObjetosCargados();
    void calcularCajaEnvolvente(const std::string& nombre_objeto);
    void crearCajaDeAjusteGlobal();
    void descargarObjeto(std::string& nombre_objeto);
    void guardarObjetoEnArchivo(const std::string& nombre_objeto, const std::string& nombre_archivo);
    void verticeCercanoObjeto(double px, double py, double pz, std::string& nombre_objeto);
    void verticeCercanoTodosObjetos(double px, double py, double pz);
    void verticesCercanosCaja(std::string& nombre_objeto);
    void rutaCortaVertices(int v1, int v2, std::string& nombre_objeto);
    void rutaCortaCentro(int v1, std::string& nombre_objeto);
};

#endif // __MENU_H__

// eof - menu.h