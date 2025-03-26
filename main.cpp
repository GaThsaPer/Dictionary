#include "AVL.h"
#include "Menu.h"

int main(){
    DIC::Dictionary dictionary;
    std::vector<std::string> v = dictionary["kot"];
    std::cout << v.at(0);
    return 0;
}