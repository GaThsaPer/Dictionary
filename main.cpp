#include "AVL.h"
#include "Menu.h"

int main(){
    std::vector<std::string> temp;
    temp.push_back("cat");
    DIC::node* root = new DIC::node(nullptr, "kot", temp);

    temp.at(0) = "armagedon";
    root->Insert(&root, new DIC::node(nullptr, "armagedon", temp));
    
    temp.at(0) = "bird";
    root->Insert(&root, new DIC::node(nullptr, "ptak", temp));
    
    temp.at(0) = "ara";
    root->Insert(&root, new DIC::node(nullptr, "ara", temp));

    temp.at(0) = "grandmother";
    root->Insert(&root, new DIC::node(nullptr, "babcia", temp));

    temp.at(0) = "dog";
    root->Insert(&root, new DIC::node(nullptr, "pies", temp));
    
    temp.at(0) = "dad";
    root->Insert(&root, new DIC::node(nullptr, "tata", temp));
    
    temp.at(0) = "azyl";
    root->Insert(&root, new DIC::node(nullptr, "azyl", temp));
    
    temp.at(0) = "dolphin";
    root->Insert(&root, new DIC::node(nullptr, "delfin", temp));
    
    temp.at(0) = "tak";
    root->Insert(&root, new DIC::node(nullptr, "abecadlo", temp));
    
    temp.at(0) = "dinosaur";
    root->Insert(&root, new DIC::node(nullptr, "dinozaur", temp));
    
    temp.at(0) = "mum";
    root->Insert(&root, new DIC::node(nullptr, "mama", temp));
    
    temp.at(0) = "tomato";
    root->Insert(&root, new DIC::node(nullptr, "pomidor", temp));
    
    temp.at(0) = "toy";
    root->Insert(&root, new DIC::node(nullptr, "zabawka", temp));
    
    temp.at(0) = "cucamber";
    root->Insert(&root, new DIC::node(nullptr, "ogorek", temp));
    
    
    temp.at(0) = "father";
    root->Insert(&root, new DIC::node(nullptr, "tata", temp));
    
    temp.at(0) = "castle";
    root->Insert(&root, new DIC::node(nullptr, "zamek", temp));
    
    temp.at(0) = "zupe";
    root->Insert(&root, new DIC::node(nullptr, "zupa", temp));
    
    root->printBT();
    return 0;
}