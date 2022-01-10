#include "../header.hpp"

void get_allocator(void)
{
	int psize;
	ft::map<char,int> mymap;
	ft::pair<const char,int>* p;

	// allocate an array of 5 elements using mymap's allocator:
	p=mymap.get_allocator().allocate(5);

	// assign some values to array
	psize = sizeof(ft::map<char,int>::value_type)*5;

	std::cout << "The allocated array has a size of " << psize << " bytes.\n";

	mymap.get_allocator().deallocate(p,5);
}


void equal_range(void)
{
	ft::map<int, std::string> m;
		
		m[0]="zero";
		m[1]="one";
		m[2]="two";

    {
        ft::pair<ft::map<int, std::string>::iterator, ft::map<int, std::string>::iterator> p = m.equal_range(1);
       
	    for (ft::map<int, std::string>::iterator &q = p.first; q != p.second; ++q) {
            std::cout << "m[" << q->first << "] = " << q->second << '\n';
        }
 
        if (p.second == m.find(2)) {
            std::cout << "end of equal_range (p.second) is one-past p.first\n";
        } else {
            std::cout << "unexpected; p.second expected to be one-past p.first\n";
        }
    }
 
    {
        ft::pair<ft::map<int, std::string>::iterator, ft::map<int, std::string>::iterator> pp = m.equal_range(-1);
        if (pp.first == m.begin()) {
            std::cout << "pp.first is iterator to first not-less than -1\n";
        } else {
            std::cout << "unexpected pp.first\n";
        }
 
        if (pp.second == m.begin()) {
            std::cout << "pp.second is iterator to first element greater-than -1\n";
        } else {
            std::cout << "unexpected pp.second\n";
        }
    }
 
    {
        ft::pair<ft::map<int, std::string>::iterator, ft::map<int, std::string>::iterator> ppp = m.equal_range(3);
        if (ppp.first == m.end()) {
            std::cout << "ppp.first is iterator to first not-less than 3\n";
        } else {
            std::cout << "unexpected ppp.first\n";
        }
 
        if (ppp.second == m.end()) {
            std::cout << "ppp.second is iterator to first element greater-than 3\n";
        } else {
            std::cout << "unexpected ppp.second\n";
        }
    }



	ft::map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
	ret = mymap.equal_range('b');

	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';

	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';
}

void lower_bound_upper_bound(void)
{

	ft::map<char,int> mymap;
	ft::map<char,int>::iterator itlow,itup;

	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=60;
	mymap['d']=80;
	mymap['e']=100;

	itlow=mymap.lower_bound ('b');  // itlow points to b
	itup=mymap.upper_bound ('d');   // itup points to e (not d!)

	mymap.erase(itlow,itup);        // erases [itlow,itup)

	// print content:
	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

}

void count(void)
{
	ft::map<char,int> mymap;
	char c;

	mymap ['a']=101;
	mymap ['c']=202;
	mymap ['f']=303;

	for (c='a'; c<'h'; c++)
	{
		std::cout << c;
		if (mymap.count(c)>0)
		std::cout << " is an element of mymap.\n";
		else 
		std::cout << " is not an element of mymap.\n";
	}

}


void find(void)
{
	ft::map<char,int> mymap;
	ft::map<char,int>::iterator it;

	mymap['a']=50;
	mymap['b']=100;
	mymap['c']=150;
	mymap['d']=200;

	it = mymap.find('b');
	if (it != mymap.end())
		mymap.erase (it);

	// print content:
	std::cout << "elements in mymap:" << '\n';
	std::cout << "a => " << mymap.find('a')->second << '\n';
	std::cout << "c => " << mymap.find('c')->second << '\n';
	std::cout << "d => " << mymap.find('d')->second << '\n';
}

// Example module 97 key compare function
struct ModCmp {
    bool operator()(const int lhs, const int rhs) const
    {
        return (lhs % 97) < (rhs % 97);
    }
};

void value_comp(void)
{

	ft::map<char,int> mymap;

	mymap['x']=1001;
	mymap['y']=2002;
	mymap['z']=3003;

	std::cout << "mymap contains:\n";

	ft::pair<char,int> highest = *mymap.rbegin();          // last element

	ft::map<char,int>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mymap.value_comp()(*it++, highest) );

}

void key_comp(void)
{

    ft::map<int, char, ModCmp> cont;
    
	cont[1]='a';
	cont[2]='b';
	cont[3]='c';
	cont[4]='d';
	cont[5]='e';


    ft::map<int, char, ModCmp>::key_compare comp_func = cont.key_comp();
 
    for (ft::map<int, char, ModCmp>::iterator it = cont.begin(); it != cont.end();  it++) {
        bool before = comp_func(it->first, 100);
        bool after = comp_func(100, it->first);
 
        std::cout << '(' << it->first << ',' << it->second;
        if (!before && !after)
            std::cout << ") equivalent to key 100\n";
        else if (before)
            std::cout << ") goes before key 100\n";
        else if (after)
            std::cout << ") goes after key 100\n";
    }

	ft::map<char,int> mymap;

	ft::map<char,int>::key_compare mycomp = mymap.key_comp();

	mymap['a']=100;
	mymap['b']=200;
	mymap['c']=300;

	std::cout << "mymap contains:\n";

	char highest = mymap.rbegin()->first;     // key value of last element

	ft::map<char,int>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mycomp((*it++).first, highest) );

	std::cout << '\n';

}

void clear(void)
{
	ft::map<char,int> mymap;

	mymap['x']=100;
	mymap['y']=200;
	mymap['z']=300;

	std::cout << "mymap contains:\n";
	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	mymap.clear();
	mymap['a']=1101;
	mymap['b']=2202;

	std::cout << "mymap contains:\n";
	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void swap(void)
{

	ft::map<char,int> foo,bar;

	foo['x']=100;
	foo['y']=200;

	bar['a']=11;
	bar['b']=22;
	bar['c']=33;

	foo.swap(bar);

	std::cout << "foo contains:\n";
	for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "bar contains:\n";
	for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

}

void erase(void)
{

	ft::map<char,int> mymap;
	ft::map<char,int>::iterator it;

	// insert some values:
	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	mymap['d']=40;
	mymap['e']=50;
	mymap['f']=60;

	it=mymap.find('b');
	mymap.erase (it);                   // erasing by iterator

	mymap.erase ('c');                  // erasing by key

	it=mymap.find ('e');
	mymap.erase ( it, mymap.end() );    // erasing by range

	// show content:
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

}

void insert(void)
{
	
	
	ft::map<char,int> mymap;

	// first insert function version (single parameter):
	mymap.insert ( ft::pair<char,int>('a',100) );
	mymap.insert ( ft::pair<char,int>('z',200) );

	ft::pair<ft::map<char,int>::iterator,bool> ret;
	ret = mymap.insert ( ft::pair<char,int>('z',500) );
	if (ret.second==false) {
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret.first->second << '\n';
	}

	// second insert function version (with hint position):
	ft::map<char,int>::iterator it = mymap.begin();
	mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
	mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting

	// third insert function version (range insertion):
	ft::map<char,int> anothermap;
	anothermap.insert(mymap.begin(),mymap.find('c'));

	// showing contents:
	std::cout << "mymap contains:\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "anothermap contains:\n";
	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void bracket_operator(void)
{
	ft::map<char,std::string> mymap;

	mymap['a']="an element";
	mymap['b']="another element";
	mymap['c']=mymap['b'];

	std::cout << "mymap['a'] is " << mymap['a'] << '\n';
	std::cout << "mymap['b'] is " << mymap['b'] << '\n';
	std::cout << "mymap['c'] is " << mymap['c'] << '\n';
	std::cout << "mymap['d'] is " << mymap['d'] << '\n';

	std::cout << "mymap now contains " << mymap.size() << " elements.\n";

}


void max_size(void)
{
    ft::map<char,char> s;
    std::cout << "Maximum size of a 'map' is " << s.max_size() << "\n";

	int i;
	ft::map<int,int> mymap;

	if (mymap.max_size()>1000)
	{
		for (i=0; i<1000; i++) mymap[i]=0;
		std::cout << "The map contains 1000 elements.\n";
	}
	else std::cout << "The map could not hold 1000 elements.\n";
}

void size(void)
{
	ft::map<int,char> nums;

	nums[1]='a';
	nums[3]='b';
	nums[5]='c';
	nums[7]='d';

    std::cout << "nums contains " << nums.size() << " elements.\n";
	
	ft::map<char,int> mymap;
	mymap['a']=101;
	mymap['b']=202;
	mymap['c']=302;

	std::cout << "mymap.size() is " << mymap.size() << '\n';


}

void empty(void)
{
    ft::map<int,int> numbers;
    std::cout << std::boolalpha;
    std::cout << "Initially, numbers.empty(): " << numbers.empty() << '\n';
 
    // numbers.emplace(42, 13);
    numbers.insert(ft::make_pair(13317, 123)); 
    std::cout << "After adding elements, numbers.empty(): " << numbers.empty() << '\n';

	ft::map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	while (!mymap.empty())
	{
		std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
		mymap.erase(mymap.begin());
	}
}

void rbegin_rend(void)
{
    ft::map<int, std::string> coins;
	coins[10] = "dime";
	coins[100] = "dollar";
	coins[50] = "half dollar";
	coins[5] = "nickel";
	coins[1] = "penny";
	coins[25] = "quarter";

    std::cout << "US coins in circulation, largest to smallest denomination:\n";
    for (ft::map<int, std::string>::reverse_iterator it = coins.rbegin(); it != coins.rend(); ++it) {
        std::cout << std::setw(11) << it->second << " = ¢" << it->first << '\n';
    }

	ft::map<char,int> mymap;

	mymap['x'] = 100;
	mymap['y'] = 200;
	mymap['z'] = 300;

	// show content:
	ft::map<char,int>::reverse_iterator rit;
	for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
		std::cout << rit->first << " => " << rit->second << '\n';

}

struct Point { double x, y; };
 
//Compare the x-coordinates of two Point pointers
struct PointCmp {
    bool operator()(const Point *lhs, const Point *rhs) const { 
        return lhs->x < rhs->x; 
    }
};

void begin_end(void)
{
	    Point points[3] = { {2, 0}, {1, 0}, {3, 0} };
 
    //mag is a map sending the address of node to its magnitude in the x-y plane
    //Although the keys are pointers-to-Point, we want to order the map by the
    // x-coordinates of the points and NOT by the addresses of the Points. This
    // is done by using the PointCmp class's comparison method.
    ft::map<Point *, double, PointCmp> mag;
 
	mag[points] = 2;
	mag[points + 1] = 1;
	mag[points + 2] = 3;


    //Change each y-coordinate from 0 to the magnitude
    for(ft::map<Point *, double, PointCmp>::iterator iter = mag.begin(); iter != mag.end(); ++iter){
        Point *cur = iter->first; // pointer to Node
        cur->y = mag[cur]; // could also have used  cur->y = iter->second;
    }
 
    //Update and print the magnitude of each node
    for(ft::map<Point *, double, PointCmp>::iterator  iter = mag.begin(); iter != mag.end(); ++iter){
        Point *cur = iter->first;
        mag[cur] = hypot(cur->x, cur->y);
        std::cout << "The magnitude of (" << cur->x << ", " << cur->y << ") is ";
        std::cout << iter->second << '\n';
    }
 	
	ft::map<int, float> num_map;
	num_map[4] = 4.13;
	num_map[9] = 9.24;
	num_map[1] = 1.09;
	// calls a_map.begin() and a_map.end()
	for (ft::map<int, float>::iterator it = num_map.begin(); it != num_map.end(); ++it) {
		std::cout << it->first << ", " << it->second << '\n';
	}
	ft::map<char,int> mymap;

	mymap['b'] = 100;
	mymap['a'] = 200;
	mymap['c'] = 300;

	// show content:
	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it) {
		std::cout << it->first << " => " << it->second << '\n';
	}
}	

void display_sizes(const ft::map<int, int> &nums1,
                   const ft::map<int, int> &nums2,
                   const ft::map<int, int> &nums3)
{
    std::cout << "nums1: " << nums1.size() 
              << " nums2: " << nums2.size()
              << " nums3: " << nums3.size() << '\n';
}
 


void equal_operator(void)
{
	ft::map<int, int> nums1;

	nums1[3] = 1;
	nums1[4] = 1;
	nums1[5] = 9;
	nums1[6] = 1;
	nums1[7] = 1;
	nums1[8] = 9;

	ft::map<int, int> nums2; 
	ft::map<int, int> nums3;

	std::cout << "Initially:\n";
	display_sizes(nums1, nums2, nums3);

	// copy assignment copies data from nums1 to nums2
	nums2 = nums1;

	std::cout << "After assigment:\n"; 
	display_sizes(nums1, nums2, nums3);

	// move assignment moves data from nums1 to nums3,
	// modifying both nums1 and nums3
	nums3.swap(nums1);

	std::cout << "After move assigment:\n"; 
	display_sizes(nums1, nums2, nums3);
	
	ft::map<char,int> first;
	ft::map<char,int> second;

	first['x']=8;
	first['y']=16;
	first['z']=32;

	second=first;                // second now contains 3 ints
	first=ft::map<char,int>();  // and first is now empty

	std::cout << "Size of first: " << first.size() << '\n';
	std::cout << "Size of second: " << second.size() << '\n';
}


bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};


void constructors(void)
{

  ft::map<char,int> first;

  first['a']=10;
  first['b']=30;
  first['c']=50;
  first['d']=70;

  ft::map<char,int> second (first.begin(),first.end());

  ft::map<char,int> third (second);

  ft::map<char,int,classcomp> fourth;                 // class as Compare

  bool(*fn_pt)(char,char) = fncomp;
  ft::map<char,int,bool(*)(char,char)> fifth (fn_pt); // func

}

void comparison_operators(void)
{

	ft::map<int, char> alice;
    
	alice[1]='a';
	alice[2]='b';
	alice[3]='c';


	ft::map<int, char> bob;
    
	bob[7]='Z';
	bob[8]='Y';
	bob[9]='X';
	bob[10]='W';
	
	ft::map<int, char> eve;
 
	eve[1]='a';
	eve[2]='b';
	eve[3]='c';

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

}


void my_map_tests(void)
{
	comparison_operators();
	constructors();
	equal_operator();
	begin_end();
	rbegin_rend();
	empty();
	size();
	max_size();
	bracket_operator();
	insert();
	erase();
	swap();
	clear();
	key_comp();
	value_comp();
	find();
	count();
	lower_bound_upper_bound();
	equal_range();
	get_allocator();

}

int main(void)
{
	my_map_tests();	
	return 0;
}
