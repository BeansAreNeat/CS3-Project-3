// Collection.cpp

#include "Collection.h"
#include "list.h"
#include <string>
#include <iostream>
#include <stdexcept>


template <typename T>
Collection<T>::Collection() : head_(nullptr) {}

template <typename T>
Collection<T>::~Collection() {
    // Implement the destructor to clean up dynamically allocated nodes.
    while (head_ != nullptr) {
        node<T>* temp = head_;
        head_ = head_->getNext();
        delete temp;
    }
}

template <typename T>
void Collection<T>::addItem(const T& item) {
    // Add a new node to the front of the list.
    node<T>* newNode = new node<T>;
    newNode->setData(item);
    newNode->setNext(head_);
    head_ = newNode;
}

template <typename T>
void Collection<T>::removeItem(const T& item) {
    // Remove all instances of the item from the collection.
    node<T>* current = head_;
    node<T>* prev = nullptr;

    while (current != nullptr) {
        if (current->getData() == item) {
            // Item found, remove the node.
            if (prev != nullptr) {
                prev->setNext(current->getNext());
                delete current;
                current = prev->getNext();
            }
            else {
                // Removing the head node.
                node<T>* temp = head_;
                head_ = head_->getNext();
                delete temp;
                current = head_;
            }
        }
        else {
            prev = current;
            current = current->getNext();
        }
    }
}

template <typename T>
T Collection<T>::lastItem() const {
    // Return the last item added to the collection.
    if (head_ == nullptr) {
        // Handle the case where the collection is empty.
        throw std::runtime_error("Collection is empty");
    }

    node<T>* current = head_;
    while (current->getNext() != nullptr) {
        current = current->getNext();
    }

    return current->getData();
}

template <typename T>
void Collection<T>::printCollection() const {
    // Print all items in the collection.
    node<T>* current = head_;
    while (current != nullptr) {
        std::cout << current->getData() << " ";
        current = current->getNext();
    }
    std::cout << std::endl;
}

// Explicit instantiation for the types you intend to use.
template class Collection<int>;
template class Collection<std::string>;
// Add more explicit instantiations for other types as needed.
