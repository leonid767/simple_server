#ifndef __linux__
#ifndef _EPOLL_H
#define _EPOLL_H
#include <stdint.h>

enum EPOLL_EVENTS
  {
    EPOLLIN = 0x001,
#define EPOLLIN EPOLLIN
    EPOLLPRI = 0x002,
#define EPOLLPRI EPOLLPRI
    EPOLLOUT = 0x004,
#define EPOLLOUT EPOLLOUT
    EPOLLRDNORM = 0x040,
#define EPOLLRDNORM EPOLLRDNORM
    EPOLLRDBAND = 0x080,
#define EPOLLRDBAND EPOLLRDBAND
    EPOLLWRNORM = 0x100,
#define EPOLLWRNORM EPOLLWRNORM
    EPOLLWRBAND = 0x200,
#define EPOLLWRBAND EPOLLWRBAND
    EPOLLMSG = 0x400,
#define EPOLLMSG EPOLLMSG
    EPOLLERR = 0x008,
#define EPOLLERR EPOLLERR
    EPOLLHUP = 0x010,
#define EPOLLHUP EPOLLHUP
    EPOLLRDHUP = 0x2000,
#define EPOLLRDHUP EPOLLRDHUP
    EPOLLONESHOT = (1 << 30),
#define EPOLLONESHOT EPOLLONESHOT
    EPOLLET = (1 << 31)
#define EPOLLET EPOLLET
  };


/* Valid opcodes ( "op" parameter ) to issue to epoll_ctl().  */
#define EPOLL_CTL_ADD 1      /* Add a file descriptor to the interface.  */
#define EPOLL_CTL_DEL 2      /* Remove a file descriptor from the interface.  */
#define EPOLL_CTL_MOD 3      /* Change file descriptor epoll_event structure.  */

typedef union epoll_data
{
    void				*ptr;
    int					fd;
    unsigned int		u32;
    uint64_t		    u64;
} epoll_data_t;

struct epoll_event
{
    int64_t				events;      /* Epoll events */
    epoll_data_t		data;        /* User data variable */
};

int epoll_create(int size);
int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event);
int epoll_wait(int epfd, struct epoll_event *events, int maxevents, int timeout);

#endif
#endif
