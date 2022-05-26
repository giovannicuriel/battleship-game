#include <cli/command-builder.hpp>

CliCommandBuilder::CliCommandBuilder(
    PatriciaTree<Node<CliCommand*, StringKeySpec>>* tree,
    Field* field
): m_Tree(tree), m_Field(field) {

}

CliCommandNode CliCommandBuilder::buildCommand(CommandKey key) {
    switch (key) {
        case PRINT_HELP_COMMAND:
            return CliCommandNode { "print help", new PrintHelpCommand(m_Tree) };
        case CREATE_MINEFIELD:
            return CliCommandNode { "minefield create", new CreateMinefieldCommand(m_Field) };
        case PRINT_MINEFIELD:
            return CliCommandNode { "minefield print", new PrintMinefieldCommand(m_Field) };
        case PROBE_MINEFIELD:
            return CliCommandNode { "probe", new ProbeMinefieldCommand(m_Field) };
        case SWEEP_MINEFIELD:
            return CliCommandNode { "sweep", new SweepMinefieldCommand(m_Field) };
        default:
            return CliCommandNode { "unknown", nullptr };
    }
}
