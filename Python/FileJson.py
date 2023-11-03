import json
data = {} #json
with open("data.json", 'w') as json_file: #save
    json.dump(data, json_file)
    
with open("data.json", 'r') as json_file: #read
    data1 = json.load(json_file)