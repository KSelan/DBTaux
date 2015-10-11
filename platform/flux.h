#ifndef FLUX_H
#define FLUX_H
#include <cmath>

class Flux
{
public:
    Flux();
    Flux(int index, double value) : index(index),NFValue(value){}

    int index;
    double NFValue;
    double DiscountedValue;
    double capital;

    void discount(double taux)
    {
        this->DiscountedValue = NFValue /  std::pow(1+taux/12,this->index);
    }

    void financer(double taux)
    {
        this->DiscountedValue = NFValue *  std::pow(1+taux/12,this->index-1);
    }

};

#endif // FLUX_H
