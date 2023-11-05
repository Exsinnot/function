import random

class Box():
    def __init__(self,name,listitems) -> None:
        self.name = name
        self.listitems = listitems

RandomBox = []

def creatRandomBox():
    global RandomBox
    itemrate = []
    listbox = []
    name = input("Enter Name Box : ")
    while True:
        item = input("Enter Items : ")
        if item == "0":
            break
        rate = int(input("Enter Rate 1-100%: "))
        itemrate.append([item,rate])
    for x in itemrate:
        for j in range(x[1]):
            listbox.append(x[0])
    RandomBox.append(Box(name,listbox))
    
def ranbox(name):
    global RandomBox
    for x in RandomBox:
        if x.name == name:
            print(x.listitems[random.randint(0,99)])
            return
    print("NotFount")
creatRandomBox()

boxname = input("Enter Box name : ")
for x in range(20):
    ranbox(boxname)
        