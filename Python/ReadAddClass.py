class Items:
    def __init__(self,name,price,amount,count) -> None:
        self.name = name
        self.price = price
        self.amount = amount
        self.count = count
        
    def editprice(self,newprice):
        self.price = newprice
        
    def addcount(self,count):
        self.count += count
        
    def ckcount(self):
        return self.count

listitems = []

def readItems():
    global listitems
    with open("Python/Test/Items.txt","r") as f:
        data = f.readlines()
        for x in data:
            listitems.append(Items(x.strip().split(',')[0],x.strip().split(',')[1],x.strip().split(',')[2],x.strip().split(',')[3]))
        

