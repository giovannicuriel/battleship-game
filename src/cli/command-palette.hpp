#ifndef __CLI_COMMAND_PALETTE_HPP__
#define __CLI_COMMAND_PALETTE_HPP__

#include <cli/patricia-tree.hpp>
#include <logic/minefield/minefield.hpp>

struct CliCommand {
    virtual void operator()() = 0;
};

struct PrintHelpCommand: public CliCommand {
protected:
    PatriciaTree<Node<CliCommand*, StringKeySpec>>* m_Tree;
public:
    PrintHelpCommand(PatriciaTree<Node<CliCommand*, StringKeySpec>> *tree);
    void operator()();
};

struct CreateMinefieldCommand: public CliCommand {
protected:
    Field* m_Field;
public:
    CreateMinefieldCommand(Field * field);
    void operator()();
};

struct PrintMinefieldCommand: public CliCommand {
protected:
    Field* m_Field;
public:
    PrintMinefieldCommand(Field * field);
    void operator()();
};

struct ProbeMinefieldCommand: public CliCommand {
protected:
    Field* m_Field;
public:
    ProbeMinefieldCommand(Field * field);
    void operator()();
};

struct SweepMinefieldCommand: public CliCommand {
protected:
    Field* m_Field;
public:
    SweepMinefieldCommand(Field * field);
    void operator()();
};



#endif // __CLI_COMMAND_PALETTE_HPP__