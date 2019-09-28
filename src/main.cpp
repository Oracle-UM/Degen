#include <cctype>
#include <iostream>
#include <random>

template <class T = int>
class UniformDistRNG final {
   public:
    UniformDistRNG(T min, T max) : uniform_dist{ min, max } {}

    [[nodiscard]]
    auto operator()() -> T { return uniform_dist(rand_engine); }

   private:
    static inline auto rand_engine = std::mt19937{ std::random_device{}() };
    std::uniform_int_distribution<T> uniform_dist;
};


auto main(int argc, char* argv[]) -> int {
    if (argc < 2) {
        return 1;
    }

    for (auto i = 1; i < argc; ++i) {
        auto rng = UniformDistRNG(1, 100);
        for (auto it = argv[i]; *it; ++it) {
            auto const c = *it;
            if (rng() < 50) {
                *it = tolower(c);
            } else {
                *it = toupper(c);
            }
        }
    }
    for (auto i = 1; i < argc - 1; ++i) {
        std::cout << argv[i] << ' ';
    }
    std::cout << argv[argc - 1];
    std::cout << '\n';
}