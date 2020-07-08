class Human(object):
    def __init__(self,name,age):
        self.__name=name
        self.__age=age

    def get_name(self):
        return self.__name

    def get_age(self):
        return self.__age


zls=Human('zls',19)

#print(zls.get_age())

class Student(Human):
    count=0
    def __init__(self,name):
        self.__name=name
        Student.count+=1
print(Student.count)
a=Student('zls')
b=Student('cyf')
print(Student.count)