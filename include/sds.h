#ifndef SDS_H
#define SDS_H
#include <my_ints.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct sds
{
    uint64 len;
    uint64 curr_cap;
    char *buf;
} sds;

sds *new_sds(uint64 curr_cap);
sds *sds_from (const void *data, uint64 len);
void sds_free (sds *string);
uint64 sds_len(const sds *string);
char *sds_data (const sds *string);
void sds_append(sds string, sds to_be_appended);
char get_at (const sds *string, uint64 index);
int sds_set (sds *string, const void *data, uint64 len);
int sds_cmp(const sds *string1, const sds *string2);
void sds_clear (sds *string);
sds *sds_copy (const sds *string);

#endif