#include <setjmp.h>
#include <stdio.h>

#define try if (!setjmp(env))
#define catch else
#define throw longjmp(env, 1)

static jmp_buf env;

int div(const int n1, const int n2) {
  if (!n2) {
    throw;
  }

  return n1 / n2;
}

int main(void) {
  try {
    printf("4 / 2 = %d\n", div(4, 2));
    printf("10 / 2 = %d\n", div(10, 2));
    printf("10 / 0 = %d\n", div(10, 0));  // error
  } catch {
    printf("exception has occurred\n");
  }

  return 0;
}
