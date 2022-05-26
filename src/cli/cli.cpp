#include <cli/cli.hpp>

Cli::Cli(Field& f) : m_Field(f) {
    pt.insertNode(std::string("print help"), &Cli::printHelp);
    pt.insertNode(std::string("minefield create"), &Cli::createMinefield);
    pt.insertNode(std::string("minefield print"), &Cli::printMinefield);
    pt.insertNode(std::string("probe"), &Cli::probeMinefield);
    pt.insertNode(std::string("sweep"), &Cli::sweepMinefield);
}

void Cli::run() {
    std::string command;
    printHelp();
    m_Field.generate(Dimension { 10, 10}, 4);
    std::cout << m_Field;
    while (command != "exit") {
        getline(std::cin, command);
        if (command == "") { continue; }
        auto node = pt.findNode(command, false);
        if (node != nullptr) {
            auto fn = node->getData();
            (this->*fn)();
        } else {
            std::cout << "Command not found\n";
        }
    }
}
void Cli::printHelp() {
    std::cout << "This is the help menu\n";
    std::cout << this->pt;
}
void  Cli::createMinefield() {
    std::cout << "Generating minefield...\n";
    m_Field.generate(Dimension { 10, 10}, 4);
    std::cout << "ok.\n";
}
void Cli::printMinefield() {
    std::cout << "Minefield is: \n";
    std::cout << m_Field;
    std::cout << "ok.\n";
}
void Cli::probeMinefield() {
    ::Point p;
    std::cout << "Probing minefield: \n";
    std::cout << "X: ";
    std::cin >> p.x;
    std::cout << "Y: ";
    std::cin >> p.y;
    auto result = m_Field.probe(p);
    std::cout << "Result: \n";
    std::cout << result;
    std::cout << "Minefield is: \n";
    std::cout << m_Field;
    std::cout << "ok.\n";
}

void Cli::sweepMinefield() {
    auto result = m_Field.sweep();
    for (int16_t x = 0; x < 10; x++) {
        for (int16_t y = 0; y < 10; y++) {
            auto nBomb = result[::Point { x, y }];
            std::cout << "[" << (nBomb < 0 || nBomb > 10 ? "" : " ") << nBomb << "]";
        }
        std::cout << "\n";
    }
}
