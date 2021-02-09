//
// Created by 유승우 on 2021/02/09.
//

#ifndef BLAS_VECTOR3_IMPL_HPP
#define BLAS_VECTOR3_IMPL_HPP

#include "Vector3.hpp"

namespace BLAS {

    template<typename T>
    template<typename U>
    Vector<T, 3>::Vector(const std::initializer_list<U>& list) {
        Set(list);
    }


#endif //BLAS_VECTOR3_IMPL_HPP
