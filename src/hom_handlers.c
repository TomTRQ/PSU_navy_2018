/*
** EPITECH PROJECT, 2019
** handlers.c
** File description:
** Navy's signal handlers
*/

#include "my.h"

void set_recs(struct sigaction rec, struct sigaction rec2)
{
    sigemptyset(&rec.sa_mask);
    sigemptyset(&rec2.sa_mask);
    rec.sa_sigaction = &rec1_handler;
    rec2.sa_sigaction = &rec2_handler;
    rec.sa_flags = SA_SIGINFO;
    rec2.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &rec, NULL);
    sigaction(SIGUSR2, &rec2, NULL);
}

void rec1_handler(int sig, siginfo_t *siginfo, void *context)
{
}

void rec2_handler(int sig, siginfo_t *siginfo, void *context)
{
    int epid = siginfo->si_pid;

    mod_k(epid);
}

int mod_k(int epid)
{
    static int k = 0;

    if (epid == 9)
        k = 0;
    if (epid != 0 && epid != 9)
        k = 3;
    if (k == 3)
        return (3);
    return (0);
}
