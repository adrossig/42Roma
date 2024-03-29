#include "../header.hpp"

void	printVector(std::vector<char> *test) {
	for (std::vector<char>::iterator it = test->begin(); it != test->end(); it += 1)
		std::cout << *it << " ";
}

void	printCapacity(std::string mess, std::vector<char> *test) {
	std::cout << "-> Vector size " << mess << " : " << test->size() << std::endl;
	std::cout << "-> Vector max_size " << mess << " : " << test->max_size() << std::endl;
	std::cout << "-> Vector capacity " << mess << " : " << test->capacity() << std::endl;
}

void	testingVectorCapacity(std::vector<char> *test) {
	std::cout << "-> Vector size : " << test->size() << std::endl;
	std::cout << "-> Vector max_size : " << test->max_size() << std::endl;
	std::cout << "-> Vector capacity : " << test->capacity() << std::endl;
	test->resize(2);
	std::cout << "-> After resize (from 4 to 2) : ";
	for (std::vector<char>::iterator it = test->begin(); it != test->end(); it += 1)
		std::cout << *it << " ";
	std::cout << std::endl;
	printCapacity("after resize", test);
	test->resize(6, 'b');
	std::cout << "-> After resize (from 2 to 6, val = 'b') : ";
	for (std::vector<char>::iterator it = test->begin(); it != test->end(); it += 1)
		std::cout << *it << " ";
	std::cout << std::endl;
	printCapacity("after resize", test);
	try {
		test->reserve(8);
		printCapacity("after reserve", test);
	}
	catch (std::length_error &exc) {
		std::cout << std::endl << "-> " <<  exc.what() << std::endl;
	}
}

void	testingVectorIterator(std::vector<char> *test) {
	std::vector<char>::iterator	start = test->begin();
	std::vector<char>::iterator	end = test->end();
	std::vector<char>::reverse_iterator rstart(test->rbegin());
	std::vector<char>::reverse_iterator rend(test->rend());

	std::cout << "-> First element iterator : " << *start << std::endl;
	std::cout << "-> Last element iterator - 1 : " << *end << std::endl;
	std::cout << "-> Vector elements with iterator : ";
	while (start != end)
		std::cout << *start++ << " ";
	std::cout << std::endl;
	std::cout << "-> Vector elements with reverse iterator : ";
	while (rstart != rend)
		std::cout << *rstart++ << " ";
	std::cout << std::endl;
	try {
		std::cout << "-> At of 3 : " << test->at(3) << std::endl;
		std::cout << "-> At of 6 : " << test->at(6) << std::endl;
	}
	catch (std::out_of_range &exc) {
		std::cout << "error " << exc.what() << std::endl;
	}
	std::cout << "-> Front element : " << test->front() << std::endl;
	std::cout << "-> Back element : " << test->back() << std::endl;
}

void	testingVetorModifiers(std::vector<char> *test) {
	test->assign(10, 'c');
	printCapacity("after assign", test);
	std::cout << "-> Vector elements after assign : " << std::endl << "   ";
	printVector(test);
	std::cout << std::endl;
	test->push_back('d');
	printCapacity("after push_back", test);
	std::cout << "-> Vector elements after push_back : " << std::endl << "   ";
	printVector(test);
	std::cout << std::endl;
	test->pop_back();
	printCapacity("after pop_back", test);
	std::cout << "-> Vector elements after pop_back : " << std::endl << "   ";
	printVector(test);

	std::vector<char>::iterator it1 = test->begin();
	test->insert(it1, 'd');
	std::cout << std::endl << "-> Vector elements after insert 'd' at beginning : " << std::endl << "   ";
	printVector(test);
	it1 = test->begin();
	it1 = test->insert(it1 + 10 , 'e');
	std::cout << std::endl << "-> Vector elements after insert 'e' at position 10 : " << std::endl << "   ";
	printVector(test);

	std::vector<char> it2 (5, 'f');
  	test->insert (it1 ,it2.begin(),it2.end());
	std::cout << std::endl << "-> Vector elements after insert 5 types 'f' at end : " << std::endl << "   ";
	printVector(test);
	test->erase(test->begin() + 10);
	it1 = test->begin();
	std::cout << std::endl << "-> Vector elements after erasing 5th element ('e') : " << std::endl << "   ";
	printVector(test);
	test->erase(test->begin() + 1, test->begin() + 11);
	it1 = test->begin();
	std::cout << std::endl << "-> Vector elements after erasing all 'c' : " << std::endl << "   ";
	printVector(test);
	std::cout << std::endl;
}

void	testingVectorAllocator(void) {
	std::vector<int> test;
	int	*new_test = NULL;

	new_test = test.get_allocator().allocate(5);
	for (int idx = 0; idx < 5; idx += 1)
		test.get_allocator().construct(&new_test[idx], idx);
	std::cout << "-> Vector after creation with get_allocator :" << std::endl << "   ";
	for (int idx = 0; idx < 5; idx += 1)
		std::cout << ' ' << new_test[idx];
	std::cout  << std::endl << std::endl;
	for (int idx = 0; idx < 5; idx += 1)
		test.get_allocator().destroy(&new_test[idx]);
	test.get_allocator().deallocate(new_test, 5);
}

void	testingVector(void) {
	std::vector<char>	test1;
	std::vector<char> 	test2(4, 'a');
	std::vector<char>	test3 = test2;
	std::vector<char>	test4(test3.begin(), test3.end());

	std::cout << "------------- [ CAPACITY ] --------------" << std::endl;
	testingVectorCapacity(&test4);
	std::cout << "------------- [ ITERATOR ] --------------" << std::endl;
	testingVectorIterator(&test4);
	std::cout << "------------- [ MODIFIERS ] -------------" << std::endl;
	testingVetorModifiers(&test4);
	std::cout << "------------- [ ALLOCATOR ] -------------" << std::endl;
	testingVectorAllocator();
}
int main(void)
{
	testingVector();
	return 0;
}
