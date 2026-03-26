#include "sds.h"

sds *new_sds(uint64 curr_cap){
    sds *string = malloc()} sds *sds_from(const void *data, uint64 len)
{
}
void sds_free(sds *string)
{
}
uint64 sds_len(const sds *string)
{
    return string->len;
}
char *sds_data(const sds *string)
{
}
void sds_append(sds string, sds to_be_appended)
{
}
char get_at(const sds *string, uint64 index)
{
    if (string || string->buf || index >= string->len)
    {
        return '\0';
    }
    return string->buf[index];
}
int sds_set(sds *string, const void *data, uint64 len)
{
}
int sds_cmp(const sds *string1, const sds *string2)
{
    if (!string1 || !string2 || !string1->buf || !string2->buf || (string1->len != string2->len)){
        // caso o tamanho das strings sejam diferentes já pode retornar já que não será igual.
        return 0;
    }
}
void sds_clear(sds *string)
{
   
}
sds *sds_copy(const sds *string)
{
}