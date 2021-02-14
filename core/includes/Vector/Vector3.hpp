#ifndef SYMMLESS_VECTOR3_HPP
#define SYMMLESS_VECTOR3_HPP

#include <cmath>
#include <limits>
#include <type_traits>

#include "Vector.hpp"

namespace Symmless {
    //!
    //! \brief 3D vector class.
    //!
    //! This class defines 3D vector and associated operations.
    //!
    //! \tparam T - Type of the element
    //!
    template<typename T>
    class Vector<T, 3> final {
    public:
        static_assert(std::is_floating_point<T>::value,
                "Vector only can be instantiated with floating point types.");

        //! Constructs 3D vector filled with zeros.
        SYMMLESS_HOST_DEVICE
        constexpr Vector() : _x{ 0 }, _y{ 0 }, _z{ 0 }
        {
            // Do nothing
        }

        //! Constructs 3D vector whose elements are initialized with given values.
        SYMMLESS_HOST_DEVICE
        constexpr Vector(T x, T y, T z) : _x{ x }, _y{ y }, _z{ z }
        {
            // Do nothing
        }

        //! Constructs 3D vector with initializer list.
        template <typename U>
        SYMMLESS_HOST_DEVICE
        Vector(const std::initializer_list<U>& list);

        //! Copy constructor.
        SYMMLESS_HOST_DEVICE
        constexpr Vector(const Vector& v) : _x{ v._x }, _y{ v._y }, _z{ v._z }
        {
            // Do nothing
        }

        //! Move constructor.
        SYMMLESS_HOST_DEVICE
        constexpr Vector(Vector&& v) noexcept : _x{ v._x }, _y{ v._y }, _z{ v._z }
        {
            // Do nothing
        }

        //! Default destructor.
        SYMMLESS_HOST_DEVICE
        ~Vector() = default;

        //! Copy assignment operator.
        SYMMLESS_HOST_DEVICE
        Vector& operator=(const Vector& v);

        //! Move assignment operator.
        SYMMLESS_HOST_DEVICE
        Vector& operator=(const Vector&& v) noexcept;

        //! Set all x,y, z components to \p s.
        SYMMLESS_HOST_DEVICE
        void Set(T s);

        //! Set x, y, z components with each given values.
        SYMMLESS_HOST_DEVICE
        void Set(T x, T y, T z);

        //! Set x, y, z components with given initializer list.
        template <typename U>
        SYMMLESS_HOST_DEVICE
        void Set(const std::initializer_list<U>& list);

        //! Set x, y, z components with elements of given vector \p v.
        SYMMLESS_HOST_DEVICE
        void Set(const Vector& v);

        //! Set x, y, z to zero.
        SYMMLESS_HOST_DEVICE
        void SetZero();

        //! Calculate L2 norm of this vector
        SYMMLESS_HOST_DEVICE
        float Length();

        //! Normalize this vector.
        SYMMLESS_HOST_DEVICE
        void Normalize();

        //! Element-wise scalar addition
        SYMMLESS_HOST_DEVICE
        Vector Add(T c) const;

        //! Vector addition
        SYMMLESS_HOST_DEVICE
        Vector Add(const Vector& v) const;

        //! Element-wise scalar subtraction
        SYMMLESS_HOST_DEVICE
        Vector Sub(T c) const;

        //! Vector subtraction
        SYMMLESS_HOST_DEVICE
        Vector Sub(const Vector& v) const;

        //! Element-wise scalar multiplication
        SYMMLESS_HOST_DEVICE
        Vector Mul(T c) const;

        //! Element-wise vector multiplication
        SYMMLESS_HOST_DEVICE
        Vector Mul(const Vector& v) const;

    public:
        T _x;
        T _y;
        T _z;
    };

}

#include "Vector3-Impl.hpp"

#endif //SYMMLESS_VECTOR3_HPP
