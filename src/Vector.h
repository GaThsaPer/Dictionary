#pragma once

template<typename T>
class Vector2{
    public:
        Vector2() = default;
        Vector2(T _x, T _y):x(_x), y(_y) {}
        ~Vector2() {}
        T x;
        T y;
    private:
    
};