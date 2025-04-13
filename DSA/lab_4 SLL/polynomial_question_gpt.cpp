#include <iostream>
using namespace std;

// A Node class that represents a term in the polynomial
class Node {
public:
    int coeff;     
    int exp;       
    Node* next;    

    Node(int c, int e) : coeff(c), exp(e), next(nullptr) {}
};

// Polynomial class to manage the linked list of polynomial terms
class Polynomial {
    Node* head;

public:
    // A Constructor  that initializes an empty polynomial
    Polynomial() : head(nullptr) {}

    void insertTerm(int coeff, int exp) {
        Node* newNode = new Node(coeff, exp);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            // insertion at the end is done for output to be in ascending order of exponents
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    Polynomial subtract(const Polynomial& other) const {
        Polynomial result;
        Node* pointer1 = this->head; // Pointer to first polynomial
        Node* pointer2 = other.head; // Pointer to second polynomial

        // Traversing both the lists and subtracting the  corresponding terms
        while (pointer1 != nullptr && pointer2 != nullptr) {
            if (pointer1->exp > pointer2->exp) {
                result.insertTerm(pointer1->coeff, pointer1->exp);
                pointer1 = pointer1->next;
            } else if (pointer1->exp < pointer2->exp) {
                result.insertTerm(-pointer2->coeff, pointer2->exp); // negate second poly
                pointer2 = pointer2->next;
            } else {
                // Same exponent: Hence we subtract the coefficients
                int diff = pointer1->coeff - pointer2->coeff;
                if (diff != 0) {
                    result.insertTerm(diff, pointer1->exp);
                }
                pointer1 = pointer1->next;
                pointer2 = pointer2->next;
            }
        }

        // Appending the remaining terms of the first polynomial
        while (pointer1 != nullptr) {
            result.insertTerm(pointer1->coeff, pointer1->exp);
            pointer1 = pointer1->next;
        }

        // Appending the remaining terms of the second polynomial
        while (pointer2 != nullptr) {
            result.insertTerm(-pointer2->coeff, pointer2->exp);
            pointer2 = pointer2->next;
        }

        return result;
    }

    // Displaying the polynomial in a readable format
    void traverse() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->coeff << "x^" << current->exp;
            if (current->next != nullptr) {
                cout << " + ";
            }
            current = current->next;
        }
        cout << endl;
    }
};

// Main function to test the polynomial subtraction
int main() {
    Polynomial poly1, poly2, result;

    // First polynomial: 5x^3 + 4x^2 + 3x^1 + 2x^0
    poly1.insertTerm(5, 3);
    poly1.insertTerm(4, 2);

    poly1.insertTerm(2, 0);

    // Second polynomial: 3x^3 + 2x^2 + 1x^1 + 1x^0
    poly2.insertTerm(3, 3);
    poly2.insertTerm(2, 2);
    poly2.insertTerm(1, 1);
    poly2.insertTerm(1, 0);

    // Display the polynomials
    cout << "Polynomial 1: ";
    poly1.traverse();

    cout << "Polynomial 2: ";
    poly2.traverse();

    // Subtract poly2 from poly1
    result = poly1.subtract(poly2);

    // Display the result
    cout << "Result of subtraction: ";
    result.traverse();

    return 0;
}
