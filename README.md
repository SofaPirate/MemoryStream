This Arduino library is mainly used for debugging purposes. It provides a Stream class that writes and reads from a single/common buffer, allowing to test your functions and algorithms.

Example usage:

```
StringStream stream;
stream.write(42);
int val = stream.read(); // <-- variable "val" will contain value 42
```
