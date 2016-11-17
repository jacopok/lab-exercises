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

int main(){
    default_random_engine generator;
    cout << "How many random numbers do you want? " << endl;
    int number;
    cin >> number;
    cout << "What should be the average? " << endl;
    double average;
    cin >> average;
    cout << "What should be the standard deviation? " << endl;
    double deviation;
    cin >> deviation;
//  cout << "Which file do you want these written to?" << endl;
    string filename;
//    cin >> filename;
    filename = "output.txt";
    ofstream outputfile(filename);
    if (!outputfile){
        cout << "Error in opening the file"<< endl;
        return -1;
    }
    normal_distribution<double> norm(average, deviation);
    for (int i = 0; i<number; i++){
        outputfile << norm(generator) << endl;
    }
    return 0;
}

