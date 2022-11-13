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

    IsBinFileInDebug;

    for ($i = 0; $i -lt $CFiles.Length; $i++) {
        $Command = "g++ -c " + $CFiles[$i] + " -o " + $OBJFiles[$i] + " -O3";
        Invoke-Expression $Command;
    }

    $MakeBin = "g++ " + $OBJFiles + " -o " + "Sokoban" + " -O3";
    Invoke-Expression $MakeBin;

    for ($i = 0; $i -lt $OBJFiles.Length; $i++) {
        $Command = "Remove-Item " + $OBJFiles[$i];
        Invoke-Expression $Command;
    }

    move .\Sokoban.exe .\bin\debug
}


Make;