/*
 *          Copyright Frantisek Hrbata 2008 - 2010.
 * Distributed under the Boost Software License, Version 1.0.
 *    (See accompanying file LICENSE_1_0.txt or copy at
 *          http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef __AV_H__
#define __AV_H__

#include <sys/types.h>

#define AV_EVENT_OPEN  1
#define AV_EVENT_CLOSE 2

#define AV_ACCESS_ALLOW 1
#define AV_ACCESS_DENY  2

#define AV_CACHE_DISABLE 0
#define AV_CACHE_ENABLE  1

struct av_connection {
	int fd;
};

struct av_event {
	int id;   //由avflt设置，app不允许修改
	int type; //区分 event类型
	int fd;    
	pid_t pid;
	pid_t tgid;
	int res;
	int cache;
};

int av_register(struct av_connection *conn);
int av_unregister(struct av_connection *conn);
int av_register_trusted(struct av_connection *conn);
int av_unregister_trusted(struct av_connection *conn);
int av_request(struct av_connection *conn, struct av_event *event, int timeout);
int av_reply(struct av_connection *conn, struct av_event *event);
int av_set_result(struct av_event *event, int res);
int av_set_cache(struct av_event *event, int cache);
int av_get_filename(struct av_event *event, char *buf, int size);

#endif

