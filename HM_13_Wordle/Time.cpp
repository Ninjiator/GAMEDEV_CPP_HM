#include <iostream>
#include <ctime>

int getDay(const std::tm* tmObj)
{
    return tmObj->tm_mday;
}

int getMonth(const std::tm* tmObj)
{
    return tmObj->tm_mon + 1;
}

int getYear(const std::tm* tmObj)
{
    return tmObj->tm_year + 1900;
}

// time_t is an absolute time, represented as the integer number 
// of seconds since the UNIX epoch(midnight GMT, 1 January 1970)
// It is useful as an easy-to-work with representation of a point in time

// struct tm is a calendar date and time
// It is used when converting to or from human
// readable representations of the date and time
