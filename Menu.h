#pragma once
#include "AVL.h"
#include "Vector.h"
#include <ncurses.h>
#include <menu.h>
#include <form.h>

namespace UI{
    struct windowSpec{
        Vector2<int> screenSize;
    };

    class Menu{
    public:
        Menu() = default;
        ~Menu();
        void Init(const windowSpec &spec);
        void Run();
        void ShutDown();
    private:
        DIC::Dictionary dictionary;
        ITEM **m_item;
        MENU *m_menu;
        WINDOW *m_window;
        int iSizeChoices;
        std::string *choices;
    };

}