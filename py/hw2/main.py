import Pro_1
import Pro_2
import Pro_3
import Pro_4
import os
if __name__ == '__main__':
    while True:
        print("1. Pro_1")
        print("2. Pro_2")
        print("3. Pro_3")
        print("4. Pro_4")
        print("0. Exit")
        choice = input("Please select a problem: ")
        if choice == '1':
            Pro_1.pro1()
        elif choice == '2':
            Pro_2.pro2()
        elif choice == '3':
            Pro_3.pro3()
        elif choice == '4':
            Pro_4.pro4()
        elif choice == '0':
            break
        else:
            print("Invalid choice. Please try again.")
        os.system("pause")
        os.system("cls")

        
