//
// Created by Ekyso on 12/14/2021.
//

#ifndef CH9_HASHMAP_CHAINING2_HASH_H
#define CH9_HASHMAP_CHAINING2_HASH_H
/** Hash Function Objects Template */
template<typename Key_Type>
struct hash {
    size_t operator()(const Key_Type&) {};
};

// Write a specialization for string
#include <string>
template<>
struct hash<std::string> {
    size_t operator()(const std::string& s = "") {
        size_t result = 0;
        for (size_t i = 0; i < s.length(); i++) {
            result = result * 31 + s[i];
        }
        return result;
    }
};

// Write a specialization for int
template<>
struct hash<int> {
    size_t operator()(int i = 0) {
        return size_t(4262999287U * i);
    }
};


#endif //CH9_HASHMAP_CHAINING2_HASH_H
