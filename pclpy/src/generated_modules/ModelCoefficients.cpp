
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/eigen.h>
#include <pcl/point_types.h>

namespace py = pybind11;
using namespace pybind11::literals;

PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);
#include "../make_opaque_vectors.hpp"

#include <pcl/ModelCoefficients.h>



void defineModelCoefficients(py::module &m) {
    using Class = pcl::ModelCoefficients;
    using Ptr = Class::Ptr;
    using ConstPtr = Class::ConstPtr;
    py::class_<Class, boost::shared_ptr<Class>> cls(m, "ModelCoefficients");
    cls.def(py::init<>());
    cls.def_readwrite("header", &Class::header);
    cls.def_readwrite("values", &Class::values);
}

void defineModelCoefficientsFunctions(py::module &m) {
}

void defineModelCoefficientsClasses(py::module &sub_module) {
    defineModelCoefficients(sub_module);
    defineModelCoefficientsFunctions(sub_module);
}