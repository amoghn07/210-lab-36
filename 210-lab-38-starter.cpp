#include <iostream>
#include "IntBinaryTree.h"
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream fin;
    string val;
    int choice = 1;
    fin.open("codes.txt");
    //creating a BST
    IntBinaryTree tree;

    while (true){
        cout << "1. Add a record\n";
        cout << "2. Delete a record\n";
        cout << "3. Search if a record exists\n";
        cout << "4. Modify record\n";
        cout << "5. Display tree in order\n";
        cout << "0. Quit\n";
        cout << "Enter your choice(0-5): ";
        cin >> choice;
        //error handling for non int choice
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Please enter a valid number.\n";
            continue;
        }

        if (choice == 0){
            break;
        }
        else if (choice == 1){
            fin >> val;
            tree.insertNode(val);
        }
        else if (choice == 2){
            cout << "Enter record to be deleted: ";
            cin >> val;
            if (tree.searchNode(val)){
                tree.remove(val);
                cout << "Record removed.\n";
            }
            else cout << "Record not found\n";
        }
        else if (choice == 3){
            cout << "Enter record to search for: ";
            cin >> val; 
            bool result = tree.searchNode(val);
            if (result) cout << "Record exists.\n";
            else cout << "Record does not exist.\n";
        }
        else if (choice == 4){
            cout << "Enter record to be modified: ";
            cin >> val;
            if (tree.searchNode(val)){
                tree.remove(val);
                cout << "Enter new record value: ";
                string newVal;
                cin >> newVal;
                tree.insertNode(newVal);
                cout << "Record modified.\n";
            }
            else cout << "Record not found.\n";
        }
        else if (choice == 5){
            cout << "Displaying tree: \n";
            tree.displayInOrder();
        }
        else{
            cout << "Please enter a valid choice between 0 and 5.\n";
        }
    }
    fin.close();

    return 0;
}