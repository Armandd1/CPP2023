//
// Created by arman on 2023. 10. 30.
//

#include <random>
#include "matrix.h"

Matrix::Matrix(int mRows, int mCols) {
    this->mRows = mRows;
    this->mCols = mCols;
    this->mElements = new double *[mRows];
    for (int i = 0; i < mRows; i++) {
        this->mElements[i] = new double[mCols];
    }
}

Matrix::Matrix(const Matrix &what) {
    this->mRows = what.mRows;
    this->mCols = what.mCols;
    this->mElements = new double *[mRows];
    for (int i = 0; i < mRows; i++) {
        this->mElements[i] = new double[mCols];
    }
    for (int i = 0; i < mRows; i++) {
        for (int j = 0; j < mCols; j++) {
            this->mElements[i][j] = what.mElements[i][j];
        }
    }
}

Matrix::Matrix(Matrix &&what) {
    this->mCols = what.mCols;
    this->mRows = what.mRows;
    this->mElements = what.mElements;
    what.mElements = nullptr;
    what.mRows = 0;
    what.mCols = 0;
}

Matrix::~Matrix() {
    for (int i = 0; i < mRows; i++) {
        delete[] this->mElements[i];
    }
    delete[] this->mElements;
    this->mElements = nullptr;
    this->mRows = 0;
    this->mCols = 0;
}

void Matrix::fillMatrix(double value) {
    for (int i = 0; i < mRows; i++) {
        for (int j = 0; j < mCols; j++) {
            this->mElements[i][j] = value;
        }
    }
}

void Matrix::randomMatrix(int a, int b) {

    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(a,b-1);

    for (int i = 0; i < mRows; i++) {
        for (int j = 0; j < mCols; j++) {
            this->mElements[i][j] = dist(mt);
        }
    }
}

void Matrix::printMatrix(ostream &os) const {
    for (int i = 0; i < mRows; i++) {
        for (int j = 0; j < mCols; j++) {
            os << this->mElements[i][j] << " ";
        }
        os << endl;
    }

}

bool Matrix::isSquare() const {
    if(this->mRows == this->mCols) {
        return true;
    }
    return false;
}

Matrix operator+(const Matrix &x, const Matrix &y) {
    if(x.mRows != y.mRows || x.mCols != y.mCols) {
        throw std::out_of_range("Matrix dimensions do not match!");
    }
    else{
        Matrix *mat = new Matrix(x.getRows(), x.getCols());
        for( int i =0; i < mat->mRows; i++) {
            for( int j = 0; j < mat->mCols; j++) {
                mat->mElements[i][j] = x.mElements[i][j] + y.mElements[i][j];
            }
        }
        return *mat;
    }
}

Matrix operator*(const Matrix &x, const Matrix &y) {
    if(x.mCols != y.mRows) {
        throw std::out_of_range("Matrix dimensions do not match!");
    }
    else{
        Matrix *mat = new Matrix(x.getRows(), y.getCols());
        for( int i =0; i < mat->mRows; i++) {
            for( int j = 0; j < mat->mCols; j++) {
                mat->mElements[i][j] = 0;
                for( int k = 0; k < x.mCols; k++) {
                    mat->mElements[i][j] += x.mElements[i][k] * y.mElements[k][j];
                }
            }
        }
        return *mat;
    }
}

istream &operator>>(istream &is, Matrix &mat) {
    for( int i =0; i < mat.mRows; i++) {
        for( int j = 0; j < mat.mCols; j++) {
            is >> mat.mElements[i][j];
        }
    }
    return is;
}

ostream &operator<<(ostream &os, const Matrix &mat) {
    for( int i =0; i < mat.mRows; i++) {
        for( int j = 0; j < mat.mCols; j++) {
            os << mat.mElements[i][j] << " ";
        }
    }
    return os;
}

double *Matrix::operator[](int index) {
    if(index < 0 || index > this->mRows) {
        throw std::out_of_range("Index out of range!");
    }
    return this->mElements[index];
}

double *Matrix::operator[](int index) const {
    if(index < 0 || index > this->mRows) {
        throw std::out_of_range("Index out of range!");
    }
    return this->mElements[index];
}

Matrix &Matrix::operator=(const Matrix &mat) {
    if(this->mRows != mat.mRows || this->mCols != mat.mCols) {
        throw std::out_of_range("Matrix dimensions do not match!");
    }
    else{
        this->mRows = mat.mRows;
        this->mCols = mat.mCols;
        for( int i =0; i < mat.mRows; i++) {
            for( int j = 0; j < mat.mCols; j++) {
                this->mElements[i][j] = mat.mElements[i][j];
            }
        }
        return *this;
    }
}

Matrix &Matrix::operator=(Matrix &&mat) {
    if(this->mRows != mat.mRows || this->mCols != mat.mCols) {
        throw std::out_of_range("Matrix dimensions do not match!");
    }
    else{
        this->mRows = mat.mRows;
        this->mCols = mat.mCols;
        this->mElements = mat.mElements;
        mat.mRows = 0;
        mat.mCols = 0;
        mat.mElements = nullptr;
        return *this;
    }
}
