#include <iostream>
using namespace std;

class Node {
public:
  int coeff;
  int exp;
  Node* next;

  Node(int c, int e): coeff(c), exp(e), next(nullptr) {}
};

class Polynomial {
  Node* head;
public:
  Polynomial(): head(nullptr) {}

  void insertTerm(int coeff, int exp) {
    Node* newNode = new Node(coeff, exp);

    if (head == nullptr) {
      head = newNode;
    } else {
      Node* temp = head;
      while (temp->next != nullptr) {
        temp = temp->next;
      }

      temp->next = newNode;
    }
  }

  Polynomial subtract (const Polynomial &other) const {
    Polynomial result;
    Node* temp1 = this->head;
    Node* temp2 = other.head;

    while(temp1 != nullptr && temp2 != nullptr ) {
      if(temp1->exp > temp2->exp) {
        result.insertTerm(temp1->coeff, temp1->exp);
        temp1 = temp1->next;
      } else if (temp1->exp < temp2->exp) {
        result.insertTerm(temp2->coeff, temp2->exp);
        temp2 = temp2->next;
      } else {
        int diff = temp1->coeff - temp2->coeff;

        if (diff != 0)
          result.insertTerm(diff, temp1->exp);
        temp1 = temp1->next;
        temp2 = temp2->next;
      }
    }

    while (temp1 != nullptr) {
      result.insertTerm(temp1->coeff, temp1->exp);
      temp1 = temp1->next;
    }

    while (temp2 != nullptr) {
      result.insertTerm(-temp2->coeff, temp2->exp);
      temp2 = temp2->next;
    }
    return result;
  }

  void traverse() {
    Node* temp = head;
    while(temp != nullptr) {
      cout << temp->coeff << " x ^ " << temp->exp;

      if(temp->next != nullptr) {
        cout << " + ";
      }
      temp = temp->next;
    }
    cout << "\n";
  }
};
int main() {
  Polynomial poly1, poly2, result;

  poly1.insertTerm(5, 3);
  poly1.insertTerm(4, 2);
  poly1.insertTerm(3, 1);
  poly1.insertTerm(2, 0);

  poly2.insertTerm(3, 3);
  poly2.insertTerm(2, 2);
  poly2.insertTerm(1, 1);
  poly2.insertTerm(1, 0);

  cout<< "Polynomial 1: ";
  poly1.traverse();
  cout<< "Polynomial 2: ";
  poly2.traverse();

  result = poly1.subtract(poly2);
  cout<< "Result of subtraction: ";
  result.traverse();
  return 0;
}