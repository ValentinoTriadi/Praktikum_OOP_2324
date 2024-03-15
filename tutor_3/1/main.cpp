#include "BinaryTree.hpp"

int main(){
    BinaryTree<int> tree;
    tree.setValue(6);
    tree.addChild(7).addChild(8).addChild(9);
    tree.addChild(11).addChild(10);
    cout << tree << endl;
    BinaryTree<int> tree2 = tree;
    cout << tree2 << endl;
}