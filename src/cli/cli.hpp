#ifndef __CLI_CLI_HPP__
#define __CLI_CLI_HPP__

#include <cli/patricia-tree.hpp>
#include <logic/minefield/minefield.hpp>

#include <cli/command-palette.hpp>
#include <cli/command-builder.hpp>

class Cli {
protected:
    PatriciaTree<Node<CliCommand*, StringKeySpec>>* m_CommandTree;
    Field* m_Field;
    CliCommandBuilder* m_Builder;
    void probeMinefield();
    void sweepMinefield();
public:
    Cli(
        PatriciaTree<Node<CliCommand*, StringKeySpec>>* tree,
        Field* field,
        CliCommandBuilder* builder
    );

    void run();
};

#endif //__CLI_CLI_HPP__
