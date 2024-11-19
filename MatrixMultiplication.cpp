#include "MatrixMultiplication.h"

std::vector<double> matrixVectorMultiply(const std::vector<std::vector<double>>& matrix, const std::vector<double>& vec){

    std::vector<double> result(matrix.size(), 0.0);
    for (size_t i = 0; i < matrix.size(); ++i){
        for (size_t j = 0; j < vec.size(); ++j){
            result[i] += matrix[i][j] * vec[j];
        }
    }

    return result;

}

