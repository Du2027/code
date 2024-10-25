#include "ascii.h"

char ascii_at(int value){
   if (value < 33 || value >= 127) {
      return 0;
   }
   else {
      return (char) value;
   }
}
