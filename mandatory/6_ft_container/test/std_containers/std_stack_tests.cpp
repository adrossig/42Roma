#include "../header.hpp"

void stack_relational_operators(void)
{

	int arr[] = {1, 2, 3};
    std::vector<int> ali;
	ali.insert(ali.begin(), arr, arr + 3);
    std::stack<int, std::vector<int> > alice (ali);  
	
	int arr1[] = {7, 8, 9, 10};
    std::vector<int> bo;
	bo.insert(bo.begin(), arr1, arr1 + 4);    
    std::stack<int, std::vector<int> > bob (bo);  
	
 	int arr2[] = {1, 2, 3};
    std::vector<int> ev;
	ev.insert(ev.begin(), arr2, arr2 + 3);
    std::stack<int, std::vector<int> > eve (ev);  

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
	
	std::stack<int> mystack;

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
	
	std::stack<int> mystack;

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
    std::stack<int>   s;
 
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

	std::stack<int> mystack;

	mystack.push(10);
	mystack.push(20);

	mystack.top() -= 5;

	std::cout << "mystack.top() is now " << mystack.top() << '\n';
}

void stack_size(void)
{
	std::cout << std::boolalpha;
 
    std::stack<int> container;
 
    std::cout << "Initially, container.size(): " << container.size() << '\n';
 
    for (int i = 0; i < 7; ++i)
        container.push(i);
    std::cout << "After adding elements, container.size(): " << container.size() << '\n';
	
	std::stack<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';

	for (int i=0; i<5; i++) myints.push(i);
	std::cout << "1. size: " << myints.size() << '\n';

	myints.pop();
	std::cout << "2. size: " << myints.size() << '\n';

}

void stack_empty(void)
{
    
	std::cout << std::boolalpha;
 
    std::stack<int> container;
 
    std::cout << "Initially, container.empty(): " << container.empty() << '\n';
 
    container.push(42);
    std::cout << "After adding elements, container.empty(): " << container.empty() << '\n';

	std::stack<int> mystack;
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

    std::stack<int> c1;
    c1.push(5);
    std::cout << c1.size() << '\n';
 
    std::stack<int, std::stack<int> > c2(c1);
    std::cout << c2.size() << '\n';
 
    std::deque<int> deq; 
	deq.push_back(3);
	deq.push_back(1);
	deq.push_back(4);
	deq.push_back(1);
	deq.push_back(5);

    std::stack<int, std::deque<int> > c3(deq);
    std::cout << c3.size() << '\n';

	std::deque<int> mydeque (3,100);          // deque with 3 elements
	std::vector<int> myvector ((size_t)2,200);        // vector with 2 elements

	std::stack<int> first;                    // empty stack
	std::stack<int, std::deque<int> > second (mydeque);         // stack initialized to copy of deque

	std::stack<int,std::vector<int> > third;  // empty stack using vector
	std::stack<int,std::vector<int> > fourth (myvector);

	std::cout << "size of first: " << first.size() << '\n';
	std::cout << "size of second: " << second.size() << '\n';
	std::cout << "size of third: " << third.size() << '\n';
	std::cout << "size of fourth: " << fourth.size() << '\n';

}


void std_stack_tests(void)
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
	std_stack_tests();	
	return 0;
}
