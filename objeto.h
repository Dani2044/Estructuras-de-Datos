#ifndef __OBJETO_H__
#define __OBJETO_H__

#include <string>
#include <vector>
#include <limits>
#include "vertice.h"
#include "cara.h"

class Objeto {
private:
    std::string nombre;
    std::vector<Cara> caras;

public:
    Objeto();
    Objeto(const std::string& nombre);
    Objeto(const std::string& nombre, const std::vector<Vertice>& vertices, const std::vector<Cara>& caras);

    std::string getNombre() const;
    const std::vector<Cara>& getCaras() const;
    void setNombre(const std::string& nombre);
    void setCaras(const std::vector<Cara>& caras);
    void agregarCara(const Cara& cara);
    void calcularCajaEnvolvente(double& xmin, double& ymin, double& zmin, double& xmax, double& ymax, double& zmax) const;
    std::string toString() const;
};

#endif // __OBJETO_H__

// eof - objeto.h