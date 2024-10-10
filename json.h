#ifndef JSON_H
#define JSON_H

#include "pretty.h"

void json_print_commit(
			 const struct commit *commit,
			 struct json_writer *jw);

#endif /* JSON_H */
