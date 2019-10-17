#include "stddef.h"
#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "memory.h"
#include "execinfo.h"

#undef NDEBUG
#include "assert.h"

void bt() {
#define BUFF_SIZE 100
	int j, nptrs;
	void *buffer[BUFF_SIZE];
	char **strings;

	nptrs = backtrace(buffer, BUFF_SIZE);

	strings = backtrace_symbols(buffer, nptrs);
	//backtrace_symbols_fd(buffer + 1, nptrs - 1, STDOUT_FILENO);
	if (strings == NULL) {
		perror("backtrace_symbolls)");
		exit(EXIT_FAILURE);
	}
	for (j = 1; j < nptrs; j++) {
		printf(" ** %2d %s\n", nptrs - j - 1, strings[j]);
	}
	free(strings);
}

int sub1() {
  printf("sub1:+\n");
  bt();
  printf("sub1:-\n");
}

int main() {
  printf("main:+\n");

  bt();
  sub1();

  printf("main:-\n");
  return 0;
}
