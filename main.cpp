/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:02:57 by matthieu          #+#    #+#             */
/*   Updated: 2022/10/31 16:08:12 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "vector.hpp"
#include <vector>

int main()
{
	ft::vector<int> myVec;

	myVec.push_back(5);
	myVec.pop_back();
	myVec.push_back(6);
	myVec.push_back(7);
	myVec.push_back(8);
	ft::vector<int>::iterator it = myVec.begin();
	ft::vector<int>::iterator itend = myVec.end();
	ft::vector<int> myVec2(it, itend);
	std::cout << myVec.size() << std::endl;
	std::cout << myVec.capacity() << std::endl;
	return (0);
}