#define USE_THE_REPOSITORY_VARIABLE

#include "git-compat-util.h"
#include "config.h"
#include "commit.h"

#include "json.h"
#include "json-writer.h"
#include "object-name.h"
#include "strbuf.h"

int pretty = 1;

void json_print_commit(
			 const struct commit *commit,
			 struct json_writer *jw) 
{
    jw_object_begin(jw, pretty);
    jw_object_string(jw, "commit",
        repo_find_unique_abbrev(the_repository, &commit->object.oid, 40));
}

void json_init_log(struct json_writer* jw) {
	jw_init(jw);
    jw_object_begin(jw, pretty);
    jw_object_inline_begin_array(jw, "commits");
}

void json_user_info(struct json_writer *block,
		  const char *what,
		  const char *buf,
		  size_t len)
{
	struct strbuf tsb;
	strbuf_init(&tsb, len + 1);
	strbuf_add(&tsb, buf, len);
	jw_object_string(block, what, tsb.buf);

}

void json_add_date(struct json_writer *block, struct ident_split *ident) {
	jw_object_string(block, "date", 
		show_ident_date(ident, DATE_MODE(ISO8601_STRICT)));
}

struct json_writer *json_begin_merge_list(void) {
	struct json_writer *jw_merge;
	jw_merge = xmalloc(sizeof(*jw_merge));
	jw_init(jw_merge);
	jw_array_begin(jw_merge, pretty);
	return jw_merge;
}

void json_add_merge(struct json_writer *jw_merge, char *merge_id) {
	jw_array_string(jw_merge, merge_id);
}

void json_end_merge_list(struct json_writer *block, struct json_writer *jw_merge) {
	jw_end(jw_merge);
	jw_object_sub_jw(block, "merge", jw_merge);
}

void json_end_commit(struct json_writer* jw) {
	jw_end(jw);
} 

void json_end(struct json_writer* jw, FILE* file) {
		jw_end(jw);
		jw_end(jw);
		fprintf(file, "%s\n", jw->json.buf);
		jw_release(jw);
}