/*
 * Exercise8.cxx
 * 
 * Copyright 2016 jacopot <jacopot@dip075.studenti.math.unipd.it>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <iostream>
#include <cmath>
using namespace std;

struct c_complex{
    double re;
    double im;
};

struct p_complex{
    double mag;
    double arg;
};

p_complex polar(c_complex z);
void write_complex(c_complex z);
c_complex product(c_complex, c_complex);
c_complex sum(c_complex, c_complex);
double magnitude (c_complex);
double angle (c_complex);


int main(){
    cout << "What are your number's coordinates? (Real first)" << endl;
    c_complex number;
    cin >> number.re >> number.im;
    cout << "The magnitude is: " << magnitude(number) << " and the argument is: " << angle(number) << endl;
    cout << "Now give me another complex number, in cartesian coordinates." << endl;
    c_complex number2;
    cin >> number2.re >> number2.im;
    cout << "Their sum is ";
    write_complex(sum(number, number2));
    cout << "Their product is ";
    write_complex(product(number, number2));
    return 0;
}

p_complex polar(c_complex z){
    p_complex z_p;
    z_p.mag = sqrt( pow(z.re, 2) + pow(z.im, 2) );
    z_p.arg = atan2( z.im, z.re );
    return z_p;
}

void write_complex(c_complex z){
    p_complex z_polar = polar(z);
    cout << z.re << " + " << z.im << "i, in polar cordinates " << z_polar.mag << "e^(" << z_polar.arg << "i)" << endl;
}

c_complex sum(c_complex x, c_complex y){
    c_complex sum;
    sum.re = x.re + y.re;
    sum.im = x.im + y.im;
    return sum;
}

c_complex product(c_complex x, c_complex y){
    c_complex product;
    product.re = x.re * y.re - x.im * y.im;
    product.im = x.re * y.im + x.im * y.re;
    return product;
}

double magnitude (c_complex x){
    p_complex polarn = polar (x);
    return polarn.mag;
}

double angle (c_complex x){
    p_complex polarn = polar (x);
    return polarn.arg;
}
