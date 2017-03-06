//
// Created by alexey on 31.10.16.
//

#include "Book.h"

class Table_key {
public:
    int id;

    int pages;

    Table_key() {
        id = 0;
        pages= 0;
    }

    Table_key(int i,Book &obj) {
        id = i;
        pages = obj.GetPages();
    }

};