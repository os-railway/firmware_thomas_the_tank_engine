#include "logger.h"

#include <stdio.h>

int add(int a, int b) {
  return a + b;
}

void log_message(const char* message) {
  printf("%s\n", message);
}
