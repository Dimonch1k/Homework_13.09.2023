#include "Undo_Redo.h"


Undo_Redo::Undo_Redo()
{
	currentText = "";
	undoStack = stack<string>();
	redoStack = stack<string>();
}


void Undo_Redo::addText(string text)
{
    redoStack = stack<string>();  // The stack "redo" clears with a new action
    currentText += text;          // The text inputed by user adds to string "currentText"
}


void Undo_Redo::deleteText(int deleteChars)
{
    if (deleteChars > currentText.length()) { // If amount, that input user to delete such amount of chars is bigger than length of current text,                                      
        deleteChars = currentText.length();  // so the number of "deleteChars" becomes such a length of "currentText"
    }
    string deletedText = currentText.substr(currentText.length() - deleteChars, deleteChars); // Take the substring from the currentText
    undoStack.push(deletedText);  // The text, that will be delete adds to stack "undoStack"
    redoStack = stack<string>();  // The stack "redoStack" clears with a new action
    currentText.erase(currentText.length() - deleteChars, deleteChars); // Part of the text is deleted with the specified length
}


void Undo_Redo::undo()
{
    if (!undoStack.empty()) // If stack "undoStack" isn't empty, the action executes
    {
        string undoneText = undoStack.top(); // Take the top from the undoStack
        undoStack.pop();                     // Delete the top in "undoStack"
        redoStack.push(undoneText);          // Add to "redoStack" the "undoneText"
        currentText += undoneText;
        undoneText = "";
    }
}


void Undo_Redo::redo()
{
    if (!redoStack.empty()) // If stack "redoStack" isn't empty, the action executes
    {
        string redoneText = redoStack.top(); // Take the top from the redoStack
        redoStack.pop();                     // Delete the top in "redoStack"
        undoStack.push(redoneText);          // Add to "undoStack" the "redoneText"
        currentText = currentText.substr(0, currentText.length() - redoneText.length());
    }
}

string Undo_Redo::getCurrentText() 
{
    return currentText;
}