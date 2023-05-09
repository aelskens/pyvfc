#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "vfc.h"

namespace py = pybind11;

PYBIND11_MODULE(pyvfc, m) {
    py::class_<VFC>(m, "VFC", R"mydelimiter(Class that implements the VFC algorithm. \n:param method: The method for outlier removal. The options are 1 for NORMAL_VFC, 2 for FAST_VFC \nand 3 for SPARSE_VFC, defaults to 3. \n:type method: int, optional \n:param maxIter: The maximum number of iterations, defaults to 500. \n:type maxIter: int, optional \n:param gamma: Percentage of inliers in the samples. This is an inital value for EM iteration \nand is not important, defaults to 0.9. \n:type gamma: float, optional \n:param beta: Paramerter of Gaussian Kernel, k(x, y) = exp(-beta* || x - y || ^ 2), defaults to 0.1. \n:type beta: float, optional \n:param lmbda: Represents the trade-off between the goodness of data fit and smoothness of the field, defaults to 3.0. \n:type lmbda: float, optional \n:param theta: The threshold value that determines whether the sample is an inliner or not. An inliner has a posterior \nprobability which is superior to theta, defaults to 0.75. \n:type theta: float, optional \n:param a: Paramerter of the uniform distribution. It is that the outliers obey a uniform distribution 1/a, defaults  \nto 10.0. \n:type a: float, optional \n:param ecr: The minimum limitation of the energy change rate in the iteration process, defaults to 1e-5. \n:type ecr: float, optional \n:param minP: The posterior probability Matrix P may be singular for matrix inversion. The minimum value of P is set  \nas minP, defaults to 1e-5. \n:type minP: float, optional)mydelimiter")
        .def(py::init<int, int, float, float, float, float, float, float, float>(), 
            py::arg("method") = 3, py::arg("maxIter") = 500, py::arg("gamma") = 0.9f,
            py::arg("beta") = 0.1f, py::arg("lmbda") = 3.0f, py::arg("theta") = 0.75f,
            py::arg("a") = 10.0f, py::arg("ecr") = 1e-5, py::arg("minP") = 1e-5)
        .def("setData", &VFC::setData)
        .def("optimize", &VFC::optimize)
        .def("obtainCorrectMatch", &VFC::obtainCorrectMatch)
        .def("getMethod", &VFC::getMethod)
        .def("getMaxIter", &VFC::getMaxIter)
        .def("getGamma", &VFC::getGamma)
        .def("getBeta", &VFC::getBeta)
        .def("getLambda", &VFC::getLambda)
        .def("getTheta", &VFC::getTheta)
        .def("getA", &VFC::getA)
        .def("getEcr", &VFC::getEcr)
        .def("getMinP", &VFC::getMinP);
}
