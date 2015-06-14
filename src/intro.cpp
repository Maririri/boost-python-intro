#include <boost/python.hpp>

#include "functions.hpp"

using namespace boost::python;

BOOST_PYTHON_MODULE(intro)
{
	def("type_info", intro::typeInfo);
}
