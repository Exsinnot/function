import requests
url = "https://watertele.egat.co.th/srdpm/dataStation/ajx_teledata_right.php?stationSI=16"
response = requests.get(url)
data = response.text
data = data.split("\r")
print(data[1].split("value='")[1].split("'")[0])