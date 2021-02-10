//
// Created by 유승우 on 2021/02/09.
//

#include "unitTest.hpp"
#include <Vector/Vector3.hpp>

using namespace BLAS;

TEST(Vector3, Constructors) {
    //! Default constructor
    Vector<float, 3> vec_default_constructor = Vector<float, 3>();
    EXPECT_FLOAT_EQ(0.0f, vec_default_constructor._x);
    EXPECT_FLOAT_EQ(0.0f, vec_default_constructor._y);
    EXPECT_FLOAT_EQ(0.0f, vec_default_constructor._z);

    //! Constructor with initial values
    Vector<float, 3> vec_initialized_with_params = Vector<float, 3>(3.0f, 2.0f, -1.0f);
    EXPECT_FLOAT_EQ(3.0f, vec_initialized_with_params._x);
    EXPECT_FLOAT_EQ(2.0f, vec_initialized_with_params._y);
    EXPECT_FLOAT_EQ(-1.0f, vec_initialized_with_params._z);

    //! Constructor with initializer list
    Vector<float, 3> vec_initialized_with_list = { 1.0f, 1.0f, 1.0f };
    EXPECT_FLOAT_EQ(1.0f, vec_initialized_with_list._x);
    EXPECT_FLOAT_EQ(1.0f, vec_initialized_with_list._y);
    EXPECT_FLOAT_EQ(1.0f, vec_initialized_with_list._z);

    //! Copy constructor
    Vector<float, 3> vec_copy_constructed = Vector<float, 3>(vec_initialized_with_params);
    EXPECT_FLOAT_EQ(3.0f, vec_copy_constructed._x);
    EXPECT_FLOAT_EQ(2.0f, vec_copy_constructed._y);
    EXPECT_FLOAT_EQ(-1.0f, vec_copy_constructed._z);

    //! Move constructor
}
    EXPECT_FLOAT_EQ(0.0f, vec._x);
    EXPECT_FLOAT_EQ(0.0f, vec._y);
    EXPECT_FLOAT_EQ(0.0f, vec._z);
}