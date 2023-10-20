#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;



#define TASK 2


#if TASK == 1

#include "Task1.h"

int main()
{
    Node* head = nullptr;


    for (int i = 0; i < 4; i++) // The user input values in stack
    {
        int value = 0;
        cout << "Enter " << i + 1 << " number: ";
        cin >> value;
        push(head, value); // Put node to the end of the stack
    }
    cout << "\n";
    display(head);

    if (head)
    {
        pop(head);
        display(head);

        top(head);
        display(head);
    }

}


#elif TASK == 2

#include "Undo_Redo.h"

void Options(Undo_Redo& editor)
{
    cout << "\n\n\t\t\tCurrent Text: " << editor.getCurrentText() << endl;
    cout << "\t\t\tOptions:" << endl;
    cout << "\t\t\t1. Add Text" << endl;
    cout << "\t\t\t2. Delete Text" << endl;
    cout << "\t\t\t3. Undo" << endl;
    cout << "\t\t\t4. Redo" << endl;
    cout << "\t\t\t5. Quit" << endl;
}

void ADD(Undo_Redo& editor)
{
    string text;
    cin.ignore();         // Ignore newline character from previous input(it used special when used getline())
    cout << "Input the text: "; getline(cin, text);   // The user input text
    editor.addText(text); // The method "addText" executes from class "Undo_Redo"
}

void DELETE(Undo_Redo& editor)
{
    int deleteChars;
    cout << "Enter the number of characters to delete: ";
    cin >> deleteChars;
    editor.deleteText(deleteChars); // The method "deleteText" executes from class "Undo_Redo"
}


void UNDO(Undo_Redo& editor)
{
    editor.undo(); // The method "undo" executes from class "Undo_Redo"
}

void REDO(Undo_Redo& editor)
{
    editor.redo(); // The method "redo" executes from class "Undo_Redo"
}

void EXIT()
{
    cout << "You exiting the program.\n\n";
    exit(0);
}

void EXCEPTION()
{
    cout << "Invalid choice. Try again.\n\n";
}

int MakeChoice()
{
    int choice;
    cout << "\n\t\t\tEnter the number to perform the action: ";
    cin >> choice;  // The user make choice
    cout << "\t\t\t";
    return choice;
}

void ActionPerforms(int choice, Undo_Redo& editor)
{
    switch (choice) // The action, that has the number inputed by user executes
    {
    case 1: {
        ADD(editor);
        break;
    }
    case 2: {
        DELETE(editor);
        break;
    }
    case 3:
        UNDO(editor);
        break;

    case 4:
        REDO(editor);
        break;

    case 5: // Stop the program
        EXIT();

    default: // If the user input the number less than 0 and larger than 5, an error is reported on the screen
        EXCEPTION();
    }
}

// I use in this program <stack> library, because its easier to use aready done stack and manage it

int main() {
    Undo_Redo editor;
    int choice = 0;

    while (true) { 
        Options(editor);
        choice = MakeChoice();
        
        ActionPerforms(choice, editor);
    }
    return 0;
}
#endif 