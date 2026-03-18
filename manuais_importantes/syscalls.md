-> kernel

open(2)

openat(2)

close(2)

read(2)

write(2)

pread(2)

pwrite(2)

readv(2)

writev(2)

lseek(2)

fsync(2)

fdatasync(2)

sync(2)

stat(2)

fstat(2)

lstat(2)

statx(2)

access(2)

faccessat(2)

dup(2)

dup2(2)

dup3(2)

fcntl(2)

ioctl(2)

Processos

fork(2)

vfork(2)

clone(2)

execve(2)

wait(2)

waitpid(2)

waitid(2)

exit(2)

getpid(2)

getppid(2)

getuid(2)

setuid(2)

setgid(2)

kill(2)

tgkill(2)

ptrace(2)

prctl(2)

Memória

mmap(2)

munmap(2)

mprotect(2)

mremap(2)

brk(2)

sbrk(2)

mlock(2)

munlock(2)

mlockall(2)

munlockall(2)

msync(2)

madvise(2)

Filesystem

mkdir(2)

rmdir(2)

link(2)

linkat(2)

unlink(2)

unlinkat(2)

rename(2)

renameat(2)

symlink(2)

readlink(2)

chdir(2)

fchdir(2)

chroot(2)

mount(2)

umount(2)

Pipes / IPC

pipe(2)

pipe2(2)

mkfifo(2)

shmget(2)

shmat(2)

shmdt(2)

shmctl(2)

semget(2)

semop(2)

semctl(2)

msgget(2)

msgsnd(2)

msgrcv(2)

msgctl(2)

Sinais

signal(2)

sigaction(2)

sigprocmask(2)

sigpending(2)

sigsuspend(2)

sigaltstack(2)

signalfd(2)

Polling / async I/O

select(2)

pselect(2)

poll(2)

ppoll(2)

epoll_create(2)

epoll_ctl(2)

epoll_wait(2)

eventfd(2)

timerfd_create(2)


-> networking p


socket(2)

bind(2)

listen(2)

accept(2)

accept4(2)

connect(2)

shutdown(2)

send(2)

sendto(2)

sendmsg(2)

recv(2)

recvfrom(2)

recvmsg(2)

getsockopt(2)

setsockopt(2)

socketpair(2)

Protocol manuals (seção 7)


socket(7)

ip(7)

ipv6(7)

tcp(7)

udp(7)

raw(7)

packet(7)

unix(7)

netlink(7)


SP mdrn ->

pthread_create(3)

pthread_join(3)

pthread_exit(3)

pthread_mutex_lock(3)

pthread_mutex_unlock(3)

pthread_cond_wait(3)

pthread_cond_signal(3)

pthread_rwlock_rdlock(3)

pthread_rwlock_wrlock(3)

timers ->

time(2)

clock_gettime(2)

clock_settime(2)

nanosleep(2)

gettimeofday(2)

timer_create(2)

timer_settime(2)


conceituais ->


signal(7)

credentials(7)

epoll(7)

pipe(7)

fifo(7)

unix(7)

socket(7)

tcp(7)

udp(7)

ip(7)

ipv6(7)

path_resolution(7)

hier(7)

proc(5)

capabilities(7)

cgroups(7)

namespaces(7)


debugging -> 

ptrace(2)

proc(5)

core(5)

backtrace(3)

resumos -> 

syscalls(2)

intro(2)

socket(7)

signal(7)

pthreads(7)

feature_test_macros(7)