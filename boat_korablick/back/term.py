import socket
import eel
from time import gmtime, strftime
import os

# секунды прошли с эпох
 # @eel.expose
 # def stop_temper():
 # os.remove( r"C:\Users\dnk\Desktop\boat_korablick\front\veter.txt")

@eel.expose
def temper():

    HOST = "172.28.133.117"  # Standard loopback interface address (localhost)
    PORT = 65200  # Port to listen on (non-privileged ports are > 1023)
    print("trm")

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

    
   
    veter_f = open(r"C:\Users\dnk\Desktop\boat_korablick\front\veter.txt","a")   

    veter_f.write("status: " + str(data)+ str(local_time)+'\n')   
