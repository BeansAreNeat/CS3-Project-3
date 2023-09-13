#ifndef COLLECTION_H_
#define COLLECTION_H_

#include "list.h"

template <typename T>
class Collection {
public:
    Collection();
    ~Collection();

    void addItem(const T& item);
    void removeItem(const T& item);
    T lastItem() const;
    void printCollection() const;

private:
    // Add private members for the list.
    node<T>* head_;
};

// Implement the member functions of the Collection class in the Collection.cpp file.

#endif // COLLECTION_H_