/*
** arg.c for mouliPushswap in /home/alexandre/Documents/git/mouliPushswap/src
**
** Made by alexandre Chamard-bois
** Login   <alexandre@epitech.net>
**
** Started on  Thu Oct 19 22:00:31 2017 alexandre Chamard-bois
** Last update Fri Nov 17 12:05:29 2017 alexandre Chamard-bois
*/

#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "mouli.h"

static void trim(char *str) {
	size_t	i = 0;
	size_t	len = strlen(str);

	while (str[i] && isblank(str[i])) {
		i++;
	}
	while (len > 0 && isblank(str[--len]));
	if (!len && isblank(*str)) {
		*str = 0;
		return ;
	}
	for (unsigned int j = 0; j < len - i + 1; j++) {
		str[j] = str[i + j];
	}
	str[len - i + 1] = 0;
	for (i = 0; str[i] && str[i] != '#'; i++);
	str[i] = 0;
}

static int get_args(FILE *fp, infos_t *infos)
{
	char	*line = NULL;
	size_t	len = 0;
	ssize_t	read;

	while ((read = getline(&line, &len, fp)) != -1) {
		trim(line);
		sscanf(line, "min: %d", &infos->min);
		sscanf(line, "max: %d", &infos->max);
		sscanf(line, "calls: %u", &infos->calls);
		sscanf(line, "seed: %u", &infos->seed);
		sscanf(line, "verbose: %d", &infos->verbose);
		sscanf(line, "debug: %d", &infos->debug);
		sscanf(line, "timeout: %d", &infos->timeout);
		if (strstr(line, "}")) {
			break;
		}
	}
	if (line) {
		free(line);
	}
	return ((read <= 0));
}

static list_t *new_serie(list_t *list, FILE *fp, infos_t *def_infos, char const *line)
{
	infos_t	infos;
	list_t	*new_serie;
	size_t	i = strlen(line) - 1;

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
		new_serie->prev = list;
		if (list) {
			list->next = new_serie;
		}
		new_serie->next = NULL;
		list = new_serie;
		for (; i > 0 && !isdigit(line[i]); i--);
	}
	return (list);
}

static list_t *recup_series(FILE *fp, infos_t *default_infos)
{
	list_t	*list = NULL;
	char	*line = NULL;
	size_t	len = 0;
	ssize_t	read;

	while ((read = getline(&line, &len, fp)) != -1) {
		trim(line);
		sscanf(line, "min: %d", &default_infos->min);
		sscanf(line, "max: %d", &default_infos->max);
		sscanf(line, "calls: %u", &default_infos->calls);
		sscanf(line, "seed: %u", &default_infos->seed);
		sscanf(line, "verbose: %d", &default_infos->verbose);
		sscanf(line, "debug: %d", &default_infos->debug);
		sscanf(line, "timeout: %d", &default_infos->timeout);
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
	infos_t	default_infos = {-50000, 50000, 0, 10, time(NULL), 0, 0, 10};
	list_t	*series;
	FILE	*fp;

	if (!(fp = fopen(file, "r"))) {
		dprintf(2, "%s: File not found.\n", file);
		return (NULL);
	}
	series = recup_series(fp, &default_infos);
	for (list_t *ptr = series; ptr; ptr = ptr->next) {
		ptr->infos.min = MAX(-50000, ptr->infos.min);
		ptr->infos.max = MIN(ptr->infos.max, 50000);
		ptr->infos.max = MAX(ptr->infos.min, ptr->infos.max);
		ptr->infos.nb_args = MIN(ptr->infos.nb_args, 100000);
	}
	fclose(fp);
	if (series) {
		while (series->prev) {
			series = series->prev;
		}
	}
	return (series);
}
