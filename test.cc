#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <list>

#include "list_of.hpp"


template <typename T>
class A {
public:
	void print() const
	{
		typename T::const_iterator it = _strings.begin();
		const typename T::const_iterator end_it = _strings.end();

		while (it != end_it) {
			std::cout << *it << std::endl;
			++it;
		};
	}

private:
	static const T _strings;
};

template <typename T>
const T A<T>::_strings = list_of<T>("GET")("POST")("PUT");

typedef std::list<std::string> StringList;
typedef std::vector<std::string> StringVector;
typedef std::set<std::string> StringSet;

int main(void)
{
	A<StringList> a1;	
	a1.print();

	A<StringVector> a2;
	a2.print();

	A<StringSet> a3;
	a3.print();

	return 0;
}
