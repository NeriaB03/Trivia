import socket
import json

SERVER_IP = "127.0.0.1"
SERVER_PORT = 666
MT_CLIENT_LOG_IN = '2'
MT_CLIENT_SIGN_UP = '3'
MT_SERVER_ERROR = '7'

def getDataFromUser(command):
    return input(command)

def login(sock):
    username = getDataFromUser("Please Enter Your Username: ")
    password = getDataFromUser("Please Enter Your Password: ")
    loginJson = '{"username":"%s","password":"%s"}'%(username,password)
    loginJson = json.loads(loginJson)
    loginReq = MT_CLIENT_LOG_IN + str(len(json.dumps(loginJson))).zfill(4) + json.dumps(loginJson)
    sock.sendall(loginReq.encode())

def signup(sock):
    username = getDataFromUser("Please Enter Your Username: ")
    password = getDataFromUser("Please Enter Your Password: ")
    email = getDataFromUser("Please Enter Your Email: ")
    signupJson = '{"username":"%s","password":"%s","email":"%s"}'%(username,password,email)
    signupJson = json.loads(signupJson)
    signupReq = MT_CLIENT_SIGN_UP + str(len(json.dumps(signupJson))).zfill(4) + json.dumps(signupJson)
    sock.sendall(signupReq.encode())

def main():
    sock = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    server_addr = (SERVER_IP,SERVER_PORT)
    sock.connect(server_addr)
    option = "2"
    while(option != "0" and option != "1"):
        option = input("Would you like to signup or login? (0 - for login, 1 - for signup)")
        if option == "0":
            login(sock)
        elif option == "1":
            signup(sock)
        else:
            print("Try again next time...")
    server_response = sock.recv(1024).decode()
    print(json.loads(server_response)["Message"])

if __name__ == "__main__":
    main()