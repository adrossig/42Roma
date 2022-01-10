#include "../header.hpp"

void stack_relational_operators(void)
{

	int arr[] = {1, 2, 3};
    ft::vector<int> ali;
	ali.insert(ali.begin(), arr, arr + 3);
    ft::stack<int, ft::vector<int> > alice (ali);  
	
	int arr1[] = {7, 8, 9, 10};
    ft::vector<int> bo;
	bo.insert(bo.begin(), arr1, arr1 + 4);    
    ft::stack<int, ft::vector<int> > bob (bo);  
	
 	int arr2[] = {1, 2, 3};
    ft::vector<int> ev;
	ev.insert(ev.begin(), arr2, arr2 + 3);
    ft::stack<int, ft::vector<int> > eve (ev);  

    std::cout << std::boolalpha;
 
    // Compare non equal containers
    std::cout << "alice == bob returns " << (alice == bob) << '\n';
    std::cout << "alice != bob returns " << (alice != bob) << '\n';
    std::cout << "alice <  bob returns " << (alice < bob) << '\n';
    std::cout << "alice <= bob returns " << (alice <= bob) << '\n';
    std::cout << "alice >  bob returns " << (alice > bob) << '\n';
    std::cout << "alice >= bob returns " << (alice >= bob) << '\n';
 
    std::cout << '\n';
 
    // Compare equal containers
    std::cout << "alice == eve returns " << (alice == eve) << '\n';
    std::cout << "alice != eve returns " << (alice != eve) << '\n';
    std::cout << "alice <  eve returns " << (alice < eve) << '\n';
    std::cout << "alice <= eve returns " << (alice <= eve) << '\n';
    std::cout << "alice >  eve returns " << (alice > eve) << '\n';
    std::cout << "alice >= eve returns " << (alice >= eve) << '\n';
	    std::cout << '\n';

}	


void stack_pop(void)
{
	
	ft::stack<int> mystack;

	for (int i=0; i<5; ++i) mystack.push(i);

	std::cout << "Popping out elements...";
	while (!mystack.empty())
	{
		std::cout << ' ' << mystack.top();
		mystack.pop();
	}
	std::cout << '\n';
}

void stack_push(void)
{
	
	ft::stack<int> mystack;

	for (int i=0; i<5; ++i) mystack.push(i);

	std::cout << "Popping out elements...";
	while (!mystack.empty())
	{
		std::cout << ' ' << mystack.top();
		mystack.pop();
	}
	std::cout << '\n';
}

void stack_top(void)
{
    ft::stack<int>   s;
 
    s.push( 2 );
    s.push( 6 );
    s.push( 51 );
 
    std::cout << s.size() << " elements on stack\n";
    std::cout << "Top element: "
	      << s.top()         // Leaves element on stack
	      << "\n";
    std::cout << s.size() << " elements on stack\n";
    s.pop();
    std::cout << s.size() << " elements on stack\n";
    std::cout << "Top element: " << s.top() << "\n";

	ft::stack<int> mystack;

	mystack.push(10);
	mystack.push(20);

	mystack.top() -= 5;

	std::cout << "mystack.top() is now " << mystack.top() << '\n';
}

void stack_size(void)
{
	std::cout << std::boolalpha;
 
    ft::stack<int> container;
 
    std::cout << "Initially, container.size(): " << container.size() << '\n';
 
    for (int i = 0; i < 7; ++i)
        container.push(i);
    std::cout << "After adding elements, container.size(): " << container.size() << '\n';
	
	ft::stack<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';

	for (int i=0; i<5; i++) myints.push(i);
	std::cout << "1. size: " << myints.size() << '\n';

	myints.pop();
	std::cout << "2. size: " << myints.size() << '\n';

}

void stack_empty(void)
{
    
	std::cout << std::boolalpha;
 
    ft::stack<int> container;
 
    std::cout << "Initially, container.empty(): " << container.empty() << '\n';
 
    container.push(42);
    std::cout << "After adding elements, container.empty(): " << container.empty() << '\n';

	ft::stack<int> mystack;
	int sum (0);

	for (int i=1;i<=10;i++) mystack.push(i);

	while (!mystack.empty())
	{
		sum += mystack.top();
		mystack.pop();
	}

	std::cout << "total: " << sum << '\n';

}

void stack_constructor(void)
{

    ft::stack<int> c1;
    c1.push(5);
    std::cout << c1.size() << '\n';
 
    ft::stack<int, ft::stack<int> > c2(c1);
    std::cout << c2.size() << '\n';
 
    std::deque<int> deq; 
	deq.push_back(3);
	deq.push_back(1);
	deq.push_back(4);
	deq.push_back(1);
	deq.push_back(5);

    ft::stack<int, std::deque<int> > c3(deq);
    std::cout << c3.size() << '\n';

	std::deque<int> mydeque (3,100);          // deque with 3 elements
	ft::vector<int> myvector ((size_t)2,200);        // vector with 2 elements

	ft::stack<int> first;                    // empty stack
	ft::stack<int, std::deque<int> > second (mydeque);         // stack initialized to copy of deque

	ft::stack<int,ft::vector<int> > third;  // empty stack using vector
	ft::stack<int,ft::vector<int> > fourth (myvector);

	std::cout << "size of first: " << first.size() << '\n';
	std::cout << "size of second: " << second.size() << '\n';
	std::cout << "size of third: " << third.size() << '\n';
	std::cout << "size of fourth: " << fourth.size() << '\n';

}


void my_stack_tests(void)
{
	
	stack_constructor();
	stack_empty();
	stack_size();
	stack_top();
	stack_push();
	stack_pop();
	stack_relational_operators();

}

int main(void)
{
	my_stack_tests();
	return 0;
}
