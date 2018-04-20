#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

bool is_prime(int number){
    if(number<2)
        return false;
    for(int i=2; i<sqrt(number); ++i)
        if(number%i==0)
            return false;
    return true;
}

struct node {
    int data;
    node *next;
    node();
};

node::node() {
    next = nullptr;
}

struct lista {
    node *head;
    void push(int data);
    void pop(int index);
    void fill_list(int start, int end);
    void sito();
    void display();
    void save();
    lista();
};

lista::lista() {
    head = nullptr;
}

void lista::push(int data) {
    node *new_node = new node;
    new_node->data = data;
    if(head == nullptr)
        head = new_node;
    else {
        node *cur = head;
        while(cur->next)
            cur = cur->next;
        cur->next = new_node;
    }
}

void lista::pop(int index) {
    if(head == nullptr)
        cout << "ERROR 0x00";
    else if (head->data ==index) {
        node *tmp = head;
        head = tmp->next;
    }
    else {
        node *cur = head;
        while(cur->next->data != index)
            cur = cur->next;
        if(cur){
            node *tmp = cur->next;
            cur->next = tmp->next;
            delete tmp;
        }
    }
}

void lista::fill_list(int start, int end) {
    if (start > end)
        swap(start, end);
    for (int i = start; i <= end; ++i)
        push(i);
}

void lista::display() {
    if(head == 0)
        cout << "ERROR 0x0" << endl;
    else {
        node *cur = head;
        while(cur){
            cout << cur->data << ' ';
            cur = cur->next;
        }
    }
}

void lista::save() {
    ofstream out;
    out.open("wynik.txt");
    node *cur = head;
    while(cur){
        out << cur->data << endl;
        cur = cur->next;
    }
    out.close();
}

void lista::sito() {
    node *cur = head;
    while(cur->next != nullptr)
        cur = cur->next;
    int len = sqrt(cur->data);
    for(int i=2; i<=len; i++){
        if(is_prime(i)){
            cur = head;
            while(cur){
                if(cur->data%i == 0 && cur->data != i)
                    pop(cur->data);
                cur = cur->next;
            }
        }
    }
}

int main() {
    lista *liczby = new lista;
    liczby->fill_list(2, 120);
    liczby->sito();
    liczby->save();
    liczby->display();
}
