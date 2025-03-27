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

DIC::node::node(): parent(nullptr), left(nullptr), right(nullptr) {}
DIC::node::node(node *_p): parent(_p), left(nullptr), right(nullptr) {}
DIC::node::~node(){
    delete left;
    delete right;
}
void DIC::node::Insert(node* node){
    DIC::node* temp = this;
    int indexKey = 0;
    std::string sKey = node->key;
    while(temp != nullptr){
        if(sKey.at(indexKey) < key.at(indexKey)){
            if(temp->left != nullptr)
                temp = temp->left;
            else{
                temp->left = node;
                temp = nullptr;
            }
        }
        else if(sKey.at(indexKey) > key.at(indexKey)){
            if(temp->right != nullptr)
                temp = temp->right;
            else{
                temp->right = node;
                temp = nullptr;
            }
        }
        else if(sKey.at(indexKey) = key.at(indexKey)){
            ++indexKey;
        }
    }
}
void DIC::node::Right (node* node){
    DIC::node* tempCh = node->right;
    DIC::node* tempCh2 = tempCh->right;

}
void DIC::node::Left (node* node) {}
void DIC::node::LeftRight (node* node) {}
void DIC::node::RightLeft (node* node) {}