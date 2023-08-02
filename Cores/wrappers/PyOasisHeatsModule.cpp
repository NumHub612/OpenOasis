#include "Tools/Pybind11/include/pybind11/pybind11.h"
#include "Cores/SystHeats/demo/heats.h"

namespace py = pybind11;


PYBIND11_MODULE(PyOasisHeats, m)
{
    // optional module docstring
    m.doc() = "pybind11 example plugin";
    // expose add function, and add keyword arguments and default arguments
    m.def("plus", &oasis_plus, "test function", py::arg("i") = 1, py::arg("j") = 2);

    // exporting variables
    m.attr("the_answer") = 42;
    py::object world     = py::cast("World");
    m.attr("what")       = world;
}