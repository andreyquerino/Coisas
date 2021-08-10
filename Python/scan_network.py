#!/usr/bin/env python

##Author : AndreyQuerino
##Descr  : Digitalizar interface sem fio e Ethernet

from scapy.all import arping
import netifaces as ni

print "[+] Digitalizando interface de rede sem fio...\n"

if 'wlp3s0' in ni.interfaces():
	if ni.AF_INET in ni.ifaddresses('wlp3s0'):
		ip = ni.ifaddresses('wlp3s0')[ni.AF_INET][0]['addr']
		ipsplit = ip.split('.')
		ipsplit[3] = '*'
		iprange = '.'.join(ipsplit)
		arping(iprange)
	else:
		print "[-] Nenhum IP foi atribuído à interface sem fio\n"
else:
	print "[-] Interface wlp3s0 não encontrada. Por favor, mude o nome da interface"

print "[+] Digitalizando interface de rede Ethernet...\n"

if 'enp2s0' in ni.interfaces():
	if ni.AF_INET in ni.ifaddresses('enp2s0'):
		ip = ni.ifaddresses('enp2s0')[ni.AF_INET][0]['addr']
		ipsplit = ip.split('.')
		ipsplit[3] = '*'
		iprange = '.'.join(ipsplit)
		arping(iprange)
	else:
		print "[-] Nenhum IP foi atribuído ao Ethernet Interface"
else:
	print "[-] Interface enp2s0 não encontrada. Por favor, mude o nome da interface"
