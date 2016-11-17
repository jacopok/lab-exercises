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
#include <vector>
#include <random>
#include <fstream>

using namespace std;

double average(double data[], int index1, int index2);
double stdev(double data[], int index1, int index2);

int main(){
    cout << "What file do you want me to read from?" << endl;
    string filename;
    cin >> filename;
    ifstream inputfile(filename);
    double number;
    double *data = new double[number];
    *it1 = data.begin();
    while(inputfile >> number){
        *it1 = number;
        it1++;
    }
    cout << average(data, it1, data.end()) << endl;
    cout << stdev(data, it1, data.end()) << endl;
}

double average(double data[], int index1, int index2){
    int size = index2 - index1;
    double sum = 0;
    for(int i = 0; i < size; i++){
        sum += data[i];
    }
    double average = sum/size; 
    return average;
}

double stdev(double data[], int index1, int index2){
    int size = index2 - index1;
    double differences = 0;
    double av = average (data, index1, index2);
    for(int i = 0; i < size; i++){
        differences += pow((data[i] - av), 2);
    }
    double stdev = sqrt(  differences / (size - 1));
    return stdev;
}
