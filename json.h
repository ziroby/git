#ifndef JSON_H
#define JSON_H

#include "pretty.h"

void json_print_commit(
			 const struct commit *commit,
			 struct strbuf *sb);

#endif /* JSON_H */
