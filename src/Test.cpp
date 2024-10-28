//
// Created by Yancey on 2024-10-24.
//

#include "Test.h"
#include <iostream>
#include <serialization/serialization.h>
#include <string>

namespace example {
    class Person1 {// NOLINT(*-pro-type-member-init)
    public:
        std::string name = "Tom";
        int32_t age;
        std::vector<int> aaa;
    };
}// namespace example

// CODEC(example::Person1)
#define CODEC_BBB(v1) int v1 = 1;
#define CODEC_AAA(...) CODEC_PASTE(CODEC_BBB, __VA_ARGS__)
#define CODEC_CCC(...)         \
    void ccc() {               \
        CODEC_AAA(__VA_ARGS__) \
    }

int main(int argc, char *argv[]) {
    try {
        // rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));
        rapidjson::Document document;
        // document.ParseStream();
        example::Person1 person;
        if (document.HasParseError()) {
            throw std::runtime_error("json parse error");
        }
        // serialization::Codec<example::Person1>::from_json(document, person);
        assert(person.name == "Tom");
        assert(person.age == 18);
    } catch (std::exception &err) {
        std::cout << err.what() << std::endl;
    }
}
