# serialization

## Description

serialization library for C++. It support json format and binary format.

## Get start

Person.h

```cpp
#include <string>
#include <vector>

namespace exmaple {

    class Person {
        std::string name;
        int age;
    };

    CODEC_H(Person)

}
```

Person.cpp

```cpp
#include "Person.h

namespace exmaple {
    
    CODEC(Person, name, age)
    
}
```

main.cpp

```cpp
#include <Person.h>

int main() {
    Person person;
    person
    JsonUtil.encode(person);
}
```
