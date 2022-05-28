#ifndef __CLI_COMMAND_PALETTE_HPP__
#define __CLI_COMMAND_PALETTE_HPP__

#include <cli/patricia-tree.hpp>
#include <cli/input-reader.hpp>
#include <logic/minefield/minefield.hpp>


struct CliCommand {
    virtual void execute() = 0;
};

struct PrintHelpCommand: public CliCommand {
protected:
    PatriciaTree<Node<CliCommand*, StringKeySpec>>* m_Tree;
public:
    PrintHelpCommand(PatriciaTree<Node<CliCommand*, StringKeySpec>> *tree);
    void execute();
};

struct CreateMinefieldCommand: public CliCommand {
protected:
    Field* m_Field;
public:
    CreateMinefieldCommand(Field * field);
    void execute();
};

struct PrintMinefieldCommand: public CliCommand {
protected:
    Field* m_Field;
public:
    PrintMinefieldCommand(Field * field);
    void execute();
};

struct ProbeMinefieldCommand: public CliCommand {
protected:
    Field* m_Field;
    InputReader* m_Reader;
public:
    ProbeMinefieldCommand(Field * field, InputReader* reader);
    void execute();
};

struct SweepMinefieldCommand: public CliCommand {
protected:
    Field* m_Field;
public:
    SweepMinefieldCommand(Field * field);
    void execute();
};



#endif // __CLI_COMMAND_PALETTE_HPP__