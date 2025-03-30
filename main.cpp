#include "AVL.h"
#include "Menu.h"

int main(){
    const UI::windowSpec spec{
        .screenSize = {10, 40}
    };

    UI::Menu menu = UI::Menu();
    menu.Init(spec);
    menu.Run();
    menu.ShutDown();

    return 0;
}