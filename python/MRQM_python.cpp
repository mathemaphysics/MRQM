#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "MRQM/MRQM.hpp"

namespace py = pybind11;

namespace MRQM {

PYBIND11_MODULE(MRQM, m)
{
  m.doc() = "Python Bindings for MRQM";
  m.def("add_one", &add_one, "Increments an integer value");
}

} // namespace MRQM
