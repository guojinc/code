from Pro_1 import good, goods
import json


def load():
    good_list = []
    try:
        with open("goods.json", "r", encoding="utf-8") as f:
            good_list = json.load(f)
            return good_list
    except FileNotFoundError:
        print("No json file found.")
        exit(0)
def dic_good(good_list):
    goods_list = []
    for good in good_list:
        goods_list.append({
            "pid": good.pid,
            "pname": good.pname,
            "price": good.price,
            "num": good.num,
            "acount": good.acount,
            "pdate": good.pdate
        })
    return goods_list

def save(good_list):
    with open("goods.json", "w", encoding="utf-8") as f:
        good_list = dic_good(good_list)
        json.dump(good_list, f)
        f.flush()




