
import os
import socket
import sqlite3
import selectors
import struct

PORT =1234
HOST = '0.0.0.0'
def get_port():
    try:
        dir = os.path.dirname(os.path.abspath(__file__))
        path = os.path.join(dir, "myport.info")
        with open(path, "r") as f:
            p = f.read()
            PORT = int(p.strip())
    except FileExistsError:
        print("")
    except Exception as e:
        print(e)
   
sel = selectors.DefaultSelector()


## accept connection to client
def accept(sock):
    conn, addr = sock.accept()  
    print('accepted', conn, 'from', addr)
    conn.setblocking(False)
    sel.register(conn, selectors.EVENT_READ, handle)





## handle clients and messages

def handle(conn, mask):
    data = conn.recv(1024) 
    if data:
      data
      print("helo")  
    else:
        print('closing', conn)
        sel.unregister(conn)
        conn.close()



def main():
    print("main now")
    get_port()

    try:
        sock = socket.socket()
        sock.bind((HOST,PORT))
        sock.listen()
        sock.setblocking(False)
        sel.register(sock, selectors.EVENT_READ, accept)
        while True:
            events = sel.select()
            for key, mask in events:
                callback = key.data
                callback(key.fileobj)
    except Exception as e:
        print(e)
    except KeyboardInterrupt:
        print("bye")

if __name__ == "__main__":
    print("starting")
    main()