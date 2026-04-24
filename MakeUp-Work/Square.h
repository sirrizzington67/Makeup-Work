#ifndef SQUARE_H
#define SQUARE_H

class Square {
public:
    Square(int side = 0);

    int getSide()      const { return side; }
    void setSide(int s);

    int getArea()      const { return side * side; }
    int getPerimeter() const { return 4 * side; }

private:
    int side;
};

#endif