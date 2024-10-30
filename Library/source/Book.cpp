#include <utility>

#include "../include/Book.h"

Book::Book(std::string p_title, std::string p_genre, std::string p_author, int p_id)
{
    title = std::move(p_title);
    genre = std::move(p_genre);
    author = std::move(p_author);

    personalID = p_id;
}

void Book::getInfo() const
{
    std::cout << "Title: " << title << "\nGenre: " << genre << "\nAuthor: " << author << std::endl;
}