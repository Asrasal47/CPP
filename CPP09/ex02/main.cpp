#include "PmergeMe.hpp"
#include <sys/time.h>
#include <iomanip>

static bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

static	std::vector<int>	loadVec(int argc, char** argv)
{
	std::vector<int>	args;
	int nb;
	for (int i = 1; i < argc; i++)
	{
		nb = atoi(argv[i]);
		if (std::find(args.begin(), args.end(), nb) != args.end())
			continue;
		args.push_back(nb);
	}
	return args;
}

static	MyQue<int>	loadQue(int argc, char** argv)
{
	MyQue<int> args;

    for (int i = 1; i < argc; ++i) {
        int nb = atoi(argv[i]);
        bool duplicate = false;
        for (size_t j = 0; j < args.size(); ++j) {
            if (args[j] == nb) {
                duplicate = true;
                break;
            }
        }
        if (duplicate) {
            continue;  
        }
        args.push(nb);
    }
    return args;
}


int	main(int argc, char** argv)
{

	if (argc < 2)
	{
		std::cerr << "Usage: PmergeMe <num>*" << std::endl;
		return 1;
	}
	for (int i = 1; i < argc; i++)
	{
		if (!is_number(argv[i]))
		{
			std::cerr << "Error: Invalid input (not a number)" << std::endl;
			return 1;
		}
	}

	clock_t startTime, endTime, diff_vector, diff_queue;

	/*##########################################VECTOR##########################################*/
	startTime = clock();
	std::vector<int>	vec = loadVec(argc, argv);
	std::cout << "Before sorting: ";
    print(vec);
    PmergeMe::mergeInsertionSortVec(vec, 0, vec.size() - 1);
	
	endTime = clock();
	diff_vector = endTime - startTime;
    std::cout << "After sorting: ";
    print(vec);

	if (!sorted(vec))
	{
		std::cerr << "Error: sorting the Vector failed for some reason ¯\\\\_(⊙︿⊙)_//¯" << std::endl;
		return 1;
	}
	else
	{
		std::cout << "Vector: Ok " << std::setprecision(7) << (double)diff_vector / CLOCKS_PER_SEC << "s" << std::endl;
	}

	/*##########################################QUEUE##########################################*/
	startTime = clock();
	MyQue<int>	q = loadQue(argc, argv);
    PmergeMe::mergeInsertionSortQue(q, 0, q.size() - 1);
	
	endTime = clock();
	diff_queue = endTime - startTime;


	if (!q.sorted())
	{
		std::cerr << "Error: sorting the queue failed for some reason ¯\\\\_(⊙︿⊙)_//¯" << std::endl;
		return 1;
	}
	else
	{
		std::cout << "queue: Ok " << (double)diff_queue / CLOCKS_PER_SEC << "s" << std::endl;
	}
    return 0;
}