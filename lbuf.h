/* $Id$ */

#ifndef LBUF_H
#define LBUF_H

#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <sysexits.h>

struct lbuf {
	int	 lb_pos;
	int	 lb_max;
	char	*lb_buf;
};

#define LBUF_INIT(lb)							\
	do {								\
		(lb).lb_pos = (lb).lb_max = -1;				\
		(lb).lb_buf = NULL;					\
	} while (0)

#define LBUF_APPEND(lb, ch)						\
	do {								\
		if (++(lb).lb_pos >= (lb).lb_max) {			\
			(lb).lb_max += 30;				\
			if (((lb).lb_buf = realloc((lb).lb_buf,		\
			     (lb).lb_max * sizeof(*(lb).lb_buf))) ==	\
			    NULL)					\
				err(EX_OSERR, "realloc");		\
		}							\
		(lb).lb_buf[(lb).lb_pos] = (ch);			\
	} while (0)

#define LBUF_GET(lb)							\
	(lb).lb_buf

#define LBUF_SET(lb, s)							\
	(lb).lb_buf = (s)

#define LBUF_FREE(lb)							\
	free((lb).lb_buf)

#define LBUF_RESET(lb)							\
	(lb).lb_pos = -1						\

#define LBUF_CHOP(lb)							\
	(lb).lb_pos--

#endif /* LBUF_H */
