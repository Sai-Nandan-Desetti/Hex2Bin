# Hex2Bin
The program converts hexadecimal instructions to binary ones.

### Details
All machine instructions on the standard version of the Simplified Instructional Computer have the following 24-bit format:
```
opcode(8)  x(1)   address(15)
```
* The number in the parentheses next to a particular indicate the number of bits needed to specify the value of that field.
* `x` is used to indicate indexed-addressing mode.

### Example
```
Enter the hexadecimal instruction: 03C300
Binary representation: 0000 0011 1100 0011 0000 0000
Opcode: 00000011
Mode: Indexed
Address: 100001100000000
```

## Reference
Book Title: *System Software - An Introduction to Systems Programming*

Author: Leland Beck.
