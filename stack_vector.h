#pragma once

#include <array>
#include <stdexcept>

template <typename T, size_t N>
class StackVector {
public:
    explicit StackVector(size_t a_size = 0):size(a_size)
    {
        if (a_size > N)
            throw std::invalid_argument("Error: invalid argument");
    }

    T& operator[](size_t index)
    {
        return _vect[index-1];
    }
    const T& operator[](size_t index) const
    {
        return _vect[index-1];
    }

    T* begin() {
        //return _vect.data();//эта функция возвращает указатель на первый элемент объекта массива.
        return _vect.begin();
    }
    T* end()
    {
        //return &_vect[size];
        return begin() + size;
    }
    auto begin() const 
    {
        return _vect.begin();
    }
    auto end() const 
    {
        //return &_vect[size];
        return begin() + size;
    }

    size_t Size() const
    {
        return size;
    }
    size_t Capacity() const
    {
        return N;
    }

    void PushBack(const T& value)
    {
        if (size >= N)
            throw std::overflow_error("ERROR: overflow error");

        _vect[size] = value;
        ++size;
        
    }
    T PopBack()
    {
        if (size==0)
            throw std::underflow_error("ERROR: underflow error");

        T temp = _vect[size-1];
        _vect[size-1] = 0;
        --size;
        return temp;
    }

private:
    std::array<T, N> _vect;
    size_t size = 0;
};
