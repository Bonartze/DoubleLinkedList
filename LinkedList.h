//
// Created by ivan on 11.06.23.
//

#ifndef UNTITLED58_LINKEDLIST_H
#define UNTITLED58_LINKEDLIST_H

#include <memory>
#include <iostream>

template<typename T>
struct Node {
    T data;
    std::shared_ptr<Node<T>> next;
    std::weak_ptr<Node<T>> prev;

    Node(T d) : data(d), next(nullptr) {}
};

template<typename T>
class LinkedList {
private:
    std::shared_ptr<Node<T>> head;
public:
    LinkedList(T d) {
        head = std::make_shared<Node<T>>(Node<T>{d});
    }

    void add_end(T d) {
        auto temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = std::make_shared<Node<T>>(Node<T>{d});
        temp->next->next = nullptr;
        temp->next->prev = temp;
        temp->next->data = d;
    }

    void add_beg(T d) {
        auto temp = std::make_shared<Node<T>>(Node<T>{d});
        temp->next = head;
        head->prev = temp;
        head = temp;
    }

    friend std::ostream &operator<<(std::ostream &os, LinkedList<T> l) {
        auto temp = l.head;
        while (temp) {
            os << temp->data << ' ';
            temp = temp->next;
        }
        return os;
    }
};


#endif //UNTITLED58_LINKEDLIST_H
