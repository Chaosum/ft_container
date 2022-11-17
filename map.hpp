/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:30:34 by matthieu          #+#    #+#             */
/*   Updated: 2022/11/16 17:16:44 by matthieu         ###   ########.fr       */
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
	typedef	Key	key_type;
	typedef	T	mapped_type;
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

};