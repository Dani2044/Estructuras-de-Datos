#include "objeto.h"
#include <sstream>
#include <limits>

// Constructor por defecto
Objeto::Objeto() {}

// Constructor con nombre
Objeto::Objeto(const std::string& nombre) : nombre(nombre) {}

// Constructor con parámetros
Objeto::Objeto(const std::string& nombre, const std::vector<Vertice>& vertices, const std::vector<Cara>& caras)
    : nombre(nombre), caras(caras) {}

// Getters
std::string Objeto::getNombre() const {
    return nombre;
}

const std::vector<Cara>& Objeto::getCaras() const {
    return caras;
}

// Setters
void Objeto::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}

void Objeto::setCaras(const std::vector<Cara>& caras) {
    this->caras = caras;
}

// Métodos para agregar elementos
void Objeto::agregarCara(const Cara& cara) {
    caras.push_back(cara);
}

// Métodos de manipulación
void Objeto::calcularCajaEnvolvente(double& xmin, double& ymin, double& zmin, double& xmax, double& ymax, double& zmax) const {
    xmin = ymin = zmin = std::numeric_limits<double>::max();
    xmax = ymax = zmax = std::numeric_limits<double>::lowest();

    for (const Cara& cara : caras) {
        for (const Vertice& vertice : cara.getVertices()) {
            if (vertice.getX() < xmin) xmin = vertice.getX();
            if (vertice.getY() < ymin) ymin = vertice.getY();
            if (vertice.getZ() < zmin) zmin = vertice.getZ();
            if (vertice.getX() > xmax) xmax = vertice.getX();
            if (vertice.getY() > ymax) ymax = vertice.getY();
            if (vertice.getZ() > zmax) zmax = vertice.getZ();
        }
    }
}

// Método para obtener una representación en cadena
std::string Objeto::toString() const {
    std::ostringstream oss;
    oss << "Nombre: " << nombre << "\n";
    oss << "Número de caras: " << caras.size() << "\n";
    for (const Cara& cara : caras) {
        oss << "Cara con " << cara.getNumeroVertices() << " vértices\n";
    }
    return oss.str();
}