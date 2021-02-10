//
// Created by 유승우 on 2021/02/09.
//

#include "unitTest.hpp"
#include <Vector/Vector3.hpp>

using namespace BLAS;

TEST(Vector3, Constructors) {
    //! Default constructor
    Vector<float, 3> vec = Vector<float, 3>();
    EXPECT_FLOAT_EQ(0.0f, vec._x);
    EXPECT_FLOAT_EQ(0.0f, vec._y);
    EXPECT_FLOAT_EQ(0.0f, vec._z);
}