#include "Menu.h"
UI::Menu::~Menu(){
    delete [] choices;
    choices = nullptr;
}
void UI::Menu::LOWER(std::string &str){
    for(int i =0; i < str.size(); i++){
        if(str.at(i) < 0x61 && str.at(i) != ' '){
            str.at(i)+= 32;
        }
    }
}
bool UI::Menu::corrLett(std::string str){
    LOWER(str);
    for(int i=0; i<str.size(); i++){
        if((str.at(i) < 0x61 || str.at(i) > 0x7a) && str.at(i) != ' '){
            return false;
        }
    }
    return true;
}

void UI::Menu::Init(const windowSpec &spec){
    iSizeChoices = 4;
    //MAIN MENU
    choices = new std::string[iSizeChoices];
    choices[0] = "Search";
    choices[1] = "Add";
    choices[2] = "Show Tree";
    choices[3] = "EXIT";
    //FIND MENU
    findField = new FIELD*[2];
    findForm = new FORM;
    //ADD MENU
    addField = new FIELD*[3];
    addForm = new FORM;
    //NCURSES
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    //MAIN MENU
    m_item = (ITEM**)calloc(iSizeChoices + 1, sizeof(ITEM*));
    for(int i=0; i<iSizeChoices; i++)
        m_item[i] = new_item(choices[i].c_str(), nullptr);
    m_item[iSizeChoices] = (ITEM*)NULL;
    if(m_item == nullptr){
        endwin();
        throw std::runtime_error("Failed to allocate m_item\n");
    }

    m_menu = new_menu((ITEM**)m_item);
    post_menu(m_menu);
    refresh();
    //FIND MENU
    findField[0] = new_field(1, 20, 4, 18, 0, 0);
    findField[1] = NULL;

    set_field_back(findField[0], A_UNDERLINE);
    field_opts_off(findField[0], O_AUTOSKIP);
    findForm = new_form(findField);
    //ADD MENU
    addField[0] = new_field(1, 20, 4, 18, 0, 0);
    addField[1] = new_field(1, 20, 6, 18, 0, 0);
    addField[2] = NULL;

    set_field_back(addField[0], A_UNDERLINE);
    field_opts_off(addField[0], O_AUTOSKIP);
    set_field_back(addField[1], A_UNDERLINE);
    field_opts_off(addField[1], O_AUTOSKIP);
    addForm = new_form(addField);
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
            case 0x17:
            case '\n':
                switch(temp){
                case 0:
                    unpost_menu(m_menu);
                    FindMenu(c);
                    post_menu(m_menu);
                    break;
                case 1:
                    unpost_menu(m_menu);
                    AddMenu(c);
                    post_menu(m_menu);
                    break;
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
    //MAIN MENU
    unpost_menu(m_menu);
    free_menu(m_menu);

    for(int i=0; i<iSizeChoices; i++){
        free_item(m_item[i]);
    }
    //FIND MENU
    free_form(findForm);
    free_field(findField[0]);
    //ADD MENU
    free_form(addForm);
    free_field(addField[0]);
    free_field(addField[1]);

    endwin();
}

void UI::Menu::FindMenu(int c){
    post_form(findForm);
    refresh();

    mvprintw(4, 10, "Search: ");
    refresh();
    std::string tempText;
    Vector2<int> cursor;
    std::vector<std::string> search;
    while((c = getch()) != KEY_LEFT){
        switch(c){
            case KEY_BACKSPACE:
            case 127:
                if(!tempText.empty()){
                    tempText.pop_back();
                    form_driver(findForm, REQ_DEL_PREV);
                }
                break;
                case '\n':
                getyx(stdscr, cursor.y, cursor.x);
                for(int i=0; i<6; i++){
                    move(6+i, 0);
                    clrtoeol();
                }
                search = dictionary[tempText.c_str()];
                for(int i=0; i<search.size(); i++)
                    mvprintw(6+i, 10, search.at(i).c_str());
                if(search.size() == 0)
                    mvprintw(6, 10, "Word didn't found");
                move(cursor.y, cursor.x);
                refresh();
            break;
            default:
                if(tempText.size()<20){
                    tempText += c;
                    form_driver(findForm, c);
                }
            break;
        }
    }
    unpost_form(findForm);
}

void UI::Menu::AddMenu(int c){
    post_form(addForm);
    refresh();

    mvprintw(4, 10, "Polish: ");
    mvprintw(6, 8, "Japanese: ");
    refresh();
    int index = 0;
    std::string str[2];
    move(4, 18);
    while((c = getch()) != KEY_LEFT){
        switch(c){
            case KEY_UP:
                index != 0?index--:index;
                form_driver(addForm, REQ_NEXT_FIELD);
                form_driver(addForm, REQ_END_LINE);
                break;
                case KEY_DOWN:
                index != 1?index++:index;
                form_driver(addForm, REQ_PREV_FIELD);
                form_driver(addForm, REQ_END_LINE);
            break;
            case KEY_BACKSPACE:
            case 127:
                if(!str[index].empty()){
                    str[index].pop_back();
                    form_driver(addForm, REQ_DEL_PREV);
                }
            break;
            case '\n':
                if(!str[0].empty() && !str[1].empty() && (corrLett(str[0]) && corrLett(str[1]))){
                    form_driver(addForm, REQ_DEL_LINE);
                    form_driver(addForm, REQ_NEXT_FIELD);
                    form_driver(addForm, REQ_DEL_LINE);
                    form_driver(addForm, REQ_NEXT_FIELD);
                    LOWER(str[0]);
                    LOWER(str[1]);
                    dictionary.AddWord(str[0], str[1]);
                }
                break;
                default:
                if(str[index].size() < 18){
                    str[index] += c;
                    form_driver(addForm, c);
                }
                break;
            }
        }
        form_driver(addForm, REQ_DEL_LINE);
        form_driver(addForm, REQ_NEXT_FIELD);
        form_driver(addForm, REQ_DEL_LINE);
        form_driver(addForm, REQ_NEXT_FIELD);
        unpost_form(addForm);
}