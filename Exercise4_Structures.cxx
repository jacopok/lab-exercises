/*
 * Exercise3.cxx
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

int main(){
    cout << "What are your coordinates? (Real first)" << endl;
    c_complex number;
    cin >> number.re >> number.im;
    p_complex polar_number = polar(number);
    cout << "The magnitude is: " << polar_number.mag << " and the argument is: " << polar_number.arg << endl;
    cout << "Now give me another complex number, in cartesian coordinates." << endl;
    c_complex number2;
    cin >> number2.re >> number2.im;
    c_complex sum;
    sum.re = number.re + number2.re;
    sum.im = number.im + number2.im;
    p_complex p_sum = polar(sum);
    cout << "The sum of these is: " << sum.re << " + " << sum.im << "i, in polar cordinates " << p_sum.mag << "(e^(" << p_sum.arg << "i))" << endl;
    return 0;
}

p_complex polar(c_complex z){
    double mag = sqrt( pow(z.re, 2) + pow(z.im, 2) );
    double arg = atan2( z.im, z.re );
    p_complex z_p;
    z_p.mag = mag;
    z_p.arg = arg;
    return z_p;
}
