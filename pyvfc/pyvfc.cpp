#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "vfc.h"

namespace py = pybind11;

PYBIND11_MODULE(pyvfc, m) {
    py::class_<VFC>(m, "VFC")
        .def(py::init())
        .def(py::init<int, int, float, float, float, float, float, float, float>())
        .def("setData", &VFC::setData)
        .def("optimize", &VFC::optimize)
        .def("obtainCorrectMatch", &VFC::obtainCorrectMatch);
}
