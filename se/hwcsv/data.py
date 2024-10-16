import csv
import platform
import os

def PrintInfo():
    print("Choose the way to query")
    print("1.Query name or score by id")
    print("2.Query id or score by name")
    print("3.Query name or id by score")
    print("4.Query score by id and name")
    print("5.Query name by score and id")
    print("6.Query id by name and score")
    print("7.Query if exists by name, score and id")
    print("0.exit")


def query(data, way):
    if way == 1:
        ID = input("ID: ")
        for item in data:
            if item["学号"] == ID:
                print(f"Name: {item['姓名']}, Score: {item['成绩']}")
                input()
                return
    if way == 2:
        Name = input("Name: ")
        for item in data:
            if item["姓名"] == Name:
                print(f"ID: {item['学号']}, Score: {item['成绩']}")
                input()
                return
    if way == 3:
        Score = input("Score: ")
        for item in data:
            if item["成绩"] == Score:
                print(f"ID: {item['学号']}, Name: {item['姓名']}")
                input()
                return
    if way == 4:
        Name = input("Name: ")
        ID = input("ID: ")
        for item in data:
            if item["姓名"] == Name and item["学号"] == ID:
                print(f"Score: {item['成绩']}")
                input()
                return
    if way == 5:
        Score = input("Score: ")
        ID = input("ID: ")
        for item in data:
            if item["成绩"] == Score and item["学号"] == ID:
                print(f"Name {item['姓名']}")
                input()
                return
    if way == 6:
        Score = input("Score: ")
        Name = input("Name: ")
        for item in data:
            if item["成绩"] == Score and item["姓名"] == Name:
                print(f"Name {item['学号']}")
                input()
                return
    if way == 7:
        Name = input("Name: ")
        ID = input("ID: ")
        Score = input("Score: ")
        for item in data:
            if item["成绩"] == Score and item["姓名"] == Name and item["学号"] == ID:
                print("Student Exists")
                input()
                return
    print("Student Not Exists")
    input()




def main():
    with open("data.CSV", "r", encoding='GBK') as file:
        data = csv.DictReader(file)
        while True:
            if platform.system() == "Windows":
                os.system("cls")
            else:
                os.system("clear")
            PrintInfo()
            UserInut = input("Your choice: ")
            try:
                if UserInut == "0":
                    break
                if int(UserInut) > 0 and int(UserInut) <= 7:
                    query(data, int(UserInut))
                else:
                    print("Invalid Input!")
                    input()
            except Exception as e:
                print("Invalid Input!")
                input()

if __name__ == '__main__':
    main()
