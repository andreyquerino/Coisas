'Script para executar um arquivo em determinado tempo

Dim wshShell
Set wshShell = CreateObject("WScript.Shell")
WScript.Sleep(600000) '10 minutos em milisegundos.
wshShell.Run("calc.exe")
