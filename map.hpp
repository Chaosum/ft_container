/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:30:34 by matthieu          #+#    #+#             */
/*   Updated: 2022/12/08 13:06:38 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory>
#include <limits.h>
#include <exception>
#include "map_iterator.hpp"
#include "reverse_iterator.hpp"
#include "lexicographical_compare.hpp"

template<
	class Key,
	class T,
	class Compare = std::less<Key>,
	class Allocator = std::allocator<std::pair<const Key, T>>
> class map
{
	//member type
	typedef	Key	key_type; //type de la key
	typedef	T	mapped_type; //type de la la var stocker
	typedef	std::pair<const Key, T>	value_type;
	typedef	std::size_t	size_type;
	typedef	std::ptrdiff_t	difference_type;
	typedef	Compare	key_compare;
	typedef	Allocator	allocator_type;
	typedef	value_type&	reference;
	typedef	const value_type&	const_reference;
	typedef	typename Allocator::pointer	pointer;
	typedef	typename Allocator::const_pointer	const_pointer;
	typedef	MapIter<T, difference_type>	iterator;
	typedef	MapIter<T, difference_type, const T*, const T&>	const_iterator;
	typedef	ft::reverse_iterator<iterator>				reverse_iterator;
	typedef	ft::reverse_iterator<const_iterator>		const_reverse_iterator;

	//Member functions
	explicit map (const key_compare& comp = key_compare(),	const allocator_type& alloc = allocator_type())
	{
		
	}
	template <class InputIterator>
	map (InputIterator first, InputIterator last,	const key_compare& comp = key_compare(),	const allocator_type& alloc = allocator_type())
	{
	}
	map (const map& x)
	{
	}
	~map()
	map	&operator=()
		//operator=
	//Element access
		//at
		//operator[]
	//Iterators
		//begin
		//end
		//rbegin
		//rend
	//Capacity
		//empty
		//size
		//max_size
	//Modifiers
		//clear
		//insert
		//erase
		//swap
	//Lookup
		//count
		//find
		//equal_range
		//lower_bound
		//upper_bound
	//Observers
		//key_comp
		//value_comp
	//Non-member functions
		//std::swap
		//operator==
};