#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *left, *right;
  Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class Tree {
  Node *root;

public:
  Tree() { root = nullptr; }
};
int main() {
  Tree t1;
  return 0;
}