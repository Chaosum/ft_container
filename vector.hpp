/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:33:19 by matthieu          #+#    #+#             */
/*   Updated: 2022/10/04 16:14:06 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <memory>
# include <cstring>
# define _INITIAL_CAPACITY_ 1

namespace ft
{
	template<
		class T,
		class Allocator = std::allocator<T>
	>
	class vector
	{
	public:
		//member types
		typedef	T										value_type;
		typedef	Allocator								allocator_type;
		typedef	std::size_t								size_type;
		typedef	std::ptrdiff_t							difference_type;
		typedef	value_type&								reference;
		typedef	const value_type&						const_reference;
		typedef typename	Allocator::pointer			pointer;
		typedef typename	Allocator::const_pointer	const_pointer;
		// LegacyRandomAccessIterator and LegacyContiguousIterator to value_type	iterator;
		// LegacyRandomAccessIterator and LegacyContiguousIterator to const value_type	const_iterator;
 		typedef	reverse_iterator<iterator>			reverse_iterator;
		typedef	reverse_iterator<const_iterator>	const_reverse_iterator;

		//constructor

		vector(const Allocator& alloc = Allocator()) // 1
		{
			_alloc = alloc;
			_capacity = _INITIAL_CAPACITY_;
			_size = 0;
			_data = _alloc.allocate(_capacity);
		}
		explicit vector( size_type count, const T& value = T(),const Allocator& alloc = Allocator())
		{
			_alloc = alloc;
			_capacity = count;
			_size = count;
			_data = _alloc.allocate(count);
			size_type i = 0;
			while (i < count)
			{
				_alloc.construct(_data + i, value);
				i++;
			}
		}
		vector( const vector& other )
		{
			_alloc = other._alloc;
			_capacity = other._capacity;
			_size = other._size;
			_data = _alloc.allocate(_capacity);
			size_type i = 0;
			while (i  < _size)
			{
				_alloc.construct(_data + i, other._data[i])
				i++;
			}
		}
		~vector()
		{
			size_type i = 0;
			while (i < _size)
			{
				_alloc.destroy(_data + i);
				i++;
			}
			_alloc.deallocate(_data, _capacity);
		}

		//member functions

		vector& operator=( const vector& other ) // operator = assigns values to the container
		{
			size_type i = 0;
			while (i < _size)
			{
				_alloc.destroy(_data + i);
				i++;
			}
			_alloc.deallocate(_data, _capacity);
			_alloc = other._alloc;
			_capacity = other._capacity;
			_size = other._size;
			_data = _alloc.allocate(_capacity);
			size_type i = 0;
			while (i  < _size)
			{
				_alloc.construct(_data + i, other._data[i])
				i++;
			}
			return (*this);
		}
		
		void assign( size_type count, const T& value ) // assign assigns values to the container
		{
			size_type i = 0;
			while (i < _size)
			{
				_alloc.destroy(_data + i);
				i++;
			}
			_alloc.deallocate(_data, _capacity);
			_size = count;
			_capacity = count;
			_data = alloc.allocate(count);
			i = 0;
			while (i < count)
			{
				_alloc.construct(_data + i, value);
				i++;
			}
		}
		template< class InputIt >
		void assign( InputIt first, InputIt last ) // assign assigns values to the container
		{
			size_type i = 0;
			while (i < _size)
			{
				_alloc.destroy(_data + i);
				i++;
			}
			_alloc.deallocate(_data, _capacity);
			_size = last - first;
			_capacity = _size;
			_data = _alloc.allocate(_size);
			i = 0;
			InputIt it = first;
			while (it != last)
			{
				_alloc.construct(_data + i, *it);
				it++;
				i++;
			}
		}
		
		allocator_type get_allocator() const // get_allocator returns the associated allocator
		{
			return (_alloc);
		}
		reference at( size_type pos )
		{
			if (pos >= count)
				throw (std::__throw_out_of_range("vector"));
			return (_data[pos]);
		}
		const_reference at( size_type pos ) const
		{
			if (pos >= count)
				throw (std::__throw_out_of_range("vector"));
			return (_data[pos]);
		}
		
		reference operator[]( size_type pos )
		{
			return (_data[pos]);
		}
		const_reference operator[]( size_type pos ) const
		{
			return (_data[pos]);
		}
		
		reference front()
		{
			return (_data[0]);
		}
		const_reference front() const
		{
			return (_data[0]);
		}
		reference back()
		{
			return (_data[_size - 1]);
		}
		const_reference back() const
		{
			return (_data[_size - 1]);
		}

		T* data()
		{
			return (_data);
		}
		const T* data() const
		{
			return (_data);
		}

		bool empty() const
		{
			return ( _size == 0);
		}
		size_type size() const
		{
			return (_size);
		}
		size_type max_size() const
		{
			return (_alloc.max_size());
		}
		void reserve( size_type new_cap )
		{
			if (new_cap <= _capacity)
				return ;
			pointer temp_data = _alloc.allocate((new_cap));
			memmove(tmp, _data, _size * sizeof(value_type));
			_alloc.deallocate(_data, _capacity);
			_capacity = new_cap;
			_data = tmp;
		}

		size_type capacity() const
		{
			return (_capacity);
		}

		void clear()
		{
			size_type i = 0;
			while (i < _size)
			{
				_alloc.destruct(_data + i);
				i++;
			}
			_size = 0;
		}

		iterator insert( iterator pos, const T& value )
		{
			size_type i = pos - begin();
			if (_size + 1 >= _capacity)
			{
				reserve(_capacity * 2);
				_capacity = _capacity * 2;
			}
			if (i < size)
				memmove(_data + i + 1, data + i, sizeof(value_type) * (size - i));
			_alloc.construct(_data + i, value);
			_size++;
		}
		void insert( iterator pos, size_type count, const T& value )
		{
			size_type i = pos - begin();
			while (_size + count >= _capacity)
			{
				reserve(_capacity * 2);
				_capacity = _capacity * 2;
			}
			if (i < size)
				memmove(_data + i + count, data + i, sizeof(value_type) * (size - i));
			size_type constr = 0;
			_size = _size + count;
			while (count)
			{
				_alloc.construct(_data + i, value);
				i++;
				count--;
			}
		}
		template< class InputIt >
		void insert( iterator pos, InputIt first, InputIt last )
		{
			size_type i = pos - begin();
			size_type count = last - first;
			while (_size + count >= _capacity)
			{
				reserve(_capacity * 2);
				_capacity = _capacity * 2;
			}
			if (i < size)
				memmove(_data + i + count, data + i, sizeof(value_type) * (size - i));
			size_type constr = 0;
			_size = _size + count;
			while (first != last)
			{
				_alloc.construct(_data + i, *first);
				i++;
				first++;
			}
		}
		iterator erase( iterator pos )
		{
			if (pos < begin())
				pos = begin();
			size_type i = pos - begin();
			if (i >= size)
				return (pos);
			_data.destroy(_data + i);
			memmove(_data + i , _data + i + 1, sizeof(value_type) * (size - i - 1));
			_size--;
			return (_data + i);
		}
		iterator erase( iterator first, iterator last )
		{
			if (first < begin() || first > end())
				return first;
			size_type i = first - begin();
			iterator it = first;
			size_type count = 0;
			while (it != last)
			{
				_alloc.destroy(data + i);
				i++;
				it++;
				count++;
			}
			memmove(_data + i - count, _data + i, sizeof(value_type) * count);
			_size = _size - count;
			return (first);
		}

		void push_back( const T& value );
		{
			if (_size + 1 >= _capacity)
			{
				reserve(_capacity * 2);
				_capacity = _capacity * 2;
			}
			iterator it = _data + _size;
			*it = value;
			_size++;
		}

		void pop_back()
		{
			if (_size == 0)
				return ;
			_alloc.destroy(_data + _size - 1);
			_size--;
		}

		void resize(size_type count, T value = T())
		{
			if (_size < count)
			{
				while (_capacity < count)
				{
					reserve(_capacity * 2);
					_capacity = _capacity * 2;
				}
				size_type i = _size;
				while (i < count)
				{
					_alloc.construct(_data + i, value);
					i++;
				}
				_size = count;
			}
			else if (_size > count)
			{
				while (_size != count)
					pop_back();
			}
		}

		void swap( vector& other )
		{
			pointer		tmp_data = this->_data;
			size_type	tmp_size = this->_size;
			size_type	tmp_capacity = this->_capacity;
			Allocator	&tmp_alloc = this->_alloc;

			this->_data = other->_data;
			this->_size = other->_size;
			this->_capacity = other->_capacity ;
			this->_alloc = other->_alloc;

			other->_data = tmp_data;
			other->_size = tmp_size;
			other->_capacity = tmp_capacity;
			other->_alloc = tmp_alloc;
		}

		friend bool operator==( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs );
		friend bool operator!=( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs );
		friend bool operator<( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs );
		friend bool operator<=( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs );
		friend bool operator>( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs );
		friend bool operator>=( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs );

	private:
		pointer		_data;
		size_type	_size;
		size_type	_capacity;
		Allocator	_alloc;
	};

	template< class T, class Alloc >
	void swap( std::vector<T,Alloc>& lhs, std::vector<T,Alloc>& rhs )
	{
		lhs.swap(rhs);
	}
}

#endif