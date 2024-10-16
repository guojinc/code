import os
class Student:
    def __init__(self, sid, sname, sgender,\
                 sage, classname):
        self.sid = sid
        self.sname = sname
        self.sgender = sgender
        self.sage = sage
        self.classname = classname

    def show(self):
        print('学号:', self.sid)
        print('姓名:', self.sname)
        print('性别:', self.sgender)
        print('年龄:', self.sage)
        print('班级:', self.classname)
def pro4():
    stu_list = []
    while True:
        print("1. Add a student")
        print("2. Show all students")
        print("3. Exit")
        choice = input("Please select an option: ")
        if choice == '1':
            sid = input("Please input the student ID: ")
            sname = input("Please input the student name: ")
            sgender = input("Please input the student gender: ")
            sage = input("Please input the student age: ")
            classname = input("Please input the student class: ")
            student = Student(sid, sname, sgender, sage, classname)
            stu_list.append(student)
            print("Student added.")
        if (choice == '2'):
            for stu in stu_list:
                print("=====================================")
                stu.show()
                print("=====================================")
        if choice == '3':
            break
        os.system("pause")
        os.system("cls")