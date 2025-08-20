# serialization

## Description

serialization library for C++. It supports json format and binary format.

## Get start

```cpp
#include <serialization/serialization.h>
#include <string>
#include <vector>

namespace example {

    class Person {
    public:
        std::string name;
        int age;
    };

    class Teacher : public Person {
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

}// namespace example

CODEC(example::Person, name, age)

CODEC_WITH_PARENT(example::Teacher, example::Person, students)// need: CODEC(example::Person, name, age)

CODEC_NONE(example::EmptyClass)

CODEC_NONE_WITH_PARENT(example::Student, example::Person)// need: CODEC(example::Person, name, age)

CODEC_ENUM(example::Job, std::uint8_t)

CODEC_UNIQUE_PTR(example::Person)// need: CODEC(example::Person, name, age)

CODEC_UNIQUE_PTR(example::Teacher)// need: CODEC_WITH_PARENT(example::Teacher, example::Person, students)

CODEC_UNIQUE_PTR(example::Student)// need: CODEC_WITH_PARENT(example::Student, example::Person)

example::Teacher teacher_from_json(const rapidjson::GenericValue<rapidjson::UTF8<>> &jsonValue) {
    example::Teacher teacher;
    serialization::Codec<example::Teacher>::template from_json<rapidjson::GenericValue<rapidjson::UTF8<>>>(jsonValue, teacher);
    return teacher;
}

rapidjson::GenericDocument<rapidjson::UTF8<>> teacher_to_json(const example::Teacher &teacher) {
    rapidjson::GenericDocument<rapidjson::UTF8<>> jsonValue;
    serialization::Codec<example::Teacher>::template to_json<rapidjson::GenericDocument<rapidjson::UTF8<>>>(jsonValue.GetAllocator(), jsonValue, teacher);
    return jsonValue;
}

example::Teacher teacher_from_binary(std::istream &istream) {
    example::Teacher teacher;
    serialization::template from_binary<true>(istream, teacher);
    return teacher;
}

void teacher_to_binary(std::ostream &ostream, const example::Teacher &teacher) {
    serialization::template to_binary<true>(ostream, teacher);
}
```
