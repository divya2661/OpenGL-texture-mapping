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

std::string function::readFile(std::string fileName){

	std::ifstream ifs;
	ifs.open (fileName.c_str());

	std::string word,file = "";
 
 	while (ifs>>word){
   		file.append(word + " ");
  	}

  ifs.close();

  return file;
}

bool function::getPoint(std::string fileName, std::vector<Point>&result){

	// returnValue returnvalue;
	bool ans;
	namespace qi = boost::spirit::qi;
	std::string file;
	file = readFile(fileName);

	std::string input(file);
    std::vector<Point> points;
    std::vector<Point> v;
	Grammer::PointParser<std::string::iterator> g2;
	bool r  = qi::phrase_parse(input.begin(), input.end(), g2, qi::space,points);

	if(r){
		
		ans = true;
		for (int i = 0; i < points.size();i++)
		{
			result.push_back(points[i]);
		}
		
	}
	else
	{	
		ans = false;
	}
	return ans;
}	
