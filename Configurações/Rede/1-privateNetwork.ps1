Set-NetConnectionProfile -Name ((Get-NetConnectionProfile | findstr Name).Trim("Name :")) -NetworkCategory Private