#include "sds.h"

sds sdsnew(const char *str)
{
    return sds_from(str, strlen(str));
}
sds sds_from(const char *str, size_t len)
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
sds make_room_for(sds source, size_t needed)
{
    struct sds_header *sh = get_header(source);
    size_t required = needed;
    if (sh->free >= needed)
    {
        return source;
    }
    size_t curr_len = sh->len;
    size_t new_len = curr_len + needed;
    size_t new_cap;

    if (new_len < LINEAR_SIZE * LINEAR_SIZE)
    {
        new_cap = new_len * 2;
    }
    else
    {
        new_cap = new_len + LINEAR_SIZE * LINEAR_SIZE;
    }
    struct sds_header *new_sh = realloc(sh, sizeof(*new_sh) + new_cap);
    if (new_sh == NULL)
    {
        return NULL;
    }
    new_sh->free = new_cap - curr_len;
    return new_sh->buf;
}
void sds_free(sds string)
{
    if (string == NULL)
        return;
    struct sds_header *sh = get_header(string);
    /*
        ARRUMAR.
    */
    free(sh);

}
void set_sds_len(sds string)
{
    struct sds_header *sh = get_header(string);
    sh->len = strlen(sh->buf);
    return;
}
size_t sds_len(const sds string)
{
    struct sds_header *ptr = get_header(string);
    return ptr->len;
}
void sds_cat(sds string, sds to_be_appended)
{
    size_t string_length = sds_len(string);
    size_t to_add = sds_len(to_be_appended);
    size_t required = string_length + to_add;
    if (string_length < required)
    {
        make_room_for(string, to_add);
    }
    size_t counter = 0;
    for (size_t i = string_length; i < required; i++)
    {
        string[i] = to_be_appended[counter];
        counter++;
    }
    string[required] = '\0';
    return;
}
char get_at(const sds string, size_t index)
{
    if (index > (sds_len(string) - 1))
    {
        perror("Index não existente");
        return '\0';
    }
    return string[index];
}
int sds_set(sds string, const void *data, size_t len_needed)
{
    struct sds_header *sh = get_header(string);
    size_t length = sh->len;
    if (length < len_needed)
    {
        make_room_for(string, len_needed);
    }
    return 1;
}
void sds_to_lower(sds string)
{
    size_t length = sds_len(string);
    for (size_t i = 0; i < length; i++)
    {
        if (string[i] >= 'A' && string[i] <= 'Z')
        {
            string[i] = string[i] + 32;
        }
    }
}
void sds_to_upper(sds string)
{
    size_t length = sds_len(string);
    for (size_t i = 0; i < length; i++)
    {
        if (string[i] >= 'a' && string[i] <= 'z')
        {
            string[i] = string[i] - 32;
        }
    }
}
int sds_cmp(const sds string1, const sds string2)
{
    size_t length = sds_len(string1);
    if (sds_len(string1) != sds_len(string2))
    {
        return 0;
    }
    for (size_t i = 0; i < length; i++)
    {
        if (string1[i] != string2[i])
        {
            return 0;
        }
    }
    return 1;
}
void sds_clear(sds string)
{
    size_t length = sds_len(string);
    memset(string, 0, length);
    struct sds_header *sh = get_header(string);
    sh->free = length;
    sh->len = 0;
    string[0] = '\0';
}
sds sds_copy(sds dest, const sds src)
{
    size_t src_length = sds_len(src);
    size_t dest_length = sds_len(dest);
    if (dest_length < src_length)
    {
        perror("Destination string is too small to receive source copy.\n");
        return NULL;
    }
    memcpy(dest, src, src_length + 1);
    return dest;
}
sds sds_remove_free_space(sds string)
{
    struct sds_header *sh = get_header(string);
    realloc ()

    /*
    TO DO -> FREE COM REALLOC (); 
    */


}



size_t sds_capacitiy(sds string)
{
    struct sds_header *sh = get_header(string);
    return sh->len + sh->free;
    /*
        TO DO -> CALCULO CORRETO DA CAPICDIADE
    */
}
sds sds_range(sds string, size_t start, size_t end)
{
    if (start > sds_len(string) || start < 0 || end > sds_len(string) || end < 0)
    {
        return NULL;
    }
    /*
        TO DO -> ARRANJAR FORMA QUE SEJA SEM CRIAR UMA NOVA STRING TODA HORA.
    */
    sds substr = sdsnew("");
    for (size_t i = start; i < end; i++)
    {
        sds_append(substr, string[i]);
    }
    return substr;
}
sds sdsdup(sds string)
{
    struct sds_header *sh = get_header(string);
    size_t total_size = sizeof(struct sds_header) + sh->len + 1;
    struct sds_header *new_sh = malloc(total_size);
    if (new_sh == NULL)
    {
        perror("Erro");
    }
    memcpy(new_sh, sh, total_size);
    return (sds)new_sh->buf;
}
int main()
{
    printf("Teste:\n");
    sds string = sdsnew("Hello there!");
    size_t len = sds_len(string);
    printf("%zu\n", len);
    sds_to_lower(string);
    printf("%s\n", string);
    sds new_string = sdsnew(" this is the added one!");
    printf("%s\n", new_string);
    sds_append(string, new_string);
    printf("%s\n", string);
    sds s = sds_range(string, 2, 5);
    return 0;
}