#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

namespace DIC{
    class node{
    public:
        node();
        ~node();
    private:
        int key;
        std::vector<std::string> words;
        int weight;
        int* parent;
        int* left;
        int* right;
    };

    class Dictionary{
    public:
        Dictionary();
        ~Dictionary();
        std::vector<std::string> operator[] (const std::string &val);
    private:
        node* root;
    };
}