/* check_stanza.h
** strophe XMPP client library -- stanza tests
**
** Copyright (C) 2005-2009 Collecta, Inc. 
**
**  This software is provided AS-IS with no warranty, either express or
**  implied.
**
**  This software is distributed under license and may not be copied,
**  modified or distributed except as expressly authorized under the
**  terms of the license contained in the file LICENSE.txt in this
**  distribution.
*/

#include <stdlib.h>
#include <string.h>

#include <check.h>

#include <strophe.h>

#include "test.h"

static xmpp_ctx_t    *ctx;

void xmpp_warn(const xmpp_ctx_t * const ctx,
               const char * const area,
               const char * const fmt,
               ...);

/* Test support */
/* ************************************************************ */

static void handle_setup(void) {
    xmpp_initialize();
    ctx = xmpp_ctx_new(NULL, NULL);
    fail_if(ctx == NULL, "Failed to set up ctx");
}

static void handle_teardown(void) {
    xmpp_ctx_free(ctx);
    ctx = NULL;
    xmpp_shutdown();
}

/* The actual tests */
/* ************************************************************ */

START_TEST(test_large_logger)
{
    int num_bytes = 16 * 1024;
    char *big_ass_string = calloc(num_bytes + 1, sizeof(char));

    memset((void*)big_ass_string, 'a', num_bytes);
    fail_unless(strlen(big_ass_string) == num_bytes,
                "The string isn't long enough.");

    xmpp_warn(ctx, "conn", "Big ass string:  %s", big_ass_string);
}
END_TEST

Suite *parser_suite(void)
{
    Suite *s = suite_create("Stanza");
    TCase *tc = tcase_create("Core");

    tcase_add_checked_fixture(tc, handle_setup, handle_teardown);

    tcase_add_test(tc, test_large_logger);

    suite_add_tcase(s, tc);
    return s;
}

TEST_MAIN
