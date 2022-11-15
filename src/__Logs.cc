#include <iostream>
#include "../include/__Logs.h"


__Logs logging;


__Logs::__Logs()
{
    this->_totalLogs = 0;
    this->_totalErrors = 0;
    this->_criticalErrors = 0;

    this->_ofs.open(__LOG_FILENAME, std::ios::out | std::ios::trunc);

    if (this->checkFile() == false) {
        try {
            this->_ofs.open(__LOG_FILENAME, std::ios::out | std::ios::trunc);
        } catch (...) {
            throw "Unable to open the log file";
        }
    }
}


__Logs::~__Logs()
{ 
    this->_totalLogs = 0;
    this->_totalErrors = 0;
    this->_criticalErrors = 0;

    this->_ofs.close();
}


void __Logs::writeError(c_p_char errorMessage, bool isCritical)
{
    this->_ofs << "ERROR: " << errorMessage << std::endl;

    if (isCritical)
        this->_criticalErrors++;
    else
        this->_totalErrors++;
}


void __Logs::writeLog(c_p_char logMessage)
{
    this->_ofs << "LOG: " << logMessage << std::endl;
    this->_totalLogs++;
}


void __Logs::writeSummary()
{
    this->_ofs << std::endl 
               << "SUMMARY:" 
               << std::endl
               << "\tTOTAL ERRORS: " << this->_totalErrors 
               << std::endl
               << "\tCRITICAL ERRORS: " << this->_criticalErrors 
               << std::endl
               << "\tTOTAL LOGS: " << this->_totalLogs 
               << std::endl;
}


bool __Logs::checkFile()
{
    int isOpen;

    if (this->_ofs.is_open())
        isOpen = true;
    else
        isOpen = false;

    return isOpen;
}