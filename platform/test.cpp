#include "test.h"

test::test()
{
    class Point{
public:
        int x;
        mutable int y;

        int getX() const {return this->x;}
        int incrementAndGetY() const
        {
            this->y++;
            return this->y;
        }
        int getY(){return this->y;}
    };

    void launchConstTest()
    {
        Point p1;
        p1.x = 13;
        p1.y = 14;

        int x1 = p1.getX();
        int y1 = p1.incrementAndGetY();

        const Point p2;
        p2.y = 1;
        int y2 = p2.getY();

    }

}

