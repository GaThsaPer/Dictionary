#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

namespace DIC{
    class node{
    public:
        node();
        node(node *_p);
        node(node *_p, std::string key, std::vector<std::string> val);
        ~node();
        void Insert(node* node);
    private:
        std::string key;
        std::vector<std::string> words;
        int weight;
        node* parent;
        node* left;
        node* right;
        void Right (node* node);
        void Left (node* node);
        void LeftRight (node* node);
        void RightLeft (node* node);
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