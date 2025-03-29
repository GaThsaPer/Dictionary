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
        void Insert(node** root, node* node);
        std::vector<std::string> GetVal() {return words;}
        void printBT();
    private:
        void printBT(const std::string& prefix, const DIC::node* node, bool isLeft);
        std::string key;
        std::vector<std::string> words;
        int weight;
        node* parent;
        node* left;
        node* right;
        void Back(node** root, node* node);
        void Right (node** root, node*& node);
        void Left (node** root, node* node);
        void LeftRight (node**root, node* node);
        void RightLeft (node** root, node* node);
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