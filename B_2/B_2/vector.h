#pragma once

#include <algorithm>
#include <cstring>
#include <iostream>

template <typename T>
class MyVector {
private:
    T* _arr = nullptr;
    size_t _size = 0;
    size_t _capacity = 0;

public:
    MyVector() = default;

    explicit MyVector(size_t size) {
        resize(size);
    }

    MyVector(T* data, size_t size) {
        resize(size);
        memcpy(this->_arr, data, sizeof(T) * size);
    }

    MyVector(const MyVector& vec) {
        resize(vec.size());
        memcpy(_arr, vec._arr, sizeof(T)* size());
    }

    ~MyVector() {
        resize(0);
    }

    MyVector<T>& operator = (const MyVector& vec) {
        if (this != &vec) {
            resize(vec.size());
            if(std::is_trivially_copyable<T>()) {
                memcpy(_arr, vec._arr, sizeof(T) * vec.size());
            }
            else {
                for (size_t i = 0; i < size(); i++) {
                    _arr[i] = vec[i];
                }
            }
        }
        return *this;
    }

    [[nodiscard]] size_t capacity() const {
        return this->_capacity;
    }

    [[nodiscard]] size_t size() const {
        return this->_size;
    }

    void reserve(const size_t capacity) {
        T* array_new = nullptr;

        if(capacity > 0) {
            array_new = new T[capacity]{};
            if (_arr) {
                auto count = std::min<size_t>(capacity, _size);
                if(std::is_trivially_copyable<T>()) {
                    memcpy(array_new, _arr, sizeof(T) * count);
                }
                else {
                    for (size_t i = 0; i < count; i++) {
                        array_new[i] = _arr[i];
                    }
                }
            }
        }

        delete[] this->_arr;
        this->_arr = array_new;

        this->_capacity = capacity;
    }

    void resize(const size_t size) {
        if(size >= capacity()) {
            reserve(size*2);
        }
        _size = size;
    }

    void fill_rand(size_t count, T min = 0, T max = 100) {
        resize(count);
        for (size_t i = 0; i < size(); i++) {
            _arr[i] = (rand() % (max - min + 1)) + min;
        }
    }

    void push_back(const T& el) {
        resize(size() + 1);
        _arr[_size-1] = el;
    }

    void clear() {
        this->_size = 0U;
    }

    friend std::ostream& operator<< (std::ostream& str, const MyVector& v) {
        for (int i = 0; i < v->size; i++) {
            str << v[i] << " ";
        }
        return str;
    }

    const T& operator[] (size_t idx) const {
        if(idx >= size()){
            throw std::invalid_argument("index out of bounds");
        }

        return this->_arr[idx];
    }

    T& operator[] (size_t idx) {
        if(idx >= size()){
            throw std::invalid_argument("index out of bounds");
        }

        return this->_arr[idx];
    }
};