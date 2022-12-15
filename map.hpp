/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:30:34 by matthieu          #+#    #+#             */
/*   Updated: 2022/12/15 14:17:23 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory>
#include <limits.h>
#include <exception>
#include "map_iterator.hpp"
#include "reverse_iterator.hpp"
#include "lexicographical_compare.hpp"
#include "Tree.hpp"
#include "pair.hpp"

template<
	class Key,
	class T,
	class Compare = std::less<Key>,
	class Allocator = std::allocator<std::pair<const Key, T> >
> class map
{
private:
	typedef _Tree<ft::pair<const Key, T>, Compare, Allocator> _tree_type;
	typedef typename _tree_type::Node _Node;
	_tree_type _tree;
public:
	//member type
	typedef	Key	key_type; //type de la key
	typedef	T	mapped_type; //type de la var stocker
	typedef	ft::pair<const Key, T>	value_type;
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
		_tree = _tree_type(comp, alloc);
	}
	template <class InputIterator>
	map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
	{
		_tree = _tree_type(comp, alloc);
		//insert range
	}
	map (map const &rhs)
	{
		_tree = rhs._tree;
	}
	~map()
	{
	}
	map	&operator=(map const &rhs)
	{
		_tree = rhs._tree;
		return (*this);
	}
	//Element access
		// T& at( const Key& key )
		// {
		// }
		// const T& at( const Key& key ) const
		// {
		// }
		// mapped_type	&operator[]( const Key& key )
		// {
		// }
	//Iterators
		//begin
		//end
		//rbegin
		//rend
	//Capacity
	bool empty() const
	{
		return (_tree.getNbNodes() == 0);
	}
	size_type size() const
	{
		return (_tree.getNbNodes());
	}
	size_type max_size() const
	{
		return (_tree.getAlloc().max_size());
	}
	//Modifiers
	//clear
	//Erases all elements from the container. After this call, size() returns zero.
	void clear()
	{
	}
	//insert
	//Inserts value.
	std::pair<iterator, bool> insert( const value_type& value )
	{
	}
	//Inserts elements from range [first, last). If multiple elements in the range have keys that compare
	//equivalent, it is unspecified which element is inserted (pending LWG2844).
	template< class InputIt >
	void insert( InputIt first, InputIt last )
	{
	}
	//erase
	//Removes the element at pos.
	iterator erase( iterator pos )
	{
	}
	//Removes the element (if one exists) with the key equivalent to key.
	size_type erase( const Key& key )
	{
	}
	//swap
	//Exchanges the contents of the container with those of other.
	//Does not invoke any move, copy, or swap operations on individual elements.
	//All iterators and references remain valid. The past-the-end iterator is invalidated.
	void swap( map& other )
	{
	}
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
