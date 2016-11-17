/*
 * Exercise6.cxx
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
#include <vector>
using namespace std;

void calculate_integral(int intervals, double a, double b);
double function(double x);

int main(){
    double a, b;
    int intervals;
    cout << "Give me the starting and ending points of your interval: ";
    cin >> a >> b;
    cout << "How many intervals do you want? ";
    cin >> intervals;
    calculate_integral(intervals, a, b);
    return 0;
}

void calculate_integral(int intervals, double a, double b){
    vector<double> sums_inf (intervals, 0);
    vector<double> sums_sup (intervals, 0);
    int index = 0;
    double delta = (b-a)/intervals;
    for(double x=a; x<b; x += delta){
        sums_inf[index] = function(x) * delta;
        cout << "s" << index << " = " << sums_inf[index] << endl;
        sums_sup[index] = function(x + delta) * delta;
        cout << "S" << index << " = " << sums_sup[index] << endl;
        ++index; // calculates the area of the rectangles
        // this is not a proper Riemann integral since it does not look at the maximum of the function
    }
    double integral_value_inf; 
    double integral_value_sup;
    for(int i = 0; i<intervals; ++i){
        integral_value_inf += sums_inf[i];
        integral_value_sup += sums_sup[i]; // adds up all the contributions
    }
    cout << "The estimates of the integral of f(x) between " << a << " and " << b << " are: " << integral_value_inf << " and " << integral_value_sup << endl;
}

double function(double x){
    return sin(x);
}
