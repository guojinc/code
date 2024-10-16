import os
class good():
    def __init__(self, pid, pname, price, num, acount, pdate):
        self.pid = pid
        self.pname = pname
        self.price = price
        self.num = num
        self.acount = acount
        self.pdate = pdate

    def show(self):
        print('商品ID:', self.pid)
        print('商品名称:', self.pname)
        print('商品价格:', self.price)
        print('商品数量:', self.num)
        print('商品总价:', self.acount)
        print('商品日期:', self.pdate)

class goods():
    def __init__(self):
        self.goods_list = []


    def get_good(self):
        pid = input("Please input the product ID: ")
        for good in self.goods_list:
            if good.pid == pid:
                print("Product ID already exists.")
                return
        pname = input("Please input the product name: ")
        price = float(input("Please input the product price: "))
        num = int(input("Please input the product number: "))
        pdate = input("Please input the product date: ")
        item = good(pid, pname, price, num, price * num, pdate)
        self.goods_list.append(item)
        print("Product added.")
        return item
    
    def show_all(self):
        if not self.goods_list:
            print("No products.")
            return
        str = ["Product ID", "Product Name", "Price", "Number", "Total Price", "Date"]
        ident = 15
        print(f"{str[0]:^{ident}}{str[1]:^{ident}}{str[2]:^{ident}}{str[3]:^{ident}}{str[4]:^{ident}}{str[5]:^{ident}}")
        for good in self.goods_list:
            print(f"{good.pid:^{ident}}{good.pname:^{ident}}{good.price:^{ident}}{good.num:^{ident}}{good.acount:^{ident}}{good.pdate:^{ident}}")
    def sort(self):
        self.goods_list.sort(key = lambda x: x.price)

    #用于从json文件中添加数据
    def Add(self, added : dict):
        self.goods_list.append(good(added['pid'], added['pname'], added['price'], added['num'], added['acount'], added['pdate']))

    #用于从输入添加数据
    def add(self):
        good = self.get_good()
        self.sort()
    
    def delete(self):
        pid = input("Please input the product ID: ")
        good = iter(self.goods_list)
        while True:
            try:
                item = next(good)
                if item.pid == pid:
                    self.goods_list.remove(item)
                    print("Product deleted.")
                    break
            except StopIteration:
                print("Product not found.")
                break
    
    def modify(self):
        pid = input("Please input the product ID: ")
        good = iter(self.goods_list)
        while True:
            try:
                item = next(good)
                if item.pid == pid:
                    os.system("cls")
                    print("Found product, please input the new information.")
                    new = self.get_good()
                    self.goods_list.remove(item)
                    self.goods_list.append(new)
                    print("Product modified.")
                    break
            except StopIteration:
                print("Product not found.")
                break
    
    def find(self):
        pid = input("Please input the product ID: ")
        for good in self.goods_list:
            if good.pid == pid:
                print("=====================================")
                good.show()
                print("=====================================")
                break
        else:
            print("Product not found.")
