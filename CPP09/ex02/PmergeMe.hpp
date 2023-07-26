#ifndef PMERGE_HPP
#define PMERGE_HPP

#include <iostream>
#include <vector>
#include <queue>

template<typename T>
class MyQue : public std::queue<T> {
public:
    explicit MyQue(size_t count = 0, const T& value = T()) {
        for (size_t i = 0; i < count; ++i) {
            this->push(value);
        }
    }

    T& operator[](size_t index) {
        if (index >= this->size()) {
            throw std::out_of_range("Index out of range");
        }

        typename std::queue<T>::container_type::iterator it = this->c.begin();
        std::advance(it, index);
        return *it;
    }

    const T& operator[](size_t index) const {
        if (index >= this->size()) {
            throw std::out_of_range("Index out of range");
        }

        typename std::queue<T>::container_type::const_iterator it = this->c.begin();
        std::advance(it, index);
        return *it;
    }

	bool sorted() const {
        if (this->empty()) {
            return true;
        }

        for (size_t i = 1; i < this->size(); ++i) {
            if ((*this)[i] < (*this)[i - 1]) {
                return false;
            }
        }

        return true;
    }
};


class	PmergeMe
{
	private:
	PmergeMe();
	PmergeMe(PmergeMe const & copy);
	PmergeMe&	operator=(const PmergeMe& copy);
	~PmergeMe();

	public:
	static	void    mergeInsertionSortVec(std::vector<int>& vec, int left, int right);
	static	void    mergeInsertionSortQue(MyQue<int>& q, int left, int right);

};	

template<typename T>
bool	sorted(T const & container)
{
	typename T::const_iterator it;
	for (it = container.begin(); it != container.end(); ++it)
	{
		if (it + 1 != container.end() && *it <= *(it + 1))
			continue;
		break;
	}
	if (it + 1 == container.end())
		return true;
	return false;
}

template<typename T>
void	print(T const & vec)
{
	for(int i = 0; i < (int)vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

#endif
