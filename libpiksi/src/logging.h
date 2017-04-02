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

#ifndef LIBPIKSI_LOGGING_H
#define LIBPIKSI_LOGGING_H

#include "common.h"
#include <syslog.h>

int logging_init(const char *identity);
void logging_deinit(void);

void piksi_log(int priority, const char *format, ...);
void piksi_vlog(int priority, const char *format, va_list ap);

#endif /* LIBPIKSI_LOGGING_H */
