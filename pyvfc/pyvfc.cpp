#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "vfc.h"

namespace py = pybind11;

PYBIND11_MODULE(pyvfc, m) {
    py::class_<VFC>(m, "VFC")
        .def(py::init())
        // .def(py::init<int, int, float, float, float, float, float, float, float>())
        // .def(py::init<int method, int maxIter, float gamma, float beta, float lambda, float theta, float a, float ecr, float minP>())
        .def("setData", &VFC::setData)
        .def("optimize", &VFC::optimize)
        .def("obtainCorrectMatch", &VFC::obtainCorrectMatch);
}
