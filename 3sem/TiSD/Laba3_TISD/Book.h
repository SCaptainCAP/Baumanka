//
// Created by alexey on 30.10.16.
//

#ifndef TISD3_BOOK_H
#define TISD3_BOOK_H

#define LEN_STRING 150


#include <iostream>

using namespace std;

enum kind_art {
    novels, plays, poems
};

enum kind_localization {
    patriotic, translated
};

enum type_book {
    technical, art
};

struct technical_book {
    char industry[LEN_STRING];
    kind_localization locate;
    int year;

    void create_technical_book();

    void show();

};

struct art_book {
    kind_art art;

    void create_art_book();

    void show();
};


union kind_book {
    technical_book tech;
    art_book art;
};

class Book {

private:

    string author_name;
    string book_title;
    string publisher;
    int pages;
    type_book book_t;
    kind_book book_record;

public:

    void read_from_file(istream &fin);

    bool search(int year, char *ind);

    void create_record();

    void show();

    int GetPages();

};


#endif //TISD3_BOOK_H
