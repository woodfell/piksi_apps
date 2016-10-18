/*
 * Copyright (C) 2016 Swift Navigation Inc.
 * Contact: Jacob McNamee <jacob@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

#ifndef SWIFTNAV_FILTER_NONE_H
#define SWIFTNAV_FILTER_NONE_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {

} filter_none_state_t;

void filter_none_init(void *filter_none_state, const char *filename);
int filter_none_process(void *filter_none_state,
                        const uint8_t *msg, uint32_t msg_length);

#endif /* SWIFTNAV_FILTER_NONE_H */
