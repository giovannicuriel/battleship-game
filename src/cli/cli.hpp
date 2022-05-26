#ifndef __CLI_CLI_HPP__
#define __CLI_CLI_HPP__

#include <cli/patricia-tree.hpp>
#include <logic/minefield/minefield.hpp>

class Cli {
protected:
    typedef void(Cli::*CliCommand)();
    PatriciaTree<Node<CliCommand, StringKeySpec>> pt;

    Field m_Field;
    void printHelp();
    void createMinefield();
    void printMinefield();
    void probeMinefield();
    void sweepMinefield();
public:
    Cli(Field& f);

    void run();
};
#endif //__CLI_CLI_HPP__
