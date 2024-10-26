//
// Created by Yancey on 2024-10-24.
//

#pragma once

#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <serialization/serialization.h>
#include <string>

class Person1 {// NOLINT(*-pro-type-member-init)
public:
    std::string name = "Tom";
    int32_t age;
    std::vector<int> aaa;
};

CODEC(Person1, name, age, aaa)

int main(int argc, char *argv[]) {
    try {
        rapidjson::Document document;
        document.Parse(R"({"age":18, "name":"Tom", "aaa": [1, 2, 3]})");
        Person1 person;// NOLINT(*-pro-type-member-init)
        if (document.HasParseError()) {
            throw std::runtime_error("json parse error");
        }
        serialization::Codec<Person1>::from_json(document, person);
        assert(person.name == "Tom");
        assert(person.age == 18);
    } catch (serialization::JsonSerializationKeyException &err) {
        std::cout << err.what() << std::endl;
    }
}

#endif//TEST_H
