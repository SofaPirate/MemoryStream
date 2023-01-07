Arduino library providing a simple Stream class that allows to read and write to a common buffer. It can be used to simulate streaming such as 
serial communication, typically for debugging and testing purposes.

Example usage:

```c++
#include <StringStream.h>

// Create StringStream object.
StringStream stream;

void setup() {
  Serial.begin(115200);
}

void loop() {
  // Write value.
  stream.write(123);

  // Read value.
  int val = stream1.read(); // variable "val" will contain value 123
  Serial.println(val); // will print "123"

  // Write string.
  stream.println("Hello!");
  Serial.println(stream.readString()); // will print "Hello!"
}
```

By default, the size of the buffer is 128 bytes. This can be changed by defining `STRING_STREAM_BUFFER_SIZE` before including the library:

```c++

#define STRING_STREAM_BUFFER_SIZE 64
#include <StringStream.h>
```
