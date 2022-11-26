#ifndef __LOGS_H
#define __LOGS_H
#include <fstream>
#ifndef _TYPES_INCL
#define _TYPES_INCL
#include "Types.h"
#endif /* _TYPES_INCL */

#define __LOG_FILENAME ".\\logs\\LatestLogs.log"

class __Logs
{
private:
    u_int _totalErrors;
    u_int _totalLogs;
    u_int _criticalErrors; // Wycieki pamieci, zle wskazniki itd.

    std::ofstream _ofs;

public:
    __Logs(); // Konstruktor
    ~__Logs(); // Destruktor

    void writeLog(c_p_char);
    void writeMovementLog(c_p_char, char);
    void writeError(c_p_char, bool);
    void writeSummary();

    bool checkFile();
};

extern __Logs logging;

#endif /* __LOGS_H */