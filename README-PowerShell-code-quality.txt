# statisk kode analyse
# https://github.com/PowerShell/PSScriptAnalyzer

Install-Module -Name PSScriptAnalyzer -Scope CurrentUser

Invoke-ScriptAnalyzer a.ps

# skriver du et litt større script/prosjekt, 
# vurder unit testing med Pester (trengs nok ikke for OS-emnet)
