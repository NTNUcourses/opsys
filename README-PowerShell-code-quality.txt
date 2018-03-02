# statisk kode analyse
# https://github.com/PowerShell/PSScriptAnalyzer

# som administrator
Install-Module -Name PSScriptAnalyzer

# tilbake som vanlig bruker
Invoke-ScriptAnalyzer a.ps

# skriver du et litt større script/prosjekt, 
# vurder unit testing med Pester (trengs nok ikke for OS-emnet)
