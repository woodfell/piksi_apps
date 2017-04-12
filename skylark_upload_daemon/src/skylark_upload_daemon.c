/*
 * Copyright (C) 2017 Swift Navigation Inc.
 * Contact: Swift Navigation <dev@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

#include <fcntl.h>
#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>
#include <libpiksi/logging.h>
#include <libpiksi/util.h>
#include <libskylark.h>

static bool debug = false;
static const char *fifo_file_path = NULL;
static const char *url = NULL;

static int parse_options(int argc, char *argv[])
{
  enum {
    OPT_ID_FILE = 1,
    OPT_ID_URL,
    OPT_ID_DEBUG,
  };

  const struct option long_opts[] = {
    {"file",  required_argument, 0, OPT_ID_FILE},
    {"url  ", required_argument, 0, OPT_ID_URL},
    {"debug", no_argument,       0, OPT_ID_DEBUG},
    {0, 0, 0, 0},
  };

  int opt;
  while ((opt = getopt_long(argc, argv, "", long_opts, NULL)) != -1) {
    switch (opt) {
      case OPT_ID_FILE: {
        fifo_file_path = optarg;
      }
      break;

      case OPT_ID_URL: {
        url = optarg;
      }
      break;

      case OPT_ID_DEBUG: {
        debug = true;
      }
      break;

      default: {
        return -1;
      }
      break;
    }
  }

  return 0;
}

int main(int argc, char *argv[])
{
  if (parse_options(argc, argv) != 0) {
    piksi_log(LOG_ERR, "invalid options");
    exit(EXIT_FAILURE);
  }

  char uuid_buf[256];
  if (device_uuid_get(uuid_buf, sizeof(uuid_buf)) != 0) {
    piksi_log(LOG_ERR, "device uuid error");
    exit(EXIT_FAILURE);
  }

  int fd = open(fifo_file_path, O_RDONLY);
  if (fd < 0) {
    piksi_log(LOG_ERR, "fifo error (%d) \"%s\"", errno, strerror(errno));
    exit(EXIT_FAILURE);
  }

  int ret = skylark_setup();
  if (ret != 0) {
    piksi_log(LOG_ERR, "setup error");
    close(fd);
    exit(EXIT_FAILURE);
  }

  skylark_config_t config = {
    .url   = url,
    .uuid  = uuid_buf,
    .debug = debug,
    .fd    = fd,
  };

  ret = skylark_upload(&config);
  if (ret != 0) {
    piksi_log(LOG_ERR, "request error");
    skylark_teardown();
    close(fd);
    exit(EXIT_FAILURE);
  }

  skylark_teardown();
  close(fd);

  return EXIT_SUCCESS;
}
