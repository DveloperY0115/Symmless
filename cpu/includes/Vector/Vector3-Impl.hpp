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

    template<typename T>
    Vector<T, 3>& Vector<T, 3>::operator=(const Vector& v) {
        Set(v);
        return (*this);
    }

    template <typename T>
    void Vector<T, 3>::Set(T s) {
        this->_x = s;
        this->_y = s;
        this->_z = s;
    }

    template <typename T>
    void Vector<T, 3>::Set(T x, T y, T z) {
        this->_x = x;
        this->_y = y;
        this->_z = z;
    }

    template <typename T>
    template <typename U>
    void Vector<T, 3>::Set(const std::initializer_list<U>& list) {
        assert(list.size() >= 3);

        auto first_elem = list.begin();
        this->_x = static_cast<T>(*first_elem);
        this->_y = static_cast<T>(*(++first_elem));
        this->_z = static_cast<T>(*(++first_elem));
    }

#endif //BLAS_VECTOR3_IMPL_HPP
