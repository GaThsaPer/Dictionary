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
DIC::node::node(node* n, std::string s, std::vector<std::string> v): 
    parent(n), left(nullptr), right(nullptr), key(s), words(v) {}
DIC::node::~node(){
    delete left;
    delete right;
}
void DIC::node::Insert(node** root, node* node){
    DIC::node* temp = this;
    int indexKey = 0;
    std::string sKey = node->key;
    while(temp != nullptr){
        if(sKey == temp->key){
            temp->words.push_back(node->GetVal().at(0));
            temp = nullptr;
            delete node;
            node = nullptr;
        }
        else if(sKey < temp->key){
            if(temp->left != nullptr)
                temp = temp->left;
            else{
                temp->left = node;
                node->parent = temp;
                temp = nullptr;
            }
        }
        else if(sKey > temp->key){
            if(temp->right != nullptr)
                temp = temp->right;
            else{
                temp->right = node;
                node->parent = temp;
                temp = nullptr;
            }
        }
    }
    if(node != nullptr){
        Back(root, node);
    }
}
void DIC::node::Back(node** root, node* node){
    DIC::node *temp = node;
    do {
        temp = temp->parent;
        temp->key>node->key?temp->weight++:temp->weight--;
        if(temp->weight == -2){
            // std::cout << "DATA\n";
            if(temp->right->key < node->key)
            Right(root, temp);
            else
            RightLeft(root, temp);
            break;
        }
        else if(temp->weight == 2){
            if(temp->left->key > node->key)
                Left(root, temp);
            else
                LeftRight(root, temp);
            // std::cout << "TEST\n";
        }
        if(temp->weight == 0){
            break;
        }
        
    } while (temp->parent != nullptr);
    
}

void DIC::node::Right (node** root, node*& node){
    DIC::node* child = node->right;
    //left and right switch
    node->right = child->left;
    if(child->left != nullptr)
        child->left->parent = node;
    //switch node
    child->left = node;
    //parent switch
    child->parent = node->parent;
    node->parent = child;
    //chande trace
    if(child->parent != nullptr)
        child->parent->key > child->key?child->parent->left = child:child->parent->right = child;
    else
        *root = child;
    child->weight++;
    //change weight
    node->weight += 2;
}
void DIC::node::Left (node** root, node* node) {
    DIC::node *child = node->left;
    node->left = child->right;
    if(child->right != nullptr) 
    child->right->parent = node;
    child->right = node;
    child->parent = node->parent;
    node->parent = child;
    if(child->parent != nullptr){
        child->parent->key > child->key?child->parent->left = child:child->parent->right = child;
    }
    else{
        *root = child;
    }
    child->weight--;
    node->weight -= 2;
}
void DIC::node::RightLeft (node** root, node* node) {

}
void DIC::node::LeftRight (node** root, node* node) {}

void DIC::node::printBT(const std::string& prefix, const DIC::node* node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        std::cout << node->key << '(' << node->weight << ')' << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

void DIC::node::printBT()
{
    printBT("", this, false);    
}