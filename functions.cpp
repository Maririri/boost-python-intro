#include <typeinfo>

#include "functions.hpp"

namespace intro
{

char const* typeInfo(PyObject* obj)
{
	return typeid(obj).name();
}

}
