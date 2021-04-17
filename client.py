import socket

SERVER_IP = "127.0.0.1"
SERVER_PORT = 666

def main():
    sock = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    server_addr = (SERVER_IP,SERVER_PORT)
    sock.connect(server_addr)

    server_msg = sock.recv(5).decode()
    print(server_msg)
    if server_msg == "Hello":
        sock.sendall(server_msg.encode())

if __name__ == "__main__":
    main()