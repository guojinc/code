from Pro_1 import good, goods
import json
from Pro_2 import load, save
import os

def main():
    goods_list = load()
    Goods = goods()
    for good in goods_list:
        Goods.Add(good)

    while True:
        print("1. Add product")
        print("2. Show all products")
        print("3. Delete product")
        print("4. Find and show product")
        print("5. Modify product")
        print("6. Save and exit")
        choice = input("Please input your choice: ")
        if choice == "1":
            Goods.add()
        elif choice == "2":
            Goods.show_all()
        elif choice == "3":
            Goods.delete()
        elif choice == "4":
            Goods.find()
        elif choice == "5":
            Goods.modify()
        elif choice == "6":
            save(Goods.goods_list)
            break
        else:
            print("Invalid input.")
        os.system("pause")
        os.system("cls")

if __name__ == "__main__":
    main()