#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "vfc.h"

namespace py = pybind11;

PYBIND11_MODULE(pyvfc, m) {
    py::class_<VFC>(m, "VFC")
        // .def(py::init<>())
        .def(py::init<int, int, float, float, float, float, float, float, float>(), 
            py::arg("method") = 3, py::arg("maxIter") = 50, py::arg("gamma") = 0.9f,
            py::arg("beta") = 0.1f, py::arg("lambda") = 3.0f, py::arg("theta") = 0.75f,
            py::arg("a") = 10.0f, py::arg("ecr") = 1e-5, py::arg("minP") = 1e-5)
        // .def(py::init<int method, int maxIter, float gamma, float beta, float lambda, float theta, float a, float ecr, float minP>())
        .def("setData", &VFC::setData)
        .def("optimize", &VFC::optimize)
        .def("obtainCorrectMatch", &VFC::obtainCorrectMatch);
}
