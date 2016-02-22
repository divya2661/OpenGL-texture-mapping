#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/fusion/include/std_pair.hpp>
#include <boost/spirit/repository/include/qi_seek.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/bind.hpp>
#include <bits/stdc++.h>


struct Point
{
	double x;
	double y;
	double z;

	Point() : x(0.0), y(0.0), z(0.0){}
};

BOOST_FUSION_ADAPT_STRUCT
(
    Point,
    (double, x) 
    (double, y)
    (double, z)
)

namespace client
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

	      //BOOST_SPIRIT_DEBUG_NODES((prefix)(comment)(singlePoint)(start));
	   }

	   qi::rule<Iterator, Point(), qi::space_type>              singlePoint;
	   qi::rule<Iterator, qi::space_type>                       comment;
	   qi::rule<Iterator, qi::space_type>                       prefix;
	   qi::rule<Iterator, std::vector<Point>(), qi::space_type> start;

	};
}
int main()
{
	namespace qi = boost::spirit::qi;

	std::string input("#this is a comment point
			[2.48695 2.49756 -3.05561,
			 2.48695 5.55317 -3.05561,
			 5.54256 2.49756 -3.05561,
			 2.48695 2.49756 -3.05561]");

    
    std::vector<Point> points;
	client::PointParser<std::string::iterator> g2;
	 

	if(!qi::phrase_parse(input.begin(), input.end(), g2, qi::space,points))
	{
		std::cout << "-------------------------------- \n";
        std::cout << "Parsing failed\n";
        std::cout << "-------------------------------- \n";
	}
	else
	{
		std::cout << "-------------------------------- \n";
        std::cout << "Parsing success\n";

        std::cout<<"x         y         z"<<'\n';

        for (int i = 0; i < points.size();i++)
        {
        	std::cout<<points[i].x<<"  "<<points[i].y<<"  "<< points[i].z<<'\n';
        }

        std::cout << "-------------------------------- \n";
	}

	return 0;
}







