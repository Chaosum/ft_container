/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:52:15 by mservage          #+#    #+#             */
/*   Updated: 2022/12/12 21:07:19 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{
	template<class T1, class T2>
	struct pair
	{
	public:
		typedef T1	first_type;
		typedef	T2	second_type;
		Pair()
		{
			first = first_type();
			second = second_type();
		}
		pair( const T1& x, const T2& y )
		{
			first = x;
			second = y;
		}
		template< class U1, class U2 >
		pair( const pair<U1, U2>& p )
		{
			first = p.first;
			second = p.second;
		}
		~Pair(){}
		pair& operator=( const pair& other )
		{
			first = other.first;
			second = other.second;
		}
		friend bool operator==(pair const & lhs, pair const & rhs) { return lhs.first == rhs.first && lhs.second == rhs.second; }
		friend bool operator!=(pair const & lhs, pair const & rhs) { return !(lhs == rhs); }
		friend bool operator<(pair const & lhs, pair const & rhs) { return lhs.first < rhs.first && lhs.second < rhs.second; }
		friend bool operator>(pair const & lhs, pair const & rhs) { return lhs.first > rhs.first && lhs.second > rhs.second; }
		friend bool operator<=(pair const & lhs, pair const & rhs) { return lhs.first <= rhs.first && lhs.second <= rhs.second; }
		friend bool operator>=(pair const & lhs, pair const & rhs) { return lhs.first >= rhs.first && lhs.second >= rhs.second; }
	private:
		first_type	first;
		second_type	second;
	};
	template <class T1, class T2>
	pair<T1, T2> make_pair(T1 t, T2 u)
	{
		return pair<T1, T2>(t, u);
	}
} // namespace ft