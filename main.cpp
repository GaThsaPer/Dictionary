#include "AVL.h"
#include "Menu.h"

int main(){
    DIC::Dictionary dictionary;
    // dictionary.ShowTree();
    dictionary.AddWord("mama", "okaasan");
    std::cout << dictionary["mama"];
    return 0;
}