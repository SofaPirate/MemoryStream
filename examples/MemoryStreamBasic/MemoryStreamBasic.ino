/*
 * MemoryStreamBasic example
 * Copyright (C) 2016 Sofian Audry -- info(@)sofianaudry(.)com
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
#include <MemoryStream.h>

// Declare MemoryStream.
MemoryStream stream;

void setup() {
  Serial.begin(57600);
}

void loop() {
  // Write to stream.
  stream.println("Hello world!");

  // Read from stream and send it to Serial.
  while (stream.available())
    Serial.write(stream.read());
}
