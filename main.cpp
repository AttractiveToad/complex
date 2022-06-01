#include <iostream>
#include <cmath>

namespace myComplex
{
    template<typename T>
    class complex
    {
    private:
        T re;
        T im;
    public:
        //constructors
        complex(T r, T i) : re{r}, im{i} {}
        complex(T r) : re{r}, im{0.0} {}
        complex() : re{0.0}, im{0.0} {}
        //get private data
        T real() {
            return re;
        }
        T imag() {
            return im;
        }

        complex & operator += (complex z) {
            re+=z.re;
            im+=z.im;
            return *this;
        }
        complex & operator -= (complex z) {
            re-=z.re;
            im-=z.im;
            return *this;
        }
        complex & operator + (complex z) {
            complex temp;
            temp.re=re+z.re;
            temp.im=im+z.im;
            return temp;
        }
        complex operator - (complex z) {
            complex temp;
            temp.re=re-z.re;
            temp.im=im-z.im;
            return temp;
        }
        complex operator - () {
            complex temp;
            temp.re=-re;
            temp.im=-im;
            return temp;
        }
        complex operator*(complex z) {
            complex temp;
            temp.re=re*z.re-im*z.im;
            temp.im=re*z.im+im*z.re;
            return temp;
        }
        complex operator/(complex z) {
            complex temp;
            temp.re = (re * z.re + im * z.im) / (pow(z.re, 2) + pow(z.im, 2));
            temp.im = (im * z.re - z.im * re) / (pow(z.re, 2) + pow(z.im, 2));
            return temp;
        }

        bool operator!=(complex z) {
            return (re != z.re && im != z.im);
        }
        bool operator==(complex z) {
            return (re == z.re && im == z.im);
        }

        complex & operator *= (complex z);
        complex & operator /= (complex z);
    };

    //out of class definitions
    template<typename T>
    complex<T> & complex<T>::operator *= (complex z) {
        re=re*z.re-im*z.im;
        im=re*z.im+im*z.re;
        return *this;
    }

    template<typename T>
    complex<T> & complex<T>::operator /= (complex z) {
        re = (re * z.re + im * z.im) / (pow(z.re, 2) + pow(z.im, 2));
        im = (im * z.re - z.im * re) / (pow(z.re, 2) + pow(z.im, 2));
        return *this;
    }

    template<typename T>
    std::ostream & operator << (std::ostream& os, myComplex::complex<T> & z) {
        std::cout.precision(2);
        os << "real: " << std::scientific;
        os << z.real() << '\n';
        os << "imag: ";
        os << z.imag() << '\n';
        return (os);
    }
}

int main()
{
    myComplex::complex<double> z1 {1.0, 2.0};
    myComplex::complex<double> z2 {1.0, 2.0};
    myComplex::complex<double> z3;
    z3=z1/z2;
    //std::cout << (z1 == z2);
    std::cout << z3 << std::endl;
    //std::cout << z3 << std::endl;

    return 0;
}