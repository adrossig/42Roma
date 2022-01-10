#ifndef UTILS_HPP
#define UTILS_HPP

# include <cstddef>
# include <utility>
# include <iostream>
# include <string>


namespace ft
{
	////////////////////////////////// ENABLE IF /////////////////////////////////////////
	/* SRCS: https://en.cppreference.com/w/cpp/types/enable_if
			 https://riptutorial.com/cplusplus/example/3777/enable-if */

	template<bool B, class T = void>
	struct enable_if {};
	
	template<class T>
	struct enable_if<true, T> { typedef T type; };

	/////////////////////////////////////////// PAIR ////////////////////////////////////////////

	template <class T1, class T2> 
		struct pair
		{
			typedef T1 first_type;
			typedef T2 second_type;

			first_type first;
			second_type second;

			pair() : first(), second() {}

			template<class U, class V> 
				pair(const pair<U,V>& pr) : first(pr.first), second(pr.second) {}

			pair(const first_type& a, const second_type& b) : first(a), second(b) {}
		
			pair& operator= (const pair& pr) { first = pr.first; second = pr.second; return(*this);}


		};

	template <class T1, class T2> //equal compare
  		bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return lhs.first==rhs.first && lhs.second==rhs.second; }

	template <class T1, class T2>
  		bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return !(lhs==rhs); }

	template <class T1, class T2>
  		bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

	template <class T1, class T2>
  		bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return !(rhs<lhs); }

	template <class T1, class T2>
  		bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return rhs<lhs; }

	template <class T1, class T2>
  		bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return !(lhs<rhs); }

	/////////////////////////////////////////// MAKE PAIR ////////////////////////////////////////////
	/* SRCS: https://www.cplusplus.com/reference/utility/make_pair/ */

	template <class T1,class T2>
		pair<T1,T2> make_pair (T1 x, T2 y)
		{
			return ( pair<T1,T2>(x,y) );
		}		  

	/////////////////////////////////////////// EQUAL ////////////////////////////////////////////
	/* SRCS: https://en.cppreference.com/w/cpp/algorithm/equal */

	template <class InputIterator1, class InputIterator2>
		bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
		{
			for (; first1 != last1; ++first1, ++first2) {
				if (!(*first1 == *first2)) {
					return false;
				}
			}
			return true;
		}

	/////////////////////////////////////////// LEXICOGRAPHICAL COMPARE ////////////////////////////////////////////
	/* SRCS: https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare */

	template <class InputIterator1, class InputIterator2>
		bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
		{
			while (first1!=last1)
			{
				if (first2==last2 || *first2<*first1) return false;
				else if (*first1<*first2) return true;
				++first1; ++first2;
			}
			return (first2!=last2);
		}

	/////////////////////////////////////////// IS INTEGRAL ////////////////////////////////////////////
	/* SRCS: https://www.boost.org/doc/libs/1_63_0/boost/type_traits/is_integral.hpp
			 https://stackoverflow.com/questions/43571962/how-is-stdis-integral-implemented */	

	template <class T> struct is_integral : public std::false_type {};

	template<> struct is_integral<bool> : public std::true_type{};
	template<> struct is_integral<char> : public std::true_type{};
	// template<> struct is_integral<char16_t> : public std::true_type{};
	// template<> struct is_integral<char32_t> : public std::true_type{};
	template<> struct is_integral<wchar_t> : public std::true_type{};
	template<> struct is_integral<signed char> : public std::true_type{};
	template<> struct is_integral<short> : public std::true_type{};
	template<> struct is_integral<long> : public std::true_type{};
	template<> struct is_integral<long long> : public std::true_type{};
	template<> struct is_integral<int> : public std::true_type{};
	template<> struct is_integral<unsigned char> : public std::true_type{};
	template<> struct is_integral<unsigned short int> : public std::true_type{};
	template<> struct is_integral<unsigned int> : public std::true_type{};
	template<> struct is_integral<unsigned long int> : public std::true_type{};
	template<> struct is_integral<unsigned long long int> : public std::true_type{};

}

#endif
