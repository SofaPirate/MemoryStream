/*
 * MemoryStream
 * Copyright (C) 2016-2022 Sofian Audry -- info(@)sofianaudry(.)com
 * 
 * This library is mainly used for debugging purposes. It writes and reads
 * from a single/common buffer, allowing to test your functions and algorithms.
 * 
 * Example use:
 * <code>
 * MemoryStream stream;
 * stream.write(42);
 * int val = stream.read(); // <-- variable "val" will contain value 42
 * </code>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "MemoryStream.h"

MemoryStream::MemoryStream() : writePos(0), readPos(0), length(0) {}

int MemoryStream::read() {
  int val = peek();
  if (val >= 0) {
    readPos = (readPos+1) % MEMORY_STREAM_BUFFER_SIZE;
    length--;
  }
  return val;
}
  
int MemoryStream::peek() {
  return ( available() == 0 ? (-1) : (int)buffer[readPos] );
}
  
size_t MemoryStream::write(uint8_t c) {
  if (length >= MEMORY_STREAM_BUFFER_SIZE)
    return 0; // buffer is full
  else
  {
    buffer[writePos] = c;
    writePos = (writePos+1) % MEMORY_STREAM_BUFFER_SIZE;
    length++;
    return 1;
  }
}
