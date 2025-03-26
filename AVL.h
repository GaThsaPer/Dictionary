#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

namespace DIC{
    class avl{
    public:
        avl();
        ~avl();
    private:
        int key;
        std::vector<std::string> words;
        int* left;
        int* right;
    };

    class Dictionary{
    public:
        Dictionary();
        ~Dictionary();
    private:
        avl* root;
    };
}