#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class Objeto {
private:
    std::string nombre_objeto;
    int n_vertices;
    std::vector<int> x;
    std::vector<int> y;
    std::vector<int> z;
    std::vector<int> cj;
    std::vector<int> ij;

public:
    // Constructor
    Objeto(std::string nombre_objeto, int n_vertices, std::vector<int> x, std::vector<int> y, std::vector<int> z,
           std::vector<int> cj, std::vector<int> ij)
        : nombre_objeto(nombre_objeto), n_vertices(n_vertices), x(x), y(y), z(z), cj(cj), ij(ij) {}

    // Getters
    std::string getNombreObjeto() const { return nombre_objeto; }
    int getNVertices() const { return n_vertices; }
    std::vector<int> getX() const { return x; }
    std::vector<int> getY() const { return y; }
    std::vector<int> getZ() const { return z; }
    std::vector<int> getCj() const { return cj; }
    std::vector<int> getIj() const { return ij; }

    // Setters
    void setNombreObjeto(const std::string& nombre_objeto) { this->nombre_objeto = nombre_objeto; }
    void setNVertices(int n_vertices) { this->n_vertices = n_vertices; }
    void setX(const std::vector<int>& x) { this->x = x; }
    void setY(const std::vector<int>& y) { this->y = y; }
    void setZ(const std::vector<int>& z) { this->z = z; }
    void setCj(const std::vector<int>& cj) { this->cj = cj; }
    void setIj(const std::vector<int>& ij) { this->ij = ij; }

    // ToString
    std::string toString() const {
        std::ostringstream oss;
        int totalAristas = 0;
        
        for (const auto& num : cj) {
            totalAristas += num;
        }
    
        oss << nombre_objeto << " contiene " << n_vertices << " vértices, ";
        oss << totalAristas << " aristas y " << cj.size() << " caras.";
        return oss.str();
    }
};