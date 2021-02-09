#ifndef BLAS_VECTOR3_HPP
#define BLAS_VECTOR3_HPP

#include <limits>
#include <type_traits>

namespace BLAS {
    //!
    //! \brief 3D vector class.
    //!
    //! This class defines 3D vector data structure and associated operations.
    //!
    //! \tparam T - Type of the element
    //!
    template<typename T>
    class Vector<T, 3> final {
    public:
        static_assert(std::is_floating_point<T>::value,
                "Vector only can be instantiated with floating point types.");

        //! Constructs 3D vector filled with zeros.
        constexpr Vector()


    private:
        T x;
        T y;
        T z;
    };
}
#endif //BLAS_VECTOR3_HPP
