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
    std::cout <<"--------------------------------------------------------------------------------------------\n";
    std::cout << "Bienvenido al sistema de gestión de objetos." << std::endl;
    std::cout << "Para obtener información general sobre los comandos posibles, escriba 'ayuda'." << std::endl;
}

// Verifica si un objeto está cargado
bool Menu::objetoCargado(const std::string& nombre_objeto) {
    return std::any_of(objetosCargados.begin(), objetosCargados.end(),
        [&nombre_objeto](const Objeto& obj) { return obj.getNombreObjeto() == nombre_objeto; });
}

// Muestra el menú
void Menu::mostrarMenu() {
    std::cout << "==========================================================================================================\n" << std::endl;
    std::cout << "Comandos disponibles:\n"<< std::endl<< std::endl;
    std::cout << "- cargar <nombre_archivo>: Carga una malla desde un archivo." << std::endl;
    std::cout << "- listado: Muestra los objetos cargados en memoria." << std::endl;
    std::cout << "- envolvente <nombre_objeto>: Calcula la caja envolvente de un objeto específico." << std::endl;
    std::cout << "- envolvente: Calcula la caja envolvente global de todos los objetos." << std::endl;
    std::cout << "- descargar <nombre_objeto>: Elimina un objeto de la memoria." << std::endl;
    std::cout << "- guardar <nombre_objeto> <nombre_archivo>: Guarda la malla de un objeto en un archivo." << std::endl;
    std::cout << "- v_cercano <px> <py> <pz> <nombre_objeto>: Buscar vértice más cercano (objeto específico)." << std::endl;
    std::cout << "- v_cercano <px> <py> <pz>: Buscar vértice más cercano (todos los objetos)." << std::endl;
    std::cout << "- v_cercanos_caja <nombre_objeto>: Buscar vértices más cercanos a su caja." << std::endl;
    std::cout << "- ruta_corta <i1> <i2> <nombre_objeto>: Ruta más corta entre vértices." << std::endl;
    std::cout << "- ruta_corta_centro <i1> <nombre_objeto>: Ruta más corta al centro de un objeto." << std::endl;
    std::cout << "- salir: Termina la ejecución del programa." << std::endl;
    std::cout << "- ayuda: Muestra esta ayuda." << std::endl << std::endl;
    std::cout << "Para obtener más información sobre un comando específico, escriba 'ayuda' seguido del nombre del comando." << std::endl;
    std::cout << "Ejemplo: ayuda cargar\n" << std::endl;
    std::cout << "==========================================================================================================\n" << std::endl;
}

// Maneja la entrada del usuario
void Menu::manejarEntradaUsuario() {
    std::string entrada;
    std::cout << "$ ";
    std::getline(std::cin, entrada);

    std::istringstream ss(entrada);
    std::string comando;
    std::string argumento;
    ss >> comando;
    
    if (comando == "ayuda") {
        ss >> argumento;  // Intenta obtener un segundo argumento
        if (!argumento.empty()) {
            // Maneja la ayuda específica para cada comando
            if(argumento == "cargar"){
                std::cout <<"--------------------------------------------------------------------------------------------\n"
                          << "Comando: cargar <nombre_archivo>\n"
                          << "Descripción: Carga en memoria la malla desde el archivo especificado, agregando el objeto a los gestionados por el sistema.\n"
                          << "Ejemplo: cargar modelo.obj\n"
                          <<"--------------------------------------------------------------------------------------------\n";
            } else if(argumento == "listado"){
                std::cout <<"--------------------------------------------------------------------------------------------\n"
                          << "Comando: listado\n"
                          << "Descripción: Muestra una lista de todos los objetos cargados en memoria, incluyendo detalles como cantidad de vértices, aristas y caras.\n"
                          << "Ejemplo: listado\n"
                          <<"--------------------------------------------------------------------------------------------\n";
            } else if(argumento == "envolvente"){
                std::cout <<"--------------------------------------------------------------------------------------------\n"
                          << "Comando: envolvente [nombre_objeto]\n"
                          << "Descripción: Calcula la caja envolvente para el objeto especificado o para todos los objetos si no se especifica uno.\n"
                          << "Ejemplo: envolvente nombreFigura\n"
                          <<"--------------------------------------------------------------------------------------------\n";
            } else if(argumento == "descargar"){
                std::cout <<"--------------------------------------------------------------------------------------------\n"
                          << "Comando: descargar <nombre_objeto>\n"
                          << "Descripción: Elimina un objeto específico de la memoria del sistema.\n"
                          << "Ejemplo: descargar nombreFigura\n"
                          <<"--------------------------------------------------------------------------------------------\n";
            } else if(argumento == "guardar"){
                std::cout <<"--------------------------------------------------------------------------------------------\n"
                          << "Comando: guardar <nombre_objeto> <nombre_archivo>\n"
                          << "Descripción: Guarda la malla del objeto especificado en un nuevo archivo, permitiendo la persistencia de datos.\n"
                          << "Ejemplo: guardar nombreFigura copia_modelo.obj\n"
                          <<"--------------------------------------------------------------------------------------------\n";
            } else if(argumento == "v_cercano"){
                std::cout <<"--------------------------------------------------------------------------------------------\n"
                          << "Comando: v_cercano <px> <py> <pz> [nombre_objeto]\n"
                          << "Descripción: Identifica el vértice más cercano al punto especificado por las coordenadas <px>, <py>, <pz>. Si se proporciona un [nombre_objeto], busca solo dentro de ese objeto. Si no se especifica un objeto, busca en todos los objetos cargados.\n"
                          << "Ejemplo 1 (objeto específico): v_cercano 1 2 3 nombreObjeto\n"
                          << "Ejemplo 2 (todos los objetos): v_cercano 1 2 3\n"
                          <<"--------------------------------------------------------------------------------------------\n";
            } else if(argumento == "v_cercanos_caja"){
                std::cout << "--------------------------------------------------------------------------------------------\n"
                          << "Comando: v_cercanos_caja <nombre_objeto>\n"
                          << "Descripción: Identifica los vértices del objeto nombre_objeto más cercanos a las esquinas de su caja envolvente.\n"
                          << "Ejemplo: v_cercanos_caja nombreFigura\n"
                          << "--------------------------------------------------------------------------------------------\n";
            } else if(argumento == "ruta_corta"){
                std::cout <<"--------------------------------------------------------------------------------------------\n"
                          << "Comando: ruta_corta <i1> <i2> <nombre_objeto>\n"
                          << "Descripción: Calcula la ruta más corta entre dos vértices de un objeto especificado, basada en la distancia euclidiana.\n"
                          << "Ejemplo: ruta_corta 0 5 nombreObjeto\n"
                          <<"--------------------------------------------------------------------------------------------\n";
            } else if(argumento == "ruta_corta_centro"){
                std::cout <<"--------------------------------------------------------------------------------------------\n"
                          << "Comando: ruta_corta_centro <i1> <nombre_objeto>\n"
                          << "Descripción: Determina la ruta más corta desde un vértice hasta el centroide del objeto especificado.\n"
                          << "Ejemplo: ruta_corta_centro 2 nombreObjeto\n"
                          <<"--------------------------------------------------------------------------------------------\n";
            } else {
                std::cout << "Ayuda para el comando especificado no disponible. Intente 'ayuda' para ver todos los comandos.\n";
            }
        } else {
            // No hay segundo argumento, muestra el menú general de ayuda
            mostrarMenu();
        }        
    }  else if (comando == "cargar") { 
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
        guardarObjetoEnArchivo(nombre_objeto, nombre_archivo);
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
    } else {
        std::cout << "Opción no válida." << std::endl;
    }
}

// Salir del programa
void Menu::salirPrograma() {
    std::cout << "Saliendo del programa..." << std::endl;
    exit(0);
}

// Carga un objeto
void Menu::cargarObjeto(const std::string& nombre_archivo) {
    // Verificar si el archivo puede ser abierto
    std::ifstream file(nombre_archivo);
    if (!file.is_open()) {
        std::cout << "(Archivo no existe) El archivo " << nombre_archivo << " no existe o es ilegible." << std::endl;
        return;
    }

    std::string nombre_objeto;
    int n_vertices;
    std::vector<int> x, y, z;
    std::vector<int> cj;
    std::vector<int> ij;
    std::string line;

    // Leer el nombre de la malla
    if (std::getline(file, line)) {
        nombre_objeto = line;
    } else {
        std::cout << "(Archivo vacío o incompleto) El archivo " << nombre_archivo << " no contiene un objeto 3D válido." << std::endl;
        return;
    }

    // Verificar si el objeto ya está cargado
    if (objetoCargado(nombre_objeto)) {
        std::cout << "(Objeto ya existe) El objeto " << nombre_objeto << " ya ha sido cargado en memoria." << std::endl;
        return;
    }

    // Leer la cantidad de vértices
    if (std::getline(file, line)) {
        n_vertices = std::stoi(line);
    } else {
        std::cout << "(Archivo vacío o incompleto) El archivo " << nombre_archivo << " no contiene un objeto 3D válido." << std::endl;
        return;
    }

    // Leer las coordenadas de los vértices
    for (int i = 0; i < n_vertices; ++i) {
        if (std::getline(file, line)) {
            std::stringstream ss(line);
            int xi, yi, zi;
            ss >> xi >> yi >> zi;
            x.push_back(xi);
            y.push_back(yi);
            z.push_back(zi);
        } else {
            std::cout << "(Archivo vacío o incompleto) El archivo " << nombre_archivo << " no contiene un objeto 3D válido." << std::endl;
            return;
        }
    }

    // Leer las caras
    while (std::getline(file, line) && line == "-1") {
        std::stringstream ss(line);
        int c;
        ss >> c;
        cj.push_back(c);
        for (int i = 0; i < c; ++i) {
            int idx;
            ss >> idx;
            ij.push_back(idx);
        }
    }

    // Crear el objeto y añadirlo a la lista de objetos cargados
    Objeto objeto(nombre_objeto, n_vertices, x, y, z, cj, ij);
    objetosCargados.push_back(objeto);
    std::cout << "(Resultado exitoso) El objeto " << nombre_objeto << " ha sido cargado exitosamente desde el archivo " << nombre_archivo << "." << std::endl;
}

// Lista los objetos cargados
void Menu::listarObjetosCargados() {
   if (objetosCargados.empty()) {
        std::cout << "(Memoria vacía) Ningún objeto ha sido cargado en memoria." << std::endl;
        return;
    }

    std::cout << "(Resultado exitoso) Hay " << objetosCargados.size() << " objetos en memoria:" << std::endl;
    for (const Objeto& objeto : objetosCargados) {
        std::cout << objeto.toString() << std::endl;
    }
}

// Crea la caja de ajuste para un objeto específico
void Menu::crearCajaDeAjuste(std::string& nombre_objeto) {
    if (!objetoCargado(nombre_objeto)) {
        std::cout << "(Objeto no existe) El objeto " << nombre_objeto << " no ha sido cargado en memoria." << std::endl;
        return;
    }

    std::string nombreCaja = "env_" + nombre_objeto;
    std::cout << "(Resultado exitoso) La caja envolvente del objeto " << nombre_objeto << " se ha generado con el nombre " << nombreCaja << " y se ha agregado a los objetos en memoria." << std::endl;
}

// Crea la caja de ajuste global para todos los objetos
void Menu::crearCajaDeAjusteGlobal() {
    if (objetosCargados.empty()) {
        std::cout << "(Memoria vacía) Ningún objeto ha sido cargado en memoria." << std::endl;
        return;
    }
    
    std::cout << "(Resultado exitoso) La caja envolvente global se ha generado con el nombre env_global y se ha agregado a los objetos en memoria." << std::endl;
}

// Elimina un objeto
void Menu::descargarObjeto(std::string& nombre_objeto) {
    auto it = std::find_if(objetosCargados.begin(), objetosCargados.end(),
        [&nombre_objeto](const Objeto& obj) { return obj.getNombreObjeto() == nombre_objeto; });

    if (it == objetosCargados.end()) {
        std::cout << "(Objeto no existe) El objeto " << nombre_objeto << " no ha sido cargado en memoria." << std::endl;
        return;
    }

    objetosCargados.erase(it);
    std::cout << "(Resultado exitoso) El objeto " << nombre_objeto << " ha sido eliminado de la memoria de trabajo." << std::endl;
}


// Guarda un objeto
void Menu::guardarObjetoEnArchivo( std::string& nombre_objeto,std::string& nombre_archivo) {
    // Buscar el objeto por nombre
    std::vector<Objeto>::iterator it = std::find_if(objetosCargados.begin(), objetosCargados.end(),
        [&nombre_objeto](const Objeto& obj) { return obj.getNombreObjeto() == nombre_objeto; });

    if (it == objetosCargados.end()) {
        // Objeto no encontrado
        std::cout << "(Objeto no existe) El objeto " << nombre_objeto << " no ha sido cargado en memoria." << std::endl;
        return;
    }

    // Objeto encontrado, escribir en el archivo
    const Objeto& objeto = *it;
    std::ofstream archivo(nombre_archivo);

    if (!archivo) {
        std::cerr << "Error al abrir el archivo para escritura." << std::endl;
        return;
    }

    archivo << objeto.getNombreObjeto() << std::endl;
    archivo << objeto.getX().size() << std::endl;

    // Escribir los vértices
    for (size_t i = 0; i < objeto.getX().size(); ++i) {
        archivo << objeto.getX()[i] << ' ' << objeto.getY()[i] << ' ' << objeto.getZ()[i] << std::endl;
    }

    // Escribir las caras
    for (size_t i = 0; i < objeto.getCj().size(); ++i) {
        archivo << objeto.getCj()[i];
        for (size_t j = 0; j < objeto.getCj()[i]; ++j) {
            archivo << ' ' << objeto.getIj()[i * objeto.getCj()[i] + j];
        }
        archivo << std::endl;
    }

    archivo << "-1" << std::endl;
    archivo.close();

    // Mensaje de éxito
    std::cout << "(Resultado exitoso) La información del objeto " << nombre_objeto
              << " ha sido guardada exitosamente en el archivo " << nombre_archivo << "." << std::endl; 
}

// Encuentra el vértice más cercano en un objeto específico
void Menu::verticeCercanoObjeto(double px, double py, double pz, std::string& nombre_objeto) {
    if (!objetoCargado(nombre_objeto)) {
        std::cout << "(Objeto no existe) El objeto " << nombre_objeto << " no ha sido cargado en memoria." << std::endl;
        return;
    }

    std::cout << "(Resultado exitoso) El vértice más cercano al punto (" << px << ", " << py << ", " << pz << ") es el vértice i con coordenadas (vx, vy, vz) a una distancia de valor_distancia." << std::endl;
}

// Encuentra el vértice más cercano en todos los objetos
void Menu::verticeCercanoTodosObjetos(double px, double py, double pz) {
    if (objetosCargados.empty()) {
        std::cout << "(Memoria vacía) Ningún objeto ha sido cargado en memoria." << std::endl;
        return;
    }

    std::cout << "(Resultado exitoso) El vértice más cercano al punto (" << px << ", " << py << ", " << pz << ") es el vértice i del objeto nombre_objeto con coordenadas (vx, vy, vz) a una distancia de valor_distancia." << std::endl;
}

// Encuentra los vértices más cercanos a las esquinas de la caja de ajuste
void Menu::verticesCercanosCaja(std::string& nombre_objeto) {
    if (!objetoCargado(nombre_objeto)) {
        std::cout << "(Objeto no existe) El objeto " << nombre_objeto << " no ha sido cargado en memoria." << std::endl;
        return;
    }

    std::cout << "(Resultado exitoso) Los vértices del objeto " << nombre_objeto << " más cercanos a las esquinas de la caja de ajuste son: vértices_x, vértices_y, vértices_z." << std::endl;
}

// Encuentra la ruta más corta entre dos vértices de un objeto
void Menu::rutaCortaVertices(int v1, int v2, std::string& nombre_objeto) {
    if (!objetoCargado(nombre_objeto)) {
        std::cout << "(Objeto no existe) El objeto " << nombre_objeto << " no ha sido cargado en memoria." << std::endl;
        return;
    }

    std::cout << "(Índices iguales) Los indices de los vertices dados son iguales." << std::endl;
    std::cout << "(Índices no existen) Algunos de los indices de vertices estan fuera de rango para el objeto " << nombre_objeto << std::endl;
    std::cout << "(Resultado exitoso) La ruta más corta entre los vértices " << v1 << " y " << v2 << " del objeto " << nombre_objeto << " es ruta_corta." << std::endl;
}

// Encuentra la ruta más corta de un vértice al centro del objeto
void Menu::rutaCortaCentro(int v1, std::string& nombre_objeto) {
    if (!objetoCargado(nombre_objeto)) {
        std::cout << "(Objeto no existe) El objeto " << nombre_objeto << " no ha sido cargado en memoria." << std::endl;
        return;
    }

    std::cout << "(Índices no existen) El indice de vertice esta fuera de rango para el objeto nombre_objeto." << nombre_objeto << std::endl;
    std::cout << "(Resultado exitoso) La ruta más corta entre el vértice " << v1 << " y el centro del objeto " << nombre_objeto << " es ruta_corta." << std::endl;
}

#endif // __MENU__HXX__

// eof - menu.hxx
