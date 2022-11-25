//
// Created by armon on 4/30/2020.
//
#include <iostream>
#include "Data.h"
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <ctime>
#include <chrono>


using namespace std;
using namespace std::chrono;

template <class T>
void bubbleSort(vector<T> &s);

template <class T>
void selectionSort(vector<T> &s);

template <class T>
void mergeSort(vector<T> &s);

template <class T>
void merge(vector<T>&left, vector<T>& right, vector<T>&s);


int main() { //code borrowed from project 7

    srand(time(NULL));
    ifstream in;
    ofstream out;
    string line;
    string filename;
    int counter = 1;
    int entries;
    cout << "Enter a filename (../Bikeshare.csv): ";
    cin >> filename;
    cout << endl;
    cout << "Number of entries: ";
    cin >> entries;
    cout << endl;

    in.open(filename);
    if (!in.good()) {
        cout << "Unable to open file: " << filename << endl;
        return -1;
    }
    cout << "Reading " << filename << "..." << endl;
    cout << endl;
    cout << "Before sorts:" << endl;

    vector<Data> dataV;
    while (counter <= entries) {
        getline(in, line);
        string substring;
        getline(in, substring, ',');//id
        int tmp1;
        istringstream(substring) >> tmp1;
        int id = tmp1;
        getline(in, substring, ',');//start
        string start = substring;
        getline(in, substring, ',');//stop
        int tmp2;
        istringstream(substring) >> tmp2;
        int stop = tmp2;
        getline(in, substring, ',');//trip
        int tmp3;
        istringstream(substring) >> tmp3;
        int trip = tmp3;

        Data DataObj(id, start, stop, trip);
        cout << DataObj;
        dataV.push_back(DataObj);
        counter++;
    }
    in.close();

    cout << endl;

//3 copies of dataV
    vector<Data> dataV_B;
    vector<Data> dataV_S;
    vector<Data> dataV_M;
    dataV_B = dataV;
    dataV_S = dataV;
    dataV_M = dataV;

//vector of rand integers
    vector<int> intV;
    for (int i = 0; i<= entries; ++i){
        intV.push_back((rand() % 100000 + 1));
        cout << intV.at(i);
        cout << endl;
    }
    cout << endl;

//first round of sorts

cout << "After Sorts Set 1: " << endl;

auto start = high_resolution_clock::now();
bubbleSort(dataV_B);
    for (int i = 0; i < dataV_B.size(); ++i){
        cout << dataV_B.at(i);
    }
auto stop = high_resolution_clock::now();
auto duration = duration_cast<microseconds>(stop - start);
cout << "(Bubble sort took " << duration.count() << " microseconds)" << endl;
    cout << endl;

    start = high_resolution_clock::now();
bubbleSort(intV);
    for (int i = 0; i < intV.size(); ++i){
        cout << intV.at(i);
        cout << endl;
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "(Bubble sort took " << duration.count() << " microseconds)" << endl;
    cout << endl;

    start = high_resolution_clock::now();
selectionSort(dataV_S);
    for (int i = 0; i < dataV_S.size(); ++i){
        cout << dataV_S.at(i);
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "(Selection sort took " << duration.count() << " microseconds)" << endl;
    cout << endl;

    start = high_resolution_clock::now();
selectionSort(intV);
    for (int i = 0; i < intV.size(); ++i){
        cout << intV.at(i);
        cout << endl;
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "(Selection sort took " << duration.count() << " microseconds)" << endl;
    cout << endl;

    start = high_resolution_clock::now();
mergeSort(dataV_M);
    for (int i = 0; i < dataV_M.size(); ++i){
        cout << dataV_M.at(i);
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "(Merge sort took " << duration.count() << " microseconds)" << endl;
    cout << endl;

    start = high_resolution_clock::now();
mergeSort(intV);
    for (int i = 0; i < intV.size(); ++i){
        cout << intV.at(i);
        cout << endl;
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "(Merge sort took " << duration.count() << " microseconds)" << endl;
    cout << endl;



//second round of sorts
    cout << "After Sorts Set 2: " << endl;
    start = high_resolution_clock::now();
    bubbleSort(dataV_B);
    for (int i = 0; i < dataV_B.size(); ++i){
        cout << dataV_B.at(i);
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "(Bubble sort took " << duration.count() << " microseconds)" << endl;
    cout << endl;

    start = high_resolution_clock::now();
    bubbleSort(intV);
    for (int i = 0; i < intV.size(); ++i){
        cout << intV.at(i);
        cout << endl;
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "(Bubble sort took " << duration.count() << " microseconds)" << endl;
    cout << endl;

    start = high_resolution_clock::now();
    selectionSort(dataV_S);
    for (int i = 0; i < dataV_S.size(); ++i){
        cout << dataV_S.at(i);
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "(Selection sort took " << duration.count() << " microseconds)" << endl;
    cout << endl;

    start = high_resolution_clock::now();
    selectionSort(intV);
    for (int i = 0; i < intV.size(); ++i){
        cout << intV.at(i);
        cout << endl;
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "(Selection sort took " << duration.count() << " microseconds)" << endl;
    cout << endl;

    start = high_resolution_clock::now();
    mergeSort(dataV_M);
    for (int i = 0; i < dataV_M.size(); ++i){
        cout << dataV_M.at(i);
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "(Merge sort took " << duration.count() << " microseconds)" << endl;
    cout << endl;

    start = high_resolution_clock::now();
    mergeSort(intV);
    for (int i = 0; i < intV.size(); ++i){
        cout << intV.at(i);
        cout << endl;
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "(Merge sort took " << duration.count() << " microseconds)" << endl;
    cout << endl;



}

template <class T>
void bubbleSort(vector<T> &s){
    T tmp;
    int pass;
    for (int i = 0; i < s.size(); ++i) {
        pass = 0;
        for (int j = 0; j < s.size() - 1; ++j) {
            if (s.at(j) > s.at(j + 1)) {
                tmp = s.at(j);
                s.at(j) = s.at(j + 1);
                s.at(j + 1) = tmp;
                pass++;
            }
        }
        if (pass == 0) {
            break;
        }
    }
}

template <class T>
void selectionSort(vector<T> &s) {
    for (int i = 0; i < s.size(); ++i) {//code zybooks

        // Find index of smallest remaining element
        int smallest = i;
        for (int j = i + 1; j < s.size(); ++j) {

            if (s[j] < s[smallest]) {
                smallest = j;
            }
        }

        // Swap s[i] and s[smallest]
        T tmp = s[i];
        s[i] = s[smallest];
        s[smallest] = tmp;
    }
}

template <class T>
void mergeSort(vector<T> &s){
    if (s.size() <= 1){
        return;
    }

    int mid = s.size() / 2;
    vector<T> left;
    vector<T> right;

    for (size_t j = 0; j < mid;j++)
        left.push_back(s[j]);
    for (size_t j = 0; j < (s.size()) - mid; j++)
        right.push_back(s[mid + j]);

    mergeSort(left);
    mergeSort(right);
    merge(left, right, s);
}

template <class T>
void merge(vector<T>&left, vector<T>& right, vector<T>& s){
    int leftSize = left.size();
    int rightSize = right.size();
    int i = 0, j = 0, k = 0;

    while (j < leftSize && k < rightSize)
    {
        if (left[j] < right[k]) {
            s[i] = left[j];
            j++;
        }
        else {
            s[i] = right[k];
            k++;
        }
        i++;
    }
    while (j < leftSize) {
        s[i] = left[j];
        j++; i++;
    }
    while (k < rightSize) {
        s[i] = right[k];
        k++; i++;
    }
}