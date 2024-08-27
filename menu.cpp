// Implementación del menú

#include "menu.h"
#include <chrono>
#include <limits>
#include <vector>

// Constructor
Menu::Menu() {
    objetosCargados.clear();
    std::cout << "Bienvenido al sistema de gestión de objetos. Digite 'ayuda' en caso de requerirlo." << std::endl;
}

// Muestra el menú
void Menu::mostrarMenu() {
    std::cout << "==========================================================================================================\n" << std::endl;
    std::cout << "Comandos disponibles:\n" << std::endl << std::endl;
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
    std::cout << "- ayuda: Muestra esta ayuda." << std::endl;
    std::cout << "\nPara obtener más información sobre un comando específico, escriba 'ayuda' seguido del nombre del comando." << std::endl;
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

    // Comienza a medir el tiempo
    std::chrono::high_resolution_clock::time_point inicio = std::chrono::high_resolution_clock::now();

    if (comando == "ayuda") {
        ss >> argumento;
        if (!argumento.empty()) {
            // Maneja la ayuda específica para cada comando
            if (argumento == "cargar") {
                std::cout << "--------------------------------------------------------------------------------------------\n"
                          << "Comando: cargar <nombre_archivo>\n"
                          << "Descripción: Carga en memoria la malla desde el archivo especificado, agregando el objeto a los gestionados por el sistema.\n"
                          << "Ejemplo: cargar modelo.obj\n"
                          << "--------------------------------------------------------------------------------------------\n";
            } else if (argumento == "listado") {
                std::cout << "--------------------------------------------------------------------------------------------\n"
                          << "Comando: listado\n"
                          << "Descripción: Muestra una lista de todos los objetos cargados en memoria, incluyendo detalles como cantidad de vértices, aristas y caras.\n"
                          << "Ejemplo: listado\n"
                          << "--------------------------------------------------------------------------------------------\n";
            } else if (argumento == "envolvente") {
                std::cout << "--------------------------------------------------------------------------------------------\n"
                          << "Comando: envolvente [nombre_objeto]\n"
                          << "Descripción: Calcula la caja envolvente para el objeto especificado o para todos los objetos si no se especifica uno.\n"
                          << "Ejemplo: envolvente nombreFigura\n"
                          << "--------------------------------------------------------------------------------------------\n";
            } else if (argumento == "descargar") {
                std::cout << "--------------------------------------------------------------------------------------------\n"
                          << "Comando: descargar <nombre_objeto>\n"
                          << "Descripción: Elimina un objeto específico de la memoria del sistema.\n"
                          << "Ejemplo: descargar nombreFigura\n"
                          << "--------------------------------------------------------------------------------------------\n";
            } else if (argumento == "guardar") {
                std::cout << "--------------------------------------------------------------------------------------------\n"
                          << "Comando: guardar <nombre_objeto> <nombre_archivo>\n"
                          << "Descripción: Guarda la malla del objeto especificado en un nuevo archivo, permitiendo la persistencia de datos.\n"
                          << "Ejemplo: guardar nombreFigura copia_modelo.obj\n"
                          << "--------------------------------------------------------------------------------------------\n";
            } else if (argumento == "v_cercano") {
                std::cout << "--------------------------------------------------------------------------------------------\n"
                          << "Comando: v_cercano <px> <py> <pz> [nombre_objeto]\n"
                          << "Descripción: Identifica el vértice más cercano al punto especificado por las coordenadas <px>, <py>, <pz>. Si se proporciona un [nombre_objeto], busca solo dentro de ese objeto. Si no se especifica un objeto, busca en todos los objetos cargados.\n"
                          << "Ejemplo 1 (objeto específico): v_cercano 1 2 3 nombreObjeto\n"
                          << "Ejemplo 2 (todos los objetos): v_cercano 1 2 3\n"
                          << "--------------------------------------------------------------------------------------------\n";
            } else if (argumento == "v_cercanos_caja") {
                std::cout << "--------------------------------------------------------------------------------------------\n"
                          << "Comando: v_cercanos_caja <nombre_objeto>\n"
                          << "Descripción: Identifica los vértices del objeto nombre_objeto más cercanos a las esquinas de su caja envolvente.\n"
                          << "Ejemplo: v_cercanos_caja nombreFigura\n"
                          << "--------------------------------------------------------------------------------------------\n";
            } else if (argumento == "ruta_corta") {
                std::cout << "--------------------------------------------------------------------------------------------\n"
                          << "Comando: ruta_corta <i1> <i2> <nombre_objeto>\n"
                          << "Descripción: Calcula la ruta más corta entre dos vértices de un objeto especificado, basada en la distancia euclidiana.\n"
                          << "Ejemplo: ruta_corta 0 5 nombreObjeto\n"
                          << "--------------------------------------------------------------------------------------------\n";
            } else if (argumento == "ruta_corta_centro") {
                std::cout << "--------------------------------------------------------------------------------------------\n"
                          << "Comando: ruta_corta_centro <i1> <nombre_objeto>\n"
                          << "Descripción: Determina la ruta más corta desde un vértice hasta el centroide del objeto especificado.\n"
                          << "Ejemplo: ruta_corta_centro 2 nombreObjeto\n"
                          << "--------------------------------------------------------------------------------------------\n";
            } else if (argumento == "salir") {
                std::cout << "--------------------------------------------------------------------------------------------\n"
                          << "Comando: salir\n"
                          << "Descripción: Finaliza la ejecución del programa.\n"
                          << "Ejemplo: salir\n"
                          << "--------------------------------------------------------------------------------------------\n";
            } else {
                std::cout << "Ayuda para el comando especificado no disponible. Intente 'ayuda' para ver todos los comandos.\n";
            }
        } else {
            // No hay segundo argumento, muestra el menú general de ayuda
            mostrarMenu();
        }
    } else if (comando == "cargar") {
        std::string nombre_archivo;
        ss >> nombre_archivo;
        cargarObjeto(nombre_archivo);
    } else if (comando == "listado") {
        listarObjetosCargados();
    } else if (comando == "envolvente") {
        std::string nombre_objeto;
        if (ss >> nombre_objeto) {
            calcularCajaEnvolvente(nombre_objeto);
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
        std::cout << "Comando no reconocido. Escriba 'ayuda' para ver la lista de comandos disponibles." << std::endl;
    }

    std::chrono::high_resolution_clock::time_point fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = fin - inicio;
    std::cout << "El comando '" << comando << "' se ejecutó en " << duracion.count() << " segundos." << std::endl;
}

// Muestra la información de ayuda
void Menu::mostrarAyuda() {
    std::cout << "1. Comando: cargar nombre_archivo\n";
    std::cout << "   Descripción: Carga en memoria la información del objeto nombre_objeto contenida en el archivo identificado por nombre_archivo.\n";
    std::cout << "   Posibles salidas en pantalla:\n";
    std::cout << "   - (Archivo vacío o incompleto) El archivo nombre_archivo no contiene un objeto 3D valido.\n";
    std::cout << "   - (Archivo no existe) El archivo nombre_archivo no existe o es ilegible.\n";
    std::cout << "   - (Objeto ya existe) El objeto nombre_objeto ya ha sido cargado en memoria.\n";
    std::cout << "   - (Resultado exitoso) El objeto nombre_objeto ha sido cargado exitosamente desde el archivo nombre_archivo.\n\n";

    std::cout << "2. Comando: listado\n";
    std::cout << "   Descripción: Lista los objetos cargados actualmente en memoria, junto con la información básica de cada uno: cantidad de puntos, de aristas y de caras.\n";
    std::cout << "   Posibles salidas en pantalla:\n";
    std::cout << "   - (Memoria vacía) Ningún objeto ha sido cargado en memoria.\n";
    std::cout << "   - (Resultado exitoso) Hay n objetos en memoria:\n";
    std::cout << "     nombre_objeto_1 contiene n_1 vértices, a_1 aristas y c_1 caras.\n";
    std::cout << "     nombre_objeto_2 contiene n_2 vértices, a_2 aristas y c_2 caras.\n\n";

    std::cout << "3. Comando: envolvente nombre_objeto\n";
    std::cout << "   Descripción: Calcula la caja envolvente del objeto identificado por nombre_objeto.\n";
    std::cout << "   Posibles salidas en pantalla:\n";
    std::cout << "   - (Objeto no existe) El objeto nombre_objeto no ha sido cargado en memoria.\n";
    std::cout << "   - (Resultado exitoso) La caja envolvente del objeto nombre_objeto se ha generado con el nombre env_nombre_objeto y se ha agregado a los objetos en memoria.\n\n";

    std::cout << "4. Comando: envolvente\n";
    std::cout << "   Descripción: Calcula la caja envolvente que incluye a todos los objetos cargados actualmente en memoria.\n";
    std::cout << "   Posibles salidas en pantalla:\n";
    std::cout << "   - (Memoria vacía) Ningún objeto ha sido cargado en memoria.\n";
    std::cout << "   - (Resultado exitoso) La caja envolvente de los objetos en memoria se ha generado con el nombre env_global y se ha agregado a los objetos en memoria.\n\n";

    std::cout << "5. Comando: descargar nombre_objeto\n";
    std::cout << "   Descripción: Descarga de la memoria toda la información básica (vértices, aristas, caras) del objeto identificado por nombre_objeto.\n";
    std::cout << "   Posibles salidas en pantalla:\n";
    std::cout << "   - (Objeto no existe) El objeto nombre_objeto no ha sido cargado en memoria.\n";
    std::cout << "   - (Resultado exitoso) El objeto nombre_objeto ha sido eliminado de la memoria de trabajo.\n\n";

    std::cout << "6. Comando: guardar nombre_objeto nombre_archivo\n";
    std::cout << "   Descripción: Escribe en un archivo de texto, identificado por nombre_archivo, la información básica (vértices y caras) del objeto identificado por nombre_objeto.\n";
    std::cout << "   Posibles salidas en pantalla:\n";
    std::cout << "   - (Objeto no existe) El objeto nombre_objeto no ha sido cargado en memoria.\n";
    std::cout << "   - (Resultado exitoso) La información del objeto nombre_objeto ha sido guardada exitosamente en el archivo nombre_archivo.\n\n";

    std::cout << "7. Comando: v_cercano px py pz nombre_objeto\n";
    std::cout << "   Descripción: Identifica el vértice del objeto nombre_objeto más cercano (en términos de la distancia euclidiana) al punto indicado por las coordenadas px, py y pz.\n";
    std::cout << "   Posibles salidas en pantalla:\n";
    std::cout << "   - (Objeto no existe) El objeto nombre_objeto no ha sido cargado en memoria.\n";
    std::cout << "   - (Resultado exitoso) El vértice i (vx, vy, vz) del objeto nombre_objeto es el más cercano al punto (px, py, pz), a una distancia de valor_distancia.\n\n";

    std::cout << "8. Comando: v_cercano px py pz\n";
    std::cout << "   Descripción: Identifica, entre todos los objetos cargados en memoria, el vértice más cercano (en términos de la distancia euclidiana) al punto indicado por las coordenadas px, py y pz.\n";
    std::cout << "   Posibles salidas en pantalla:\n";
    std::cout << "   - (Memoria vacía) Ningún objeto ha sido cargado en memoria.\n";
    std::cout << "   - (Resultado exitoso) El vértice i (vx, vy, vz) del objeto nombre_objeto es el más cercano al punto (px, py, pz), a una distancia de valor_distancia.\n\n";

    std::cout << "9. Comando: v_cercanos_caja nombre_objeto\n";
    std::cout << "   Descripción: Identifica los vértices del objeto nombre_objeto más cercanos a los puntos que definen la caja envolvente del objeto.\n";
    std::cout << "   Posibles salidas en pantalla:\n";
    std::cout << "   - (Objeto no existe) El objeto nombre_objeto no ha sido cargado en memoria.\n";
    std::cout << "   - (Resultado exitoso) Los vértices del objeto nombre_objeto más cercanos a las esquinas de su caja envolvente son:\n";
    std::cout << "     Esquina Vertice Distancia\n";
    std::cout << "     1 (e1x, e1y, e1z) i1 (v1x, v1y, v1z) valor_distancia_1\n";
    std::cout << "     2 (e2x, e2y, e2z) i2 (v2x, v2y, v2z) valor_distancia_2\n";
    std::cout << "     ...\n";
    std::cout << "     8 (e8x, e8y, e8z) i8 (v8x, v8y, v8z) valor_distancia_8\n\n";

    std::cout << "10. Comando: ruta_corta i1 i2 nombre_objeto\n";
    std::cout << "    Descripción: Identifica los índices de los vértices que conforman la ruta más corta entre los vértices dados para el objeto nombre_objeto.\n";
    std::cout << "    Posibles salidas en pantalla:\n";
    std::cout << "    - (Objeto no existe) El objeto nombre_objeto no ha sido cargado en memoria.\n";
    std::cout << "    - (Índices iguales) Los índices de los vértices dados son iguales.\n";
    std::cout << "    - (Índices no existen) Algunos de los índices de vértices están fuera de rango para el objeto nombre_objeto.\n";
    std::cout << "    - (Resultado exitoso) La ruta más corta que conecta los vértices i1 y i2 del objeto nombre_objeto pasa por: i1, v1, v2, ..., vn, i2; con una longitud de valor_distancia.\n\n";

    std::cout << "11. Comando: ruta_corta_centro i1 nombre_objeto\n";
    std::cout << "    Descripción: Identifica los índices de los vértices que conforman la ruta más corta entre el vértice dado y el centro del objeto nombre_objeto.\n";
    std::cout << "    Posibles salidas en pantalla:\n";
    std::cout << "    - (Objeto no existe) El objeto nombre_objeto no ha sido cargado en memoria.\n";
    std::cout << "    - (Índice no existe) El índice de vértice está fuera de rango para el objeto nombre_objeto.\n";
    std::cout << "    - (Resultado exitoso) La ruta más corta que conecta el vértice i1 con el centro del objeto nombre_objeto, ubicado en ct (ctx, cty, ctz), pasa por: i1, v1, v2, ..., vn, ic; con una longitud de valor_distancia.\n\n";

    std::cout << "12. Comando: guardar_caja nombre_objeto nombre_archivo\n";
    std::cout << "    Descripción: Escribe en un archivo de texto, identificado por nombre_archivo, la información de la caja envolvente del objeto nombre_objeto.\n";
    std::cout << "    Posibles salidas en pantalla:\n";
    std::cout << "    - (Objeto no existe) El objeto nombre_objeto no ha sido cargado en memoria.\n";
    std::cout << "    - (Resultado exitoso) La caja envolvente del objeto nombre_objeto ha sido guardada exitosamente en el archivo nombre_archivo.\n\n";
}

// Verificar si un objeto se encuentra cargado en memoria
bool Menu::objetoCargado(const std::string& nombre_objeto) {
    for (int i = 0; i < objetosCargados.size(); i++) {
        if (objetosCargados[i].getNombre() == nombre_objeto) {
            return true;
        }
    }
    return false;
}

// Salir del programa
void Menu::salirPrograma() {
    std::cout << "Saliendo del programa..." << std::endl;
    exit(0);
}

// Cargar objeto en memoria
void Menu::cargarObjeto(const std::string& nombre_archivo) {
    std::ifstream file(nombre_archivo);
    if (!file.is_open()) {
        std::cout << "(Archivo no existe) El archivo " << nombre_archivo << " no existe o es ilegible." << std::endl;
        return;
    }

    std::string mesh_name;
    int n_vertices;
    std::vector<Vertice> vertices;
    std::vector<Cara> caras;

    std::string line;

    if (std::getline(file, mesh_name)) {
        if (objetoCargado(mesh_name)) {
            std::cout << "(Objeto ya existe) El objeto " << mesh_name << " ya ha sido cargado en memoria." << std::endl;
            return;
        }
    } else {
        std::cout << "(Archivo vacío o incompleto) El archivo " << nombre_archivo << " no contiene un objeto 3D válido." << std::endl;
        return;
    }

    if (std::getline(file, line)) {
        try {
            n_vertices = std::stoi(line);
        } catch (...) {
            std::cout << "(Formato inválido) El número de vértices no es válido en el archivo " << nombre_archivo << "." << std::endl;
            return;
        }
    } else {
        std::cout << "(Archivo vacío o incompleto) El archivo " << nombre_archivo << " no contiene un objeto 3D válido." << std::endl;
        return;
    }

    for (int i = 0; i < n_vertices; ++i) {
        if (std::getline(file, line)) {
            std::stringstream ss(line);
            double x = 0.0, y = 0.0, z = 0.0;
            ss >> x >> y >> z;
            vertices.push_back(Vertice(x, y, z));
        } else {
            std::cout << "(Archivo vacío o incompleto) El archivo " << nombre_archivo << " no contiene un objeto 3D válido." << std::endl;
            return;
        }
    }

    while (std::getline(file, line)) {
        if (line == "-1") break;
        std::stringstream ss(line);
        int num_vertices;
        if (!(ss >> num_vertices) || num_vertices <= 0) {
            std::cout << "(Formato inválido) El número de vértices de la cara no es válido en el archivo " << nombre_archivo << "." << std::endl;
            return;
        }

        std::vector<int> indices(num_vertices);
        for (int i = 0; i < num_vertices; ++i) {
            if (!(ss >> indices[i])) {
                std::cout << "(Formato inválido) Los índices de los vértices no son válidos en el archivo " << nombre_archivo << "." << std::endl;
                return;
            }
        }

        Cara cara;
        for (int index : indices) {
            if (index >= 0 && index < vertices.size()) {
                cara.agregarVertice(vertices[index]);
            } else {
                std::cout << "(Índice inválido) El índice del vértice en la cara es inválido en el archivo " << nombre_archivo << "." << std::endl;
                return;
            }
        }
        caras.push_back(cara);
    }

    Objeto objeto(mesh_name);
    for (const Cara& cara : caras) {
        objeto.agregarCara(cara);
    }
    objetosCargados.push_back(objeto);

    std::cout << "(Resultado exitoso) El objeto " << mesh_name << " ha sido cargado exitosamente desde el archivo " << nombre_archivo << "." << std::endl;
}

// Listar objetos cargados en memoria
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

// Crear caja de ajuste para un objeto determinado
void Menu::calcularCajaEnvolvente(const std::string& nombre_objeto) {
    Objeto* objetoEncontrado = nullptr;
    for (int i = 0; i < objetosCargados.size(); ++i) {
        if (objetosCargados[i].getNombre() == nombre_objeto) {
            objetoEncontrado = &objetosCargados[i];
            break;
        }
    }

    if (!objetoEncontrado) {
        std::cout << "(Objeto no existe) El objeto " << nombre_objeto << " no ha sido cargado en memoria." << std::endl;
        return;
    }

    double xmin = std::numeric_limits<double>::max();
    double ymin = std::numeric_limits<double>::max();
    double zmin = std::numeric_limits<double>::max();
    double xmax = std::numeric_limits<double>::lowest();
    double ymax = std::numeric_limits<double>::lowest();
    double zmax = std::numeric_limits<double>::lowest();

    for (const Cara& cara : objetoEncontrado->getCaras()) {
        for (const Vertice& vertice : cara.getVertices()) {
            double x = vertice.getX();
            double y = vertice.getY();
            double z = vertice.getZ();

            if (x < xmin) xmin = x;
            if (y < ymin) ymin = y;
            if (z < zmin) zmin = z;
            if (x > xmax) xmax = x;
            if (y > ymax) ymax = y;
            if (z > zmax) zmax = z;
        }
    }

    std::string nombreBase = "env_" + nombre_objeto;
    std::string nombreCaja = nombreBase;
    int contador = 1;

    if (objetoCargado(nombreCaja)) {
        while (objetoCargado(nombreCaja)) {
            nombreCaja = nombreBase + std::to_string(contador);
            ++contador;
        }
    }

    Objeto cajaEnvolvente(nombreCaja);

    std::vector<Vertice> vertices = {
        Vertice(xmin, ymin, zmin),
        Vertice(xmin, ymin, zmax),
        Vertice(xmin, ymax, zmin),
        Vertice(xmin, ymax, zmax),
        Vertice(xmax, ymin, zmin),
        Vertice(xmax, ymin, zmax),
        Vertice(xmax, ymax, zmin),
        Vertice(xmax, ymax, zmax)
    };

    std::vector<Cara> caras = {
        Cara({vertices[0], vertices[1], vertices[3], vertices[2]}),
        Cara({vertices[4], vertices[5], vertices[7], vertices[6]}),
        Cara({vertices[0], vertices[1], vertices[5], vertices[4]}),
        Cara({vertices[1], vertices[3], vertices[7], vertices[5]}),
        Cara({vertices[3], vertices[2], vertices[6], vertices[7]}),
        Cara({vertices[2], vertices[0], vertices[4], vertices[6]})
    };

    cajaEnvolvente.setCaras(caras);

    objetosCargados.push_back(cajaEnvolvente);

    std::cout << "(Resultado exitoso) La caja envolvente del objeto " << nombre_objeto
              << " se ha generado con el nombre " << nombreCaja
              << " y se ha agregado a los objetos en memoria." << std::endl;
}

// Crear caja de ajuste global
void Menu::crearCajaDeAjusteGlobal() {
    if (objetosCargados.empty()) {
        std::cout << "(Memoria vacía) Ningún objeto ha sido cargado en memoria." << std::endl;
        return;
    }

    double xmin = std::numeric_limits<double>::max();
    double ymin = std::numeric_limits<double>::max();
    double zmin = std::numeric_limits<double>::max();
    double xmax = std::numeric_limits<double>::lowest();
    double ymax = std::numeric_limits<double>::lowest();
    double zmax = std::numeric_limits<double>::lowest();

    for (const Objeto& objeto : objetosCargados) {
        for (const Cara& cara : objeto.getCaras()) {
            for (const Vertice& vertice : cara.getVertices()) {
                double x = vertice.getX();
                double y = vertice.getY();
                double z = vertice.getZ();

                if (x < xmin) xmin = x;
                if (y < ymin) ymin = y;
                if (z < zmin) zmin = z;
                if (x > xmax) xmax = x;
                if (y > ymax) ymax = y;
                if (z > zmax) zmax = z;
            }
        }
    }

    std::string nombreBase = "env_global";
    std::string nombreCajaGlobal = nombreBase;
    int contador = 1;
    
    if (objetoCargado(nombreCajaGlobal)) {
        while (objetoCargado(nombreCajaGlobal)) {
            nombreCajaGlobal = nombreBase + std::to_string(contador);
            ++contador;
        }
    }

    Objeto cajaGlobal(nombreCajaGlobal);

    std::vector<Vertice> vertices = {
        Vertice(xmin, ymin, zmin),
        Vertice(xmin, ymin, zmax),
        Vertice(xmin, ymax, zmin),
        Vertice(xmin, ymax, zmax),
        Vertice(xmax, ymin, zmin),
        Vertice(xmax, ymin, zmax),
        Vertice(xmax, ymax, zmin),
        Vertice(xmax, ymax, zmax)
    };

    std::vector<Cara> caras = {
        Cara({vertices[0], vertices[1], vertices[3], vertices[2]}),
        Cara({vertices[4], vertices[5], vertices[7], vertices[6]}),
        Cara({vertices[0], vertices[1], vertices[5], vertices[4]}),
        Cara({vertices[1], vertices[3], vertices[7], vertices[5]}),
        Cara({vertices[3], vertices[2], vertices[6], vertices[7]}),
        Cara({vertices[2], vertices[0], vertices[4], vertices[6]})
    };

    cajaGlobal.setCaras(caras);

    objetosCargados.push_back(cajaGlobal);

    std::cout << "(Resultado exitoso) La caja de ajuste global se ha generado con el nombre " << nombreCajaGlobal
              << " y se ha agregado a los objetos en memoria." << std::endl;
}

// Elimina un objeto
void Menu::descargarObjeto(std::string& nombre_objeto) {
    for (std::vector<Objeto>::iterator it = objetosCargados.begin(); it != objetosCargados.end(); ++it) {
        if (it->getNombre() == nombre_objeto) {
            objetosCargados.erase(it);
            std::cout << "(Resultado exitoso) El objeto " << nombre_objeto 
                      << " ha sido eliminado de la memoria de trabajo." << std::endl;
            return;
        }
    }
    
    std::cout << "(Objeto no existe) El objeto " << nombre_objeto << " no ha sido cargado en memoria." << std::endl;
}

// Guardar Objeto
void Menu::guardarObjetoEnArchivo(const std::string& nombre_objeto, const std::string& nombre_archivo) {
    Objeto* objetoEncontrado = nullptr;
    for (int i = 0; i < objetosCargados.size(); ++i) {
        if (objetosCargados[i].getNombre() == nombre_objeto) {
            objetoEncontrado = &objetosCargados[i];
            break;
        }
    }

    if (!objetoEncontrado) {
        std::cout << "(Objeto no existe) El objeto " << nombre_objeto << " no ha sido cargado en memoria." << std::endl;
        return;
    }

    const Objeto& objeto = *objetoEncontrado;
    std::ofstream archivo(nombre_archivo);

    if (!archivo) {
        std::cerr << "Error al abrir el archivo para escritura." << std::endl;
        return;
    }
    
    archivo << objeto.getNombre() << std::endl;

    std::vector<Vertice> verticesUnicos;
    for (int i = 0; i < objeto.getCaras().size(); ++i) {
        const Cara& cara = objeto.getCaras()[i];
        for (int j = 0; j < cara.getNumeroVertices(); ++j) {
            const Vertice& verticeCara = cara.getVertices()[j];
            bool encontrado = false;
            for (int k = 0; k < verticesUnicos.size(); ++k) {
                if (verticesUnicos[k] == verticeCara) {
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                verticesUnicos.push_back(verticeCara);
            }
        }
    }

    int numVertices = verticesUnicos.size();
    archivo << numVertices << std::endl;

    for (int i = 0; i < numVertices; ++i) {
        const Vertice& vertice = verticesUnicos[i];
        archivo << vertice.getX() << ' ' << vertice.getY() << ' ' << vertice.getZ() << std::endl;
    }

    for (int i = 0; i < objeto.getCaras().size(); ++i) {
        const Cara& cara = objeto.getCaras()[i];
        int numVerticesCara = cara.getNumeroVertices();
        archivo << numVerticesCara;
        for (int j = 0; j < numVerticesCara; ++j) {
            const Vertice& verticeCara = cara.getVertices()[j];
            int indice = -1;
            for (int k = 0; k < numVertices; ++k) {
                if (verticesUnicos[k] == verticeCara) {
                    indice = k;
                    break;
                }
            }
            archivo << ' ' << indice;
        }
        archivo << std::endl;
    }

    archivo << "-1";
    archivo.close();

    std::cout << "(Resultado exitoso) La información del objeto " << nombre_objeto
              << " ha sido guardada exitosamente en el archivo " << nombre_archivo << "." << std::endl;
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