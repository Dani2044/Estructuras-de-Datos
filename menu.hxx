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
   // return std::find(objetosCargados.begin(), objetosCargados.end(), nombre_objeto) != objetosCargados.end(); // Find devuelve un iterador al primer elemento que coincide con el valor buscado o al final del contenedor si no se encuentra
    return false;
}

// Muestra el menú
void Menu::mostrarMenu() {
    std::cout << "A continuación se presentan las opciones con sus respectivos comandos.\nDigite 'ayuda' y el comando que desea consultar para más información." << std::endl;
    std::cout << "1. Cargar objeto: cargar nombre_archivo. " << std::endl;
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
    std::string argumento;
    ss >> comando;

    if(ss>>argumento){        
        if(comando == "ayuda" && argumento == "cargar"){
            std::cout << "Comando: cargar nombre_archivo,  Carga en memoria la información del objeto nombre_objeto contenida en el archivo identificado por nombre_archivo." << std::endl;
        }
        else if(comando == "ayuda" && argumento == "listado"){
            std::cout << "Comando: listado,  Lista los objetos cargados actualmente en memoria, junto con la información básica de cada uno: cantidad de puntos, de aristas y de caras." << std::endl;
        }
        else if(comando == "ayuda" && argumento == "envolvente"){
            std::cout << "Comando: envolvente nombre_objeto, Calcula la caja envolvente del objeto identificado por nombre_objeto." << std::endl;
        }
        else if(comando == "ayuda" && argumento == "descargar"){
            std::cout << "Comando: descargar nombre_objeto, Elimina del sistema la información del objeto." << std::endl;
        }
        else if(comando == "ayuda" && argumento == "guardar"){
            std::cout << "Comando: guardar nombre_objeto nombre_archivo, Escribe en un archivo de texto, identificado por nombre_archivo, la información básica (vértices y caras) del objeto identificado por nombre_objeto." << std::endl;
        }
        else if(comando == "ayuda" && argumento == "v_cercano"){
            std::cout << "Comando: v_cercano px py pz nombre_objeto, Identifica el vértice del objeto nombre_objeto más cercano (en términos de la distancia euclidiana) al punto indicado por las coordenadas px, py y pz." << std::endl;
        }        
    } else if(comando == "ayuda"){
        mostrarAyuda();
    } else if (comando == "cargar") { 
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
    } else if (comando == "ayuda") {
        mostrarAyuda();
    }else {
        std::cout << "Opción no válida." << std::endl;
    }
}

// Muestra la información de ayuda
void Menu::mostrarAyuda() {
}

// Salir del programa
void Menu::salirPrograma() {
    std::cout << "Saliendo del programa..." << std::endl;
    exit(0);
}

// Carga un objeto
void Menu::cargarObjeto(const std::string& nombre_archivo) {
    // Verificar si el archivo puede ser abierto
   std::ifstream file;
    file.open(nombre_archivo);
    std::cout << nombre_archivo << std::endl;
    if (!file.is_open()) {
        std::cout << "El archivo " << nombre_archivo << " no existe o es ilegible." << std::endl;
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
        std::cout << "Nombre de la malla: " << nombre_objeto << std::endl;
    } else {
        std::cout << "El archivo " << nombre_archivo << " no contiene un objeto 3D válido." << std::endl;
        return;
    }

    // Leer la cantidad de vértices
    if (std::getline(file, line)) {
        n_vertices = std::stoi(line);
    } else {
        std::cout << "El archivo " << nombre_archivo << " no contiene un objeto 3D válido." << std::endl;
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
            std::cout << "El archivo " << nombre_archivo << " no contiene un objeto 3D válido." << std::endl;
            return;
        }
    }

    // Leer las caras
    while (std::getline(file, line)) {
        if (line == "-1") {
            break;
        }
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
    std::cout << "El objeto " << nombre_objeto << " ha sido cargado exitosamente desde el archivo " << nombre_archivo << "." << std::endl;
}

// Lista los objetos cargados
void Menu::listarObjetosCargados() {
   if (objetosCargados.empty()) {
        std::cout << "Ningún objeto ha sido cargado en memoria." << std::endl;
        return;
    }

    std::cout << "Hay " << objetosCargados.size() << " objetos en memoria:" << std::endl;
    for (const Objeto& objeto : objetosCargados) {
        std::cout << objeto.toString() << std::endl;
    }
}

// Crea la caja de ajuste para un objeto específico
void Menu::crearCajaDeAjuste(std::string& nombre_objeto) {
    /*if (!objetoCargado(nombre_objeto)) {
        std::cout << "El objeto " << nombre_objeto << " no ha sido cargado en memoria." << std::endl;
        return;
    }

    std::string nombreCaja = "env_" + nombre_objeto;
    std::cout << "La caja envolvente del objeto " << nombre_objeto << " se ha generado con el nombre " << nombreCaja << " y se ha agregado a los objetos en memoria." << std::endl;*/
}

// Crea la caja de ajuste global para todos los objetos
void Menu::crearCajaDeAjusteGlobal() {
  /*  if (objetosCargados.empty()) {
        std::cout << "Ningún objeto ha sido cargado en memoria." << std::endl;
        return;
    }
    
    std::cout << "La caja envolvente global se ha generado con el nombre env_global y se ha agregado a los objetos en memoria." << std::endl;*/
}

// Elimina un objeto
void Menu::descargarObjeto(std::string& nombre_objeto) {
    // Buscar el objeto por nombre
  /*  auto it = std::find_if(objetosCargados.begin(), objetosCargados.end(),
        [&nombre_objeto](const Objeto& obj) { return obj.getNombreObjeto() == nombre_objeto; });

    if (it == objetosCargados.end()) {
        // Objeto no encontrado
        std::cout << "(Objeto no existe) El objeto " << nombre_objeto << " no ha sido cargado en memoria." << std::endl;
        return;
    }

    // Eliminar el objeto de memoria
    objetosCargados.erase(it);

    // Mensaje de éxito
    std::cout << "(Resultado exitoso) El objeto " << nombre_objeto << " ha sido eliminado de la memoria de trabajo." << std::endl;*/
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
   /* if (!objetoCargado(nombre_objeto)) {
        std::cout << "El objeto " << nombre_objeto << " no ha sido cargado en memoria." << std::endl;
        return;
    }

    std::cout << "El vértice más cercano al punto (" << px << ", " << py << ", " << pz << ") es el vértice i con coordenadas (vx, vy, vz) a una distancia de valor_distancia." << std::endl;*/
}

// Encuentra el vértice más cercano en todos los objetos
void Menu::verticeCercanoTodosObjetos(double px, double py, double pz) {
    /*if (objetosCargados.empty()) {
        std::cout << "Ningún objeto ha sido cargado en memoria." << std::endl;
        return;
    }

    std::cout << "El vértice más cercano al punto (" << px << ", " << py << ", " << pz << ") es el vértice i del objeto nombre_objeto con coordenadas (vx, vy, vz) a una distancia de valor_distancia." << std::endl;*/
}

// Encuentra los vértices más cercanos a las esquinas de la caja de ajuste
void Menu::verticesCercanosCaja(std::string& nombre_objeto) {
   /* if (!objetoCargado(nombre_objeto)) {
        std::cout << "El objeto " << nombre_objeto << " no ha sido cargado en memoria." << std::endl;
        return;
    }

    std::cout << "Los vértices del objeto " << nombre_objeto << " más cercanos a las esquinas de la caja de ajuste son: vértices_x, vértices_y, vértices_z." << std::endl;*/
}

// Encuentra la ruta más corta entre dos vértices de un objeto
void Menu::rutaCortaVertices(int v1, int v2, std::string& nombre_objeto) {
    /*if (!objetoCargado(nombre_objeto)) {
        std::cout << "El objeto " << nombre_objeto << " no ha sido cargado en memoria." << std::endl;
        return;
    }

    std::cout << "Los indices de los vertices dados son iguales." << std::endl;
    std::cout << "Algunos de los indices de vertices estan fuera de rango para el objeto " << nombre_objeto << std::endl;
    std::cout << "La ruta más corta entre los vértices " << v1 << " y " << v2 << " del objeto " << nombre_objeto << " es ruta_corta." << std::endl;*/
}

// Encuentra la ruta más corta de un vértice al centro del objeto
void Menu::rutaCortaCentro(int v1, std::string& nombre_objeto) {
    /*if (!objetoCargado(nombre_objeto)) {
        std::cout << "El objeto " << nombre_objeto << " no ha sido cargado en memoria." << std::endl;
        return;
    }

    std::cout << "El indice de vertice esta fuera de rango para el objeto nombre_objeto." << nombre_objeto << std::endl;
    std::cout << "La ruta más corta entre el vértice " << v1 << " y el centro del objeto " << nombre_objeto << " es ruta_corta." << std::endl;*/
}

#endif // __MENU__HXX__

// eof - menu.hxx