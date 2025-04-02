# Dictionary
This project involves a terminal-based application for UNIX-based operating systems. It is using ncurses libraryto create a simple text-based user interface exploit the FORM or MENU to 
functionality (from menu.h and form.h)</br>
For data managment, the project implement an AVL tree as the primary structur to store and manage a dictionary efficiently.
## Technology
### AVL Tree
I'm using AVL Tree to store all words from database (which consist of .txt files). The choice of an AVL Tree provide fast searching with computational complexity of O(logN). </br>
Each node in the tree contains the following:
* Parent pointer
* Two child pointers (left and right)
* Weigth (with values {-1, 0, 1})
* key - a string storing Polish word
* words - a vector of strings (each word may have multiple meanings)
</br></br>
The tree provides two main operations and several usefull:
* Find methods - two variants to search words in the dictionary. First one return pointer to node containing the data, secound returns only the vector of strings meanings
* Insert method - adds new words to both the tree and database(.txt files). If the word already exists, the method add the new meaning to the vector (if it isn't already in the dictionary)
* operator<< - overloaded function that together with the Dictionary operator[], allows displaying a searched word using simple statement ``` cout << dictionaty[string];```
* Back, left and the rest method - allow to return from a node to the root while updating the tree structure with rotations if Weigth becomes unbalanced. 
### Ncurses library
## Instalation
1. You need to install ncurses library:
```bash
#MacOS
brew install ncurses
#Linux
sudo apt-get install libncurses5-dev libncursesw5-dev
```
2. Clone the repository and navigate to project directory:
```bash
git clone https://github.com/GaThsaPer/Dictionary
cd Dictionary
```
3. Run program </br>
You can run the program by using the command:
```bash
./Dictionary
```
4. If the program doesn't run, compile project manually in terminal by command and then execute:
```bash
g++ -std=c++20 -o ./build/Dictionary ./src/*.cpp -lncurses -lmenu -lform
```
5. Install g++ compiler if it's not available on your system:
```bash
#macos
brew install gcc
#linux
sudo apt install gcc
```
Tested on: MacBook Pro (2016)
