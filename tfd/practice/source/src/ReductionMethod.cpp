//
// Copyright 2018 sarroutbi at yahoo.es
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.

#include "ReductionMethod.hpp"

void ReductionMethod::resolve() {
  // NOTE: RESOLUTION METHOD PENDING. BASICALLY WOULD FOLLOW NEXT STEPS
  // 1) Get Names of Var Names (x, y)
  // 2) Obtain the values for first name (x) for each of the equation (3, 6)
  // 3) Multiply between them (3*6 = 18)
  // 4) Split between the value (18/3 = 6; 18/6 = 3)
  // 5) Apply splitted value and multiply by -1
  // 6) Sum both equations to erase one variable and resolve the other
}

ReductionMethod::~ReductionMethod() {}
