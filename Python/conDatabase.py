import mysql.connector
import time
import datetime
dbconfig = {
    'host' : 'localhost',
    'user' : 'root',
    'password' : '',
    'database' : 'DB',
}

timestamp = int(time.time())
dt_object = datetime.datetime.fromtimestamp(timestamp)
cnx = mysql.connector.connect(**dbconfig)
cur = cnx.cursor()
coms = "INSERT INTO `HELPLIST` (`ID`, `info`, `Phone`, `com`, `time`) VALUES (NULL, %(info)s, %(Phone)s, %(com)s, %(time)s)"
latitude = 0
longitude = 0
phone = "3215767-231"
com="Hello"

datain = {
    'info': f"{latitude},{longitude}",
    'Phone': phone, 
    'com': com,
    'time': datetime.datetime(dt_object.year, dt_object.month, dt_object.day, dt_object.hour, dt_object.minute, dt_object.second)
} 
cur.execute(coms,datain)
cnx.commit()
cur.close()
cnx.close()


cnx = mysql.connector.connect(**dbconfig)
cur = cnx.cursor()
cur.execute(f"SELECT * FROM `Data` WHERE `time` LIKE '%test%'")
datadb = cur.fetchall()
cur.close()
cnx.close()