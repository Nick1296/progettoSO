#include "simplefs.h"
#include <stdio.h>
#include <unistd.h>

int main(int agc, char** argv) {
  int i,j,printed,print;
  uint8_t mask;
  printf("FirstBlock size %ld\n", sizeof(FirstFileBlock));
  printf("DataBlock size %ld\n", sizeof(FileBlock));
  printf("FirstDirectoryBlock size %ld\n", sizeof(FirstDirectoryBlock));
  printf("DirectoryBlock size %ld\n", sizeof(DirectoryBlock));

  printf("\t\t\t Testing disk driver module:\n");
  printf("\t testing disk_init\n");
  //let's eliminate the previously created file if any
  unlink("disk");
  DiskDriver disk;
  DiskDriver_init(&disk,"disk",10);
  printf("associated file descriptor: %d\n",disk.fd);
  printf("\t DiskHeader info:\n");
  printf("num blocks: %d\n",disk.header->num_blocks );
  printf("num bitmap blocks: %d\n",disk.header->bitmap_blocks );
  printf("bitmap entries: %d\n",disk.header->bitmap_entries );
  printf("num free blocks: %d\n",disk.header->free_blocks );
  printf("first free block: %d\n",disk.header->first_free_block );
  printf("\t Bitmap info\n");
  print=disk.header->num_blocks;
  for(i=0;i<(disk.header->num_blocks+7)/8;i++){
    mask=128;
    printf("block %d:\n",i);
    for(j=0;j<8 && printed<print;j++){
      printf("%c",((mask & disk.bmap->entries[i])? '1' :'0'));
      mask=mask>>1;
      printed++;
    }
    printf("\n");
  }
}
