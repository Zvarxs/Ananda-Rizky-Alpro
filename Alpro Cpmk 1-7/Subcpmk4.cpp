#include <iostream>
#include <string>

struct Book {
    std::string title;
    std::string author;
    int publicationYear;
    std::string publisher;
    float price;
};

void printBookInfo(const Book& book) {
    std::cout << "Title: " << book.title << std::endl;
    std::cout << "Author: " << book.author << std::endl;
    std::cout << "Publication Year: " << book.publicationYear << std::endl;
    std::cout << "Publisher: " << book.publisher << std::endl;
    std::cout << "Price: $" << book.price << std::endl;
}

int main() {
    Book book1;
    book1.title = "C++ Programming";
    book1.author = "Bjarne Stroustrup";
    book1.publicationYear = 1985;
    book1.publisher = "Addison-Wesley";
    book1.price = 59.99f;

    Book book2 = {"The C++ Standard Library", "Nicolai M. Josuttis", 1999, "Addison-Wesley", 69.99f};

    std::cout << "Information about book1:" << std::endl;
    printBookInfo(book1);
    std::cout << std::endl;

    std::cout << "Information about book2:" << std::endl;
    printBookInfo(book2);
    std::cout << std::endl;

    return 0;
}