#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <string>
#include <iostream>
using namespace std;



class Str {
private:
	char* text;
	int size;





public:
	Str() : text{ nullptr }, size{ 0 } {}
	Str(const char* text) {

		this->size = strlen(text);
		this->text = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			this->text[i] = text[i];
		}
		this->text[size] = '\0';
	}
	Str(const Str& str)
	{
		this->size = str.size;
		this->text = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			text[i] = str.text[i];
		}
	}





	friend std::ostream& operator<<(std::ostream& out, const Str& text) {
		out << text.text;
		return out;
	}
	friend std::istream& operator>>(std::istream& in, Str& str)
	{
		str.clear();
		char* tmp = new char[10000];
		in.getline(tmp, 10000);
		str.push_back(tmp);
		return in;
	}



	void push_back(char c) {





		char* tmp = new char[size + 1];
		strncpy(tmp, text, size);
		tmp[size] = c;
		size++;
		delete[] text;
		text = tmp;
		tmp = nullptr;
	}
	void append(int space, char value)
	{
		char* tmp = new char[size + 2];
		strncpy(tmp, text, size);
		char last = tmp[size - 1];


		for (int i = space; i < size; i++)
		{
			tmp[i + 1] = tmp[i];
		}



		tmp[space] = value;
		tmp[size] = last;
		tmp[size + 1] = '\0';
		size++;
		delete[] text;
		text = tmp;
		tmp = nullptr;
	}
	void push_back(const char* c) {
		int NEWsize = size + strlen(c);
		char* tmp = new char[NEWsize + 1];

		strncpy(tmp, text, size);
		strncpy(tmp + size, c, NEWsize - size);


		tmp[NEWsize] = '\0';
		size = NEWsize;
		delete[] text;


		text = tmp;
		tmp = nullptr;
	}
	void replace(int start, int end, const char* value)
	{
		for (int i = start; i <= end; i++)
		{
			text[i] = *value;
		}
	}

	void resize(int newSize) {
		if (newSize < size) {
			char* tmp = new char[newSize + 1];
			strncpy(tmp, text, newSize);
			tmp[newSize] = '\0';
			size = newSize;
			delete[] text;
			text = tmp;
		}
	}

	void push_front(char c) {
		char* tmp = new char[size + 2];
		tmp[0] = c;
		strncpy(tmp + 1, text, size);
		tmp[size + 1] = '\0';
		size++;
		delete[] text;
		text = tmp;
	}

	bool operator==(const Str& str)const
	{
		if (size != str.size)
		{
			return false;
		}


		for (int i = 0; i < size; i++)
		{
			if (text[i] != str.text[i])
			{
				return false;
			}
		}

		return true;
	}
	friend bool operator>(const Str& LeftStr, const Str& rightStr)
	{
		if (rightStr == LeftStr)
		{
			return false;
		}

		int size = LeftStr.size > rightStr.size ? rightStr.size : LeftStr.size;

		int numberLeft = 0;
		int numberRight = 0;


		for (int i = 0; i < size; i++)
		{
			if (LeftStr.text[i] > rightStr.text[i])
			{
				numberLeft++;
			}
			if (LeftStr.text[i] < rightStr.text[i])
			{
				numberRight++;
			}
		}
		return numberLeft > numberRight;

	}
	friend bool operator<(const Str& LeftStr, const Str& rightStr)
	{
		if (rightStr == LeftStr)
		{
			return false;
		}

		int size = LeftStr.size > rightStr.size ? rightStr.size : LeftStr.size;
		int numberLeft = 0;
		int numberRight = 0;
		for (int i = 0; i < size; i++)
		{
			if (LeftStr.text[i] < rightStr.text[i])
			{
				numberLeft++;
			}
			if (LeftStr.text[i] > rightStr.text[i])
			{
				numberRight++;
			}
		}
		return numberLeft > numberRight;

	}

	bool operator>=(const Str& str) const {
		return !(*this < str);
	}

	bool operator<=(const Str& str) const {
		return !(*this > str);
	}
	Str operator+(const Str& strLeft) const {
		Str result = *this;
		result.push_back(strLeft.text);
		return result;
	}
	friend Str operator+(const char* c, const Str& str) {
		Str result(c);
		result.push_back(str.text);
		return result;
	}

	void clear() {
		delete[] text;
		text = nullptr;
		size = 0;
	}
	~Str() { clear(); }
};

int main() {
	Str s1 = "ZZZ";
	Str s2 = "AAAA";

	Str s3 = "Hello";
	Str result = s3 + s1;

	result = "Prepend " + s3;

	s1.resize(2);

	s1.push_front('X');

	if (s1 >= s2) cout << s1 << " is greater than or equal to " << s2 << endl;
	else cout << s1 << " is less than " << s2 << endl;

	if (s2 <= s3) cout << s2 << " is less than or equal to " << s3 << endl;
	else cout << s2 << " is greater than " << s3 << endl;
}