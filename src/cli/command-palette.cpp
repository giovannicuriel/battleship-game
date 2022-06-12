#include <cli/command-palette.hpp>
#include <utils.hpp>

PrintHelpCommand::PrintHelpCommand(
    PatriciaTree<Node<CliCommand*, StringKeySpec>>* tree
    ): m_Tree(tree) {

}
void PrintHelpCommand::execute() {
    std::cout << "This is the help menu\n";
    std::cout << m_Tree->toString();
}

CreateMinefieldCommand::CreateMinefieldCommand(Field* field):
    m_Field(field) { }

void CreateMinefieldCommand::execute() {
    std::cout << "Generating minefield...\n";
    m_Field->generate(Area {0, 0, 10, 10}, 4);
    std::cout << "ok.\n";
}

PrintMinefieldCommand::PrintMinefieldCommand(Field* field):
    m_Field(field) { }

void PrintMinefieldCommand::execute() {
    std::cout << "Minefield is: \n";
    std::cout << *m_Field;
    std::cout << "ok.\n";
}

ProbeMinefieldCommand::ProbeMinefieldCommand(Field* field, InputReader* reader):
    m_Field(field), m_Reader(reader) { }

void ProbeMinefieldCommand::execute() {
    ::Point p;
    std::cout << "Probing minefield: \n";
    std::cout << std::endl;
    std::cout << "X: ";
    m_Reader->readValue(p.x);
    std::cout << std::endl;
    std::cout << "Y: ";
    m_Reader->readValue(p.y);
    std::cout << std::endl;
    auto result = m_Field->probe(p);
    // std::cout << "Result: \n";
    // std::cout << result;
    std::cout << std::endl;
    std::cout << "Minefield is: \n";
    std::cout << *m_Field;
    std::cout << std::endl;
    std::cout << "ok.\n";
}

SweepMinefieldCommand::SweepMinefieldCommand(Field* field):
    m_Field(field) { }

void SweepMinefieldCommand::execute() {
    auto result = m_Field->sweep();
    for (int16_t x = 0; x < 10; x++) {
        for (int16_t y = 0; y < 10; y++) {
            auto nBomb = result[::Point { x, y }];
            std::cout << "[" << (nBomb < 0 || nBomb > 10 ? "" : " ") << nBomb << "]";
        }
        std::cout << "\n";
    }
}
