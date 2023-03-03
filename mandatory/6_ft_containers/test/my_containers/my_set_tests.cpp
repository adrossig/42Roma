#include "../header.hpp"

int intcmp(int int1, int int2) {
	return ((int1 > int2) ? int1 : int2);
}

struct classcomp {
	bool operator()(const char& lhs, const char& rhs) const {
		return lhs < rhs;
	}
};

int main(void)
{
    // SECTION SET TESTS (Bonus)
    std::cout << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "---------------SET TESTS---------------" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    std::cout << std::endl;

    {
        // SECTION constructor()
        std::cout << "----------TESTING constructor()----------" << std::endl;
        ft::set<int> first;
        int myints[] = {10, 20, 30, 40, 50};
        ft::set<int> second(myints, myints + 5);
        ft::set<int> third(second);
        ft::set<int> fourth(second.begin(), second.end());
        ft::set<int, classcomp> fifth;
        int (*fn_pt)(int, int) = intcmp;
        ft::set<int, int (*)(int, int)> sixth(fn_pt);
        //! SECTION
        std::cout << std::endl;
    }

    {
        // SECTION operator=
        std::cout << "----------TESTING operator=----------" << std::endl;
        int myints[] = {12, 82, 37, 64, 15};
        ft::set<int> first(myints, myints + 5);
        ft::set<int> second;
        second = first;
        first = ft::set<int>();
        std::cout << "Size of first: " << int(first.size()) << std::endl;
        std::cout << "Size of second: " << int(second.size()) << std::endl;
        // !SECTION
        std::cout << std::endl;
    }

    {
        // SECTION begin() end()
        std::cout << "----------TESTING begin() end()----------" << std::endl;
        int myints[] = {75, 23, 65, 42, 13};
        ft::set<int> myset(myints, myints + 5);
        std::cout << "myset contains:";
        for (ft::set<int>::iterator it = myset.begin(); it != myset.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << std::endl;
        //! SECTION
        std::cout << std::endl;
    }

    {
        // SECTION rbegin() rend()
        std::cout << "----------TESTING rbegin() rend()----------" << std::endl;
        int myints[] = {21, 64, 17, 78, 49};
        ft::set<int> myset(myints, myints + 5);
        ft::set<int>::reverse_iterator rit;
        std::cout << "myset contains:";
        for (rit = myset.rbegin(); rit != myset.rend(); ++rit)
            std::cout << ' ' << *rit;
        std::cout << std::endl;
        //! SECTION
        std::cout << std::endl;
    }

    {
        // SECTION empty()
        std::cout << "----------TESTING empty()----------" << std::endl;
        ft::set<int> myset;
        myset.insert(20);
        myset.insert(30);
        myset.insert(10);
        std::cout << "myset contains:";
        while (!myset.empty())
        {
            std::cout << ' ' << *myset.begin();
            myset.erase(myset.begin());
        }
        std::cout << std::endl;
        //! SECTION
        std::cout << std::endl;
    }

    {
        // SECTION size()
        std::cout << "----------TESTING size()----------" << std::endl;
        ft::set<int> myints;
        std::cout << "0. size: " << myints.size() << std::endl;
        for (int i = 0; i < 10; ++i)
            myints.insert(i);
        std::cout << "1. size: " << myints.size() << std::endl;
        myints.insert(100);
        std::cout << "2. size: " << myints.size() << std::endl;
        myints.erase(5);
        std::cout << "3. size: " << myints.size() << std::endl;
        // !SECTION
        std::cout << std::endl;
    }

    {
        // SECTION max_size()
        std::cout << "----------TESTING max_size()----------" << std::endl;
        int i;
        ft::set<int> myset;
        if (myset.max_size() > 1000)
        {
            for (i = 0; i < 1000; i++)
                myset.insert(i);
            std::cout << "The set contains 1000 elements." << std::endl;
        }
        else
            std::cout << "The set could not hold 1000 elements." << std::endl;
        // !SECTION
        std::cout << std::endl;
    }

    {
        // SECTION insert()
        std::cout << "----------TESTING insert()----------" << std::endl;
        ft::set<int> myset;
        ft::set<int>::iterator it;
        ft::pair<ft::set<int>::iterator, bool> ret;
        for (int i = 1; i <= 5; ++i)
            myset.insert(i * 10);
        ret = myset.insert(20);
        if (ret.second == false)
            it = ret.first;
        myset.insert(it, 25);
        myset.insert(it, 24);
        myset.insert(it, 26);
        int myints[] = {5, 10, 15};
        myset.insert(myints, myints + 3);
        std::cout << "myset contains:";
        for (it = myset.begin(); it != myset.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << std::endl;
        //! SECTION
        std::cout << std::endl;
    }
    {
        // SECTION erase()
        std::cout << "----------TESTING erase()----------" << std::endl;
        ft::set<int> myset;
        ft::set<int>::iterator it;
        for (int i = 1; i < 10; i++)
            myset.insert(i * 10);
        it = myset.begin();
        ++it;
        myset.erase(it);
        myset.erase(40);
        it = myset.find(60);
        myset.erase(it, myset.end());
        std::cout << "myset contains:";
        for (it = myset.begin(); it != myset.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << std::endl;
        // !SECTION
        std::cout << std::endl;
    }
    {
        // SECTION swap()
        std::cout << "----------TESTING swap()----------" << std::endl;
        int myints[] = {12, 75, 10, 32, 20, 25};
        ft::set<int> first(myints, myints + 3);
        ft::set<int> second(myints + 3, myints + 6);
        first.swap(second);
        std::cout << "first contains:";
        for (ft::set<int>::iterator it = first.begin(); it != first.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << std::endl;
        std::cout << "second contains:";
        for (ft::set<int>::iterator it = second.begin(); it != second.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << std::endl;
        // !SECTION
        std::cout << std::endl;
    }

    {
        // SECTION clear()
        std::cout << "----------TESTING clear()----------" << std::endl;
        ft::set<int> myset;
        myset.insert(100);
        myset.insert(200);
        myset.insert(300);
        std::cout << "myset contains:";
        for (ft::set<int>::iterator it = myset.begin(); it != myset.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << std::endl;
        myset.clear();
        myset.insert(1101);
        myset.insert(2202);
        std::cout << "myset contains:";
        for (ft::set<int>::iterator it = myset.begin(); it != myset.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << std::endl;
        //! SECTION
        std::cout << std::endl;
    }

    {
        // SECTION key_comp()
        std::cout << "----------TESTING key_comp()----------" << std::endl;
        ft::set<int> myset;
        int highest;
        ft::set<int>::key_compare mycomp = myset.key_comp();
        for (int i = 0; i <= 5; i++)
            myset.insert(i);
        std::cout << "myset contains:";
        highest = *myset.rbegin();
        ft::set<int>::iterator it = myset.begin();
        do
        {
            std::cout << ' ' << *it;
        } while (mycomp(*(++it), highest));
        std::cout << std::endl;
        // !SECTION
        std::cout << std::endl;
    }

    {
        // SECTION value_comp()
        std::cout << "----------TESTING value_comp()----------" << std::endl;
        ft::set<int> myset;
        ft::set<int>::value_compare mycomp = myset.value_comp();
        for (int i = 0; i <= 5; i++)
            myset.insert(i);
        std::cout << "myset contains:";
        int highest = *myset.rbegin();
        ft::set<int>::iterator it = myset.begin();
        do
        {
            std::cout << ' ' << *it;
        } while (mycomp(*(++it), highest));
        std::cout << std::endl;
        // !SECTION
        std::cout << std::endl;
    }

    {
        // SECTION find()
        std::cout << "----------TESTING find()----------" << std::endl;
        ft::set<int> myset;
        ft::set<int>::iterator it;
        for (int i = 1; i <= 5; i++)
            myset.insert(i * 10);
        it = myset.find(20);
        myset.erase(it);
        myset.erase(myset.find(40));
        std::cout << "myset contains:";
        for (it = myset.begin(); it != myset.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << std::endl;
        // !SECTION
        std::cout << std::endl;
    }

    {
        // SECTION count()
        std::cout << "----------TESTING count()----------" << std::endl;
        ft::set<int> myset;
        for (int i = 1; i < 5; ++i)
            myset.insert(i * 3);
        for (int i = 0; i < 10; ++i)
        {
            std::cout << i;
            if (myset.count(i) != 0)
                std::cout << " is an element of myset." << std::endl;
            else
                std::cout << " is not an element of myset." << std::endl;
        }
        // !SECTION
        std::cout << std::endl;
    }

    {
        // SECTION lower_bound() upper_bound()
        std::cout << "----------TESTING lower_bound() upper_bound()----------" << std::endl;
        ft::set<int> myset;
        ft::set<int>::iterator itlow, itup;
        for (int i = 1; i < 10; i++)
            myset.insert(i * 10);
        itlow = myset.lower_bound(30);
        itup = myset.upper_bound(60);
        myset.erase(itlow, itup);
        std::cout << "myset contains:";
        for (ft::set<int>::iterator it = myset.begin(); it != myset.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << std::endl;
        // !SECTION
        std::cout << std::endl;
    }

    {
        // SECTION equal_range()
        std::cout << "----------TESTING equal_range()----------" << std::endl;
        ft::set<int> myset;
        for (int i = 1; i <= 5; i++)
            myset.insert(i * 10);
        ft::pair<ft::set<int>::iterator, ft::set<int>::iterator> ret;
        ret = myset.equal_range(30);
        std::cout << "the lower bound points to: " << *ret.first << std::endl;
        std::cout << "the upper bound points to: " << *ret.second << std::endl;
        // !SECTION
        std::cout << std::endl;
    }

    {
        // SECTION get_allocator()
        std::cout << "----------TESTING get_allocator()----------" << std::endl;
        ft::set<int> myset;
        int *p;
        unsigned int i;
        p = myset.get_allocator().allocate(5);
        for (i = 0; i < 5; i++)
            p[i] = (i + 1) * 10;
        std::cout << "The allocated array contains:";
        for (i = 0; i < 5; i++)
            std::cout << ' ' << p[i];
        std::cout << std::endl;
        myset.get_allocator().deallocate(p, 5);
        // !SECTION
        std::cout << std::endl;
    }
    // !SECTION SET TESTS
    return 0;
}
