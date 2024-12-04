import socket
import threading

# Simple Client-Server Model
# Server Code
def simple_server():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind(("localhost", 12345))
    server.listen(1)
    print("Simple Server: Listening for connections...")

    conn, addr = server.accept()
    print(f"Connected by {addr}")

    data = conn.recv(1024)
    print(f"Received: {data.decode()}")
    conn.sendall(b"Hello from server")
    conn.close()

# Client Code
def simple_client():
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect(("localhost", 12345))
    client.sendall(b"Hello from client")
    response = client.recv(1024)
    print(f"Server Response: {response.decode()}")
    client.close()

# Iterative Client-Server Model
# Server Code
def iterative_server():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind(("localhost", 12346))
    server.listen(5)
    print("Iterative Server: Listening for connections...")

    while True:
        conn, addr = server.accept()
        print(f"Connected by {addr}")

        data = conn.recv(1024)
        print(f"Received: {data.decode()}")
        conn.sendall(b"Response from iterative server")
        conn.close()

# Client Code
def iterative_client():
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect(("localhost", 12346))
    for i in range(3):
        client.sendall(f"Message {i+1} from client".encode())
        response = client.recv(1024)
        print(f"Server Response: {response.decode()}")
    client.close()

# Concurrent Client-Server Model
# Server Code
def handle_client(conn, addr):
    print(f"Connected by {addr}")
    data = conn.recv(1024)
    print(f"Received: {data.decode()}")
    conn.sendall(b"Response from concurrent server")
    conn.close()

def concurrent_server():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind(("localhost", 12347))
    server.listen(5)
    print("Concurrent Server: Listening for connections...")

    while True:
        conn, addr = server.accept()
        thread = threading.Thread(target=handle_client, args=(conn, addr))
        thread.start()

# Client Code
def concurrent_client():
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect(("localhost", 12347))
    client.sendall(b"Hello from concurrent client")
    response = client.recv(1024)
    print(f"Server Response: {response.decode()}")
    client.close()

# Choose which model to run
if __name__ == "__main__":
    print("Choose a model to run:")
    print("1: Simple Server and Client")
    print("2: Iterative Server and Client")
    print("3: Concurrent Server and Client")
    choice = int(input("Enter choice: "))

    if choice == 1:
        threading.Thread(target=simple_server).start()
        simple_client()
    elif choice == 2:
        threading.Thread(target=iterative_server).start()
        iterative_client()
    elif choice == 3:
        threading.Thread(target=concurrent_server).start()
        concurrent_client()
    else:
        print("Invalid choice!")
