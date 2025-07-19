#include <iostream>
#include <stdexcept>

template <typename T>
class Vector{
    int Size;
    int Capacity;
    T* arr;
    public:
    Vector(int Size, const T* arrGiven): Size(Size), Capacity(Size), arr(new T[Size]){
        std::copy(arrGiven, arrGiven + Size, arr);
    }
    Vector(int Size): Size(Size), Capacity(Size), arr(new T [Size]) {}
    Vector(): Size(0), Capacity(0), arr(nullptr){}
    Vector(const Vector& other) : Size(other.Size),Capacity(other.Capacity), arr(new T[other.Size]) {
        std::copy(other.arr, other.arr + other.Size, arr);
    }
    ~Vector() { delete[] arr; }
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] arr;
            Size = other.Size;
            Capacity = other.Capacity;
            arr = new T[Capacity];
            std::copy(other.arr, other.arr + other.Size, arr);
        }
        return *this;
    }
    T& operator[](int index) const {
        if (index >= Size) throw std::out_of_range("Index out of range");
        return arr[index];
    }
    T front(){
        return arr[0];
    }
    T back(){
        return arr[Size - 1];
    }   
    T& at(int index){
        if ((index >= Size) || (index < 0)){
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }
    T& data(){
        return arr;
    }
    bool empty(){
        if (Size == 0){
            return true;
        }
        else{
            return false;
        }
    }
    int size(){
        return Size;
    }
    int capacity(){
        return Capacity;
    }
    void reserve(size_t newCapacity){
        if (newCapacity <= Capacity){
            return;
        }
        else{
            T* new_arr = new T[newCapacity];
            for (int i = 0; i < Size; ++i) {
            new_arr[i] = arr[i];
            }
            delete[] arr;
            arr = new_arr;
            Capacity = newCapacity;
        }
    }
    void shrink_to_fit(){
        if (Size == 0) {
            delete[] arr;
            arr = nullptr;
            Capacity = 0;
            return;
        }
        else if (Size >= Capacity){
            return;
        }
        else{
            T* new_arr = new T[Size];
            for (int i = 0; i < Size; ++i) {
            new_arr[i] = arr[i];
            }
            delete[] arr;
            arr = new_arr;
            Capacity = Size;
        }
    }
    void push_back(T& element){
        if (Size == Capacity) {
            reserve(Capacity == 0 ? 1 : Capacity + 1);
        }
        arr[Size] = element;
        ++Size;
    }
    void pop_back(){
        if (Size == 0) throw std::out_of_range("pop_back() on empty vector");
        arr[Size - 1].~T();
        --Size;
    }
    void clear() {
        delete[] arr;
        arr = nullptr;
        Size = 0;
        Capacity = 0;
    }
    void swap(Vector& other){
        std::swap(Size, other.Size);
        std::swap(Capacity, other.Capacity);
        std::swap(arr, other.arr);
    }
    void insert(int index, const T& element) {
        if (index < 0 || index > Size) return;
        T* newArr = new T[Size + 1];
        for (int i = 0; i < index; ++i) {
            newArr[i] = arr[i];
        }
        newArr[index] = element;
        for (int i = index; i < Size; ++i) {
            newArr[i + 1] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        ++Size;
    }
    void erase(int index){
        if (index < 0 || index >= Size) return;
        T* newArr = new T[Size - 1];
        for (int i = 0; i < index; ++i){
            newArr[i] = arr[i];
        }
        for (int i = index + 1; i < Size; ++i){
            newArr[i - 1] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        --Size;
    }
};

int main(){

}