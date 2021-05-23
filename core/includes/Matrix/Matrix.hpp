#ifndef SYMMLESS_MATRIX_HPP
#define SYMMLESS_MATRIX_HPP

#include "Common/Symmless.hpp"

#include <array>

namespace Symmless {
    //
    // \brief Generalized matrix class.
    //
    // This class defines a matrix of size (Rows, Cols) and associated operations.
    //
    // \param T - Type of the element
    // \param Rows - Number of rows
    // \param Cols - Number of columns
    //
    template <typename T, size_t Rows, size_t Cols>
    class Matrix final {
        using ContainerType = std::array<T, Rows * Cols>
    public:
        static_assert(Rows > 0 && Cols > 0, 
                        "Size of static-sized matrix should be greater than zero.");
        
        // Constructor.
        // Create a matrix filled with zeros.
        SYMMLESS_HOST_DEVICE
        Matrix() {
            // Do nothing.
        }

    private:
        ContainerType container = ContainerType();
    }
}

#endif