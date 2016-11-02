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

int calcola_fib(int k);

int main(){
    cout << "Which Fibonacci number do you want to calculate?";
    int number;
    cin >> number;
    cout << "The " << number << "th Fibonacci number is: " << calcola_fib(number) << endl;
    double ratio = (double) calcola_fib(number) / calcola_fib(number - 1);
    cout << "The ratio with its predecessor is: " << ratio << endl;
    return 0;
}

int calcola_fib(int k){
    long int number[k+1];
    number[0] = 1;
    number[1] = 1;
    for(int i = 2; i<=k; i++){
        number[i] = number[i-1] + number[i-2];
    }
    return number[k];
}
