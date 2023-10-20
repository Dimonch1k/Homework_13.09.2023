#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Undo_Redo
{
private:
    string currentText; // Text, that user input
    stack<string> undoStack; // Stack for method "undo"
    stack<string> redoStack; // Stack for method "redo"

public:
    Undo_Redo();

    void addText(string text);
    void deleteText(int deleteChars);
    void undo();
    void redo();

    string getCurrentText();
};

