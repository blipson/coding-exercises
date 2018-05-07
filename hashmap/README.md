# Hash Maps
A data structure for efficiently and dynamically storing items of key->value pairs in memory. It employs the use of a hash function to decide at what location to store items. Accomodation is made for collision, a scenario in which the hash funciton decides to store an item in a location already taken up by another item. The average cost per operation in a hash table is entirely divorced from the number of items already stored in the hash table, thus making it a good data structure for storing lots of items.

## Implementation #1: Linear Probing
This implementation includes the following files:
```
headers/HashEntryLinearProbing.h
headers/HashMapLinearProbing.h
implementation/HashEntryLinearProbing.cpp
implementation/HashMapLinearProbing.cpp
```
It utilizes linear probing to accomodate collision. In linear probing, values are stored in order starting at index 0, and ending at the last index of the table. When it's found that a value already exists in the desired location, the algorithm simply moves to the next one. For example, imagine you have an empty table of size 5.
```
| | | | | |
```
Then you insert a key->value pair. In this case let's say it's a name and an address.
```
|{"Ben", "123 Fake St"}| | | | |
```
You see it got inserted at the first index. Now let's add another entry.
```
|{"Ben", "123 Fake St"}|{"Jeffrey", "222 NotReal Ave"}| | | |
```
When entering Jefferey's information, the algorithm first looked at the first index in the table and saw that it was already taken, so it moved on to the next index.
### Handling Duplicates
Depending on the implementation, a hash map may or may not allow for multiple values on duplicate keys. In this case it does. It treats duplicate values no differently than any other value. It'll just insert it at the next available index. So if we try to enter another address for Ben we'll get.
```
|{"Ben", "123 Fake St"}|{"Jeffrey", "222 NotReal Ave"}|{"Ben", "333 Another Ln"}| | |
```
This makes sense in this case because there could be two different people both named Ben who live in different places.

## Implementation #1: Separate Chaining
This implementation includes the following files:
```
headers/HashEntrySeparateChaining.h
headers/HashMapSeparateChaining.h
implementation/HashEntrySeparateChaining.cpp
implementation/HashMapSeparateChaining.cpp
```
It utilizes separate chaining to accomodate collision. In separate chaining, values are stored based on a hash function, in this case it's based on the ASCII value of the key string modded by the table size. When it's found that a value already exists in the desired location, the algorithm creates a second entry at that same index. This is possible because each entry holds a HashEntrySeparateChaining* pointer value within it that defaults to null. To put another entry at that index you write that pointer to point to the value of your new entry. This essentially creates a linked list at every index of the table. For example, imagine you have an empty table of size 5.
```
| | | | | |
```
Then you insert a key->value pair. In this case we'll just use some test values.
```
| |{"testkey", "testvalue"}| | | |
```
You see it got inserted at the second index. This is because our hash function took the ASCII value of "testkey" (which is 777) and modded it by the table size (which is 5), thus yielding the remainder value 2. Now let's add another entry.
```
| |{"testkey", "testvalue"}|{"testkeytwo", "testvalue"}| | |
```
It gets inserted at the third index because "testkeytwo" has an ASCII value of 1123, which when divided by our table size (5) yields a remainder value of 3. Let's add an entry that requires our linked list implementation.
```
    | |{"testkey", "testvalue", aaaaa*}|{"testkeytwo", "testvalue"}| | |
      |{"aaaaa", "aaaaa"}              |
 ```
 You can see that the entry with the key "aaaaa" got entered into the second index, because "aaaaa" has an ASCII value of 582, which yields 2 when divided by 5. But since there was already an entry at index 2, it created a new pointer to the next entry, which I've denoted as aaaaa*, and added the aaaaa entry to the linked list.
### Handling Duplicates
Depending on the implementation, a hash map may or may not allow for multiple values on duplicate keys. In this case it does not, but if it did it'd treat duplicate values no differently than any other value. It'd just insert it at the appropriate index, which would necessarily require creating a new entry in a linked list since it must have the same ASCII value as the duplicate key. So if we try to enter another address for "testkeytwo" we'll get.
```
    | |{"testkey", "testvalue", aaaaa*}|{"testkeytwo", "testvalue", testkeytwo*}| | |
      |{"aaaaa", "aaaaa"}              |{"testkeytwo", "anothertestvalue"}      |
 ```
Sometimes it makes sense to disallow duplicates, like if you're wanting to store key->value pairs of database primary keys->value of a column in that database. Primary keys must be unique, and thus a data structure that disallows unique entries is more useful. It's also not even necessary to account for collision (although this implementation still does) if you disallow unique key constraints. You could have a different hash function which ensures that new items always get put in new indexes, in which case disallowing duplicates would remove unnecessary overhead and allow for more efficiency.
