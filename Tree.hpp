/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:23:26 by mservage          #+#    #+#             */
/*   Updated: 2022/12/15 19:57:27 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "map.hpp"
namespace ft
{
	template<
		class Key,
		class T,
		class Compare,
		class Allocator>
	class Tree
	{
	private:
			typedef T _value_type;
			typedef typename T::first_type _Key;
			typedef typename T::second_type _mapped_type;
			typedef typename std::size_t _size_type;
			Allocator	_alloc;
			_size_type _nb_nodes;
			Compare const _comp;
	public:
		class Node
		{
		private:
			Node *_left;
			Node *_right;
			Node *_parent;
			_value_type _content;
			_size_type _height;
			_size_type _balance_factor;
		public:
			Node()
			{
				_left = NULL;
				_right = NULL;
				_parent = NULL;
				_height = 0;
				_balance_factor = 0;
			}
			Node(_value_type content)
			{
				_left = NULL;
				_right = NULL;
				_parent = NULL;
				_content = content;
				_height = 0;
				_balance_factor = 0;
			}
			Node(Node const & other)
			{
				_left = other._left;
				_right = other._right;
				_parent = other._parent;
				_content = other._content;
				_height = other._height;
				_balance_factor = other._balance_factor;
			}
			~Node()
			{
			}
		};
		Tree()
		{
			_comp = Compare();
			_alloc = Allocator();
			_root = NULL;
			_nb_nodes = 0;
		}
		Tree(Compare const &comp, Allocator const &alloc)
		{
			_comp = comp;
			_alloc = alloc;
			_alloc = Allocator;
			_root = NULL;
			_nb_nodes = 0;
		}
		~Tree()
		{
			//clean tree
		}
		Allocator const &getAlloc() const
		{
			return (_alloc);
		}
		_size_type const &getNbNodes() const
		{
			return (_nb_nodes);
		}
		Compare const getComp() const
		{
			return (_comp);
		}
		Node	*_insert(value_type const &content)
		{
			if (_root == NULL) //first node
				return (root = createNode());
			_comp
		}
	private:
		Node *_root;
	};
}
