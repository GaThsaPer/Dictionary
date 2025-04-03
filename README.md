# Dictionary
This project involves a terminal-based application for UNIX-based operating systems. It is using ncurses libraryto create a simple text-based user interface exploit the FORM or MENU to functionality (from menu.h and form.h)</br>
For data managment, the project implement an AVL tree as the primary structur to store and manage a dictionary efficiently.
## Technology and Functionality
### AVL Tree
I'm using AVL Tree to store all words from database (which consist of .txt files). The choice of an AVL Tree provide fast searching with computational complexity of O(logN). </br>
Each node in the tree contains the following:
* Parent pointer
* Two child pointers (left and right)
* Weigth (with values {-1, 0, 1})
* key - a string storing Polish word
* words - a vector of strings (each word may have multiple meanings)

The tree provides two main operations and several usefull:
* Find methods - two variants to search words in the dictionary. First one return pointer to node containing the data, secound returns only the vector of strings meanings
* Insert method - adds new words to both the tree and database(.txt files). If the word already exists, the method add the new meaning to the vector (if it isn't already in the dictionary)
* operator<< - overloaded function that together with the Dictionary operator[], allows displaying a searched word using simple statement ``` cout << dictionaty[string];```
* Back, left and the rest method - allow to return from a node to the root while updating the tree structure with rotations if Weigth becomes unbalanced. 
### Ncurses library
[Ncurses](https://en.wikipedia.org/wiki/Ncurses) is a UNIX-based library, for creating textual user interfaces that works in a wild of terminals. I used 2 
modules from that library: menu.h to compose character-cell terminal menu and form.h to create form screens, which allows users utilize the dictionary.
My menu class includes the following parameters:
* Dictionary - The object which contains the AVL Tree and all dictionary.
* ITEM -
* MENU -
* FIELD -
* FORM -
* WINDOW -
* Choices -

</br> You can find decumentation to ncurses [there](https://invisible-island.net/ncurses/man/ncurses.3x.html).
## Usage
Main menu the program has 4 options:
1. Search - translate polish words into japaneese writnig in their roomaji alphabet (one of their 4 alphabets)
2. Add - Allow you add new word to dictionary, which will be added into AVL and data base
3. Show Tree - It doesn't work now, in future will show how AVL looks
4. EXIT - Power off the program

From each option you can back to main menu with left arrow, and jumps between forms with up and down arrows. Enter key confirms your actions like adding new word, translating it or chose option where do you want to enter like Add or Search.</br></br>
***Remember polish characters doesn't works yet***
## Requirements
1. UNIX-based Operating System
2. Ncurses library
3. g++ compiler
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
You can run the program by using the following command in build catalogue:
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
brew install g++
#linux
sudo apt install gcc
sudo apt install g++
```
Tested on: MacBook Pro (2016)

## Development and Plan
- [ ] Improve Interface
- [ ] Json data base instead of two .txt files
- [ ] Show tree AVL function
- [ ] Two side translate
- [ ] Polish characters support
- [ ] Japaneese alphabets
## Contact 
You can find contact to me on my [My GitHb](https://github.com/GaThsaPer) account, or text on [Instagram](https://www.instagram.com/gathasper/).
