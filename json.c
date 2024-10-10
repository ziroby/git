#define USE_THE_REPOSITORY_VARIABLE

#include "git-compat-util.h"
#include "config.h"
#include "commit.h"

#include "json.h"
#include "json-writer.h"
#include "object-name.h"
#include "strbuf.h"

void json_print_commit(
			 const struct commit *commit,
			 struct json_writer *jw) 
{
    int pretty = 0;

    jw_object_begin(jw, pretty);
    jw_object_string(jw, "commit",
        repo_find_unique_abbrev(the_repository, &commit->object.oid, 40));
}