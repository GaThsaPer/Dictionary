#include "AVL.h"
//Dictionary constructor and destructor
DIC::Dictionary::Dictionary(){
    std::fstream filePL;
    std::fstream fileJP;
    filePL.open("polish.txt", std::ios::in);
    fileJP.open("japanese.txt", std::ios::in);

    std::string polish, japanese;
    std::getline(filePL, polish);
    std::getline(fileJP, japanese);
    std::vector<std::string> jp;
    jp.push_back(japanese);
    root = new node(nullptr, polish, jp);
    while(std::getline(filePL, polish) && std::getline(fileJP, japanese)){
        jp.at(0) = japanese;
        root->Insert(&root, new node(nullptr, polish, jp));
    }
    filePL.close();
    fileJP.close();
}
DIC::Dictionary::~Dictionary(){
    delete root;
}
//Add new words to dictionary
void DIC::Dictionary::AddWord(std::string sKey, std::string mean){
    std::fstream filePL;
    std::fstream fileJP;

    filePL.open("polish.txt", std::ios::app);
    fileJP.open("japanese.txt", std::ios::app);

    filePL << '\n' << sKey;
    fileJP << '\n' << mean;
    std::vector<std::string> tempVec;
    tempVec.push_back(mean);
    root->Insert(&root, new DIC::node(nullptr, sKey, tempVec));

    fileJP.close();
    filePL.close();
}

//Constructors and Destructors for Tree
DIC::node::node(): parent(nullptr), left(nullptr), right(nullptr) {}
DIC::node::node(node *_p): parent(_p), left(nullptr), right(nullptr) {}
DIC::node::node(node* n, std::string s, std::vector<std::string> v): 
    parent(n), left(nullptr), right(nullptr), key(s), words(v) {}
DIC::node::~node(){
    delete left;
    delete right;
}
//Insert function
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
                // std::cout << "TEST\n";
            break;
        }
        else if(temp->weight == 2){
            if(temp->left->key > node->key)
                Left(root, temp);
            else
                LeftRight(root, temp);
        }
        if(temp->weight == 0){
            break;
        }
        
    } while (temp->parent != nullptr);
    
}
//Rotations for tree
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
    DIC::node* child = node->right;
    DIC::node* grandChild = child->left;
    
    node->right = grandChild->left;
    child->left = grandChild->right;
    
    if(node->right != nullptr)
        node->right->parent = node;
    if(child->left != nullptr)
        child->left->parent = child; 

    grandChild->left = node;
    grandChild->right = child;

    grandChild->parent = node->parent;
    child->parent = grandChild;
    node->parent = grandChild;

    if(grandChild->parent == nullptr)
        *root = grandChild;
    else
        grandChild->parent->key > grandChild->key? grandChild->parent->left = grandChild: grandChild->parent->right = grandChild;
    
    node->weight += 2;
    child->weight--;
    grandChild->weight = 0;
}
void DIC::node::LeftRight (node** root, node* node) {
    DIC::node* child = node->left;
    DIC::node* grandChild = child->right;

    node->left = grandChild->right;
    child->right = grandChild->left;

    if(node->left != nullptr)
        node->left->parent = node;
    if(child->right != nullptr)
        child->right->parent = child;

    grandChild->left = child;
    grandChild->right = node;

    grandChild->parent = node->parent;
    child->parent = grandChild;
    node->parent = grandChild;

    if(grandChild->parent == nullptr)
        *root = grandChild;
    else
        grandChild->parent->key > grandChild->key? grandChild->parent->left = grandChild: grandChild->parent->right = grandChild;

    child->weight++;
    node->weight -= 2;
    grandChild->weight = 0;
}
// Searching tree
std::vector<std::string> DIC::node::Find(std::string sKey){
    DIC::node* temp = this;
    while(temp != nullptr){
        if(temp->key == sKey)
            return temp->words;
        else if(temp->key > sKey)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return {};
}
DIC::node* DIC::node::FindNode(std::string sKey){
    DIC::node* temp = this;
    while(temp != nullptr){
        if(temp->key == sKey)
            return temp;
        else if(temp->key > sKey)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return nullptr;
} 
//Operator<< for node
namespace DIC{
    std::ostream& operator<<(std::ostream& os, node* node){
        if(node == nullptr){
            os << "Word isn't in dictionary\n";
        }
        else{
            for(int i=0; i<node->GetVal().size(); i++){
                os << node->GetKey() << " - " << node->GetVal().at(i);
                if(i != node->GetKey().size())
                    os << '\n';
            }
        }
        return os;
    }
}
//Printing Tree
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