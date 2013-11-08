#include <iostream>
#include <string>

using namespace std;

class Book
{
	friend ostream& operator<<(ostream&, const Book&);
public:
	Book(const string &str=""): bookTitle(str) {}
private:
	string bookTitle;
};

ostream& operator<<(ostream &output, const Book &book)
{
	output << "The title of book: " << book.bookTitle;

	return output;
}

int main()
{
	Book book("C++ primer");

	cout << book << endl;

	return 0;
}
