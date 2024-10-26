//
// Created by Yancey on 2024-10-24.
//

#pragma once

#ifndef TEST_H
#define TEST_H

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
    rapidjson::Document document;
    document.Parse("({\"age\":18, \"name\":\"Tom\"})");
    Person1 person;// NOLINT(*-pro-type-member-init)
    serialization::Codec<Person1>::from_json(document, person);
    assert(person.name == "Tom");
    assert(person.age == 18);
}

#endif//TEST_H
