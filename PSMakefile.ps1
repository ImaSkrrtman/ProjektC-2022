# Uzywaj tego skryptu jak nie dziala tb komenda Make


# Sprawdzenie czy plik binarny jest w sciezce jak tak to usuwamy go i robimy nowy
function IsBinFileInDebug() {
    $BinPath = ".\bin\debug\Sokoban.exe";
    $CheckPath = Test-Path -Path $BinPath -PathType Leaf;
    if ($CheckPath -eq $True) {
        Remove-Item $BinPath;
    }
}


# Tworzenie projektu
function Make() {
    # Dodawaj tutaj pliki *.cpp
    $CFiles = ".\src\Board.cpp", ".\src\PlayerModel.cpp", ".\src\Sokoban.cpp", ".\src\Wrappers.cpp";
    
    # Dodawaj tutaj pliki cpp tyle ze rozszerzenie cpp zmien na .o
    # Wszystko w odpowiedniej kolejnosci
    $OBJFiles = ".\src\Board.o", ".\src\PlayerModel.o", ".\src\Sokoban.o", ".\src\Wrappers.o";

    Write-Output "Checking if the old version exsists in the .\bin\debug path"
    IsBinFileInDebug;

    Write-Output "Making the project"
    for ($i = 0; $i -lt $CFiles.Length; $i++) {
        $Command = "g++ -c " + $CFiles[$i] + " -o " + $OBJFiles[$i] + " -O3";
        Invoke-Expression $Command;
    }

    $MakeBin = "g++ " + $OBJFiles + " -o " + "Sokoban" + " -O3";
    Invoke-Expression $MakeBin;

    Write-Output "Cleaning"
    for ($i = 0; $i -lt $OBJFiles.Length; $i++) {
        $Command = "Remove-Item " + $OBJFiles[$i];
        Invoke-Expression $Command;
    }

    Write-Output "Moving the new Sokoban.exe file to the .\bin\debug path"
    Write-Output "Everything is done"

    move .\Sokoban.exe .\bin\debug

    Get-ChildItem .\bin\debug

    Write-Output "You can run the project via .\bin\debug\Sokoban.exe or go to the executable path and type .\Sokoban.exe"
}


Make;