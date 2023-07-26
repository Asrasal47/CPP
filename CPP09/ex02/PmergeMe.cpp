#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	std::cout << "U should not see this" << std::endl;
}

PmergeMe::PmergeMe(PmergeMe const & copy)
{
	std::cout << "U should not see this" << std::endl;
	(void)copy;
}

PmergeMe&	PmergeMe::operator=(PmergeMe const & copy)
{
	std::cout << "U should not see this" << std::endl;
	(void)copy;
	return (*this);
}

PmergeMe::~PmergeMe()
{
	std::cout << "U should not see this" << std::endl;
}

static void mergeVec(std::vector<int>& vec, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = vec[left + i];

    for (int j = 0; j < n2; ++j)
        R[j] = vec[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vec[k] = L[i];
            ++i;
        } else {
            vec[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        vec[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        vec[k] = R[j];
        ++j;
        ++k;
    }
}

void	PmergeMe::mergeInsertionSortVec(std::vector<int>& vec, int left, int right)
{
    const int THRESHOLD = 16;

    if (left < right) {
        if (right - left <= THRESHOLD) {
            for (int i = left + 1; i <= right; ++i) {
                int key = vec[i];
                int j = i - 1;

                while (j >= left && vec[j] > key) {
                    vec[j + 1] = vec[j];
                    --j;
                }

                vec[j + 1] = key;
            }
        } else {
            int mid = (left + right) / 2;
            mergeInsertionSortVec(vec, left, mid);
            mergeInsertionSortVec(vec, mid + 1, right);
            mergeVec(vec, left, mid, right);
        }
    }
}

static void mergeQue(MyQue<int>& q, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    MyQue<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = q[left + i];

    for (int j = 0; j < n2; ++j)
        R[j] = q[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            q[k] = L[i];
            ++i;
        } else {
            q[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        q[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        q[k] = R[j];
        ++j;
        ++k;
    }
}

void	PmergeMe::mergeInsertionSortQue(MyQue<int>& q, int left, int right)
{
    const int THRESHOLD = 16;

    if (left < right) {
        if (right - left <= THRESHOLD) {
            for (int i = left + 1; i <= right; ++i) {
                int key = q[i];
                int j = i - 1;

                while (j >= left && q[j] > key) {
                    q[j + 1] = q[j];
                    --j;
                }

                q[j + 1] = key;
            }
        } else {
            int mid = (left + right) / 2;
            mergeInsertionSortQue(q, left, mid);
            mergeInsertionSortQue(q, mid + 1, right);
            mergeQue(q, left, mid, right);
        }
    }
}
