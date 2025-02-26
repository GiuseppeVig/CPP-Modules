#include "Serializer.hpp"

int main() {
    Data data;
    data.name = "Alice";
    data.age = 25;

    std::cout << "Original Data Address: " << &data << std::endl;
    std::cout << "Original Name: " << data.name << ", Age: " << data.age << std::endl;

    // Serialize and Deserialize
    uintptr_t raw = Serializer::serialize(&data);
    Data* newData = Serializer::deserialize(raw);

    std::cout << "Deserialized Data Address: " << newData << std::endl;
    std::cout << "Deserialized Name: " << newData->name << ", Age: " << newData->age << std::endl;

    // Check if deserialized pointer matches the original pointer
    if (newData == &data) {
        std::cout << "✅ Serialization and Deserialization successful!" << std::endl;
    } else {
        std::cout << "❌ Error: Deserialized pointer does not match original." << std::endl;
    }

    return 0;
}
