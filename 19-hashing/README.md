# Hashing

- Key-Value pair
- Eg: menu of a Restaurant Item-Price

- Unordered DS
- Search: O(1)
- Insert: O(1)
- Erase: O(1)

## Hash Function

- key needs to be converted into address (int) - done with hash function
- data is stored in the address

## Collision

- if address for keys are same, they cause COLLISION
  - good hash function + collision handling strategy

* open hashing / separate chaining \*
* other techniques: closed hashing, double hashing

- good table distribution
- better table size as prime number

* k mod tableSize
* handling "string keys"
  - sum of ascii values (bad distribution) + anagrams cause collision
  - better approach: weighted sum

- Separate Chaining

  - implemented using Linked List
  - the linked list should be kept small
  - load factor - on reaching a threshold double tableSize

- https://youtu.be/UJkE-apV9Dk
  - unordered_map, map
    - Example: linked list contains cycle?, phone book (ordered by alphabetical order)
  - unordered_set, set
    - pair sum K
