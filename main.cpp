#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/fusion/include/std_pair.hpp>
#include <boost/spirit/repository/include/qi_seek.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/bind.hpp>
#include <bits/stdc++.h>

//header file to define grammer for parsing
#include "grammer.hpp"	
#include "function.h"
#include "points.h"

int main()
{
	
	std::vector<Point> points;
	function fun;
	bool ans = fun.getPoint("cube.wrl",points);
	
	if(!ans)
	{
		std::cout << "-------------------------------- \n";
        std::cout << "Parsing failed\n";
        std::cout << "-------------------------------- \n";
	}
	else
	{
		std::cout << "-------------------------------- \n";
        std::cout << "Parsing success\n";

        std::cout<<"x         y        z"<<'\n';

        for (int i = 0; i < points.size();i++)
        {
        	std::cout<<points[i].x<<"  "<<points[i].y<<"  "<< points[i].z<<'\n';
        }

        std::cout << "-------------------------------- \n";
	}

	return 0;
}







