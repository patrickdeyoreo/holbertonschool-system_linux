# 0x0C. Sockets

## Resources:books:
Read or watch:
* [Sockets - GNU](https://intranet.hbtn.io/rltoken/8-GQYB18McIu6nJsG_IPew)
* [Sockets Programming in C](https://intranet.hbtn.io/rltoken/ACPJ5oRoCzUt3IajvwEKBg)
* [List of HTTP status codes](https://intranet.hbtn.io/rltoken/7QEbgeOKOqhgVaXwvHvQyA)
* [RFC 2616 -> HTTP 1.1](https://intranet.hbtn.io/rltoken/lKmhLE_RqNgR9Ejw54mLVA)

---
## Learning Objectives:bulb:
What you should learn from this project:

* What is a socket and how it is represented on a Linux/UNIX system
* What are the different types of sockets
* What are the different socket domains
* How to create a socket
* How to bind a socket to an address/port
* How to listen and accept incoming traffic
* How to connect to a remote application
* What is the the HTTP protocol
* How to create a simple HTTP server

---

### [0. Listen](./0-server.c)
* Write a program that opens an IPv4/TCP socket, and listens to traffic on port 12345 (Any address).


### [1. Accept](./1-server.c)
* Write a program that opens an IPv4/TCP socket, and listens to traffic on port 12345 (Any address).


### [2. Client](./2-client.c)
* Write a program that connects to a listening server


### [3. Roger](./3-server.c)
* Write a program that opens an IPv4/TCP socket, and listens to traffic on port 12345 (Any address).


### [4. REST API - The Request](./Makefile)
* Write a program that opens an IPv4/TCP socket, and listens to traffic on port 8080 (Any address).


### [5. REST API - Queries](./Makefile)
* Write a program that opens an IPv4/TCP socket, and listens to traffic on port 8080 (Any address).


### [6. REST API - Headers](./Makefile)
* Write a program that opens an IPv4/TCP socket, and listens to traffic on port 8080 (Any address).


### [7. REST API - Body parameters](./Makefile)
* Write a program that opens an IPv4/TCP socket, and listens to traffic on port 8080 (Any address).


### [8. REST API - Create TODO](./Makefile)
* Now that you can parse an HTTP request, it’s time to implement our REST API. Start by handling the POST method for the path /todos


### [9. REST API - Retrieve all TODOs](./Makefile)
* Handle the GET method for the path /todos


### [10. REST API - Retrieve a single TODO](./Makefile)
* Handle the GET method for the path /todos?id={id}


### [11. REST API - Delete a TODO](./Makefile)
* Handle the DELETE method for the path /todos?id={id}

---

## Author
* **Patrick DeYoreo** - [patrickdeyoreo](github.com/patrickdeyoreo)