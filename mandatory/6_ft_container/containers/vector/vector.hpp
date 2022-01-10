#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <memory>

#include "../utils.hpp"
#include "../iterators.hpp"

namespace ft
{
		
	template<typename T>
    class VectorIterator : public std::iterator<std::random_access_iterator_tag, T>
	{
		public:
		
		typedef typename std::iterator<std::random_access_iterator_tag, T>::iterator_category	iterator_category;
        typedef std::ptrdiff_t                      difference_type;
		typedef typename T::value_type value_type;
		typedef value_type* pointer;
		typedef value_type& reference;
		typedef size_t                              size_type;

		public:
			VectorIterator() : _Ptr(NULL) {};
			VectorIterator(pointer ptr) : _Ptr(ptr) {};
			VectorIterator(const VectorIterator &cpy) : _Ptr(cpy._Ptr) {};
			virtual ~VectorIterator() {}

			VectorIterator &operator=(const VectorIterator &op)
			{
				if (this == &op)
					return (*this);
				_Ptr = op._Ptr;
				return (*this);
			}

			pointer base() const
			{
				return ((_Ptr));
			}
			
			bool operator==(const VectorIterator& other) const 
			{
				return _Ptr == other._Ptr;
			}

			bool operator!=(const VectorIterator& other) const 
			{
				return !(*this == other);
			}

			pointer operator->() 
			{
				return (&(operator*()));
			}

			reference operator*() 
			{
				return *_Ptr;
			}
			
			VectorIterator& operator++() 
			{
				_Ptr++;
				return *this;
			}

			VectorIterator operator++(int)
			{
				VectorIterator iterator = *this;
				++(*this);
				return iterator;
			}

			VectorIterator& operator--() 
			{
				_Ptr--;
				return *this;
			}

			VectorIterator operator--(int) 
			{
				VectorIterator iterator = *this;
				--(*this);
				return iterator;
			}

			reference operator[](int index)
			{
				return *(_Ptr + index);
			}

			reference operator*() const
			{
				return *_Ptr;
			}			

			VectorIterator operator+(size_t index)
			{	
				return (_Ptr + index); 
			}

			VectorIterator operator-(size_t index)
			{	
				return (_Ptr - index); 
			}

			VectorIterator	operator+=(difference_type n) const
			{
				_Ptr += n;
				return (*this);
			}

			VectorIterator	operator-=(difference_type n) const
			{
				_Ptr -= n;
				return (*this);
			}


		private:
			pointer _Ptr;


	};

	/* SRCS: https://www.youtube.com/watch?v=ryRf4Jh_YC0&t=2173s&ab_channel=TheCherno */

	template <typename T, class Alloc = std::allocator<T> >
    class vector
    {
		public:
			typedef	T							value_type;
			typedef std::allocator<value_type> allocator_type;	
			
			typedef value_type&					reference;
			typedef const value_type&			const_reference;
			typedef value_type*					pointer;
			typedef const value_type*			const_pointer;

			typedef VectorIterator<vector<value_type>	>		iterator;
			typedef const VectorIterator<vector<value_type> >		const_iterator;
			typedef ft::reverse_iterator<iterator >		reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			
			typedef ptrdiff_t difference_type;
			typedef size_t						size_type;


		private:
			T* _Data;
			allocator_type _alloc;
			
			size_t _Size;
			size_t _Capacity;

		public:

////////////////////////////////////////////////// ITERATORS /////////////////////////////////////////////////////	

			iterator begin()
			{
				iterator it(_Data + 1);
				return (it);
			}

			const_iterator			begin() const
			{
				return const_iterator(_Data + 1);
			}

			iterator end()
			{
				return iterator(_Data + _Size + 1);
			}

			const_iterator			end() const
			{
				return (const_iterator(_Data + _Size + 1));
			}

			reverse_iterator rbegin()
			{
				iterator it = end();
				it--;
				return reverse_iterator(it);
			}

			const_reverse_iterator rbegin() const
			{
				iterator it = end();
				it--;
				return const_reverse_iterator(it);
			}

			reverse_iterator rend()
			{
				iterator it = begin();
				it--;
				return reverse_iterator(it); 
			}

			const_reverse_iterator rend() const
			{
				iterator it = begin();
				it--;
				return const_reverse_iterator(it); 
			}			

	    public:

////////////////////////////////////////////////// CONSTRUCTORS DESTRUCTORS ASSIGNMENT /////////////////////////////////////////////////////			

            explicit vector(const allocator_type& alloc = allocator_type()) // default constructor
            {
				(void)alloc;
				_Size = 0;
				_Capacity = 0;
            }

			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) // fill constructor
			{
				(void)alloc;
				_Size = 0;
				_Capacity = 0;
				for (size_type i = 0 ; i < n ; i++)
					push_back(val);
			}

			template <class InputIterator>
				vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) // range constructor
				{
					(void)alloc;
					_Size = 0;
					_Capacity = 0;
					while(first != last)
					{
						push_back(*first);	
						first++;
					}
				} 

			vector (const vector& x) : _alloc(x._alloc) // copy constructor
			{
				_Size = 0;
				_Capacity = 0;

				insert(end(), x.begin(), x.end());
			}

            ~vector()
            {
				clear();
				if (_Capacity > 0)
					_alloc.deallocate(_Data, _Capacity);
            }

 			vector& operator= (const vector& x)
			{
				if (_Size != 0)
					clear();
				insert(end(), x.begin(), x.end());

				return *this;
			} 

////////////////////////////////////////////////// CAPACITY FUNCTIONS /////////////////////////////////////////////////////			

			size_t size() const { return _Size; }

			size_type max_size() const { return (allocator_type().max_size()); }

			void resize (size_type n, value_type val = value_type())
			{
				if (n < _Size)
				{
					while (_Size > n)
						pop_back();
				}
				else if (n > _Size)
				{
					while (_Size < n)
						push_back(val);
				}
			}

			size_type capacity() const { return _Capacity; }

			bool empty() const { return (_Size == 0 ? true : false); }

			void reserve (size_type n) 
			{
				if (n > _Capacity)
					ReAlloc(n); 	
			}

////////////////////////////////////////////////// MODIFIERS /////////////////////////////////////////////////////			

			template <class InputIterator>
  				void assign (InputIterator first, InputIterator last)
				{
					clear();
					insert(end(), first, last);
				} 	

			void assign (size_type n, const value_type& val)
			{
				clear();
				insert(end(), n, val);
			}
			
			void push_back(const value_type& value)
			{
				
				if (_Size >= _Capacity) // allocate memory again only if we have reached the end of data array
				{
					if (_Size == 0)
						ReAlloc(1);
					else
						ReAlloc( (2 * _Capacity));
				}	

				_alloc.construct(&_Data[_Size + 1], value);
				_Size++;	
			}

			void pop_back()
			{
				if (_Size > 0)
				{
					_Size--;
					_alloc.destroy(&_Data[_Size + 1]);
				}
			}

			void clear()
			{
				for (size_t i = 1; i < _Size + 1; i++)
					_alloc.destroy(&_Data[i]);

				_Size = 0;	
			}

			iterator erase(iterator position)
			{
				iterator pos = position;

				while (pos != end())
				{
					_alloc.destroy(&(*(pos)));
					_alloc.construct(&(*pos), *(pos + 1));
					pos++;
				}
				_Size--;
				return (position);
			}

			iterator erase(iterator first, iterator last)
			{
				iterator it = first;

				while (first != last)
				{
					it = erase(it);
					first++;
				}
				return (it);
			}

			iterator insert (iterator position, const value_type& val)
			{
				size_t it_ret = 0;
				for (iterator it = begin(); it != position ; it++)
					it_ret++;
				if (_Size >= _Capacity) // allocate memory again only if we have reached the end of data array
				{
					if (_Size == 0)
					{
						push_back(val);
						return(begin());	
					}
					else
						ReAlloc( (2 * _Capacity));
						
					position = begin();
					for (size_t i = 0; i < it_ret ; i++)
						position++;
				}	
				iterator last = end();
				++_Size;		
				if (last != position)
				{
					while (last != position)
					{
						--last;
						_alloc.construct(&(*(last + 1)), *last);
					}
				}
				_alloc.construct(&(*last), val);
				return (last);
			}

				
    		void insert (iterator position, size_type n, const value_type& val)
			{
				while (n > 0)
				{
					--n;	
					position = insert(position, val);
				}
			}

			template <class InputIterator>
				void insert (iterator position, InputIterator first, InputIterator last)
				{
					while (first != last)
					{
						position = insert(position, *first);
						++first;
						++position;
					}
				}

			void swap (vector& x)
			{
				pointer tmp_data;
				size_t tmp_size;
				size_t tmp_capacity;

				// create tmp object based on x
				tmp_capacity = x._Capacity;
				tmp_size = x._Size;
				tmp_data = _alloc.allocate(tmp_capacity);
				
				for (size_t i = 1; i < tmp_size + 1; i++)
					_alloc.construct(&tmp_data[i], x._Data[i]);

				// destroy and deallocate x, and build it again based on this
				for (size_t i = 1; i < x._Size + 1; i++)
					_alloc.destroy(&x._Data[i]);	

				_alloc.deallocate(x._Data, x._Capacity);
				
				x._Size = _Size;
				x._Capacity = _Capacity;

				if (x._Capacity > 0)
				{
				x._Data = _alloc.allocate(x._Capacity);
				for (size_t i = 1; i < x._Size + 1; i++)
					_alloc.construct(&x._Data[i], _Data[i]);
				}
				// destroy and deallocate this, and point them toward tmp
				for (size_t i = 1; i < _Size + 1; i++)
					_alloc.destroy(&_Data[i]);	

				_alloc.deallocate(_Data, _Capacity);
				
				_Size = tmp_size;
				_Capacity = tmp_capacity;
				_Data = tmp_data;

			}
			
////////////////////////////////////////////////// ALLOCATOR /////////////////////////////////////////////////////			
			allocator_type get_allocator() const
			{
				allocator_type alloc_copy(_alloc);
				return alloc_copy;
			}

////////////////////////////////////////////////// ELEMENT ACCESS /////////////////////////////////////////////////////			

		const_reference operator[] (size_type n) const
		{
			return _Data[n + 1];
		}

		reference operator[] (size_type n)
		{
			return _Data[n + 1];
		}

		const_reference at (size_type n) const
		{
			if (n >= _Size || n < 0)
				throw std::out_of_range("vector");
			return _Data[n + 1];
		}

		reference at (size_type n)
		{
			if (n >= _Size || n < 0)
				throw std::out_of_range("vector");
			return _Data[n + 1];
		}

		reference front()
		{
			return *(_Data + 1);
		}

		const_reference front() const
		{
			return *(_Data + 1);
		}

		reference back()
		{
			return *(_Data + _Size);
		}

		const_reference back() const
		{
			return *(_Data + _Size);
		}		

////////////////////////////////////////////////// MY FUNCTIONS /////////////////////////////////////////////////////	
		private:
			void ReAlloc(size_t newCapacity)
			{

				T* newBlock = _alloc.allocate(newCapacity + 2); // +2 for begin and end

				if (newCapacity < _Size)
					_Size = newCapacity;

				for (size_t i = 1; i < _Size + 1; i++)
					_alloc.construct(&newBlock[i], _Data[i]);

				for (size_t i = 1; i < _Size + 1; i++)
					_alloc.destroy(&_Data[i]);

				if (_Size > 0)
					_alloc.deallocate(_Data, _Capacity);
				_Data = newBlock;
				_Capacity = newCapacity;	
			}

	};

////////////////////////////////////////////////// RELATIONAL OPERATORS /////////////////////////////////////////////////////	

	template <class T, class Alloc>
	bool operator== (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()) );
	}

	template <class T, class Alloc>
		bool operator!= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
		{
			return (!(lhs == rhs));
		}

	template <class T, class Alloc>
		bool operator<  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
		{
			return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}

	template <class T, class Alloc>
		bool operator<= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
		{
			return (!(rhs < lhs));
		}

	template <class T, class Alloc>
		bool operator>  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
		{
			return (rhs < lhs);
		}

	template <class T, class Alloc>
		bool operator>= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
		{
			return (!(lhs < rhs));
		}


	template <class T, class Alloc>
		void swap (ft::vector<T,Alloc>& x, ft::vector<T,Alloc>& y)
		{
			x.swap(y);
		}


}


#endif
