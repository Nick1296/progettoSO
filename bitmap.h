#pragma once

#include <inttypes.h>
#include "bitmap_structures.h"

// initializes the bitmap given an empty BitMap, the number of bitmap_blocks,
// the number of disk blocks covered and the number of already occupied disk blocks
void BitMap_init(BitMap *b, int bitmap_blocks, int disk_blocks, int occupation);

// converts a block index to an index in the array,
// and a char that indicates the offset of the bit inside the array
BitMapEntryKey BitMap_blockToIndex(int num);

// converts a bit to a linear index
int BitMap_indexToBlock(int entry, uint8_t bit_num);

// returns the index of the first bit having status "status"
// in the bitmap bmap, and starts looking from position start
int BitMap_get(BitMap *bmap, int start, int status);

// sets the bit at index pos in bmap to status
// return status passed on success
int BitMap_set(BitMap *bmap, int pos, int status);

// return the status of the bit at index pos in bmap
int BitMap_test(BitMap *bmap, int pos);
