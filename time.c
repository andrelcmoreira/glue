#define _XOPEN_SOURCE
#include <stdio.h>
#include <string.h>
#include <time.h>

#define SECONDS_IN_DAY  86400

void add_days_to_date(const char *date, int days, char *out_date)
{
    struct tm tm;
    time_t unix_tstamp;

    if (!date || !out_date) {
        return;
    }

    memset(&tm, 0, sizeof(tm));
    (void)strptime(date, "%d-%m-%Y", &tm);

    unix_tstamp = mktime(&tm) + (days * SECONDS_IN_DAY);

    memset(&tm, 0, sizeof(tm));
    (void)localtime_r(&unix_tstamp, &tm);
    (void)sprintf(
        out_date,
        "%d-%d-%d",
        tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900
    );
}

int main(int argc, char *argv[])
{
    char date[255] = { 0 };

    add_days_to_date("15-01-2021", 30, date);
    (void)printf("date = %s\n", date);

    return 0;
}
