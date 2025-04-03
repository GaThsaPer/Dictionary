# Dictionary
This project involves a terminal-based application for UNIX-based operating systems. It uses the ncurses library to create a simple text-based user interface exploit the FORM or MENU functionality (from menu.h and form.h)</br>
For data management, the project implements an AVL tree as the primary structur to store and manage a dictionary efficiently.
## Requirements
1. UNIX-based Operating System
2. Ncurses library
3. g++ compiler
## Installation
1. Clone the repository and navigate to project directory:
```bash
git clone https://github.com/GaThsaPer/Dictionary
cd Dictionary
```
2. Install g++ compiler if it's not available on your system:
```bash
#macos
brew install gcc
brew install g++
#linux
sudo apt install gcc
sudo apt install g++
```
3. Install the ncurses library:
```bash
#MacOS
brew install ncurses
#Linux
sudo apt-get install libncurses5-dev libncursesw5-dev
```
4. Create build directory compile project manually in terminal by command and then execute:
```bash
#Linux
mkdir build
#Compile
g++ -std=c++20 -o ./build/Dictionary ./src/*.cpp -lncurses -lmenu -lform
```
5. Run program </br>
You can run the program by using the following command in build catalogue:
```bash
./build/Dictionary
```
Tested on: MacBook Pro (2016)
## Usage
The program offers four main options:
1. Search - Translates Polish words into Japaneese using the romaji alphabet (one of four Japanese writing systems).
2. Add - Allows you to add new words to the dictionary, which will be sorted in an AVL tree and a database.
3. Show Tree - (Not yet implemented) In the future, tis will display the structure of the AVL tree.
4. EXIT - Closes the program

**Navigation**</br>
* You can return to the main menu at any time using **left arrow** key.
* Navigate between options using the **up and down arrow** keys.
* Press **Enter** to confirm actions, such as adding new word, translating, or selecting an option like Add or Search.

</br>***NOTE: Polish characters are not supported yet***

## Technology and Functionality
### AVL Tree
I'm using AVL Tree to store all words from database (which consist of .txt files). The choice of an AVL Tree provide fast searching with computational complexity of O(logN). </br>
Each node in the tree contains the following:
* Parent pointer
* Two child pointers (left and right)
* Weight (with values {-1, 0, 1})
* key - a string storing Polish word
* words - a vector of strings (each word may have multiple meanings)

**Tree Operations**
The tree supports two main operations and several additional ones:
* Find methods - Two variants for searching words in the dictionary:
  1. First returns a pointer to the node containing the data.
  2. Second returns only a vector of strings meanings.
* Insert method - Adds new words to both the tree and the database(.txt files). If the word already exists, the method adds the new meaning to the vector (provided it is not already in the dictionary)
* Overload `operator<<` - Works together with the `Dictionary` `operator[]`, allowing a word to be displayed using a simple statement: ` cout << dictionaty[string];`
* Back, left and Other Methods - Enable returning from a node to the root while updating the tree structure with rotations if the weigth becomes unbalanced. 
### Ncurses library
[Ncurses](https://en.wikipedia.org/wiki/Ncurses) is a UNIX-based library for creating textual user interfaces that work across various terminal environments. In this project i used two modules from the library: 
* `menu.h` For composing character-cell terminal menus.
* `form.h` For creating form-based screens that allow users to interact with the dictionary.

**Menu class** 
The Menu includes the following components:
* `Dictionary` - An object containing the AVL tree and the entire dictionary. This is the core class, that provides all functionalities, such as searching for words and adding new ones. 
* `Choices` & `iSizeChoices` - An array of main menu options and its size.
* `ITEM` - A pointer indicating all available menu choices, later used to build MENU.
* `MENU` - A pointer used in the `menu_driver` method to display and manage the menu interface.
* `FIELD` - An array of pointers representing form fields.
* `FORM` - A pointer used to manage FIELD elements and display them on the screen.

Menu Class Methods:
* `Init` - Initializes all objects and variables for the menus.
* `Run` - The main program loop.
* `ShutDown` - Destroys all menu objects that were created in `Init`.
* `FindMenu` - The menu loop where users can search for word meanings.
* `AddMenu` - The menu loop where users can add new words to the dictionary.
* `LOWER` - Converts all letters to lowercase (similar to SQL's `LOWER` function).
* `corrLett` - A boolean function that checks whether a string is correctly formatted.

For more details,you can find the Ncurses documentation [here](https://invisible-island.net/ncurses/man/ncurses.3x.html).

## Development and Plan
- [ ] Improve Interface (Better UI in ncurses)
- [ ] Json data base instead of two .txt files
- [ ] Show tree AVL function (Display tree structure)
- [ ] Two-way translation (enable to translations from Japanese to Polish)
- [ ] Polish characters support - (UTF-8 implementation)
- [ ] Japanese script support (add kanji, hiragana, and katakana)
## Contact 
You can find contact to me on my [My GitHub](https://github.com/GaThsaPer) account, or text on [Instagram](https://www.instagram.com/gathasper/).
