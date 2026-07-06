#include <stdio.h>
#include "hashmap.h"

int main(void) {
    // Creating a hashmap with 10 buckets
    hashmap map = hashmap_create(10);
    if (map == NULL) printf("There was an error with the creation of the hashmap\n");

    hashmap_set(map, "one", 1);
    hashmap_set(map, "two", 2);
    hashmap_set(map, "three", 3);
    hashmap_set(map, "four", 4);
    hashmap_set(map, "one", 11);


    // Current size
    printf("Current elements: %d\n", hashmap_size(map));

    // Finding values
    int value;
    if (hashmap_get(map, "one", &value)) printf("'one' -> %d\n", value);

    if (hashmap_get(map, "two", &value)) printf("'two' -> %d\n", value);

    if (hashmap_get(map, "five", &value) == -4) printf("'five' not found\n");


    // Checking for specific keys
    printf("Contains 'three'? %s\n", hashmap_has_key(map, "three") ? "Yes" : "No");
    printf("Contains 'eight'? %s\n", hashmap_has_key(map, "eight") ? "Yes" : "No");


    // list of keys
    list keys = hashmap_get_keys(map);
    printf("Keys: ");
    iterator _it = iterator_create(keys);

    while (iterator_has_next(_it)) {
        char* key = (char*)iterator_next(_it);
        printf("%s ", key);
    }
    printf("\n");
    iterator_destroy(&_it);
    list_destroy(&keys);

    hashmap_destroy(&map);

    return 0;
}
