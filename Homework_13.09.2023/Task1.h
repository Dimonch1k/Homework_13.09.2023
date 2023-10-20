#pragma once

#include <iostream>
using namespace std;


class Node {
public:
    int value;
    Node* next;

    Node()
    {
        value = 0;
        next = nullptr;
    }
    Node(int value)
    {
        this->value = value;
        this->next = nullptr;
    }
};


string isEmpty(Node* head)
{
    if (!head)
    {
        cout << "The stack is empty!\n\n";
    }
    return "";
}

void push(Node*& head, int value)
{
    Node* newNode = new Node(value);

    if (!head)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

void pop(Node*& head)
{

    while (head)
    {
        if (head->next)
        {
            cout << "The element " << head->value << " was deleted!\n\n";
            head = head->next;
            return;
        }
        cout << "The element " << head->value << " was deleted!\n\n";
        head = nullptr;
        return;
    }
}

void top(Node* head)
{
    while (head->next)
    {
        head = head->next;
    }
    cout << "The final number in the stack is " << head->value << "\n\n";
}

void display(Node* head)
{
    if (!head)
    {
        cout << "The stack is empty\n\n";
        return;
    }
    cout << "All numbers: ";
    while (head)
    {
        cout << head->value << " ";
        head = head->next;
    }
    cout << "\n\n";
}