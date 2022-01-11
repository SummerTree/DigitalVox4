// Copyright (c) 2018 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include "ray3.h"
#include <gtest/gtest.h>

using namespace Imath;

TEST(Ray3, Constructors) {
    Ray3D ray;
    EXPECT_EQ(V3d(0), ray.origin);
    EXPECT_EQ(V3d(1, 0, 0), ray.direction);

    Ray3D ray2({1, 2, 3}, {4, 5, 6});
    EXPECT_EQ(V3d(1, 2, 3), ray2.origin);
    EXPECT_EQ(V3d(4, 5, 6).normalized(), ray2.direction);

    Ray3D ray3(ray2);
    EXPECT_EQ(V3d(1, 2, 3), ray3.origin);
    EXPECT_EQ(V3d(4, 5, 6).normalized(), ray3.direction);
}

TEST(Ray3, PointAt) {
    Ray3D ray;
    EXPECT_EQ(V3d(4.5, 0.0, 0.0), ray.pointAt(4.5));
}