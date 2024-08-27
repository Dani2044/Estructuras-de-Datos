#ifndef __VERTICE_H__
#define __VERTICE_H__

class Vertice {
private:
    double x, y, z;

public:
    Vertice();
    Vertice(double x, double y, double z);

    double getX() const;
    double getY() const;
    double getZ() const;
    void setX(double x);
    void setY(double y);
    void setZ(double z);
    double distancia(const Vertice& otro) const;
    bool operator==(const Vertice& otro) const;
};

#endif // __VERTICE_H__

// eof - vertice.h