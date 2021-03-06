﻿#pragma once

#include <inttypes.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <signal.h>


#define CHECK_ERR(cond, msg)  if (cond) {                       \
                              perror(msg);                     \
                              _exit(EXIT_FAILURE);             \
                             }

#define FAILED (-1)
#define SUCCESS 0
#define BLOCK_FREE 0
#define BLOCK_USED 1
#define BLOCK_SIZE 512
#define MISSING (-1)
#define CONTROL_BLOCK 0
#define DIRECTORY 1
#define FILE 0
#define FILENAME_MAX_LENGTH 128
#define PERM_ERR (-2)
// root uid
#define ROOT ((unsigned) 0)
#define GROUP_SIZE 1024
// uasername length
#define NAME_LENGTH 128
// gpasswd operation type
#define ADD 1
#define REMOVE 0
// empty group entry
#define EMPTY (-1)
// defining permissions number
#define READ 4
#define WRITE 2
#define EXECUTE 1
