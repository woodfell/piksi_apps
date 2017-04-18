/*
 * Copyright (C) 2017 Swift Navigation Inc.
 * Contact: Jacob McNamee <jacob@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

#ifndef SWIFTNAV_ZMQ_ROUTER_PRINT_H
#define SWIFTNAV_ZMQ_ROUTER_PRINT_H

#include "zmq_router.h"
#include <stdio.h>

int zmq_router_print(FILE *f, const router_t *router);

#endif /* SWIFTNAV_ZMQ_ROUTER_PRINT_H */
