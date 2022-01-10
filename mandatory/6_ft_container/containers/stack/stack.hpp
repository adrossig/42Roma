#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <fstream>
#include <list>
#include <stack>

#include "../vector/vector.hpp"
#include "../map/map.hpp"

namespace ft
{
	template <typename T, typename container=ft::vector<T> >
	class stack 
	{
		public:	
			typedef T			value_type;
			typedef container	container_type;
			typedef size_t		size_type;
		
		protected:
			container _c;

		public:
			explicit stack (const container_type& ctnr = container_type())
			:	_c(ctnr) {}
			
			stack(stack const &src)
			{
				_c = src._c;		
			}	

			stack &operator=(stack const &src)
			{
				_c = src._c;
				return *this;
			}

			~stack() {}

			bool empty() const
			{
				return _c.empty();
			}

			size_type size() const
			{
				return _c.size();
			}

			value_type &top()
			{
				return _c.back();
			}

			const value_type &top() const
			{
				return _c.back();
			}

			void push (const value_type& val)
			{
				_c.push_back(val);
			}
			
			void pop()
			{
				_c.pop_back();				
			}
 			
			friend bool operator==( const stack<T,container>& lhs, const stack<T,container>& rhs ) { return (lhs._c == rhs._c);}
			friend bool operator!=( const stack<T,container>& lhs, const stack<T,container>& rhs ) { return (lhs._c != rhs._c);}
			friend bool operator>=( const stack<T,container>& lhs, const stack<T,container>& rhs ) { return (lhs._c >= rhs._c);}
			friend bool operator>( const stack<T,container>& lhs, const stack<T,container>& rhs ) { return (lhs._c > rhs._c);}
			friend bool operator<=( const stack<T,container>& lhs, const stack<T,container>& rhs ) { return (lhs._c <= rhs._c);}
			friend bool operator<( const stack<T,container>& lhs, const stack<T,container>& rhs ) { return (lhs._c < rhs._c);}												
	};
} //ft


#endif
