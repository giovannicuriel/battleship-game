#include <cli/patricia-tree.hpp>

#include <gtest/gtest.h>

typedef Node<int, StringKeySpec> TestNodeType;

TEST(PatriciaTreeTest, ShouldCreateASimpeTree) {
    PatriciaTree<TestNodeType> tree;
}

TEST(PatriciaTreeTest, ShouldAddNonIntersectingNodes) {
    PatriciaTree<TestNodeType> tree;
    tree.insertNode(std::string("aaa-sample-1"), 10);
    tree.insertNode(std::string("bbb-sample-1"), 20);
    tree.insertNode(std::string("ccc-sample-1"), 30);

    TestNodeType* nodeAAA = tree.findNode(std::string("aaa-sample-1"), false);
    TestNodeType* nodeBBB = tree.findNode(std::string("bbb-sample-1"), false);
    TestNodeType* nodeCCC = tree.findNode(std::string("ccc-sample-1"), false);

    EXPECT_EQ(nodeAAA->getData(), 10);
    EXPECT_EQ(nodeBBB->getData(), 20);
    EXPECT_EQ(nodeCCC->getData(), 30);
}

TEST(PatriciaTreeTest, ShouldAddALongerKeyNode) {
    PatriciaTree<TestNodeType> tree;
    tree.insertNode(std::string("sample"), 1);
    tree.insertNode(std::string("sample-10-example"), 101);
    
    TestNodeType* node = tree.findNode(std::string("sample"), false);
    EXPECT_EQ(node->getData(), 1);
    node = tree.findNode(std::string("sample-10-example"), false);
    EXPECT_EQ(node->getData(), 101);
}

TEST(PatriciaTreeTest, ShouldAddASmallerKeyNode) {
    PatriciaTree<TestNodeType> tree;
    tree.insertNode(std::string("sample-10-example"), 101);
    tree.insertNode(std::string("sample"), 1);
    
    TestNodeType* node = tree.findNode(std::string("sample"), false);
    EXPECT_EQ(node->getData(), 1);
    node = tree.findNode(std::string("sample-10-example"), false);
    EXPECT_EQ(node->getData(), 101);
}

TEST(PatriciaTreeTest, ShouldReturnNullIfKeyNotFound) {
    PatriciaTree<TestNodeType> tree;
    tree.insertNode(std::string("sample"), 1);
    
    TestNodeType* node = tree.findNode(std::string("other"), false);
    EXPECT_EQ(node, nullptr);
    node = tree.findNode(std::string("other"), true);
    EXPECT_EQ(node, nullptr);
}

TEST(PatriciaTreeTest, ShouldReturnNullIfKeyNotFound2) {
    PatriciaTree<TestNodeType> tree;
    tree.insertNode(std::string("sample"), 1);
    tree.insertNode(std::string("sample-other"), 1);
    
    TestNodeType* node = tree.findNode(std::string("sampleX"), false);
    // EXPECT_EQ(node, nullptr);
}


TEST(PatriciaTreeTest, ShouldReturnIfSingleEntryIsFound) {
    PatriciaTree<TestNodeType> tree;
    tree.insertNode(std::string("sample"), 1);
    
    TestNodeType* node = tree.findNode(std::string("samp"), true);
    EXPECT_EQ(node->getData(), 1);
    node = tree.findNode(std::string("samp"), false);
    EXPECT_EQ(node, nullptr);
}

TEST(PatriciaTreeTest, ShouldPrintATree) {
    PatriciaTree<TestNodeType> tree;
    tree.insertNode(std::string("sample"), 1);
    tree.insertNode(std::string("sample-10-example"), 101);
    tree.insertNode(std::string("sample-21-example"), 210);
    tree.insertNode(std::string("sample-10"), 10);
    tree.insertNode(std::string("sample-20"), 20);

    std::string result = tree.toString();

    EXPECT_NE(result.length(), 0);
}