#ifndef GRAMMER_H
#define GRAMMER_H

#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/repository/include/qi_seek.hpp>
#include <boost/bind.hpp>
#include <bits/stdc++.h>
#include "points.h"

// struct Point
// {
// 	double x;
// 	double y;
// 	double z;

// 	Point() : x(0.0), y(0.0), z(0.0){}
// };

BOOST_FUSION_ADAPT_STRUCT
(
    Point,
    (double, x) 
    (double, y)
    (double, z)
)


namespace Grammer
{

	namespace qi = boost::spirit::qi;
	namespace repo = boost::spirit::repository;
    template <typename Iterator>

	struct PointParser : public qi::grammar<Iterator, std::vector<Point>(), qi::space_type>
	{

	   PointParser() : PointParser::base_type(start, "PointGrammar")
	   {

	      singlePoint = qi::double_>>qi::double_>>qi::double_>>*qi::lit(",");
	      comment = qi::lit("#")>>*(qi::char_("a-zA-Z.") - qi::eol);
	      prefix = repo::seek[qi::lexeme[qi::skip[qi::lit("point")>>qi::lit("[")>>*comment]]];
	      start %= prefix>>qi::repeat[singlePoint];     
	      	
	   }

	   qi::rule<Iterator, Point(), qi::space_type>              singlePoint;
	   qi::rule<Iterator, qi::space_type>                       comment;
	   qi::rule<Iterator, qi::space_type>                       prefix;
	   qi::rule<Iterator, std::vector<Point>(), qi::space_type> start;

	};
}

#endif