#include <cstdio>
#include <memory>
#include <string>

using ShoppingList = std::shared_ptr<std::FILE>;

ShoppingList makeFile(const char *filename, const char *flags) {
    return std::shared_ptr<FILE>(fopen(filename, flags), [](FILE *f) { fclose(f); });
}

class Partner {
public:
    ShoppingList shoppingList;

    void addToFile(const std::string &element) {
        fprintf(shoppingList.get(), "%s", element.c_str());
    }
};

int main() {

    Partner boy{};
    boy.shoppingList = makeFile("ShoppingList", "wb");

    Partner girl{};
    girl.shoppingList = boy.shoppingList;
    girl.addToFile("Butter");
    girl.addToFile("Milk");

    return 0;
}
