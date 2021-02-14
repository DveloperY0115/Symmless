//
// Created by 유승우 on 2021/02/09.
//

#include "unitTest.hpp"
#include "Vector/Vector3.hpp"

using namespace Symmless;

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

TEST(Vector3, Setters) {
    Vector<float, 3> vec = Vector<float, 3>(3.0f, 2.0f, -1.0f);
    EXPECT_FLOAT_EQ(3.0f, vec._x);
    EXPECT_FLOAT_EQ(2.0f, vec._y);
    EXPECT_FLOAT_EQ(-1.0f, vec._z);

    //! Set all components to zero
    vec.SetZero();
    EXPECT_FLOAT_EQ(0.0f, vec._x);
    EXPECT_FLOAT_EQ(0.0f, vec._y);
    EXPECT_FLOAT_EQ(0.0f, vec._z);

    //! Set all components to 1.0
    vec.Set(1.0f);
    EXPECT_FLOAT_EQ(1.0f, vec._x);
    EXPECT_FLOAT_EQ(1.0f, vec._y);
    EXPECT_FLOAT_EQ(1.0f, vec._z);

    //! Set components with different given values
    vec.Set(4.0f, -5.0f, 1.0f);
    EXPECT_FLOAT_EQ(4.0f, vec._x);
    EXPECT_FLOAT_EQ(-5.0f, vec._y);
    EXPECT_FLOAT_EQ(1.0f, vec._z);

    //! Set components with initializer list
    vec.Set({ 3.0f, 2.0f, -1.0f });
    EXPECT_FLOAT_EQ(3.0f, vec._x);
    EXPECT_FLOAT_EQ(2.0f, vec._y);
    EXPECT_FLOAT_EQ(-1.0f, vec._z);

    //! Set components with other vector
    Vector<float, 3> vec_other = Vector<float, 3>();
    vec.Set(vec_other);
    EXPECT_FLOAT_EQ(0.0f, vec._x);
    EXPECT_FLOAT_EQ(0.0f, vec._y);
    EXPECT_FLOAT_EQ(0.0f, vec._z);
}

TEST(Vector3, AssignmentOps) {
    Vector<float, 3> vec1 = Vector<float, 3>();
    Vector<float, 3> vec2 = Vector<float, 3>({ 1.0f, 1.0f, 2.0f });

    EXPECT_FLOAT_EQ(0.0f, vec1._x);
    EXPECT_FLOAT_EQ(0.0f, vec1._y);
    EXPECT_FLOAT_EQ(0.0f, vec1._z);

    EXPECT_FLOAT_EQ(1.0f, vec2._x);
    EXPECT_FLOAT_EQ(1.0f, vec2._y);
    EXPECT_FLOAT_EQ(2.0f, vec2._z);

    //! Check copy assignment operator
    vec1 = vec2;
    EXPECT_FLOAT_EQ(1.0f, vec1._x);
    EXPECT_FLOAT_EQ(1.0f, vec1._y);
    EXPECT_FLOAT_EQ(2.0f, vec1._z);

    //! Check move assignment operator

}

TEST(Vector3, LengthAndNormalize) {
    Vector<float, 3> vec = Vector<float, 3>({ 1.0f, 1.0f, 2.0f });

    //! Check length function
    float vec_norm = vec.Length();
    EXPECT_FLOAT_EQ(std::sqrt(1.0f * 1.0f + 1.0f * 1.0f + 2.0f * 2.0f),
                    vec_norm);

    //! Check normalization function
    vec.Normalize();
    EXPECT_FLOAT_EQ(1.0f / vec_norm, vec._x);
    EXPECT_FLOAT_EQ(1.0f / vec_norm, vec._y);
    EXPECT_FLOAT_EQ(2.0f / vec_norm, vec._z);
}

TEST(Vector3, AlgebraicOps) {
    Vector<float, 3> vec = Vector<float, 3>({ 1.0f, 1.0f, 1.0f });
    EXPECT_FLOAT_EQ(1.0f, vec._x);
    EXPECT_FLOAT_EQ(1.0f, vec._y);
    EXPECT_FLOAT_EQ(1.0f, vec._z);

    Vector<float, 3> vec_add_const = vec.Add(3.0f);
    EXPECT_FLOAT_EQ(4.0f, vec_add_const._x);
    EXPECT_FLOAT_EQ(4.0f, vec_add_const._y);
    EXPECT_FLOAT_EQ(4.0f, vec_add_const._z);

    Vector<float, 3> vec_add_vec = vec.Add(Vector<float, 3>(1.0f, 2.0f, 3.0f));
    EXPECT_FLOAT_EQ(2.0f, vec_add_vec._x);
    EXPECT_FLOAT_EQ(3.0f, vec_add_vec._y);
    EXPECT_FLOAT_EQ(4.0f, vec_add_vec._z);

    Vector<float, 3> vec_sub_const = vec.Sub(1.0f);
    EXPECT_FLOAT_EQ(0.0f, vec_sub_const._x);
    EXPECT_FLOAT_EQ(0.0f, vec_sub_const._y);
    EXPECT_FLOAT_EQ(0.0f, vec_sub_const._z);

    Vector<float, 3> vec_sub_vec = vec.Sub(Vector<float, 3>(1.0f, 1.0f, 1.0f));
    EXPECT_FLOAT_EQ(0.0f, vec_sub_vec._x);
    EXPECT_FLOAT_EQ(0.0f, vec_sub_vec._y);
    EXPECT_FLOAT_EQ(0.0f, vec_sub_vec._z);

    Vector<float, 3> vec_mul_const = vec.Mul(2.0f);
    EXPECT_FLOAT_EQ(2.0f, vec_mul_const._x);
    EXPECT_FLOAT_EQ(2.0f, vec_mul_const._y);
    EXPECT_FLOAT_EQ(2.0f, vec_mul_const._z);

    Vector<float, 3> vec_mul_vec = vec.Mul(Vector<float, 3>(3.0f, 4.0f, 5.0f));
    EXPECT_FLOAT_EQ(3.0f, vec_mul_vec._x);
    EXPECT_FLOAT_EQ(4.0f, vec_mul_vec._y);
    EXPECT_FLOAT_EQ(5.0f, vec_mul_vec._z);

    float result_dot = vec.Dot(Vector<float, 3>(2.0f, 3.0f, 4.0f));
    EXPECT_FLOAT_EQ(9.0f, result_dot);

    Vector<float, 3> result_cross = vec.Cross(Vector<float, 3>(2.0f, 3.0f, 4.0f));
    EXPECT_FLOAT_EQ(1.0f, result_cross._x);
    EXPECT_FLOAT_EQ(-2.0f, result_cross._y);
    EXPECT_FLOAT_EQ(1.0f, result_cross._z);

    Vector<float, 3> vec_rsub_const = vec.RSub(3.0f);
    EXPECT_FLOAT_EQ(2.0f, vec_rsub_const._x);
    EXPECT_FLOAT_EQ(2.0f, vec_rsub_const._y);
    EXPECT_FLOAT_EQ(2.0f, vec_rsub_const._z);

    Vector<float, 3> vec_rsub_vec = vec.RSub(Vector<float, 3>(2.0f, 3.0f, 4.0f));
    EXPECT_FLOAT_EQ(1.0f, vec_rsub_vec._x);
    EXPECT_FLOAT_EQ(2.0f, vec_rsub_vec._y);
    EXPECT_FLOAT_EQ(3.0f, vec_rsub_vec._z);
}