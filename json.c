#define USE_THE_REPOSITORY_VARIABLE

#include "git-compat-util.h"
#include "config.h"
#include "commit.h"

#include "json.h"
#include "json-writer.h"
#include "strbuf.h"

void json_print_commit(
			 const struct commit *commit,
			 struct strbuf *sb) 
{
    struct json_writer jw;
    int pretty = 0;

    jw_init(&jw);
    jw_object_begin(&jw, pretty);

    

    jw_end(&jw);
    strbuf_addbuf(sb, &jw.json);
    jw_release(&jw);

}