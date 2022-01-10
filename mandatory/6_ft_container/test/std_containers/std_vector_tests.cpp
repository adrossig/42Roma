#include "../header.hpp"

void std_vec_swap_overload(void)
{
	
	int arr[] = {1, 2, 3};
    std::vector<int> alice;
	alice.insert(alice.begin(), arr, arr + 3);
    
	int arr1[] = {7, 8, 9, 10};
    std::vector<int> bob;
	bob.insert(bob.begin(), arr1, arr1 + 4);   
 
    // auto print = [](const int& n) { std::cout << ' ' << n; };
 
    // Print state before swap
    std::cout << "alice:";
	for (std::vector<int>::iterator it = alice.begin(); it!=alice.end(); ++it)
		std::cout << ' ' << *it;
    std::cout << "\n" "bob  :";
	for (std::vector<int>::iterator it = bob.begin(); it!=bob.end(); ++it)
		std::cout << ' ' << *it;
    std::cout << '\n';
 
    std::cout << "-- SWAP\n";
    std::swap(alice, bob);
 
    // Print state after swap
    std::cout << "alice:";
	for (std::vector<int>::iterator it = alice.begin(); it!=alice.end(); ++it)
		std::cout << ' ' << *it;
    std::cout << "\n" "bob  :";
	for (std::vector<int>::iterator it = bob.begin(); it!=bob.end(); ++it)
		std::cout << ' ' << *it;
    std::cout << '\n';
	
	// unsigned int i;
	std::vector<int> foo ((size_t)3,100);   // three ints with a value of 100
	std::vector<int> bar ((size_t)5,200);   // five ints with a value of 200

	foo.swap(bar);

	std::cout << "foo contains:";
	for (std::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "bar contains:";
	for (std::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

}

void std_vec_relational_operators(void)
{
	int arr[] = {1, 2, 3};
    std::vector<int> alice;
	alice.insert(alice.begin(), arr, arr + 3);
    
	int arr1[] = {7, 8, 9, 10};
    std::vector<int> bob;
	bob.insert(bob.begin(), arr1, arr1 + 4);    
	
 	int arr2[] = {1, 2, 3};
    std::vector<int> eve;
	eve.insert(eve.begin(), arr2, arr2 + 3);

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

	std::vector<int> foo ((size_t)3,100);   // three ints with a value of 100
	std::vector<int> bar ((size_t)2,200);   // two ints with a value of 200

	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

	
}

void std_vec_get_allocator(void)
{
	std::vector<int> myvector;
	int * p;
	unsigned int i;

	// allocate an array with space for 5 elements using vector's allocator:
	p = myvector.get_allocator().allocate(5);

	// construct values in-place on the array:
	for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

	std::cout << "The allocated array contains:";
	for (i=0; i<5; i++) std::cout << ' ' << p[i];
	std::cout << '\n';

	// destroy and deallocate:
	for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
	myvector.get_allocator().deallocate(p,5);
}

void std_vec_clear(void)
{

	int arr[] = {1, 2, 3};
    std::vector<int> container;
	container.insert(container.begin(), arr, arr + 3);

    // auto print = [](const int& n) { std::cout << " " << n; };
 
    std::cout << "Before clear:";
	for (std::vector<int>::iterator e = container.begin() ; e != container.end(); e++) {
        std::cout << " "<< *e  ;
    }

    std::cout << "\nSize=" << container.size() << ", Capacity=" << container.capacity() << '\n';
 
    std::cout << "Clear\n";
    container.clear();
 
    std::cout << "After clear:";
	for (std::vector<int>::iterator e = container.begin() ; e != container.end(); e++) {
        std::cout << " "<< *e  ;
    }

    std::cout << "\nSize=" << container.size() << ", Capacity=" << container.capacity() << '\n';

	std::vector<int> myvector;
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	myvector.clear();
	myvector.push_back (1101);
	myvector.push_back (2202);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
}

void std_vec_swap(void)
{
	std::vector<int> foo ((size_t)3,100);   // three ints with a value of 100
	std::vector<int> bar ((size_t)5,200);   // five ints with a value of 200

	foo.swap(bar);

	std::cout << "foo contains:";
	for (unsigned i=0; i<foo.size(); i++)
		std::cout << ' ' << foo[i];
	std::cout << '\n';

	std::cout << "bar contains:";
	for (unsigned i=0; i<bar.size(); i++)
		std::cout << ' ' << bar[i];
	std::cout << '\n';
}

void std_vec_erase(void)
{
	std::vector<int> c;

    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    c.insert(c.begin(), arr, arr+10);
	for (std::vector<int>::iterator e = c.begin() ; e != c.end(); e++) {
        std::cout << " "<< *e  ;
    }
    std::cout << "\n"; 
 
    c.erase(c.begin());
	for (std::vector<int>::iterator e = c.begin() ; e != c.end(); e++) {
        std::cout << " "<< *e  ;
    }
    std::cout << "\n"; 
 
    c.erase(c.begin()+2, c.begin()+5);
	for (std::vector<int>::iterator e = c.begin() ; e != c.end(); e++) {
        std::cout << " "<< *e  ;
    }
    std::cout << "\n"; 
 
    // Erase all even numbers (C++11 and later)
    for (std::vector<int>::iterator it = c.begin(); it != c.end(); ) {
        if (*it % 2 == 0) {
            it = c.erase(it);
        } else {
            ++it;
        }
    }
	for (std::vector<int>::iterator e = c.begin() ; e != c.end(); e++) {
        std::cout << " "<< *e  ;
    }
    std::cout << "\n"; 
	
	std::vector<int> myvector;

	// set some values (from 1 to 10)
	for (int i=1; i<=10; i++) myvector.push_back(i);

	// erase the 6th element
	myvector.erase (myvector.begin()+5);

	// erase the first 3 elements:
	myvector.erase (myvector.begin(),myvector.begin()+3);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); ++i)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
}

void std_vec_insert(void)
{
	std::vector<int> vec((size_t)3,100);
    for (std::vector<int>::iterator e = vec.begin() ; e != vec.end(); e++) {
        std::cout << " "<< *e  ;
    }
    std::cout << "\n"; 
 
    std::vector<int>::iterator ite = vec.begin();
    ite = vec.insert(ite, 200);
    for (std::vector<int>::iterator e = vec.begin() ; e != vec.end(); e++) {
        std::cout << " "<< *e  ;
    }
    std::cout << "\n"; 
 
    vec.insert(ite,(size_t)2,300);
    for (std::vector<int>::iterator e = vec.begin() ; e != vec.end(); e++) {
        std::cout << " "<< *e  ;
    }
    std::cout << "\n"; 
 
    // "it" no longer valid, get a new one:
    ite = vec.begin();
 
    std::vector<int> vec2((size_t)2,400);
    vec.insert(ite+2, vec2.begin(), vec2.end());
    for (std::vector<int>::iterator e = vec.begin() ; e != vec.end(); e++) {
        std::cout << " "<< *e  ;
    }
    std::cout << "\n"; 
 
    int arr[] = { 501,502,503 };
    vec.insert(vec.begin(), arr, arr+3);
    for (std::vector<int>::iterator e = vec.begin() ; e != vec.end(); e++) {
        std::cout << " "<< *e  ;
    }
    std::cout << "\n"; 
	
	std::vector<int> myvector ((size_t)3,100);
	std::vector<int>::iterator it;

	it = myvector.begin();
	it = myvector.insert ( it , 200 );

	myvector.insert (it,(size_t)2,300);

	// "it" no longer valid, get a new one:
	it = myvector.begin();

	std::vector<int> anothervector ((size_t)2,400);
	myvector.insert (it+2,anothervector.begin(),anothervector.end());

	int myarray [] = { 501,502,503 };
	myvector.insert (myvector.begin(), myarray, myarray+3);

	std::cout << "myvector contains:";
	for (it = myvector.begin(); it != myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void std_vec_pop_back(void)
{
    std::vector<int> numbers;
	std::cout << "[";
    for (std::vector<int>::iterator e = numbers.begin() ; e != numbers.end(); e++) {
        std::cout << " "<< *e  ;
    }
    std::cout << " ]\n"; 
 
    numbers.push_back(5);
    numbers.push_back(3);
    numbers.push_back(4);
 
	std::cout << "[";
    for (std::vector<int>::iterator e = numbers.begin() ; e != numbers.end(); e++) {
        std::cout << " "<< *e  ;
    }
    std::cout << " ]\n"; 
 
    numbers.pop_back();
 
	std::cout << "[";
    for (std::vector<int>::iterator e = numbers.begin() ; e != numbers.end(); e++) {
        std::cout << " "<< *e  ;
    }
    std::cout << " ]\n"; 

	std::vector<int> myvector;
	int sum (0);
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);

	while (!myvector.empty())
	{
		sum+=myvector.back();
		myvector.pop_back();
	}

	std::cout << "The elements of myvector add up to " << sum << '\n';
}

void std_vec_push_back(void)
{
    std::vector<std::string> letters;
 
    letters.push_back("abc");
    std::string s = "def";
    letters.push_back(std::move(s));
 
    std::cout << "vector holds: ";
    for (std::vector<std::string>::iterator e = letters.begin() ; e != letters.end(); e++) std::cout << '\"' << *e << '\"' << ' ';
    std::cout << "\nMoved-from string holds " << '\"' << s << '\"'  << '\n';
}

void std_vec_assign(void)
{
	std::vector<char> characters;
    
	characters.assign(5, 'a');
    for (std::vector<char>::iterator e = characters.begin() ; e != characters.end(); e++) {
        std::cout << *e << ' ' ;
    }
    std::cout << '\n';  	
 
    const std::string extra(6, 'b');
    characters.assign(extra.begin(), extra.end());
    for (std::vector<char>::iterator e = characters.begin() ; e != characters.end(); e++) {
        std::cout << *e << ' ' ;
    }
    std::cout << '\n';  	
	
	std::vector<int> first;
	std::vector<int> second;
	std::vector<int> third;

	first.assign ((size_t)7,100);             // 7 ints with a value of 100

	std::vector<int>::iterator it;
	it=first.begin()+1;

	second.assign (it,first.end()-1); // the 5 central values of first

	int myints[] = {1776,7,4};
	third.assign (myints,myints+3);   // assigning from array.

	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';
	std::cout << "Size of third: " << int (third.size()) << '\n';
}

void std_vec_back(void)
{
    std::vector<char> letters;
  	letters.push_back('a');
	letters.push_back('b');
	letters.push_back('c');
	letters.push_back('d');
	letters.push_back('e');
	letters.push_back('f');	
 
    if (!letters.empty()) {
        std::cout << "The last character is '" << letters.back() << "'.\n";
    }  


	std::vector<int> myvector;

	myvector.push_back(10);

	while (myvector.back() != 0)
	{
		myvector.push_back ( myvector.back() -1 );
	}

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size() ; i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
}

void std_vec_front(void)
{
    std::vector<char> letters;
  	letters.push_back('o');
	letters.push_back('m');
	letters.push_back('g');
	letters.push_back('w');
	letters.push_back('t');
	letters.push_back('f');	
    if (!letters.empty()) {
        std::cout << "The first character is '" << letters.front() << "'.\n";
    } 

	std::vector<int> myvector;

	myvector.push_back(78);
	myvector.push_back(16);

	// now front equals 78, and back 16

	myvector.front() -= myvector.back();

	std::cout << "myvector.front() is now " << myvector.front() << '\n';
}

void std_vec_at(void)
{
    std::vector<int> data;
 	data.push_back(1);
	data.push_back(2);
	data.push_back(4);
	data.push_back(5);
	data.push_back(5);
	data.push_back(6);	

    // Set element 1
    data.at(1) = 88;
 
    // Read element 2
    std::cout << "Element at index 2 has value " << data.at(2) << '\n';
 
    std::cout << "data size = " << data.size() << '\n';
 
    try {
        // Set element 6
        data.at(6) = 666;
    } catch (std::out_of_range const& exc) {
        std::cout << exc.what() << '\n';
    }
 
    // Print final values
    std::cout << "data:";
    for (unsigned i=0; i< data.size(); i++)
        std::cout << " " << data.at(i);
    std::cout << '\n';
  
	std::vector<int> myvector (10);   // 10 zero-initialized ints

	// assign some values:
	for (unsigned i=0; i<myvector.size(); i++)
		myvector.at(i)=i;

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector.at(i);
	std::cout << '\n';
}

void std_vec_bracket_operator(void)
{
    std::vector<int> numbers;
	numbers.push_back(2);
	numbers.push_back(4);
	numbers.push_back(6);
	numbers.push_back(8);	
 
    std::cout << "Second element: " << numbers[1] << '\n';
 
    numbers[0] = 5;
 
    std::cout << "All numbers:";
    for (std::vector<int>::iterator e = numbers.begin() ; e != numbers.end(); e++) {
        std::cout << ' ' << *e;
    }
    std::cout << '\n';

	std::vector<int> myvector (10);   // 10 zero-initialized elements

	std::vector<int>::size_type sz = myvector.size();

	// assign some values:
	for (unsigned i=0; i<sz; i++) myvector[i]=i;

	// reverse vector using operator[]:
	for (unsigned i=0; i<sz/2; i++)
	{
		int temp;
		temp = myvector[sz-1-i];
		myvector[sz-1-i]=myvector[i];
		myvector[i]=temp;
	}

	std::cout << "myvector contains:";
	for (unsigned i=0; i<sz; i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

}

void std_vec_reserve(void)
{
	std::vector<int>::size_type sz;

	std::vector<int> foo;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i=0; i<100; ++i) {
		foo.push_back(i);
		if (sz!=foo.capacity()) {
		sz = foo.capacity();
		std::cout << "capacity changed: " << sz << '\n';
		}
	}

	std::vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100);   // this is the only difference with foo above
	std::cout << "making bar grow:\n";
	for (int i=0; i<100; ++i) {
		bar.push_back(i);
		if (sz!=bar.capacity()) {
		sz = bar.capacity();
		std::cout << "capacity changed: " << sz << '\n';
		}
	}
}

void std_vec_empty(void)
{
	std::cout << std::boolalpha;
    std::vector<int> numbers;
    std::cout << "Initially, numbers.empty(): " << numbers.empty() << '\n';
 
    numbers.push_back(42);
    std::cout << "After adding elements, numbers.empty(): " << numbers.empty() << '\n';
	
	
	std::vector<int> myvector;
	int sum (0);

	for (int i=1;i<=10;i++) myvector.push_back(i);

	while (!myvector.empty())
	{
		sum += myvector.back();
		myvector.pop_back();
	}

	std::cout << "total: " << sum << '\n';
}

void std_vec_capacity(void)
{
    int sz = 200;
    std::vector<int> v1;
 
    size_t cap = v1.capacity();
    std::cout << "initial capacity=" << cap << '\n';
 
    for (int n = 0; n < sz; ++n) {
        v1.push_back(n);
        if (cap != v1.capacity()) {
            cap = v1.capacity();
            std::cout << "new capacity=" << cap << '\n';
        }
    }
 
    std::cout << "final size=" << v1.size() << '\n';
    std::cout << "final capacity=" << v1.capacity() << '\n';
}

void std_vec_resize(void)
{
	std::vector<int> c;
	c.push_back(1);
	c.push_back(2);
	c.push_back(3);
    std::cout << "The vector holds: ";
    for(std::vector<int>::iterator e = c.begin() ; e != c.end(); e++) std::cout << *e << ' ';
    std::cout << '\n';
    c.resize(5);
    std::cout << "After resize up to 5: ";
    for(std::vector<int>::iterator e = c.begin() ; e != c.end(); e++) std::cout << *e << ' ';
    std::cout << '\n';
    c.resize(2);
    std::cout << "After resize down to 2: ";
    for(std::vector<int>::iterator e = c.begin() ; e != c.end(); e++) std::cout << *e << ' ';
    std::cout << '\n';
	
	std::vector<int> myvector;

	// set some initial content:
	for (int i=1;i<10;i++) myvector.push_back(i);

	myvector.resize(5);
	myvector.resize(8,100);
	myvector.resize(12);

	std::cout << "myvector contains:";
	for (size_t i=0;i < myvector.size();i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

}


void std_vec_max_size(void)
{   
	std::vector<char> s;
    std::cout << "Maximum size of a 'vector' is " << s.max_size() << "\n";

	std::vector<int> myvector;

	// set some content in the vector:
	for (int i=0; i<100; i++) myvector.push_back(i);

	std::cout << "size: " << myvector.size() << "\n";
	std::cout << "capacity: " << myvector.capacity() << "\n";
	std::cout << "max_size: " << myvector.max_size() << "\n";

}

void std_vec_size(void)
{
	std::vector<int> nums;
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(5);
	nums.push_back(7);
	
	    std::cout << "nums contains " << nums.size() << " elements.\n";

	std::vector<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';

	for (int i=0; i<10; i++) myints.push_back(i);
	std::cout << "1. size: " << myints.size() << '\n';

	myints.insert (myints.end(),(size_t)10,100);
	std::cout << "2. size: " << myints.size() << '\n';

	myints.pop_back();
	std::cout << "3. size: " << myints.size() << '\n';

}

void std_vec_rbegin_rend(void)
{
	std::vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(4);
	nums.push_back(8);
	nums.push_back(16);	
    std::vector<std::string> fruits;
	fruits.push_back("orange");
	fruits.push_back("apple");
	fruits.push_back("raspberry");
    std::vector<char> empty;
 
    // Print vector.
    for (std::vector<int>::reverse_iterator e = nums.rbegin() ; e != nums.rend(); e++) 
    	std::cout << *e << ' ';
	std::cout << '\n';	
 
    // Sums all integers in the vector nums (if any), printing only the result.
    std::cout << "Sum of nums: "
              << std::accumulate(nums.rbegin(), nums.rend(), 0) << '\n';
 
    // Prints the first fruit in the vector fruits, checking if there is any.
    if (!fruits.empty())
        std::cout << "First fruit: " << *fruits.rbegin() << '\n';
 
    if (empty.rbegin() == empty.rend())
        std::cout << "vector 'empty' is indeed empty.\n";

	std::vector<int> myvector (5);  // 5 default-constructed ints

	int i=0;

	std::vector<int>::reverse_iterator rit = myvector.rbegin();
	for (; rit!= myvector.rend(); ++rit)
		*rit = ++i;

	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void std_vec_begin_end(void)
{
	std::vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(4);
	nums.push_back(8);
	nums.push_back(16);	
    std::vector<std::string> fruits;
	fruits.push_back("orange");
	fruits.push_back("apple");
	fruits.push_back("raspberry");
    std::vector<char> empty;
 
    // Print vector.
    // std::for_each(nums.begin(), nums.end(), [](const int n) { std::cout <<  << ' '; });
	// for
    // std::cout << '\n';
    for (std::vector<int>::iterator e = nums.begin() ; e != nums.end(); e++) 
    	std::cout << *e << ' ';
	std::cout << '\n';	
    // Sums all integers in the vector nums (if any), printing only the result.
    std::cout << "Sum of nums: "
              << std::accumulate(nums.begin(), nums.end(), 0) << '\n';
 
    // Prints the first fruit in the vector fruits, checking if there is any.
    if (!fruits.empty())
        std::cout << "First fruit: " << *fruits.begin() << '\n';
 
    if (empty.begin() == empty.end())
        std::cout << "vector 'empty' is indeed empty.\n";
	
	std::vector<int> myvector;
	for (int i=1; i<=5; i++) myvector.push_back(i);

	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
	std::cout << ' ' << *it;
	std::cout << '\n';

}

void display_sizes(char const* comment,
                   const std::vector<int>& nums1,
                   const std::vector<int>& nums2,
                   const std::vector<int>& nums3)
{
    std::cout << comment
              << " nums1: " << nums1.size() << ','
              << " nums2: " << nums2.size() << ','
              << " nums3: " << nums3.size() << '\n';
}
 
void display(char const* comment, std::vector<int>& v)
{
    std::cout << comment << "{ ";
    for (std::vector<int>::iterator e = v.begin() ; e != v.end(); e++) {
        std::cout << *e << ' ';
    }
    std::cout << "}\n";
}	

void std_vec_equal_operator(void)
{
     std::vector<int> nums1;
	nums1.push_back(3);
	nums1.push_back(1);
	nums1.push_back(4);
	nums1.push_back(6);
	nums1.push_back(5);
	nums1.push_back(9);

    std::vector<int> nums2;
    std::vector<int> nums3;
 
    display_sizes("Initially:\n", nums1, nums2, nums3);
 
    // copy assignment copies data from nums1 to nums2
    nums2 = nums1;
 
    display_sizes("After assignment:\n", nums1, nums2, nums3);
 
    // move assignment moves data from nums1 to nums3,
    // modifying both nums1 and nums3
    nums3.swap(nums1);
 
    display_sizes("After move assignment:\n", nums1, nums2, nums3);
 
    display("Now nums3 = ", nums3);
 
    // copy assignment of an initializer_list copies data to nums3
    nums3.clear();
 	nums3.push_back(1);
	nums3.push_back(2);
	nums3.push_back(3);

    display("After assignment of initializer_list \n nums3 = ", nums3);
  
  
  
  std::vector<int> foo ((size_t)3,0);
  std::vector<int> bar ((size_t)5,0);

  bar = foo;
  foo = std::vector<int>();

  std::cout << "Size of foo: " << int(foo.size()) << '\n';
  std::cout << "Size of bar: " << int(bar.size()) << '\n';
}

void std_vec_constructor(void)
{
	  // constructors used in the same order as described above:
	std::vector<int> first;                                // empty vector of ints
	std::vector<int> second ((size_t)4,100);                       // four ints with value 100
	std::vector<int> third (second.begin(),second.end());  // iterating through second
	std::vector<int> fourth (third);                       // a copy of third

	// the iterator constructor can also be used to construct from arrays:
	int myints[] = {16,2,77,29};
	std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

	std::cout << "The contents of fifth are:";
	for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

}

void std_vector_tests(void)
{
	std_vec_constructor();
	std_vec_equal_operator();
	std_vec_begin_end();
	std_vec_rbegin_rend();
	std_vec_size();
	std_vec_max_size();
	std_vec_resize();
	std_vec_capacity();
	std_vec_empty();
	std_vec_reserve();
	std_vec_bracket_operator();
	std_vec_at();
	std_vec_front();
	std_vec_back();
	std_vec_assign();
	std_vec_push_back();
	std_vec_pop_back();
	std_vec_insert();
	std_vec_erase();
	std_vec_swap();
	std_vec_clear();
	std_vec_get_allocator();
	std_vec_relational_operators();
	std_vec_swap_overload();
}	

int main(void)
{
	std_vector_tests();	
	return 0;
}
