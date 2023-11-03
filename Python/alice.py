print(open("Python/Test/alice.txt",'r').read().count("Alice"))
text = open("Python/Test/alice.txt",'r').read()
all = open("Python/Test/alice.txt",'r').readlines()
for index,x in enumerate(all):
    all[index] = all[index].strip("?-_/.,'"+'"`!\n')
word = []
for x in all:
    for j in x.split(' '):
        if j in word or j == '':
            continue
        else:
            word.append({j:text.count(j)})
for x in word:
    print(x)