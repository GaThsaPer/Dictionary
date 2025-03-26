#include "AVL.h"

DIC::Dictionary::Dictionary(){
    root = new node;
}

DIC::Dictionary::~Dictionary(){
    delete root;
}

std::vector<std::string> DIC::Dictionary::operator[](const std::string &val){
    std::vector<std::string> ret;
    if(val == "kot"){
        ret.push_back("cat");
        return ret;
    }
    ret.push_back("CHu");
    return ret;
}

DIC::node::node() {
    parent = nullptr;
    left = nullptr;
    right = nullptr;
}

DIC::node::~node(){
    delete left;
    delete right;
}