#include "Magnitude.h"

double vectorMagnitude(const std::vector<double>& vec){

    double sum = 0.00;

    for (double val: vec){
        sum+= val*val;
    }

    return sqrt(sum);

}