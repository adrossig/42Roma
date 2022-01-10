#ifndef ITERATORS_HPP
#define ITERATORS_HPP

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <memory>
#include <limits>

namespace ft 
{

	////////////////////////////////// ITERATOR TRAITS /////////////////////////////////////////
	/* SRCS: https://stackoverflow.com/questions/6742008/what-are-the-typical-use-cases-of-an-iterator-trait
			 https://www.boost.org/doc/libs/1_49_0/libs/iterator/doc/iterator_traits.html */
			 
		template <class Iterator>
		struct iterator_traits
		{
			public:
				typedef typename Iterator::value_type			value_type;
				typedef typename Iterator::difference_type		difference_type;
				typedef typename Iterator::pointer				pointer;
				typedef typename Iterator::reference			reference;
				typedef std::random_access_iterator_tag	iterator_category;
		};

		template <class T>
		struct iterator_traits<T*>
		{
			public:
				typedef T								value_type;
				typedef ptrdiff_t						difference_type;
				typedef T*								pointer;
				typedef T&								reference;
				typedef std::random_access_iterator_tag	iterator_category;
		};

		template <class T>
		struct iterator_traits<const T*>
		{
			public:
				typedef T								value_type;
				typedef ptrdiff_t						difference_type;
				typedef T*								pointer;
				typedef T&								reference;
				typedef std::random_access_iterator_tag	iterator_category;
		};

	/////////////////////////////////////////// REVERSE ITERATOR ////////////////////////////////////////////
	/* SRCS: http://www.cplusplus.com/reference/iterator/reverse_iterator/ */

	template <class Iterator> 
		class reverse_iterator 
		{
			/*~~~~~~~~~~~~~~~~ MEMBER TYPES ~~~~~~~~~~~~~~~~~~*/
						
			typedef Iterator iterator_type;
			typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
			typedef typename ft::iterator_traits<Iterator>::reference			reference;			


			
			/*~~~~~~~~~~~~~~~~ CONSTRUCTOR DESTRUCTOR ASSIGNMENT ~~~~~~~~~~~~~~~~~~*/
			
			public:
				reverse_iterator() : _it() {}

				explicit reverse_iterator (iterator_type it) : _it(it) {}		

				explicit reverse_iterator (const pointer p) : _it(p) {}	

				template <class Iter>
					reverse_iterator (const reverse_iterator<Iter>& rev_it) : _it(rev_it.base()) {}
				
				template <class Iter>
					reverse_iterator (const iterator_category& it) : _it(it.base()) {}

				virtual ~reverse_iterator() {};

			/*~~~~~~~~~~~~~~~~ MEMBER FUNCTIONS ~~~~~~~~~~~~~~~~~~*/

				iterator_type base() const
				{
					return (_it);
				}

				reference operator*() const
				{
					iterator_type copy = _it;
					return (*(copy--));
				}

				reverse_iterator operator+ (difference_type n) const
				{
					return (reverse_iterator(_it - n));
				}
				
				reverse_iterator& operator++()
				{
					--_it;
					return (*this);
				}

				reverse_iterator operator++(int)
				{
					reverse_iterator copy = *this;
					++(*this);
					return (copy);
				}

				reverse_iterator& operator+=(difference_type n)
				{
					_it -= n;
					return (*this);
				}

				reverse_iterator operator-(difference_type n) const
				{
					return (reverse_iterator(_it + n));
				}

				reverse_iterator& operator--()
				{
					++_it;
					return (*this);
				}

				reverse_iterator operator--(int)
				{
					reverse_iterator copy = *this;
					--(*this);
					return (copy);
				}

				reverse_iterator& operator-=(difference_type n)
				{
					_it += n;
					return (*this);
				}

				pointer	operator->() const
				{
					return (&(operator*()));
				}

				reference operator[] (difference_type n) const
				{
					return (base()[-n - 1]);
				}

				private:
					iterator_type _it;

		};

	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ NON-MEMBER FUNCTION OVERLOADS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

	template <class Iterator>
		bool operator== (const reverse_iterator<Iterator>& lhs,	const reverse_iterator<Iterator>& rhs)
		{
			return (lhs.base() == rhs.base());
		}

	template <class Iterator>
		bool operator!= (const reverse_iterator<Iterator>& lhs,	const reverse_iterator<Iterator>& rhs)
		{
			return (lhs.base() != rhs.base());
		}

	template <class Iterator>
		bool operator<  (const reverse_iterator<Iterator>& lhs,	const reverse_iterator<Iterator>& rhs)
		{
			return (lhs.base() > rhs.base());
		}

	template <class Iterator>
		bool operator<= (const reverse_iterator<Iterator>& lhs,	const reverse_iterator<Iterator>& rhs)
		{
			return (lhs.base >= rhs.base());
		}

	template <class Iterator>
		bool operator>  (const reverse_iterator<Iterator>& lhs,	const reverse_iterator<Iterator>& rhs)
		{
			return (lhs.base < rhs.base());
		}	

	template <class Iterator>
		bool operator>= (const reverse_iterator<Iterator>& lhs,	const reverse_iterator<Iterator>& rhs)
		{
			return (lhs.base <= rhs.base());
		}

	template <class Iterator>
		reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n,	const reverse_iterator<Iterator>& rev_it)
		{
			return (rev_it + n);
		}

	template <class Iterator>
		typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
		{
			return (lhs.base() - rhs.base());
		}
	
}

#endif
