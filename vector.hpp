/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:33:19 by matthieu          #+#    #+#             */
/*   Updated: 2022/09/05 11:54:27 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <memory>

namespace ft
{
	template<
		class T,
		class Allocator = std::allocator<T>
	>
	class vector
	{
	private:

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

		vector()
		{
			
		}
		explicit vector( const Allocator& alloc );
		explicit vector( size_type count, const T& value = T(),const Allocator& alloc = Allocator());
		vector( const vector& other );
		~vector();

		//member functions

		vector& operator=( const vector& other ); // operator = assigns values to the container
		void assign( size_type count, const T& value ); // assign assigns values to the container
		template< class InputIt >
		void assign( InputIt first, InputIt last ); // assign assigns values to the container
		allocator_type get_allocator() const; // get_allocator returns the associated allocator

		reference at( size_type pos );
		const_reference at( size_type pos ) const;
		
		reference operator[]( size_type pos );
		const_reference operator[]( size_type pos ) const;
		
		reference front();
		const_reference front() const;

		reference back();
		const_reference back() const;

		T* data();
		const T* data() const;

		bool empty() const;

		size_type size() const;

		size_type max_size() const;

		void reserve( size_type new_cap );

		size_type capacity() const;

		void clear();

		iterator insert( iterator pos, const T& value );
		void insert( iterator pos, size_type count, const T& value );
		template< class InputIt >
		void insert( iterator pos, InputIt first, InputIt last );

		iterator erase( iterator pos );
		iterator erase( iterator first, iterator last );

		void push_back( const T& value );

		void pop_back();

		void resize( size_type count );
		void resize( size_type count, T value = T() );

		void swap( vector& other );

		friend bool operator==( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs );
		friend bool operator!=( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs );
		friend bool operator<( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs );
		friend bool operator<=( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs );
		friend bool operator>( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs );
		friend bool operator>=( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs );
	};

	template< class T, class Alloc >
	void swap( std::vector<T,Alloc>& lhs, std::vector<T,Alloc>& rhs )
	{
		lhs.swap(rhs);
	}
}

#endif