class ST:
    grade = []
    def __init__(self,id) -> None:
        self.id = id
    def saveGrade(self,sub,grade):
        subs = sub.lower()
        for item in self.grade:
            if subs in item:
                return
        self.grade.append({subs:grade})
    def EditGrade(self,sub,ngrade):
        subs = sub.lower()
        for index,item in enumerate(self.grade):
            if subs in item:
                self.grade[index][subs] = ngrade
                return
        print("NOT FOND")

import json

stid = []

def savedata():
    global stid
    stidjson = {
        "id" : [],
        "grade" : []
    }
    for x in stid:
        stidjson["id"].append(x.id)
        save = []
        for j in x.grade:
            save.append(j)
        stidjson["grade"].append(save)
    with open("Python/Test/stid.json", 'w') as json_file:
        json.dump(stidjson, json_file)

def readdata():
    global stid
    with open("Python/Test/stid.json", 'r') as json_file: 
        data1 = json.load(json_file)
    for x in range(len(data1['id'])):
        st = ST(data1['id'][x])
        st.grade = data1['grade'][x]
        stid.append(st)

def CreateID():
    global stid
    id = input("Enter ID : ")
    for x in stid:
        if x.id == id:
            return False
    stid.append(ST(id))
    return True

readdata()
while True:
    o = input("1.Create ID\n2.Edit ID\n3.DEL ID\n0.Exit\nEnter : ")
    if o == '1':
        if CreateID():
            savedata()
            print("สำเร็จ")
        else:
            print("ซ้ำ")
    elif o == '2':
        id = input("Enter ID : ")
        ck = 0
        for x in stid:
            if x.id == id:
                while True:
                    print(f"ID : {x.id}")
                    for k in x.grade:
                        print(f"{k}")
                    c = input("1.Add Grade\n2.Edit Grade \n0.Exit\nEnter : ")
                    if c == '1':
                        sub = input("Enter Sub : ")
                        grade = input("Enter Grade : ")
                        x.saveGrade(sub,grade)
                        savedata()
                    elif c == '2':
                        sub = input("Enter Sub : ")
                        grade = input("Enter Grade : ")
                        x.EditGrade(sub,grade)
                        savedata()
                    elif c == '0':
                        ck = 1
                        break
            if ck == 1:
                break
        print("Not Foud")
    elif o == '3':
        id = input("Enter ID : ")
        ck = 0
        for x in stid:
            if x.id == id:
                stid.remove(x)
                savedata()
                break
    elif o == '0':
        break