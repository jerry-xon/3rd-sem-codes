#include <stdio.h>

typedef struct {
    float real;
    float imaginary;
} Complex;

Complex addComplex(Complex c1, Complex c2){
    Complex result;
    result.real = c1.real + c2.real;
    result.imaginary = c1.imaginary + c2.imaginary;
    return result;
}

Complex multiplyComplex(Complex c1, Complex c2){
    Complex result;
    result.real = c1.real * c2.real - c1.imaginary * c2.imaginary;
    result.imaginary  = c1.real * c2.imaginary + c1.imaginary * c2.real;

    return result;
}                                             
                                            
int main(){                                             
    Complex c1, c2, sum, product;                                             
                                            
    printf("Enter the real and the imaginar part of the first complex number: ");                                             
    scanf("%f %f", &c1.real, &c1.imaginary);                                             
                                            
    printf("Enter the real and the imaginar part of the second complex number: ");                                             
    scanf("%f %f", &c2.real, &c2.imaginary);                                             
                                            
    sum = addComplex(c1, c2);                                             
    product = multiplyComplex(c1, c2);                                             
                                            
    printf("Sum = %f + %f\n", sum.real, sum.imaginary);                                             
    printf("Product = %f + %f\n", product.real, product.imaginary);                                              
                                            
    return 0;

}