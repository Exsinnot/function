data = []
with open("Python/Test/Data1.txt","r") as F:
    for x in F.readlines():
        data.append(x.strip().split(":"))

data[0][1] = "EXSINNOT"
print(data)

with open("Python/Test/Data1.txt","w") as F:
    for x in data:
        F.write(f"{x[0]}:{x[1]}\n")