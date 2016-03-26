#ifndef POINT_H
#define POINT_H

#include <iostream>

class point
{
public:
    point();
    point(int x, int y):x(x),y(y){}
    int getX() const {return x;}
    int getY() const {return y;}

    friend std::ostream& operator << (std::ostream & stream, const point & p)
    {
        stream << "point d'abscisse " << p.getX() << " et d'ordonnée " << p.getY() << std::endl;
        return stream;
    }

   private:
    int x,y;
};

#endif // POINT_H
