#include <iostream>
#include <fstream>
#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/polygon.hpp>
#include <boost/assign/list_of.hpp>

namespace bgeo = boost::geometry;
namespace trans = bgeo::strategy::transform;

typedef bgeo::model::d2::point_xy<double> point;
typedef bgeo::model::polygon<point> polygon;

int main()
{
    polygon poly_original;
    bgeo::exterior_ring(poly_original) = boost::assign::list_of<point>
        (0, 0)
        (1, 1)
        (1, 0)
        (0, 0)
        ;
	
    trans::rotate_transformer<boost::geometry::degree, double, 2, 2> rotate(90.0);

    polygon poly_rotated;
    bgeo::transform(poly_original, poly_rotated, rotate);

	std::ofstream svg("output.svg");
    bgeo::svg_mapper<point> mapper(svg, 400, 400);

    // Add geometries such that all these geometries fit on the map
    mapper.add(poly_original);
	mapper.add(poly_rotated);

    // Draw the geometries on the SVG map, using a specific SVG style
    mapper.map(poly_original, "fill-opacity:0.3;fill:rgb( 51, 51,153);stroke:rgb( 51, 51,153);stroke-width:2");
    mapper.map(poly_rotated , "fill-opacity:0.3;fill:rgb(153,153, 51);stroke:rgb(153,153, 51);stroke-width:2");

	return 0;
}