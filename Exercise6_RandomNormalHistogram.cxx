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
#include <random> // compile with -std=c++11

using namespace std;

void print_histogram(vector<unsigned>& histogram);

int main(){
    default_random_engine generator;
    cout << "How many random grades do you want? " << endl;
    int number;
    cin >> number;
    cout << "What should be the average? " << endl;
    double average;
    cin >> average;
    average -= 18;
    cout << "What should be the standard deviation? " << endl;
    double deviation;
    cin >> deviation;
    normal_distribution<> norm(average, deviation);
    vector<unsigned> histogram (13, 0);
    for(int i = 0; i < number; i++){
        auto index = lround(norm(generator));
        if(index < 13 && index >= 0){
            ++histogram[index];
        }
    }
    print_histogram(histogram);
    return 0;
}

void print_histogram(vector<unsigned>& histogram){
    for(int index = 0; index < 13; index++){
        cout << 18 + index << " ";
        for(int i = histogram[index]; i > 0; i--){
            cout << "*";
        }
        cout << endl;
    }
}

