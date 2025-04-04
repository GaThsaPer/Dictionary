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
        void FindMenu(int c);
        void AddMenu(int c);
        void TreeMenu(int c);
        void LOWER(std::string &str);
        bool corrLett(std::string str);
        DIC::Dictionary dictionary;
        //Main menu
        ITEM **m_item;
        MENU *m_menu;
        //Find Method menu
        FIELD **findField;
        FORM *findForm;
        //Add Method menu
        FIELD **addField;
        FORM *addForm;
        //
        WINDOW *m_window;
        int iSizeChoices;
        std::string *choices;
    };

}