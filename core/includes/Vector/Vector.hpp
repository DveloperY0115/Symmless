#ifndef SYMMLESS_VECTOR_HPP
#define SYMMLESS_VECTOR_HPP

#include <cstddef>
#include <array>
#include <type_traits>

namespace Symmless {
    //!
    //! \brief Generalized vector class.
    //!
    //! This class defines a vector of size \p N and associated operations.
    //!
    //! \tparam T - Type of the element
    //! \tparam N - Number of elements
    //!
    template<typename T, std::size_t N>
    class Vector final {
    public:
        static_assert(N > 0,
                "Size of static-sized vector should be greater than zero.");
        static_assert(std::is_floating_point<T>::value,
                "Vector only can be instantiated with floating point types.");

        using ContainerType = std::array<T, N>;

        //! Constructs a vector filled with zeros.
        Vector();

        //! Constructs a vector with multiple parameters.
        template <typename... Params>
        explicit Vector(Params... params);

        //! Constructs a vector with initializer list.
        template <typename U>
        Vector(const std::initializer_list<U>& list);

        //! Copy constructor.
        Vector(Vector& v);

        //! Copy asssignment operator.
        Vector& operator=(const Vector& v);



    private:
        std::array<T, N> _elements;
    };
}

#include "Vector-Impl.hpp"

#endif //SYMMLESS_VECTOR_HPP
