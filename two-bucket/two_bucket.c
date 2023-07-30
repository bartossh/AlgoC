#include "two_bucket.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum {TRANSFER, FILL_1, EMPTY_2} action_t;

typedef struct {
    bucket_liters_t b1;
    bucket_liters_t b2;
} record;

typedef struct {
    bucket_liters_t b1;
    bucket_liters_t b2;
    bucket_liters_t b1max;
    bucket_liters_t b2max;
    action_t        action;
    record*         records;
    int             records_len;
    int             records_cap;
} state;

static state new_state(bucket_liters_t bucket_1_size, bucket_liters_t bucket_2_size)
{
    int cap = 10;
    record *r = malloc(10 * sizeof(record));
    if (r == NULL)
    {
        exit(1);
    }
    state s = {
        .b1 = 0,
        .b2 = 0,
        .b1max = bucket_1_size,
        .b2max = bucket_2_size,
        .action = FILL_1,
        .records = r,
        .records_len = 0,
        .records_cap = cap,
    };
    return s;
}

static void free_state(state *s)
{
    free(s->records);
    (*s).records = NULL;
    (*s).records_len = 0;
    (*s).records_cap = 0;
}

static void append_record_to_state(state *s, record r)
{
    if (s->records_len == s->records_cap-1)
    {
        (*s).records_cap += 10;
        (*s).records = realloc(s->records, s->records_cap * sizeof(record));
        if (s->records == NULL) {
            exit(1);
        }
    }
    s->records[(*s).records_len++] = r;
}

static bucket_result_t calc_result_from_state(state *s, bucket_liters_t goal, bucket_id_t start_bucket)
{
    bucket_result_t result;
    for (int i = 0; i < s->records_len; i++)
    {
        int idx = start_bucket == BUCKET_ID_1 ? (s->records_len -1) - i : i;
        record r = s->records[idx];
        if (r.b1 == goal)
        {
            result.possible = true;
            result.move_count = start_bucket == BUCKET_ID_1 ? i : i + 1;
            result.goal_bucket = BUCKET_ID_1;
            result.other_bucket_liters = r.b2;
            return result;
        }
        if (r.b2 == goal)
        {
            result.possible = true;
            result.move_count = start_bucket == BUCKET_ID_1 ? i : i + 1;
            result.goal_bucket = BUCKET_ID_2;
            result.other_bucket_liters = r.b1;
            return result;
        }
    }
    result.possible = false;
    return result;
}

static void update_state(state *s)
{
    if (s->action == TRANSFER)
    {
        bucket_liters_t b1 = s->b1;
        (*s).b1 = s->b1 + s->b2 < s->b1max ? s->b1 + s->b2 : s->b1max;
        (*s).b2 = s->b2 - (s->b1 - b1);
        return;
    }
    if (s->action == FILL_1)
    {
        (*s).b2 = s->b2max;
        return;
    }
    if (s->action == EMPTY_2)
    {
        (*s).b1 = 0;
        return;
    }
}

static void loop_transfers(state *s)
{
    bool first = true; 
    while ((s->b1 != 0 || s->b2 != 0) || first)
    {
        first = false;
        update_state(s);

        record r = {
            .b1 = s->b1,
            .b2 = s->b2,
        };
        append_record_to_state(s, r);

        if (s->action == FILL_1)
        {
            (*s).action = TRANSFER;
        }
        else if (s->action == TRANSFER && s->b1 == s->b1max)
        {
            (*s).action = EMPTY_2;
        }
        else if (s->action == TRANSFER)
        {
            (*s).action = FILL_1;
        }
        else
        {
            (*s).action = TRANSFER;
        }

    }
    return;
}

bucket_result_t measure(bucket_liters_t bucket_1_size, bucket_liters_t bucket_2_size, bucket_liters_t goal_volume, bucket_id_t start_bucket)
{
    bucket_result_t result;
    result.possible = false;
   
    if (start_bucket == BUCKET_ID_1 && goal_volume == bucket_2_size)
    {
        result.possible = true;
        result.move_count = 2;
        result.goal_bucket = BUCKET_ID_2;
        result.other_bucket_liters = bucket_1_size;
        return result;
    }
    if (start_bucket == BUCKET_ID_2 && goal_volume == bucket_1_size)
    {
        result.possible = true;
        result.move_count = 2;
        result.goal_bucket = BUCKET_ID_1;
        result.other_bucket_liters = bucket_1_size;
        return result;
    }

    if (goal_volume > bucket_1_size && goal_volume > bucket_2_size)
    {
        return result;
    }

    if (bucket_1_size == bucket_2_size)
    {
        if (bucket_1_size == goal_volume)
        {
            result.possible = true;
            result.move_count = 1;
            result.goal_bucket = start_bucket;
            result.other_bucket_liters = 0;
            return result;
        }
        return result;
    }

    state s = new_state(bucket_1_size, bucket_2_size);

    loop_transfers(&s);

    result = calc_result_from_state(&s, goal_volume, start_bucket);

    free_state(&s);

    return result;
}
