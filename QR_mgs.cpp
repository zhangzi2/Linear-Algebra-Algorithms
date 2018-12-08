#include <stdio.h>
#include <iostream>
#include <vector>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

//QR factorization vis Modified GS
vector<MatrixXd> QR_mgs(MatrixXd A){
    MatrixXd Q = MatrixXd::Zero(A.rows(), A.cols());
    MatrixXd R = MatrixXd::Zero(A.cols(), A.cols());
    MatrixXd v = MatrixXd::Zero(A.rows(), A.cols());
    
    vector<MatrixXd> QR;
    
    for (int i = 0; i<A.cols(); ++i){
        v.row(i) = A.row(i);
    }
    
    for (int i = 0; i < A.cols(); ++i){
        R(i,i) = v.col(i).norm();
        Q.col(i) = (1/R(i,i))*v.col(i);
        
        for (int j = i + 1; j<A.cols(); ++j){
            R(i,j) = Q.col(i).adjoint()*v.col(j);
            v.col(j) =  v.col(j) - R(i,j)*Q.col(j);
        }   
    }
    QR.push_back(Q);
    QR.push_back(R);
    return QR;
}
