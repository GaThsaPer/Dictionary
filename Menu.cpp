#include "Menu.h"
UI::Menu::~Menu(){
}

void UI::Menu::Init(const windowSpec &spec){
    dictionary = DIC::Dictionary();
    iSizeChoices = 4;
    choices = new std::string[iSizeChoices];
    choices[0] = "Search";
    choices[1] = "Add";
    choices[2] = "Show Tree";
    choices[3] = "EXIT";

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    m_item = (ITEM**)calloc(iSizeChoices + 1, sizeof(ITEM*));
    for(int i=0; i<iSizeChoices; i++)
        m_item[i] = new_item(choices[i].c_str(), nullptr);
    m_item[iSizeChoices] = (ITEM*)NULL;

    m_menu = new_menu((ITEM**)m_item);
    post_menu(m_menu);
    refresh();
}

void UI::Menu::Run(){
    int c;
    int temp = 0;
    bool endFlag = true;
    while(endFlag){
        c = getch();
        switch (c){
            case KEY_DOWN:
                temp != 3? temp++: temp;
                menu_driver(m_menu, REQ_DOWN_ITEM);
                break;
            case KEY_UP:
                temp != 0?temp--: temp;
                menu_driver(m_menu, REQ_UP_ITEM);    
                break;
            case '\n':
                switch(temp){
                case 0:
                case 1:
                case 2:
                break;
                case 3:
                    endFlag = false;
                    break;       
                }
                break;
        }
    }
}

void UI::Menu::ShutDown(){
    for(int i=0; i<iSizeChoices; i++)
        free_item(m_item[i]);
    free_menu(m_menu);
    endwin();
}