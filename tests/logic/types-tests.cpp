#include <logic/types.hpp>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(LogicTypeTests, ShouldCreateAndPrintADimension) {
    Dimension d { x: 10, y: 20};
    std::string results = d.toString();
    EXPECT_EQ("<10, 20>", results);
}

TEST(LogicTypeTests, ShouldBuildAPoint) {
    Point p { x: 10, y: 20 };
    std::string result = p.toString();
    EXPECT_EQ("[10, 20]", result);
}

TEST(LogicTypeTests, ShouldComparePointsProperly) {
    Point p1 { x: 10, y: 20 };
    Point p2 { x: 10, y: 20 };
    Point expectedSum { x: 20, y: 40 };
    Point sum = p1 + p2;

    EXPECT_EQ(p1, p2);
    EXPECT_EQ(sum, expectedSum);
    EXPECT_TRUE(p1 < sum);
    EXPECT_TRUE(operator<(p1, sum));
}

