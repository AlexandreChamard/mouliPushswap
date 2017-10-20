/*
** arg.c for mouliPushswap in /home/alexandre/Documents/git/mouliPushswap/src
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Thu Oct 19 22:00:31 2017 alexandre Chamard-bois
** Last update Fri Oct 20 11:35:42 2017 alexandre Chamard-bois
*/

#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "mouli.h"

void trim(char *str) {
    size_t i = 0;
    size_t len = strlen(str);

    while (str[i] && isblank(str[i])) {
        i++;
    }
    while (len > 0 && isblank(str[--len]));
    if (!len && isblank(*str)) {
        *str = 0;
        return ;
    }
    for (int j = 0; j < len - i + 1; j++) {
        str[j] = str[i + j];
    }
    str[len - i + 1] = 0;
    for (i = 0; str[i] && str[i] != '#'; i++);
    str[i] = 0;
}

int get_args(FILE *fp, infos_t *infos)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fp)) != -1) {
        trim(line);
        sscanf(line, "min: %d", &infos->min);
        sscanf(line, "max: %d", &infos->max);
        sscanf(line, "calls: %u", &infos->calls);
        sscanf(line, "seed: %u", &infos->seed);
        if (strstr(line, "}")) {
            break;
        }
    }
    if (line) {
        free(line);
    }
    return ((read <= 0));
}

list_t *new_serie(list_t *list, FILE *fp, infos_t *def_infos, char const *line)
{
    infos_t     infos;
    list_t      *new_serie;
    size_t      i = strlen(line) - 1;

    memcpy(&infos, def_infos, sizeof(infos_t));
    get_args(fp, &infos);
    for (; i > 0 && !isdigit(line[i]); i--);
    while (i > 0) {
        for (; i > 0 && isdigit(line[i]); i--);
        if (!i) {
            break;
        }
        if (!(new_serie = malloc(sizeof(list_t)))) {
            return (list);
        }
        memcpy(&new_serie->infos, &infos, sizeof(infos_t));
        new_serie->infos.nb_args = atoi(line + i + 1);
        new_serie->next = list;
        list = new_serie;
        for (; i > 0 && !isdigit(line[i]); i--);
    }
    return (list);
}

list_t *recup_series(FILE *fp, infos_t *default_infos)
{
    list_t  *list = NULL;
    char    *line = NULL;
    size_t  len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fp)) != -1) {
        trim(line);
        sscanf(line, "min: %d", &default_infos->min);
        sscanf(line, "max: %d", &default_infos->max);
        sscanf(line, "calls: %u", &default_infos->calls);
        sscanf(line, "seed: %u", &default_infos->seed);
        if (strstr(line, "serie:")) {
            list = new_serie(list, fp, default_infos, line);
        }
    }
    if (line) {
        free(line);
    }
    return (list);
}

list_t *pars_file(char const *file)
{
    infos_t default_infos = {-50000, 49999, 0, 10, time(NULL)};
    list_t *series;
    FILE    *fp;

    if (!(fp = fopen(file, "r"))) {
        return (NULL);
    }
    series = recup_series(fp, &default_infos);
    return (series);
}
