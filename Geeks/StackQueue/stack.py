#!/usr/bin/env python3

class Stack:
    """模拟栈的基本操作"""
    # 初始化
    def __init__(self):
        self.item = []
    # 判空
    def isEmpty(self):
        return len(self.item) == 0
    # 压栈
    def push(self, data):
        self.item.append(data)
    # 出栈
    def pop(self):
        if not self.isEmpty():
            return self.item.pop()
    # 去栈顶元素
    def top(self):
        if not self.isEmpty():
            return self.item[len(self.item)-1]
    # 栈的大小
    def size(self):
        return len(self.item)

s = Stack()
s.push(1)
s.push(3)
s.push(4)
print(s.top())
s.pop()
print(s.top())
s.pop()
s.pop()
print(s.top())
s.pop()

def SortedInsert(s, x):
    if s.isEmpty() or x > s.top():
        s.push(x)
        return;
    else:
        temp = s.top()
        s.pop()
        SortedInsert(s, x)
        s.push(temp)

def StackSort(s):
    if not s.isEmpty():
        temp = s.top()
        s.pop()
        StackSort(s)
        SortedInsert(s, temp)
