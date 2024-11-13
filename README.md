# serialization

## Description

serialization library for C++. It support json format and binary format.

## Get start

```cpp
#include <serialization/serialization.h>
#include <string>
#include <vector>

namespace exmaple {

    class Person {
    public:
        std::string name;
        int age;
    };

    class Teacher : Person {
    public:
        std::vector<Person> students;
    };

    class EmptyClass {
    };

    class Student : Person {
    };

    enum Job : std::uint8_t {
        TEACHER,
        STUDENT
    };

}// namespace exmaple

CODEC(exmaple::Person, name, age)

CODEC_WITH_PARENT(exmaple::Teacher, exmaple::Person, students)// need: CODEC(exmaple::Person, name, age)

CODEC_NONE(exmaple::EmptyClass)

CODEC_NONE_WITH_PARENT(exmaple::Student, exmaple::Person)// need: CODEC(exmaple::Person, name, age)

CODEC_ENUM(exmaple::Job, std::uint8_t)

CODEC_UNIQUE_PTR(exmaple::Person)// need: CODEC(exmaple::Person, name, age)

CODEC_UNIQUE_PTR(exmaple::Teacher)// need: CODEC_WITH_PARENT(exmaple::Teacher, exmaple::Person, students)

CODEC_UNIQUE_PTR(exmaple::Student)// need: CODEC_WITH_PARENT(exmaple::Student, exmaple::Person)

exmaple::Teacher teacher_from_json(const rapidjson::Value<rapidjson::UTF8<>> &jsonValue) {
    exmaple::Teacher teacher;
    serialization::Codec<exmaple::Teacher>::template from_json<true>(jsonValue, teacher);
    return teacher;
}

rapidjson::Value<rapidjson::UTF8<>> teacher_to_json(const exmaple::Teacher &teacher) {
    rapidjson::Value<rapidjson::UTF8<>> jsonValue;
    serialization::Codec<exmaple::Teacher>::template to_json<true>(jsonValue, teacher);
    return jsonValue;
}

exmaple::Teacher teacher_from_binary(std::istream &istream) {
    exmaple::Teacher teacher;
    serialization::template from_binary<true>(istream, teacher);
    return teacher;
}

void teacher_to_binary(std::ostream &ostream, const exmaple::Teacher &teacher) {
    serialization::template to_binary<true>(ostream, teacher);
}
```
