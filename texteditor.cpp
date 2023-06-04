#include <iostream>
#include <stack>
using namespace std;

void insertCharacter(stack<char>& before, char c) {
    before.push(c);
}

void deleteCharacter(stack<char>& before) {
    if (!before.empty()) {
        before.pop();
    }
}

void moveCursorLeft(stack<char>& before, stack<char>& after) {
    if (!before.empty()) {
        after.push(before.top());
        before.pop();
    }
}

void moveCursorRight(stack<char>& before, stack<char>& after) {
    if (!after.empty()) {
        before.push(after.top());
        after.pop();
    }
}

void printText(stack<char> before, stack<char> after) {
    // Print the text in the correct order
    while (!before.empty()) {
        cout << before.top();
        before.pop();
    }
    // Reverse and print the text after the cursor
    stack<char> temp;
    while (!after.empty()) {
        temp.push(after.top());
        after.pop();
    }
    while (!temp.empty()) {
        cout << temp.top();
        temp.pop();
    }
    cout << endl;
}

int main() {
    stack<char> before;  // Characters before the cursor
    stack<char> after;   // Characters after the cursor

    char option;
    char ch;

    do {
        cout << "1. Insert character" << endl;
        cout << "2. Delete character" << endl;
        cout << "3. Move cursor left" << endl;
        cout << "4. Move cursor right" << endl;
        cout << "5. Print text" << endl;  // New option: Print text
        cout << "6. Exit" << endl;        // New option: Exit

        cout << "Enter option: ";
        cin >> option;

        switch (option) {
            case '1':
                cout << "Enter character to insert: ";
                cin >> ch;
                insertCharacter(before, ch);
                break;
            case '2':
                deleteCharacter(before);
                break;
            case '3':
                moveCursorLeft(before, after);
                break;
            case '4':
                moveCursorRight(before, after);
                break;
            case '5':
                cout << "Current text: ";
                printText(before, after);
                break;
            case '6':
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }
    } while (true);

    return 0;
}

        
        
