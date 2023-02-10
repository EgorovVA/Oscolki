import socket
import eel
from time import gmtime, strftime
import os
from os import path
import shutil
# секунды прошли с эпох
#@eel.expose
#def stop_ustroistvo():
   # if path.exists("C:\Users\dnk\Desktop/boat_korablick/front"):
      #  shutil.rmtree("C:\Users\dnk\Desktop/boat_korablick/front)
@eel.expose
def ustroistvo():

    HOST = "172.28.133.117"  # Standard loopback interface address (localhost)
    PORT = 65500  # Port to listen on (non-privileged ports are > 1023)
    print("aksi")

    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    
        s.bind((HOST, PORT))
        s.listen()
        conn, addr = s.accept()
        with conn:
            print(f"Connected by {addr}")
            while True:
      
                local_time = strftime("%Y-%m-%d %H:%M:%S", gmtime())

                data = conn.recv(1024)
                print(data, local_time)
                break

    weather_f = open(r"C:\Users\dnk\Desktop\boat_korablick\front\weather.txt", "a")
    weather_f.write("status: " + str(data)+ str(local_time)+'\n')
   


    


