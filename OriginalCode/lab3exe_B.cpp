
// lab3exe_B.c
// ENSF 614 Fall 2021 LAB 3 - EXERCISE B

#include <iostream>
using namespace std;

#include "cplx_number.h"

void global_print(const Cplx& n);
// REQUIRES: n refers to an object of class Cplx
// PROMISES: displays the values of real and imaginary parts of a complex number.

int main(void)
{
    Cplx num1;
    
    num1.setRealPart(666);
    
    
    global_print(num1);
    
    Cplx num2(34, 5);
    
    global_print(num2);
    
    Cplx *p = &num2;
    
    cout << "\nTesting member functions add and subtract: \n";
    
    num2 = p -> add(num1);
    global_print(*p);
    
    num1 = num1.subtract(p);
    global_print(num1);
    
    return 0;
}

void global_print(const Cplx& n)
{
    cout << "\nYour complex number is: (" << n.getRealPart( )
    << ", "<< n.getImaginaryPart( ) << ")" << endl;
    
}

// pasted from cplx_number.cpp
Cplx::Cplx(double real , double imag ): realM(real),
imagM(imag) {
    // point three - When the program reaches this point for the second time
}

double Cplx::getRealPart() const {
    // point two - When the program reaches this point for the first time
    return realM;
}

double Cplx::getImaginaryPart( ) const {
    return imagM;
}

void Cplx::setRealPart(double arg) {
    
    realM = arg;
    // Point one
}

void Cplx::setImaginaryPart(double arg) {
    imagM = arg;
}

Cplx Cplx::add(const Cplx& other)const {
    Cplx local;
    
    local.realM = this->getRealPart() + other.realM;
    local.imagM = imagM + other.imagM;
    
    return local;
}

Cplx Cplx::subtract(const Cplx* other)const {
    Cplx local;
    local.realM = realM - other->realM;
    local.imagM = imagM - other->imagM;
    
    // point four
    
    return local;
}