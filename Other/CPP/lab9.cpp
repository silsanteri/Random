// Exercise 9

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator> 
#include <vector>
#include <cstdlib>
#include <cstdint>
#include <ios>
#include <limits>
#include <iomanip>
#include <sstream>
#include <memory>


// Functions
double getDouble(const char* msg);


// Point
class Point {
    public:
        Point(double xcoord = 0.0, double ycoord = 0.0) : x(xcoord), y(ycoord){}
        virtual ~Point() = default;
        virtual void input(); // I removed the prompt variable, because I think it's unnecessary.
        virtual void output() const;
        virtual double area() const;
        void move(double deltax, double deltay);
    private:
        double x;
        double y;
};


// Circle
class Circle : public Point {
    public:
        Circle(double xcoord = 0.0, double ycoord = 0.0, double rad = 0.0): Point(xcoord, ycoord), radius(rad){}
        void input();
        void output() const;
        double area() const;
        void move(double deltax, double deltay);
    private:
        double radius;
};


// Square
class Square : public Point {
    public:
        Square(double xcoord = 0.0, double ycoord = 0.0, double wid = 0.0, double hei = 0.0): Point(xcoord, ycoord), width(wid), height(hei){}
        void input();
        void output() const;
        double area() const;
        void move(double deltax, double deltay);
    private:
        double width;
        double height;
};


// Source: https://stackoverflow.com/questions/1380463/sorting-a-vector-of-custom-objects
struct sortPointArea {
    inline bool operator() (const std::shared_ptr<Point>& p1, const std::shared_ptr<Point>& p2){
        return (p1->area() < p2->area());
    }
};


int main(){
    srand(time(NULL));
    int randTemp = 0;

    Point one(1.0, 1.0);
    Circle two(2.0, 2.0, 2.0);
    Square three(5.0, 5.0, 2.0, 2.0);
    Square four(0, 0, 0, 0);
    Circle five(0, 0, 0);
    Point six(0, 0);

    four.input();
    five.input();
    six.input();

    std::vector<std::shared_ptr<Point>> list;
    list.push_back(std::make_shared<Point>(one));
    list.push_back(std::make_shared<Circle>(two));
    list.push_back(std::make_shared<Square>(three));
    list.push_back(std::make_shared<Square>(four));
    list.push_back(std::make_shared<Circle>(five));
    list.push_back(std::make_shared<Point>(six));

    // Extra Exercise (9B)
    // I'm not sure if this is the right way to implement the extra exercise.
    // But it works and I can't figure out a better way to do it.
    std::cout << "Creating five random objects." << std::endl;
    for(int i=0; i<5; i++){
        randTemp = (rand() % 3) + 1;

        if (randTemp == 1){
            std::cout << "Random object #" << i+1 << " - Point" << std::endl;
            Point p;
            p.input();
            list.push_back(std::make_shared<Point>(p));
        } else if (randTemp == 2){
            std::cout << "Random object #" << i+1 << " - Circle" << std::endl;
            Circle c;
            c.input();
            list.push_back(std::make_shared<Circle>(c));
        } else if (randTemp == 3){
            std::cout << "Random object #" << i+1 << " - Square" << std::endl;
            Square s;
            s.input();
            list.push_back(std::make_shared<Square>(s));
        } else {
            std::cout << "Unexpected error!" << std::endl;
            break;
        }
    }
    // END OF Extra

    std::cout << std::endl;
    for(auto p : list){
        p->output();
    }

    std::sort(list.begin(), list.end(), sortPointArea());
    
    std::cout << "\nSorted:" << std::endl;
    for(auto p : list){
        p->output();
    }
}


// Functions
double getDouble(const char* msg){
    double temp;
    while (1) {
        std::cout << msg;
        if (std::cin >> temp) {
            break;
        } else {
            std::cout << "Enter a numerical value." << std::endl;
            std::cin.clear();
            while (std::cin.get() != '\n') ;
        }
    }
    return temp;
}


// Point
void Point::input(){
    this->x = getDouble("Enter x: ");
    this->y = getDouble("Enter y: ");
}

void Point::output() const{
    std::cout << "Coordinates: (" << this->x << "," << this->y << ")" << std::endl;
}

double Point::area() const{
    return 0.0;
}

void Point::move(double deltax, double deltay){
    this->x += deltax;
    this->y += deltay;
}


// Circle
void Circle::input(){
    Point::input();
    this->radius = getDouble("Enter radius: ");
}

void Circle::output() const{
    std::cout << "Circle's area: " << this->area() << " - ";
    Point::output();
}

double Circle::area() const{
    const float pi = 3.14159f;
    return pi * radius * radius;
}

void Circle::move(double deltax, double deltay){
    Point::move(deltax, deltay);
}


// Square
void Square::input(){
    Point::input();
    this->width = getDouble("Enter width: ");
    this->height = getDouble("Enter height: ");
}

void Square::output() const{
    std::cout << "Square's area: " << this->area() << " - ";
    Point::output();
}

double Square::area() const{
    return height * width;
}

void Square::move(double deltax, double deltay){
    Point::move(deltax, deltay);
}