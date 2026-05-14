#include <iostream>
#include "IntBinaryTree.h"
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream fin;
    string val;
    int choice;
    fin.open("codes.txt");
    //creating a BST
    IntBinaryTree tree;

    while (choice != 0){
        cout << "1. Add a record\n";
        cout << "2. Delete a record\n";
        cout << "3. Search if a record exists\n";
        cout << "4. Modify record\n";
        cout << "5. Display tree in order\n";
        cout << "0. Quit\n";
        cout << "Enter your choice(0-5): ";
        cin >> choice;

        if (choice == 1){
            fin >> val;
            tree.insertNode(val);
        }
        else if (choice == 2){
            cout << "Enter record to be deleted: ";
            cin >> val;
            tree.remove(val);
        }
        else if (choice == 3){
            cout << "Enter record to search for: ";
            cin >> val; 
            bool result = tree.searchNode(val);
            if (result) cout << "Record exists.";
            else cout << "Record does not exist.";
        }
    }
    //populating tree with for loop
    for (int i = 0; i < 10; i++){
        fin >> val;
        tree.insertNode(val);
    }
    tree.displayInOrder();

    return 0;
}