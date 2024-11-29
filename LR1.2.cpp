#include <iostream>
#include <vector>

using namespace std;

class Book
{
public:
    string author;
    string title;
    bool ArtType;
    // конструктор Book
    Book(string AuthorName, string BookTitle, bool GenreType)
        : author(AuthorName), title(BookTitle), ArtType(GenreType) {}
};
class Library
{
private:
    // конструктор Library
    vector<Book *> books;

public:
    // деструктор Library
    ~Library()
    {
        for (auto book : books)
        {
            delete book;
        }
    }
    // добавление книги в библиотеку
    void AddBook(string AuthorName, string BookTitle, bool FictionType, int number)
    {
        // если автор или название пустые, не добавляем книгу
        if (AuthorName.empty() || BookTitle.empty())
        {

            cout << "Cannot add " << number << " book: author or title is empty." << endl;
            return;
        }
        // добавление книги
        books.push_back(new Book(AuthorName, BookTitle, FictionType));
    }

    // подсчёт жанров книг при помощи switch
    void CountBooksUsingSwitch()
    {
        int artTypeCount = 0, technicalTypeCount = 0;
        for (auto book : books)
        {
            switch (book->ArtType)
            {
            case true:
                artTypeCount++;
                break;
            case false:
                technicalTypeCount++;
                break;
            }
        }
        cout << "Fiction books: " << artTypeCount << ", Technical books: " << technicalTypeCount << endl;
    }

    // подсчёт жанров книг при помощи if
    void СountBooksWithoutSwitch()
    {
        int artTypeCount = 0, technicalTypeCount = 0;
        for (auto book : books)
        {
            if (book->ArtType)
            {
                artTypeCount++;
            }
            else
            {
                technicalTypeCount++;
            }
        }
        cout << "Fiction books: " << artTypeCount << ", Technical books: " << technicalTypeCount << endl;
    }
};
int main()
{
    Library lib;
    // добавление книг
    lib.AddBook("Fujimoto", "Chainsaw-man", true, 1);
    lib.AddBook("Koji Miura", "Ao no hako", true, 2);
    lib.AddBook("Dostoevskyi", "", true, 3);
    lib.AddBook("Rowling", "Harry Potter", true, 4);
    lib.AddBook("George Orwell", "1984", true, 5);
    lib.AddBook("Fadke Arun", "Computer relay protections", false, 6);
    lib.AddBook("", "", false, 7);

    // вывод колличества технического типа и литературного
    lib.CountBooksUsingSwitch();
    lib.СountBooksWithoutSwitch();

    return 0;
}
