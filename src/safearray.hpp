////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief     Safearray class methods definition
/// \author    Sergey Shershakov
/// \version   0.2.0
/// \date      30.01.2017
///            This is a part of the course "Algorithms and Data Structures" 
///            provided by  the School of Software Engineering of the Faculty 
///            of Computer Science at the Higher School of Economics.
///
/// This file contains templates of the method of the class Safearray.
/// This file is not going to be used w/o its main counterpart, safearray.h.
/// Since the file is used only through safearray.h, which has its own "include 
/// watcher", we add no addition "watcher" here.
///
////////////////////////////////////////////////////////////////////////////////

// #ifndef    // No need to have a watcher here!


// we have to indicate that methods of the class Safearray are also inside the namespace xi
#include "safearray.h"

namespace xi {


template <typename T>
SafeArray<T>::SafeArray(size_t cap): _capacity(cap)
{
    _storage = new T[cap];
}
template <typename T>
SafeArray<T>::~SafeArray()
{
    delete[] _storage;
    _capacity = 0;
}

template <typename T>
SafeArray<T>::SafeArray(const SafeArray &safeArray): SafeArray<T>::SafeArray(safeArray._capacity)
{
    for(int i = 0; i < _capacity; i++)
        _storage[i] = safeArray._storage[i];
}

template <typename T>
T& SafeArray<T>::operator[] (size_t k)
{
    if(k >= _capacity)
        throw std::out_of_range("invalid index");
    return _storage[k];
}

template <typename T>
const T& SafeArray<T>::operator[] (size_t k) const
{
    if(k >= _capacity)
        throw std::out_of_range("invalid index");
    return _storage[k];
}

template <typename T>
typename SafeArray<T>::SafeArray& SafeArray<T>::operator= (const SafeArray& right)
{
    if (this == &right) {
        return *this;
    }
    _capacity = right._capacity;
    delete[] _storage;
    _storage = new T[_capacity];
    for(int i = 0; i < _capacity; i++)
        _storage[i] = right._storage[i];
    return *this;
}

template<typename T>
size_t SafeArray<T>::getCapacity() const
{
    return _capacity;
}


} // namespace xi
