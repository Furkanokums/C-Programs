#include <iostream>
using namespace std;

// 2+3i   4-2i   + - *   a+bi

class ComplexNumber {
private:
    int real;
    int image;
public:

    ComplexNumber(int real, int image) {
        this->real = real;
        this->image = real;
    }

    ComplexNumber operator + (const ComplexNumber &x) {
        int a = this->real + x.real;
        int b = this->image + x.image;
        ComplexNumber *new_complex_number = new ComplexNumber(a,b);
        return *new_complex_number;
    }

    ComplexNumber operator - (const ComplexNumber &x) {
        int a = this->real - x.real;
        int b = this->image - x.image;
        ComplexNumber *new_complex_number = new ComplexNumber(a,b);
        return *new_complex_number;
    }

    ComplexNumber operator * (const ComplexNumber &x) {
        int a = (this->real * x.real) - (this->image * x.image);
        int b = (this->real*x.image) + (this->image*x.real);
        ComplexNumber *new_complex_number = new ComplexNumber(a,b);
        return *new_complex_number;
    }

    bool operator == (const ComplexNumber &x) {
        return this->real == x.real && this->image == x.image ;
    }


    friend ostream& operator <<(ostream &out,ComplexNumber c) {
        if (c.image >= 0) {
            out << c.real << "+" << c.image << "i"<<endl;
        }
        else {
            out << c.real << c.image << "i"<<endl;
        }
    }

};
int main() {

    ComplexNumber c1(2,3);
    ComplexNumber c2(4,1);

    cout << c1+c2<<endl;




}
