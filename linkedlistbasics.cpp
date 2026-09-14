#include <iostream>
using namespace std;

/*
========================================================
              SINGLY LINKED LIST USING CLASS
========================================================

THEORY:

A linked list is a linear data structure made up of
nodes.

Each node contains:
1. DATA -> stores the value
2. NEXT -> stores address of the next node

In a singly linked list, each node points only to the
next node.

Example:

HEAD
 ↓
[10|•] -> [20|•] -> [30|NULL]

The last node always points to NULL.

========================================================
*/

class LinkedList
{
private:

    // Node of the linked list
    class Node
    {
    public:
        int data;
        Node* next;

        Node(int value)
        {
            data = value;
            next = NULL;
        }
    };

    Node* head;


public:

    // Constructor
    LinkedList()
    {
        head = NULL;
    }


    // =================================================
    // 1. PUSH FRONT
    // =================================================

    /*
    Push Front = Insert a node at the beginning.

    Steps:
    1. Create a new node.
    2. New node points to current head.
    3. Make new node the head.

    Example:

    Before:
    HEAD -> 10 -> 20 -> 30 -> NULL

    After pushFront(5):

    HEAD -> 5 -> 10 -> 20 -> 30 -> NULL
    */

    void pushFront(int value)
    {
        Node* newNode = new Node(value);

        newNode->next = head;
        head = newNode;
    }


    // =================================================
    // 2. PUSH BACK
    // =================================================

    /*
    Push Back = Insert a node at the end.

    Steps:
    1. Create a new node.
    2. If list is empty, make it HEAD.
    3. Otherwise traverse to the last node.
    4. Make last node point to new node.
    */

    void pushBack(int value)
    {
        Node* newNode = new Node(value);

        // If list is empty
        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node* temp = head;

        // Go to last node
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }


    // =================================================
    // 3. PRINT LINKED LIST
    // =================================================

    /*
    Printing:
    Start from HEAD and keep moving to the next node
    until NULL is reached.
    */

    void printList()
    {
        Node* temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }


    // =================================================
    // 4. POP FRONT
    // =================================================

    /*
    Pop Front = Delete the first node.

    Steps:
    1. Store head in temporary pointer.
    2. Move head to the next node.
    3. Delete the old first node.

    Before:
    HEAD -> 10 -> 20 -> 30

    After:
    HEAD -> 20 -> 30
    */

    void popFront()
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;

        head = head->next;

        delete temp;
    }


    // =================================================
    // 5. POP BACK
    // =================================================

    /*
    Pop Back = Delete the last node.

    We need to reach the SECOND LAST node because
    its next pointer must be changed to NULL.

    Example:

    Before:
    10 -> 20 -> 30 -> NULL

    After:
    10 -> 20 -> NULL
    */

    void popBack()
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

        // Only one node
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;

        // Reach second-last node
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;

        temp->next = NULL;
    }


    // =================================================
    // 6. INSERT IN MIDDLE
    // =================================================

    /*
    Insert at a particular position.

    Position starts from 1.

    Example:

    10 -> 20 -> 30

    insertMiddle(15, 2)

    Result:

    10 -> 15 -> 20 -> 30

    Steps:
    1. Reach the node BEFORE the required position.
    2. New node points to the next node.
    3. Previous node points to new node.
    */

    void insertMiddle(int value, int position)
    {
        // Position 1 means insert at front
        if (position == 1)
        {
            pushFront(value);
            return;
        }

        Node* temp = head;

        // Reach node before required position
        for (int i = 1; i < position - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Invalid position!" << endl;
            return;
        }

        Node* newNode = new Node(value);

        // Adjust links
        newNode->next = temp->next;
        temp->next = newNode;
    }


    // =================================================
    // 7. SEARCH
    // =================================================

    /*
    Search = Find whether a particular value exists.

    Steps:
    1. Start from HEAD.
    2. Compare data with required value.
    3. If found, print position.
    4. Otherwise move to next node.
    5. Continue until NULL.

    Time Complexity = O(n)
    */

    void search(int value)
    {
        Node* temp = head;
        int position = 1;

        while (temp != NULL)
        {
            if (temp->data == value)
            {
                cout << "Element found at position "
                     << position << endl;
                return;
            }

            temp = temp->next;
            position++;
        }

        cout << "Element not found!" << endl;
    }
};


// =====================================================
// MAIN FUNCTION
// =====================================================

int main()
{
    LinkedList list;

    // Push Back
    list.pushBack(10);
    list.pushBack(20);
    list.pushBack(30);

    cout << "Linked List: ";
    list.printList();


    // Push Front
    list.pushFront(5);

    cout << "After Push Front: ";
    list.printList();


    // Insert in Middle
    list.insertMiddle(15, 3);

    cout << "After Inserting 15 at position 3: ";
    list.printList();


    // Search
    list.search(20);


    // Pop Front
    list.popFront();

    cout << "After Pop Front: ";
    list.printList();


    // Pop Back
    list.popBack();

    cout << "After Pop Back: ";
    list.printList();


    return 0;
}