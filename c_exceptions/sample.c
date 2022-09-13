#include <setjmp.h>
#include <stdio.h>

#define try \
  int ret = setjmp(env); \
  if (!ret)
#define catch(exp_code) else if (ret == exp_code)
#define throw(exp_code) longjmp(env, exp_code)
// exceptions
#define GENERIC_ERROR_EXCEPTION     1
#define DIVISION_BY_ZERO_EXCEPTION  2

static jmp_buf env;

int div(const int n1, const int n2) {
  if (!n2) {
    throw(DIVISION_BY_ZERO_EXCEPTION);
  }

  return n1 / n2;
}

int main(void) {
  try {
    printf("4 / 2 = %d\n", div(4, 2));
    printf("10 / 2 = %d\n", div(10, 2));
    printf("10 / 0 = %d\n", div(10, 0));  // error
  } catch(DIVISION_BY_ZERO_EXCEPTION) {
    printf("division by zero error\n");
  } catch(GENERIC_ERROR_EXCEPTION) {
    printf("generic error\n");
  }

  return 0;
}
