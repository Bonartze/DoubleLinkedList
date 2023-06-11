//
// Created by ivan on 11.06.23.
//

#ifndef UNTITLED58_LINKEDLIST_H
#define UNTITLED58_LINKEDLIST_H

#include "NullException.h"
#include <memory>
#include <iostream>

template<typename T>
struct Node {
    T data;
    std::shared_ptr<Node<T>> next;
    std::shared_ptr<Node<T>> prev;

    Node(T d) : data(d), next(nullptr) {}
};

template<typename T>
class LinkedList {
private:
    std::shared_ptr<Node<T>> head;
    std::shared_ptr<Node<T>> tail;
public:
    LinkedList(T d) {
        tail = head = std::make_shared<Node<T>>(Node<T>{d});
    }

    void add_end(T d) {
        auto temp = std::make_shared<Node<T>>(Node<T>{d});
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }

    void add_beg(T d) {
        auto temp = std::make_shared<Node<T>>(Node<T>{d});
        temp->next = head;
        head->prev = temp;
        head = temp;
    }

    void delete_end() {
        if (!head)
            throw NullException("Null head\n");
        if (head != tail) {
            tail = tail->prev;
            tail->next.reset();
        } else
            head.reset();
    }

    void delete_begin() {
        if (!head)
            throw NullException("Null head\n");
        if (head != tail) {
            head = head->next;
            head->prev.reset();
        } else
            head.reset();
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
