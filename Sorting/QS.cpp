//
// Created by gmspr on 10/11/2022.
//

#include "QS.h"
#include "string"
#include "iostream"
#include "sstream"


using namespace std;

QS::QS(){
    array = NULL;
    arraySize = 0;
    currentPosition = 0;
}

QS::~QS(){
    clear();
}

void QS::sortAll() {
    if(arraySize >= 3){
        sort(0, currentPosition -1);
        return;
    }
    else{
        return;
    }
}

void QS::swap(int left, int right) {
    int temp = array[left];
    array[left] = array[right];
    array[right] = temp;
}

void QS::sort(int left, int right) {
    if (left < right) {
        if (right - left < 2) {
            if (array[left] > array[right])
                swap(left, right);
        } else if (right - left == 2) {
            medianOfThree(left, right);
        } else if (right - left > 2) {
            int pivot = medianOfThree(left, right);
            pivot = partition(left, right, pivot);
            sort(left, pivot - 1);
            sort(pivot + 1, right);
        }
    }
}

int QS::medianOfThree(int left, int right){
    int middle = (right + left)/2;

    if(left >= right){
        return -1;
    }

    if(currentPosition == 0 || left < 0 || right > currentPosition){
        return -1;
    }

    if(array[left] < array[middle] && array[middle] < array[right]){
        return middle;
    }

    if(array[left] >= array[right]){
        int temp = array[left];
        array[left] = array[right];
        array[right] = temp;
    }

    if(array[left] >= array[middle]){
        int temp = array[left];
        array[left] = array[middle];
        array[middle] = temp;
    }
    if(array[right] <= array[middle]){
        int temp = array[right];
        array[right] = array[middle];
        array[middle] = temp;
    }

    return middle;
}

int QS::partition(int left, int right, int pivotIndex){
    int temp = array[left];
    array[left] = array[pivotIndex];
    array[pivotIndex] = temp;

    int up = left + 1;
    int down = right;

    if (array == NULL) {
        return -1;
    }
    if (pivotIndex < left || pivotIndex > right) {
        return -1;
    }
    if (left < 0 || right > arraySize - 1 || left >= right) {
        return -1;
    }
    if(currentPosition == 0){
        return -1;
    }

    do {
        while ((up != right) && !(array[left] < array[up])) {
            up++;
        }

        while (array[left] < array[down]) {
            down--;
        }

        if(up < down){
            int temp1 = array[down];
            array[down] = array[up];
            array[up] = temp1;
        }
    }
    while(up < down);

    int temp3 = array[left];
    array[left] = array[down];
    array[down] = temp3;

    return down;

}

string QS::getArray() const{
    if(arraySize == 0){
        cout << "array size is 0" << endl;
        return "";
    }

    if(currentPosition == 0){
        return "";
    }

    else{
        stringstream ss;
        for(int i = 0; i < currentPosition; i++){
            ss << array[i];
            if(i < currentPosition - 1){
                ss << ",";
            }
        }
        return ss.str();
    }
}

int QS::getSize() const{
    return currentPosition;
}

bool QS::addToArray(int value){
    if (currentPosition == arraySize){
        return false;
    }
    else{
        array [currentPosition] = value;
        currentPosition++;
        return true;
    }

}

bool QS::createArray(int capacity){
    if(capacity < 0){
        return false;
    }

    else{
        clear();
        array = new int[capacity];
        arraySize = capacity;
        return true;
    }


}

void QS::clear(){
    delete[] array;
    currentPosition = 0;
    arraySize = 0;
}
