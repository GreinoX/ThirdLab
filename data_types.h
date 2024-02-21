//
// Created by Thund on 19.02.2024.
//

#define MAX_SIZE 100


#ifndef THIRDLAB_DATA_TYPES_H
#define THIRDLAB_DATA_TYPES_H

#include <iostream>
#include <cmath>

namespace fig{

    class Point{
    public:
        double x = 0;
        double y = 0;

        Point();

        Point(const double &_x, const double &_y);

        Point(const std::pair<double, double> &_x);

    };

    class Triangle{
    private:
        fig::Point a;
        fig::Point b;
        fig::Point c;
        double square;
    public:
        Triangle();

        Triangle(const std::pair<double, double> &_a, const std::pair<double, double> &_b, const std::pair<double, double> &_c );

        void calculate_square();

        bool operator == (const Triangle &T) const;

        bool operator != (const Triangle &T) const;

        bool operator >(const Triangle &T) const;

        bool operator <(const Triangle &T) const;

        double get_square();
    };
}

class Mass{
private:
    const size_t max_size = MAX_SIZE;
    size_t current_size = 1;
    int* massive;
public:
    Mass(size_t _current_size){
        if(_current_size < max_size){
            current_size = _current_size;
            massive = new int[current_size];
        }
    }

    int& operator[] (int index) const{
        return *(massive + index);
    }

    Mass& operator+(const Mass& T) const{
        if(current_size + T.current_size < MAX_SIZE){
            current_size = current_size + T.current_size;

        }
    }

    size_t get_size(){
        return current_size;
    }

};


#endif //THIRDLAB_DATA_TYPES_H
