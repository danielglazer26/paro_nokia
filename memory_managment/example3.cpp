#include <iostream>
#include <stdexcept>

class CustomLogicError : public std::logic_error {
public:
    explicit CustomLogicError(const std::string &arg) : logic_error(arg) {
    }
};

class Resource {
public:
    void use(const char *arg) {
        std::cout << "Using resource. Passed " << *arg << std::endl;
        if (*arg == 'd') {
            throw CustomLogicError("Passed d. d is prohibited.");
        }
    }
};

void validateArguments(int argc) {
    if (argc != 2) {
        std::cerr << "You need to pass 1 argument" << std::endl;
        exit(-1);
    }
}

int main(int argc, char *argv[]) {
    validateArguments(argc);

    const char *argument = argv[1];
    Resource *rsc = nullptr;

    try {
        rsc = new Resource();
        rsc->use(argument);
    }
    catch (CustomLogicError &e) {
        std::cout << e.what() << std::endl;
    }
    delete rsc;

    return 0;
}

