#include "AVL.h"

DIC::Dictionary::Dictionary(){

}

DIC::Dictionary::~Dictionary(){
    delete root;
}

DIC::avl::avl() {

}

DIC::avl::~avl(){
    delete left;
    delete right;
}