##Author : AndreyQuerino
##Descr  : Execute o arquivo test.bat como administrador. Este script é uma alternativa ao sudo, mas para Windows 

$secpasswd = ConvertTo-SecureString "<EnterPasswordHere>" -AsPlainText -Force
$mycreds = New-Object System.Management.Automation.PSCredential ("<EnterUsernameHere>",$secpasswd)
$computer = "<EnterHostnameHere>"
[System.Diagnostics.Process]::Start("C:\Users\%USERNAME%\AppData\local\temp\test.bat","",$mycreds.Username, $mycreds.Password, $computer)

