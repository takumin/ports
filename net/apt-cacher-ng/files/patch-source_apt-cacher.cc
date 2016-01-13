--- source/apt-cacher.cc.orig	2015-12-20 14:54:05 UTC
+++ source/apt-cacher.cc
@@ -5,6 +5,7 @@
 #include <stddef.h>
 #include <sys/stat.h>
 #include <sys/types.h>
+#include <stdlib.h>
 #include <unistd.h>
 #include <cstdbool>
 #include <cstdint>
