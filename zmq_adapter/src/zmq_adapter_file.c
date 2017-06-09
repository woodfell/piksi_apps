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

#include "zmq_adapter.h"

int file_loop(const char *file_path)
{
  int fd = open(file_path, O_RDWR);
  if (fd < 0) {
    syslog(LOG_ERR, "error opening file");
    return 1;
  }

  io_loop_start(fd, dup(fd));
  io_loop_wait();

  close(fd);
  fd = -1;
  return 0;
}
