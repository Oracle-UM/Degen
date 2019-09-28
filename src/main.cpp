#include <cctype>
#include <iostream>
#include <random>

auto main(int argc, char* argv[]) -> int {
    if (argc < 2) {
        return 1;
    }

    auto rand_engine = std::mt19937(std::random_device()());
    for (auto i = 1; i < argc; ++i) {
        auto rng = std::uniform_int_distribution(1, 100);
        for (auto it = argv[i]; *it; ++it) {
            auto const c = *it;
            *it = (rng(rand_engine) < 50)
                ? tolower(c)
                : toupper(c);
        }
    }

    for (auto i = 1; i < argc - 1; ++i) {
        std::cout << argv[i] << ' ';
    }
    std::cout << argv[argc - 1];
    std::cout << '\n';
}