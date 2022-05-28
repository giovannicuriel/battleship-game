#ifndef __MOCK_COMMAND_TREE_HPP__
#define __MOCK_COMMAND_TREE_HPP__

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <cli/patricia-tree.hpp>

template<typename Node, typename DataType = Node::dataType, typename Key = Node::keyType>
class MockCommandTree: public PatriciaTree<Node, DataType, Key> {
public:
    MOCK_METHOD((Node*), findNode, (Key key, bool relaxed), (const));
    MOCK_METHOD((void), insertNode, (Key key, DataType data), ());
    MOCK_METHOD((std::string), toString, (), (const));
};

#endif // __MOCK_COMMAND_TREE_HPP__