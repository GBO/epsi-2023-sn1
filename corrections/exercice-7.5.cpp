#include <iostream>
using namespace std;


class Node {
private:
  int data;
  Node* next;

public:
  Node(int data) {
    this->data = data;
    this->next = nullptr;
  }

  int get_data() { return this->data; }
  void set_data(int data) { this->data = data; }
  Node* get_next() { return this->next; }

  void add(int new_data) {
    if (this->next == nullptr) {
      this->next = new Node(new_data);
    } else {
      this->next->add(new_data);
    }
  }

  void insert(int position, int new_data) {
    Node* current = this;
    int i = 0;

    while (current->next != nullptr) {
      if (position == i) {
        Node* nn = new Node(current->data);
        nn->next = current->next;
        current->data = new_data;
        current->next = nn;
        break;
      }
      i++;
      current = current->next;
    }
  }

  int count() {
    int result;
    if (this->next == nullptr) {
      result = 1;
    } else {
      result = 1 + this->next->count();
    }
    return result;
  }

  void display() {
    Node* current = this;
    cout << "Les " << this->count() <<  " valeurs : ";
    while (current->next != nullptr) {
      cout << current->data << ", ";
      current = current->next;
    }
    cout << current->data << endl;
  }
};


int main(int argc, char **argv) {
  cout << "Exercice 7.5" << endl;

  Node* n1 = new Node(12);
  n1->add(24);
  n1->add(48);
  n1->add(96);
  n1->add(192);



  cout << "Le noeud : " << n1->get_data() << endl;
  cout << "Le noeud : " << n1->get_next()->get_data() << endl;
  cout << "Le noeud : " << n1->get_next()->get_next()->get_data() << endl;

  n1->display();
  n1->insert(0, 6);
  n1->insert(3, 36);
  n1->display();

  delete n1;

  return 0;
}
