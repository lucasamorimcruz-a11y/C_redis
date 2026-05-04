#include "sds.h"

sds sdsnew (const char *str){
    return sds_from (str, strlen(str));
}
sds sds_from (const char* str, uint64 len){
    struct sds_header *sh = malloc (sizeof (struct sds_header) +  len + 1);
    if (sh == NULL) {
        return NULL;
    }
    sh->len = len;
    sh->free = 0;

    sds string = sh->buf;
    memcpy(string, str, len);
    string[len] = '\0';
    return string;
}
struct sds_header *get_header (sds string){
    return (struct sds_header *) ((char *) string - sizeof(struct sds_header));
}
sds make_room_for (sds source, uint64 needed){
}

void sds_free (sds string){

}
void set_sds_len (sds string){

}
uint64 sds_len (const sds string){
    struct sds_header *ptr = get_header(string);
    return ptr->len;
}

int main (){ 
    printf("Teste\n");
    sds string = sdsnew ("Hello there!");
    int len = sds_len(string);
    printf("%d\n", len);
    strlen (string);
    return 0;
}