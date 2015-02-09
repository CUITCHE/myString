#pragma once
#include <iostream>
using std::cout;
using std::cin;
using std::ostream;
using std::istream;
namespace cs2b_mystring{

	class myString
	{
	public:
		//construct empty
		myString(void);
		//constructed by c-string
		myString(const char *rawString);
		//deep-copy;
		myString(const myString &other);
		//operator=
		myString& operator=(const myString &rhs);
		//operator<<
		friend ostream& operator<<(ostream &out, const myString &str);
		//operator>>, skip leading spaces, and end by space,limit length = 127(contains end of sequence)
		friend istream& operator>>(istream &in, myString &str);
		//ready read readyToReadLength sizes from istream-in, and then return size of reading factly
		//limit length = 127(contains end of sequence)
		void read(istream &in, int endOfChar);
		//operator[]
		char& operator[](const size_t pos);
		//operator[]const
		const char& operator[](const size_t pos)const;
		//relational operators
		bool operator<(const myString &rhs)const;
		bool operator<(const char *rhs)const;
		bool operator<=(const myString &rhs)const;
		bool operator<=(const char *rhs)const;
		bool operator>(const myString &rhs)const;
		bool operator>(const char *rhs)const;
		bool operator>=(const myString &rhs)const;
		bool operator>=(const char *rhs)const;
		bool operator==(const myString &rhs)const;
		bool operator==(const char *rhs)const;
		bool operator!=(const myString &rhs)const;
		bool operator!=(const char *rhs)const;
		//friend functins of relational operators
		friend bool operator<(const char* lhs, const myString &rhs){return !(rhs < lhs);}
		friend bool operator<=(const char* lhs, const myString &rhs){return !(rhs <= lhs);}
		friend bool operator>(const char* lhs, const myString &rhs){return !(rhs > lhs);}
		friend bool operator>=(const char* lhs, const myString &rhs){return !(rhs >= lhs);}
		friend bool operator==(const char* lhs, const myString &rhs){return (rhs == lhs);}
		friend bool operator!=(const char* lhs, const myString &rhs){return rhs != lhs;}
		//combine
		myString operator+(const myString &rhs)const;
		myString operator+(const char *rhs)const;
		friend myString operator+(const char* lhs,const myString &rhs);
		
		myString& operator+=(const myString &rhs);
		myString& operator+=(const char *rhs);
		~myString(void);
		size_t length()const;
	protected:
		void construction(const char *src);
		//by address of _raw
		bool equal(const myString &other);
		//return true if _raw is not equal NULL
		bool isValid()const;
	private:
		char *_raw;
	};

}