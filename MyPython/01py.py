#!/usr/bin/env python3

class People:
    # 基本属性
    name = ''
    age = 0
    # 私有属性
    __weight = 0
    # 构造方法
    def __init__(self, name, age, weight):
        self.name = name
        self.age = age
        self.__weight = weight
    # 一般方法
    def speak(self):
        print("My name is %s, and I am %d years old." %(self.name, self.age))

class Student(People):
    grade = ''
    def __init__(self, name, age, weight, grade):
        People.__init__(self, name, age, weight)
        self.grade = grade

    def speak(self):
        print("My name is %s, and I am %d years old, learn in %d grade." %(self.name, self.age, self.grade))

p = Student('subond', 25, 69, 12)
p.speak()
