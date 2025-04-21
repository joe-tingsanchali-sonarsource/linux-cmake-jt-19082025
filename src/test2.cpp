#include "lib.h"

int ff(int x) {
  return 2 / x;
}

int main() {
  return myfun(false, ff) != ff(10);
}

float array_access(int i) {
    float array[4] = {1.0f, 2.0f, 3.0f, 4.0f};
    return array[i];
}

float two_step_access(void) {
    float result;
    int i = 12 / 3;
    int j = 12.1f / 2.9f;

    result = array_access(i); // -> This one is found by static code analysis (SonarQube), as the index is calculated based on integers
    result += array_access(j);// -> This one is not found by static code analysis (SonarQube), as the index is calculated based on floats

    return result;
}
