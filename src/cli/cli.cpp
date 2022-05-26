#include <cli/cli.hpp>


Cli::Cli(
    PatriciaTree<Node<CliCommand*, StringKeySpec>>* tree,
    Field* field,
    CliCommandBuilder* builder
) : m_Field(field), m_CommandTree(tree), m_Builder(builder) {
    auto insertNode = [this](CommandKey key) { 
        auto node = m_Builder->buildCommand(key);
        m_CommandTree->insertNode(node.key, node.command);
    };

    insertNode(PRINT_HELP_COMMAND);
    insertNode(CREATE_MINEFIELD);
    insertNode(PRINT_MINEFIELD);
    insertNode(PROBE_MINEFIELD);
    insertNode(SWEEP_MINEFIELD);
}

void Cli::run() {
    std::string command;
    m_Field->generate(Dimension { 10, 10}, 4);
    while (command != "exit") {
        getline(std::cin, command);
        if (command == "") { continue; }
        auto node = m_CommandTree->findNode(command, false);
        if (node != nullptr) {
            auto fn = node->getData();
            (*fn)();
        } else {
            std::cout << "Command not found. Try 'print help'\n";
        }
    }
}
