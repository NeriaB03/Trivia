import socket
import json

SERVER_IP = "127.0.0.1"
SERVER_PORT = 666
MT_CLIENT_LOG_IN = '2'
MT_CLIENT_SIGN_UP = '3'
MT_SERVER_ERROR = '7'

def main():


    sock = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    server_addr = (SERVER_IP,SERVER_PORT)
    sock.connect(server_addr)
    option = "2"
    while(option != "0" and option != "1"):
        option = input("Would you like to signup or login? (0 - for login, 1 - for signup)")
        if option == "0":
            loginJson = '{"username":"user1","password":"1234"}'
            loginJson = json.loads(loginJson)
            loginReq = MT_CLIENT_LOG_IN + str(len(json.dumps(loginJson))).zfill(4) + json.dumps(loginJson)
            sock.sendall(loginReq.encode())
        elif option == "1":
            signupJson = '{"username":"user1","password":"1234","mail":"user1@gmail.com"}'
            signupJson = json.loads(signupJson)
            signupReq = MT_CLIENT_SIGN_UP + str(len(json.dumps(signupJson))).zfill(4) + json.dumps(signupJson)
            print(signupReq)
            sock.sendall(signupReq.encode())
        else:
            print("Try again next time...")
    server_response = sock.recv(1024).decode()
    print(server_response)

if __name__ == "__main__":
    main()