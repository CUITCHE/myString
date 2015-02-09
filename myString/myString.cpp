#include "myString.h"
#include <string.h>
#include <cassert>
namespace cs2b_mystring{

	myString::myString(void)
		:_raw(NULL)
	{
	}

	myString::myString(const char *rawString)
	{
		construction(rawString);
	}

	myString::myString(const myString &other)
	{
		construction(other._raw);
	}

	void myString::construction(const char *src)
	{
		assert(src!=NULL);
		size_t size = strlen(src)+1;
		_raw = new char[size];
		memcpy(_raw,src,size*sizeof(char));
	}

	ostream& operator<<(ostream &out, const myString &str)
	{
		size_t size = str.length();
		for (size_t i=0; i<size; ++i){
			cout<<str[i];
		}
		cout.flush();
		//or use printf(...);
		return out;
	}

	istream& operator>>(istream &in, myString &str)
	{
		char ch = in.peek();
		//skip leading-space
		while (!in.eof() && (ch == ' ' || ch == '\n')){
			in.get();
			ch = in.peek();
		}
		if (str.isValid()){
			delete[]str._raw;
			str._raw = NULL;
		}
		char readStr[127];
		size_t count = 0;
		while (!in.eof() && (ch != ' ' && ch != '\n') && count < 126){
			in.get();
			readStr[count++] = ch;
			ch = in.peek();
		}
		str._raw = new char[count + 1];
		memcpy(str._raw, readStr, sizeof(char)*count);
		str._raw[count]='\0';
		return in;
	}

	myString::~myString(void)
	{
		if (_raw != NULL){
			delete[]_raw;
		}
	}

	void myString::read(istream &in, int endOfCharh)
	{
		char readStr[127];
		in.getline(readStr, 127, endOfCharh);
		if (_raw != NULL){
			delete[]_raw;
		}
		size_t len = strlen(readStr)+1;
		_raw = new char[len];
		memcpy(_raw,readStr,sizeof(char)*len);

	}

	char& myString::operator[](const size_t pos)
	{
		assert(length()>pos);
		return _raw[pos];
	}

	const char& myString::operator[](const size_t pos) const
	{
		assert(length()>pos);
		return _raw[pos];
	}

	bool myString::operator<(const myString &rhs)const
	{
		return (*this < rhs._raw);
	}

	bool myString::operator<(const char *rhs)const
	{
		if (!isValid() || !rhs){
			return false;
		}
		return strcmp(_raw, rhs)<0;
	}

	bool myString::operator<=(const myString &rhs)const
	{
		return (*this <= rhs._raw);
	}

	bool myString::operator<=(const char *rhs)const
	{
		if (!isValid() || !rhs){
			return false;
		}
		return strcmp(_raw, rhs)<=0;
	}

	bool myString::operator>(const myString &rhs)const
	{
		return !(*this <= rhs);
	}

	bool myString::operator>(const char *rhs)const
	{
		return !(*this <= rhs);
	}

	bool myString::operator>=(const myString &rhs)const
	{
		return !(*this < rhs);
	}

	bool myString::operator>=(const char *rhs)const
	{
		return !(*this < rhs);
	}

	bool myString::operator==(const myString &rhs)const
	{
		return (*this == rhs._raw);
	}

	bool myString::operator==(const char *rhs)const
	{
		if (!isValid() || !rhs){
			return false;
		}
		return strcmp(_raw, rhs)==0;
	}

	bool myString::operator!=(const myString &rhs)const
	{
		return !(*this==rhs);
	}

	bool myString::operator!=(const char *rhs)const
	{
		return !(*this==rhs);
	}

	myString myString::operator+(const myString &rhs)const
	{
		return *this+rhs._raw;
	}

	myString myString::operator+(const char *rhs)const
	{
		size_t first = length();
		size_t second = rhs ? strlen(rhs) : 0;
		size_t totall = first+second+1;
		myString newStr;
		newStr._raw = new char[totall];
		char *p = newStr._raw;
		memcpy(p,_raw,first*sizeof(char));
		memcpy(p+first,rhs,(second)*sizeof(char));
		*(p+totall-1) = '\0';
		return newStr;
	}
	myString operator+(const char* lhs,const myString &rhs)
	{
		myString str(lhs);
		return str+rhs;
	}

	myString& myString::operator+=(const myString &rhs)
	{
		return *this+=rhs._raw;
	}

	myString& myString::operator+=(const char *rhs)
	{
		size_t first = length();
		size_t second = rhs ? strlen(rhs) : 0;
		size_t totall = first+second+1;
		char *newStr = new char[totall];
		memcpy(newStr, _raw, first*sizeof(char));
		memcpy(newStr+first,rhs, second*sizeof(char));
		*(newStr+totall-1) = '\0';
		if (_raw != NULL){
			delete[]_raw;
		}
		_raw = newStr;
		return *this;
	}

	size_t myString::length()const
	{
		return _raw ? strlen(_raw) : 0;
	}

	bool myString::isValid() const
	{
		return _raw!=NULL;
	}

	myString& myString::operator=(const myString &rhs)
	{
		if (this->equal(rhs)){
			return *this;
		}
		if (_raw != NULL){
			delete[]_raw;
		}
		int len = rhs.length();
		_raw = new char[len+1];
		memcpy(_raw, rhs._raw, sizeof(char)*len);
		_raw[len] = '\0';
		return *this;
	}

	bool myString::equal(const myString &other)
	{
		return _raw == other._raw;
	}

}


