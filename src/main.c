#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <my_ints.h>
#include <netinet/in.h>
/*
    fds são como uma porta de comunicação com o kernel, que por escolha de design dos sistemas UNIX, é utilizado para interagir com diversos processos como se fossem FILES (Everything is a file).
    a quantidade de fds são limitadas, e todos (seja ao abrir um fd para um dispositivo, para um socket, etc) compartilham da mesma piscina de fds disponíveis por computador.


*/

typedef struct in_address
{
    uint32 s_address;
};
typedef struct sockaddr_in
{
    uint16 sin_family;
    uint16 sin_port;
    struct in_address sin_address;
};

int main()
{
    return 0;
}

void create_new_socket()
{
    int fd = socket(AF_INET, SOCK_STREAM, 0); // AF_INET -> IPV4, SOCK_STREAM -> TCP, 0 -> protocolo padrão
    int val = 1;
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
    struct sockaddr_in address = {};
    address.sin_family = AF_INET;
    address.sin_port = htons(1234);
    address.sin_address.s_address = htonl(INADDR_ANY);
    int rv = bind(fd, (const struct sockaddr *)&address, sizeof(address));
    if (rv)
    {
        die("bind()");
    }
    listen(fd, SOMAXCONN);
    int client = accept(fd, NULL, NULL);
    close(client);
}
