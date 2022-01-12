#if !defined(TEST_UTILS)
#define TEST_UTILS

#define OK "✅"
#define KO "❌"

#define ASSERT(x)                     \
    if (x) {                          \
        std::cout << OK << std::endl; \
    } else {                          \
        std::cout << KO << std::endl; \
        abort();                      \
    }

#define CYAN "\033[0;36m"
#define RESET "\033[0m"
#define PURPLE "\033[0;35m"

#define PRINT_TITLE(ms) std::cout << PURPLE << ms << RESET << std::endl

#endif  // TEST_UTILS
