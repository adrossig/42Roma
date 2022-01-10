#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <memory>
#include <limits>

#include "../utils.hpp"
#include "../iterators.hpp"

namespace ft
{
	
	template<class pair>	
	struct link
	{
		pair data;
		struct link *prev;
		struct link *next;
	};	

	template <class pair> 
    class MapIterator : public std::iterator<std::bidirectional_iterator_tag, pair>
	{
		public:
		
		typedef typename std::iterator<std::bidirectional_iterator_tag, pair>::value_type			value_type;
		typedef typename std::iterator<std::bidirectional_iterator_tag, pair>::difference_type		difference_type;
		typedef typename std::iterator<std::bidirectional_iterator_tag, pair>::reference			reference;
		typedef typename std::iterator<std::bidirectional_iterator_tag, pair>::pointer				pointer;
		typedef typename std::iterator<std::bidirectional_iterator_tag, pair>::iterator_category	iterator_category;

		link<pair> *_Ptr; //pointer_type

		public:
			MapIterator() {}
			MapIterator(const MapIterator &to_copy) : _Ptr(to_copy._Ptr) {}
			MapIterator(link<pair> *ptr) : _Ptr(ptr) {}
			
			virtual ~MapIterator() {};

			MapIterator& operator=(const MapIterator& x) { 
				if (&x == this)
					return (*this);
				_Ptr = x._Ptr; return *this; }  

			bool operator==(const MapIterator& other) const 
			{
				
				return _Ptr == other._Ptr; 
			}

			bool operator!=(const MapIterator& other) const 
			{
				return !(*this == other);
			}
			
			MapIterator& operator++() 
			{
				_Ptr = _Ptr->next;
				return *this;
			}

			MapIterator operator++(int) 
			{
				MapIterator iterator = *this;
				operator++();
				return iterator;
			}

			MapIterator& operator--() 
			{
				_Ptr = _Ptr->prev;
				return *this;
			}

			MapIterator operator--(int) 
			{
				MapIterator iterator = *this;
				operator--();
				return iterator;
			}

			reference operator[](int index) 
			{
				for (int i = 0; i < index ; i++)
					_Ptr = _Ptr->next;
				
				return _Ptr->data; 
			}

			reference operator*() 
			{
				return _Ptr->data;
			}			

			pointer operator->()
			{
				return (&(operator*())); 
			}	

			value_type value()
			{
				return (_Ptr); 
			}	

	};
	

	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator< ft::pair<const Key,T> > > 

		class map
		{


			public:
				typedef Key		key_type;
				typedef T 	mapped_type;
				typedef ft::pair<key_type, mapped_type> value_type;
				typedef Compare key_compare;

				/* SRCS: https://www.cplusplus.com/reference/map/map/value_comp/ */
				
				class value_compare : std::binary_function<value_type, value_type, bool>
				{
					friend class map<key_type, mapped_type, key_compare, Alloc>;

					protected:
						Compare comp;
						value_compare (Compare c) : comp(c) {}

					public:
						bool operator() (const value_type& x, const value_type& y) const
						{
							return comp(x.first, y.first);
						}
				};

				typedef link<value_type>			link_type;

				
				typedef Alloc													allocator_type;
				typedef typename allocator_type::reference						reference;
				typedef typename allocator_type::const_reference				const_reference;
				typedef typename allocator_type::pointer						pointer;
				typedef typename allocator_type::const_pointer					const_pointer;
				typedef ft::MapIterator<value_type>								iterator;
				typedef const ft::MapIterator<value_type>							const_iterator;
				typedef	ft::reverse_iterator<iterator>							reverse_iterator;
				typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
				typedef size_t													size_type;

				typedef ptrdiff_t difference_type;

			private:
				typedef typename allocator_type::template rebind<link<value_type> >::other link_allocator;
			
				link_allocator _alloc;
				size_type _Size;
				link<value_type> *_link;


////////////////////////////////////////////////// ITERATORS /////////////////////////////////////////////////////	
			public:

				iterator begin()
				{
					return (iterator(_link->next));
				}

				iterator end()
				{
					return (iterator(_link));
				}

				const_iterator begin() const
				{
					return (const_iterator(_link->next));
				}

				const_iterator end() const
				{
					return (const_iterator(_link));
				}

				reverse_iterator rbegin()
				{
					return reverse_iterator(_link->prev);
				}

				const_reverse_iterator rbegin() const
				{
					return const_reverse_iterator(_link->prev);
				}

				reverse_iterator rend()
				{
					return reverse_iterator(_link);
				}	

				const_reverse_iterator rend() const
				{
					return const_reverse_iterator(_link);	
				}

////////////////////////////////////////////////// CONSTRUCTORS DESTRUCTORS ASSIGNMENT /////////////////////////////////////////////////////			

				explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) // empty
				:  _Size(0)
				{
					(void)alloc;
					(void)comp;
					_link = _alloc.allocate(1);

					_link->next = _link;
					_link->prev = _link;				
				}

				template <class InputIterator> // range
					map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
					{
						(void)alloc;
						(void)comp;
						_link = _alloc.allocate(1);

						_link->next = _link;
						_link->prev = _link;
	
						insert(first, last);
					}

				map (const map& x) : _Size(x._Size)  //copy
				{
					_link = _alloc.allocate(1);

					_link->next = _link;
					_link->prev = _link;

					insert(x.begin(), x.end());
					
				}

				map& operator= (const map& x)
				{
					clear();
					insert(x.begin(), x.end());
					return (*this);
				}

				~map()
				{
					clear();
					_alloc.deallocate(_link, 1);
				}

////////////////////////////////////////////////// CAPACITY FUNCTIONS /////////////////////////////////////////////////////			

				bool empty() const { return(_Size == 0 ? true : false); } 

				size_type size() const { return(_Size); }

				size_type max_size() const { return (link_allocator().max_size()); }

////////////////////////////////////////////////// ELEMENT ACCESS /////////////////////////////////////////////////////			

				mapped_type& operator[] (const key_type& k)
				{
					iterator it = find(k);

					if (it == end())
					{
						insert(ft::make_pair(k, mapped_type()));
						it = find(k);	
						return (it->second);
					}
					return (it->second);
				}

////////////////////////////////////////////////// MODIFIERS /////////////////////////////////////////////////////			

			ft::pair<iterator,bool> insert (const value_type& val) // single element
			{
				link<value_type> *to_add;
				link<value_type> *ptr = _link->next;

				while (ptr != _link && key_compare()(ptr->data.first, val.first) )
					ptr = ptr->next;
				if (ptr != _link && ptr->data.first == val.first)
					return (ft::pair<iterator, bool>(iterator(ptr), false));
				to_add = new_link(val);
				place_link(to_add, ptr);
				_Size++;
				return (ft::pair<iterator, bool>(iterator(to_add), true));
			}

			iterator insert (iterator position, const value_type& val) //with hint
			{
				(void)position;
				ft::pair<iterator, bool> ret = insert(val);
				return (ret.first);
			}
	
			template <class InputIterator>
			void insert (InputIterator first, InputIterator last) // range
			{
				while (first != last)
				{
					insert(*first);
					++first;
				}
			}

    		void erase (iterator position)
			{
				link<value_type> *ptr = position._Ptr;
				ptr->prev->next = ptr->next;
				ptr->next->prev = ptr->prev;
				_alloc.destroy(ptr);
				_alloc.deallocate(ptr, 1);
				_Size--;
			}

			size_type erase (const key_type& k)
			{
				iterator it = find(k);
				if (it != end())
				{
					erase(it);
					return 1;
				}
				return 0;
			}

		    void erase (iterator first, iterator last)
			{
				iterator tmp;

				while (first != last)
				{
					tmp = ++first;
					--first;
					erase(first);
					first = tmp;
				}
			}

			void swap (map& x)
			{
				link_type *link_tmp;
				size_type size_tmp;

				link_tmp = x._link;
				size_tmp = x._Size;

				x._link = _link;
				x._Size = _Size;

				_link = link_tmp;
				_Size = size_tmp;
			}

			void clear()
			{
				erase(begin(), end());
			}			

////////////////////////////////////////////////// OBSERVERS /////////////////////////////////////////////////////			
			key_compare key_comp() const
			{
				return (key_compare());
			}

			value_compare value_comp() const
			{
				return (value_compare(key_compare()));
			}

////////////////////////////////////////////////// OPERATI0NS /////////////////////////////////////////////////////	
			iterator find (const key_type& k)
			{
				for (iterator it = begin(); it != end(); it++)
				{
					if (it->first == k)
						return it;
				}
				return end();			
			}

			const_iterator find (const key_type& k) const
			{
				for (iterator it = begin(); it != end(); it++)
				{
					if (it->first == k)
						return const_iterator(it);
				}
				return end();	
			}

			size_type count (const key_type& k) const
			{
				iterator it = find(k);
				if (it != end())
					return 1;
				return 0;	
			}

			iterator lower_bound (const key_type& k)
			{
				for (iterator it = begin(); it != end(); it++)
				{
					if (!key_compare()(it->first, k))
						return (it);
				}
				return end();
			}
			
			const_iterator lower_bound (const key_type& k) const
			{
				return(const_iterator(lower_bound(k)));
			}
			
			iterator upper_bound (const key_type& k)
			{
				for (iterator it = begin(); it != end(); it++)
				{
					if (key_compare()(k, it->first))
						return (it);
				}
				return end();
			}

			const_iterator upper_bound (const key_type& k) const
			{
				return(const_iterator(upper_bound(k)));
			}

			pair<const_iterator,const_iterator> equal_range (const key_type& k) const
			{
				return (ft::make_pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));
			}
			
			pair<iterator,iterator> equal_range (const key_type& k)
			{
				return (ft::make_pair<iterator, iterator>(lower_bound(k), upper_bound(k)));	
			}

////////////////////////////////////////////////// ALLOCATOR /////////////////////////////////////////////////////	

			allocator_type get_allocator() const { return(_alloc); }
////////////////////////////////////////////////// MY PRIVATE FUNCTIONS /////////////////////////////////////////////////////	

		private:
			link<value_type>	*new_link(const value_type &val)
			{
				link<value_type> *link_to_add = _alloc.allocate(1);
				link<value_type> value;
				value.data = val;
				_alloc.construct(link_to_add, value);
				return (link_to_add);
			}

			void place_link(link<value_type> *link_to_add, link<value_type> *next_link)
			{
				link_to_add->next = next_link;
				link_to_add->prev = next_link->prev;
				next_link->prev->next = link_to_add; 
				next_link->prev = link_to_add;
			}

		};

////////////////////////////////////////////////// RELATIONAL OPERATORS /////////////////////////////////////////////////////	

	template< class Key, class T, class Compare, class Alloc >
		bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
		{
			return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()) );
		}

	template< class Key, class T, class Compare, class Alloc >
		bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
		{
			return (!(lhs == rhs));
		}

	template< class Key, class T, class Compare, class Alloc >
		bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
		{
			return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}

	template< class Key, class T, class Compare, class Alloc >
		bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
		{
			return (!(rhs < lhs));
		}

	template< class Key, class T, class Compare, class Alloc >
		bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
		{
			return (rhs < lhs);
		}

	template< class Key, class T, class Compare, class Alloc >
		bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
		{
			return (!(lhs < rhs));
		}

} // ft

#endif
