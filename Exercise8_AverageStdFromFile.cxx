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

double average(vector<double>& data);
double stdev(vector<double>& data);
void reduce(vector<double> & data, int parts);

int main(){
    cout << "What file do you want to read from?" << endl;
    string filename;
//  cin >> filename;
    filename = "output.txt";
    ifstream inputfile(filename);
    double number;
    vector<double> data;
    while(inputfile >> number){
        data.push_back(number);
    }
    reduce(data, 1);
    reduce(data, 4);
    reduce(data, 20);
}

double average(vector<double>& data){ // calculates the average of a vector
    int size = data.size();
    double sum = 0;
    for(int i = 0; i < size; i++){
        sum += data[i];
    }
    double average = sum/size; 
    return average;
}

double stdev(vector<double>& data){ // calculates the standard deviation
    int size = data.size();
    double differences = 0;
    double av = average (data);
    for(int i = 0; i < size; i++){
        differences += pow((data[i] - av), 2);
    }
    double stdev = sqrt(  differences / (size - 1));
    return stdev;
}

void reduce(vector<double> & data, int parts){
    int totalsize = data.size();
    string s = ""; if (parts > 1) s = "s";
    cout << "Splitting the data into " << parts << " section" << s << endl;
    for(int i = 0; i < parts; i++){
        vector<double> partial; // array containing just the elements in the section we want
        for(int k = (totalsize / parts) * i; k < (totalsize / parts) * (i+1); k++){
            partial.push_back(data[k]);
        }
        cout << "The average of section " << i+1 << " is: " << average(partial) << endl;
        cout << "The standard deviation of section " << i+1 << " is: " << stdev(partial) << endl;
    }
    cout << endl;
}
