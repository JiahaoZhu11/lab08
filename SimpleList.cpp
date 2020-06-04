// Created By: Jiahao Zhu
// Created Date: 2020/6/3

#include <bits/stdc++.h>
#include "SimpleList.h"

using namespace std;

template <class T>
SimpleList<T>::SimpleList() {
    numElements = 0;
    elements = new T[CAPACITY];
}

template <class T>
SimpleList<T>::~SimpleList() {
/*    if (is_pointer<T>::value) {
        cout << "yes" << endl; //test
        cout << numElements << endl; //test
        for (int i = 0; i < numElements; i++) {
            delete elements[i];
        }
        delete[] elements;
    }
    else*/ delete[] elements;
}

template <class T>
T SimpleList<T>::at(int index) const throw (InvalidIndexException) {
    if (index > -1 && index < numElements) return elements[index];
    else throw InvalidIndexException();
}

template <class T>
bool SimpleList<T>::empty() const {
    if (numElements == 0) return true;
    else return false;
}

template <class T>
T SimpleList<T>::first() const throw (EmptyListException) {
    if (numElements == 0) throw EmptyListException();
    else return elements[0];
}

template <class T>
T SimpleList<T>::last() const throw (EmptyListException) {
    if (numElements == 0) throw EmptyListException();
    else return elements[numElements - 1];
}

template <class T>
int SimpleList<T>::getNumElements() const {
    return numElements;
}

template <class T>
void SimpleList<T>::insert(T item) throw (FullListException) {
    if (numElements == CAPACITY) throw FullListException();
    else {
        elements[numElements] = item;
        numElements++;
    }
}

template <class T>
void SimpleList<T>::remove(int index) throw (InvalidIndexException, EmptyListException) {
    if (numElements == 0) throw EmptyListException();
    else if (index < numElements) {
        numElements -= 1;
        for (int i = index; i < numElements; i++) {
            elements[i] = elements[i + 1];
        }
    }
    else throw InvalidIndexException();
}
