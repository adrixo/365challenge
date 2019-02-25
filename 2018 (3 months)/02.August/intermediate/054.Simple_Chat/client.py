#!/usr/bin/python

from socket import AF_INET, socket, SOCK_STREAM
from threading import Thread

def receive(serverSocket):
    while True:
        try:
            msg = serverSocket.recv(BUFSIZ).decode("utf8")
            print(msg)
        except OSError:
            break


# host and port
HOST = input('Enter host: ')
if not HOST:
    HOST = 'localhost'
PORT = input('Enter port: ')
if not PORT:
    PORT = 33001
else:
    PORT = int(PORT)

BUFSIZ = 1024
ADDR = (HOST, PORT)

client_socket = socket(AF_INET, SOCK_STREAM)
client_socket.connect(ADDR)


msg = str(input("Enter your name: "))
client_socket.send(bytes(msg, "utf8"))
Thread(target=receive, args=(client_socket,)).start()

while msg != "{quit}":
    msg = str(input("> "))
    client_socket.send(bytes(msg, "utf8"))

client_socket.send(bytes(msg, "utf8"))
client_socket.close()
