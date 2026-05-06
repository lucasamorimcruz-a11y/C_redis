#include "sds.h"

sds sdsnew(const char *str)
{
    return sds_from(str, strlen(str));
}
sds sds_from(const char *str, uint64 len)
{
    struct sds_header *sh = malloc(sizeof(struct sds_header) + len + 1);
    if (sh == NULL)
    {
        return NULL;
    }
    sh->len = len;
    sh->free = 0;

    sds string = sh->buf;
    memcpy(string, str, len);
    string[len] = '\0';
    return string;
}
struct sds_header *get_header(sds string)
{
    return (struct sds_header *)((char *)string - sizeof(struct sds_header));
}
sds make_room_for(sds source, uint64 needed)
{
    struct sds_header *sh = get_header(source);
    size_t required = needed;

    if (sh->free < required){
        size_t new_len = sh->len + needed;

        size_t new_cap = sh->len + sh->free;
        if (new_cap == 0) {
            new_cap = required;
        }
        while (new_cap < new_len){
            if (new_cap < 1024 * 1024){
                    new_cap *= 2;
            }    
            else{

            }
        }
        struct sds_header *new_sh = realloc (sh, sizeof (*sh) + new_cap);
        if (new_sh == NULL){
            return NULL;
        }
        new_sh->free = new_cap - new_sh->len;
        sh = new_sh;
    }
    return sh->buf;
}
void sds_free(sds string)
{
    if (string == NULL)
        return;
    struct sds_header *sh = get_header(string);
    free(sh);
}
void set_sds_len(sds string)
{
}
uint64 sds_len(const sds string)
{
    struct sds_header *ptr = get_header(string);
    return ptr->len;
}
void sds_append(sds string, sds to_be_appended)
{
    uint64 original_string_size = sds_len(string);
    uint64 to_be_added_size = sds_len(to_be_appended);
    struct sds_header *ptr = get_header(string);
    if (original_string_size < to_be_added_size)
    {
        make_room_for(string, to_be_added_size);
    }

    int counter = 0;
    for (int i = original_string_size - 1; i < original_string_size + to_be_added_size; i++)
    {
        string[i] = to_be_appended[counter];
        counter++;
    }
    return;
}
char get_at(const sds string, uint64 index)
{
    if (index > (sds_len(string) - 1))
    {
        perror("Index não existente");
        return '\0';
    }
    return string[index];
}
int sds_set(sds string, const void *data, uint64 len_needed)
{
}
void sds_to_lower(sds string)
{
    uint64 length = sds_len(string);
    for (int i = 0; i < length; i++)
    {
        if (string[i] >= 'A' && string[i] <= 'Z')
        {
            string[i] = string[i] + 32;
        }
    }
}
void sds_to_upper(sds string)
{
    uint64 length = sds_len(string);
    for (int i = 0; i < length; i++)
    {
        if (string[i] >= 'a' && string[i] <= 'z')
        {
            string[i] = string[i] - 32;
        }
    }
}
int sds_cmp(const sds string1, const sds string2)
{
}
void sds_clear(sds string)
{
    uint64 length = sds_len(string);
    for (int i = 0; i < length; i++)
    {
        string[i] = " ";
    }
}
sds sds_copy(sds dest, const sds src)
{
    int src_length = sds_len(src);
    int dest_length = sds_len(dest);
    if (dest_length < src_length)
    {
        perror("Destination string is too small to receive source copy.\n");
        return NULL;
    }
    for (int i = 0; i < src_length; i++)
    {
    }
}
sds cat(sds s, const char *t)
{

}
int main()
{
    printf("Teste\n");
    sds string = sdsnew("Hello there!");
    int len = sds_len(string);
    printf("%d\n", len);
    strlen(string);
    printf("%s\n", string);
    sds_to_lower(string);
    printf("%s\n", string);
    sds new_string = sdsnew(" this is the added one!");
    sds_append(string, new_string);
    return 0;
}