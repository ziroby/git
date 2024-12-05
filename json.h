#ifndef JSON_H
#define JSON_H

#include "pretty.h"

void json_print_commit(
			 const struct commit *commit,
			 struct json_writer *jw);

void json_init_log(struct json_writer* jw);

/** Rename me and give a good comment */
void json_user_info(struct json_writer *block,
		  const char *what,
		  const char *buf,
		  size_t len);

void json_add_date(struct json_writer *block, struct ident_split *ident);

struct json_writer *json_begin_merge_list(void);

void json_add_merge(struct json_writer *jw_merge,char *oidp);

void json_end_merge_list(struct json_writer *block, struct json_writer *jw_merge);

void json_end_commit(struct json_writer* jw);

void json_end(struct json_writer* jw, FILE* file);
#endif /* JSON_H */
