#!/usr/bin/env python3

class twoStack:

    def __init__(self, n):
        self.size = n;
        self.arr = [None] * n;
        self.top1 = -1;
        self.top2 = self.size

    def push1(self, x):
        if self.top1 < self.top2 - 1:
            self.top1 = self.top1 + 1
            self.arr[self.top1] = x
        else:
            print("Stack is Overflow")
            exit(1)

    def push2(self, x):
        if self.top1 < self.top2 - 1:
            self.top2 = self.top2 - 1
            self.arr[self.top2] = x
        else:
            print("Stack is Overflow")
            exit(1)

    def pop1(self):
        if self.top1 >= 0:
            x = self.arr[self.top1]
            self.top1 = self.top1 - 1
            return x
        else:
            print("Stack is Underflow")
            exit(1)

    def pop2(self):
        if self.top2 <= self.size:
            x = self.arr[self.top2]
            self.top2 = self.top2 - 1
            return x
        else:
            print("Stack is Underflow")
            exit(1)

ts = twoStack(5)
ts.push1(1)
ts.push1(2)
ts.push2(11)
ts.push2(12)

print("Stack1 pop " + str(ts.pop1()))
print("Stack2 pop " + str(ts.pop2()))
