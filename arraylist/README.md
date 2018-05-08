# Array Lists
A data structure that serves as a dynamic array that can grow or shrink as needed.

## Implementation
This implementation includes the following files:
```
ArrayList.h
ArrayList.cpp
```
The algorithm will grow or shrink the array by 50% as necessary. For example, if you had an array of length 4 that was fully populated.
```
|1|2|3|4|
```
Then you decide to call arrayList.add(5), thus adding another element, it'd increase the capacity of the array by 50% resulting in:
```
|1|2|3|4|5| |
```
You see it added 2 new spaces because 4/2=2. The public "size" variable denotes how many non-null elements are in the arraylist, while the private "length" variable denotes how much capacity the array list currently has in memory. "Null" elements are denoted as the integer 0 in this implementation, thus making 0 and invalid entry.

An example of shrinking the array would be if you removed 4 and 5 off the end of the list by calling arrayList.removeRange(3, 4). It'd result in:
```
|1|2|3|
```
It shrunk the array down to 3 because it reached the point where 50+% of it was unused (6/2=3). In this implementation arraylists can never be smaller than length 1.
