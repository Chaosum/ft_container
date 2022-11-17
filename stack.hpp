/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:11:40 by mservage          #+#    #+#             */
/*   Updated: 2022/08/15 16:53:38 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP
#include <deque>

namespace ft{
	template<
		class T,
		class Container = std::deque<T>
	> class stack
	{
	public:
		typedef Container							container_type;
		typedef typename Container::value_type		value_type;
		typedef	typename Container::size_type		size_type;
		typedef	typename Container::reference		reference;
		typedef typename Container::const_reference	const_reference;

		stack(const stack& other){
			c = Container(other);
		}
		explicit stack(const Container& cont = Container()){
			c = cont;
		}
		~stack(){
		}
		stack& operator=(const stack& other){
			c = other.c;
			return *this;
		}
		reference top(){
			return (c.back());
		}
		const_reference top() const{
			return (c.back());
		}
		bool empty() const{
			return (c.empty());
		}
		size_type size() const{
			return (c.size());
		}
		void push(const value_type& value){
			c.push_back(value);
		}
		void pop(){
			c.pop_back();
		}

		friend	bool operator==( const stack& lhs, const stack& rhs ){
			return lhs.c == rhs.c;
		}
		friend	bool operator!=( const stack& lhs, const stack& rhs ){
			return lhs.c != rhs.c;
		}
		friend	bool operator<( const stack& lhs, const stack& rhs ){
			return lhs.c < rhs.c;
		}
		friend	bool operator<=( const stack& lhs, const stack& rhs ){
			return lhs.c <= rhs.c;
		}
		friend	bool operator>( const stack& lhs, const stack& rhs ){
			return lhs.c > rhs.c;
		}
		friend	bool operator>=( const stack& lhs, const stack& rhs ){
			return lhs.c >= rhs.c;
		}

	private:
		Container c;
	};
}

#endif
