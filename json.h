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
		  
#endif /* JSON_H */
