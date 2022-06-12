#include <gtest/gtest.h>
#include <types.hpp>

TEST(CommonTypes, ShouldBuildAPoint) {
    Point a { x: 10, y: 10 };
    Point b { x: 20, y: 25 };
    Point c = a + b;
    EXPECT_EQ(c.x, 30);
    EXPECT_EQ(c.y, 35);
}

TEST(CommonTypes, PointsShouldBeComparable) {
    Point a { x: 10, y: 10 };
    Point b { x: 20, y: 25 };
    EXPECT_LT(a, b);
    EXPECT_TRUE(a < b);
    EXPECT_GT(b, a);
    EXPECT_EQ(a, a);
}

TEST(CommonTypes, ShouldBuildAnArea) {
    Area a { x: 10, y: 10, w: 50, h: 50 };
    Point p1 { x: 0, y: 0 };
    Point p2 { x: 15, y: 15 };
    EXPECT_FALSE(a.contains(p1));
    EXPECT_TRUE(a.contains(p2));
}

TEST(CommonTypes, ShouldBuildAColor) {
    Color c1 { r: 100, g: 100, b: 100, a: 255 };
    std::vector<u_int8_t> c2 { 100, 100, 100, 255 };
    std::vector<u_int8_t> c3 { 10, 10, 10, 25 };
    std::vector<u_int8_t> colors {10, 10, 10, 25};

    c1 += c2;
    EXPECT_EQ(c1.r, 200);
    EXPECT_EQ(c1.g, 200);
    EXPECT_EQ(c1.b, 200);
    EXPECT_EQ(c1.a, 255);

    c1 -= c3;
    EXPECT_EQ(c1.r, 190);
    EXPECT_EQ(c1.g, 190);
    EXPECT_EQ(c1.b, 190);
    EXPECT_EQ(c1.a, 230);

    c1.copyFrom(colors);
    EXPECT_EQ(c1.r, 10);
    EXPECT_EQ(c1.g, 10);
    EXPECT_EQ(c1.b, 10);
    EXPECT_EQ(c1.a, 25);
}