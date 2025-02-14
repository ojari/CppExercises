#define CATCH_CONFIG_RUNNER // Configure catch to use your main, and not its own.
#include <catch.hpp>
#include <iostream>
#include <exception>

int main(int argCount, char** ppArgs) {
    try {
        auto result = Catch::Session().run(argCount, ppArgs);
        if (result != 0) {
            std::cout << "Result: " << result << "\n";
        }
        return (result < 0xFF ? result : 0xFF);
    }
    catch (const std::exception& ex) {
        auto pMessage = ex.what();
        if (pMessage) {
            std::cout << "An unhandled exception was thrown:\n" << pMessage;
        }
        return -1;
    }
}
