#ifndef LIST_OF_HPP
#define LIST_OF_HPP

#include <iterator>
#include <algorithm>

template <typename ContainerType>
class list_of {
	typedef typename ContainerType::value_type ValueType;

public:
	list_of(const ValueType& arg)
	{
		std::fill_n(std::inserter(_container, _container.begin()), 1, arg);
	}

	list_of& operator()(const ValueType& arg)
	{
		std::fill_n(std::inserter(_container, _container.begin()), 1, arg);

		return *this;
	}

	operator ContainerType()
	{
		return _container;
	}

private:
	ContainerType _container;
};

#endif //LIST_OF_HPP
