#ifndef BLAS_VECTOR3_HPP
#define BLAS_VECTOR3_HPP

template <typename T, size_t N>
class Vector3 final {
public:
    static_assert(
            N > 0,
            "Size of static-sized vector should be greater than zero."
            );
    static_assert(
            std::is_floating_point<T>::value,
            "Vector only can be instantiated with floating point types."
            );

private:
    std::array<T, N> _elements;
};
#endif //BLAS_VECTOR3_HPP
