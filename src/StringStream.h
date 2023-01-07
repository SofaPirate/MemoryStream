/*
 * StringStream
 * Copyright (C) 2016-2022 Sofian Audry -- info(@)sofianaudry(.)com
 * 
 * This library is mainly used for debugging purposes. It writes and reads
 * from a single/common buffer, allowing to test your functions and algorithms.
 * 
 * Example use:
 * <code>
 * StringStream stream;
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
#ifndef STRING_STREAM_H_
#define STRING_STREAM_H_

#include <Stream.h>

#ifndef STRING_STREAM_BUFFER_SIZE 128
#define STRING_STREAM_BUFFER_SIZE 128
#endif

class StringStream : public Stream
{
public:
  StringStream();

  // Stream methods
  virtual int available() { return length; }
  
  virtual int read();
  
  virtual int peek();
  
  virtual void flush() { }
  
  virtual size_t write(uint8_t c);

private:
  // Circular buffer containing the information.
  uint8_t buffer[STRING_STREAM_BUFFER_SIZE];
  
  // Current write position in the circular buffer.
  int writePos;
  
  // Current read position in the circular buffer.
  int readPos;
  
  // Currentl length of the data available in buffer.
  int length;
};

#endif


