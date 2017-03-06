//
// Created by alexey on 30.10.16.
//
#include <iostream>
#include <fstream>
#include <climits>
#include <cstring>
#include <limits>
#include <sstream>
#include "Book.h"

int Book::GetPages() {
    return pages;
}

void Book::show() {
    cout << "Автор: " << author_name << endl;
    cout << "Название: " << book_title << endl;
    cout << "Издательство: " << publisher << endl;
    cout << "Кол-во страниц: " << pages << endl;

    cout << "Вид литературы: ";
    switch (book_t) {
        case technical:
            cout << "Техническая" << endl;
            book_record.tech.show();
            break;
        case art:
            cout << "Художественная" << endl;
            book_record.art.show();
            break;
    }
};

void Book::create_record() {


    cout << "Введите автора: ";
    //cin >>author_name;
    author_name = "";
    getline(std::cin, author_name);


    book_title = "";
    cout << "Введите название: ";
    //cin >>book_title;
    getline(std::cin, book_title);


    cout << "Введите издательство: ";
    //>publisher;
    publisher = "";
    getline(std::cin, publisher);
    //cin >>publisher;

    string tmp;
    cout << "Введите количество страниц: ";
    pages = -1;
    while (true) {
        getline(cin, tmp);
        stringstream myStream(tmp);
        if (myStream >> pages && pages > 0)
            break;
        cout << "Ошибочный ввод" << endl;
    }

    cout << "Выберите вид литературы: \n0- Техническая, \n1- Художественная \n";
    int x = -1;
    while (true) {
        getline(cin, tmp);
        stringstream myStream(tmp);
        if (myStream >> x && (x == 0 || x == 1))
            break;
        cout << "Ошибочный ввод" << endl;
    }


    book_t = type_book(x);

    switch (x) {
        case 0:
            book_record.tech.create_technical_book();
            break;
        case 1:
            book_record.art.create_art_book();
            break;
    }

}

void art_book::create_art_book() {

    cout << "Выберите тип  произведения: \n0- роман, \n1- пьеса, \n2- стихи\n";
    int x = -1;
    string tmp;
    while (true) {
        getline(cin, tmp);
        stringstream myStream(tmp);
        if (myStream >> x && (x == 0 || x == 1 || x == 2))
            break;
        cout << "Ошибочный ввод" << endl;
    }
    art = kind_art(x);

}

void technical_book::create_technical_book() {

    cout << "Введите отрасль: \n";

    cin.getline(industry, sizeof industry);
    if (strlen(industry) > LEN_STRING) {
        cout << "Превышено количество символов!\n";
    }

    string tmp;
    cout << "Выберите тип  произведения: \n0- отечественная, \n1- переводная\n";
    int x = -1;
    while (true) {
        getline(cin, tmp);
        stringstream myStream(tmp);
        if (myStream >> x && (x == 0 || x == 1))
            break;
        cout << "Ошибочный ввод\n";
    }

    locate = kind_localization(x);
    cout << "Введите год издания\n";
    year = -1;
    while (true) {
        getline(cin, tmp);
        stringstream myStream(tmp);
        if (myStream >> year && (year > 0 && year < 2017))
            break;
        cout << "Ошибочный ввод\n";
    }

}

void art_book::show() {

    cout << "Тип  произведения: ";
    switch (art) {
        case novels:
            cout << "роман" << endl;
            break;
        case plays:
            cout << "пьеса" << endl;
            break;
        case poems:
            cout << "стихи" << endl;
            break;
    }
}

void technical_book::show() {

    cout << "Отрасль: " << industry << endl;

    cout << "Тип  произведения: ";
    switch (locate) {
        case patriotic:
            cout << "отечественная" << endl;
            break;
        case translated:
            cout << "переводная" << endl;
            break;
    }

    cout << "Год издания: " << year << endl;

}

void Book::read_from_file(istream &fin) {


    fin >> author_name;
    fin >> book_title;
    fin >> publisher;
    fin >> pages;
    int x;
    fin >> x;
    book_t = type_book(x);

    if (x == 0) {
        fin >> book_record.tech.industry;
        fin >> x;
        book_record.tech.locate = kind_localization(x);
        fin >> book_record.tech.year;
    } else {
        int x;
        fin >> x;
        book_record.art.art = kind_art(x);
    }


};



//Вывести список всей переводной лит-ры по указанной отрасли с годом издания не позднее указанного.

bool Book::search(int year, char *ind) {
    if (book_t != technical)
        return false;
    if (book_record.tech.locate != translated)
        return false;

    if (strcmp(book_record.tech.industry, ind) != 0)
        return false;

    if (book_record.tech.year > year)
        return false;

    return true;


}
