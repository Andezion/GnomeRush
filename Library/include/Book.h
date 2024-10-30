#ifndef LIBRARY_BOOK_H
#define LIBRARY_BOOK_H

#include <string>
#include <iostream>

class Book
{
public:
    std::string title{};
    std::string genre{};
    std::string author{};
    std::string language{};

    int personalID{};

    Book(std::string p_title, std::string p_genre, std::string p_author, int p_id);

    void getInfo() const;
};

#endif //LIBRARY_BOOK_H
