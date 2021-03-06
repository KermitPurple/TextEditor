#ifndef TEXT_EDITOR
#define TEXT_EDITOR

#include<windows.h>
#include<string>
#include"Node.h"

class TextEditor{
private:
    Node* head; // pointing at first character in the document
    Node* curr; // pointing at where the cursor is
    Node* selection; // pointer to where selection was started
    Node* clipboard; // head of linked list containing contents of clipboard
    bool running; // if the main loop is running
    bool insert_at_begining; // if inserting before first character
    void set_color(int color); // set color of text output
    void gotoxy(COORD coord); // move cursor to (x, y) coord on screen
    COORD get_xy(Node* n, bool to_print); // get coord of cursor based on curr
    void keyboard_input(); // take input from user
    void save_file(std::string file_name); // save a current document to a file
    void load_file(std::string file_name); // load document from a file
    std::string get_file_name(); // get user input for file name
    void show_help(); // print help screen
    void move_up(); // move up one line maintaining x
    void move_down(); // move up one line maintaining x
    void print_text(); // print contents of document
    void delete_list(); // delete the linked list containing document
    void insert_character(char key); // insert character at curr
    void delete_character(); // delete curr
    void paste_clipboard(); // insert clipboard at curr
    void delete_clipboard(); // delete linked list for clipboard
    void copy_selection(); // copy selection into clipboard
    void print_overlay(); // print the overlay for the screen
    void draw_screen(); // print the entire screen overlay and all
    std::pair<Node*, Node*> get_selection_start_end(); // get the start and end points of the text currently selected
public:
    TextEditor(); // constructor
    ~TextEditor(); // deconstructor
    void run(); // start running editor
};

#endif //TEXT_EDITOR
