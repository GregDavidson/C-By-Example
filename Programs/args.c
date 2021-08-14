#include <stdio.h>

int main(int argc, char **argv) {
  printf("Program %s has %d arguments.\n", argv[0], argc);

  puts("\nHere they are last to first: ");
  while ( argc-- )
    puts( argv[argc] );		// random access

  puts("\nHere they are first to last: ");
  while ( *argv )
    puts( *argv++ );		// sequential access

  return 0;
}

  
  
