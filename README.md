# Dictionary
This project involves a terminal-based application for UNIX-based operating systems. It is using ncurses libraryto create a simple text-based user interface exploit the FORM or MENU to 
functionality (from menu.h and form.h)</br>
For data managment, the project implement an AVL tree as the primary structur to store and manage a dictionary efficiently.
## Technology
### AVL Tree
I'm using AVL Tree to contain all words from database (actualy .txt files). That's because of fast searching and O(logN) computational complexity of that algorithm. Each node 
contains:
* one parent pointer,
* two child pointers (left and right),
* weigth (contains {-1, 0, 1} values),
* key - string contains polish word
* words - a vector of strings (each word can has a few meanings).
</br></br>The tree has a find method - to find one or more searching words, and Insert method, which allow you to add new words to tree and database(.txt files). If insert will find the
word which you want to add, will add to vector if isn't already contain that meaning.
### Ncurses library
## Instalation
To open dictionary, you will need a ncurses library:
```bash
(MacOS)
brew install ncurses
(Linux)
sudo apt-get install libncurses5-dev libncursesw5-dev
```
Then, clone repository and navigate to directory:
```bash
git clone https://github.com/GaThsaPer/Dictionary
cd Dictionary
```
You can run program by double-click on file Dictionary, or type command: 
```bash
./Dictionary
```
If it won't run, try to compile project in terminal by command and then run the project:
```bash
g++ -std=c++20 -o Dictionary ./*.cpp -lncurses -lmenu -lform
```
If you don't have g++ compiler you need to instal it:
```bash
(macos)
brew install gcc
(linux)
sudo apt install gcc
```
Project tested on MacBook Pro 2016
