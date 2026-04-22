#ifndef SDS_H
#define SDS_H
#include <my_ints.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
typedef char *sds;
typedef struct sds_header
{
    uint64 len;
    uint64 free;
    char buf[];
} sds_header;

sds new_sds(uint64 cap);
sds sds_from (const void *data, uint64 len);
sds make_room_for (sds source, uint64 needed);
void sds_free (sds string);
void set_sds_len (sds string);
uint64 sds_len(const sds string);
int sds_reserve (sds string, uint64 needed);
char sds_data (const sds string);
void sds_append(sds string, sds to_be_appended);
char get_at (const sds string, uint64 index);
int sds_set (sds string, const void *data, uint64 len_needed);
void sds_to_lower (sds string);
void sds_to_upper (sds string);
int sds_cmp(const sds string1, const sds string2);
void sds_clear (sds string);
sds sds_copy (sds dest, const sds src);

#endif 