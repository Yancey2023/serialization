# serialization

## Description

serialization library for C++. It support json format and binary format.

## Get start

```cpp
#include <string>
#include <vector>

namespace exmaple {

    class Person {
        std::string name;
        int age;
    };

}

CODEC_H(exmaple::Person)
```

## TODO

1. macro: SERIALIZATION_ONLY_READ_FROM_BINARY
2. cmake target: serialization_only_read_from_binary
3. util: JsonUtil, BinaryUtil (or add in BasicCodec?)
4, change: use char* instead object key std::string



