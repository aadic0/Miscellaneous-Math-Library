// first some background information

/*

All information sourced from: https://www.cs.cmu.edu/~15464-s13/lectures/lecture6/iksurvey.pdf

This formula is used in iterative control or gradient descent-based approaches for solving inverse kinematics problems.
It updates joint velocities to minimize positional error (e) in a cartesian space.

The formula is as follows:

\Delta\theta = J^Te

Where,
/Delta/theta is a vector of joint velocities (rate of change of all joint angles) for all n joints of a robot.
J is the jocobian matrix that maps joint velocities to end-effector velocties. The dimensions for the matrix are 6 x n, for n joints, with rows representing linear and angular velocity mappings.
T just means transpose.
e is the error vector, and is just simplified to e = xdesired - xcurrent, where both x are vectors in the cartesian space.

However, the classic transponse method implementation would cause a lot of unneccesary jerk in the robotic arm. Thus, we will implement a slightly different formula:

\Delta\theta = \alpha J^Te

Where \alpha is some scalar (run tests on the arm to determine the perfect number)


*/

#include <iostream>
#include <math.h>
#include <vector>
#include "MatrixMultiplication.h"
#include "Magnitude.h"

void jacobianTransposeIK(const std::vector<std::vector<double>>& J, 
                         std::vector<double>& theta, 
                         const std::vector<double>& desiredPosition, 
                         const std::vector<double>& currentPosition, 
                         double stepSize, 
                         double tolerance, double scaler){
    
    std::vector<double> error(desiredPosition.size());
    
    // Iterative loop
    while (true){

        // Compute the error vector
        for (size_t i = 0; i < desiredPosition.size(); ++i){
            error[i] = desiredPosition[i] - currentPosition[i];
        }

        // Check if the error is within tolerance
        if (vectorMagnitude(error) < tolerance){
            break;
        }

        // Compute the joint velocity update: J^T * e
        std::vector<double> jointVelocities = matrixVectorMultiply(J, error);

        

        // Update joint angles
        for (size_t i = 0; i < theta.size(); ++i) {
            theta[i] += stepSize * jointVelocities[i];
        }
    }

    std::cout << "Converged joint angles: ";
    for (double angle : theta) {
        std::cout << angle << " ";
    }
    std::cout << std::endl;
}


int main(){
    return 0;
}
