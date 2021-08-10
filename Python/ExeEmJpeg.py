#!/usr/bin/python3

##Author : AndreyQuerino
##Descr  : Script para incorporar arquivos exe em jpeg

import sys

if (len(sys.argv) != 3):
    print("Usage:\n ./" + sys.argv[0] + " <JpegFile> <ExeParaEmbed>")
else:
    JpegFile = open(sys.argv[1], "rb").read()
    ExecFile = open(sys.argv[2], "rb").read()
    OutputFile = open("embeded.jpg", "wb")
    OutputFile.write(JpegFile)
    OutputFile.write(ExecFile)
    print ("[+] Incorporado para embeded.jpg")
