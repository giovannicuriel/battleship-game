#include <cli/command-palette.hpp>

PrintHelpCommand::PrintHelpCommand(
    PatriciaTree<Node<CliCommand*, StringKeySpec>>* tree
    ): m_Tree(tree) {

}
void PrintHelpCommand::operator()() {
    std::cout << "This is the help menu\n";
    std::cout << *m_Tree;
}

CreateMinefieldCommand::CreateMinefieldCommand(Field* field):
    m_Field(field) { }

void CreateMinefieldCommand::operator()() {
    std::cout << "Generating minefield...\n";
    m_Field->generate(Dimension { 10, 10}, 4);
    std::cout << "ok.\n";
}

PrintMinefieldCommand::PrintMinefieldCommand(Field* field):
    m_Field(field) { }

void PrintMinefieldCommand::operator()() {
    std::cout << "Minefield is: \n";
    std::cout << *m_Field;
    std::cout << "ok.\n";
}

ProbeMinefieldCommand::ProbeMinefieldCommand(Field* field):
    m_Field(field) { }

void ProbeMinefieldCommand::operator()() {
    ::Point p;
    std::cout << "Probing minefield: \n";
    std::cout << "X: ";
    std::cin >> p.x;
    std::cout << "Y: ";
    std::cin >> p.y;
    auto result = m_Field->probe(p);
    std::cout << "Result: \n";
    std::cout << result;
    std::cout << "Minefield is: \n";
    std::cout << *m_Field;
    std::cout << "ok.\n";
}

SweepMinefieldCommand::SweepMinefieldCommand(Field* field):
    m_Field(field) { }

void SweepMinefieldCommand::operator()() {
    auto result = m_Field->sweep();
    for (int16_t x = 0; x < 10; x++) {
        for (int16_t y = 0; y < 10; y++) {
            auto nBomb = result[::Point { x, y }];
            std::cout << "[" << (nBomb < 0 || nBomb > 10 ? "" : " ") << nBomb << "]";
        }
        std::cout << "\n";
    }
}
