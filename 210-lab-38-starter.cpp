#include <iostream>
#include "IntBinaryTree.h"
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream fin;
    string val;
    fin.open("codes.txt");
    //creating a BST
    IntBinaryTree tree;

    //populating tree with for loop
    for (int i = 0; i < 10; i++){
        fin >> val;
        tree.insertNode(val);
    }
    tree.displayInOrder();
    
    return 0;
}