#ifndef __CARA_H__
#define __CARA_H__

#include <vector>
#include "vertice.h"

class Cara {
private:
    std::vector<Vertice> vertices;  // Almacena directamente objetos Vertice

public:
    Cara();
    Cara(const std::vector<Vertice>& vertices);

    const std::vector<Vertice>& getVertices() const;
    int getNumeroVertices() const;
    void setVertices(const std::vector<Vertice>& vertices);
    double calcularArea() const;
    void agregarVertice(const Vertice& vertice);
};

#endif // __CARA_H__

// eof - cara.h