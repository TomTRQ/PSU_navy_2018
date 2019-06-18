/*
** EPITECH PROJECT, 2019
** handlers.c
** File description:
** Navy's signal handlers
*/

#include "my.h"

void handler1(int sig, siginfo_t *siginfo, void *context)
{
    int epid = siginfo->si_pid;

    connector(epid);
}

void f_hit(int sig, siginfo_t *siginfo, void *context)
{
    ch_hit(sig);
}

void f_miss(int sig, siginfo_t *siginfo, void *context)
{
    ch_hit(sig);
}

int ch_hit(int sig)
{
    static int c_hit = 0;

    if (sig == 10)
        c_hit = 1;
    if (sig == 12)
        c_hit = 2;
    if (sig == 0)
        return (c_hit);
    if (sig == 3)
        c_hit = 0;
}