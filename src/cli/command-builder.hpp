#ifndef __CLI_COMMAND_BUILDER_HPP__
#define __CLI_COMMAND_BUILDER_HPP__

#include <cli/patricia-tree.hpp>
#include <cli/command-palette.hpp>
#include <cli/input-reader.hpp>

enum CommandKey {
    PRINT_HELP_COMMAND,
    CREATE_MINEFIELD,
    PRINT_MINEFIELD,
    PROBE_MINEFIELD,
    SWEEP_MINEFIELD
};

struct CliCommandNode {
    std::string key;
    CliCommand* command;
};

class CliCommandBuilder {
protected:
    PatriciaTree<Node<CliCommand*, StringKeySpec>>* m_Tree;
    Field* m_Field;
    InputReader* m_Reader;
public:
    CliCommandBuilder(
        PatriciaTree<Node<CliCommand*, StringKeySpec>>* tree,
        Field* m_Field,
        InputReader* m_Reader
    );
    virtual CliCommandNode buildCommand(CommandKey key);
};


#endif// __CLI_COMMAND_BUILDER_HPP__