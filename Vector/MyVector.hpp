#pragma once
#include <cstdint>
#include <iostream>

template <class T>
class MyVector{
private:
    T* data;
    size_t size;
    size_t capacity;
public:
    MyVector() = default;
    MyVector(size_t capacity){
        this->data = new T[capacity];
        this->capacity = capacity;
    }
    MyVector(const MyVector<T>& other){
        copyFrom(other);
    }
    MyVector(MyVector<T>&& other){
        moveFrom(std::move(other));
    }
    MyVector<T>& operator=(const MyVector<T>& other){
        if(this != &other){
            free();
            copyFrom(other);
        }
        return *this;
    }
    MyVector<T>&operator=(MyVector<T>&& other){
        if(this != &other){
            free();
            moveFrom(std::move(other));
        }
    }

    void pushBack(const T& element){
        this->data[this->size] = element;
        this->size++;
    }

    void popBack(){
        this->size--;
    }

    void insert(size_t index, const T& element){
        if(index > this->capacity)
            throw std::exception();
        else if(this->capacity == this->size)
            throw std::exception();

        this->data[index] = element;
    }

    void remove(size_t index){
        if(index >= this->size)
            throw std::exception();

        for(size_t i = index; i < this->size - 1; i++)
            this->data[i] = this->data[i+1];

        this->size--;
    }

    size_t count() const{
        return this->size;
    }

    bool isEmpty() const{
        return this->size == 0;
    }

    T& back(){
        return this->data[this->size - 1];
    }

    T& operator[](size_t index){
        return this->data[index];
    }

    T& operator[](size_t index) const{
        return this->data[index];
    }

    void clear(){
        this->size = 0;
        delete[] this->data;
    }
private:
    void resize(){
        T* temp = new T[this->capacity * 2];

        for(size_t i = 0; i < this->size; i++)
            temp[i] = this->data[i];

        delete[] this->data;
        
        this->data = temp;
        this->capacity *= 2;
    }
    void copyFrom(const MyVector<T>& other){
        this->data = new T[other.capacity];

        for(size_t i = 0; i < other.size; i++)
            this->data[i] = other.data[i];

        this->size = other.size;
        this->capacity = other.capacity;
    }
    void moveFrom(MyVector<T>&& other){
        this->data = other.data;
        this->size = other.size;
        this->capacity = other.capacity;

        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }
    void free(){
        delete[] this->data;
        this->data = nullptr;
        this->size = 0;
        this->capacity = 0;
    }
};